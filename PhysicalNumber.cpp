#include "PhysicalNumber.h"
#include <stdlib.h>
#include <iostream>
using namespace ariel;

PhysicalNumber::PhysicalNumber(float value, Unit type){
	this->value=value;
	this->type=type;
}

const PhysicalNumber& PhysicalNumber::operator=(const PhysicalNumber& other){
	this->setValue(other.value);
	return *this;
}
	
PhysicalNumber PhysicalNumber::operator+ (const PhysicalNumber& other) const{
	if(abs(this->getType()-(other.type)>=7)){throw "Error: not the same type!";}

return PhysicalNumber(this->getValue()+(other.value),this->getType());
}

PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& other) const{
	if(abs(this->getType()-(other.getType()))>=7){throw "Error: not the same type!";}

return PhysicalNumber(this->getValue()-(other.value),this->getType());
}


PhysicalNumber PhysicalNumber::operator+() const{
	return *this;
}

PhysicalNumber PhysicalNumber::operator-(){
	if(this->getValue()>0)
		this->setValue(-(this->getValue()));
	return *this;
}


const PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& other){
	if(abs(this->getType()-(other.type))>=7){throw "Error: not the same type!";}

	this->setValue(this->value+other.value);

	return *this;
}

const PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& other){
	if(abs(this->getType()-(other.type))>=7){throw "Error: not the same type!";}

	this->setValue(this->value+other.value);	
	return *this;
}

const PhysicalNumber& PhysicalNumber::operator++(){
	this->setValue(this->getValue()+1);

	return *this;
}

const PhysicalNumber& PhysicalNumber::operator--(){
	this->setValue(this->getValue()-1);

	return *this;
}


bool PhysicalNumber::operator==(const PhysicalNumber& other){
	if(this->getValue()==other.value)
		return true;
	return false;
}

bool PhysicalNumber::operator<=(const PhysicalNumber& other){
	if(this->getValue()<=other.value)
		return true;
	return false;
}

bool PhysicalNumber::operator>=(const PhysicalNumber& other){
	if(this->getValue()>=other.value)
		return true;
	return false;
}

bool PhysicalNumber::operator!=(const PhysicalNumber& other){
		if(this->getValue()!=other.value)
		return true;
	return false;
}

bool PhysicalNumber::operator<(const PhysicalNumber& other){
		if(this->getValue()<other.value)
		return true;
	return false;
}

bool PhysicalNumber::operator>(const PhysicalNumber& other){
		if(this->getValue()>other.value)
		return true;
	return false;
}

ostream& operator<<(ostream& stream, const PhysicalNumber& other){
	stream<<other.getValue()<<"["<<other.getType()<<"]";
	return stream;
}

std::istream& operator>>(std::istream& is, const PhysicalNumber& other){
	
}