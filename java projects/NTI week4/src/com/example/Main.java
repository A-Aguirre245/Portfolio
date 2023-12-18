package com.example;

import java.awt.FlowLayout;

import javax.swing.JFrame;

public class Main {
	public static void main(String[] args) {
		JFrame frame = new JFrame("Drawings");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(400,400);
		frame.setLayout(new FlowLayout());
		
		frame.setVisible(true);

	}
}
