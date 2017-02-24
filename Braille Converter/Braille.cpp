#include "stdafx.h"
#include "Braille.h"

/********************************************\
	++++++++ NOTE TO SELF +++++++
	NEVER, AND I MEAN NEVER, PUT ANYTING
	IN THE FILE BEFORE THE PRECOMPILED HEADER
\*********************************************/

using namespace std;
	//constants
	const std::bitset<6> Braille::capFlag(0x1);
	const std::bitset<6> Braille::numFlag(0xf);
	const string Braille::BitsetBaseVals[10] = { "00100000", "00110000", "00100100", "00100110",
		"00100010", "00110100", "00110110", "00110010", "00010100", "00010110" };
	//constructor
	Braille::Braille(string str){
		this->phrase = str;
		binaryRepresentation = new bitset<8>[phrase.length()];
		convert_to_truefalse(phrase);
	}

	//copy constructor
	Braille::Braille(const Braille& braille)
	{
		phrase = braille.phrase;
		binaryRepresentation = new bitset<8>[phrase.length()];
		memcpy(binaryRepresentation, braille.binaryRepresentation, sizeof(bitset<8>)*phrase.length());

	}
	//move constructor
	Braille::Braille(Braille&& braille)
	{
		phrase = std::move(braille.phrase);
		binaryRepresentation = braille.binaryRepresentation;
		braille.binaryRepresentation = nullptr;
	}
	//class destructor
	Braille::~Braille()
	{
		delete[] binaryRepresentation;
	}
	//returns the phrase memeber of the Braille object
	const string& Braille::getPhrase() const// this second "const" ensures that the function doesn't change any of the members of the instance it is tied to 
	{
		return phrase;
	}

	const bitset<8>& Braille::getBinRepAt(int index) const
	{
		return binaryRepresentation[index];
	}
	/*
	Takes the input string and modifies the instance's binaryRepresentation 
	variable to point to indiviual bitset values for each character that 
	contain the actual bianry representation as well as flags declaring if the
	character is a number or a capital letter.
	*/
	void Braille::convert_to_truefalse(string str){
		for (int i = 0; i < (int) phrase.length(); i++)
		{			
			int w = 29;
			int letter = phrase.at(i) - 97;
			int * let = &letter;
			
			bool isCapital = false;
			bool isNumber = false;
			
			//CHECK FOR ABNORMALITIES
			if (*let >= -32 && *let <= -7)//capital letter
			{
				isCapital = true;
				*let += 32;
			}
			else if (*let == -49)//zero
				*let = 9;
			else if(*let >= -48 && *let <= -40)	//number 1-9
			{	
				isNumber = true;
				*let += 48;

			}
			//MAIN ROUTINE
			if (*let == 23 || *let == 24 ||*let == 25)//need to shift x, y, and z left to deal with the abnormality of w
			{
				*let -= 1;
			}
			else if (*let == 22)
			{
				*let = 29;
			}

			int row = *let / 10;
			int column = *let % 10;
			bitset<8> binVal(BitsetBaseVals[column]);
			if (row == 0)
			{
				//do nothing
			}
			else if (row == 1)
			{
				binVal.set(3, 1);
			}
			else if (row == 2 && column == 9)
				binVal.set(0, 1);
			else if (row == 2)
			{
				binVal.set(3, 1);
				binVal.set(0, 1);
			}
			/*if the given character doesn't fit any above conditions ie. it is not a number or letter or any kind 
			it is printed as a space*/
			else 
			{
				binVal.reset();
			}
			/*
				MSB will be the isCapital flag
				MSB-1 will be the isNumber flag
			*/
			if (isCapital)
				binVal.set(7, 1);
			else if (isNumber)
				binVal.set(6, 1);

			//add final value to the storage array
			binaryRepresentation[i] = binVal;
		}
	}

	
	std::ostream & operator<<(std::ostream & os, Braille br)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < (int)br.getPhrase().length(); j++)//each iteration of this loop should print one of the three lines of dots for the braille phrase
			{
				bitset<8> curr = br.getBinRepAt(j);
				
				string printVal1 = curr.test(5-i) == 1 ? "." : " ";
				string printVal2 = curr.test(5-i-3) == 1 ? "." : " ";
				if (curr.test(7) == 1){
					string v1 = Braille::capFlag.test(5 - i) == 1 ? "." : " ";
					string v2 = Braille::capFlag.test(5 - i - 3) == 1 ? "." : " ";
					std::cout << v1 << " " << v2 << " ";
				}
				else if (curr.test(6) == 1){
					string v1 = Braille::numFlag.test(5 - i) == 1 ? "." : " ";
					string v2 = Braille::numFlag.test(5 - i - 3) == 1 ? "." : " ";
					std::cout << v1 << " " << v2 << " ";
				}
				std::cout << printVal1 << " " << printVal2 << " ";
			}
			std::cout << endl;
		}
		return os;
	}

	void Braille::printBinRep()
	{
		for (int i = 0; i < (int)phrase.length(); i++)
		{
			bitset<8> temp(getBinRepAt(i));
			if (temp.test(7))
				cout << Braille::capFlag;
			else if (temp.test(6))
				cout << Braille::numFlag;
			cout << temp.to_string().substr(2);
		}
		cout << endl;
	}


