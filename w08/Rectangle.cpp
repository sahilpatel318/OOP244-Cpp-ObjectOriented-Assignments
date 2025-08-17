/*
Name: Sahil Hareshbhai Patel
ID: 173793225
Email: shpatel27@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iomanip>
#include "Rectangle.h"
#include "Utils.h"
using namespace std;

namespace seneca {
	
	// Default constructor initializes a Rectangle with 0 width and height
	Rectangle::Rectangle() : LblShape() {
		mWidth = 0;
		mHeight = 0;
	}

	// Constructor that takes a label, width, and height for the rectangle.
	Rectangle::Rectangle(const char* label, int width, int height)
		: LblShape(label), mWidth(width), mHeight(height) {
		if (mHeight < 3) mHeight = 3;
		if (mWidth < (ut.strlen(label) + 2)) mWidth = ut.strlen(label) + 2;
	}

	// Reads the specifications for the rectangle (label, width, and height) from the input stream
	void Rectangle::getSpecs(istream& istr) {
		LblShape::getSpecs(istr);
		istr >> mWidth;
		istr.ignore();
		istr >> mHeight;
		istr.ignore(1000, '\n');
	}

	// Draws the rectangle to the output stream in a frame-like format
	void Rectangle::draw(ostream& ostr) const {
		if (mHeight > 0) {
			ostr << '+';
			for (int i = 0; i < (mWidth - 2); i++) {
				ostr << '-';
			}
			ostr << '+' << endl;
			ostr << '|';
			ostr.setf(ios::left);
			ostr.width(mWidth - 2);
			ostr << label();
			ostr.unsetf(ios::left);
			ostr << "|" << endl;

			for (int i = 0; i < mHeight - 3; ++i) {
				ostr << "|";
				ostr.width(mWidth - 2);
				ostr.fill(' ');
				ostr << " ";      
				ostr << "|" << endl;
			}
			ostr << '+';
			for (int i = 0; i < (mWidth - 2); i++) {
				ostr << '-';
			}
			ostr << '+';
		}
	}
}