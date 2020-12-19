#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

/**********************/
/*******Problem 1******/
/**********************/
/* ID: 2020147570     */
/* NAME: KWONDONGUK   */
/**********************/

int main(){
	int loopNum;

	ofstream outfile;
	outfile.open("output1.txt");

	cout << "Enter the number of interations for the loop: ";
	cin >> loopNum;

	for (int i = 0; i < loopNum; i++) {
		int a, b, c, d;
		cout << "Enter the coefficients of the equation [y = ax^3 + bx^2 + cx + d]" << endl;
		cout << "a: "; cin >> a;
		cout << "b: "; cin >> b;
		cout << "c: "; cin >> c;
		cout << "d: "; cin >> d;

        // To fix the precision of floating numbers
	outfile << setprecision(3) << fixed;

		if (pow(b, 2) - 3*a*c < 0)
			outfile << "Not Available.\n";
		else if (pow(b, 2) - 3*a*c == 0)
			outfile << (double)(-b)/(3*a) << "\n";
		else
			outfile << (double)(-b+sqrt(pow(b, 2)-3*a*c))/(3*a) << " " <<(double)(-b-sqrt(pow(b, 2)-3*a*c))/(3*a) << "\n";

	}

	outfile.close();

	return 0;
}
