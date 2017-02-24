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
	Braille(const Braille& braille);
	Braille(Braille&& braille);
	const std::string& getPhrase() const;
	const std::bitset<8>& getBinRepAt(int index) const;
	friend std::ostream& operator<<(std::ostream& os, Braille br);
	void printBinRep();
	~Braille();

private:
	static const std::bitset<6> capFlag;
	static const std::bitset<6> numFlag;
	static const std::string BitsetBaseVals[10];
	std::string phrase;
	void convert_to_truefalse(std::string str);
	std::bitset<8> *binaryRepresentation;
};

std::ostream & operator<<(std::ostream & os, Braille br);
#endif
