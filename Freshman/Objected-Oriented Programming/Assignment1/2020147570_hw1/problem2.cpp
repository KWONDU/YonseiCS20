#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
using namespace std;

/**********************/
/*******Problem 2******/
/**********************/
/* ID: 2020147570     */
/* NAME: KWONDONGUK   */
/**********************/

int main(){
	int loopNum;

	ifstream infile("input2.txt");

	infile >> loopNum;
	for (int i = 0; i < loopNum; i++) {
		int lineNum;
		infile >> lineNum;

		for(int j = 0; j < lineNum; j++) {
			for(int k = 0; k < lineNum-1-j; k++) {
				cout << " ";
			}
			for(int k = 0; k < 2*j+1; k++) {
				cout << "*";
			}
			for(int k = 0; k < lineNum-1-j; k++) {
				cout << " ";
			}
			cout << "\n";
		}
	}

	infile.close();

	return 0;
}
