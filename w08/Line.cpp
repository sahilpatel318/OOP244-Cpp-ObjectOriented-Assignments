/*
Name: Sahil Hareshbhai Patel
ID: 173793225
Email: shpatel27@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iomanip>
#include "Line.h"
#include "Utils.h"
using namespace std;

namespace seneca {

	// Constructor initializes label using base class constructor and sets the line length.
	Line::Line(const char* label, int length) : LblShape(label), mLength(length) {
		if (mLength < ut.strlen(label)) {
			mLength = ut.strlen(label);
		}
	}

	// getSpecs function reads the line's label from the input stream and then its length.
	void Line::getSpecs(istream& istr) {
		LblShape::getSpecs(istr);
		istr >> mLength;
		istr.ignore(1000, '\n');
	}

	// draw function outputs the label followed by a line of "=" characters of length mLength
	void Line::draw(ostream& ostr) const {
		if (mLength > 0 && label()) {
			ostr << label() << endl;
			for (int i = 0; i < mLength; i++) {
				ostr << "=";
			}
		}
	}


}