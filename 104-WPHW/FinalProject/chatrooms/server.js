// chatrooms
var port = 8081;

// require http,fs,path,mime,lib/chat_server
// function send404, sendFile, servStatic

var http = require('http');
var fs = require('fs');
var path = require('path');
var mime = require('mime');
var cache = {};




function send404(response){
//console.log("in 404");
	response.writeHead(404, {'Conten-Type': 'text/plain'});
	response.write('Error 404: resource not found.');
	response.end();
}



function sendFile(response, filePath, fileContents){
console.log("in sendFile");
	response.writeHead(
		200, 
		{'Conten-Type': mime.lookup(path.basename(filePath))}
	);
//console.log("fileContents: " + fileContents);
	response.end(fileContents);
}

function serveStatic(response, cache, absPath){
	if (cache[absPath]) {									//檢查檔案是否被快取在記憶體中
//console.log("cache success");		
		sendFile(response, absPath, cache[absPath]);		//從記憶體提供檔案
	}else {
		fs.exists(absPath, function(exists) {				//檢查檔案是否存在
//console.log("in fs.exists");
			if(exists){
//console.log("in if");
				fs.readFile(absPath, function(err, data){	//從磁碟讀取檔案
//console.log("in fs.readFile");
					if(err){
//console.log("in if(err)");
						send404(response);
					}else{
//console.log("in else2")
						cache[absPath] = data;
						sendFile(response, absPath, data);	//提供從磁碟讀取的檔案
					}
				});
			}else{
console.log("in else1");
				send404(response);							//404
			}
		});
	}
}

var server = http.createServer(function(request, response) {	//建立HTTP伺服器，使用暱名函式定義針對每個請所產生的行為
	var filePath = false;
	
	if(request.url == '/'){
		filePath = 'public/index.html';						//決定預設提供的HTML檔案
console.log("[*][*]filePath: "+ filePath)
	}else{
		filePath = 'public' + request.url;					
console.log("[*][*]filePath:" + filePath)
	}
	var absPath = './' + filePath;							//將URL路徑轉換為相對檔案路徑
	serveStatic(response, cache, absPath);					//提供靜態檔案
});

server.listen(port, function(){
	console.log("[*]chatrooms Server listening on port "+port);
});

var chatServer = require('./lib/chat_server');
chatServer.listen(server);