/*
 * Class: CMSC140 CRN30525
 * Instructor:Dr. Chwen-Huey(Alyssa) Wu
 * Project5
 * Description: Create a Lo Shu Magic Square that has all unique numbers and check if it meets the requirements to be a Lo Shu Magic square
 * Due Date:5/5/21
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here:Brady Buttrey


 * Pseudocode or Algorithm for the program:
	(be sure to indent items with control structure)
	(need to match flow chart submitted in documentation)
  1.
  2.
  3.
  4.
  5.
 (more as needed)
*/



#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;



// Global constants 
const int ROWS = 3;  // The number of rows in the array
const int COLS = 3;  // The number of columns in the array
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number

// Function prototypes
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size);

int main()
{
	bool magicArray1;
	/* Define a Lo Shu Magic Square using 3 parallel arrays corresponding         to each row of the grid */
	int magicArray[3][3];
	// Your code goes here
	magicArray1 = isMagicSquare(magicArray[0], magicArray[1], magicArray[2], 3);
	return 0;
}
// Function definitions go here


//function to get the range 
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max) {
	//for loop to iterate through the rows
	for ( int i = 0; i < 3; i++)
	{
		//if arrayrow is greater than the max it will return false
		if (arrayRow1[i] > MAX || arrayRow2[i] > max || arrayRow3[i] > max)
		{
			return false;
		}
		//if arrayrow is less than the min it will return false
		else if (arrayRow1[i] < MIN || arrayRow2[i] < MIN || arrayRow3[i] < MIN) {
			return false;
		}
	}
	return true;
}
//function to insure all numbers are unqire and do not repeat 
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
	//for to iterate 
	for (int i = 0; i < size -1; i++)
	{
		//for loop to compare first iterating numbers
		for (int j = i; j <size ; j++)
		{
			//compares each number to check for unique numbers
			if (arrayRow1[i] == arrayRow1[j] || arrayRow2[i] == arrayRow2[j] || arrayRow3[i] == arrayRow3[j] ||
				arrayRow1[i] == arrayRow2[j] || arrayRow1[i] == arrayRow3[j] || arrayRow2[i] == arrayRow3[j])
			{
				return false;
			}

		}

	}

	return true;
}
//function to check the sum of each row to see if they all have the same sum
bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size) {
	//declaration to test
	int sum1 = 0, sum2 = 0, sum3 =0 ;
	//loop to iterate through each row
	for (int i = 0; i < 3; i++)
	{
		sum1 += arrayrow1[i];
		sum2 += arrayrow2[i];
		sum3 += arrayrow3[i];
	}
	//if statements to check if the all equal and if not returns false
	if (sum1 != sum2)
	{
		return false;
	}
	if (sum1 != sum3)
	{
		return false;
	}
	if (sum3 != sum2)
	{
		return false;
	}
	else {
		return true;
	}


}

//function to check that the columns equal the same sum
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size) {
	//declarations to test
	int sum1, sum2, sum3;
	//function to test
	sum1 = arrayrow1[0] + arrayrow2[0] + arrayrow3[0];
	sum2 = arrayrow1[1] + arrayrow2[1] + arrayrow3[1];
	sum3 = arrayrow1[2] + arrayrow2[2] + arrayrow3[2];
	
	//if statement to compare each column
	if (sum1 != sum2)
	{
		return false;
	}
	if (sum1 != sum3)
	{
		return false;
	}
	if (sum3 != sum2)
	{
		return false;
	}
	else {
		return true;
	}

}

//check the sum of the rows diagonally 
bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size) {
	//declarations for test
	int sum1, sum2;
	//calculations to check rows
	sum1 = arrayrow1[0] + arrayrow2[1] + arrayrow3[2];
	sum2 = arrayrow1[2] + arrayrow2[1] + arrayrow3[0];

	//if statement to compare each row
	if (sum1 != sum2) {
		return false;
	}
	return true;
}
//function to fill the magic square
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
	//for loop to iterate through the first row
	for (int i = 0; i < 3; i++)
	{
		//asks the user to fill column 1
		cout << "Enter the number for row 0 and column " << i << endl;
		//users enters row 1 values
		cin >> arrayRow1[i];
	}
	//loop to iterate through the second row
	for (int i = 0; i < 3; i++)
	{
		//asks user to input the second row of numbers
		cout << "Enter the number for row 1 and column " << i << endl;
		//users inputs row 2 numbers
		cin >> arrayRow2[i];
	}
	//loop to iterate through the third row
	for (int i = 0; i < 3; i++)
	{
		//asks user to input the third row of numbers
		cout << "Enter the number for row 2 and column " << i << endl;
		//users enters row 3 values
		cin >> arrayRow3[i];
	}



}

//function to display the square 
void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size) {
	//prints out all numbers in row 1
	cout << arrayrow1[0] << " " << arrayrow1[1] << " " << arrayrow1[2] << endl;
	//prints out all numbers in row 2
	cout << arrayrow2[0] << " " << arrayrow2[1] << " " << arrayrow2[2] << endl;
	//prints out all numbers in row 3
	cout << arrayrow3[0] << " " << arrayrow3[1] << " " << arrayrow3[2] << endl;
}

//function to put all functions in and make the game work
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
	//declarations for user
	string name = "Brady Buttrey" , due = "5/5/2021" , projnum = "5";
	char again;
	bool retry = true, isColLoShu = false, isRowLoShu = false, isRangeLoShu = false, isUnique = false, isDiagLoShu = false;


	// loop to have users retry once finished
	while (retry)
	{

		//calls fill array function to fill the magic square 
		fillArray(arrayRow1, arrayRow2, arrayRow3, size = 3);
		//calls show array function to display the magic square 
		showArray(arrayRow1, arrayRow2, arrayRow3, 3);

		
		//check if the sum of the rows meet the requirements 
		isRowLoShu = checkRowSum(arrayRow1, arrayRow2, arrayRow3, 3);
		//check if the sum of the rows meet the requirements 
		isRangeLoShu = checkRange(arrayRow1, arrayRow2, arrayRow3, 3, MIN, MAX);
		//check if the numbers are all unqiue 
		isUnique = checkUnique(arrayRow1, arrayRow2, arrayRow3, 3);
		//check if the sum of the rows diagonally meet the requirements 
		isDiagLoShu = checkDiagSum(arrayRow1, arrayRow2, arrayRow3, 3);

		//if statement to check if columns 
		if (isRowLoShu)
		{
			//checks if the columns are all the same rum
			isColLoShu = checkColSum(arrayRow1, arrayRow2, arrayRow3, 3);
		}
		
		isColLoShu = checkColSum(arrayRow1, arrayRow2, arrayRow3, 3);
		//if statement to check all requirements of a lo shu magic square, will fall in this if not a lo shu
		if (!isRowLoShu || !isColLoShu || !isRangeLoShu || !isDiagLoShu || isUnique)
		{
			//displays message that it is not a magic square
			cout << "This is not a Lo Shu Magic Square!" << endl;
		}
		//if statement to check all requirements of a lo shu magic square, will fall in this if it is a lo shu
		if (isRowLoShu && isColLoShu && isRangeLoShu && isDiagLoShu && !isUnique)
		{
			//displays message that it is a magic square
			cout << "This is a Lo Shu Magic Square!" << endl;
		}
		//asks the user if they would like to try again
		cout << "Do you want to try again? (Y/N)" << endl;
		//user inputs y or n to try again or not
		cin >> again;
		//if statement to check the response if yes
		if (again == 'Y' || again == 'y') {
			//will start again
			continue;
		}
		//else to check for the "N" response 
		else {
			//does not restart
			retry = false;
			//displays programmer name
			cout << "Name: " << name << endl;
			//displayer project numbers
			cout << "Project #" << projnum << endl;
			//displays project due date
			cout << "Due date: " << due << endl;
		}

		return retry;
	}
}