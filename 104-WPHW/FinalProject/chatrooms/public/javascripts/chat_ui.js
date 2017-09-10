
function divEscapedContentElement(message) {					//不可信任的資料放在div裡，直接用text輸出
	return $('<div></div>').text(message);
}

function divSystemContentElement(message) {						//可信任的字串內容，以html方式輸出
	return $('<div></div>').html('<i>' + message + '</i>');
}

function processUserInput(chatApp, socket) {
	var message = $('#send-message').val();						//jquery 把送出的message 抓下來assign給message
	var systemMessage;
	
	if (message.charAt(0) == '/'){								//if system message
		systemMessage = chatApp.processCommand(message);		//包到 divSystemContentElement 去 jquery append
		if (systemMessage) {
			$('#messages').append(divSystemContentElement(systemMessage));//jquery append message
		}
	}else {														// if not system message
		chatApp.sendMessage($('#room').text(), message);		// 把message 顯示在房間
		$('#messages').append(divEscapedContentElement(message));
		$('#messages').scrollTop($('#messages')).prop('scrollHeight');
	}
	
	$('#send-message').val('');
}

var socket = io.connect();

$(document).ready(function() {

	
	var chatApp = new Chat(socket);
	
	socket.on('nameResult', function(result){					//展示暱稱變更的結果
		var message;
		
		if (result.success) {
			message = 'You are now known as ' + result.name + '.';
		}else {
			message = result.message;
		}
		$('#messages').append(divSystemContentElement(message));
	});
	
	socket.on('joinResult', function(result) {					//展示聊天室變更的結果
		$('#room').text(result.room);
		$('#messages').append(divSystemContentElement('Room changed.'));
	});
	
	socket.on('message', function (message) {					//展示收到的訊息
		var newElement = $('<div></div>').text(message.text);
		$('#messages').append(newElement);
	})
	
	socket.on('rooms', function(rooms) {						//展示有效聊天室的清單
		$('#room-list').empty();
		
		for(var room in rooms){
			room = room.substring(1, room.length);
			if (room != ''){
				$('#room-list').append(divEscapedContentElement(room));
			}
		}
		$('#room-list div').click(function() {
			chatApp.processCommand('/join' + $(this).text());
			$('#send-message').focus();
		});
	});
	
	setInterval(function() {
		socket.emit('rooms');
	}, 1000);
	
	$('#send-message').focus();
	
	$('#send-form').submit(function() {
		processUserInput(chatApp, socket);
		return false;
	});
});