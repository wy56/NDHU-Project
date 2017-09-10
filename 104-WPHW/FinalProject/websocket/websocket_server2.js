
//websocket_server

var http = require("http");
var fs = require('fs');
var path = require('path');
var mime = require('mime');
var websocket_server = require('websocket').server;
var clients = [];
var cache = {};

//var clientUI = require('fs').readFileSync("websocket_client.html");

var port = 1113;

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


function onRequest(request,response){//建立HTTP伺服器，使用暱名函式定義針對每個請所產生的行為
	var filePath = false;
console.log("port "+port+" requested!");
	if(request.url == '/'){
		filePath = 'websocket_client.html';						//決定預設提供的HTML檔案
//console.log("[*]filePath: "+ filePath)
	}else{
		filePath =  request.url;					
//console.log("[*]filePath:" + filePath)
	}
	var absPath = './' + filePath;							//將URL路徑轉換為相對檔案路徑
	serveStatic(response, cache, absPath);					//提供靜態檔案
}

var server = http.createServer(onRequest);

server.listen(port, function(){
	console.log("[*]node_server(websocket) listening on port "+port);
});


wsServer = new websocket_server({
	httpServer: server,
	autoAcceptConnections: false	
});

function onWsRequest(request){
	var connection = request.accept('echo-protocol', request.origin);
	console.log("WebSocket connection accepted.");
	connection.on('message', function(message) {
            console.log('Received Message1112: ' + message.utf8Data);
            //connection.sendUTF(message.utf8Data);
    });
}

wsServer.on('request',onWsRequest);