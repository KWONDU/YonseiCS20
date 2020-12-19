#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
using namespace std;

/**********************/
/*******Problem 1******/
/**********************/
/* ID: 2020147570     */
/* NAME: KWONDONGUK   */
/**********************/

int main(){
    int loopNum;
    char dump[51]; // to ignore '\n' in first line

    ifstream infile("input1.txt");

    infile >> loopNum;
    infile.getline(dump, 51);

    for (int i = 0; i < loopNum; i++){
        char inputString[51];
        infile.getline(inputString, 51);
        
        int num_occur[5] = {0, 0, 0, 0, 0};
	for(int j = 0; j < 51; j++){
		switch(inputString[j]) {
		//count number of a
			case 'a':
				num_occur[0]++;
				break;
		//count number of e
			case 'e':
				num_occur[1]++;
				break;
		//count number of i
			case 'i':
				num_occur[2]++;
				break;
		//count number of o
			case 'o':
				num_occur[3]++;
				break;
		//count number of u
			case 'u':
				num_occur[4]++;
				break;
			default:
				break;
		}
	}
	
	//print
	cout << num_occur[0] << " " << num_occur[1] << " "
	     << num_occur[2] << " " << num_occur[3] << " "
	     << num_occur[4] << endl;
    }
    infile.close();

    return 0;
}
