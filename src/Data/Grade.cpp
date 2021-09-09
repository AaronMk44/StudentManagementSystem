#include <string>
#include "Grade.h"

using namespace std;

Grade::Grade()
{
	this-> testOne = 0;
	this-> testTwo = 0;
	this-> testThree = 0;
	this-> assignOne = 0;
	this-> assignTwo = 0;
	this-> finalExam = 0;
}
Grade::Grade(const Grade& copy)
{
	this-> testOne = copy.testOne;
	this-> testTwo = copy.testTwo;
	this-> testThree = copy.testThree;
	this-> assignOne = copy.assignOne;
	this-> assignTwo = copy.assignTwo;
	this-> finalExam = copy.finalExam;
}

float Grade::getAssignOne() const {
	return assignOne;
}

void Grade::setAssignOne(float assignOne) {
	this->assignOne = assignOne;
}

float Grade::getAssignTwo() const {
	return assignTwo;
}

void Grade::setAssignTwo(float assignTwo) {
	this->assignTwo = assignTwo;
}

float Grade::getFinalExam() const {
	return finalExam;
}

void Grade::setFinalExam(float finalExam) {
	this->finalExam = finalExam;
}

float Grade::getTestOne() const {
	return testOne;
}

void Grade::setTestOne(float testOne) {
	this->testOne = testOne;
}

float Grade::getTestThree() const {
	return testThree;
}

void Grade::setTestThree(float testThree) {
	this->testThree = testThree;
}

float Grade::getTestTwo() const {
	return testTwo;
}

void Grade::setTestTwo(float testTwo) {
	this->testTwo = testTwo;
}

float Grade::evaluteCA()
{
	return (((this->testOne + this->testTwo + this->testThree + this->assignOne + this->assignTwo)/500) * 100)/2;
}

float Grade::evaluteFinalScore()
{
	return ( Grade::evaluteCA() + (this->finalExam / 2) );
}

string Grade::toString()
{
	std::string temp = "Test One : " + to_string(this->testOne) +
					   "\nTest Two : " + to_string(this->testTwo) +
					   "\nTest Three : " + to_string(this->testThree) +
					   "\nAssignment One : " + to_string(this->assignOne) +
					   "\nAssignment Two : " + to_string(this->assignTwo) +
					   "\nCA (Out of 50%): " + to_string(Grade::evaluteCA()) +
					   "\nFinal Exam Score : " + to_string(this->finalExam) +
					   "\nYear Score : " + to_string(Grade::evaluteFinalScore()) + "\n";

	return temp;
}
