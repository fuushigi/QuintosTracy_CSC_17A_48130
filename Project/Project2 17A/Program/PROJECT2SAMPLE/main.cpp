/*
* File: testmain.cpp
* Author: Tracy Quintos
* Created on December 6, 2014
* Purpose: project 2 17A 48130
*/
#include <iostream>
#include <cstdlib>
#include <vector> //challenge mode pay out list
#include <cstring> //case 5 "phone a friend"
#include <fstream> //reading for file Challenger mode rules
#include "MyFunctions.h" //header that holds functions for Main Game
#include "Mother1.h" //base class for challenger mode
#include "Daughter1.h" //derived class for challenger mode, inherits void Mother1::inputException1() question 1, and other functions
using namespace std;

//User Libraries
//Global Constant
//Function Prototype
//Execution starts here!
/*
*
*/
struct player //function with structure 
    //structure for gathering player information after when GAME OVER
{
    char firstName[20]; //holds first name
    char lastName[20]; //holds last name
    char address[20]; //address info
    char addresso[20]; //address info
    char addressp[10]; //address info
    char occupation[20]; //holds occupation
    int age; //holds age
    int finalScore; //holds final money point received
};

int main(int argc, char** argv)
{ //

const int arraySize = 2; //size of the array that holds how many ID #s there are
int tests[arraySize] = {2123629, 2152573}; //array to hold ID #s
int accountN = 0; //holds the account numbers
int results = 0; //holds what # the account is in the element(inside array))

cout << "*Welcome to 17A Project 2 Fall2014*" << endl;
cout << "   Please enter a valid ID #" << endl; //Asks user to input their ID number
cin >> accountN; //variable for ID #
results = searchList(tests, arraySize, accountN); //linear search result
if (results == -1)//if result(ID number) is -1 (false) cout msg will show
    {
        cout << "SORRY, INVALID ENTRY, PLEASE TRY AGAIN.\n"; 
    }//if user ID is not valid this message will show, user has to try again.
else // else the user will be brought to the main menu to begin game, see rules, or quit.
{
mainMenu();//main menu function
}
//Exit stage right
return 0;
}

void mainCHMenu() //void main challenge mode menu function
{
    Daughter1 teri; //derived daughter class 'teri'
    
    //displays money point system in "case 5" 1 D array
    //has 5 money awards, each question is worth $300k -grand total $1.5
    int moneyP[1][5] = { 300000, 300000, 300000, 300000, 300000};
    int *pMoney[2];
    *pMoney = moneyP[0];

int choice; //holds the choices for menu
int number1; //holds choice 4 Phone number of friend life line
ofstream outputFile; //writes phone a friend life line phone number CASE 4
ifstream nameFile; //ifstream namefile to read the RULES.txt
string input; //string input, inputs the rules from txt onto console
cout << "******************************************\n"; //Opening title if void function main menu is opened
cout << "\t\t*WHO WANTS*\n";
cout << "\t\t *TO BE A*\n";
cout << "\t\t*MILLIONAIRE*\n";
cout << "\t\t*CHALLANGE MODE*\n";
cout << "******************************************\n";
cout << "1. START GAME \n"; //choice 1 allows player to start the game
cout << "2. RULES \n"; //choice 2 opens the RULES.txt file onto console, rules can be read through here
cout << "3. QUIT CHALLANGE MODE \n";//choice 3 quits the game
cout << "4. PRIZE MONEY LIST \n"; //choice 4 display money prize
cout << "5. PHONE-A-FRIEND CHALLENGE MODE \n";
cout << "PLEASE ENTER CHOICE: \t"; //cout msg for a menu choice
cin >> choice; //inputs choice
switch (choice) //switch statement which holds the choice inputs
{
    case 1: //case 1 or START GAME will automatically call question 1
    teri.inputException1(); //challenger mode question 1 being called as a derived class 'teri' inheriting from mother1
    break;
    case 2:
    cout << "RULES PLACE HOLDER\n"; //case 2 for rules
    nameFile.open("RULES2.txt"); //opens file "RULES.txt"(will be placed in same destination as the cpp file
    if (nameFile) //fstream to read from RULES.txt file
    {
    getline(nameFile, input); //namefile, input reads file
    while (nameFile)
    {
        cout<<input<<endl;
        getline(nameFile,input); //getline gets the from the namefils it's input which holds the rules to the game
    }
            nameFile.close(); //file close after opening txt
}
else //else statement if txt cannot be read
{
cout<<"ERROR:cannot open file.\n"; //incase the file cannot be read this message will be shown
}
    break;
    case 3: //case 3 will cout a message that you have quit the game
    cout << "***************************************************\n";
    cout<<"YOU CHOOSE TO QUIT CHALLENGE MODE, HAVE A NICE DAY.\n";
     cout << "***************************************************\n";
    mainMenu();
    break;
    case 4: //case 5 will print out the money points "pay out structure"
    cout << "******************************************\n";    
    cout << "**Challenge Mode Payout Structure**" <<endl;
    displayCHNumbers(); 
    mainCHMenu();
    break;
    case 5:
    phoneCHfriend();    
    break;
default:
cout<<"INVALID OPTION, RETURNING TO NORMAL GAME MENU \n"; //in the event the user enters in an invalid key for choice
} // an option to try again will be given
mainMenu();
}

void displayCHNumbers() //stl vector 
//displays the money point "pay out structure" for challenge mode
{
    vector<int> tracyVector;
    
    tracyVector.push_back(300000); //push_back money prizes questions 1-5
    tracyVector.push_back(400000);
    tracyVector.push_back(500000);
    tracyVector.push_back(600000);
    tracyVector.push_back(1500000);
        
        for (unsigned int i = 0; i < tracyVector.size(); i++) //for loop to display the vector
        {
            cout <<"Money Point: " << "$" << tracyVector[i] << "  \n";
        }
            
}

void phoneCHfriend() //phone a friend life line utilizing cstring, CHALLENGE user must memorize contact number in order to use life-line
{
    cin.ignore(); //when case 5 in challenger mode menu is chosen, this allows for user to input
    const int NUM_PHONES = 5; // 5 contacts
    const int LENGTH = 30; //length of each char is set to 30
    
    char contacts[NUM_PHONES][LENGTH] = //given information for player to use, SEE CHALLENGE MODE RULES
        {"TQ Tracy Quintos 9514439475",
         "ML Mark Lehr 9518527417",
         "KW Kelly Wingate 9517479632",
         "GW George Wreckts 9513261457",
         "KP Kenny Phung 9518547145" };
    
    char lookUp[LENGTH];
    char *strPtr = NULL;
    int index;
    
    cout << "Enter the initials of a contact: ";
    cin.getline(lookUp, LENGTH);
    
    for (index = 0; index < NUM_PHONES; index++)
    {
        strPtr = strstr(contacts[index], lookUp);
        if (strPtr != NULL)
            break;
    }
        if (strPtr != NULL)
        {
            cout << contacts[index] << endl;
            mainCHMenu();  //after contact info is given main challenger menu will display
        }
        else
            cout << "No matching contact was found.\n"; //msg will display if contact given is not found
}

void initialize(player s[]) //initializing structure "player" function
{                          // information gathering
        int i = 0;
        
        s[i].firstName; //first name of player
        s[i].lastName; //last name of player
        s[i].address; //first part of address i.e. 123 ect.
        s[i].addresso;//second part of address i.e. "Maple" ect
        s[i].addressp; // street type i.e. court, bld, way  ect
        s[i].occupation; //occupation of player
        s[i].age; //age of player
        s[i].finalScore; //final score of game
    
}

void input(player s[]) //function to input structure "player" information
{                     //displays the prompts player to input asked information
        int i = 0;
        cout << "Please enter your first (space) last name: \n"; 
        cin >> s[i].firstName >> s[i].lastName;
        cout << "Please your enter address: (125 Appleton rd.) \n"; 
        cin >> s[i].address >> s[i].addresso >> s[i].addressp;
        cout << "Please enter occupation: \n";
        cin >> s[i].occupation;
        cout << "Please enter your age: \n"; 
        cin >> s[i].age;
        cout << "Please enter your final score: \n";
        cin >> s[i].finalScore;
        
}

void print(player s[]) //Functions with structures function print
{
        int i = 0;
        cout << "#################################################" <<endl;
        cout << "##THANKS FOR PLAYING! MONEY WILL BE SENT TO:## \n";
        cout << "Contestant: " << s[i].firstName << " " << s[i].lastName <<endl;
        cout << "Address: " << s[i].address << " " << s[i].addresso << " " << s[i].addressp <<endl;
        cout << "Occupation: " << s[i].occupation <<endl;
        cout << "Age: " << s[i].age << " years old \n";
        cout << "Final Score: " << s[i].finalScore <<endl;
        cout << "################################################# \n" <<endl;
    
}

void winlosefunction() //function that calls functions with structures //initialize and input functions
{
    player info[1];
    initialize (info);
    input (info);
}

void winprint() //function that calls functions with structures //print function
{
     player info[1];
     initialize (info);
     print (info);
}