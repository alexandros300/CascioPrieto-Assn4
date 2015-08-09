#include <cstdlib>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
#include "PrietoCascio-assn4-common.h"
#include "Cascio-assn4-funcs.h"
#include "Prieto-assn4-funcs.h"
#include <ctime>
#include <string>
using namespace std;

int main(int argc, const char * argv[])
{
	int randArray[2*ARRAY_SIZE];
	int* Sort1 =new int[ARRAY_SIZE];
	int* Sort2 = new int[ARRAY_SIZE];
	int startTime, endTime, elapsedTime;
	float averageTimeSort1 = 0.0;
	float averageTimeSort2 = 0;
	char choice1=' ';
	char choice2=' ';
	int numberTimes =0;
	string sortType = "";
	string sortType1 = "";
	int i = 0;
	while (true){

		//Ask for two choice of sorting algo
		userMenu(choice1, choice2);
		if ((choice1 == 'E' && choice2 == 'E') || (choice1 == 'e' && choice2 == 'e')){
			return 0;
		}
		//generate ranarray

		cout << "\nEnter the number of times to repeat each sort (1 or more): ";
		cin >> numberTimes;


		for (i = 0; i < numberTimes; i++){
			// Perform action here that you want to time

			//Generate array of 10000 random numbers between 1 and 30000
			genRandomArray(randArray);


			//to make both array element unique
			for (i = 0; i < ARRAY_SIZE; i++){
				Sort1[i] = randArray[i];
			}

			//second array

			for (i = 0; i <  ARRAY_SIZE; i++){
				Sort2[i] = randArray[i + ARRAY_SIZE];
			}

			cout << "Starting sort #" << (i + 1) << "." << endl;
			{
				if (choice1 != 'E'){
					startTime = clock();

					switch (toupper(choice1)){
					case 'B':
						sortType = "Bubble Sort";
						bubbleSort(Sort1, ARRAY_SIZE);
						break;
					case 'M':
						sortType = "Merge Sort";
						mergesort(Sort1, tempList, 0, ARRAY_SIZE);
						break;

					case 'Q':
						sortType = "Quick Sort";
						quicksort(Sort1, 0, ARRAY_SIZE);

						break;
					case 'I':
						sortType = "Insertion Sort";
						insertionSort(Sort1, ARRAY_SIZE);
						break;

					case 'E':
						break;

					default:
						break;
					}

					endTime = clock();
					elapsedTime = endTime - startTime;
					report(sortType, elapsedTime);
					averageTimeSort1 += elapsedTime;
				}
			};



			{
				if (choice2 != 'E'){

					startTime = clock();
					switch (toupper(choice2)){
					case 'B':
						sortType1 = "Bubble Sort";
						bubbleSort(Sort2, ARRAY_SIZE);

						break;
					case 'M':
						sortType1 = "Merge Sort";
						mergesort(Sort2, tempList, 0, ARRAY_SIZE);
						break;

					case 'Q':
						sortType1 = "Quick Sort";
						quicksort(Sort2, 0, ARRAY_SIZE);

						break;
					case 'I':
						sortType1 = "Insertion Sort";
						insertionSort(Sort2, ARRAY_SIZE);
						break;

					case 'E':
						break;

					default:
						break;
					}
					endTime = clock();
					elapsedTime = endTime - startTime;
					averageTimeSort2 += elapsedTime;
					report(sortType1, elapsedTime);

				}
			}

			if (vaildArray(Sort1,Sort2, ARRAY_SIZE) == true){
					cout << "\tSorts validated" << endl;
				}
			};
		
		cout << endl;
		averageTimeSort1 = (averageTimeSort1 / numberTimes);
		averageTimeSort2 = (averageTimeSort2 / numberTimes);
		
		cout << "SORTING RESULTS" << endl;
		cout << "---------------" << endl;
		cout << "\t" << std::right<< sortType << setw(13) << (averageTimeSort1 ) << " clock ticks on average" << endl;
		cout << "\t" << std::right<<sortType1 << setw(13) <<  (averageTimeSort2 ) << " clock ticks on average" << endl;

		system("pause");
		
	}
			
	//Print the report

	//User chooses table size for tests and initial hash method
	return 0;
}
