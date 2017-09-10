/***************************************************************************************
 * Server Side Program                                                                 *
 ***************************************************************************************/

package secureChat;

import java.io.*;
import java.net.*;
import java.util.*;
import java.security.*;
import java.security.interfaces.RSAPublicKey;
import java.security.interfaces.RSAPrivateKey;
import java.security.spec.PKCS8EncodedKeySpec;
import java.security.spec.X509EncodedKeySpec;

import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;


public class Server {
	
	// Server Variables ---------------------------------------------------------------------------------------
	static String broadcastString = "";					// The Broadcast String
	static boolean Setupd = false;						// Setup checker
	
	/* Deprecated Code
	static Coder coder = new Coder();
	// Deprecated Code
	*/

	static String Run;									// The Commander
	
	// AES Encryption and Decryption --------------------------------------------------------------------------
	static String AESKeyAlgorithm = "AES";				// AES key algorithm definition
	static String AESKey = "";							// AES Key
	static String AESEncryptedCipher = "";				// Cipher Encrypted by AES key
	/* AES Encryption need Java Cryptography Extension (JCE) Unlimited Strength Jurisdiction Policy Files*/
	
	
	// Base64 encoder and decoder -----------------------------------------------------------------------------
	
	static Base64.Decoder b64decoder = Base64.getDecoder();
	static Base64.Encoder b64encoder = Base64.getEncoder();
	
	
	// RSA Encryption and Decryption --------------------------------------------------------------------------
	static String RSAKeyAlgorithm = "RSA";				// RSA Key algorithm definition
	static String RSAPublicKeyForMap = "";				// RSA public key hash map generate seed
	static String RSAPrivateKeyForMap = "";				// RSA private key hash map generate seed
	static Map<String, Object> RSAMap;					// RSA key hash map
	static String RSAPublicKey = "";					// RSA public key
	static String RSAPrivateKey = "";					// RSA private key
	
	// RSA Exchange Handler -----------------------------------------------------------------------------------
	static String RSARemotePublicKey = "";				// RSA Remote public key
	static String RSARemotePublicKeyEncryptedAES;		// RSA encrypt AES key using Remote public key
	
	// Signature Cap and De-Cap -------------------------------------------------------------------------------
	// Signature Function is not implemented - Deprecated Code
	/*
	static String SIGAlgorithm = "RSA";					// Signature's Main Algorithm
	static String SIGPanAlgorithm = "MD5withRSA";		// Signature's pan Algorithm
	static String SIGPublicKeyForMap = "";				// Signature's public key hash map generate seed
	static String SIGPrivateKeyForMap = "";				// Signature's private key hash map generate seed
	static Map<String, Object> SIGMap;					// Signature's key hash map
	static String SIGPublicKey = "";					// Signature's public key
	static String SIGPrivateKey = "";					// Signature's private key
	
	// Signature Exchange Handler -----------------------------------------------------------------------------
	static String SIGRemotePublicKey = "";				// Signature's Remote Public key
	// Not Implemented - Deprecated Code
	*/
	
	// Miscellaneous ------------------------------------------------------------------------------------------
	static Scanner scanner = new Scanner(System.in);	// Console Input Handler
	static String selection = "";						// Selection for switch case
	
	//Network Configurations ----------------------------------------------------------------------------------
	static int myPort = 0;								// The port on localhost
	static ServerSocket myServerSocket;					// The ServerSocket on localhost
	static Socket mySocket;								// The Socket on localhost
	static PrintWriter send;							// The Sender through mySocket
	
	static int remotePort = 0;							// The port on remote site
	static String remoteIP = "";						// The IP of remote site
	static Socket remoteSocket;							// The socket to connect to remote
	static BufferedReader receive;						// The receiver to get from remote
	static String Buffer;								// The String handler
	
	
	
	/* Deprecated Code
	 * static int serverPort = 0;							// Server Communication Port
	 * static ServerSocket serverSocket;					// Server Socket Allocator
	 * static Socket socket;								// Server Socket Initializer
	 * static BufferedReader receive;						// in Stream Handler
	 * static String clientIP = "";							// Client IP
	 * static int clientPort = 0;							// Client Port
	 * static Socket clientSocket;
	 * static PrintWriter send;								// Server Out Stream Handler
	 * static String Buffer;								// Temp location for in string
	 */
	
	/*
	 * Program Main entry point -------------------------------------------------------------------------------
	 */
	
	public static void main(String[] args){
		while(true){
			System.out.print("Command>");
			Run = scanner.next();			
			Execute(Run);
			
			}
	}
	
	
	/*
	 * Functions Entry point ---------------------------------------------------------------------------------
	 */
	
	// Server Setup Helper -----------------------------------------------------------------------------------
	public static void ServerSetup(){
		try{
			System.out.println("Generating AES Key");
			AESKey = AESGenKey();
			
			System.out.println("Generating RSA Hasher");
			RSAPublicKeyForMap = RandomGenerator(10);
			RSAPrivateKeyForMap = RandomGenerator(10);
			
			//Deprecated Code
			/*System.out.println("Should AES Key Generate Automatically? Y or N");
			selection = scanner.next();
			switch(selection){
			case "Y":
				AESKey = RandomGenerator(10);
				break;
			case "N":
				System.out.println("Enter AES key for Cipher");
				AESKey = scanner.next();
				break;
			default:
				System.out.println("Invalid Selection");
			}
			
			System.out.println("Should RSA Hasher Generate Automatically? Y or N");
			selection = scanner.next();
			switch(selection){
			case "Y":
				RSAPublicKeyForMap = RandomGenerator(10);
				RSAPrivateKeyForMap = RandomGenerator(10);
				break;
			case "N":
				System.out.println("Enter RSA Public Hash:");
				RSAPublicKeyForMap = scanner.next();
				System.out.println("Enter RSA Private Hash:");
				RSAPrivateKeyForMap = scanner.next();
				break;
			default:
				System.out.println("Invalid Selection");
				break;
			}
			// Deprecated Code
			*/
			
			System.out.println("Local Port:");
			myPort = scanner.nextInt();
			
			System.out.println("Remote IP Address:");
			remoteIP = scanner.next();
			
			System.out.println("Remote Port:");
			remotePort = scanner.nextInt();
			
			System.out.println("Message you would like to send");
			broadcastString = scanner.next();
			
			
			
		}catch(Exception e){
			e.printStackTrace();
		}
		// Deprecated Code
		/*
		try{
			
			// Server Setup :: AES Key Setup
			
			System.out.println("Should AES Key Generate Automatically? Y or N");
			selection = scanner.next();
			switch(selection){
			case "Y":
				AESKey = RandomGenerator(10);
				break;
			case "N":
				System.out.println("Enter AES Key for Cipher");
				AESKey = scanner.next();
			default:
				System.out.println("Invalid Selection");
			}
			
			// Server Setup :: RSA Key Setup
			
			System.out.println("Should RSA Hasher Generate Automatically? Y or N");
			selection = scanner.next();
			switch(selection){
			case "Y":
				RSAPublicKeyForMap = RandomGenerator(10);
				RSAPrivateKeyForMap = RandomGenerator(10);
				break;
			case "N":
				System.out.println("Enter RSA Public Hash:");
				RSAPublicKeyForMap = scanner.next();
				System.out.println("Enter RSA Private Hash:");
				RSAPrivateKeyForMap = scanner.next();
				break;
			default:
				System.out.println("Invalid Selection");
				break;
			}
			
			// Communication Port Setup
			
			System.out.println("Server Port Setup:");
			serverPort = scanner.nextInt();
			
			System.out.println("Client IP:");
			clientIP = scanner.next();
			
			System.out.println("Client Port:");
			clientPort = scanner.nextInt();
			
			// Message Setup
			
			System.out.println("What message would you like to broadcast?");
			broadcastString = scanner.next();
			Setupd = true;
			
		}catch(Exception e){
			ErrorHandler("Server Setup");
		}
	*/
	// Deprecated Code
	}
	
	
	// Command Helper --------------------------------------------------------------------------------------------
	public static void CmdHelp(){
		System.out.println("Help -- Call this menu out");
		System.out.println("PrintAll -- Print All Variables on Screen");
		System.out.println("ServerSetup -- Setting up basic elements");
		System.out.println("Start -- Start the Server up");
		System.out.println("Terminate -- Terminate the System");
		
	}
	
	// Command Executor ------------------------------------------------------------------------------------------
	public static void Execute(String Command){
		switch(Command){
		case "Help":
			CmdHelp();
			break;
		case "PrintAll":
			PrintAll();
			break;
		case "Start":
			Start();
			break;
		case "ServerSetup":
			ServerSetup();
			break;
		case "Terminate":
			Terminate();
			break;
		default:
			CmdHelp();	
		}
	}
	
	// Error Handler ---------------------------------------------------------------------------------------------
	public static void ErrorHandler(String Err){
		System.out.println("Something wrong with " + Err + " That's all we know");
		System.exit(1);
	}
	
	// Print All value in System ---------------------------------------------------------------------------------
	
	public static void PrintAll(){
		System.out.println("Server Variables:");
		System.out.println("broadcastingString = " + broadcastString);
		System.out.println();
		System.out.println();
		System.out.println("AES Encryption and Decryption:");
		System.out.println("AESKey = " + AESKey);
		System.out.println("AESEncryptedCipher = " + AESEncryptedCipher);
		System.out.println();
		System.out.println();
		System.out.println("RSA Encryption and Decryption:");
		System.out.println("RSAPublicKeyForMap = " + RSAPublicKeyForMap);
		System.out.println("RSAPrivateKeyForMap = " + RSAPrivateKeyForMap);
		System.out.println("RSAPublicKey = " + RSAPublicKey);
		System.out.println("RSAPrivateKey = " + RSAPrivateKey);
		System.out.println();
		System.out.println();
		System.out.println("RSA Exchange Handler");
		System.out.println("RSARemotePublicKey = " + RSARemotePublicKey);
		System.out.println("RSARemotePublicKeyEncryptedAES = " + RSARemotePublicKeyEncryptedAES);
		System.out.println();
		System.out.println();
		
		/* Deprecated Code
		System.out.println("Signature Cap and De-cap");
		System.out.println("SIGPublicKeyForMap = " + SIGPublicKeyForMap);
		System.out.println("SIGPrivateKeyforMap = " + SIGPrivateKeyForMap);
		System.out.println("SIGPublicKey = " + SIGPublicKey);
		System.out.println("SIGPrivateKey = " + SIGPrivateKey);
		System.out.println();
		System.out.println();
		System.out.println("Signature Exchange Handler");
		System.out.println("SIGRemotePublicKey = " + SIGRemotePublicKey);
		System.out.println();
		System.out.println();
		// Deprecated Code
		 */
		
		System.out.println("Network Configurations");
		System.out.println("myPort = " + myPort);
		System.out.println("remoteIP = " + remoteIP);
		System.out.println("remotePort = " + remotePort);
		System.out.println();
		
		
		
	}
	
	// Server Start up ----------------------------------------------------------------------------------------
	public static void Start(){
		try{
			System.out.println("Server Info: Initializing Connections");
			myServerSocket = new ServerSocket(myPort);
			
			System.out.println("Server Info: Waiting Remote to Connect");
			mySocket = myServerSocket.accept();
			remoteSocket = new Socket(remoteIP, remotePort);
			
			System.out.println("Server Info: Initializing Sender and Receiver");
			send = new PrintWriter(mySocket.getOutputStream(), true);
			receive = new BufferedReader(new InputStreamReader(remoteSocket.getInputStream()));
			
			System.out.println("Send Command: RequestRSAPublicKey");
			send.println("RequestRSAPublicKey");
			
			while(!receive.ready()){}
			Buffer = receive.readLine();
			System.out.println("Client Says: " + Buffer);
			if (Buffer.equals("ReadyToSendRSAPublicKey")){
				System.out.println("Server Info: Ready to Receive RSA Public Key from Client");
				send.println("Comfirm");
			}
			
			while(!receive.ready()){}
			Buffer = receive.readLine();
			System.out.println("Server Info: Receiving RSA Public Key from Client");
			RSARemotePublicKey = Buffer;
			System.out.println("RSARemotePublicKey = " + RSARemotePublicKey);
			
			while(!receive.ready()){}
			Buffer = receive.readLine();
			System.out.println("Client Says: " + Buffer);
			if (Buffer.equals("RequestAESKeyEncryptByMyRSAPublicKey")){
				System.out.println("Server Info: Generating RSA Encrypting AES Key");
				RSARemotePublicKeyEncryptedAES = b64encoder.encodeToString(encryptByPublicKey(AESKey.getBytes(), RSARemotePublicKey));
				System.out.println("Send Command: ReadyToSendEncryptedAES");
				send.println("ReadyToSendEncryptedAES");
			}
			
			while(!receive.ready()){}
			Buffer = receive.readLine();
			if (Buffer.equals("Comfirm")){
				System.out.println("Server Info: Sending Encrypted AES key to remote");
				System.out.println("AESKey = " + AESKey);
				System.out.println("RSARemotePublicKeyEncryptedAES = " + RSARemotePublicKeyEncryptedAES);
				send.println(RSARemotePublicKeyEncryptedAES);
			}
			
			while(!receive.ready()){}
			Buffer = receive.readLine();
			if (Buffer.equals("RequestAESEncryptedCipher")){
				System.out.println("Client Says: RequestAESEncryptedCipher");
				AESEncryptedCipher = b64encoder.encodeToString((encryptByAES(broadcastString.getBytes(), AESKey)));
				System.out.println("Send Command: ReadyToSendAESEncryptedCipher");
				send.println("ReadyToSendAESEncryptedCipher");
			}
			
			while(!receive.ready()){}
			Buffer = receive.readLine();
			if (Buffer.equals("Comfirm")){
				System.out.println("server Info: Sending AES Encrypted Cipher to remote");
				System.out.println("broadcastString = " + broadcastString);
				System.out.println("AESEncryptedCipher = " + AESEncryptedCipher);
				send.println(AESEncryptedCipher);
				
			}
			
			
			
			/* Deprecated Code
			while(!receive.ready() && receive.readLine() != "SendRSAPublicKey"){}
			System.out.println("Send Command: Comfirm");
			send.println("Comfirm");
			while(!receive.ready()){}
			RSARemotePublicKey = receive.readLine();
			System.out.println("Server Info: Get RSARemotePublicKey = " + RSARemotePublicKey);
			// Deprecated Code
			*/
			
		}catch(Exception e){
			ErrorHandler("Server Start Up");
			e.printStackTrace();
			Terminate();
		}
		
		/* Deprecated Code
		try{
			if (Setupd == false){
				System.out.println("You haven't setup yet!");
				return;
			}
			serverSocket = new ServerSocket(serverPort);
			clientSocket = new Socket(clientIP, clientPort);
			System.out.println("Server Info: Waiting for Connection");
			socket = serverSocket.accept();
			send = new PrintWriter(clientSocket.getOutputStream(), true);
			receive = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			System.out.println("Server Info: Client Connected!");
			
			// Request RSAPublicKey
			
			System.out.println("Send Command: RequestRSAPublicKey");
			send.println("RequestRSAPublicKey");
			while(!receive.ready()){};
			RSARemotePublicKey = receive.readLine();
			
			// Encrypting AES key to Send
			System.out.println("Server Info: Encrypting AES");
			RSARemotePublicKeyEncryptedAES = encryptByPublicKey(AESKey.getBytes(), RSARemotePublicKey).toString();
			System.out.println("Send Command: SendingRSAEncryptedAES");
			send.println("SendingRSAEncryptedAES");
			send.println(RSARemotePublicKeyEncryptedAES);
			
			
			
			// Exchange Signal for Request RSAPublicKey
			
			
			
			System.out.println("Waiting Receving Client RSA Public Key");
			
			
			
		}catch (Exception e){
			e.printStackTrace();
			//ErrorHandler("Server StartUp");
		}
		// Deprecated Code
		*/
	}
	
	
	// Random String Generator -----------------------------------------------------------------------------------
	public static String RandomGenerator(int Length){
		int num = 0;
		String outString = "";
		while(outString.length() < Length){
			num = (int)(Math.random()*(90-50+1)) +50;
			if (num > 57 && num < 65){
				continue;
			}else if(num == 73 || num == 76 || num == 79){
				continue;
			}else{
				outString += (char)num;
			}			
		}
		return outString;
	}
	
	// AES Functions ----------------------------------------------------------------------------------------------
	
	public static String AESGenKey() throws Exception{
		KeyGenerator keygen = KeyGenerator.getInstance(AESKeyAlgorithm);
		keygen.init(256);
		SecretKey key = keygen.generateKey();
		return b64encoder.encodeToString(key.getEncoded());
	}
	
	public static byte[] encryptByAES(byte[] data, String key) throws Exception{
		byte[] keyBytes = b64decoder.decode(key);
		SecretKeySpec secretkeyspec = new SecretKeySpec(keyBytes, AESKeyAlgorithm);
		Cipher cipher = Cipher.getInstance(AESKeyAlgorithm);
		cipher.init(Cipher.ENCRYPT_MODE, secretkeyspec);
		return cipher.doFinal(data);
	}
	
	public static byte[] decryptByAES(byte[] data, String key) throws Exception{
		byte[] keyBytes = b64decoder.decode(key);
		SecretKeySpec secretkeyspec = new SecretKeySpec(keyBytes, AESKeyAlgorithm);
		Cipher cipher = Cipher.getInstance(AESKeyAlgorithm);
		cipher.init(Cipher.DECRYPT_MODE,  secretkeyspec);
		return cipher.doFinal(data);
	}
	
	// RSA Functions ----------------------------------------------------------------------------------------------
	// RSA Initializer
	public static Map<String, Object> RSAinitKey() throws Exception{
		KeyPairGenerator keypairgen = KeyPairGenerator.getInstance(RSAKeyAlgorithm);
		keypairgen.initialize(1024);
		KeyPair keypair = keypairgen.generateKeyPair();
		
		RSAPublicKey publickey = (RSAPublicKey) keypair.getPublic();
		RSAPrivateKey privatekey = (RSAPrivateKey) keypair.getPrivate();
		
		Map<String, Object> keyMap = new HashMap<String, Object>(2);
		keyMap.put(RSAPublicKeyForMap, publickey);
		keyMap.put(RSAPrivateKeyForMap, privatekey);
		return keyMap;
	}
	
	// RSA key retriever
	public static String RSAGetPublicKey(Map<String, Object> keyMap) throws Exception{
		Key key = (Key) keyMap.get(RSAPublicKeyForMap);
		return b64encoder.encodeToString(key.getEncoded());
		
		/* Deprecated Code
		//return coder.encryptBASE64(key.getEncoded()).toString();
		//return key.toString();
		// Deprecated Code
		 */
	}
	
	public static String RSAGetPrivateKey(Map<String, Object> keyMap) throws Exception{
		Key key = (Key) keyMap.get(RSAPrivateKeyForMap);
		return b64encoder.encodeToString(key.getEncoded());
		
		/* Deprecated Code
		//return coder.encryptBASE64(key.getEncoded()).toString();
		//return key.toString();
		// Deprecated Code
		 */
	}
	
	// RSA key Encryption and Decryption
	// Encrypt by Private Key
	public static byte[] encryptByPrivateKey(byte[] data, String key) throws Exception{
		
		/* Deprecated Code
		//byte[] keyBytes = coder.decryptBASE64(key);
		//byte[] keyBytes = key.getBytes();
		// Deprecated Code
		 */
		
		byte[] keyBytes = b64decoder.decode(key);
		PKCS8EncodedKeySpec pkcs8EncodedKeySpec = new PKCS8EncodedKeySpec(keyBytes);
		KeyFactory keyFactory = KeyFactory.getInstance(RSAKeyAlgorithm);
		Key privateKey = keyFactory.generatePrivate(pkcs8EncodedKeySpec);
		Cipher cipher = Cipher.getInstance(keyFactory.getAlgorithm());
		cipher.init(Cipher.ENCRYPT_MODE, privateKey);
		return cipher.doFinal(data);
	}
	
	// Decrypt by Private Key
	public static byte[] decryptByPrivateKey(byte[] data, String key) throws Exception{
		
		/* Deprecated Code
		//byte[] keyBytes = coder.decryptBASE64(key);
		//byte[] keyBytes = key.getBytes();
		// Deprecated Code
		 */
		
		byte[] keyBytes = b64decoder.decode(key);
		PKCS8EncodedKeySpec pkcs8EncodedKeySpec = new PKCS8EncodedKeySpec(keyBytes);
		KeyFactory keyFactory = KeyFactory.getInstance(RSAKeyAlgorithm);
		Key privateKey = keyFactory.generatePrivate(pkcs8EncodedKeySpec);
		Cipher cipher = Cipher.getInstance(keyFactory.getAlgorithm());
		cipher.init(Cipher.DECRYPT_MODE, privateKey);
		return cipher.doFinal(data);
	}
	
	// Encrypt by Public Key
	public static byte[] encryptByPublicKey(byte[] data, String key) throws Exception{
		
		/* Deprecated Code
		//byte[] keyBytes = coder.decryptBASE64(key);
		//byte[] keyBytes = key.getBytes();
		// Deprecated Code
		 */
		
		byte[] keyBytes = b64decoder.decode(key);
		X509EncodedKeySpec x509EncodedKeySpec = new X509EncodedKeySpec(keyBytes);
		KeyFactory keyFactory = KeyFactory.getInstance(RSAKeyAlgorithm);
		Key publicKey = keyFactory.generatePublic(x509EncodedKeySpec);
		Cipher cipher = Cipher.getInstance(keyFactory.getAlgorithm());
		cipher.init(Cipher.ENCRYPT_MODE, publicKey);
		return cipher.doFinal(data);
	}
	
	// Decrypt by Public Key
	public static byte[] decryptByPublicKey(byte[] data, String key) throws Exception{
		
		/* Deprecated Code
		//byte[] keyBytes = coder.decryptBASE64(key);
		//byte[] keyBytes = key.getBytes();
		// Deprecated Code
		 */
		
		byte[] keyBytes = b64decoder.decode(key);
		X509EncodedKeySpec x509EncodedKeySpec = new X509EncodedKeySpec(keyBytes);
		KeyFactory keyFactory = KeyFactory.getInstance(RSAKeyAlgorithm);
		Key publicKey = keyFactory.generatePublic(x509EncodedKeySpec);
		Cipher cipher = Cipher.getInstance(keyFactory.getAlgorithm());
		cipher.init(Cipher.DECRYPT_MODE, publicKey);
		return cipher.doFinal(data);
	}
		
	// System Terminate
	public static void Terminate(){
		System.exit(1);
	}

}
