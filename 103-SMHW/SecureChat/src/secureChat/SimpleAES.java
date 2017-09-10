/****************************************************************************************
 * This is a simple program to test the AES library provided by Oracle                  *
 * AES functions required the following runtime or setup to execute:                    *
 * Java Cryptography Extension (JCE) Unlimited Strength Jurisdiction Policy Files       *
 ****************************************************************************************/
package secureChat;

import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;

import javax.crypto.BadPaddingException;
import javax.crypto.Cipher;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.KeyGenerator;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;

public class SimpleAES {
	public static void main(String[] args) throws InvalidKeyException, IllegalBlockSizeException, BadPaddingException, NoSuchAlgorithmException, NoSuchPaddingException{
		//欲加密的字串
		String msg = "This is a message.";
		System.out.println("原始字串："+new String(msg));
		//設定要使用的加密演算法
		KeyGenerator keyG = KeyGenerator.getInstance("AES");
		//設定key的長度
		keyG.init(256);
		//產生SecretKey
		SecretKey secuK = keyG.generateKey();
		//取得要用來加密的key(解密也需使用這把key)
		byte[] key = secuK.getEncoded();
		System.out.println("key："+new String(key));
		SecretKeySpec spec = new SecretKeySpec(key, "AES");
		Cipher cipher = Cipher.getInstance("AES");
		//設定為加密模式
		cipher.init(Cipher.ENCRYPT_MODE, spec);
		//將字串加密，並取得加密後的資料
		byte[] encryptData = cipher.doFinal(msg.getBytes());
		System.out.println("加密後字串："+new String(encryptData));
		 
		//使用剛剛用來加密的key進行解密
		spec = new SecretKeySpec(key, "AES");
		cipher = Cipher.getInstance("AES");
		//設定為解密模式
		cipher.init(Cipher.DECRYPT_MODE, spec);
		byte[] original = cipher.doFinal(encryptData);
		System.out.println("解密後字串："+new String(original));
	}
}
