package com.example;

import java.awt.FlowLayout;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class Main {

	public static void main(String[] args) {

		JFrame frame = new JFrame("Words");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(300,300);
		frame.setLayout(new FlowLayout());

		JLabel lblOne = new JLabel("Enter some text:");
		JTextArea txtOne = new JTextArea(5,10);
		JLabel lblTwo = new JLabel("Enter some text:");
		JTextArea txtTwo = new JTextArea(5,10);

		frame.add(lblOne);
		frame.add(new JScrollPane(txtOne));
		frame.add(lblTwo);
		frame.add(new JScrollPane(txtTwo));

		JMenuBar menu = new JMenuBar();
		JMenu strings = new JMenu("String Stuff");
		JMenuItem compare = new JMenuItem("Compare the Strings");
		JMenuItem diffrent = new JMenuItem("Where do the Strings Differ");
		JMenuItem vowels= new JMenuItem("Do the Strings Have the Same Number of Vowels");

		menu.add(strings);
		strings.add(compare);
		strings.add(diffrent);
		strings.add(vowels);
		frame.setJMenuBar(menu);

		compare.addActionListener(src ->{
			String one = txtOne.getText();
			String two = txtTwo.getText();

			if(one.equals(two)) {
				JOptionPane.showMessageDialog(null, "The strings are exactly the same");
			}else if(!one.equals(two)){
				JOptionPane.showMessageDialog(null, "The strings are not exactly the same");
			}
		});

		diffrent.addActionListener(src ->{
			String one = txtOne.getText();
			String two = txtTwo.getText();
			int lengthOne = one.length();
			int x = 0;
			
			if(one.equals(two)) {
				JOptionPane.showMessageDialog(null, "The Strins are exactly the same");
			}else {
				while(x < lengthOne - 1) {
					String a = one.substring(x, x + 1);
					String b = two.substring(x, x + 1);
					if(!a.equals(b)) {
						JOptionPane.showMessageDialog(null,"The strings differ at place " + x);
						break;
					}
					x++;
				}
			}
		});

		vowels.addActionListener(src ->{
			String one = txtOne.getText();
			String two = txtTwo.getText();
			int lengthOne = one.length();
			int lengthTwo = two.length();
			int x = 0;
			int y = 0;
			int oneCount = 0;
			int twoCount = 0;

			while(x < lengthOne - 1) {
				String a = one.substring(x, x + 1);
				if( (a.indexOf("a") == 0) || (a.indexOf("e") == 0) || (a.indexOf("i") == 0)  || (a.indexOf("o") == 0) || (a.indexOf("u") == 0) ){
					oneCount = oneCount + 1;
				}
				x++;
			}
			while(y < lengthTwo - 1) {
				String b = two.substring(y, y + 1);
				if( (b.indexOf("a") == 0) || (b.indexOf("e") == 0) || (b.indexOf("i") == 0)  || (b.indexOf("o") == 0) || (b.indexOf("u") == 0) ){
					twoCount = twoCount + 1;
				}
				y++;
			}

			if(oneCount == twoCount) {
				JOptionPane.showMessageDialog(null, "The strings have the same number of vowels");
			}else {
				JOptionPane.showMessageDialog(null, "The strings don't have the same number of vowels");
			}
		});

		frame.setVisible(true);
	}

}
