/*
Name: Sahil Hareshbhai Patel
ID: 173793225
Email: shpatel27@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Shape.h"

namespace seneca {

	// Overload the stream insertion operator (<<) for Shape objects
	std::ostream& operator<<(std::ostream& ostr, const Shape& shape) {
		shape.draw(ostr);
		return ostr;
	}
	// Overload the stream extraction operator (>>) for Shape objects
	std::istream& operator>>(std::istream& istr, Shape& shape) {
		shape.getSpecs(istr);
		return istr;
	}
}