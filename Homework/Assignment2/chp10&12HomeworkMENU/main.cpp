/*
* File: main.cpp
* Author: Tracy Quintos
* Created on October 3 , 2014, 12:12 PM
* Purpose: Homework: 5 questions chp 10:::5 questions chp 12 
*/
#include <cstdlib>
#include <iostream>
#include <sstream> //for string buffer
#include <vector> //naming vector as "tracy"
#include <cstring> // header file needed to use strstr function problem chp10prob18
#include <cstdio> 
#include<fstream>
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
void problem7();
void problem8();
void problem9();
void problem10();
void endProgram();
void readTracyqq(const char *filename) //chp12prob5
{
        const int WORDZ = 24;
        fstream tracyfile(filename); //reading from file.txt
        if ( tracyfile )
    {   
        int words = 0;
        string line;
        while ( getline(tracyfile, line) )
    {   
            cout << ++words << ": " << line << '\n';
            if ( words % WORDZ == 0 )
            {
            cout << "Please press [Enter] to continue...next 24 lines" << flush;
            int ch;
            while ( (ch = cin.get()) != '\n' && ch != EOF ) // End-of-File has been reached or to signal some other failure conditions.
                {
                   //user is prompted to press [enter] to display more lines from tracyfile
                }
            }
        }
    }
                else
                {
                   perror(filename); //print error msg
                }
}
using std::cout; //Chp12Prob4
using std::ifstream; //Constructs an ifstream object //Chp12Prob4
using std::string; //Declaring a string //Chp12Prob4
using std::getline;//Chp12Prob4
size_t count_lines(const char *filename)//Chp12Prob4
{
ifstream tracyfile("tracytest.txt");//Chp12Prob4
string line; //string for line//Chp12Prob4
size_t count = 0; //Unsigned integral type = count//Chp12Prob4
while ( getline(tracyfile, line) )//Chp12Prob4
{
++count;//increment the words from tracyfile
}
return count; //returns the count
}
const int TRA = 20;////Chp12Prob13 declares [20] for char item (needed)
//declare variables
void Add(); //function to add information for inventory 
void Display(); //function to display information that was added
struct tracyInventory //Chp12Prob13 data structure
{
char item[TRA]; // item description
int qty; //quantity of item
int wcost; // wholesale cost of item
int rcost; //retail cost of item
char date[10]; //date setting
};
void sentenceCase(string&); //Chp10Prob5
void lowerCase(string&); //Chp10Prob5
bool isSentencePunc(char);//Chp10Prob5
void Backward (char *); //Chp10Prob2
void PigString( const string& aLine, vector< string>& tracy ) //chp10Prob16 pig latin function
    {
    string buffer;

    stringstream ss( aLine);

    while( ss >> buffer )
        tracy.push_back( buffer );

    }
void readTracy(const char *filename)
{
        const int WORDZ = 10;
        fstream tracyfile(filename); //reading from file.txt
        if ( tracyfile )
    {   
        int words = 0;
        string line;
        while ( getline(tracyfile, line) )
    {   
            cout << ++words << ": " << line << '\n';
            if ( words % WORDZ == 0 )
            {
            cout << "The entire file has been read from tracy3.txt" << flush;
            int ch;
            while ( (ch = cin.get()) != '\n' && ch != EOF ) // End-of-File has been reached or to signal some other failure conditions.
                {
                   //user is prompted to press [enter] to display more lines from tracyfile
                }
            }
        }
    }
                else
                {
                   perror(filename); //Print error message
                }
}
void readTracyq(const char *filename) //chp12Prob2
{
        const int WORDZ = 24;
        fstream tracyfile(filename); //reading from file.txt
        if ( tracyfile )
    {   
        int words = 0;
        string line;
        while ( getline(tracyfile, line) )
    {   
            cout << ++words << ": " << line << '\n';
            if ( words % WORDZ == 0 )
            {
            cout << "Please press [Enter] to continue...next 24 lines" << flush;
            int ch;
            while ( (ch = cin.get()) != '\n' && ch != EOF ) // End-of-File has been reached or to signal some other failure conditions.
                {
                   //user is prompted to press [enter] to display more lines from tracyfile
                }
            }
        }
    }
                else
                {
                   perror(filename);
                }
}
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
case 8: problem8();break;
case 9: problem9();break;
case 10: problem10();break;
case 11: endProgram();break;
default:(input);
};
}while(input<11);
return 0;
}
void con()
{
cout<<"Press Enter to continue..."<<endl;
cin.ignore();
}
void displayMenu()
{
cout<<"[1] Chp10Prob16"<<endl;
cout<<"[2] Chp10Prob14"<<endl;
cout<<"[3] Chp10Prob18"<<endl;
cout<<"[4] Chp10Prob2"<<endl;
cout<<"[5] Chp10Prob5"<<endl;
cout<<"[6] Chp12Prob1"<<endl;
cout<<"[7] Chp12Prob13"<<endl;
cout<<"[8] Chp12Prob2"<<endl;
cout<<"[9] Chp12Prob5"<<endl;
cout<<"[10] Chp12Prob4"<<endl;
cout<<"[11] Exit Program"<<endl;
}
int getMenu()
{
int input;
cin>>input;
return input;
}
void problem1()
{
    
    bool bFoundVowel = false;
    

    int
        i = 0,
        j = 0;

    string
        message = "", //message/phrase or word that user has entered in
        new_word = "", //placing first letter of word in the back 
        swine_speech = "", //pig latin phrase converted from "message"
        play_again = "Y",
        vowels = "aeiou";

    vector< string > tracy;

    while( play_again == "Y" || play_again == "y" )
        {
        swine_speech = "";

        tracy.clear();
        cin.ignore(); //needed to keep cout msg and exit method from displaying before user input
        cout << "Please enter a word or a sentence: ";

        getline( cin, message ); //getline= phrases/words/setences

        PigString( message, tracy ); //calls pigstring msg 

        vector< string >::iterator itr;

        for( i = 0, itr = tracy.begin(); itr != tracy.end(); i++, itr++ )
            {
            string AWord = *itr;

            bFoundVowel = false;

            for( j = 0; j < vowels.length(); j++ )
                {
                if( tolower( AWord[ 0 ] ) == vowels[ j ] )
                   {
                    bFoundVowel = true;

                    new_word = AWord + "ay "; //adds a pig latin "ay" at the end of word or letter

                    swine_speech += new_word;

                    break;

                    }       //      If we found a vowel     

                }       //      for( j < vowels.length() )      

            if( ! bFoundVowel )
               {
               new_word = AWord.substr( 1 );

               new_word += AWord[ 0 ];

               new_word += "ay "; //new_word = new_word + "ay"

               swine_speech += new_word; //swine_speech=swine_speech + new_word

              }       //      if( ! bFoundVowel )     

          }       //      for( itr != Tokens.end() )      

        cout << swine_speech << endl; //displays the pig latin phrase entered by user

        cout << "Run Pig Latin Program? (Y or N) ";

        getline( cin, play_again );

    }       /*      while() */

    cout << "Omecay Againay! (come again!) (Press Enter to exit)";
}
void problem2()
{
    
string sentence; //string sentence
int i;//Loop variable
//Inputting string
cout<<"Example:HelloMyDearFriend"<<endl; // an example of a sentence structure
cout<<"Please enter a sentence:"; // asks user to display a sentence
cin>>sentence; //user input cin>>sentence
i=1;

while(i<sentence.length())//While loop repeats untill end of sentence
{

if(isupper(sentence.at(i)))//Checks for upper case character
{

sentence.insert(i," "); //Inserting space

sentence.at(i+1)=tolower(sentence.at(i+1)); //Converting to lower case
}
i++;
}

cout<<sentence<<endl;
  
}
void problem3()
{
cin.ignore();    
bool found = false;		// flag to find if contact was found
const int num = 11;		// num holds 11 contacts
const int length = 100;		// Maximum allowable charactersfor each line is 100

//  Array contacts[][] holds 11 contacts with phone numbers
char contacts[num][length] = {   "Becky Warren, 555-1223", 
                                 "Joe Looney, 555-0097",
                                 "Geri Palmer, 555-8787", 
                                 "Lynn Presnell, 555-1212",
                                 "Holly Gaddis, 555-8878", 
                                 "Sam Wiggins, 555-0998",
                                 "Bob Kain, 555-8712", 
                                 "Tim Haynes, 555-7676",
                                 "Warren Gaddis, 555-9037", 
                                 "Jean James, 555-4949",
                                 "Ron Palmer, 555-2783"};

char search[length];		//Array search[] holds user's input
                                                        //and searches inside the array contacts[][]
char *IdContact = NULL;		// IdContact points to the user's query inside array contacts[][]
int index;		// loop counter

//Prompts user to search for contacts
cout << "Please enter in first name or last name of contact to search contact number\n";
cin.getline(search, length);		//user's input

//Searches array for matching substring
for (index = 0; index < num; index++)
{
        IdContact = strstr(contacts[index], search);
                if (IdContact != NULL)
                {
                        cout << contacts[index] <<endl;		//prints all possible contacts with in the string
                        found = true;	//set the flag
                }
}

//if flagged as false, no matches are found and error message is displayed;
if (!found)
cout << "Sorry, No matches were found!";
}
void problem4()
{
    
// define array for letters in a word entered  and size of array allowed     
char word[31];

// ask user for input
cout << "Please enter a word not over 30 letters:" << endl;

// display word entered backwards
cin >> word;

cout << "The entered word displayed in reverse is: " << word << endl;

Backward(word); //backward function call

cout << endl;
    
}
void problem5()
{
 cin.ignore();
 const string SENTINEL = "0";//When entered as strToConvert,
                            //terminates program.  
  string strToConvert;    //The string that will be converted


  //Read in strToConvert
  cout << "Sentence Capitalizer example: hi. today we will swim. or not." << endl; //exmaple for user to follow
  cout << "\n\nEnter a String or enter 0 to exit: ";
  getline(cin, strToConvert);

  while (strToConvert != SENTINEL)
  {
    sentenceCase(strToConvert);
    cout << "New String: " << strToConvert;
   
    //Read in strToConvert
    cout << "\n\nEnter a String or enter 0 to exit: ";
    getline(cin, strToConvert);
  }
    
}
void problem6()
{
cin.ignore();    
readTracy("tracy3.txt"); //naming the file
    
}
void problem7()
{
    
    int choice; //user input choices 1-2
do //displays the option for switch statement/ menu
{
cout << "MENU" << endl;
cout << "1. Add Record: " << endl;
cout << "2. Display Records: " << endl;
cout << "Please enter your selection." << endl;
cin >> choice;

switch (choice) //switch statement for menu 1 and 2
{
case 1: 
Add(); 
break;	//Add record
case 2: 
Display(); 
break;	//Display record

default: cout << "Invalid Selection" << endl;
}
} while 
(choice <= 2);
    
}
void problem8()
{
 cin.ignore();   
 readTracyq("tracy.txt"); //naming the file and calling read function
    
}
void problem9()
{
    
const char filename[] = "tracytest.txt";
size_t i, count = count_lines(filename);
ifstream myfile(filename); //reads tracytest.txt
string line;
for ( i = 0; i < count - 10; ++i ) //for loop to display the last 10 lines of tracytest
{
getline(myfile, line); /* read and discard: skip line */
}
while ( getline(myfile, line) )
{
cout << line << "\n"; //displays the last 10 lines from tracytest.txt as instructed by gaddis
}
    
}
void problem10()
{ 
cin.ignore();    
readTracyqq("tracy2.txt"); //naming the file
    
}
void endProgram()
{
cout<<"Now exiting Program..."<<endl;
con();
cin.ignore();
}

void Backward (char *sentencePtr) //Ch10Prob2

{

       char *p = sentencePtr;
       while ( *p != '\0' )

             ++p;

       while ( p != sentencePtr )

             cout.put ( *--p );
      

}

/*function sentenceCase
Description: Converts a string so that the first letter of the first word
of a sentence is capitalized.

PARAMETERS
  strToConvert: the string being manipulated

Precondition:
  strToConvert: undefined

  HEADERS
  #include <string>

Postcondition:
  Returns the manipulated string by reference */

void sentenceCase(string& strToConvert) //Chp10Prob5
{
  //Identifies if the sentence has been capitalized. Set to false by default.
  bool thisSentenceCapped = false;
  lowerCase(strToConvert);  //Lowercase the string before processing.

  for (unsigned int i=0; i<strToConvert.length();i++)
  {
    //At a punctuation mark, the next sentence has not been manipulated
    //yet to have its first letter capitalized, so thisSentenceCapped is false.
    if (isSentencePunc(strToConvert[i]))
      thisSentenceCapped = false;

    if ((thisSentenceCapped==false) && (isalpha(strToConvert[i])))
    {
      strToConvert[i]=toupper(strToConvert[i]);
      thisSentenceCapped = true;
    }

  }
}

/*function lowerCase 
Description: makes all the characters of a string lowercase

PARAMETERS
  strToConvert: the string being manipulated

Precondition:
  strToConvert: undefined

  HEADERS
  #include <string>

Postcondition:
  Returns the string all lowercase */

void lowerCase(string& strToConvert)
{
   for(unsigned int i=0;i<strToConvert.length();i++)
   {
      strToConvert[i] = tolower(strToConvert[i]);
   }
}

/*function isSentencePunc 
Description: Checks to see if a character is a punctuation mark used to denote
the end of a sentence. (! . ?)

PARAMETERS
  character: The character being tested

Precondition:
  character: defined

Postcondition:
  Returns boolean value of true if the character is ! . or ? */

bool isSentencePunc(char character)
{
  switch(character)
  {
    case '!':
    case '.':
    case '?':
      return true;
    default:
      return false;
  }
}

void Add() // chp12Prob13 add function to file
{
fstream tracy;
const int size = 3;
char ch;
int i = 0;
tracy.open("tracyRecords.txt", ios::ate);
tracyInventory inv;

//get data
do
{
cout << "Please enter item description: " << endl; //
cin.ignore();
cin.getline(inv.item, TRA);
cout << "Please enter quantity: " << endl;
cin >> inv.qty;
cout << " Please enter wholesale cost: " << endl;
cin >> inv.wcost;
cout << "Please enter retail cost: " << endl;
cin >> inv.rcost;
cout << "Please enter date: " << endl;
cin.ignore();
cin.getline(inv.date, 10);

//write record to file
tracy.write(reinterpret_cast<char*>(&inv), sizeof(inv));
cout << "Do you want to add another record? " << endl;
cin >> ch;
} while
(ch == 'Y' && 1 < 3);

//close the file
tracy.close();
}

//"Display" function 
void Display() // chp12Prob13 display function
{
fstream tracy; //reads from file and displays
tracy.open("tracyRecords.txt", ios::ate); //stream's position indicator to the end of the stream on opening
tracyInventory inv;
tracy.read(reinterpret_cast <char*> (&inv), sizeof(inv));//convert integer types to pointer types 
while (!tracy.eof())
{

cout << "\nDescription\t: ";
cout << inv.item;
cout << "\nQuantity\t: ";
cout << inv.qty;
cout << "\nWholesale Cost\t: ";
cout << inv.wcost;
cout << "\nRetail Cost\t: ";
cout << inv.rcost;
cout << "\nDate\t: ";
cout << inv.date;
tracy.read(reinterpret_cast <char*> (&inv), sizeof(inv));//convert integer types to pointer types 
}
//close the file
tracy.close();
}