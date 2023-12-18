package com.example;

import java.awt.GridLayout;

import javax.swing.JFrame;

public class Main {
	public static void main(String[] args) {
		JFrame frame = new JFrame("Drawing 2");
		frame.setSize(400,400);
		frame.setLayout(new GridLayout());
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		frame.add(new Canvas());

		frame.setVisible(true);
	}


}
