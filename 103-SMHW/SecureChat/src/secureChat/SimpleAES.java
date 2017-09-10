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
		//���[�K���r��
		String msg = "This is a message.";
		System.out.println("��l�r��G"+new String(msg));
		//�]�w�n�ϥΪ��[�K�t��k
		KeyGenerator keyG = KeyGenerator.getInstance("AES");
		//�]�wkey������
		keyG.init(256);
		//����SecretKey
		SecretKey secuK = keyG.generateKey();
		//���o�n�Ψӥ[�K��key(�ѱK�]�ݨϥγo��key)
		byte[] key = secuK.getEncoded();
		System.out.println("key�G"+new String(key));
		SecretKeySpec spec = new SecretKeySpec(key, "AES");
		Cipher cipher = Cipher.getInstance("AES");
		//�]�w���[�K�Ҧ�
		cipher.init(Cipher.ENCRYPT_MODE, spec);
		//�N�r��[�K�A�è��o�[�K�᪺���
		byte[] encryptData = cipher.doFinal(msg.getBytes());
		System.out.println("�[�K��r��G"+new String(encryptData));
		 
		//�ϥέ��Ψӥ[�K��key�i��ѱK
		spec = new SecretKeySpec(key, "AES");
		cipher = Cipher.getInstance("AES");
		//�]�w���ѱK�Ҧ�
		cipher.init(Cipher.DECRYPT_MODE, spec);
		byte[] original = cipher.doFinal(encryptData);
		System.out.println("�ѱK��r��G"+new String(original));
	}
}
