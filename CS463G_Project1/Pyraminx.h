#ifndef PYRAMINX_H
#define	PYRAMINX_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <set>

using namespace std;

class sticker {
	public:
		sticker(string c, int p);
		string getColor();
		int getPosition();
		void setColor(string x);
		void setPosition(int x);

		bool operator==(const sticker& other) const {
			return color == other.color; // Compare the properties
		}

		bool operator<(const sticker& other) const {
			return color < other.color; // Compare the properties
		}

	private:
		string color; // red - R, blue - B, green - B, yellow - Y
		int position; //
};

class face {
	public:
		face();
		face(vector <sticker> s);
		face(face* l, face* r, face* b, vector <sticker> s);

		void setSpots(vector<sticker> setSpots);

		void LtopTwist(int tip);
		void RtopTwist(int tip);

		void LtriTwist(int tri);
		void RtriTwist(int tri);

		void LmidTwist(int mid);
		void RmidTwist(int mid);

		void LbottomTwist(int bottom);
		void RbottomTwist(int bottom);

		int checkFace();
		void aStar(face* front);

		bool operator==(const face& other) const {
			return this->getSpot() == other.getSpot() &&
				this->getLeft() == other.getLeft() &&
				this->getRight() == other.getRight() &&
				this->getBelow() == other.getBelow();
		}

		bool operator<(const face& other) const {
			if (this->getSpot() != other.getSpot()) {
				return this->getSpot() < other.getSpot();
			}
			if (this->getLeft() != other.getLeft()) {
				return this->getLeft() < other.getLeft();
			}
			if (this->getRight() != other.getRight()) {
				return this->getRight() < other.getRight();
			}
			return this->getBelow() < other.getBelow();
		}

		face* getLeft() const;
		face* getRight() const;
		face* getBelow() const;
		vector<sticker> getSpot() const;

		void printFace(string s);
		void printPyraminx(face r, face y, face b, face g);

		void randomMoves(face* front, int moves, int print);

	private:
		vector <sticker> spot;
		face* leftPtr;
		face* rightPtr;
		face* belowPtr;

		typedef void (face::*Method)(int);
		static const int numRot = 8;
		Method rotations[numRot] = {&face::LtopTwist, &face::RtopTwist, &face::LtriTwist, &face::RtriTwist, 
			&face::LmidTwist, &face::RmidTwist, &face::LbottomTwist, &face::RbottomTwist};
};


#endif
