#include <iostream>
#include "Rational.h"



int main() {

	using namespace std;
	Rational n(5, 3);
	try
	{
	
		Rational s(-1, 2);
		cout <<"PLUS "<< s + n << endl;
		cout <<"MINUS "<< n - s<<endl;
		cout << "PRODUCT "<<n * s << endl;
		cout << "DIVISION "<<n / s << endl;
		// Rational n(3, 0); exception
		//Rational n(0, 3);
		//cout << s / n; exception
		Rational n(1, 2);
		cout <<"++n "<< ++n << endl;
		cout <<"--n " <<--n << endl;
		cout <<"n++ "<< n++ << endl;
		cout <<"n "<< n << endl;
		cout <<"n-- "<< n-- << endl;
		cout <<"n "<< n << endl;
		
		cout << endl;
		cout <<"CALL get_double method: "<< n.get_double() << endl;
		cout <<"Explicit double: " <<double(n)<<endl;
		cout << "CALL get_int method: " << n.get_int() << endl;
		cout << "Explicit int: " << int(n)<< endl;
		cout << "reverse: " << n.get_reverse() << endl;
		Rational v(10, 5);
		cout << "NOD 10 and 5: "<<v;

	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
	}
}