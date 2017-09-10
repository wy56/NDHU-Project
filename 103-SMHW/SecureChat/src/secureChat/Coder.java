/*******************************************************************************
 * This library is used for backward capability of Java 6 or older             *
 * Please note that this library is INCOMPATIBLE with Java version 7 or later  *
 * Check your Java version before make any changes to the code                 *
 * You can actually slash out the deprecated code part in en/decryption section*
 * to execute this program IFF you have a Java version older than 6            *
 * IF NOT, please upgrade your Java to 7 or later and deprecate this library   *
 *******************************************************************************/


package secureChat;

import java.security.*;
import java.util.*;

import javax.crypto.*;
import javax.crypto.spec.SecretKeySpec;

public class Coder {
	static final String keySHA = "SHA";
	static final String keyMD5 = "MD5";
	static final String keyMAC = "HmacMD5";
	
	//Base64 decoder
	public static byte[] decryptBASE64(String key) throws Exception{
		Base64.Decoder b64decoder = Base64.getDecoder();
		byte[] decoded = b64decoder.decode(key);
		return decoded;
	}
	
	//Base64 encoder
	public static byte[] encryptBASE64(byte[] key) throws Exception {
		Base64.Encoder b64encoder = Base64.getEncoder();
		byte[] encoded = b64encoder.encode(key);
		return encoded;
	}
	
	//MD5 encoder
	public static byte[] encryptMD5(byte[] data) throws Exception {
		MessageDigest md5 = MessageDigest.getInstance(keyMD5);
		md5.update(data);
		return md5.digest();
	}
	
	//SHA encoder
	public static byte[] encryptSHA(byte[] data) throws Exception {
		MessageDigest sha = MessageDigest.getInstance(keySHA);
		sha.update(data);
		return sha.digest();
	}
	
	//HMAC encoder initializer
	public static byte[] initMackey() throws Exception {
		KeyGenerator keygen = KeyGenerator.getInstance(keyMAC);
		SecretKey secretkey = keygen.generateKey();
		return encryptBASE64(secretkey.getEncoded());
	}
	
	//HMAC encoder
	public static byte[] encryptHMAC(byte[] data, String key) throws Exception {
		SecretKey secretkey = new SecretKeySpec(decryptBASE64(key), keyMAC);
		Mac mac = Mac.getInstance(secretkey.getAlgorithm());
		mac.init(secretkey);
		return mac.doFinal(data);
	}
	
	
}
