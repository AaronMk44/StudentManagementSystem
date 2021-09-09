#include <string>
#include "Grade.h"

using namespace std;

#ifndef STUDENT_H_
#define STUDENT_H_

class Student
{
public:
	//Constructors
	Student();
	Student(const Student& copy);

	//Setters and Getters

	string getFirstName() const;
	void setFirstName(const string &firstName);

	string getMiddleName() const;
	void setMiddleName(const string &middleName);

	string getLastName() const;
	void setLastName(const string &lastName);

	string getDob() const;
	void setDob(const string &dob);

	string getProgram() const;
	void setProgram(const string &program);

	string getEmail() const;
	void setEmail(const string &email);

	string getStudentId() const;
	void setStudentId(string& studentId);

	void serialize(ofstream& out);
	void deserialize(ifstream& in);

	std::string toString();

	//Data Member
	Grade grades;

private:
	string firstName;
	string middleName;
	string lastName;
	string studentID;
	string dob;
	string program;
	string email;
};

#endif
