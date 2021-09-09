#include <fstream>
#include "LinkedList.h"
#include "Controller.h"
#include <Views.h>

/*
 * The following declarations are global because of memory optimization
 */

Views* views = new Views();
LinkedList* list = new LinkedList();
char resp;
string tempVar;
Student* tempStudent = nullptr;

void run()
{
	resp = views->getMainMenu();

	switch(resp)
	{

	case '1':	// [ Search Student Menu.]

		if(list->isEmpty())
		{
			views->showMsg("Attention : No Students Available.");
			run();
		}else
		{
			tempStudent = list->search(views->showSearchMenu());

			if(tempStudent == nullptr)
			{
				views->showMsg("Attention : No Results were found matching your query.");
				run();
			}else
			{
				views->showMsg("Details for : " + tempStudent->getFirstName() + " " + tempStudent->getLastName());
				views->showStudent(tempStudent);
				run();
			}
		}
		break;

	case '2':	// [ Add Student. ]

		tempStudent = nullptr;
		views->showAddSudentMenu(tempStudent);

		if(tempStudent == nullptr)
		{
			run();
		}else
		{
			list->insert(tempStudent);
			views->showMsg("Attention : Student Successfully Added.");
			run();
		}
		break;

	case '3':	// [ Edit Student Details.]

		if(list->isEmpty())
		{
			views->showMsg("Attention : No Students Available.");
			run();
		}else
		{
			tempStudent = nullptr;
			tempStudent = list->search(views->showSearchMenu());

			if(tempStudent == nullptr)
			{
				views->showMsg("Attention : No Results were found matching your query.");
				run();
			}else
			{
				views->showEditStudentDetails(tempStudent);
				list->updateDB();
				views->showMsg("Attention : Student Successfully Updated.");
				run();
			}
		}
		break;

	case '4':	// [ View Student Grades. ]
		if(list->isEmpty())
		{
			views->showMsg("Attention : No Students Available.");
			run();
		}else
		{
			tempStudent = nullptr;
			tempStudent = list->search(views->showViewStudentGradeMenu());

			if(tempStudent == nullptr)
			{
				views->showMsg("Attention : No Results were found matching your query.");
				run();
			}else
			{
				views->showMsg("Grades for : " + tempStudent->getFirstName() + " " + tempStudent->getLastName());
				views->showGrades(tempStudent);
				run();
			}
		}
		break;

	case '5':	// [ Modify Student Grades ]
		if(list->isEmpty())
		{
			views->showMsg("Attention : No Students Available.");
			run();
		}else
		{
			tempStudent = nullptr;
			tempStudent = list->search(views->showSearchMenu());

			if(tempStudent == nullptr)
			{
				views->showMsg("Attention : No Results were found matching your query.");
				run();
			}else
			{
				views->showEditStudentGrades(tempStudent);
				list->updateDB();
				views->showMsg("Attention : Student Grades Successfully Updated.");
				run();
			}
		}
		break;

	case '6':
		tempVar = views->showRemoveStudentMenu();
		tempStudent = list->search(tempVar);

		if(tempStudent == nullptr)
		{
			views->showMsg("Attention : No Results were found matching your query.");
		}else
		{
			list->deleteNode(tempVar);
			views->showMsg("Attention : Student Successfully Deleted.");
			run();
		}
		break;

	/*
	 * The lines below feature the 'view' because, the actual view should not manipulate data
	 */
	case '7':
		if(list->isEmpty())
		{
			views->showMsg("Attention : No Students Available.");
			run();
		}else if(views->showViewAllStudentsMenu() == 'Y')
		{
			Node* nodePtr = list->getAllNodeData();

			cout << "=====================================================" << endl;
			cout << "		Students at Zambia ICT College				  " << endl;
			cout << "=====================================================" << endl;

			while(nodePtr != nullptr)
			{

				cout << nodePtr->data->toString() << endl;
				cout << "=====================================================" << endl;
				nodePtr = nodePtr->nextNodePtr;
			}
			cout << "=====================================================" << endl;
			cout << "						End of List	  				  " << endl;
			cout << "=====================================================" << endl;
			run();
		}
		break;
	case '8':
		if(views->showBackupRecoveryOptMenu() == '1')
		{
			views->showMsg("Backup Menu \n Backup can be located in DIR: database/backups.");
			cout << "Enter Backup Name: ";
			getline(cin, tempVar);

			//check if file exits
			ifstream in(("database/backups/"+tempVar).c_str());
			while(!in.fail())
			{
				cout << "----------------------------------------------------" << endl;
				cout << " ERROR: File by that name exits. " << endl;
				cout << "----------------------------------------------------" << endl;
				in.close();

				cout << "Enter Backup Name: ";
				getline(cin, tempVar);
				in.open(("database/backups/"+tempVar).c_str());
			}
			in.close();

			list->makeBackup(tempVar);
			views->showMsg("Backup Successfully Created");
			cout << endl;
			run();
		}else
		{
			views->showMsg("\t\tBackup Menu \n Backup can be located in DIR: database/backups.");
			cout << "Enter Backup Name to be Restored: ";
			getline(cin, tempVar);

			//check if file exits
			ifstream in(("database/backups/"+tempVar).c_str());
			while(in.fail())
			{
				cout << "----------------------------------------------------" << endl;
				cout << " ERROR: File by that name does not exits. " << endl;
				cout << "----------------------------------------------------" << endl;
				in.close();

				cout << "Enter Backup Name to be Restored: ";
				getline(cin, tempVar);
				in.open(("database/backups/"+tempVar).c_str());
			}
			in.close();

			list->restoreBackup(tempVar);
			views->showMsg("Backup Successfully Restored.");
			cout << endl;
			run();
		}
		break;
	}


	/*
	 * Before returning control to main(), delete the views and tempStudent Objects from memory
	 */
}

void launch()
{
	run();

	list->clearList();
	delete list;
	delete views;
}
