#ifndef BRAILLE_H
#define BRAILLE_H

#pragma once

#include <string>
#include <iostream>
#include <bitset>


	
	class Braille
	{
		/*Scope now includes upper and lowercase letters as well as positive integers.
		Anything else will be printed as a space.
		*/
	public:
		Braille(std::string str);
		std::string getPhrase();
		std::bitset<8> getBinRepAt(int index);
		friend std::ostream& operator<<(std::ostream& os, Braille br);
		void printBinRep();
		~Braille();
		

	private:
		std::string BitsetBaseVals[10] = { "00100000", "00110000", "00100100", "00100110", "00100010", "00110100", "00110110", "00110010", "00010100", "00010110"};
		std::string phrase;
		bool* asBooleans;
		void convert_to_truefalse(std::string str);
		std::bitset<8> * binaryRepresentation;


	};
#endif
