package com.example;

import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class Main {
	public static void main(String[] args) {

		JFrame frame = new JFrame("Name");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(300, 400);
		frame.setLayout(new FlowLayout());

		JLabel lblName = new JLabel("Enter your full name");
		JTextField txtName = new JTextField(10);
		JButton btnFirstName = new JButton("Display First Name");
		JButton btnEraseName = new JButton("Erase Last name");
		JButton btnSwapName = new JButton("Swap Names");
		JLabel lblFirstName = new JLabel("");

		btnFirstName.addActionListener(src -> {
			String first = txtName.getText();
			int space = first.indexOf(" ");
			String firstName = first.substring(0, space);
			lblFirstName.setText("Your first name is " + firstName);
		});

		btnSwapName.addActionListener(src -> {
			String first = txtName.getText();
			int space = first.indexOf(" ");
			String lastName = first.substring(space + 1);
			txtName.setText(lastName + " " + first.substring(0,space));
		});

		btnEraseName.addActionListener(src -> {
			String first = txtName.getText();
			int space = first.indexOf(" ");
			String firstName = first.substring(0, space);
			txtName.setText(firstName + " " );
		});


		frame.add(lblName);
		frame.add(txtName);
		frame.add(btnFirstName);
		frame.add(btnSwapName);
		frame.add(btnEraseName);
		frame.add(lblFirstName);

		frame.setVisible(true);
	}
}
