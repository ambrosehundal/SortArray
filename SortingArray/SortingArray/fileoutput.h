
#pragma once
#ifndef FILE_OUTPUT_H
#define FILE_OUTPUT_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Fileoutput
{
public:
	static bool strToFile(string str, string fileout);
};
#endif