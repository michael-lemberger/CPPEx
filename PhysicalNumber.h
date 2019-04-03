#include "Unit.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

namespace ariel{	
class PhysicalNumber{
public:

PhysicalNumber();
PhysicalNumber(float, ariel::Unit);


void setValue(float f){ //setter
		this->value = f;
}
float getValue() const { //getter
		return value;
}
Unit getType() const{ 
		return type; 
}

const PhysicalNumber& operator=(const PhysicalNumber&);

PhysicalNumber operator+(const PhysicalNumber&) const;

PhysicalNumber operator+() const;

const PhysicalNumber& operator+=(const PhysicalNumber&);

const PhysicalNumber& operator++();

const PhysicalNumber& operator++(int);

PhysicalNumber operator-(const PhysicalNumber&) const;

PhysicalNumber operator-();

const PhysicalNumber& operator-=(const PhysicalNumber&);

const PhysicalNumber& operator--();

const PhysicalNumber& operator--(int);

bool operator==(const PhysicalNumber&);

bool operator<=(const PhysicalNumber&);

bool operator>=(const PhysicalNumber&);

bool operator!=(const PhysicalNumber&);

bool operator<(const PhysicalNumber&);

bool operator>(const PhysicalNumber&);

	private:
	float value;
	Unit type;
};

istream operator>>(istream&, const PhysicalNumber&);

ostream operator<<(ostream&, const PhysicalNumber&);
}