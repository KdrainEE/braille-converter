// Braille Converter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Braille.h"

using namespace std;
int main()
{
	cout << "This program converts enlgish to braille.\nPlease be advised that at this point we can only handle phrases containing letters or numbers\nAll other characters will be printed as spaces." << endl;
	while (true)
	{
		cout << "Enter the phrase you want to translate.\nEnter \"QUIT\" to quit." << endl;
		string thisOne;
		getline(cin, thisOne);
		Braille thisIter(thisOne);
		if (!(thisOne.compare("QUIT")))
			break;
		cout << "In braille, " << thisOne << " is" << endl;
		cout << thisIter << endl;
	}
	cout << "Goodbye" << endl;
    return 0;
}

