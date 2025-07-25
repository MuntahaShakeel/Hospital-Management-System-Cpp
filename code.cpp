#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>  
using namespace std;
const int MAX_DOCTORS = 50;
const int MAX_PATIENTS = 50;

struct Doctor
{
	string name, department, speciality;
	int fees = 0, rating = 0, id = 0, counter = 0, rate = 0;
	int sum;

};

struct Patient
{
	string name, concern, medical;
	int id = 0, visit = 0;
	char appointment = '\0';
};

Doctor doc[MAX_DOCTORS];
int doctorCount = 0;
Patient pat[MAX_PATIENTS];
int patientCount = 0;

void admin();
void receptionist();
void doctorFunc();
void patientFunc();
void doctor_info(int choice);
void patient_info(int choice);
void doctor_(int choice);
void patient_(int choice);
void readData();
//void writeData();

void readData()

{
	ifstream doctorFile("doctors.txt");
	ifstream patientFile("patients.txt");


	doctorFile >> doctorCount;
	for (int i = 0; i < doctorCount; i++)
	{
		doctorFile >> doc[i].id >> doc[i].name >> doc[i].department >> doc[i].speciality >> doc[i].fees >> doc[i].rating >> doc[i].counter >> doc[i].sum;
	}
	doctorFile.close();

	patientFile >> patientCount;
	for (int i = 0; i < patientCount; i++)
	{
		patientFile >> pat[i].id >> pat[i].name >> pat[i].concern >> pat[i].medical >> pat[i].visit >> pat[i].appointment;
	}
	patientFile.close();

}

void writeDoc()
{
	ofstream doctorFile("doctors.txt",ios::app);

	doctorFile << doctorCount << endl;
	for (int i = 0; i < doctorCount; i++)
	{
		// Writing doctor information to the file
		doctorFile << doc[i].id << " " << doc[i].name << " " << doc[i].department << " "
			<< doc[i].speciality << " " << doc[i].fees << " "
			<< doc[i].rating << " " << doc[i].counter << " " << doc[i].sum << endl;
	}
	doctorFile.close();
}

void writepatient() {
	ofstream patientFile("patients.txt",ios::app);
	patientFile << patientCount << endl;
	for (int i = 0; i < patientCount; i++)
	{
		// Writing patient information to the file
		patientFile << pat[i].id << " " << pat[i].name << " " << pat[i].concern << " "
			<< pat[i].medical << " " << pat[i].visit << " " << pat[i].appointment << endl;
	}
	patientFile.close();
}


void admin()
{
	cout << "\n\n\n\n\n\t\t\t Loading... !\n";
	char x = '*';
	for (int i = 0; i <= 27; i++)
	{
		Sleep(100);
		cout << x;
	}
	system("cls");
	cout << "\n\n\t\t\tWelcome ADMIN!!" << endl;
	int choice;
	do
	{
		cout << "ADMIN" << endl;
		cout << "1.Add doctor\n";
		cout << "2.Remove doctor\n";
		cout << "3.Display finance generated by each doctor\n";
		cout << "4.Display all doctors with rating\n";
		cout << "5.Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice != 5)
		{
			doctor_info(choice);
		}
	} while (choice != 5);
}

void receptionist()
{
	cout << "\n\n\n\n\n\t\t\t Loading... !\n";
	char x = '*';
	for (int i = 0; i <= 27; i++)
	{
		Sleep(100);
		cout << x;
	}
	system("cls");
	cout << "\n\n\t\t\tWelcome RECEPTIONIST!!" << endl;
	int choice;
	do
	{
		cout << "RECEPTIONIST" << endl;
		cout << "1.Add patient\n";
		cout << "2.Enter your health concern\n";
		cout << "3.Display list of all doctors\n";
		cout << "4.Display patient history\n";
		cout << "5.Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice != 5)
		{
			patient_info(choice);
		}
	} while (choice != 5);
}

void doctorFunc()
{
	cout << "\n\n\n\n\n\t\t\t Loading.. !\n";
	char x = '*';
	for (int i = 0; i <= 27; i++)
	{
		Sleep(100);
		cout << x;
	}
	system("cls");
	cout << "\n\n\t\t\tWelcome DOCTOR!!" << endl;
	int choice;
	do
	{
		cout << "DOCTOR" << endl;
		cout << "1.View patient history\n";
		cout << "2.Update patient history\n";
		cout << "3.Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice != 3)
		{
			doctor_(choice);
		}
	} while (choice != 3);
}

void patientFunc()
{
	cout << "\n\n\n\n\n\t\t\t Loading.. !\n";
	char x = '*';
	for (int i = 0; i <= 27; i++)
	{
		Sleep(100);
		cout << x;
	}
	system("cls");
	cout << "\n\n\t\t\tWelcome PATIENT!!" << endl;
	int choice;
	do {
		cout << "PATIENT" << endl;
		cout << "1.View medical history\n";
		cout << "2.Enter health concern\n";
		cout << "3.Display list of all doctors\n";
		cout << "4.Book your Appointment\n";
		cout << "5.Add rating of visited doctor\n";
		cout << "6.Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice != 6)
		{
			patient_(choice);
		}
	} while (choice != 6);
}

void doctor_info(int choice)
{
	if (choice == 1)
	{
		cout << endl;
		for (int i = doctorCount; i < 50; i++)
		{
			cout << endl;
			cin.ignore();
			cout << "Enter doctor id: ";
			cin >> doc[i].id;
			cin.ignore();
	
			cout << "Enter doctor name: ";
			getline(cin, doc[i].name);
			cout << "Enter doctor department: ";
			getline(cin, doc[i].department);
			cout << "Enter doctor speciality: ";
			getline(cin, doc[i].speciality);
			cout << "Enter doctor fees: ";
			cin >> doc[i].fees;
			doc[i].rating = 0;
			doctorCount++;
			writeDoc();

			cout << "Do you want to add another doctor? (1 for yes, 0 for no): ";
			int addAnother;
			cin >> addAnother;
			if (addAnother != 1)
			{
				break;
			}

			cout << endl;
		}

		if (doctorCount == 50)
		{
			cout << "Maximum number of doctors added. Cannot add more.\n";
		}
		else
		{
			cout << "Added successfully\n";
		}
		cout << endl;
	}


	else if (choice == 3)
	{
		cout << endl;
		if (doctorCount == 0)
		{
			cout << "No doctors available." << endl;
		}
		else
		{
			for (int i = 0; i < doctorCount; i++)
			{
				cout << "Doctor ID: " << doc[i].id << endl;
				cout << "Doctor Name: " << doc[i].name << endl;
				cout << "Doctor Department: " << doc[i].department << endl;
				cout << "Doctor finance: " << doc[i].sum << endl;
				cout << endl;
				cout << endl;
			}
		}
		cout << endl;
	}

	else if (choice == 4)
	{
		cout << endl;
		if (doctorCount == 0)
		{
			cout << "No doctors available." << endl;
		}
		else
		{
			for (int i = 0; i < doctorCount; i++)
			{
				cout << "Doctor ID: " << doc[i].id << endl;
				cout << "Doctor Name: " << doc[i].name << endl;
				cout << "Doctor Department: " << doc[i].department << endl;
				cout << "Doctor Speciality: " << doc[i].speciality << endl;
				cout << "Doctor Fees: " << doc[i].fees << endl;
				cout << "Doctor Rating: " << doc[i].rating << endl;
				cout << "Doctor finance: " << doc[i].sum << endl;
				cout << "NO OF PATIENT VISITED: " << doc[i].counter << endl;
				cout << endl;
			}
		}
		cout << endl;
	}

	else if (choice == 2)
	{
		int a;
		cout << "Enter id to delete: ";
		cin >> a;
		bool doctorFound = false;

		for (int i = 0; i < doctorCount; i++)
		{
			if (a == doc[i].id)
			{
				for (int j = i; j < doctorCount - 1; j++)
				{
					doc[j] = doc[j + 1];
				}
				doctorCount--;
				doctorFound = true;
				break;
			}
		}

		if (doctorFound)
		{
			cout << "Deleted successfully\n";
		}
		else
		{
			cout << "Doctor with ID " << a << " not found\n";
		}
		cout << endl;
	}
	else
	{
		cout << "invalid choice\n";
		cout << endl;
	}
}

void patient_info(int choice)
{
	if (choice == 1)
	{
		cout << endl;
		for (int i = patientCount; i < MAX_PATIENTS; i++)
		{
			cout << "Enter patient id: ";
			cin >> pat[i].id;
			cin.ignore();
			cout << "Enter patient name: ";
			getline(cin, pat[i].name);
			writepatient();
			cout << "Do you want to add another patient? (1 for yes, 0 for no): ";
			int addAnother;
			cin >> addAnother;

			if (addAnother != 1)
			{
				break;
			}

			patientCount++;
		}

		if (patientCount == MAX_PATIENTS)

		{
			cout << "Maximum number of patients added. Cannot add more.\n";
		}
		else
		{
			cout << "Added successfully\n";
		}
		cout << endl;
	}


	else if (choice == 2)
	{
		cout << endl;
		int patientId;
		cout << "Enter patient id: ";
		cin >> patientId;


		bool
			patientFound = false;
		for (int i = 0; i < 5; i++)
		{
			if (patientId == pat[i].id)

			{
				cout << "Enter patient concern: ";
				cin >> pat[i].concern;
				pat[i].visit++;

				bool doctorFound = false;
				for (int j = 0; j < 50; j++)
				{
					if (pat[i].concern == doc[j].speciality || pat[i].concern == doc[j].department)
					{
						cout << endl;
						cout << "DOCTOR FOR YOUR CONCERN*\n";
						cout << "Doctor ID: " << doc[j].id << endl;
						cout << "Doctor Name: " << doc[j].name << endl;
						cout << "Doctor Department: " << doc[j].department << endl;
						cout << "Doctor Speciality: " << doc[j].speciality << endl;
						cout << "Doctor Fees: " << doc[j].fees << endl;
						doctorFound = true;
						cout << "Do you want to book an appointment with " << doc[j].name << "? (y/n): ";
						cin >> pat[i].appointment;
						if (pat[i].appointment == 'Y' || pat[i].appointment == 'y')
						{
							doc[j].sum += doc[j].fees;
							cout << "Booked\n";
						}
						else
						{
							break;
						}
						break;
					}
				}

				if (!doctorFound)
				{
					cout << "No matching doctor found" << endl;
				}

				patientFound = true;
				break;
			}

		}

		if (!patientFound)
		{
			cout << "Patient with ID " << patientId << " not found" << endl;
		}
		cout << endl;
	}


	else if (choice == 3)
	{
		cout << endl;
		for (int i = 0; i < doctorCount; i++)
		{
			cout << "Doctor ID: " << doc[i].id << endl;
			cout << "Doctor Name: " << doc[i].name << endl;
			cout << "Doctor Department: " << doc[i].department << endl;
			cout << "Doctor Speciality: " << doc[i].speciality << endl;
			cout << "Doctor Fees: " << doc[i].fees << endl;

			cout << endl;
		}
		cout << endl;
	}
	else if (choice == 4)
	{
		cout << endl;
		int patientId;
		cout << "Enter patient id: ";
		cin >> patientId;

		bool patientFound = false;
		for (int i = 0; i < 50; i++)
		{
			if (patientId == pat[i].id)
			{
				cout << "PATIENT ID: " << pat[i].id << endl;
				cout << "PATIENT NAME: " << pat[i].name << endl;
				cout << "NO OF VISITS: " << pat[i].visit << endl;
				cout << "MEDICAL HISTORY: " << pat[i].medical << endl;
				patientFound = true;
				break;
			}

		}


		if (!patientFound)
		{
			cout << "Patient not found\n";
		}
		cout << endl;
	}


	else
	{
		cout << endl;
		cout << "inavlid choice\n";
		cout << endl;
	}
}

void doctor_(int choice)
{
	int a;

	cout << "Enter patient's id: ";
	cin >> a;

	if (choice == 1)
	{
		bool patientFound = false;

		for (int i = 0; i < 50; i++)
		{
			if (a == pat[i].id)
			{
				string c = pat[i].concern;
				if (pat[i].appointment == 'y' || pat[i].appointment == 'Y')
				{
					string c = pat[i].concern;

					cout << "Patient name: " << pat[i].name << endl;
					cout << "Patient's concern: " << pat[i].concern << endl;
					cout << "Medical history: " << pat[i].medical << endl;
					patientFound = true;
					break;

				}

			}
		}

		if (!patientFound)
		{
			cout << " Appointment not booked\n";
		}
		cout << endl;
	}


	else if (choice == 2)
	{
		cout << endl;
		cout << "Enter patient's id: ";
		cin >> a;

		bool appointmentFound = false;

		for (int i = 0; i < 50; i++)
		{
			if (pat[i].id == a && (pat[i].appointment == 'y' || pat[i].appointment == 'Y'))
			{
				cout << "Enter prescription or test if needed: ";
				cin.ignore();
				getline(cin, pat[i].medical);
				appointmentFound = true;
				break;
			}
		}

		if (!appointmentFound)
		{
			cout << "Appointment not booked or patient not found\n";
		}
		cout << endl;
	}


	else
	{
		cout << endl;
		cout << "invalid choice\n";
		cout << endl;
	}
}

void patient_(int choice)
{
	int a;
	if (choice == 1)
	{
		cout << endl;
		for (int i = 0; i < 50; i++)
		{
			cout << "Enter your id: ";
			cin >> a;
			if (pat[i].id == a)
			{
				cout << "ID: " << pat[i].id << endl;
				cout << "NAME: " << pat[i].name << endl;
				cout << "MEDICAL HISTORY: " << pat[i].medical << endl;
				cout << "NO OF VISITS: " << pat[i].visit << endl;
			}
			else
			{
				cout << "patient not found\n";
			}
			break;
		}
		cout << endl;
	}
	else if (choice == 2)
	{
		cout << endl;
		string c;
		bool found = false;
		cin.ignore();
		cout << "Enter your concern: ";
		getline(cin, c);
		for (int i = 0; i < 50; i++)
		{

			if (c == doc[i].speciality || c == doc[i].department)
			{
				found = true;
				cout << "Doctor ID: " << doc[i].id << endl;
				cout << "Doctor Name: " << doc[i].name << endl;
				cout << "Doctor Department: " << doc[i].department << endl;
				cout << "Doctor Speciality: " << doc[i].speciality << endl;
				cout << "Doctor Fees: " << doc[i].fees << endl;

				cout << "Want to book an appointment? (y/n): ";
				cin >> pat[i].appointment;

				if (pat[i].appointment == 'y' || pat[i].appointment == 'Y')
				{
					cout << "Book your appointment by visiting the receptionist. Thank you." << endl;
				}
				else
				{
					cout << "Thank you." << endl;
				}
				break;
			}
		}

		if (!found)
		{
			cout << "No doc to display for your concern" << endl;
		}
		cout << endl;
	}

	else if (choice == 3)
	{
		cout << endl;
		if (doctorCount != 0)
		{
			for (int i = 0; i < doctorCount; i++)
			{
				cout << "Doctor ID: " << doc[i].id << endl;
				cout << "Doctor Name: " << doc[i].name << endl;
				cout << "Doctor Department: " << doc[i].department << endl;
				cout << "Doctor Speciality: " << doc[i].speciality << endl;
				cout << "Doctor Fees: " << doc[i].fees << endl;
				cout << "Doctor Rating: " << doc[i].rate << endl;
				cout << endl;
			}
		}
		else
		{
			cout << endl;
			cout << "No doc to display\n";
		}
		cout << endl;
	}
	else if (choice == 4)
	{
		cout << endl;
		cout << "If you want to book any appointment, kindly visit the receptionist. THANK YOU." << endl;
		cout << endl;
	}
	else if (choice == 5)
	{
		cout << endl;
		string doctorNameOrSpeciality;
		cout << "Enter the name or speciality of the doctor you want to rate: ";
		cin >> doctorNameOrSpeciality;

		bool visitedDoctor = false;
		for (int i = 0; i < 50; i++)
		{
			if (pat[i].visit > 0 && (doctorNameOrSpeciality == doc[i].speciality || doctorNameOrSpeciality == doc[i].name)&& (pat[i].appointment=='y'||pat[i].appointment=='Y'))
			{
				visitedDoctor = true;
				cout << "Add rating out of 5: ";
				cin >> doc[i].rating;
				cout << "Review added successfully for " << doc[i].name << "\n";
				break;
			}
		}

		if (!visitedDoctor)
		{
			cout << endl;
			cout << "You haven't visited the specified doctor. Cannot add a review.\n";
		}
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "invalid choice\n";
		cout << endl;
	}
}

int main() {
	readData();
	int choice;
	do {
		cout << "\n\n\n\n\n\t\t\t Loading... !\n";
		char x = '*';
		for (int i = 0; i <= 27; i++)
		{
			Sleep(100);
			cout << x;
		}
		system("cls");
		cout << "\n\n\t\t\tWelcome to HOSPITAL!!" << endl;
		cout << "HOSPITAL MANAGEMENT SYSTEM" << endl;
		cout << "1.Admin" << endl;
		cout << "2.Receptionist" << endl;
		cout << "3.Doctor" << endl;
		cout << "4.Patient" << endl;
		cout << "5.Exit" << endl;
		cout << "Enter your choice according to the list: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			admin();
			break;
		case 2:
			receptionist();
			break;
		case 3:
			doctorFunc();
			break;
		case 4:
			patientFunc();
			break;
		}
	} while (choice != 5);



	return 0;
}

