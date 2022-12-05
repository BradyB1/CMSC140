/*
 * Class: CMSC140 CRN 30525
 * Instructor: Dr. Chwen-Huey Wu
 * Project 4
 * Description: Gather employee information and absences and calculate the total absences in the company along with the averages in the company
 * Due Date:4/21/2021
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Brady Buttrey

	* Pseudocode or Algorithm for the program:
	(be sure to indent items with control structure)
	(need to match flow chart submitted in documentation)
  1. Start
2. declare variables
3. start int function for numofemployees
4. display message to ask for number of employees
5. user enters number of employees
6. returns the number of employees
7. end int NumofEmployees functions
8. start int function totdaysabsent
9. ask user for the employee id
10. user input employee id
11. while true
12. display message to ask for number of days missed in the past year
13. user input daysabsent
14. if daysabsent is less than 0
15. display error message if number is less than 0
16. else if
17. breaks loop if input is valid
18. return totaldaysabsent
19. end totdaysabsent function
20. start average absence funciton
21. calculate the average absence
22. return the solution to the output
23. start int main
24. display header in output 
25. call numofemployees function 
26. begin ofstream input to .txt file
27. open the txt file
28. print header lines to the txt file
29. while numberofEmployees is greater than counter
30. keep interating through the loop and print to txt file
31. ask for programmer to input name
32. cin.ignore to avoid a bug
33. use getline to pull the full name
34. call function average absences
35. display message for total absences to the txt file
36. display message for average absences to the txt file 
37. display message for programmer name to the txt file 
38. close txt file

*/

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<cmath>
#include<math.h>
using namespace std;
//declaration 
int NumOfEmp, totdaysabs, emId, daysabsent, counter =0;
double avgDaysabs;
string programmerName;

//function to get the number of employees
int NumOfEmployees() {
	//asks the user how many people work in the company
	cout << "How many employees work in the company? ";
	//prompts user to enter the number of employees
	cin >> NumOfEmp;
	//returns the number of employees
	return NumOfEmp; 
}

//function to get employee ids and days absent
int TotDaysAbsent(int NumOfEmp) {
	
	
	//asks the user for the employee id
		cout << "What is your employee ID? (Should be four digits or less): ";
		//user inputs employee id
		cin >> emId;
		
		while (true) {
			//displays message to enter missed days
			cout << "Please enter the number of days missed in the past year: ";
			//user enters number of absent days 
			cin >> daysabsent;
			//if statement to only allow days greater than zero
			if (daysabsent <0 ) {
				//displays invalid response message
				cout << "The number of days must not be negative." << endl;
			/*	cout << "Please re-enter the number of days absent: "<< endl;*/
			}
			//breaks loop if it is a valid response
			else if (daysabsent >= 0) {
				break;
			}

		}
	
		
	return totdaysabs;
	
}

//function to get the calculation for average days absent 
double AverageAbsent(int NumOfEmp, int totdaysabs) {
	//calculation of average absences 
	avgDaysabs = (totdaysabs /NumOfEmp);
	//returns the average
	return avgDaysabs;

}

int main() {
	//displays header for the output
	cout << "Calculate the average number of days a company's employees are absent." << endl;
	cout << endl;
	//call function to ask and get employee count
	NumOfEmployees();
	//stream to write to a file
	ofstream inputfile;
	//opens the text file to record inputed data
	inputfile.open("employeeAbsences.txt");
	//message to display in file
	inputfile << "EMPLOYEE ABSENCE REPORT" << endl;
	//message to display to file
	inputfile << "EmployeeID: \tDays Absent:" << endl;
	//loop to keep asking questions to the number of employees
	while (NumOfEmp > counter) {
		//calls funciton to display
		TotDaysAbsent(NumOfEmp);
		//sends values to the .txt file
		inputfile << emId << "\t\t" << daysabsent << endl;
		totdaysabs += daysabsent;
		//keeps the loop iterating 
		counter += 1;
	}
	//displays programmer and continues to ask for the programmers name
	cout << "Programmer: " << endl;
	//used an ignore to stop a getline bug
	cin.ignore();
	//getline to pull full name
	getline(cin, programmerName);
	
	//calls function for average absences 
	AverageAbsent(NumOfEmp, totdaysabs);
	//displays message to file to hold the average
	inputfile << "\nThe " << NumOfEmp << " employees were absent a total of " << totdaysabs << " days." << endl;
	//displays message to the file
	inputfile << "The average number of days absent is " << fixed << showpoint << setprecision(1) << avgDaysabs << " days. \n" << endl;
	//user inputs name to display in the file
	inputfile << "Programmer: " << programmerName << endl;
	//closes the .txt file 
	inputfile.close();



	return 0;
}