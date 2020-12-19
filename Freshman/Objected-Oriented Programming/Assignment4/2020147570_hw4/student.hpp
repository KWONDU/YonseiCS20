#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student
{
	public:
		//constructor
		Student();
		Student(int ID, string Name);
		Student(const Student& other_s); //copy constructor
		
		//get functions
		const int getID() const;
		const string getName() const;
		
		//set functions
		void setID(const int new_ID);
		void setName(const string new_Name);
		
		//member assignment operator
		Student& operator =(const Student& other_s);
		bool operator ==(const Student& other_s) const;
		bool operator !=(const Student& other_s) const;
		
	private:
		int s_ID;
		string s_Name;
};

#endif //STUDENT_H

