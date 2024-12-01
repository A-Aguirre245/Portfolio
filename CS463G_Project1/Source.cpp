#include "Pyraminx.h"

using namespace std;

int main() {
	sticker red("R", 0);
	sticker blue("B", 0);
	sticker green("G", 0);
	sticker yellow("Y", 0);

	vector <sticker> redS;
	vector <sticker> blueS;
	vector <sticker> greenS;
	vector <sticker> yellowS;

	for (int i = 0; i < 16; i++) {
		red.setPosition(i);
		blue.setPosition(i);
		green.setPosition(i);
		yellow.setPosition(i);

		redS.push_back(red);
		blueS.push_back(blue);
		greenS.push_back(green);
		yellowS.push_back(yellow);
	}

	face blueF(blueS);
	face greenF(greenS);
	face yellowF(yellowS);
	face redF(&yellowF, &blueF, &greenF, redS);

	int rotation;
	int option;
	
	cout << "                       Welcome to the 4x4x4 Pyraminx visualizer                    " << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << "|                           Choose 1 for the randomizer                                |" << endl;
	cout << "|    Choose 2 for a closer look at how the pyraminx moves to get to its final goal     |" << endl;
	cout << "|                  Choose 3 to learn a bit more about this project                     |" << endl;
	cout << "|                           Choose 4 for the a* solver                                 |" << endl;
	cout << "|                               Choose -1 to exit                                      |" << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << "|                                           Choice: " << "                                   |";
	cin >> option;

	while (option != -1) {
		cout << "----------------------------------------------------------------------------------------" << endl;

		cout << endl;
			if (option == 1) {
				cout << endl;
				cout << "Enter a number of random moves youd like to make: ";
				cin >> rotation;

				cout << "After " << rotation << " moves, this is what the pyraminx looks like: " << endl;
				redF.randomMoves(&redF, rotation, 0);
				redF.printPyraminx(redF, yellowF, blueF, greenF);
				
			}else if (option == 2) {
				cout << "Enter a number of random moves youd like to make: ";
				cin >> rotation;
				cout << "-------------------------------------------------" << endl;
				redF.randomMoves(&redF, rotation, 1);
				cout << "there are a total of " << redF.checkFace() << " wrong spots";
			}
			else if (option == 3) {
				cout << "                              Introduction and Code Implementation: " << endl;
				cout << "For this project, all the code was created in C++ through Visual Studio and implemented two main objects, Stickers and" 
					<< " Faces, alongside multiple methods to allow rotations. The code has been separated into three files, Pyraminx.h being the" 
					<< " header file, Pyraminx.cpp holding the function definitions from the header, and Source.cpp which runs the program. The" 
					<< " project was written entirely by me, with no sections of code coming from any other online sources, generative AIs such"
					<< " as ChatGPT, or classmates. However, for some help with the implementation of the randomizer, ChatGPT was used as"
					<< " a resource for those. To compile, all you have to do is run the code, and you will be prompted what to do afterward." << endl;
				cout << endl;

				cout << "                                           Data Structure:       " << endl;
				cout << "As mentioned, this project was completed by mainly using two objects.The sticker object held two variables, a "
					<< "color: red, blue, yellow, or green, as well as its position : 0 - 15 with 0, being the top tip, and 9 and 15 being the "
					<< "other points of the triangle. The tips, 0, 9, and 15, also doubled as the axes of rotations for the rotation functions. The "
					<< "Face object held 3 pointers, one to each other face on the pyraminx and a vector that held all current stickers on that face. "
					<< "All rotations were based on an assumption that the pyraminx was held constant, with the red face being the \"main face\"." << endl;
					
				cout << "The randomizer was fairly simple and used an array of pointers to void functions holding all the rotation functions. A random "
					<< "number generator would then return a random indexing number as well as a random axis of rotation, and use those two variables "
					<< "to call a random rotation onto the pyraminx. Below is a figure of how the pyraminx was displayed.The GUI in summary would "
					<< "just print out all the faces, with each spot being shown as the current color it was holding. " << endl;
			}else if (option == 4){
				cout << endl;
				cout << "Enter a number of random moves youd like to make: ";
				cin >> rotation;

				redF.randomMoves(&redF, rotation, 0);
				cout << "Original State: " << endl;
				redF.printPyraminx(redF, yellowF, blueF, greenF);
				redF.aStar(&redF);
			}

		for (int i = 0; i < 16; i++) {
			red.setPosition(i);
			blue.setPosition(i);
			green.setPosition(i);
			yellow.setPosition(i);

			redS.push_back(red);
			blueS.push_back(blue);
			greenS.push_back(green);
			yellowS.push_back(yellow);
		}

		redF.setSpots(redS);
		blueF.setSpots(blueS);
		greenF.setSpots(greenS);
		yellowF.setSpots(yellowS);
		
		cout << "----------------------------------------------------------------------------------------" << endl;
		cout << "|                                           Choice: " << "                                   |";
		cin >> option;

	}




}
