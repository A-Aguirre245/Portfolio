package com.example;

import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;


public class Canvas extends JPanel{

	private int a = 0;
	private int b = 0;
	private int c = 0;
	private int d = 0;
	private int e = 0;

	public void update() {
		a+= Math.random() * (5 - 1 + 1) + 1;
		b+= Math.random() * (5 - 1 + 1) + 1;
		c+= Math.random() * (5 - 1 + 1) + 1;
		d+= Math.random() * (5 - 1 + 1) + 1;
		e+= Math.random() * (5 - 1 + 1) + 1;
		repaint();

		if(a + 20 > getWidth() || b + 20 > getWidth() || c + 20 > getWidth()
				|| d + 20 > getWidth() || e + 20 > getWidth()) {
			a = 0;
			b = 0;
			c= 0;
			d = 0;
			e = 0;
		}

	}

	@Override
	protected void paintComponent(Graphics g) {
		// TODO Auto-generated method stub
		super.paintComponent(g);

		g.setColor(Color.GREEN);
		g.fillRect(0, (800/3), 600, (400/3));

		g.setColor(Color.CYAN);
		g.fillRect(0, 0, 600, (400/3));

		g.setColor(Color.YELLOW);
		g.fillOval(475, 20, 100, 100);

		Color brown = new Color(148, 90, 0);
		g.setColor(brown);
		g.fillRect(0, (400/3), 600, (400/3));

		g.setColor(Color.PINK);
		g.fillRect(a, (400/3) + 10, 20, 20);

		g.setColor(Color.CYAN);
		g.fillRect(b, (400/3) + 35, 20, 20);

		g.setColor(Color.ORANGE);
		g.fillRect(c, (400/3) + 60, 20, 20);

		g.setColor(Color.RED);
		g.fillRect(d, (400/3) + 85, 20, 20);

		g.setColor(Color.YELLOW);
		g.fillRect(e, (400/3) + 110, 20, 20);

	}

}
