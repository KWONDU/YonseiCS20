#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

/**********************/
/*******Problem 3******/
/**********************/
/* ID: 2020147570     */
/* NAME: KWONDONGUK   */
/**********************/

int main(){
	int loopNum;

	ifstream infile("input3.txt");

	cout << setprecision(3) << fixed;
	infile >> loopNum;
	for (int i = 0; i < loopNum; i++) {
		double start;
		infile >> start;

		double profit;
		infile >> profit;

		double target;
		infile >> target;

		int day = 0;
		double money = start;
		while (money < target) {
			day++;
			money = money * (1 + profit/100);
			cout << "Day #" << day << ": " << money << "\n";
		}
		cout << "Final income: " << money - start << "\n";
	}

	infile.close();

	return 0;
}
