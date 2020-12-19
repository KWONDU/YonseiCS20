#include "student.hpp"

Student::Student()
{
	s_ID = 0;
	s_Name = "";
}

Student::Student(int ID, string Name)
{
	s_ID = ID;
	s_Name = Name;
}

Student::Student(const Student& other_s)
{
	s_ID = other_s.getID();
	s_Name = other_s.getName();
}

const int Student::getID() const
{
	return s_ID;
}

const string Student::getName() const
{
	return s_Name;
}

void Student::setID(const int new_ID)
{
	s_ID = new_ID;
}

void Student::setName(const string new_Name)
{
	s_Name = new_Name;
}

Student& Student::operator =(const Student& other_s)
{
	if (this == &other_s)
		return *this;
	
	s_ID = other_s.s_ID;
	s_Name = other_s.s_Name;
	
	return *this;
}

bool Student::operator ==(const Student& other_s) const
{
	return ((s_ID == other_s.s_ID) && (s_Name == other_s.s_Name));
}

bool Student::operator !=(const Student& other_s) const
{
	return ((s_ID != other_s.s_ID) || (s_Name != other_s.s_Name));
}

