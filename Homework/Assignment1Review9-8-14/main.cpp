/*
* File: main.cpp
* Author: Tracy Quintos
* Created on September 8, 2014, 10:00 PM
* Purpose: Assignment1Review9-8-14 
*/
#include <iostream>
#include <iomanip> //set precision
#include <string.h> //string compare prob 7
#include <fstream>
using namespace std;
//User Libraries
//Global constants
//Function Prototypes
int binarySearch(char *[], int, string);
void sortArray(char *[], int);
float cvs (int fahrenheit); // function celcius
void con(); //function to continue
void displayMenu(); //function to display menu
int getMenu(); //function get menu
void problem1(); //function for prob#1
void problem2(); //function for prob#2
void problem3(); //function for prob#3
void problem4(); //function for prob#4
void problem5(); //function for prob#5
void problem6(); //function for prob#6
void problem7(); //function for prob#7
void endProgram();
//Execution begins here!
int main(int argc, char** argv) {
int input;
do{
displayMenu();
input=getMenu();
switch(input){
case 1: problem1();break;
case 2: problem2();break;
case 3: problem3();break;
case 4: problem4();break;
case 5: problem5();break;
case 6: problem6();break;
case 7: problem7();break;
case 8: endProgram();break;
default:(input);
};
}while(input<=8);
return 0;
}
void con()
{
cout<<"Press Enter to continue..."<<endl;
cin.ignore();
}
void displayMenu()
{
cout<<"[1] Problem 3.12"<<endl;
cout<<"[2] Problem 3.13"<<endl;
cout<<"[3] Problem 4.10"<<endl;
cout<<"[4] Problem 5.11"<<endl;
cout<<"[5] Problem 6.7"<<endl;
cout<<"[6] Problem 7.6"<<endl;
cout<<"[7] Problem 8.7"<<endl;
cout<<"[8] Exit Program"<<endl;
}
int getMenu() //menu function
{
int input; //problem number input
cin>>input; //holds the 
return input;
}
void problem1()
{
    
  const float TAX_STATE = .04; //state tax rate @ 4%
  const float TAX_COUNTY = .02; // tax county @ 2%
  const float TAX_TOTAL = .06; // total tax @ 6%
  char month[16], year[5];
  float totalCol; // the amount collected at the register
  float sales; //holds the sales which is the total collected divided by 1.06
  float taxsumCounty; //holds the county sales tax multiplied by sales
  float taxsumState;  //holds the state sales tax multiplied by sales 
  float taxsumTotal; //holds the total sales tax multiplied by sales
 
  cout << setprecision(2) << fixed;
 
  cout << "Please enter the month you are reporting: " << endl;
  cin >> month;
  
  cout << "Please enter the year you are reporting: " << endl;
  cin >> year;
 
  cout << "Please enter the total dollar amount collected from register?" << endl;
  cin >> totalCol;
 
  sales = totalCol / 1.06; // formula given by gaddis book
  taxsumCounty = sales * TAX_COUNTY;
  taxsumState = sales * TAX_STATE;
  taxsumTotal = sales * TAX_TOTAL;
 
  cout << left << setw(7) << "Month: " << setw(13) <<  month;
  cout << setw(5) << "Year: " << setw(5) << year << endl;
  cout << "------------------------------" << endl;
  cout << left << setw(20) << "Total Collected:";
  cout << "$" << right << setw(9) << totalCol << endl;
  cout << left << setw(20) << "Sales:";
  cout << "$" << right << setw(9) << sales << endl;
  cout << left << setw(20) << "County Sales Tax:";
  cout << "$" << right << setw(9) << taxsumCounty << endl;
  cout << left << setw(20) << "State Sales Tax:";
  cout << "$" << right << setw(9) << taxsumState << endl;
  cout << left << setw(20) << "Total Sales Tax:";
  cout << "$" << right << setw(9) << taxsumTotal << endl;
    
}
void problem2()
{
    
    float propertyTax = .64; //set tax per 100$ given by gaddis book
    float propertyValue = 0; //property value
    float asmentValue = 0; //assessment value for each $100
    float propertytaxFinal = 0; //assessed property tax
    
    cout << fixed << setprecision(2);
    
    cout << "Please enter the property value:"<<endl;
    cin >> propertyValue; //user must enter in a value
    
    
    asmentValue =  propertyValue * .60; //calculates the assessment value of
    propertytaxFinal = propertyTax * asmentValue / 100; //calculates property tax
    
    cout << "The assessment value is $" << asmentValue<<endl; //displays the assessment value of property
    cout << "The property tax is $" << propertytaxFinal; //displays the property tax calculated above
    
}
void problem3()
{
    
float unitsSold; //Holds units sold
float totalCost; //total cost
float discount; //discount to be given
float packagePrice = 99.00;
	 
//Get the quantity purchased
cout << "Please enter the number of units sold\n";
cin >> unitsSold;
	     
//Determines the discount
            if (unitsSold <= 19) 
            { 
                discount = .20;
                cout << "Your discount is 20%\n"; 
            }
	         
	    else if(unitsSold <= 49)
	    {
	        discount = .30;
	        cout << "Your discount is 30%\n";
	    }
	         
	    else if(unitsSold <= 99)
	    {
	        discount = .40;
	        cout << "Your discount is 40%\n";
	    }
	         
	    else if (unitsSold >= 100)
	    {
	        discount = .50;
	        cout << "Your discount is 50%\n";
	    }
	         
	     
	//Calculates totalcost
	    totalCost = packagePrice * unitsSold * discount;
	 
	//Displays totalcost
	    cout << "Your Total Cost is: $\n";
	    cout << totalCost << endl;
    
}
void problem4()
{
    
float daysG;//number of days the population will increase
float population_increase;//percentage of increase each day
float population_size;//starting size of population
//User must enter the original number of organisms
cout<<"Please enter the original size of the population: ";
cin>>population_size;
//if the user enters a number less than 2, ask for a number larger than 1
while(population_size < 2)
{
//as requested by book, user will be prompted to re-enter value
cout << "Sorry, the original number of organism must be greater than 1";
cin >> population_size;
}
//User must enter the percentage growth of population in decimal form
cout<<"Please enter the % of growth rate in decimal form: ";
cin>>population_increase;
//if the user enters a negative percentage, ask for a positive percentage
while(population_increase < 0.0)
{
//as requested by book the user is not allowed to enter a negative value for growth %
cout<<"Please do not enter negative %";
cin>>population_increase;
}
//User must enter the number of days the organisms will grow
cout<<"Please enter the number of days the organisms will grow: ";
cin>>daysG;
//if user enters a number less than 1, ask for a number larger than 0
while(daysG < 1)
{
//The days entered must be higher than 1 day
cout<<"Number of days must exceed more than 1 day";
cin>>daysG;
}
cout<<setprecision(1)<<fixed;
//increments the days of growth
for (int count = 1; count <= daysG; count++)
{
//Outputs the incrementing days and the new growth population after calculations
//Calculations include: New population size being equal to the original population + (growth increase x original population)
cout<<"After day # " << count <<"-----";
population_size = population_size+(population_increase * population_size);
cout<<"Number of organisms grown is: "<<population_size<<endl;
}
    
}
void problem5()
{
    
    const int START_FAH = 0, //constants is taken from a previous assignment, modified it to use a function
          END_FAH = 20,
          INCREMENT = 1;

    
    float celcius; 
    cout<<fixed<<showpoint<<setprecision(2);
    
    for(int fahrenheit = START_FAH; fahrenheit <= END_FAH; fahrenheit ++) //fahrenheit conversion to celcius incremented by 20
    {
        celcius=cvs(fahrenheit);
        cout<<fahrenheit<<" Fahrenheit"<<" = "<<celcius<<" Celcius"<<endl;
    }
    
}
void problem6()
{
    
    int array[9];
    ifstream myfile ("numbers1.txt");
    
    int max, min, count, sum, avg;

    myfile >> max;
    min=max;
    count=1;

    sum=0;
    while(myfile >> array[9]){
        if(array[1] > max) max=array[1];
        if(array[1] < min) min=array[1];
        sum+=array[1];
        ++count;
    }

    cout << "min: " << min << endl
            << "max: " << max << endl 
            << "total: " << sum << endl
            << "average: " << sum/count << endl;
    
}
void problem7()
{
cin.ignore();    
const int SIZE = 20; //20 names given by gaddis book
	   char *name[] = {"Collins, Bill",  "Smith, Bart",  "Michalski, Joe", "Griffin, Jim",
	                   "Sanchez, Manny", "Rubin, Sarah", "Taylor, Tyrone", "Johnson, Jill",
	                   "Allison, Jeff",  "Moreno, Juan", "Wolfe, Bill",    "Whitman, Jean",
	                   "Moretti, Bella", "Wu, Hong",     "Patel, Renee",   "Harrison, Rose",
	                   "Smith, Cathy",   "Conroy, Pat",  "Kelly, Sean",    "Holland, Beth"};
	 
	string search; //holds search when the name is searched
	int results; //displays the array position of searched name
	 
	//Get a name to search for
	cout << "Enter the name you wish to search for: \n";
	//cin >> search;
	getline(cin, search);
        
        
	 
	//Sort the names
	sortArray(name, SIZE);
        
        	for (int i = 0; i < SIZE; i++)
	    {
	        cout << name[i] << endl;
	    }
	 
	    //Search for the name
	    results = binarySearch(name, SIZE, search);
	 
	    //If binarySearch returned -1, the name was not found
	    if (results == -1)
	        cout << "That name does not exist in the array.\n";
	    else
	    {
	        cout << "Name " << search << " was found in element "
	            << results << " of the array.\n";
	    }
    
}
void endProgram()
{
cout<<"Now exiting Program..."<<endl;
con();
cin.ignore();
}

void sortArray(char *string[], const int size) //sorting function given by gaddis bookm modified for string
                                               //as instructed
	{
	   int pass, i;
	   char *temp;
	 
	   for (pass=0; pass < size - 1; pass++)
	   {
	      for (i=0; i<size - 1; i++)
	      {
	         if (strcmp(string[i], string[i+1]) > 0)
	         {
	            temp = string[i];
	            string[i] = string[i+1];
	            string[i+1] = temp;
	         }
	      }
	   }
	}

        int binarySearch(char *word[], int size, string value) //binary search function modified for string 
                                                               //as instructed by book
	{
	    int first = 0,
	        last = size - 1,
	        middle,
	        position = -1;
	    bool found = false;
	 
	    while (!found && first <= last)
	    {
	        middle = (first + last) / 2;
	        if (word[middle] == value)
	        {
	            found = true;
	            position = middle;
	        }
	        else if (word[middle] > value)
	            last = middle - 1;
	        else
	            first = middle + 1;
	    }
	    return position;
	}

float cvs (int fahrenheit) //function holds the fahrenheit variable. 
{
    return (static_cast<float>(fahrenheit)-32)*5/9; //calcultes the conversion between fahernheit to
}