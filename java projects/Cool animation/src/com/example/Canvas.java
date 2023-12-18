package com.example;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Polygon;

import javax.swing.JPanel;

public class Canvas extends JPanel{
	private int a = 73;
	private int b = 369;
	private int c = 162;
	private int d = 284;
	private int e = 241;
	private int f = 190;
	private int h = 391;
	private int j = 12;

	private int da = 1;
	private int db = 1;
	private int dc = 1;
	private int dd = 1;
	private int de = 1;
	private int df = 1;
	private int dh = 1;
	private int dj = 1;

	public void update() {
		
		if(a > getWidth()) {
			da = -1;
		}else if(a < 0) {
			da = 1;
		}

		if(b > getHeight()) {
			db = -1;
		}else if(b < 0) {
			db = 1;
		}

		if(c > getWidth()) {
			dc = -1;
		}else if(c < 0) {
			dc = 1;
		}

		if(d > getHeight()) {
			dd = -1;
		}else if(d < 0) {
			dd = 1;
		}

		if(e  > getWidth()) {
			de = -1;
		}else if(e < 0) {
			de = 1;
		}

		if(f > getHeight()) {
			df= -1;
		}else if(f < 0) {
			df = 1;
		}

		if(h > getWidth()) {
			dh = -1;
		}else if(h < 0) {
			dh = 1;
		}

		if(j > getHeight()) {
			dj = -1;
		}else if(j < 0) {
			dj = 1;
		}

		a += da;
		b += db;
		c += dc;
		d += dd;
		e += de;
		f += df;
		h += dh;
		j += dj;

		repaint();

	}

	@Override
	protected void paintComponent(Graphics g) {
		// TODO Auto-generated method stub
		super.paintComponent(g);

		g.setColor(Color.BLACK);
		g.fillRect(0, 0, getWidth(), getHeight());

		for(int x = 0; x < 90; x += 30) {
			Polygon pA = new Polygon();
			pA.addPoint(a + x, b + x);
			pA.addPoint(c + x, d + x);
			pA.addPoint(e + x, f + x);
			pA.addPoint(h + x, j + x);
			
			g.setColor(Color.CYAN);
			g.drawPolygon(pA);

			Polygon pB = new Polygon();
			pB.addPoint(a + x + 5, b + x + 5);
			pB.addPoint(c + x + 5, d + x + 5);
			pB.addPoint(e + x + 5, f + x + 5);
			pB.addPoint(h + x + 5, j + x + 5);

			g.setColor(Color.MAGENTA);
			g.drawPolygon(pB);
			
			Polygon pC = new Polygon();
			pC.addPoint(a + x + 10, b + x + 10);
			pC.addPoint(c + x + 10, d + x + 10);
			pC.addPoint(e + x + 10, f + x + 10);
			pC.addPoint(h + x + 10, j + x + 10);
			
			g.setColor(Color.CYAN);
			g.drawPolygon(pC);

			Polygon pD = new Polygon();
			pD.addPoint(a + x + 15, b + x + 15);
			pD.addPoint(c + x + 15, d + x + 15);
			pD.addPoint(e + x + 15, f + x + 15);
			pD.addPoint(h + x + 15, j + x + 15);
			
			g.setColor(Color.MAGENTA);
			g.drawPolygon(pD);
			
			Polygon pE = new Polygon();
			pE.addPoint(a + x + 20, b + x + 20);
			pE.addPoint(c + x + 20, d + x + 20);
			pE.addPoint(e + x + 20, f + x + 20);
			pE.addPoint(h + x + 20, j + x + 20);
			
			g.setColor(Color.CYAN);
			g.drawPolygon(pE);

			Polygon pF = new Polygon();
			pF.addPoint(a + x + 25, b + x + 25);
			pF.addPoint(c + x + 25, d + x + 25);
			pF.addPoint(e + x + 25, f + x + 25);
			pF.addPoint(h + x + 25, j + x + 25);
			
			g.setColor(Color.MAGENTA);
			g.drawPolygon(pF);
			
		}
		
	}

}
