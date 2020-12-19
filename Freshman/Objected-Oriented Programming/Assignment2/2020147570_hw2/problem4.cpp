#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

/**********************/
/*******Problem 4******/
/**********************/
/* ID: 2020147570     */
/* NAME: KWONDONGUK   */
/**********************/


void print_seat_state(int first, int business, int economy){

        cout << "current vacant seats" << endl;
	cout << "first class: " << (5-first) << "/" << "5" << endl;
	cout << "business class: " << (25-business) << "/" << "25" << endl;
	cout << "economy class: " << (50-economy) << "/" << "50" << endl;
	
	//output first class's seats
	cout << "first class" << endl;
	int num1_1 = first;
	int num1_2 = 5 - first;
	while (num1_1 > 0) {
		cout << "X";
		num1_1--;
	}
	while (num1_2 > 0) {
		cout << "O";
		num1_2--;
	}
	cout << "\n";
	
	//output business class's seats
	cout << "business class" << endl;
	int num2_1 = business%5;
	int num2_2 = (25 - business)%5;
	
	//divide into sets of five
	for(int i = 0; i < int(business/5); i++) {
		cout << "XXXXX" << endl;
	}
	//remainder
	if (num2_1 != 0 && num2_2 != 0) {
		while (num2_1 > 0) {
			cout << "X";
			num2_1--;
		}
		while (num2_2 > 0) {
			cout << "O";
			num2_2--;
		}
		cout << "\n";
	}
	//divide into sets of five
	for(int i = 0; i < int((25-business)/5); i++) {
		cout << "OOOOO" << endl;
	}

	cout << "economy class" << endl;
	int num3_1 = economy%5;
	int num3_2 = (50 - economy)%5;
	
	//divide into sets of five
	for(int i = 0; i < int(economy/5); i ++) {
		cout << "XXXXX" << endl;
	}
	//remainder
	if (num3_1 != 0 && num3_2 != 0) {
		while (num3_1 > 0) {
			cout << "X";
			num3_1--;
		}
		while (num3_2 > 0) {
			cout << "O";
			num3_2--;
		}
		cout << "\n";
	}
	//divide into sets of five
	for(int i = 0; i < int((50-economy)/5); i++) {
		cout << "OOOOO" << endl;
	}
}

void add_passenger(int& first, int& business, int& economy, istream& infile){
	
	char seat;
	infile >> seat;
	int num;
	infile >> num;
	switch(seat) {
		//first class
		case '1':
			if (num+first > 5) {cout << "full seat" << endl;}
			else {
				first += num;
				cout << "add complete" << endl;
			}
			break;
		//business class
		case '2':
			if (num+business > 25) {cout << "full seat" << endl;}
			else {
				business += num;
				cout << "add complete" << endl;
			}
			break;
		//economy class
		case '3':
			if (num+economy > 50) {cout << "full seat" << endl;}
			else {
				economy += num;
				cout << "add complete" << endl;
			}
			break;
		default:
			cout<< "Wrong Input!" << "\n";
	}
}

void delete_passenger(int& first, int& business, int& economy, istream& infile){
	
	char seat;
        infile >> seat;
        int num;
        infile >> num;
	switch(seat) {
		//first class
		case '1':
			if (num>first) {cout << "wrong input" << endl;}
			else {
				first -= num;
				cout << "delete complete" << endl;
			}
			break;
		//business class
		case '2':
			if (num>business) {cout << "wrong input" << endl;}
			else {
				business -= num;
				cout << "delete complete" << endl;
			}
			break;
		//economy class
		case '3':
			if (num>economy) {cout << "wrong input" << endl;}
			else {
				economy -= num;
				cout << "delete complete" << endl;
			}
			break;
		default:
			cout<< "Wrong Input!" << "\n";
	}
}

int main(){
	int first_class = 0; //MAX: 5
	int business_class = 0; // MAX: 25
	int economy_class = 0; // MAX: 50

	int loopNum;

	ifstream infile("input4.txt");

	infile >> loopNum;
	
	for (int i = 0; i < loopNum; i++) {
		char menu;
		infile >> menu;
		switch(menu){
			case '1':
				add_passenger(first_class, business_class, economy_class, infile);
				break;
			case '2':
				delete_passenger(first_class, business_class, economy_class, infile);
				break;
			default:
				cout<< "Wrong Input!" << "\n";
		}
	}
	
	print_seat_state(first_class, business_class, economy_class);
	cout << "end the program" << "\n";

	infile.close();

	return 0;
}
