#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;


int powerNum(int base, int exponent);
int numLength(int number);
int getPosDigit(int number, int position);

class Septenary {
    private:
        int decimal;

        int sept2Dec(int sept) {
            // Problem 3-1 : Conversion from septenary number to corresponding decimal number
            // input (int) : integer number in septenary
            // output (int) : integer number in decimal
            int dec = 0;
	    for (int i = 0; i < numLength(sept); i++)
		    dec += getPosDigit(sept, i) * powerNum(7, numLength(sept) - i - 1);
	    return dec;
        }

        int dec2Sept(int dec) {
            // Problem 3-2 : Conversion from decimal number to corresponding septenary number
            // input (int) : integer number in decimal
            // output (int) : integer number in septenary
            int sept = 0;
	    for (int i = 0; i < numLength(dec); i++)
		    sept += getPosDigit(dec, i) * powerNum(10, numLength(dec) - i - 1);
	    return sept;
        }

    public:
        Septenary(int septenary) {
            // Septenary class holds the number in decimal automatically
            decimal = sept2Dec(septenary);
        }
        int getDec(void) { return decimal; }
        int getSept(void) { return dec2Sept(decimal); }

        // Problem 3-3 : Overloading of four operators for the class
        // output (int) : integer number of result in septenary number
        const Septenary operator +(const Septenary& s1, const Septenary& s2) {
		int addition = s1.getDec() + s2.getDec();
		int sept = 0;
           	for (int i = 0; i < numLength(addition); i++)
                	sept += getPosDigit(addition, i) * powerNum(10, numLength(addition) - i - 1);
		return sept;
	}
	const Septenary operator -(const Septenary& s1, const Septenary& s2) {
		int subtraction = s1.getDec() - s2.getDec();
		int sept = 0;
		for (int i = 0; i < numLength(subtraction); i++)
			sept += getPosDigit(subtraction, i) * powerNum(10, numLength(subtraction) - i - 1);
		return Septenary(sept);
	}
	const Septenary operator *(const Septenary& s1, const Septenary& s2) {
		int multiplication = s1.getDec() * s2.getDec();
		int sept = 0;
		for (int i = 0; i < numLength(multiplication); i++)
			sept += getPosDigit(multiplication, i) * powerNum(10, numLength(multiplication) - i - 1);
		return Septenary(sept);
	}
	const Septenary operator /(const Septenary& s1, const Septenary& s2) {
		int division = s1.getDec() / s2.getDec();
		int sept = 0;
		for (int i = 0; i < numLength(multiplication); i++)
			sept += getPosDigit(multiplication, i) * powerNum(10, numLength(division) - i - 1);
		return Septenary(sept);
	}
};



/*
You MUST NOT touch the code below.
If modified temporally, make sure you've restored the code when submitting.
*/

int powerNum(int base, int exponent) {
    // input (int, int)
    // output (int) : base^exponent
    // example : base=3, exponent=4 --> 3^4 = 81
    int retNum = 1;
    for(int i = 0; i < exponent; i++) {
        retNum *= base;
    }

    return retNum;
}

int numLength(int number) {
    // input (int)
    // output (int) : length of number
    // example1 : number=10392 --> 5
    // example2 : number=428   --> 3
    int length = 1;
    while(number / 10) {
        number /= 10;
        length++;
    }

    return length;
}

int getPosDigit(int number, int position) {
    // input (int, int) : position starting from 0
    // output (int) : length of number
    // example1 : number=10392, position=3 --> 9
    // example2 : number=428,   position=0 --> 4
    // example2 : number=3690,  position=1 --> 6
    int exponent = (numLength(number)-1) - position;
    int digit = (number / powerNum(10, exponent)) % 10;

    return digit;
}

int main(){
	ifstream infile("input3.txt");

	int loopNum;
	infile >> loopNum;
	for (int i = 0; i < loopNum; i++) {
        cout << "### Problem " << i+1 << " ###" << endl;
        int num1, num2;
        infile >> num1;
        infile >> num2;

        Septenary sept1 = Septenary(num1);
        Septenary sept2 = Septenary(num2);
        cout << sept1.getSept() << " in decimal: " << sept1.getDec() << endl;
        cout << sept2.getSept() << " in decimal: " << sept2.getDec() << endl;
        cout << "Num1 + Num2: " << sept1 + sept2 << endl;
        cout << "Num1 - Num2: " << sept1 - sept2 << endl;
        cout << "Num1 * Num2: " << sept1 * sept2 << endl;
        cout << "Num1 / Num2: " << sept1 / sept2 << endl << endl;
	}

	infile.close();
	return 0;
}
