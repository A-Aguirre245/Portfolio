package com.example;

import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;

public class Canvas extends JPanel {
	private int a = 0;
	private int b = 0;
	private int c = 50;
	private int d = 0;
	private int e = 100;
	private int f = 0;
	private int h = 150;
	private int i = 0;
	private int j = 200;
	private int k = 0;
	private int l = 250;
	private int m = 0;
	private int n = 300;
	private int o = 0;
	private int p = 350;
	private int q = 0;
	private int r = 400;
	private int s = 0;
	private int t = 450;
	private int u = 0;
	private int x = 0;

	private int da = 5;
	private int db = 0;
	private int dc = 5;
	private int dd = 0;
	private int de = 5;
	private int df = 0;
	private int dh = 5;
	private int di = 0;
	private int dj = 5;
	private int dk = 0;
	private int dl = 5;
	private int dm = 0;
	private int dn = 5;
	private int dO = 0;
	private int dp = 5;
	private int dq = 0;
	private int dr = 5;
	private int ds = 0;
	private int dt = 5;
	private int du = 0;

	public void update() {
		if(c + 50 > getWidth()){
			dc = 0;
			dd = 5;
		}else if(e + 50 > getWidth()){
			de = 0;
			df = 5;
		}else if(h + 50 > getWidth()){
			dh = 0;
			di = 5;
		}else if(j + 50 > getWidth()){
			dj = 0;
			dk = 5;
		}else if(l + 50 > getWidth() && x == 0){
			dl = 0;
			dm = 5;
		}else if(n + 50 > getWidth() && x == 0){
			dn = 0;
			dO = 5;
		}else if(p + 50 > getWidth() && x == 0){
			dp = 0;
			dq = 5;
		}else if(r + 50 > getWidth() && x == 0){
			dr = 0;
			ds = 5;
		}else if(t + 50 > getWidth() && x == 0){
			dt = 0;
			du = 5;
		}

		if(f + 50 > getHeight()) {
			de = -5;
			df = 0;
		}else if(i + 50 > getHeight()) {
			dh = -5;
			di = 0;
		}else if(k + 50 > getHeight()){
			dj = -5;
			dk = 0;
		}else if(m + 50 > getHeight() && x == 0){
			dl = -5;
			dm = 0;
		}else if(o + 50 > getHeight() && x == 0){
			dn = -5;
			dO = 0;
		}else if(q + 50 > getHeight() && x == 0){
			dp = -5;
			dq = 0;
		}else if(s + 50 > getHeight() && x == 0){
			dr = -5;
			ds = 0;
		}else if(u + 50 > getHeight() && x == 0){
			dt = -5;
			du = 0;
		}

		if(h < 50) {
			dh = 0;
			di = -5;
		}else if(j < 50) {
			dj = 0;
			dk = -5;
		}else if(l < 50 && x == 0) {
			dl = 0;
			dm = -5;
		}else if(n < 50 && x == 0) {
			dn = 0;
			dO = -5;
		}else if(p < 50 && x == 0) {
			dp = 0;
			dq = -5;
		}else if(r < 50 && x == 0) {
			dr = 0;
			ds = -5;
		}else if(t < 50 && x == 0) {
			dt = 0;
			du = -5;
		}

		if(j < 50 && k < 50) {
			dj = 5;
			dk = 0;
			j = 50;
			k = 50;
			x++;
		}else if(l < 50 && m < 50 && x == 0) {
			dl = 5;
			dm = 0;
			l = 50;
			m = 50;
		}else if(n < 50 && o < 50 && x == 0) {
			dn = 5;
			dO = 0;
			n = 50;
			o = 50;
		}else if(p < 50 && q < 50 && x == 0) {
			dp = 5;
			dq = 0;
			p = 50;
			q = 50;
		}else if(s < 50 && r < 50 && x == 0) {
			dr = 5;
			ds = 0;
			r = 50;
			s = 50;
		}else if(u < 50 && t < 50 && x == 0) {
			dt = 5;
			du = 0;
			t = 50;
			u = 50;
		}

		if(l + 50 > getWidth() - 50 && x == 1) {
			dl = 0;
			dm = 5;
		}else if(n + 50 > getWidth() - 50 && x == 1){
			dn = 0;
			dO = 5;
		}else if(p + 50 > getWidth() - 50 && x == 1){
			dp = 0;
			dq = 5;
		}else if(r + 50 > getWidth() - 50 && x == 1){
			dr = 0;
			ds = 5;
		}else if(t + 50 > getWidth() - 50 && x == 1){
			dt = 0;
			du = 5;
		}

		if(o + 50 > getHeight() - 50 && x == 1){
			dn = -5;
			dO = 0;
		}else if(q + 50 > getHeight() - 50 && x == 1){
			dp = -5;
			dq = 0;
		}else if(s + 50 > getHeight() - 50 && x == 1){
			dr = -5;
			ds = 0;
		}else if(u + 50 > getHeight() - 50 && x == 1){
			dt = -5;
			du = 0;
		}

		if(p < 100 && x == 1) {
			dp = 0;
			dq = -5;
		}else if(r < 100 && x == 1) {
			dr = 0;
			ds = -5;
		}else if(t < 100 && x == 1) {
			dt = 0;
			du = -5;
		}

		if(s < 100 && r < 100 && x == 1) {
			dr = 5;
			ds = 0;
			r = 100;
			s = 100;
			x++;
		}else if(u < 100 && t < 100 && x == 1) {
			dt = 5;
			du = 0;
			t = 100;
			u = 100;
		}

		if(t + 50 > getWidth() - 100 && x == 2){
			dt = 0;
			du = 5;
		}
		if(u + 50 > getHeight() - 100 && x == 2){
			dt = -5;
			du = 0;
		}
		if(t < 150 && x == 2) {
			dt = 0;
			du = -5;
		}
		if(u < 150 && t < 150 && x == 2) {
			dt = 5;
			du = 0;
			t = 150;
			u = 150;
			x++;
		}
		
		if(t + 50 > getWidth() - 150 && x == 3){
			dt = 0;
			du = 5;
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
		n += dn;
		o += dO;
		p += dp;
		q += dq;
		r += dr;
		s += ds;
		t += dt;
		u += du;

		repaint();
	}

	@Override
	protected void paintComponent(Graphics g) {
		// TODO Auto-generated method stub
		super.paintComponent(g);

		g.setColor(Color.RED);
		g.fillRect(0, 0, getWidth(),getHeight());
		g.setColor(Color.BLACK);
		g.fillRect(a, b, 50, 50);
		g.fillRect(c, d, 50, 50);
		g.fillRect(e, f, 50, 50);
		g.fillRect(h, i, 50, 50);
		g.fillRect(j, k, 50, 50);
		g.fillRect(l, m, 50, 50);
		g.fillRect(n, o, 50, 50);
		g.fillRect(p, q, 50, 50);
		g.fillRect(r, s, 50, 50);
		g.fillRect(t, u, 50, 50);
		
		if(u > getHeight()) {
			g.setColor(Color.RED);
			g.fillRect(0, 0, getWidth(), getHeight());
			
			g.setColor(Color.BLACK);
			g.fillRect(100, 150, 50, 300);
			g.fillRect(75, 450, 100, 50);
			g.fillRect(100, 150, 100, 25);
			g.fillRect(200, 150, 50, 200);
			g.fillRect(200, 300, 150, 50);
			g.fillRect(450, 150, 50, 300);
			g.fillRect(425, 450, 100, 50);
			g.fillRect(375, 150, 75, 25);
			g.fillRect(350, 150, 50, 200);
			
		}
		
		if(u > getHeight() * 4) {
			a = 0;
			b = 0;
			c = 50;
			d = 0;
			e = 100;
			f = 0;
			h = 150;
			i = 0;
			j = 200;
			k = 0;
			l = 250;
			m = 0;
			n = 300;
			o = 0;
			p = 350;
			q = 0;
			r = 400;
			s = 0;
			t = 450;
			u = 0;
			x = 0;

			da = 5;
			db = 0;
			dc = 5;
			dd = 0;
			de = 5;
			df = 0;
			dh = 5;
			di = 0;
			dj = 5;
			dk = 0;
			dl = 5;
			dm = 0;
			dn = 5;
			dO = 0;
			dp = 5;
			dq = 0;
			dr = 5;
			ds = 0;
			dt = 5;
			du = 0;

		}

	}
}


