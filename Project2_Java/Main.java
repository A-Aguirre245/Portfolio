package com.example;

import javax.swing.JFrame;

public class Main {
	public static void main(String[] args) {
		JFrame frame = new JFrame();
		frame.setSize(400,400);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Canvas myCanvas = new Canvas();
		frame.add(myCanvas);
		
		frame.setVisible(true);
		
		new Thread() {
			public void run() {
				try { 
					while(true) {
						sleep(20);
						myCanvas.update();
					}
				} catch (InterruptedException e) {
					e.printStackTrace();
				}	
			}
		}.start();
		
	}

}
