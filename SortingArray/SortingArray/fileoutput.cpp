#include "stdafx.h"
#include "Fileoutput.h"

using namespace std;

/*Writes array sort output to result.txt file*/

bool Fileoutput::strToFile(string str, string fileout)
{
	bool flag = false;
	ofstream resultFile;
	resultFile.open(fileout);
	resultFile << "Ambrose Hundal - Lab 4" << endl;
	
	if (resultFile)
	{
		resultFile << str;
		resultFile.close();
	}
	return flag;
}