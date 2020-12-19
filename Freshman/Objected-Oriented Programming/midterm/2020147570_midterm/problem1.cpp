#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;


int main(){
	int loopNum;

	ifstream infile("input1.txt");

	infile >> loopNum;
	for (int i = 0; i < loopNum; i++) {
		int lineNum;
		infile >> lineNum;
		
		// Problem1 :
		// Print a pyramid of stars by the rule given below
		// 1. The top row starts from a star at the center.
		// 2. The pyramid is of N number of lines.
		// 3. The number of stars per line increases by one with a space in between.
		for (int j = 0; j < lineNum; j++) {
			for (int k = 0; k < lineNum - j - 1; k++)
				cout << " ";
			cout << "*";
			for (int k = 0; k < j; k++)
				cout << " *";
			cout << "\n";
		}
	}

	infile.close();

	return 0;
}
