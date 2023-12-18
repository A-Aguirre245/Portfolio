package com.example;

import java.awt.GridLayout;

import javax.swing.JFrame;

public class Main {
	public static void main(String[] args) {
		JFrame frame = new JFrame("Drawings");
		frame.setSize(400, 400);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setLayout(new GridLayout());
		
		frame.add(new Canvas());
		
		
		frame.setVisible(true);
		
		
	}

}
