
#ifndef PrietoCascio_Assn4_Common_h
#define PrietoCascio_Assn4_Common_h
#include<iostream>
#include <string>
using namespace std;

//Define Constants
const int NUM_MIN = 1;  //lower limit of random numbers
const int NUM_MAX = 30000;  // upper limit of random numbers
const int ARRAY_SIZE = 10000;   //max array size

bool search(int tempNum, const int randArray[], int size);
static int tempList[ARRAY_SIZE];
void genRandomArray(int randArray[]);
int getRndNum();
void userMenu(char &choice1, char &choice2);

#endif
