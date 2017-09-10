package secureChat;

import java.lang.*;
import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class SimpleGui2 {
	private static JFrame frame = null;
	private static JButton btn = null;
	
	public static void main(String[] args){
		//Let's make a button first
		
		btn = new JButton("Click Me!");
		btn.setMnemonic(KeyEvent.VK_C);
		// btn.addActionListener(new ButtonListenr());
		
	}

}
