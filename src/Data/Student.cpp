#include <iostream>
#include <string>
#include <fstream>

#include "Student.h"

using namespace std;

Student::Student()
{

	this-> firstName = "";
	this-> middleName = "";
	this-> lastName = "";
	this-> studentID = "";
	this-> dob = "";
	this-> program = "";
	this-> email = "";
	this-> grades = Grade();

}
Student::Student(const Student& copy)
{
	this-> firstName = copy.firstName;
	this-> middleName = copy.middleName;
	this-> lastName = copy.lastName;
	this-> studentID = copy.studentID;
	this-> dob = copy.dob;
	this-> program = copy.program;
	this-> email = copy.email;
	this-> grades = Grade(copy.grades);
}

string Student::getDob() const
{
	return dob;
}

void Student::setDob(const string &dob)
{
	this->dob = dob;
}

string Student::getEmail() const
{
	return email;
}

void Student::setEmail(const string &email)
{
	this->email = email;
}

string Student::getFirstName() const
{
	return firstName;
}

void Student::setFirstName(const string &firstName)
{
	this->firstName = firstName;
}

string Student::getLastName() const
{
	return lastName;
}

void Student::setLastName(const string &lastName)
{
	this->lastName = lastName;
}

string Student::getMiddleName() const
{
	return middleName;
}

void Student::setMiddleName(const string &middleName)
{
	this->middleName = middleName;
}

string Student::getProgram() const
{
	return program;
}

void Student::setProgram(const string &program)
{
	this->program = program;
}

string Student::getStudentId() const {
	return studentID;
}

void Student::setStudentId(string& studentId) {
	this-> studentID = studentId;
}

void Student::serialize(ofstream& out)
{
	out << this->firstName << "|" << this->middleName << "|" << this->lastName << "|" <<
		this->studentID << "|" << this->dob << "|" << this->program << "|" << this->email << "|" <<
		this->grades.getTestOne() << " " << this->grades.getTestTwo() << " " << this->grades.getTestThree() << " " <<
		this->grades.getAssignOne() << " " <<  this->grades.getAssignTwo() << " " << this->grades.getFinalExam() << endl;
}

void Student::deserialize(ifstream& in)
{
	getline(in, this->firstName, '|');
	getline(in, this->middleName, '|');
	getline(in, this->lastName, '|');
	getline(in, this->studentID, '|');
	getline(in, this->dob, '|');
	getline(in, this->program, '|');
	getline(in, this->email, '|');

	float temp;

	in >> temp;
	this->grades.setTestOne(temp);

	in >> temp;
	this->grades.setTestTwo(temp);

	in >> temp;
	this->grades.setTestThree(temp);

	in >> temp;
	this->grades.setAssignOne(temp);

	in >> temp;
	this->grades.setAssignTwo(temp);

	in >> temp;
	this->grades.setFinalExam(temp);
}

string Student::toString()
{
	std::string temp = "First Name : " + this->firstName +
					   "\nMiddle Name : " + this->middleName +
					   "\nLast Name : " + this->lastName +
					   "\nStudent ID : " + this->studentID +
					   "\nD.O.B : " + this->dob +
					   "\nEmail : " + this->email +
					   "\nProgram : " + this->program;

	return temp;
}
