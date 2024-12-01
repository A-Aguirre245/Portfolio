package com.example;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		String option = "";
		double numOne = 1;
		String type = "";
		double ans = 0;
		String stop = "";
		double numTwo = 0;

		System.out.println("Hello welcome to the calculator");
		System.out
				.println("This calculator is able to add, subtract, multiply, and divide as many numbers as you want.");
		do {
			System.out.println("Do you want to add, subtract, multiply, or divide?: ");
			type = input.nextLine();

			if (type.equals("add")) {
				System.out.println("Type the number you want to add: ");
				numOne = input.nextDouble();
				ans = ans + numOne;
				while (!stop.equals("stop")) {
					System.out.println("Type the number you want to add: ");
					numOne = input.nextDouble();
					input.nextLine();
					ans = ans + numOne;
					System.out.println("If you are done type stop, if you want to continue press enter: ");
					stop = input.nextLine();
				}
				System.out.println("The sum of those numbers is: " + ans);

			} else if (type.equals("subtract")) {
				System.out.println("Type the number you want to subtract: ");
				numOne = input.nextDouble();
				ans = numOne;
				stop = "0";
				while (!stop.equals("stop")) {
					System.out.println("Type the number you want to subtract: ");
					numOne = input.nextDouble();
					input.nextLine();
					ans = ans - numOne;
					System.out.println("If you are done type stop, if you want to continue press enter: ");
					stop = input.nextLine();
				}

				System.out.println("The diffrence of those numbers is: " + ans);

			} else if (type.equals("multiply")) {
				ans = 1;
				System.out.println("Type the number you want to multiply: ");
				numOne = input.nextDouble();
				ans = ans * numOne;
				stop = "0";

				while (!stop.equals("stop")) {
					System.out.println("Type the number you want to multiply: ");
					numOne = input.nextDouble();
					input.nextLine();
					ans = ans * numOne;
					System.out.println("If you are done type stop, if you want to continue press enter: ");
					stop = input.nextLine();
				}
				System.out.println("The product of those numbers is: " + ans);

			} else if (type.equals("divide")) {
				System.out.println("Type the number you want to divide: ");
				numOne = input.nextDouble();
				ans = numOne;
				stop = "0";
				while (!stop.equals("stop")) {
					System.out.println("Type the number you want to divide: ");
					numOne = input.nextDouble();
					input.nextLine();
					ans = ans / numOne;
					System.out.println("If you are done type stop, if you want to continue press enter: ");
					stop = input.nextLine();
				}
				System.out.println("The qoutient of those numbers is: " + ans);
			}

			System.out.println("If you still want to use the calculator press enter, if you are done, type off: ");
			option = input.nextLine();

		} while (!option.equals("off"));

		System.out.println("Thank you for using this calculator");
	}
}
