package secureChat;

import java.lang.*;
import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class SimpleGui1 {
	public static void main(String[] args){
		
		// Create button
		
		JButton btn = new JButton("Click me!");
		btn.setMnemonic(KeyEvent.VK_C);	//Using alt+C to trigger it!
		
		// Panel with a flow layout.
		// To make the components to be their preferred size.
		
		JPanel panel = new JPanel(new FlowLayout());
		panel.add(btn);
		
		// Now for the frame
		
		JFrame frame = new JFrame();
		frame.setContentPane(panel); //Using this as default pane
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //Terminate program when the frame is closed
		frame.setLocation(200, 200); //Locate at (200, 2000
		frame.pack(); //Frame is ready, Pack it up for display
		frame.setVisible(true); //Make it visible	
	}
}
