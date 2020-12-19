#ifndef CLASS_H
#define CLASS_H

#include <string>
#include "student.hpp"

class Class
{
	public:
		//constructor
		Class();
		Class(string ClassName, string Instructor);
		Class(const Class& other_c); //copy constructor
		
		//destructor
		~Class();
		
		//get functions
		const string getClassName() const;
		const string getInstructor() const;
		const int getStudentIndex(int StudentID);
		const Student getStudent(int StudentIndex) const;
		const int getTotalNumOfStudents() const;
		const int getListCapacity() const;
		
		
		//member assignment operator
		const Class& operator =(const Class& other_c);
		
		//interface functions
		void SetClassName(string new_ClassName, string new_Instructor);
		void Register(string new_StudentName, int new_StudentID);
		void Withdraw(int existing_StudentID);
		void Display();
		
	private:
		string c_ClassName;
		string c_Instructor;
		Student* c_StudentList;
		
		int TotalNumOfStudents;
		int ListCapacity;
};

#endif //CLASS_H

