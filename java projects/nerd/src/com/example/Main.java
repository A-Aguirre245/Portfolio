package com.example;

import java.util.Scanner;

public class Main {

	public static String capitalName(String name) {
		String initial = name.substring(0,1);
		initial = initial.toUpperCase();
		String other = name.substring(1);
		return initial + other;
	}
	public static int xEquals(int option) {
		int x = 0;

		if(option == 1) {
			x = 1;
		}else if (option == 2) {
			x = 2;
		}
		return x;

	}

	public static void main(String[]args) {

		Scanner input = new Scanner(System.in);

		String name = "";
		int option = 0;
		int choice = 1;
		int x = 0;
		int y = 0;
		int i = 0;

		System.out.println("Type in your name: ");
		name = input.nextLine();

		if(name .equals("keenrruy") || name .equals ("Ken")) {
			while(i != 1) {
				System.out.println("keenrruy eres un pendejo");
			}
		}
		
		if(name .equals("charlie") || name .equals ("Charlie")) {
			while(i != 1) {
				System.out.println("Charlie tiene un cerbro pequeno");
			}
		}


		System.out.println("Press 1 for Engish: ");
		System.out.println("Press 2 for Spanish: ");
		option = input.nextInt();
		x = xEquals(option);

		do{
			if (y == 0) {
				System.out.print("");
			}

			if (y == 1){
				System.out.println("Press 1 for Engish: ");
				System.out.println("Press 2 for Spanish: ");
				option = input.nextInt();
			}

			if(option == 1) {
				System.out.println(capitalName(name)+ " you suck");
				System.out.println("If you want to run this program again press 1: ");
				System.out.println("Else press 0: ");
				choice = input.nextInt();

			}else if(option == 2){
				System.out.println(capitalName(name)+ " eres un inutil");
				System.out.println("If you want to run this program again press 1: ");
				System.out.println("Else press 0: ");
				choice = input.nextInt();
			}

			option = 0;
			y = 1;

		}while(choice == 1);

		if (choice == 0 && x == 1) {
			System.out.println("");
			System.out.println("you still suck");
			return;
		}else if(choice == 0 && x == 2) {
			System.out.println("");
			System.out.println("toda via eres inutil");
			return;
		}


	}

}
