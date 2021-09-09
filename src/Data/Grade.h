#include <string>

#ifndef GRADE_H_
#define GRADE_H_

class Grade
{
public:
	//Constructors

	Grade();
	Grade(const Grade& copy);

	//Getters and Setters

	float getAssignOne() const;
	void setAssignOne(float assignOne);

	float getAssignTwo() const;
	void setAssignTwo(float assignTwo);

	float getFinalExam() const;
	void setFinalExam(float finalExam);

	float getTestOne() const;
	void setTestOne(float testOne);

	float getTestThree() const;
	void setTestThree(float testThree);

	float getTestTwo() const;
	void setTestTwo(float testTwo);

	std::string toString();

private:
	//Data Members

	float testOne;
	float testTwo;
	float testThree;
	float assignOne;
	float assignTwo;
	float finalExam;

	float evaluteCA();
	float evaluteFinalScore();
};

#endif
