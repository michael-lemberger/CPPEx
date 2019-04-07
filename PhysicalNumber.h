#include "Unit.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

namespace ariel{	
class PhysicalNumber{
public:

PhysicalNumber();
PhysicalNumber(double, ariel::Unit);
PhysicalNumber(const PhysicalNumber&);


void setValue(double d){ //setter
		this->value = d;
}
double getValue() const { //getter
		return value;
}
Unit getType() const{ 
		return type; 
}

const PhysicalNumber& operator=(const PhysicalNumber&);

PhysicalNumber operator+(const PhysicalNumber&) const;

PhysicalNumber operator+() const;

const PhysicalNumber& operator+=(const PhysicalNumber&);

PhysicalNumber& operator++();

PhysicalNumber operator++(int);

PhysicalNumber operator-(const PhysicalNumber&) const;

PhysicalNumber operator-();

const PhysicalNumber& operator-=(const PhysicalNumber&);

PhysicalNumber& operator--();

PhysicalNumber operator--(int);

bool operator==(const PhysicalNumber&);

bool operator<=(const PhysicalNumber&);

bool operator>=(const PhysicalNumber&);

bool operator!=(const PhysicalNumber&);

bool operator<(const PhysicalNumber&);

bool operator>(const PhysicalNumber&);

friend istream& operator>>(istream&, const PhysicalNumber&);

friend ostream& operator<<(ostream&, const PhysicalNumber&);

void conversion(PhysicalNumber&) const;
	private:
	void Tconvert(int,PhysicalNumber&) const;
	void Lconvert(int,PhysicalNumber&) const;
	void Mconvert(int,PhysicalNumber&) const;
	double value;
	Unit type;
};
}