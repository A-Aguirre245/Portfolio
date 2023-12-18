package com.example;

import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;

public class Canvas extends JPanel {
	@Override
	protected void paintComponent(Graphics g) {
		// TODO Auto-generated method stub
		super.paintComponent(g);

		int col = 1;
		int y = 0;

		for(int x = 400; x > 0; x = x - 6) {
			if(col == 1) {
				g.setColor(Color.RED);
				g.fillRect(y, y, x - y, x - y);
				col++;
			}else if(col == 2) {
				g.setColor(Color.BLUE);
				g.fillRect(y, y, x - y, x - y);
				col++;
			}else if(col == 3) {
				g.setColor(Color.YELLOW);
				g.fillRect(y, y, x - y, x - y);
				col++;
			}else if(col == 4) {
				g.setColor(Color.GREEN);
				g.fillRect(y, y, x - y, x - y);
				col++;
			}else if(col == 5) {
				g.setColor(Color.BLACK);
				g.fillRect(y, y, x - y, x - y);
				col++;
			}else if(col == 6) {
				g.setColor(Color.PINK);
				g.fillRect(y, y, x - y, x - y);
				col++;
			}else if(col == 7) {
				g.setColor(Color.ORANGE);
				g.fillRect(y, y, x - y, x - y);
				col++;
			}else if(col == 8) {
				g.setColor(Color.MAGENTA);
				g.fillRect(y, y, x - y, x - y);
				col = 1;
			}
			y = y + 6;
		}



	}



}
