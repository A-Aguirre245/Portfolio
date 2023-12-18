/*
 * Course: CS216-001
 * Project: Lab 2
 * Purpose: practice how to run unix command from C++ program
 *          system() is used to invoke an operating command from a C++ program
 *          demo cowsay command using three different cow files
 * Author: (Andres Aguirre)
 */

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream cowSays;
    cowSays.open("cowFiles.txt");

    int NUM_OF_COWS = 0; 
    string cowNames;
    
    if(cowSays.fail()){
	   cout << "Error" << endl;
    }
    
    while(getline(cowSays, cowNames))
    {
        // each time use a different cow file for cowsay command to use
        string command_str = "cowsay -f /usr/share/cowsay/cows/";
        command_str = command_str + cowNames;
        command_str = command_str + " Hello, CS216 Students!";
        const char* command = command_str.c_str();
        system(command);
	NUM_OF_COWS++;
    }
    cowSays.close();
   cout << "There are " << NUM_OF_COWS << " cow Files stored in my VM" << endl;
    return 0;
}



