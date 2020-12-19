#include <iostream>
#include "class.hpp"

Class::Class()
{
	c_ClassName = "";
	c_Instructor = "";
	c_StudentList = NULL;
	TotalNumOfStudents = 0;
	ListCapacity = 0;
}

Class::Class(string ClassName, string Instructor)
{
	c_ClassName = ClassName;
	c_Instructor = Instructor;
	c_StudentList = NULL;
	TotalNumOfStudents = 0;
	ListCapacity = 0;
}

Class::Class(const Class& other_c)
{
	c_ClassName = "";
	c_Instructor = "";
	c_StudentList = NULL;
	TotalNumOfStudents = 0;
	ListCapacity = 0;
	
	*this = other_c;
}

Class::~Class()
{
	if (c_StudentList != NULL)
		delete [] c_StudentList;
}

const string Class::getClassName() const
{
	return c_ClassName;
}

const string Class::getInstructor() const
{
	return c_Instructor;
}

const int Class::getStudentIndex(int StudentID)
{
	int StudentIndex = -1;
	int i = 0;
	while (i < TotalNumOfStudents)
	{
		if (c_StudentList[i].getID() == StudentID)
		{
			StudentIndex = i;
			break;
		}
		i++;
	}
	
	return StudentIndex;
}

const Student Class::getStudent(int StudentIndex) const
{
	return c_StudentList[StudentIndex];
}

const int Class::getTotalNumOfStudents() const
{
	return TotalNumOfStudents;
}

const int Class::getListCapacity() const
{
	return ListCapacity;
}

const Class& Class::operator =(const Class& other_c)
{
	if (this == &other_c)
		return *this;
	
	c_ClassName = other_c.getClassName();
	c_Instructor = other_c.getInstructor();
	
	TotalNumOfStudents = other_c.getTotalNumOfStudents();
	ListCapacity = other_c.getListCapacity();

	c_StudentList = NULL;
	c_StudentList = new Student[ListCapacity];
	for (int i = 0;  i < TotalNumOfStudents; i++)
		c_StudentList[i] = other_c.getStudent(i);
		
	return *this;
}

void Class::SetClassName(string new_ClassName, string new_Instructor)
{
	c_ClassName = new_ClassName;
	c_Instructor = new_Instructor;
}

void Class::Register(string new_StudentName, int new_StudentID)
{
	TotalNumOfStudents += 1;
	if (TotalNumOfStudents == 0)
		ListCapacity = 0;
	else if (TotalNumOfStudents == 1)
		ListCapacity = 1;
	else
		if (TotalNumOfStudents > ListCapacity)
			ListCapacity *= 2;
	
	Student* s_temp = new Student[TotalNumOfStudents];
	for (int i = 0; i < TotalNumOfStudents - 1; i++)
		s_temp[i] = c_StudentList[i];
	
	c_StudentList = NULL;
	c_StudentList = new Student[ListCapacity];
	for (int i = 0; i < TotalNumOfStudents; i++)
		c_StudentList[i] = s_temp[i];
	delete [] s_temp;
	
	c_StudentList[TotalNumOfStudents - 1].setID(new_StudentID);
	c_StudentList[TotalNumOfStudents - 1].setName(new_StudentName);
}

void Class::Withdraw(int existing_StudentID)
{
	int index = getStudentIndex(existing_StudentID);
	if (index == -1)
	{
		return;
	}
	
	TotalNumOfStudents -= 1;
	if (TotalNumOfStudents == 0)
		ListCapacity = 0;
	else if (TotalNumOfStudents == 1)
		ListCapacity = 1;
	else
		if (TotalNumOfStudents <= ListCapacity/2)
			ListCapacity /= 2;
	
	Student* s_temp = new Student[TotalNumOfStudents];
	int i = 0;
	while (i < TotalNumOfStudents + 1)
	{
		if (i < index)
			s_temp[i] = c_StudentList[i];
		else if (i > index)
			s_temp[i - 1] = c_StudentList[i];
		
		i++;
	}
	
	c_StudentList = NULL;
	c_StudentList = new Student[ListCapacity];
	for (int i = 0; i < TotalNumOfStudents; i++)
		c_StudentList[i] = s_temp[i];
	delete [] s_temp;
}

void Class::Display()
{
	using std::cout;
	using std::endl;
	
	cout << "Prof. :" << c_Instructor << "\t\tClass Name :" << c_ClassName << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Total number of students : " << TotalNumOfStudents << endl;
	cout << "List Capacity :" << ListCapacity << endl;
	cout << "\n";
	for (int i = 0; i < TotalNumOfStudents; i++)
		cout << c_StudentList[i].getName() << "\t\t" << c_StudentList[i].getID() << endl;
	cout << "\n\n\n";
}

