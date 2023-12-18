package com.example;

import java.awt.FlowLayout;

import javax.swing.JFrame;

public class Main {
	public static void main(String[] args) {
		JFrame frame = new JFrame();
		frame.setSize(600, 400);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		Canvas myCanvas = new Canvas();
		frame.add(myCanvas);

		frame.setVisible(true);

		new Thread() {
			public void run() { 
				try { 
					while(true) {
						sleep(10);
						myCanvas.update();
					}
				} catch (InterruptedException e) {
					e.printStackTrace();
				}	
			}
		}.start();
	}

}

