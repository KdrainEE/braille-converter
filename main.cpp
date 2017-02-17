// Braille Converter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Braille.h"

using namespace std;
int main()
{
	/*Braille test1 = Braille("h");
	Braille test2 = Braille("P");
	Braille test3 = Braille("4");
	Braille test4 = Braille("f");
	Braille test5 = Braille("p");
	Braille test6 = Braille("s");
	Braille test7 = Braille("v");*/
	Braille test8 = Braille("kyle");
	Braille test9 = Braille("Kyle");
	Braille test10 = Braille("1234");
	Braille test11 = Braille("xyz");

	cout << test8.getPhrase() << endl;
	cout << test8 << endl;

	cout << test9.getPhrase() << endl;
	cout << test9<< endl;

	cout << test10.getPhrase() << endl;
	cout << test10 << endl;

	cout << test11.getPhrase() << endl;
	cout << test11 << endl;

	
	/*cout << test1.getPhrase() << endl;
	cout << test1 << endl;

	cout << test2.getPhrase() << endl;
	cout << test2 << endl;
	
	cout << test3.getPhrase() << endl;
	cout << test3 << endl;

	cout << test4.getPhrase() << endl;
	cout << test4 << endl;

	cout << test5.getPhrase() << endl;
	cout <<test5 << endl;

	cout << test6.getPhrase() << endl;
	cout << test6 << endl;

	cout << test7.getPhrase() << endl;
	cout << test7 << endl;*/


	cin.get();

    return 0;
}

