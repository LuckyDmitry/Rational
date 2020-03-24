#include "Rational.h"

Rational::Rational() {

	numerator = 0;
	denominator = 1;
}

Rational::Rational(int numerator) :Rational() {

	this->numerator = numerator;
}

Rational::Rational(int numerator, int denominator) : Rational(numerator) {
	
	if (denominator == 0) {
		throw std::logic_error("excepted denominator doesn't equal 0 " __FUNCTION__);
	}
	this->denominator = denominator;
	cut_number();
}

int Rational::get_int(){ // get integer value

	return numerator / denominator;
}


double Rational::get_double(){ // get double value

	return double(numerator) / denominator;
}

Rational Rational::get_reverse(){ 

	return Rational(this->denominator, this->numerator);
}

void Rational::cut_number(){ // NOD algorithm Euclid

	int a = this->numerator;
	int b = this->denominator;
	while (b != 0) {
		a %= b;
		std::swap(a, b);
	}
	this->numerator /= a;
	this->denominator /= a;
}

std::istream& operator>>(std::istream& is, Rational& number){ // enter numbers

	is >> number.numerator;
	is >> number.denominator;
	if (number.denominator == 0) {
		throw std::logic_error("Excepted doesn't equal to zero");
	}
	number.cut_number();
	return is;
}

std::ostream& operator<<(std::ostream& os, const Rational& number){	// display numbers
	

	os << number.numerator;
	if (number.denominator == 1) {
		return os;
	}
	os << '/' << number.denominator;
	return os;
}

bool operator==(const Rational& one, const Rational& two){ // compare two numbers for equality
	
	if (one.numerator == two.numerator or one.denominator == two.denominator) {
		return true;
	}
	return false;
}

bool operator!=(const Rational& one, const Rational& two) { // compare two numbers for unequality

	return (!(one == two));
}

bool operator>(const Rational& one,const Rational& two){ // compare one number more than another

	if (one.numerator * two.denominator > two.numerator* one.denominator) {
		return true;
	}
	return false;
}

bool operator<(const Rational& one, const Rational& two){ //compare one number less than another

	return (!(one > two));
}

bool operator>=(const Rational& one, const Rational& two){ //more than or equal

	if (one.numerator*two.denominator >= two.numerator * one.denominator) {
		return true;
	}
	return false;
}

bool operator<=(const Rational& one, const Rational& two){	//less than or equal

	return (!(one>=two));
}

Rational& operator+=(Rational& one, const Rational& two){

	one.numerator = (one.numerator * two.denominator) 
					+ (two.numerator * one.denominator); // get common denominator and add numerators
	one.denominator *= two.denominator;
	one.cut_number();
	return one;
}

Rational& operator-=(Rational& one, const Rational& two) {

	one.numerator = (one.numerator * two.denominator)
		- (two.numerator * one.denominator); // get common denominator and add numerators
	one.denominator *= two.denominator;
	one.cut_number();
	return one;
}
Rational& operator*=(Rational& one, const Rational& two) {

	one.numerator *= two.numerator;
	one.denominator *= two.denominator;
	one.cut_number();
	return one;
}

Rational& operator/=(Rational& one, const Rational& two) {

	one.numerator *= two.denominator;
	one.denominator *= two.numerator;
	if (one.denominator == 0) {
		throw std::logic_error("Numerator doest't should be a zero this case");
	}
	one.cut_number();
	return one;
}

const Rational operator+(const Rational& one, const Rational& two){

	return Rational((one.numerator * two.denominator) + (two.numerator * one.denominator), 
					one.denominator* two.denominator);
}

const Rational operator-(const Rational& one, const Rational& two) {

	return Rational((one.numerator * two.denominator) - (two.numerator * one.denominator),
					one.denominator * two.denominator);
}

const Rational operator*(const Rational& one, const Rational& two) {

	return Rational((one.numerator * two.numerator) ,
					one.denominator * two.denominator);
}

const Rational operator/(const Rational& one, const Rational& two) {

	return Rational((one.numerator * two.denominator),
		one.denominator * two.numerator);
}

const Rational& operator+(const Rational& one){
	
	return one;
}

const Rational& operator-(const Rational& one) {

	return Rational(-one.numerator, one.denominator);
}

const Rational& operator++(Rational& one){

	one.numerator += one.denominator;
	one.cut_number();
	return one;
}

const Rational operator++(Rational& one, int){

	Rational oldValue(one.numerator, one.denominator);
	one.numerator += one.denominator;
	one.cut_number();
	return oldValue;
}

const Rational& operator--(Rational& one) {

	one.numerator -= one.denominator;
	one.cut_number();
	return one;
}

const Rational operator--(Rational& one, int) {

	Rational oldValue(one.numerator, one.denominator);
	one.numerator -= one.denominator;
	one.cut_number();
	return oldValue;
}

