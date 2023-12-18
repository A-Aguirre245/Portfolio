package com.example;

public class Rock {
	
	//making instance variables
	private String color = "";
	private double weight = 0;
	private double pricePC = 0;
	
	//making default constructor
	public Rock(){
		color = "Red";
		weight = 3.25;
		pricePC = .5;
	}
	
	//making initializing constructor
	public Rock(String c, double w) {
		color = c;
		weight = w;
	}
	
	//making getter and setter for color and weight
	public String getColor(){
		return color;
	}
	public void setColor(String c) {
		color = c;
	}
	
	public double getWeight(){
		return weight;
	}
	public void setWeight(double w){
		weight = w;
	}
	
	//making methods for info
	public void displayInfo(){
		System.out.println("The color of the rock is " + color);
		System.out.println("The weight of the rock is " + weight);
	}
	
	//making method for the price of the rock
	public double price(double pricePC){
		return pricePC * weight;
		
	}
	

}
