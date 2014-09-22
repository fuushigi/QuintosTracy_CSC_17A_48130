/*
* File: main.cpp
* Author: Tracy Quintos
* Created on September 19, 2014, 12:12 PM
*/
#include <cstdlib>
#include <iostream>
#include <iomanip> //set precision
#define N 100 //defining N to 100 for problem 8
using namespace std;
//User Libraries
//Global constants
//Function Prototypes
void con();
void displayMenu();
int getMenu();
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void endProgram();
void mode (int x[],int n);//mode function
int calculateMedian (int*,int); //median function
void intakeOfElements (int*,int);//elements function
void printElements (int*,int); //printing elements function
int *getArray(int num); //get array function for question 1 chap9

void getinfo(int*, int); //void function to collect numbers for array
void sort(int [], int); //sort function
float average(int*, int);//mean or average function
float median(int*, int);//median function
int get_mode(int*, int);//mode function
void showArr(int* arr, int size)
{
    for(int i = 0; i < size; ++i)
    cout << setw(8) << arr[i];
}
	 
// Function prototypes
void arrSelectSort( int*, int );
//Execution begins here!
int main(int argc, char** argv) 
{
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
case 7: endProgram();break;
default:(input);
};
}while(input<7);
return 0;
}
void con()
{
cout<<"Press Enter to continue..."<<endl;
cin.ignore();
}
void displayMenu()
{
cout<<"[1] Problem 1"<<endl;
cout<<"[2] Problem 2"<<endl;
cout<<"[3] Problem 10"<<endl;
cout<<"[4] Problem 9"<<endl;
cout<<"[5] Problem 8"<<endl;
cout<<"[6] Problem Assignment 1"<<endl;
cout<<"[7] Exit Program"<<endl;
}
int getMenu()
{
int input;
cin >> input;
return input;
}
void problem1()
{
int elem; //holds elements 
int* array; //holds pointer array

cout << "Enter the number of elements in the array:\n" << endl; //user needs to put # of elements desired
cin >> elem; //# of elemens desire for interger reverse
	 
array = getArray(elem); // array = the get array's element when user is prompted
	 
for(int i = 0; i < elem; ++i) //for loop to hold array
{
	cout << array[i] << endl;
}
	  
	 
delete[] array; // deletes first array   
}
void problem2()
{
int numTests; //holds number of tests given by user

cout << "How many test scores (1..10) do you wish " << "to enter? " << flush;
cin >> numTests; //input number of tests
	
while( !cin.good() || numTests < 1 || numTests > 10 )
    {
	cout << "Enter an integer in range 1..10 : " << flush;
	cin.clear(); // clear cin stream error flags
	cin.sync(); // 'flush' cin stream
	cin >> numTests;
    }
	cin.sync();
	int* testScores = new int[numTests];
	 
	cout << "Enter the test scores below.\n";
	int  sumTestScores = 0.0;
	for( int count = 0; count < numTests; ++count )
	   {
	      cout << "Test Score " << (count + 1)
	           << ": " << flush;
	      cin >> testScores[count];
	 
	      // Only numbers in range 0.0..100.0 valid
	      while( !cin.good() ||
	             testScores[count] < 0.0 ||
	             testScores[count] > 100.0 )
	      {
	         cout << "Valid score range is 0..100"
	              << "  Please enter again: ";
	         cin.clear();
	         cin.sync();
	         cin >> testScores[count];
	      }
	      cin.sync();
	      sumTestScores += testScores[count];
	 
	   }
	   // Display the results
	   cout << "\nYou entered testScores: \n";
	   cout << fixed << showpoint << setprecision(2);
	   showArr( testScores, numTests );
	    
	   cout << "\nThe average score is "
	        << sumTestScores / numTests << endl;
	 
	   //Display the Test Scores in ascending order
	   cout << "The test scores, sorted in ascending "
	        << "order, are: \n";
	         
	   arrSelectSort( testScores, numTests );
	   // now display ...
	   showArr( testScores, numTests );
	 
	   // Free dynamically allocated memory ...
	   delete [] testScores;
	   testScores = 0; // make testScores point to null
	 
	   // to keep window open until 'Enter' pressed
	   cin.get();
}

void problem3()
{
    int Arr[100]; // holds array and with size element 100. 0-99
    int n; //holds n number of elements desired
    int temp; // holds temp array
    int i; //holds i
    int j; // j

	cout << "Please enter for the # of elements."; //user must enter the number of desire elements
	cin >> n; // # of elements

	for(i=0;i<n;i++) //for loop that counts the element #s
	{
		cout<<"Enter element " << i+1 << ":"; //displays elements and counts ++ 
		cin>>Arr[i]; //user must enter the array of [i]
	}

	for(i=0,j=n-1;i<n/2;i++,j--) //for loop to reverse the array
	{
		temp = Arr[i]; //temporary array = the array of [i]
		Arr[i] = Arr[j]; //array of [i] becomes array of [j]]
		Arr[j] = temp;  //array of [j]] becomes equal to temporary array
	}

	cout<<"\nReverse array"<<endl; //reverse msg

	for(i=0;i<n;i++) //for loop for displaying the array of [i] when reversal has taken place
        cout<<Arr[i]<<" "; //couts array of [i]

	cin.ignore();
	cin.get();
}
void problem4()
{
int nElements; //holds elements #s
        
cout<<"Please enter the number of elements desired:"; //displays # of elements wanted
cin>>nElements; // holds the number of elements given by yser

int *ptrArray = new int[nElements]; //pointer array = elements

intakeOfElements(ptrArray, nElements); //intakeOfElements function

int dMedian = calculateMedian(ptrArray, nElements); //median = calculateMedian function

printElements(ptrArray, nElements); // printElements function

cout << "The median of set is: " << dMedian << endl; //displats the median

delete [] ptrArray; //delete operator on the array
}
void problem5()
{
int x[N];
int n=0,i=0;
int m = 0;

cout<<"Enter in as many as 100 values, when finished enter in m"<<endl;
while(1)
       {
           n++;

           cin>>x[i];
           if (x[i]==m)
           {
               break;
           }
            i++;
       }

        mode(x,n);//send the values of x[] and n to mode function
}
void problem6()
{
    int*array; //int array with ptr for the functions
int num; //holds numbers for element
int mode,i;//holds mode and i
float avg; //set avg to a float
cout << "Please enter the number of elements desired: ";
cin >> num; //enter num for elements

while(num<=0) //while loop num <= 0
{
    cout << "Invalid Entry\n"; //output msg invalid entry
    cout << "Please enter the number of elements desired: ";
    cin >> num;//num that represents the # of elements desired by user
}
array = new int[num]; //array is equal to the new array
getinfo(array, num); //getinfo function called
cout << "\nThe array is:\n"; //displays the array below

for(i=0;i<num;i++) //for loop to display what element # and the numbers given in descending order
cout << "Element " << (i+1)<< ": "<< *(array+i) <<endl;
sort(array, num); //sort array called
cout << "\nThe median is: " << median(array, num) << endl; //displays the median
cout << "The average is: " <<average(array, num) << endl; //displays the average or mean
mode = get_mode(array, num); //mode function called

if (mode == -1) //if mode is equal to -1 then there is no mode
cout << "No mode.\n";
else
cout << "The mode is: " << mode << endl; //else mode is displayed
delete [] array; //delete array
}
void endProgram()
{
cout<<"Now exiting Program..."<<endl;
con();
cin.ignore();
}

int *getArray(int num) //get array function
{

int* array = 0; //dynamic array set to  0
int count, *ptr = array; //holds count and pointer = array
array = new int[num]; //array = new reversed array 
 
cout << "Enter the intergers to be placed in the array.\n"; //user needs to enter intergers  elements in dynamic array
	 
for (count = 0; count < num; count++) //for loop to count the number of # of elements, user must enter an interger for dynamic array
{
	cout << "Interger number  " << (count + 1) << " : "; //holds interger 1 through # of desired elements of array 
                                                            //and displays desired intergers
	        cin >> array[count];
}
	    ptr = array; //pointer == array
	 
	    return ptr;// returns pointer array count
}

void arrSelectSort( int* arr, int size )
{
	  
}

void intakeOfElements(int* ptr, int iN) //function holding and for inputing elements and the values
{
int *ptrI; //pointer I
int *ptrJ; //pointer J
int dTemp; //holds dTemp which is the values 

	for(ptrI = ptr; ptrI < ptr+iN; ptrI++) //for loop for next elements 
	{
	   cout << "Next element: "; //displays elements for loop
           cin >> dTemp; //holds temporary values

	   for(ptrJ = ptrI-1; ptrJ >= ptr && *ptrJ > dTemp; *(ptrJ+1) = *ptrJ ,ptrJ--);
           //sorts array for loop
          *(ptrJ+1)= dTemp;
	}
}

int calculateMedian(int* ptr, int iN) //median function
{
 int dResult; // number of the elements in that array.
 int iHalf = iN/2;
 
    if(iN%2==0) //if in is / by 2 is equal to 0
    {
       dResult = (*(ptr + iHalf-1)+ *(ptr + iHalf))/int(2);
    }
        else
        {
            dResult = *(ptr + iHalf);
        }
 return dResult;
}

void printElements(int* ptr, int iN) //displays the sorted value from element values given by user
   {
    for(int* d=ptr; d < ptr+iN; cout<<*d<<endl, d++);
   }

void mode (int x[],int n)
{
    int y[N]={0};//Sets all arrays equal to 0, defining 99 (#define N 100)
    int i; //holds i for nested
    int j,k,m; //holds intergers for loop to find the highest number in the array
    int cnt; // holds counters
    int max=0,no_mode=0,mode_cnt=0; //holds maximum mode(s) given, no_mode set to 0, //mode_count set to 0 number of modes counted 
    int num; //holds numbers for mode function

    for(k=0; k<n; k++)//Loop to count an array from left to right
{
    cnt=0;
    num=x[k];//Num will equal the value of array x[k]

    for(i=k; i<n; i++)//Nested loop to search for a value equal to x[k]
    {
        if(num==x[i])
            cnt++;//if a number is found that is equal to x[k] count will go up by one

    }
    y[k]=cnt;//The array y[k] is initialized the value of whatever count is after the nested loop
    if(cnt>=2)//If cnt is greater or equal to two then there must be atleast one mode, so no_mode goes up by one
    {
        no_mode++;
    }
}

if(no_mode==0)//after the for loops have excuted and still no_mode hasn't been incremented, there mustn't be a mode
{
    //Print there in no mode and return control to main
    cout<<"This data set has no modes\n"<<endl;
    return;
}
    for(j=0; j<n; j++)
//A loop to find the highest number in the array
    {   
		if(y[j]>max)
        max=y[j];
    }
 for(m=0; m<n; m++)//This loop finds how many modes there are in the data set
{
    //If the max is equal to y[m] then that is a mode and mode_cnt is incremeted by one
    if(max==y[m])
    mode_cnt++;
}
cout << "This data set has "<< mode_cnt << " mode(s)" <<endl;//Prints out how many modes there are
    for(m=0; m<n; m++)
    {
        if(max==y[m])//If max is equal to y[m] then the same sub set of array x[] is the actual mode
        {

            cout << "The value " << x[m] <<" appeared " << y[m] << " times in the data set\n"<<endl;
        }
    }
return;
}
void getinfo(int a[], int n) //get info function stores element #s 
{
int i; //setting i as an int

for (i= 0;i<n;i++) //for loop to display elements and array
{
    do
    {
        cout<<"Element "<<(i+1)<< ": ";
        cin >> a[i]; //array of i holds the element for array
        if(a[i]<0||a[i]>100) //if statement for validation
        cout<<"Invalid entry, Please enter a value between 0 and 100\n";
    }
    while(a[i]<0||a[i]>100); //while loop states a [i] < 0 OR > 100
}   
}

float average(int a[], int num) //mean or average function
{ 
int tot = 0,i; //setting total to O, and holds int i
float avg; //average as a float

for (i= 0;i<num; i++) //for loop to get total from a [i] by addition
tot += a[i];//equation to find total
avg=(float)tot/num; //avg is found by total divided by the number
return avg; //returns the avg back to main
}

void sort(int a[], int n) //sorting function
{ 
int i,j,t; //holds i, j and t

for(i=0;i<n-1;i++)// for loop for sorting

    for(j=i;j<n;j++) //sorting

        if(a[i]>a[j]) //if a[i]>a[j then
        {
            t=a[i]; //t is equal to a[i]
            a[i]=a[j]; //a[j] = a[i]
            a[j]=t; //a[j] to t, finishing sort
        }
}
float median(int* a, int n) //median function
{ 
int m1,m2;

if (n%2==0) //if the number can be % by 2
{
    m1=n/2; //m1 is found by dividing n by 2
    m2=(n/2)-1;//m2 is found by diving n by to then -1
    return((*(a+m1)+*(a+m2))/2.); //returns the calculated median back to main
}
else

return *(a+(n/2)); //returns the calculated median back to main
}

int get_mode(int* a, int n) //mode function
{
int* count,most,index,i,j; //int ptr holds count, most, index i and j
count= new int[n]; //count = new int array 

for(i= 0;i< n;i++)
count[i] = 0;

for(i=0;i<n;i++) //for loop for median
{
    for(j=0;j<n;j++)
    {
        if (*(a+j)==*(a +i))
        (*(count+i))++;
    }
}
most=*count; //most = to count ptr
index=0; //setting index = 0

for (i=1;i<n;i++) //for loop to find the mode, which number occurs the most
{
    if (*(count+i) >most)
    {
        most=*(count+i);
        index=i;
    }
}
if (most == 1)
return -1; //returns false
else //else returns mode
return *(a+index);
} 
