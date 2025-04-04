// Copyright (c) 2024 Nathan Greenfield. All rights reserved
#include "strlib.h"
#include <iostream>
#include <string>
#include <sstream>

std::vector<std::string> strSplit(const std::string& str, char splitChar)
{
	// Gets string which is supposed to be str, the testPhrase is similar to stock info, and testVector is gonna be an array that holds variables together
	std::string testPhrase;
	std::vector<std::string> testVector;
	// Gets parts of the string lets us take parts out using the delimiter
	std::stringstream stringStream(str);
	
	// Go through each part of the string until we hit the delimiter
	while (std::getline(stringStream, testPhrase, splitChar))
	{
		testVector.push_back(testPhrase);
	}
	
	return testVector;
}