package com.example;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Polygon;

import javax.swing.JPanel;

public class Canvas extends JPanel {
	private int a = 0;
	private int b = 0;
	private int c = 125;
	private int d = 326;
	private int e = 257;
	private int f = 216;
	private int h = 385;
	private int j = 191;
	
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
		
		if(e > getWidth()) {
			de = -1;
		}else if(e < 0) {
			de = 1;
		}
		
		if(f > getHeight()) {
			df = -1;
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
		g.fillRect(0, 0,getWidth(), getHeight());
		
		Polygon p = new Polygon();
		p.addPoint(a,b);
		p.addPoint(c,d);
		p.addPoint(e,f);
		p.addPoint(h,j);
		
		g.setColor(Color.YELLOW);
		g.drawPolygon(p);
	}

}
