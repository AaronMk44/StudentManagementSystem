
#include <iostream>
#include <cctype>
#include <string>
#include <Views.h>

using namespace std;

Views::Views()
{
	this->response = '\0';
	this->tempInput = "";
	this->tempNumericInput = 0;
	this->gabageCollector = "";
	this->blankString = "";
	this->blankNumeric = 0;
}

void Views::validate(short min, short max)
{
	/*
	 *	Input Validation:
	 *		The lines below clears the buffer since the cin >> char will only
	 *		extract a character from the buffer.
	 *
	 *		However, if the this->gabageCollector has a value, that means the
	 *		input is invalid. Thus, the while loop will execute.
	 *
	 *		If a single character was entered, it will be validated in the
	 *		loop condition.
	 */

	while(!isdigit(this->response) && !(this->response >= (48+min) && this->response <= (48+max)))
	{
		cout << endl;
		cout << "----------------------------------------------------" << endl;
		cout << " ERROR: Invalid Input [Hint: Enter a single number] " << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "Choose an option : ";
		cin >> this->response;

		/*
		 *	Input Validation:
		 *		The lines below clears the buffer since the cin >> char will only
		 *		extract a character from the buffer.
		 *
		 *		However, if the this->gabageCollector has a value, that means the
		 *		input is invalid. Thus, the while loop will execute.
		 *
		 *		If a single character was entered, it will be validated in the
		 *		loop condition.
		 */

		getline(cin, this->gabageCollector);
		if(this->gabageCollector != "")
		{
			response = 100;
		}
	}
}


char Views::getMainMenu()
{
	cout << "----------------------------------------------------" << endl;
	cout << "|  Zambia ICT College - Student Management System  |" << endl;
	cout << "----------------------------------------------------" << endl << endl;

	cout << "\t\t Main Menu" << endl;
	cout << "|----------------------------------------------------" << endl;
	cout << "| 1. Search Student. " << endl;
	cout << "|----------------------------------------------------" << endl;
	cout << "| 2. Add Student." << endl;
	cout << "| 3. Edit Student Details." << endl;
	cout << "| 4. View Student Grades." << endl;
	cout << "| 5. Modify Student Grades." << endl;
	cout << "| 6. Remove Student." << endl;
	cout << "| 7. View all Students." << endl;
	cout << "|----------------------------------------------------" << endl;
	cout << "| 8. Backup and Recovery Options." << endl;
	cout << "|----------------------------------------------------" << endl;
	cout << "| 9. Exit Program." << endl;
	cout << "|----------------------------------------------------" << endl;
	cout << "| Choose an option : ";
	cin >> this->response;

	/*
	 * Clear Buffer and begin input validation
	 */
	getline(cin, this->gabageCollector);
	if(this->gabageCollector != "")
	{
		response = 100;
	}
	Views::validate(1, 9);

	return response;
}
void Views::showMsg(string msg)
{
	cout << "----------------------------------------------------" << endl;
	cout << " " << msg << endl;
	cout << "----------------------------------------------------" << endl << endl;
}

void Views::showStudent(Student* obj) const
{
	cout << obj->toString() << endl;
}

string Views::showSearchMenu()
{
	this->tempInput = "";

	//Prompts
	cout << "----------------------------------------------------" << endl;
	cout << "|  Student Management System - Student Search       |" << endl;
	cout << "----------------------------------------------------" << endl << endl;

	cout << "Enter Student ID : ";
	getline(cin, this->tempInput);

	return this->tempInput;
}

void Views::showAddSudentMenu(Student*& tempStudent)
{

	cout << "Are you sure you want to proceed to the Add Student menu, \nyou will be unable to terminate the process. (Y/N): ";
	cin >> this->response;

	/*
	 * VALIDATE
	 */
	getline(cin, this->gabageCollector);
	if(this->gabageCollector != "")
	{
		response = 100;
	}

	while(this->response != 'Y' || this->response != 'N')
	{
		if(this->response == 'Y')
			break;
		if(this->response == 'N')
					break;
		cout << endl;
		cout << "----------------------------------------------------" << endl;
		cout << " ERROR: Invalid Input [Hint: Enter Y=Yes or N=No  ] " << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "Choose an option : ";
		cin >> this->response;

		getline(cin, this->gabageCollector);
		if(this->gabageCollector != "")
		{
			response = 100;
		}
	}
	/*
	 * END VALIDATION
	 */

	if(this->response == 'Y')
	{
		//Create dynamically a Student Object
		tempStudent = new Student();
		this->tempInput = "";

		//Prompts
		cout << "----------------------------------------------------" << endl;
		cout << "|  Student Management System - Add Student         |" << endl;
		cout << "----------------------------------------------------" << endl << endl;

		cout << "Enter First Name : ";
		getline(cin, tempInput);
		tempStudent->setFirstName(this->tempInput);
		this->tempInput = "";

		cout << "Enter Middle Name : ";
		getline(cin, this->tempInput);
		tempStudent->setMiddleName(this->tempInput);

		cout << "Enter Last Name : ";
		getline(cin, this->tempInput);
		tempStudent->setLastName(this->tempInput);

		cout << "Enter Student ID : ";
		getline(cin, this->tempInput);
		tempStudent->setStudentId(this->tempInput);

		cout << "Enter Date Of Birth [DD/MM/YYYY] : ";
		getline(cin, this->tempInput);
		tempStudent->setDob(this->tempInput);

		cout << "Enter Program : ";
		getline(cin, this->tempInput);
		tempStudent->setProgram(this->tempInput);

		cout << "Enter Email : ";
		getline(cin, this->tempInput);
		tempStudent->setEmail(this->tempInput);

		this->tempInput = "";
	}

}

void Views::showEditStudentDetails(Student*& tempStudent)
{

	cout << "Are you sure you want to proceed to the Edit Student menu, \nyou will be unable to terminate the process. (Y/N): ";
	cin >> this->response;

	/*
	 * VALIDATE
	 */
	getline(cin, this->gabageCollector);
	if(this->gabageCollector != "")
	{
		response = 100;
	}

	while(this->response != 'Y' || this->response != 'N')
	{
		if(this->response == 'Y')
			break;
		if(this->response == 'N')
					break;
		cout << endl;
		cout << "----------------------------------------------------" << endl;
		cout << " ERROR: Invalid Input [Hint: Enter Y=Yes or N=No  ] " << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "Choose an option : ";
		cin >> this->response;

		getline(cin, this->gabageCollector);
		if(this->gabageCollector != "")
		{
			response = 100;
		}
	}
	/*
	 * END VALIDATION
	 */

	if(this->response == 'Y')
	{
		this->tempInput = "";

		//Prompts
		cout << "----------------------------------------------------" << endl;
		cout << "|  Student Management System - Edit Student        |" << endl;
		cout << "----------------------------------------------------" << endl << endl;

		cout << "Instructions: \n1. To retain the current value, Do not enter input."
								"\n2. Enter 'e' to erase the contents." << endl << endl;

		cout << "Enter First Name [Current Value = " << tempStudent->getFirstName() << "]: ";
		getline(cin, this->tempInput);

			if(this->tempInput == ""){}
			else if(this->tempInput == "e")
			{tempStudent->setFirstName(this->blankString);}
			else{tempStudent->setFirstName(this->tempInput);}

		cout << "Enter Middle Name [Current Value = " << tempStudent->getMiddleName() << "]: ";
		getline(cin, this->tempInput);

			if(this->tempInput == ""){}
			else if(this->tempInput == "e")
			{tempStudent->setMiddleName(this->blankString);}
			else{tempStudent->setMiddleName(this->tempInput);}

		cout << "Enter Last Name [Current Value = " << tempStudent->getLastName() << "]: ";
		getline(cin, this->tempInput);

			if(this->tempInput == ""){}
			else if(this->tempInput == "e")
			{tempStudent->setLastName(this->blankString);}
			else{tempStudent->setLastName(this->tempInput);}

		cout << "Enter Student ID [Current Value = " << tempStudent->getStudentId() << "]: ";
		getline(cin, this->tempInput);

			if(this->tempInput == ""){}
			else if(this->tempInput == "e")
			{tempStudent->setStudentId(this->blankString);}
			else{tempStudent->setStudentId(this->tempInput);}

		cout << "Enter Date Of Birth [DD/MM/YYYY] [Current Value = " << tempStudent->getDob() << "]: ";
		getline(cin, this->tempInput);

			if(this->tempInput == ""){}
			else if(this->tempInput == "e")
			{tempStudent->setDob(this->blankString);}
			else{tempStudent->setDob(this->tempInput);}

		cout << "Enter Program [Current Value = " << tempStudent->getProgram() << "]: ";
		getline(cin, this->tempInput);

			if(this->tempInput == ""){}
			else if(this->tempInput == "e")
			{tempStudent->setProgram(this->blankString);}
			else{tempStudent->setProgram(this->tempInput);}

		cout << "Enter Email [Current Value = " << tempStudent->getEmail() << "]: ";
		getline(cin, this->tempInput);

			if(this->tempInput == ""){}
			else if(this->tempInput == "e")
			{tempStudent->setEmail(this->blankString);}
			else{tempStudent->setEmail(this->tempInput);}

		this->tempInput.clear();
	}
}

string Views::showRemoveStudentMenu()
{
	this->tempInput = "";

	//Prompts
	cout << "----------------------------------------------------" << endl;
	cout << "|  Student Management System - Remove Student      |" << endl;
	cout << "----------------------------------------------------" << endl << endl;

	cout << "Enter Student ID : ";
	getline(cin, this->tempInput);

	return this->tempInput;
}

string Views::showViewStudentGradeMenu()
{
	this->tempInput = "";

	//Prompts
	cout << "----------------------------------------------------" << endl;
	cout << "|  Student Management System - View Student Grades |" << endl;
	cout << "----------------------------------------------------" << endl << endl;

	cout << "Enter Student ID : ";
	getline(cin, this->tempInput);

	return this->tempInput;
}

void Views::showGrades(Student* obj) const
{
	cout << obj->grades.toString();
}

void Views::showEditStudentGrades(Student*& tempStudent)
{

	cout << "Are you sure you want to proceed to the Modify Student Grades menu, \nyou will be unable to terminate the process. (Yes = 1/No = 0): ";
	cin >> this->response;
	/*
	 * Clear Buffer and begin input validation
	 */
	getline(cin, this->gabageCollector);
	if(this->gabageCollector != "")
	{
		response = 100;
	}
	Views::validate(0, 1);

	if(this->response == '1')
	{
		this->tempInput = "";

		//Prompts
		cout << "----------------------------------------------------" << endl;
		cout << "| Student Management System - Modify Student Grades|" << endl;
		cout << "----------------------------------------------------" << endl << endl;

		cout << "Instructions: \n1. To retain the current value, Enter -1."
								"\n2. Enter '0' to erase the contents." << endl << endl;

		cout << "Enter Test One [Current Value = " << tempStudent->grades.getTestOne() << "]: ";
		cin >> tempNumericInput;

			if(this->tempNumericInput == -1){}
			else if(this->tempNumericInput == 0)
			{tempStudent->grades.setTestOne(this->blankNumeric);}
			else{tempStudent->grades.setTestOne(this->tempNumericInput);}

		cout << "Enter Test Two [Current Value = " << tempStudent->grades.getTestTwo() << "]: ";
		cin >> tempNumericInput;

			if(this->tempNumericInput == -1){}
			else if(this->tempNumericInput == 0)
			{tempStudent->grades.setTestTwo(this->blankNumeric);}
			else{tempStudent->grades.setTestTwo(this->tempNumericInput);}

		cout << "Enter Test Three [Current Value = " << tempStudent->grades.getTestThree() << "]: ";
		cin >> tempNumericInput;

			if(this->tempNumericInput == -1){}
			else if(this->tempNumericInput == 0)
			{tempStudent->grades.setTestThree(this->blankNumeric);}
			else{tempStudent->grades.setTestThree(this->tempNumericInput);}

		cout << "Enter Assignment One [Current Value = " << tempStudent->grades.getAssignOne() << "]: ";
		cin >> tempNumericInput;

			if(this->tempNumericInput == -1){}
			else if(this->tempNumericInput == 0)
			{tempStudent->grades.setAssignOne(this->blankNumeric);}
			else{tempStudent->grades.setAssignOne(this->tempNumericInput);}

		cout << "Enter Assignment Two [Current Value = " << tempStudent->grades.getAssignTwo() << "]: ";
		cin >> tempNumericInput;

			if(this->tempNumericInput == -1){}
			else if(this->tempNumericInput == 0)
			{tempStudent->grades.setAssignTwo(this->blankNumeric);}
			else{tempStudent->grades.setAssignTwo(this->tempNumericInput);}

		cout << "Enter Final Exam Score [Current Value = " << tempStudent->grades.getFinalExam() << "]: ";
		cin >> tempNumericInput;

			if(this->tempNumericInput == -1){}
			else if(this->tempNumericInput == 0)
			{tempStudent->grades.setFinalExam(this->blankNumeric);}
			else{tempStudent->grades.setFinalExam(this->tempNumericInput);}

		this->tempNumericInput = 0;
	}
}

char Views::showViewAllStudentsMenu()
{
	//Prompts
	cout << "----------------------------------------------------" << endl;
	cout << "|  Student Management System - View All Students	 |" << endl;
	cout << "----------------------------------------------------" << endl << endl;

	cout << "Are you sure you want to view ALL Students (Y/N): ";
	cin >> this->response;

	/*
	 * VALIDATE
	 */
	getline(cin, this->gabageCollector);
	if(this->gabageCollector != "")
	{
		response = 100;
	}

	while(this->response != 'Y' || this->response != 'N')
	{
		if(this->response == 'Y')
			break;
		if(this->response == 'N')
					break;
		cout << endl;
		cout << "----------------------------------------------------" << endl;
		cout << " ERROR: Invalid Input [Hint: Enter Y=Yes or N=No  ] " << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "Choose an option : ";
		cin >> this->response;

		getline(cin, this->gabageCollector);
		if(this->gabageCollector != "")
		{
			response = 100;
		}
	}
	/*
	 * END VALIDATE
	 */
	return this->response;
}

char Views::showBackupRecoveryOptMenu()
{
	//Prompts
	cout << "----------------------------------------------------" << endl;
	cout << "|  Student Management System - Backup and Restore	 |" << endl;
	cout << "----------------------------------------------------" << endl << endl;

	cout << "| 1. Make Backup." << endl;
	cout << "| 2. Restore Backup." << endl;
	cout << "|----------------------------------------------------" << endl;
	cout << "| Choose an option : ";
	cin >> this->response;

	/*
	 * VALIDATE
	 */
	getline(cin, this->gabageCollector);
	if(this->gabageCollector != "")
	{
		response = 100;
	}

	while(this->response != '1' || this->response != '2')
	{
		if(this->response == '1')
			break;
		if(this->response == '2')
					break;
		cout << endl;
		cout << "----------------------------------------------------" << endl;
		cout << " ERROR: Invalid Input [Hint: Enter 1 or 2  ] " << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "Choose an option : ";
		cin >> this->response;

		getline(cin, this->gabageCollector);
		if(this->gabageCollector != "")
		{
			response = 100;
		}
	}
	/*
	 * END VALIDATE
	 */
	return this->response;
}
