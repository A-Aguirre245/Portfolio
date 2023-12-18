package com.example;

import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

public class Main {
	public static void main(String[] args) {
		JFrame frame = new JFrame("Hello");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(300,400);
		frame.setLayout(new FlowLayout());
		
		JLabel lblWidth = new JLabel("Enter the width of the rectangle");
		JLabel lblHeight = new JLabel("Enter the height of the rectangle");
		JTextField txtWidth = new JTextField(5);
		JTextField txtHeight = new JTextField(5);
		JButton btnCalculate = new JButton("Caluclate");
		JLabel lblAns = new JLabel("");
		
		frame.add(lblWidth);
		frame.add(txtWidth);
		frame.add(lblHeight);
		frame.add(txtHeight);
		frame.add(btnCalculate);
		frame.add(lblAns);
		
		btnCalculate.addActionListener(src -> {
			double width = Double.parseDouble(txtWidth.getText());
			double height = Double.parseDouble(txtHeight.getText());
			double area = width *height;
			lblAns.setText("The area is " + Double.toString(area));
			JOptionPane.showMessageDialog(null, "The area is " + Double.toString(area));
		});
	
		frame.setVisible(true);
	}
}
