//ws

var http = require("http");
var fs = require('fs');
var path = require('path');
var mime = require('mime');
var ws = require('websocket-server');
var clients = [];
var cache = {};

//var clientUI = require('fs').readFileSync("websocket_client.html");

var port = 1111;

var httpserver = http.createServer();

function send404(response){
	
//console.log("in 404");
	response.writeHead(404, {'Conten-Type': 'text/plain'});
	response.write('Error 404: resource not found.');
	response.end();
}

function sendFile(response, filePath, fileContents){
	response.writeHead(
		200, 
		{'Conten-Type': mime.lookup(path.basename(filePath))}
	);
	response.end(fileContents);
}

function serveStatic(response, cache, absPath){
	if (cache[absPath]) {									//檢查檔案是否被快取在記憶體中	
		sendFile(response, absPath, cache[absPath]);		//從記憶體提供檔案
	}else {
		fs.exists(absPath, function(exists) {				//檢查檔案是否存在
			if(exists){
				fs.readFile(absPath, function(err, data){	//從磁碟讀取檔案
					if(err){
						send404(response);
					}else{
						cache[absPath] = data;
						sendFile(response, absPath, data);	//提供從磁碟讀取的檔案
					}
				});
			}else{
				send404(response);							//404
			}
		});
	}
}

httpserver.on('request',function(request,response){//建立HTTP伺服器，使用暱名函式定義針對每個請所產生的行為
	var filePath = false;
console.log("http server port "+port+" requested!");
	if(request.url == '/'){
		filePath = 'websocket_client.html';						//決定預設提供的HTML檔案
//console.log("[*]filePath: "+ filePath)
	}else{
		filePath =  request.url;					
//console.log("[*]filePath:" + filePath)
	}
	var absPath = './' + filePath;							//將URL路徑轉換為相對檔案路徑
	serveStatic(response, cache, absPath);					//提供靜態檔案
});



var wsServer = ws.createServer({server: httpserver});

wsServer.on("connection", function(socket){
	socket.send("Welcome to the chat room.");
	socket.on("message", function(msg){
		console.log(msg)
		wsServer.broadcast(msg);
	});
})

wsServer.listen(port,function(){
	console.log("[*]websocket_server listening port:" + port)
});