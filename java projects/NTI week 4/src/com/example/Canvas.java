package com.example;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Polygon;

import javax.swing.JPanel;

public class Canvas extends JPanel {
	@Override
	protected void paintComponent(Graphics g) {
		// TODO Auto-generated method stub
		super.paintComponent(g);
		
		g.setColor(Color.BLUE);
		g.fillRect(0, 0, 200, 400);
		
		g.setColor(Color.GREEN);
		g.fillRect(200, 0, 200, 400);
		
		Color purple = new Color(136, 3, 252);
		g.setColor(purple);
		g.fillOval(20, 220, 340, 130);
		
		g.setColor(Color.RED);
		g.fillRect(0, 0, 200, 200);
		
		g.setColor(Color.YELLOW);
		g.fillRect(200, 0, 200, 200);
		
		g.setColor(Color.ORANGE);
		g.fillArc(100, 100, 100, 100, 90, 270);
		
		Polygon tri = new Polygon();
		tri.addPoint(200, 0);
		tri.addPoint(400,0);
		tri.addPoint(300, 150);
		
		g.setColor(Color.CYAN);
		g.fillPolygon(tri);
		
	}
}

