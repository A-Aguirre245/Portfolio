#include "Pyraminx.h"

using namespace std;

face::face()
{
	vector<sticker> temp;
	spot = temp;
	leftPtr = NULL;
	rightPtr = NULL;
	belowPtr = NULL;
}

face::face(vector <sticker> s)

{
	spot = s;
	leftPtr = NULL;
	rightPtr = NULL;
	belowPtr = NULL;
}

face::face(face* l, face* r, face* b, vector <sticker> s)
{
	spot = s;
	leftPtr = l;
	rightPtr = r;
	belowPtr = b;
}

void face::setSpots(vector<sticker> setSpots)
{
	spot = setSpots;
}


void face::LtopTwist(int tip) //tip - 0,9,15
{
	string x = "";
	string y = "";
	string z = "";

	if (tip == 0) {
		x = spot[tip].getColor();
		y = leftPtr->spot[tip].getColor();
		z = rightPtr->spot[tip].getColor();

		spot[tip].setColor(z);
		leftPtr->spot[tip].setColor(x);
		rightPtr->spot[tip].setColor(y);
	}
	else if (tip == 9) {
		x = spot[tip].getColor();
		y = leftPtr->spot[15].getColor(); //account for different position on other face
		z = belowPtr->spot[15].getColor(); //account for different position on other face

		spot[tip].setColor(z);
		leftPtr->spot[15].setColor(x);
		belowPtr->spot[15].setColor(y);
	}
	else if (tip == 15){
		x = spot[tip].getColor();
		y = belowPtr->spot[9].getColor(); //account for different position on other face
		z = rightPtr->spot[9].getColor(); //account for different position on other face

		spot[tip].setColor(z);
		belowPtr->spot[9].setColor(x);
		rightPtr->spot[9].setColor(y);
	}	
}

void face::RtopTwist(int tip) //tip - 0,9,15. Exact same as LTopTwist just adjusts to rotate R
{
	string x = "";
	string y = "";
	string z = "";

	if (tip == 0) {
		x = spot[tip].getColor();
		y = leftPtr->spot[tip].getColor();
		z = rightPtr->spot[tip].getColor();

		spot[tip].setColor(y);
		leftPtr->spot[tip].setColor(z);
		rightPtr->spot[tip].setColor(x);
	}
	else if (tip == 9) {
		x = spot[tip].getColor();
		y = leftPtr->spot[15].getColor();
		z = belowPtr->spot[15].getColor();

		spot[tip].setColor(y);
		leftPtr->spot[15].setColor(z);
		belowPtr->spot[15].setColor(x);
	}
	else if (tip == 15) {
		x = spot[tip].getColor();
		y = belowPtr->spot[9].getColor();
		z = rightPtr->spot[9].getColor();

		spot[tip].setColor(y);
		belowPtr->spot[9].setColor(z);
		rightPtr->spot[9].setColor(x);
	}
}



void face::LtriTwist(int tri) //tri - 0,9,15
{
	LtopTwist(tri);

	vector<string> x(3), y(3), z(3);

	if (tri == 0) { //front face is easy, put all colors in a vector, and do a swap on faces
		for (int i = 1; i < 4; i++) {
			x[i - 1] = spot[i].getColor();
			y[i - 1] = leftPtr->spot[i].getColor();
			z[i - 1] = rightPtr->spot[i].getColor();
		}
		for (int i = 0; i < 3; i++) {
			spot[i + 1].setColor(z[i]);
			leftPtr->spot[i + 1].setColor(x[i]);
			rightPtr->spot[i + 1].setColor(y[i]);
		}
	} else if (tri == 9) { //other faces, deal with odd sticker first, first element
		x[0] = (spot[4].getColor());
		y[0] = (leftPtr->spot[8].getColor());
		z[0] = (belowPtr->spot[8].getColor());

		for (int i = 1; i < 3; i++) { //put the sequence of stickers in vector, accounting for positions in other faces
			x[i] = spot[i + 9].getColor();
			y[i] = leftPtr->spot[i + 12].getColor();
			z[i] = belowPtr->spot[i + 12].getColor();
		}

		spot[4].setColor(z[0]); //swap the odd stickers first
		leftPtr->spot[8].setColor(x[0]);
		belowPtr->spot[8].setColor(y[0]);
		
		for (int i = 1; i < 3; i++) {//swap the easy stickers next
			spot[i + 9].setColor(z[i]);
			leftPtr->spot[i + 12].setColor(x[i]);
			belowPtr->spot[i + 12].setColor(y[i]);
		}
	} else if (tri == 15) { //same process, accounting for the right face
		x[0] = spot[8].getColor();
		y[0] = belowPtr->spot[4].getColor();
		z[0] = rightPtr->spot[4].getColor();

		for (int i = 1; i < 3; i++) {
			x[i] = spot[i + 12].getColor();
			y[i] = belowPtr->spot[i + 9].getColor();
			z[i] = rightPtr->spot[i + 9].getColor();
		}

		spot[8].setColor(z[0]);
		belowPtr->spot[4].setColor(x[0]);
		rightPtr->spot[4].setColor(y[0]);
		
		for (int i = 1; i < 3; i++) {
			spot[i + 12].setColor(z[i]);
			belowPtr->spot[i + 9].setColor(x[i]);
			rightPtr->spot[i + 9].setColor(y[i]);
		}
	}
}

void face::RtriTwist(int tri)//tri - 0, 9, 5, Same as LtriTwist but adjusted to be a right twist
{
	RtopTwist(tri);

	vector<string> x(3), y(3), z(3);

	if (tri == 0) { //front face is easy, put all colors in a vector, and do a swap on faces
		for (int i = 1; i < 4; i++) {
			x[i - 1] = spot[i].getColor();
			y[i - 1] = leftPtr->spot[i].getColor();
			z[i - 1] = rightPtr->spot[i].getColor();
		}
		for (int i = 0; i < 3; i++) {
			spot[i + 1].setColor(y[i]);
			leftPtr->spot[i + 1].setColor(z[i]);
			rightPtr->spot[i + 1].setColor(x[i]);
		}
	}
	else if (tri == 9) { //other faces, deal with odd sticker first, first element
		x[0] = (spot[4].getColor());
		y[0] = (leftPtr->spot[8].getColor());
		z[0] = (belowPtr->spot[8].getColor());

		for (int i = 1; i < 3; i++) { //put the sequence of stickers in vector, accounting for positions in other faces
			x[i] = spot[i + 9].getColor();
			y[i] = leftPtr->spot[i + 12].getColor();
			z[i] = belowPtr->spot[i + 12].getColor();
		}

		spot[4].setColor(y[0]); //swap the odd stickers first
		leftPtr->spot[8].setColor(z[0]);
		belowPtr->spot[8].setColor(x[0]);

		for (int i = 1; i < 3; i++) {//swap the easy stickers next
			spot[i + 9].setColor(y[i]);
			leftPtr->spot[i + 12].setColor(z[i]);
			belowPtr->spot[i + 12].setColor(x[i]);
		}
	}
	else if (tri == 15) { //same process, accounting for the right face
		x[0] = spot[8].getColor();
		y[0] = belowPtr->spot[4].getColor();
		z[0] = rightPtr->spot[4].getColor();

		for (int i = 1; i < 3; i++) {
			x[i] = spot[i + 12].getColor();
			y[i] = belowPtr->spot[i + 9].getColor();
			z[i] = rightPtr->spot[i + 9].getColor();
		}

		spot[8].setColor(y[0]);
		belowPtr->spot[4].setColor(z[0]);
		rightPtr->spot[4].setColor(x[0]);

		for (int i = 1; i < 3; i++) {
			spot[i + 12].setColor(y[i]);
			belowPtr->spot[i + 9].setColor(z[i]);
			rightPtr->spot[i + 9].setColor(x[i]);
		}
	}
}

void face::LmidTwist(int mid)
{
	vector<string> x(5), y(5), z(5);

	if (mid == 0) { //front face is easy, put all colors in a vector, and do a swap on faces
		for (int i = 4; i < 9; i++) {
			x[i - 4] = spot[i].getColor();
			y[i - 4] = leftPtr->spot[i].getColor();
			z[i - 4] = rightPtr->spot[i].getColor();
		}
		for (int i = 0; i < 5; i++) {
			spot[i + 4].setColor(z[i]);
			leftPtr->spot[i + 4].setColor(x[i]);
			rightPtr->spot[i + 4].setColor(y[i]);
		}
	}else if (mid == 9) {
		x[0] = spot[1].getColor();
		y[0] = leftPtr->spot[3].getColor();
		z[0] = belowPtr->spot[3].getColor();

		for (int i = 1; i < 5; i++) {
			int j = 4;
			int k = 1;

			if (i > 2) {
				j = 9;
				k = -1;
			}

			x[i] = spot[i + j].getColor();
			y[i] = leftPtr->spot[i + j + k].getColor();
			z[i] = belowPtr->spot[i + j + k].getColor();

		}
		spot[1].setColor(z[3]);
		leftPtr->spot[3].setColor(x[4]);
		belowPtr->spot[3].setColor(y[0]);

		spot[5].setColor(z[4]);
		leftPtr->spot[6].setColor(x[2]);
		belowPtr->spot[6].setColor(y[1]);

		spot[6].setColor(z[1]);
		leftPtr->spot[7].setColor(x[3]);
		belowPtr->spot[7].setColor(y[2]);

		spot[12].setColor(z[2]);
		leftPtr->spot[11].setColor(x[0]);
		belowPtr->spot[11].setColor(y[3]);

		spot[13].setColor(z[0]);
		leftPtr->spot[12].setColor(x[1]);
		belowPtr->spot[12].setColor(y[4]);
	}else if (mid == 15) {
		x[0] = spot[3].getColor();
		y[0] = belowPtr->spot[1].getColor();
		z[0] = rightPtr->spot[1].getColor();

		for (int i = 1; i < 5; i++) {
			int j = 4;
			int k = 1;

			if (i > 2) {
				j = 9;
				k = -1;
			}

			x[i] = spot[i + j + k].getColor();
			y[i] = belowPtr->spot[i + j].getColor();
			z[i] = rightPtr->spot[i + j].getColor();

		}
		spot[3].setColor(z[4]);
		belowPtr->spot[1].setColor(x[3]);
		rightPtr->spot[1].setColor(y[0]);

		spot[6].setColor(z[2]);
		belowPtr->spot[5].setColor(x[4]);
		rightPtr->spot[5].setColor(y[1]);

		spot[7].setColor(z[3]);
		belowPtr->spot[6].setColor(x[1]);
		rightPtr->spot[6].setColor(y[2]);

		spot[11].setColor(z[0]);
		belowPtr->spot[12].setColor(x[2]);
		rightPtr->spot[12].setColor(y[3]);

		spot[12].setColor(z[1]);
		belowPtr->spot[13].setColor(x[0]);
		rightPtr->spot[13].setColor(y[4]);
	}
}

void face::RmidTwist(int mid)
{
	vector<string> x(5), y(5), z(5);

	if (mid == 0) { //front face is easy, put all colors in a vector, and do a swap on faces
		for (int i = 4; i < 9; i++) {
			x[i - 4] = spot[i].getColor();
			y[i - 4] = leftPtr->spot[i].getColor();
			z[i - 4] = rightPtr->spot[i].getColor();
		}
		for (int i = 0; i < 5; i++) {
			spot[i + 4].setColor(y[i]);
			leftPtr->spot[i + 4].setColor(z[i]);
			rightPtr->spot[i + 4].setColor(x[i]);
		}
	}
	else if (mid == 9) {
		x[0] = spot[1].getColor();
		y[0] = leftPtr->spot[3].getColor();
		z[0] = belowPtr->spot[3].getColor();

		for (int i = 1; i < 5; i++) {
			int j = 4;
			int k = 1;

			if (i > 2) {
				j = 9;
				k = -1;
			}

			x[i] = spot[i + j].getColor();
			y[i] = leftPtr->spot[i + j + k].getColor();
			z[i] = belowPtr->spot[i + j + k].getColor();

		}
		spot[1].setColor(y[3]);
		leftPtr->spot[3].setColor(z[0]);
		belowPtr->spot[3].setColor(x[4]);

		spot[5].setColor(y[4]);
		leftPtr->spot[6].setColor(z[1]);
		belowPtr->spot[6].setColor(x[2]);

		spot[6].setColor(y[1]);
		leftPtr->spot[7].setColor(z[2]);
		belowPtr->spot[7].setColor(x[3]);

		spot[12].setColor(y[2]);
		leftPtr->spot[11].setColor(z[3]);
		belowPtr->spot[11].setColor(x[0]);

		spot[13].setColor(y[0]);
		leftPtr->spot[12].setColor(z[4]);
		belowPtr->spot[12].setColor(x[1]);
	}
	else if (mid == 15) {
		x[0] = spot[3].getColor();
		y[0] = belowPtr->spot[1].getColor();
		z[0] = rightPtr->spot[1].getColor();

		for (int i = 1; i < 5; i++) {
			int j = 4;
			int k = 1;

			if (i > 2) {
				j = 9;
				k = -1;
			}

			x[i] = spot[i + j + k].getColor();
			y[i] = belowPtr->spot[i + j].getColor();
			z[i] = rightPtr->spot[i + j].getColor();

		}
		spot[3].setColor(y[4]);
		belowPtr->spot[1].setColor(z[0]);
		rightPtr->spot[1].setColor(x[3]);

		spot[6].setColor(y[2]);
		belowPtr->spot[5].setColor(z[1]);
		rightPtr->spot[5].setColor(x[4]);

		spot[7].setColor(y[3]);
		belowPtr->spot[6].setColor(z[2]);
		rightPtr->spot[6].setColor(x[1]);

		spot[11].setColor(y[0]);
		belowPtr->spot[12].setColor(z[3]);
		rightPtr->spot[12].setColor(x[2]);

		spot[12].setColor(y[1]);
		belowPtr->spot[13].setColor(z[4]);
		rightPtr->spot[13].setColor(x[0]);
	}
}

void face::LbottomTwist(int bottom)
{
	vector<string> x(7), y(7), z(7), a(9), b(7);

	if (bottom == 0) {
		for (int i = 9; i < 16; i++) {
			x[i - 9] = spot[i].getColor();
			y[i - 9] = leftPtr->spot[i].getColor();
			z[i - 9] = rightPtr->spot[i].getColor();
		}
		for (int i = 0; i < 7; i++) {
			spot[i + 9].setColor(z[i]);
			leftPtr->spot[i + 9].setColor(x[i]);
			rightPtr->spot[i + 9].setColor(y[i]);
		}

		for (int i = 0; i < 9; i++) {
			a[i] = belowPtr->spot[i].getColor();
		}

		for (int i = 0; i < 7; i++) {
			b[i] = belowPtr->spot[i + 9].getColor();
		}

		belowPtr->spot[4].setColor(a[3]);
		belowPtr->spot[9].setColor(a[0]);
		belowPtr->spot[10].setColor(a[2]);
		belowPtr->spot[11].setColor(a[1]);

		belowPtr->spot[1].setColor(a[8]);
		belowPtr->spot[5].setColor(a[7]);
		belowPtr->spot[6].setColor(a[6]);
		belowPtr->spot[12].setColor(a[5]);
		belowPtr->spot[13].setColor(a[4]);

		belowPtr->spot[0].setColor(b[6]);
		belowPtr->spot[2].setColor(b[5]);
		belowPtr->spot[3].setColor(b[4]);
		belowPtr->spot[7].setColor(b[3]);
		belowPtr->spot[8].setColor(b[2]);
		belowPtr->spot[14].setColor(b[1]);
		belowPtr->spot[15].setColor(b[0]);

	}else if (bottom == 9) {
		for (int i = 0; i < 7; i++) {
			int j = 0;
			int k = 0;

			if (i > 0) {
				k = 1;
			}
			if (i > 2) {
				k = 3;
				j = 1;
			}
			if (i > 4) {
				k = 5;
				j = 4;
			}

			x[i] = spot[i + j].getColor();
			y[i] = rightPtr->spot[i + j + k].getColor();
			z[i] = belowPtr->spot[i + j + k].getColor();
		}

		spot[0].setColor(y[6]);
		rightPtr->spot[0].setColor(z[0]);
		belowPtr->spot[0].setColor(x[5]);

		spot[1].setColor(y[4]);
		rightPtr->spot[2].setColor(z[1]);
		belowPtr->spot[2].setColor(x[6]);

		spot[2].setColor(y[5]);
		rightPtr->spot[3].setColor(z[2]);
		belowPtr->spot[3].setColor(x[3]);

		spot[4].setColor(y[2]);
		rightPtr->spot[7].setColor(z[3]);
		belowPtr->spot[7].setColor(x[4]);

		spot[5].setColor(y[3]);
		rightPtr->spot[8].setColor(z[4]);
		belowPtr->spot[8].setColor(x[1]);

		spot[9].setColor(y[0]);
		rightPtr->spot[14].setColor(z[5]);
		belowPtr->spot[14].setColor(x[2]);

		spot[10].setColor(y[1]);
		rightPtr->spot[15].setColor(z[6]);
		belowPtr->spot[15].setColor(x[0]);

		vector<string> a(9), b(7);

		for (int i = 0; i < 9; i++){
			a[i] = leftPtr->spot[i].getColor();
		}

		for (int i = 0; i < 7; i++) {
			b[i] = leftPtr->spot[i + 9].getColor();
		}

		leftPtr->spot[15].setColor(a[0]);
		leftPtr->spot[8].setColor(a[1]);
		leftPtr->spot[14].setColor(a[2]);
		leftPtr->spot[13].setColor(a[3]);

		leftPtr->spot[3].setColor(a[4]);
		leftPtr->spot[7].setColor(a[5]);
		leftPtr->spot[6].setColor(a[6]);
		leftPtr->spot[12].setColor(a[7]);
		leftPtr->spot[11].setColor(a[8]);
	
		leftPtr->spot[0].setColor(b[0]);
		leftPtr->spot[1].setColor(b[2]);
		leftPtr->spot[4].setColor(b[4]);
		leftPtr->spot[9].setColor(b[6]);
		leftPtr->spot[2].setColor(b[1]);
		leftPtr->spot[5].setColor(b[3]);
		leftPtr->spot[10].setColor(b[5]);

	}else if (bottom == 15) {
		for (int i = 0; i < 7; i++) {
			int j = 0;
			int k = 0;

			if (i > 0) {
				k = 1;
			}
			if (i > 2) {
				k = 3;
				j = 1;
			}
			if (i > 4) {
				k = 5;
				j = 4;
			}

			x[i] = spot[i + j + k].getColor();
			y[i] = belowPtr->spot[i + j].getColor();
			z[i] = leftPtr->spot[i + j].getColor();
		}

		spot[0].setColor(y[5]);
		belowPtr->spot[0].setColor(z[0]);
		leftPtr->spot[0].setColor(x[6]);

		spot[2].setColor(y[6]);
		belowPtr->spot[1].setColor(z[1]);
		leftPtr->spot[1].setColor(x[4]);

		spot[3].setColor(y[3]);
		belowPtr->spot[2].setColor(z[2]);
		leftPtr->spot[2].setColor(x[5]);

		spot[7].setColor(y[4]);
		belowPtr->spot[4].setColor(z[3]);
		leftPtr->spot[4].setColor(x[2]);

		spot[8].setColor(y[1]);
		belowPtr->spot[5].setColor(z[4]);
		leftPtr->spot[5].setColor(x[3]);

		spot[14].setColor(y[2]);
		belowPtr->spot[9].setColor(z[5]);
		leftPtr->spot[9].setColor(x[0]);

		spot[15].setColor(y[0]);
		belowPtr->spot[10].setColor(z[6]);
		leftPtr->spot[10].setColor(x[1]);

		vector<string> a(9), b(7);

		for (int i = 0; i < 9; i++) {
			a[i] = rightPtr->spot[i].getColor();
		}

		for (int i = 0; i < 7; i++) {
			b[i] = rightPtr->spot[i + 9].getColor();
		}

		rightPtr->spot[15].setColor(a[0]);
		rightPtr->spot[8].setColor(a[1]);
		rightPtr->spot[14].setColor(a[2]);
		rightPtr->spot[13].setColor(a[3]);

		rightPtr->spot[3].setColor(a[4]);
		rightPtr->spot[7].setColor(a[5]);
		rightPtr->spot[6].setColor(a[6]);
		rightPtr->spot[12].setColor(a[7]);
		rightPtr->spot[11].setColor(a[8]);

		rightPtr->spot[0].setColor(b[0]);
		rightPtr->spot[1].setColor(b[2]);
		rightPtr->spot[4].setColor(b[4]);
		rightPtr->spot[9].setColor(b[6]);
		rightPtr->spot[2].setColor(b[1]);
		rightPtr->spot[5].setColor(b[3]);
		rightPtr->spot[10].setColor(b[5]);
	}
}

void face::RbottomTwist(int bottom)
{

	vector<string> x(7), y(7), z(7), a(9), b(7);

	if (bottom == 0) {
		for (int i = 9; i < 16; i++) {
			x[i - 9] = spot[i].getColor();
			y[i - 9] = leftPtr->spot[i].getColor();
			z[i - 9] = rightPtr->spot[i].getColor();
		}
		for (int i = 0; i < 7; i++) {
			spot[i + 9].setColor(y[i]);
			leftPtr->spot[i + 9].setColor(z[i]);
			rightPtr->spot[i + 9].setColor(x[i]);
		}

		for (int i = 0; i < 9; i++) {
			a[i] = belowPtr->spot[i].getColor();
		}

		for (int i = 0; i < 7; i++) {
			b[i] = belowPtr->spot[i + 9].getColor();
		}

		belowPtr->spot[15].setColor(a[0]);
		belowPtr->spot[8].setColor(a[1]);
		belowPtr->spot[14].setColor(a[2]);
		belowPtr->spot[13].setColor(a[3]);

		belowPtr->spot[3].setColor(a[4]);
		belowPtr->spot[7].setColor(a[5]);
		belowPtr->spot[6].setColor(a[6]);
		belowPtr->spot[12].setColor(a[7]);
		belowPtr->spot[11].setColor(a[8]);

		belowPtr->spot[0].setColor(b[0]);
		belowPtr->spot[1].setColor(b[2]);
		belowPtr->spot[4].setColor(b[4]);
		belowPtr->spot[9].setColor(b[6]);
		belowPtr->spot[2].setColor(b[1]);
		belowPtr->spot[5].setColor(b[3]);
		belowPtr->spot[10].setColor(b[5]);
	}
	else if (bottom == 9) {
		for (int i = 0; i < 7; i++) {
			int j = 0;
			int k = 0;

			if (i > 0) {
				k = 1;
			}
			if (i > 2) {
				k = 3;
				j = 1;
			}
			if (i > 4) {
				k = 5;
				j = 4;
			}

			x[i] = spot[i + j].getColor();
			y[i] = rightPtr->spot[i + j + k].getColor();
			z[i] = belowPtr->spot[i + j + k].getColor();
		}

		spot[0].setColor(z[6]);
		rightPtr->spot[0].setColor(x[5]);
		belowPtr->spot[0].setColor(y[0]);

		spot[1].setColor(z[4]);
		rightPtr->spot[2].setColor(x[6]);
		belowPtr->spot[2].setColor(y[1]);

		spot[2].setColor(z[5]);
		rightPtr->spot[3].setColor(x[3]);
		belowPtr->spot[3].setColor(y[2]);

		spot[4].setColor(z[2]);
		rightPtr->spot[7].setColor(x[4]);
		belowPtr->spot[7].setColor(y[3]);

		spot[5].setColor(z[3]);
		rightPtr->spot[8].setColor(x[1]);
		belowPtr->spot[8].setColor(y[4]);

		spot[9].setColor(z[0]);
		rightPtr->spot[14].setColor(x[2]);
		belowPtr->spot[14].setColor(y[5]);

		spot[10].setColor(z[1]);
		rightPtr->spot[15].setColor(x[0]);
		belowPtr->spot[15].setColor(y[6]);

		vector<string> a(9), b(7);

		for (int i = 0; i < 9; i++) {
			a[i] = leftPtr->spot[i].getColor();
		}

		for (int i = 0; i < 7; i++) {
			b[i] = leftPtr->spot[i + 9].getColor();
		}

		leftPtr->spot[4].setColor(a[3]);
		leftPtr->spot[9].setColor(a[0]);
		leftPtr->spot[10].setColor(a[2]);
		leftPtr->spot[11].setColor(a[1]);

		leftPtr->spot[1].setColor(a[8]);
		leftPtr->spot[5].setColor(a[7]);
		leftPtr->spot[6].setColor(a[6]);
		leftPtr->spot[12].setColor(a[5]);
		leftPtr->spot[13].setColor(a[4]);

		leftPtr->spot[0].setColor(b[6]);
		leftPtr->spot[2].setColor(b[5]);
		leftPtr->spot[3].setColor(b[4]);
		leftPtr->spot[7].setColor(b[3]);
		leftPtr->spot[8].setColor(b[2]);
		leftPtr->spot[14].setColor(b[1]);
		leftPtr->spot[15].setColor(b[0]);
		
	}
	else if (bottom == 15) {
		for (int i = 0; i < 7; i++) {
			int j = 0;
			int k = 0;

			if (i > 0) {
				k = 1;
			}
			if (i > 2) {
				k = 3;
				j = 1;
			}
			if (i > 4) {
				k = 5;
				j = 4;
			}

			x[i] = spot[i + j + k].getColor();
			y[i] = belowPtr->spot[i + j].getColor();
			z[i] = leftPtr->spot[i + j].getColor();
		}

		spot[0].setColor(z[5]);
		belowPtr->spot[0].setColor(x[6]);
		leftPtr->spot[0].setColor(y[0]);

		spot[2].setColor(z[6]);
		belowPtr->spot[1].setColor(x[4]);
		leftPtr->spot[1].setColor(y[1]);

		spot[3].setColor(z[3]);
		belowPtr->spot[2].setColor(x[5]);
		leftPtr->spot[2].setColor(y[2]);

		spot[7].setColor(z[4]);
		belowPtr->spot[4].setColor(x[2]);
		leftPtr->spot[4].setColor(y[3]);

		spot[8].setColor(z[1]);
		belowPtr->spot[5].setColor(x[3]);
		leftPtr->spot[5].setColor(y[4]);

		spot[14].setColor(z[2]);
		belowPtr->spot[9].setColor(x[0]);
		leftPtr->spot[9].setColor(y[5]);

		spot[15].setColor(z[0]);
		belowPtr->spot[10].setColor(x[1]);
		leftPtr->spot[10].setColor(y[6]);

		vector<string> a(9), b(7);

		for (int i = 0; i < 9; i++) {
			a[i] = rightPtr->spot[i].getColor();
		}

		for (int i = 0; i < 7; i++) {
			b[i] = rightPtr->spot[i + 9].getColor();
		}

		rightPtr->spot[4].setColor(a[3]);
		rightPtr->spot[9].setColor(a[0]);
		rightPtr->spot[10].setColor(a[2]);
		rightPtr->spot[11].setColor(a[1]);

		rightPtr->spot[1].setColor(a[8]);
		rightPtr->spot[5].setColor(a[7]);
		rightPtr->spot[6].setColor(a[6]);
		rightPtr->spot[12].setColor(a[5]);
		rightPtr->spot[13].setColor(a[4]);

		rightPtr->spot[0].setColor(b[6]);
		rightPtr->spot[2].setColor(b[5]);
		rightPtr->spot[3].setColor(b[4]);
		rightPtr->spot[7].setColor(b[3]);
		rightPtr->spot[8].setColor(b[2]);
		rightPtr->spot[14].setColor(b[1]);
		rightPtr->spot[15].setColor(b[0]);
	}
	
}

int face::checkFace()
{
	int wrongs = 0;

	for (int i = 0; i < 16; i++) {
		if (this->spot[i].getColor() != "R") {
			wrongs++;
		}
		if (this->getLeft()->spot[i].getColor() != "Y") {
			wrongs++;
		}
		if (this->getRight()->spot[i].getColor() != "B") {
			wrongs++;
		}
		if (this->getBelow()->spot[i].getColor() != "G") {
			wrongs++;
		}
	}
	return wrongs;
}

void face::aStar(face* front)
{
	int moves = 0;
	//carefull when copying faces. temp's -> left/right/below ptr also modify fronts ptrs.
	face* temp = new face(*front);
	vector<int> axis = { 0, 9, 15 };
	vector<string> names = { "Left top twist", "Right top twist", "Left tri twist", "Right tri twist", "Left mid twist", "Right mid twist",
							"Left bottom twist", "Right bottom twist" };

	//min heap to track lowest cost states and a set to keep track of visited states
	priority_queue<pair<int, face*>, vector<pair<int, face*>>, greater<pair<int, face*>>> exploreSet; //priority queue
	set<face> visited;
	vector<face> path;
	
	int g = 0;
	int h = temp->checkFace() / 3;
	int fN = g + h;
	exploreSet.push({ fN, temp });
	
	while (!exploreSet.empty()) {
		moves++;
		pair<int, face*> tempPair = exploreSet.top();
		exploreSet.pop();

		face* tempFace = tempPair.second;
		//tempFace->printPyraminx(*tempFace, *tempFace->getLeft(), *tempFace->getRight(), *tempFace->getBelow());
		int currentCost = tempFace->checkFace();
		path.push_back(*tempFace);

		if (currentCost == 0) {
			cout << "SOLVED ! " << moves << " total moves. " << endl << endl;
			path[path.size() - 1].printPyraminx(path[path.size() - 1], *path[path.size() - 1].getLeft(), *path[path.size() - 1].getRight(), *path[path.size() - 1].getBelow());
			delete tempFace;
			return;
		}

		for (int i = 0; i < names.size(); i++) {
			for (int j = 0; j < axis.size(); j++) {
				face* tempYellow = new face(*tempFace->getLeft());
				face* tempBlue = new face(*tempFace->getRight());
				face* tempGreen = new face(*tempFace->getBelow());

				face* currentFace = new face(tempYellow, tempBlue, tempGreen, tempFace->getSpot());
				
				(currentFace->*rotations[i])(axis[j]);
				g++;
				int updateFN = g + currentFace->checkFace() / 3;

				if (visited.find(*currentFace) == visited.end()) {
					exploreSet.push({ updateFN, currentFace });
					visited.insert(*currentFace);
				}
				else {
					// If already visited, delete it to avoid memory leak
					delete currentFace;
				}
			}
		}
		delete tempFace;
	}

	while (!exploreSet.empty()) {
		auto remainingFace = exploreSet.top().second;
		delete remainingFace;
		exploreSet.pop();
	}

	//for (auto visitedFace : visited) {
		//delete visitedFace;
	//}
}


void face::randomMoves(face* front, int moves, int print)
{
	srand(time(0));
	int min = 0;
	int max = 7;
	int max2 = 2;
	vector<int> axis = { 0, 9, 15 };
	vector<string> names = { "Left top twist", "Right top twist", "Left tri twist", "Right tri twist", "Left mid twist", "Right mid twist",
							"Left bottom twist", "Right bottom twist" };

	for (int i = 0; i < moves; i++) {
		int rand = min + std::rand() % (max - min + 1);
		int rand2 = min + std::rand() % (max2 - min + 1);
		(front->*rotations[rand])(axis[rand2]);
		if (print == 1) {
			cout << names[rand] << ", Rotation on axis: " << axis[rand2] << endl;
			front->printPyraminx(*front, *front->getLeft(), *front->getRight(),  *front->getBelow());
			cout << "-------------------------------------------------" << endl;
		}
	}
}

face* face::getLeft() const
{
	return leftPtr;
}

face* face::getRight() const
{
	return rightPtr;
}

face* face::getBelow() const
{
	return belowPtr;
}

vector<sticker> face::getSpot() const
{
	return spot;
}


void face::printFace(string s)
{
	cout << s << " Face: " << endl;

	for (int i = 0; i < 16; i++) {
		if (i == 0 || i == 1 || i == 4) {
			for (int j = (3 - sqrt(i)); j > 0; j--) {
				cout << " ";
			}
		}if (i == 0 || i == 3 || i == 8) {
			cout << spot[i].getColor() << endl;
		}else {
			cout << spot[i].getColor();
		}
	}

	cout << endl << endl;
}

void face::printPyraminx(face r, face y, face b, face g)
{
	r.printFace("Red");
	y.printFace("Yellow");
	b.printFace("Blue");
	g.printFace("Green");
}

sticker::sticker(string c, int p)
{
	color = c;
	position = p;
}

string sticker::getColor()
{
	return color;
}

int sticker::getPosition()
{
	return position;
}

void sticker::setColor(string x)
{
	color = x;
}

void sticker::setPosition(int x)
{
	position = x;
}