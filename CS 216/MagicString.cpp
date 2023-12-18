/* 
 * File:   MagicString.cpp
 * Purpose: provide the definition of the MagicString class
 *
 * Author: (Andres Aguirre)
 *
 */
#include <iostream>
#include <stack>
#include "MagicString.h"

// initialize str with ini_str passing as a parameter
MagicString::MagicString(string ini_str)
{
	str = ini_str;
}

// return the current value of the private data member: str
string MagicString::getString() const
{
	return str;
}

// set the value of str to be the passed in parameter input_str
void MagicString::setString(string input_str)
{
	str = input_str;
}

// return a reverse string
// using a loop to implement
// Note that the private data member named str, has not been changed
string MagicString::rev_loop() const
{
	int length = str.length();
	if(length > 0){
		length--;
	}
	string reverse;
	for(int i = length; i >= 0; i--){
		reverse = reverse + str.substr(i, 1);
	}
	return reverse;
}

// return a reverse string
// using recursion to implement
// Note that the private data member named str, has not been changed
string MagicString::rev_recursion() const
{
	string reverse;
	int length = str.length(); 
	if(length == 0){
		return reverse;
	}else{
		reverse = reverse + str.substr(length - 1);
		MagicString temp(str.substr(0, length - 1)); 
		return reverse + temp.rev_recursion();
	}
}

// return a reverse string
// using a stack to implement
// Note that the private data member named str, has not been changed
string MagicString::rev_stack() const
{
	string reverse;
	stack<string> strsta;
	
	for(int i = 0; i < str.length(); i++){
		strsta.push(str.substr(i, 1));
	}

	while(!strsta.empty()){
		reverse = reverse + strsta.top();
		strsta.pop();
	}
	return reverse;
}

// return true if str is a palindrome
// otherwise return false
// A palindrome is defined as a sequence of characters which reads the same backward as forward
// calling member function to  implement
// Note that the private data member named str, has not been changed
bool MagicString::isPalindrome() const
{
	int length = str.length();
	bool isPalin = true;

	for(int i = 0; i < length; i++){
		if(str.substr(i, 1) == str.substr(length - 1 - i, 1)){
		       isPalin = true;
	      	}else{
	 		isPalin = false;
			return isPalin;
		}
	}
	return isPalin;	
}
        
// return true if str is a palindrome
// otherwise return false
// A palindrome is defined as a sequence of characters which reads the same backward as forward
// using recursion to implement
// Note that the private data member named str, has not been changed
bool MagicString::isPalindrome_recursion() const
{
	bool isPalin = true;
	int length = str.length();

	if(length == 0){
		return isPalin;
	}else{
		if(str.substr(0, 1) == str.substr(length - 1)){
			isPalin = true;
			MagicString temp (str.substr(1, length - 2));
			return temp.isPalindrome_recursion();
		}else{
			isPalin = false;
			return isPalin;
		}
	}
}
        
// displays str followed by a new line marker
// to the standard output
void MagicString::print() const
{
	cout << str << endl;
}
