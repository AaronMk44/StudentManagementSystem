#include "Student.h"

#ifndef MENU_H_
#define MENU_H_

class Views {
public:
	Views();

	void validate(short min, short max);

	char getMainMenu();
	void showMsg(string msg);
	void showStudent(Student* obj) const;
	string showSearchMenu();
	void showAddSudentMenu(Student*& tempStudent);
	void showEditStudentDetails(Student*& tempStudent);
	string showRemoveStudentMenu();
	string showViewStudentGradeMenu();
	void showGrades(Student* obj) const;
	void showEditStudentGrades(Student*& tempStudent);
	char showViewAllStudentsMenu();
	char showBackupRecoveryOptMenu();

private:
	char response;
	string tempInput;
	float tempNumericInput;
	string gabageCollector;
	string blankString;
	float blankNumeric;
};

#endif
