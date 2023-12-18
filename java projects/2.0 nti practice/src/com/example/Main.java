package com.example;

import java.util.Scanner;
import java.util.ArrayList;

class Main {
	public static void main(String[] args) {
		ArrayList <Integer> numbers = new ArrayList <Integer>();

		numbers.add(2);
		numbers.add(1);
		numbers.add(8);
		numbers.add(7);
		numbers.add(6);
		numbers.add(3);

		int hold = numbers.get(0);

		for(int i = 0; i < numbers.size(); i++){
			for(int j = 0; j < numbers.size() - 1; j++){
				if(numbers.get(j) > numbers.get(j + 1)){
					hold = numbers.get(j);
					numbers.set(i, numbers.get(i+1));
					numbers.set(i + 1, hold);
				}
			}
		}

		for(int element: numbers){
			System.out.println(element);
		}
	}
}

