#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <string>
#include "PrietoCascio-assn4-common.h"
using namespace std;

/*******************************************************************************
FUNCTION: search
DESCRIPTION: Takes in an array that is to be filled by the function.
Will set first index as needed from getRndNum and verify there is no
duplication with search and a logical boolean of true or false.
INPUT:
Parameters: tempNum, randArray, size. tempNum is the number used
to compare generated from getRndNum. randArray is the array holding
the non-duplicated random numbers, and size specifies the max size
of the array.
OUTPUT: 
Return Val: boolean of true or false where true indicates duplicate
and makes sure the number is not added to the array, while false
indicates the number doesn't exist within the given array.
IMPLEMENTED BY: Prieto
*******************************************************************************/
bool search(int tempNum, const int randArray[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (randArray[i] == tempNum)
		{
			return true;
		}
	}
	return false;
}


/*******************************************************************************
FUNCTION: genRandomArray
DESCRIPTION: Takes in an array that is to be filled by the function.
Will set first index as needed from getRndNum and verify there is no
duplication with search and a logical boolean of true or false.
INPUT:
Parameters: randArray, randArray is the array we will use
to contain the 5000 shuffled numbers with no duplicates.
CALLS TO: getRndNum, search
IMPLEMENTED BY: Prieto
*******************************************************************************/
void genRandomArray(int randArray[]);
{
	int numberCount = 0;   //count of array spaces filled
	int tempNum;    // number returned from GenerateNumber and tested in array

	srand(time(NULL)); // prevents the same random numbers from being created

	tempNum = getRndNum();
	randArray[numberCount] = tempNum;
	numberCount = 1;

	// Now loop to 5000 generating numbers and searching array for them ...
	// add if unique
	while (numberCount < 2*ARRAY_SIZE)
	{
		tempNum = getRndNum();
		if (!search(tempNum, randArray, numberCount))
		{
			randArray[numberCount] = tempNum;
			numberCount++;
		}
	}
}

/*******************************************************************************
FUNCTION: getRndNum
DESCRIPTION: Returns a number generated by rand from system and only
pulls number from specified range.
OUTPUT:
Return Val: int, random int returned to call within a specific range.
IMPLEMENTED BY: Prieto
*******************************************************************************/
int getRndNum();
{
	return (rand() % ((NUM_MAX + NUM_MIN) + 1));
}

/*******************************************************************************
FUNCTION: userMenu
DESCRIPTION: Takes user input for the two types of sorting methods to be compared
OUTPUT:
Return Val: choice1 and choice2
IMPLEMENTED BY: Prieto
*******************************************************************************/
void userMenu(char &choice1, char &choice2);
{

	cout << "Choose two sorts you wish to compare:" << endl;
	cout << "\tB = Bubble sort" << endl;
	cout << "\tI = Insertion sort" << endl;
	cout << "\tM = Merge sort" << endl;
	cout << "\tQ = Quick sort" << endl;
	cout << "\tE = Exit program" << endl;
	cout << "\nEnter two letter choices (or EE to exit): ";
	cin >> choice1 >> choice2;

}
