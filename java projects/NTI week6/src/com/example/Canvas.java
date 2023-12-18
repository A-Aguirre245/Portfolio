package com.example;

import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;

public class Canvas extends JPanel {
	private int a = 0;
	private int b = 0;
	private int c = 540;
	private int d = 540;
	private int e = 250;
	private int f = 250;
	private int h = 250;
	private int i = 250;
	private int j = 250;
	private int k = 250;
	private int l = 250;
	private int m = 250;
	private int x = 0;

	private int da = 5;
	private int db = 0;
	private int dc = -5;
	private int dd = 0;
	private int de = -5;
	private int df = -5;
	private int dh = 5;
	private int di = -5;
	private int dj = 5;
	private int dk = 5;
	private int dl = -5;
	private int dm = 5;


	public void update() {


		if(a + 50 > getWidth()){
			da = 0;
			db = 5;
		}

		if(b + 50 > getHeight()) {
			da = -5;
			db = 0;
		}


		if(a < 0) {
			da = 0;
			db = -5;
		}

		if(b < 0) {
			da = 5;
			db = 0;
			a = 0;
			b = 0;
		}

		if(d + 50 > getHeight()){
			dc = 5;
			dd = 0;
		}

		if(c + 50 > getWidth()) {
			dc = 0;
			dd = -5;
		}

		if(d < 0) {
			dc = -5;
			dd = 0;
		}

		if(c < 0) {
			dc = 0;
			dd = 5;
			c = 0;
			d = 0;
		}

		if(e + 50 > getWidth()) {
			de = -5;
		}else if(e < 0) {
			de = 5;
		}

		if(f + 50 > getHeight()) {
			df = -5;
		}else if(f < 0) {
			df = 5;
		}

		if(h + 50 > getWidth()) {
			dh = -5;
		}else if(h < 0) {
			dh = 5;
		}

		if(i + 50 > getHeight()) {
			di = -5;
		}else if(i < 0) {
			di = 5;
		}

		if(j + 50 > getWidth()) {
			dj = -5;
		}else if(j < 0) {
			dj = 5;
		}

		if(k + 50 > getHeight()) {
			dk = -5;
		}else if(k < 0) {
			dk = 5;
		}

		if(l + 50 > getWidth()) {
			dl = -5;
		}else if(l < 0) {
			dl = 5;
		}

		if(m + 50 > getHeight()) {
			dm = -5;
		}else if(m < 0) {
			dm = 5;
		}


		a += da;
		b += db;
		c += dc;
		d += dd;
		e += de;
		f += df;
		h += dh;
		i += di;
		j += dj;
		k += dk;
		l += dl;
		m += dm;
		repaint();

	}

	@Override
	protected void paintComponent(Graphics g) {
		// TODO Auto-generated method stub
		super.paintComponent(g);
		int col = 1;
		int y = 600;

		Color red = new Color(200, 20, 20);
		Color green = new Color(20, 200, 20);
		Color black = new Color(1, 1, 1);
		Color white = new Color(254, 254, 254);
		Color blue = new Color(20,20,200);
		Color orange = new Color(254,94,0);
		Color yellow = new Color(255,216,0);
		Color purple = new Color(97,24,123);

		for(int x = 0; x < 600; x+=10) {
			if(col == 1) {
				g.setColor(black);
				g.fillRect(x, x, y - x, y - x);
				col++;
				y-= 10;
			}else if(col == 2) {
				g.setColor(white);
				g.fillRect(x, x, y - x, y - x);
				col = 1;
				y-= 10;
			}
		}

		g.setColor(green);
		g.fillRect(a, b, 50, 50);

		g.setColor(red);
		g.fillRect(c, d, 50, 50);

		g.setColor(blue);
		g.fillOval(e, f, 50, 50);

		g.setColor(orange);
		g.fillOval(h, i, 50, 50);

		g.setColor(yellow);
		g.fillOval(j, k, 50, 50);

		g.setColor(purple);
		g.fillOval(l , m, 50, 50);
	}

}
