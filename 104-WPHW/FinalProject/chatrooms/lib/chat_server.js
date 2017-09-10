// chatServer.js
// require socket.io
// 被server.js呼叫，啟動socket.io伺服器，將日誌紀錄限制在主控台，並確立每個進來的連現如何處理


var socketio = require('socket.io');
var io;
var guestNumber = 1;
var nickNames = {};		//object	["ken","jack","guest1","guest2"]
var namesUsed = [];		//array		["ken","jack"]
var currentRoom = {};



//console.log("in chat_server.js")



exports.listen = function(server){
	
	io = socketio.listen(server);										//啟動Socket.IO伺服器，讓他奠基於既有的HTTP伺服器上
	
	io.set('log level', 1);
	
	io.sockets.on('connection', function(socket){						//io.socket listen connection -> socket
		guestNumber = assignGuestName(socket, guestNumber, nickNames, namesUsed);	//訪客連接時，設定訪客暱稱
		joinRoom(socket, 'Lobby');										//使用者連接時，放進Lobby
		
		handleMessageBroadcasting(socket, nickNames);					//處理使用者訊息、暱稱改變、聊天室建立、變更			
		handleNameChangeAttempts(socket, nickNames, namesUsed);			
		handleRoomJoining(socket);
		
		socket.on('rooms', function(){									//對socket做rooms 的處理
			socket.emit('rooms', io.sockets.manager.rooms);				//提供使用者聊天室清單
		});
		
		handleClientDisconnection(socket, nickNames, namesUsed);		//定義使用者斷線時的清理邏輯
	})
}


function assignGuestName(socket, guestNumber, nickNames, namesUsed){
	var name = 'Guest' + guestNumber;
	nickNames[socket.id] = name;										//guestName assign
	socket.emit('nameResult',{											//
		success: true,
		name: name
	})
	namesUsed.push(name);												//紀錄目前用的名字
	return guestNumber + 1;												//每多一個connection, guestNumber +1
}

function handleNameChangeAttempts(socket, nickNames, namesUsed){
								/*為什麼name這樣用 Q口Q!!!!!*/
	socket.on('nameAttempt', function(name){							//nameAttempt 事件監聽器
		
		if (name.indexOf('Guest') == 0) {
			socket.emit('nameResult', {
				success: false,
				message: 'Names cannot begin with "Guest".'
			});
		}else{/*看不懂 name 是瞎密*/
				if ( namesUsed.indexOf(name) == -1 ){					//假如暱稱未被註冊，就註冊他
					var previousName = nickNames[socket.id];			//將目前的name紀錄在previousName(準備delete)
					var previousNameIndex = namesUsed.indexOf(previousName)//講preName的index記錄下來
					namesUsed.push(name);								//namesUsed 把後來名稱加入(表示不可用)
					nickNames[socket.id] = name;						//nickNames array 直接assign 新的name
					delete namesUsed[previousNameIndex];				//namesUsed 把原本名稱殺掉(表示可用)
				
					socket.emit('nameResult', {
						success: true,
						name: name
				});
				
				socket.broadcast.to(currentRoom[socket.id]).emit('message', {//對房間廣播改名訊息
					text: previousName + ' is now known as ' + name + '.'
				});
			}else {								
				socket.emit('nameResult',{								//若暱稱被用過，廣播in use
					success: false,
					message: 'That name is already in use.'
				});
			}
		}
	});
}

function handleMessageBroadcasting(socket){
							/*一下name, 一下message的 ...= =*/
	socket.on('message', function (message){
		socket.broadcast.to(message.room).emit('message', {
			text: nickNames[socket.id] + ': ' + message.text
		});
	});
}

function joinRoom(socket, room){
	
	/*加入房間(把socket 加入room)*/
	socket.join(room);													//讓使用者加入聊天室
	currentRoom[socket.id] = room;
	
	/*廣播給其他人知道有新人加入*/
	socket.emit('joinResult', {room: room});							//讓使用者知道他現在正在新聊天室
	socket.broadcast.to(room).emit('message', {							//讓其他使用者知道新使用者加入
		text: nickNames[socket.id] + ' has joined ' + room + '.'
	});

	/*使用者介面列出房間名單*/
	var usersInRoom = io.sockets.clients(room);							//判斷有哪些人跟使用者相同聊天室, clients method returns array
	if(usersInRoom.length > 1){											//假設有其他人存在
		
		var usersInRoomSummary = 'Users currently in ' + room + ': ';	//總結字串
																		
		for (var index in usersInRoom){									//loop 比對有哪些人
			var userSocketId = usersInRoom[index].id;
			if (userSocketId != socket.id){								//if判斷式：避免廣播到自己
				if (index > 0){
					usersInRoomSummary += ', ';
				}
				usersInRoomSummary += nickNames[userSocketId];			//把比對出來的名字，接到userInRoomSummary的字串後面
			}
		}
		usersInRoomSummary += '.';
		socket.emit('message', {text: usersInRoomSummary});				//廣播
	}
}

function handleRoomJoining(socket) {
	socket.on('join', function(room){
		socket.leave(currentRoom[socket.id]);
					/*不懂room.newRoom*/
		joinRoom(socket, room.newRoom);
	});
}

function handleClientDisconnection(socket){
	socket.on('disconnect', function(){
		var nameIndex = namesUsed.indexOf(nickNames[socket.id]);
		delete namesUsed[nameIndex];
		delete nickNames[socket.id];
	});
}


