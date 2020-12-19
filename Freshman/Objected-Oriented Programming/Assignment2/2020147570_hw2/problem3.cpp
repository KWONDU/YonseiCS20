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

	infile >> loopNum;
	for (int i = 0; i < loopNum; i++) {
		
		//input card number streams
		int k;
		infile >> k;
		int c1[k], c2[k];
		for (int j = 0; j < k; j++) {infile >> c1[j];}
		for (int j = 0; j < k; j++) {infile >> c2[j];}

		//init each player's remaining cards and scores
		int pos1 = 0, sum1 = 0, pos2 = 0, sum2 = 0;
		while(1) {
			//player1 win
			if (c1[pos1] > c2[pos2]) {
				c1[pos1] -= c2[pos2];
				sum1++;
				pos2++;
			}
			//player2 win
			else if (c1[pos1] < c2[pos2]) {
				c2[pos2] -= c1[pos1];
				sum2++;
				pos1++;
			}
			//draw
			else {
				pos1++;
				pos2++;
			}
			//if one player has no card more
			if (pos1 >= k || pos2 >= k) {break;}
		}
		//print
		cout << sum1 << " " << sum2 << endl;
	}

	infile.close();

	return 0;
}
