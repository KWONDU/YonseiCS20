#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <iomanip>
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
		
		int len;
		int num = 0;
		int sum = 0;
		infile >> len;
		//convert binary number to demical number except parity bit
		for (int j = 0; j < len; j++) {
			int bin;
			infile >> bin;
			if (bin == 1) {
				num ++;
				sum += int(pow(2, len - j));
			}
		}
		//apply parity bit
		char parity;
		infile >> parity;
		if (num%2 == 0) {
			if (parity == 'o') {
				sum += 1;
			}
		}
		else {
			if (parity == 'e') {
				sum += 1;
			}
		}
		//print
		cout << sum << endl;
	}

	infile.close();

	return 0;
}
