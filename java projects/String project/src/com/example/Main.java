package com.example;

import java.util.Scanner;

public class Main {
	public static void main(String[]args) {
		Scanner input = new Scanner(System.in);
		
		String name = "";
		
		System.out.println("Whats your name: ");
		name = input.nextLine();
		
		String a = name.substring(0,1);
		a = a.toUpperCase();
		String b = name.substring(1);
		a = a + b;
		
		if(a .equals ("Joe")) {
			System.out.println("Who's " + name + "?");
			System.out.println("JOE MAMA");
		}else{
			System.out.println("Hello " + a);
		}
	}
}
