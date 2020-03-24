#pragma once
#include <iostream>
#include <istream>


class Rational
{
public:
	Rational();
	Rational(int numerator);
	Rational(int numerator, int denomirator);
	int get_int();
	double get_double();
	Rational get_reverse();
	explicit operator double() {return this->get_double();}
	explicit operator int() {return this->get_int();}

	// input/output
	friend std::istream& operator >>(std::istream& is, Rational& number);
	friend std::ostream& operator <<(std::ostream& os, const Rational& number);

	// compare operators
	friend bool operator ==(const Rational& one, const Rational& two);
	friend bool operator !=(const Rational& one, const Rational& two);
	friend bool operator >(const Rational& one, const Rational& two);
	friend bool operator <(const Rational& one, const Rational& two);
	friend bool operator >=(const Rational& one, const Rational& two);
	friend bool operator <=(const Rational& one, const Rational& two);

	//binary operators
	friend Rational& operator+=(Rational& one, const Rational& two);
	friend Rational& operator-=(Rational& one, const Rational& two);
	friend Rational& operator*=(Rational& one, const Rational& two);
	friend Rational& operator/=(Rational& one, const Rational& two);
	friend const Rational operator +(const Rational& one, const Rational& two);
	friend const Rational operator -(const Rational& one, const Rational& two);
	friend const Rational operator *(const Rational& one, const Rational& two);
	friend const Rational operator /(const Rational& one, const Rational& two);

	// unary operators
	friend const Rational& operator +(const Rational& one);
	friend const Rational& operator -(const Rational& one);
	friend const Rational& operator ++(Rational& one);
	friend const Rational& operator --(Rational& one);
	friend const Rational operator ++(Rational& one, int);
	friend const Rational operator --(Rational& one, int);


private:
	void cut_number();
	int numerator;
	int denominator;

};

