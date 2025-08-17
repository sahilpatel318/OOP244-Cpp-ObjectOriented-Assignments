/*
Name: Sahil Hareshbhai Patel
ID: 173793225
Email: shpatel27@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "LblShape.h"
#include "Utils.h"
#include <cstring>
using namespace std;

namespace seneca {
	
	// Function to return the label of the shape (constant method)
	const char* LblShape::label() const { return mLabel; }

	// Constructor that takes a C-string (label) and allocates memory for it
	LblShape::LblShape(const char* label) {
		mLabel = ut.alocpy(label); // ut.alopcy(m_label, label)
	}

	// Destructor to release the memory allocated for mLabel
	LblShape::~LblShape() {
		delete[] mLabel;
	}

	// Function to read the label from an input stream and store it in mLabel
	void LblShape::getSpecs(istream& istr) {
		char buffer[81];
		istr.getline(buffer, 81, ',');
		ut.alocpy(mLabel, buffer);
	}
}
