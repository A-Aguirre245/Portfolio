package com.example;

import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		Rock r = new Rock();
		
		//shows info with method and default constructor
		r.displayInfo();
		
		//tests setters
		r.setColor("Blue");
		r.setWeight(4.07);

		//tests getters
		System.out.println("The new color of the rock is " + r.getColor());
		System.out.println("The new weight of the rock is " + r.getWeight());
		
		//tests price method
		double pricePC = .5;
		System.out.println("The total price of the rock is " + r.price(pricePC));

	}
}