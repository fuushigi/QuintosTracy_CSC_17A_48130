/*
* File: testmain.cpp
* Author: Tracy Quintos
* Created on December 6, 2014
* Purpose: project 2 17A 48130
*/
#include <iostream>
#include <fstream> //read and writing to a file.
#include <string>
#include <cstring>
#include <iomanip>
#include "MyFunctions.h" //header that holds functions for Main Game
#include "Mother1.h" //base class for challenger mode
#include "Daughter1.h" //derived class for challenger mode, inherits void Mother1::inputException1() question 1 for challenger

using namespace std;

//User Libraries
//Global Constant
//Function Prototype
//Execution starts here!
/*
*
*/

void mainMenu() //void main menu function
{
    //displays money point system in "case 5"
    //has 14 money awards, the 15th is written on void  DisplayNumbers** 
    int moneyP[2][7] = { { 100, 200, 300, 500, 1000, 2000, 4000 }, 
                         { 8000, 16000, 32000, 64000, 125000, 250000, 500000, } };
    int *pMoney[2];
    *pMoney = moneyP[0];

    for(int i = 0; i < 7; i++)
        (*pMoney)[i] = moneyP[0][i];

    *(pMoney+1) = moneyP[1];

    for(int i = 0; i < 7; i++)
        (*(pMoney+1))[i] = pMoney[1][i];

int choice; //holds the choices for menu
int number1; //holds choice 4 Phone number of friend life line
ofstream outputFile; //writes phone a friend life line phone number CASE 4
ifstream nameFile; //ifstream namefile to read the RULES.txt
string input; //string input, inputs the rules from txt onto console
cout << "******************************************\n"; //Opening title if void function main menu is opened
cout << "\t\t*WHO WANTS*\n";
cout << "\t\t *TO BE A*\n";
cout << "\t\t*MILLIONAIRE*\n";
cout << "******************************************\n";
cout << "1. START GAME \n"; //choice 1 allows player to start the game
cout<< "2. RULES \n"; //choice 2 opens the RULES.txt file onto console, rules can be read through here
cout << "3. QUIT GAME \n";//choice 3 quits the game
cout << "4. PHONE-A-FRIEND LIFE LINE \n";
cout << "5. PRIZE MONEY LIST \n";
cout << "6. CHALLENGE MODE \n";
cout << "PLEASE ENTER CHOICE: \t"; //cout msg for a menu choice

cin >> choice; //inputs choice
switch (choice) //switch statement which holds the choice inputs
{
    case 1: //case 1 or START GAME will automatically call question 1
    questionOne();
    break;
    case 2:
cout << "RULES PLACE HOLDER\n"; //case 2 for rules
nameFile.open("RULES.txt"); //opens file "RULES.txt"(will be placed in same destination as the cpp file
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
cout << "******************************************\n";
cout<<"YOU CHOOSE TO QUIT, HAVE A NICE DAY.\n";
    break;
    case 4:
outputFile.open("PHONENUM.txt");
cout << "******************************************\n";
cout << "Please enter a phone number:\n";
cin>>number1;// number1 holds the phone number entered by player, it is written into a file "PHONENUM.txt"
outputFile<<number1<<endl;
    break;
    case 5: //case 5 will print out the money points "pay out structure"
    cout << "******************************************\n";    
    cout << "**Payout Structure**" <<endl;
    displayNumbers(pMoney, 2, 7); //calls displayNumber function which has the money prize   
    break;
    case 6:
    mainCHMenu(); //challenge mode 
    break;
default:
cout<<"INVALID OPTION, TRY AGAIN\n"; //in the event the user enters in an invalid key for choice
} // an option to try again will be given
mainMenu();
}

// template function for questions/comments
void questionOne() //function for question 1
{
cls (30); //pseudo clear screen after every user input/ answer. 30 line gap
char userInput;//char user input is for the answer the user chooses for question 1
ifstream outputFile;
string input;
cout << "E. Phone A Friend.\t\tF. Audience Poll";
cout << "\n##QUESTION 1 #############################################\n"; //question 1 title
cout << "In what year was RCC established ?\n"; //question 1 display
cout << "A. 1916\t\t\t C. 1920\n"; //choose answer A,B,C,D
cout << "B. 1945\t\t\t D. 1975\n";
cout << "##########################################################\n";
cout << "YOUR ANSWER IS: \n";//user answer is:
cin >> userInput; //cin >> user's selected answer
//life line audience poll
if(toupper(userInput) == 'F')
{
    question1Audpol(); //entering F will call the question 1 audience poll for life line
    cout << "When finished with life-line, type 'n' and enter to return to question.\n";
}
//life line phone-a-friend
if(toupper(userInput) == 'E')
{
outputFile.open("PHONENUM.txt"); //opens file "RULES.txt"(will be placed in same destination as the cpp file
if (outputFile) //writting to file
{
getline(outputFile, input); //namefile, input phone number
while (outputFile)
    {
        cout << input <<endl;
        getline(outputFile,input); //getline gets the from the namefils it's input which holds the rules to the game
        cout << "When finished with life-line, type 'n' and enter to return to question.\n";
    }
        outputFile.close(); //file close after opening txt
}
    else //else statement if txt cannot be read
    {   
        cout<<"ERROR:cannot open file.\n"; //incase the file cannot be read this message will be shown
    }
}
// if user is sure?
if(areYouSure() == true) //if statement, IS THAT YOUR FINAL ANSWER? (yes/ no) function inside if
{
if(toupper(userInput) == 'A')//toupper allows user to use the lowercase or uppercase A/a
{ //if user inputs A/a they are correct
cls (30); // pseudo clear screen after the correct answer is given
cout << "YOU ARE CORRECT!\n"; // if right answer give moneyPoints(value)
moneyPoint(100); //answer question 1 correctly user gets $100
questionTwo(); // call next questionFunction() question 2
}
else //else statement for wrong answer
{ //cout WRONG ANSWER, GAME OVER, THANKS FOR PLAYING
cout << "WRONG ANSWER! GAME OVER. THANKS FOR PLAYING!\n";
moneyPoint(0);
winlosefunction();
winprint();// $0 will be given if answer is wrong
}
}
else
{
questionOne();//if areYouSure() == false question one will be called
}
}

void questionTwo() //function for question 2
{
    char userInput;//char user input is for the answer the user chooses for question 2
    ifstream outputFile;
    string input;
    cout << "E. Phone A Friend.\t\tF. Audience Poll";
    cout << "\n##QUESTION 2 #############################################\n"; //question 2 title
    cout << "What is the capital of Germany ?\n"; //question 2 display
    cout << "A. Beirut\t\t\t C. Buenos Aires\n"; //choose answer A,B,C,D
    cout << "B. Berlin\t\t\t D. Budapest\n";
    cout << "##########################################################\n";
    cout << "YOUR ANSWER IS: \n"; //user answer is:
    cin >> userInput; //cin >> user's selected answer
    if(toupper(userInput) == 'F')
{
    question1Audpo2();
    cout << "When finished with life-line, type 'n' and enter to return to question.\n";
}
//life line phone-a-friend
if(toupper(userInput) == 'E')
{
outputFile.open("PHONENUM.txt"); //opens file "RULES.txt"(will be placed in same destination as the cpp file
if (outputFile) //fstream to read from RULES.txt file
{
getline(outputFile, input); //namefile, input reads file
while (outputFile)
    {
        cout << input <<endl;
        getline(outputFile,input); //getline gets the from the namefils it's input which holds the rules to the game
        cout << "When finished with life-line, type 'n' and enter to return to question.\n";
    }
        outputFile.close(); //file close after opening txt
}
    else //else statement if txt cannot be read
    {   
        cout<<"ERROR:cannot open file.\n"; //incase the file cannot be read this message will be shown
    }
}
    // if user is sure?
    if(areYouSure() == true) //if statement, IS THAT YOUR FINAL ANSWER? (yes/ no) function inside if
    {
        if(toupper(userInput) == 'B')//toupper allows user to use the lowercase or uppercase B/b
        { //if user inputs B/b they are correct
            cls (30); // pseudo clear screen after the correct answer is given
            cout << "YOU ARE CORRECT!\n"; // if right answer give moneyPoints(value)
            moneyPoint(200); //answer question 2 correctly user gets $200
            questionThree(); // call next questionFunction() question 3
        }
        else //else statement for wrong answer
        { //cout WRONG ANSWER, GAME OVER, THANKS FOR PLAYING
            cout << "WRONG ANSWER! GAME OVER. THANKS FOR PLAYING!\n";
            moneyPoint(0); // $0 will be given if answer is wrong
            winlosefunction();
            winprint();
        }
            
    }
    else
    {
            questionTwo(); //if areYouSure() == false question two will be called
    }
}

void questionThree() //function for question 3
{
    char userInput; //char user input is for the answer the user chooses for question 3
    ifstream outputFile;
    string input;
    cout << "E. Phone A Friend.\t\tF. Audience Poll";
    cout << "\n##QUESTION 3 ####################################################\n"; //question 3 title
    cout << "Who was the 26th U.S. President ?\n"; //question 3 display
    cout << "A. Grover Cleveland\t\t\t C. Theodore Roosevelt\n"; //choose answer A,B,C,D
    cout << "B. William McKinley\t\t\t D. Harry Truman\n";
    cout << "#################################################################\n";
    cout << "YOUR ANSWER IS: \n"; //user answer is:
    cin >> userInput;//cin >> user's selected answer
    if(toupper(userInput) == 'F')
{
    question1Audpo3();
    cout << "When finished with life-line, type 'n' and enter to return to question.\n";
}
//life line phone-a-friend
if(toupper(userInput) == 'E')
{
outputFile.open("PHONENUM.txt"); //opens file "RULES.txt"(will be placed in same destination as the cpp file
if (outputFile) //fstream to read from RULES.txt file
{
getline(outputFile, input); //namefile, input reads file
while (outputFile)
    {
        cout << input <<endl;
        getline(outputFile,input); //getline gets the from the namefils it's input which holds the rules to the game
        cout << "When finished with life-line, type 'n' and enter to return to question.\n";
    }
        outputFile.close(); //file close after opening txt
}
    else //else statement if txt cannot be read
    {   
        cout<<"ERROR:cannot open file.\n"; //incase the file cannot be read this message will be shown
    }
}
  // if user is sure?
    if(areYouSure() == true) //if statement, IS THAT YOUR FINAL ANSWER? (yes/ no) function inside if
    {
        if(toupper(userInput) == 'C') //toupper allows user to use the lowercase or uppercase C/c
        {
            cls (30); // pseudo clear screen after the correct answer is given
            cout << "YOU ARE CORRECT!\n"; // if right answer give moneyPoints(value)
            moneyPoint(300); //answer question 3 correctly user gets $300
            questionFour(); //call next questionFunction() question 4
        }
        else //else statement for wrong answer
        { //cout WRONG ANSWER, GAME OVER, THANKS FOR PLAYING
            cout << "WRONG ANSWER! GAME OVER. THANKS FOR PLAYING!\n";
            moneyPoint(0); // $0 will be given if answer is wrong
            winlosefunction();
            winprint();
        }
            
    }
    else
    {
            questionThree(); //if areYouSure() == false question three will be called
    }
}

void questionFour() //function for question 4
{
    char userInput; //char user input is for the answer the user chooses for question 4
    ifstream outputFile;
    string input;
    cout << "E. Phone A Friend.\t\tF. Audience Poll";
    cout << "\n##QUESTION 4 #############################################\n"; //question 4 title
    cout << "What element in the periodic represents PO ?\n";  //question 4 display
    cout << "A. Polonium\t\t\t C. Cobalt\n"; //choose answer A,B,C,D
    cout << "B. Oxygen\t\t\t D. Radon\n";
    cout << "##########################################################\n";
    cout << "YOUR ANSWER IS: \n"; //user answer is:
    cin >> userInput; //cin >> user's selected answer
    if(toupper(userInput) == 'F')
{
    question1Audpo4();
    cout << "When finished with life-line, type 'n' and enter to return to question.\n";
}
//life line phone-a-friend
if(toupper(userInput) == 'E')
{
outputFile.open("PHONENUM.txt"); //opens file "RULES.txt"(will be placed in same destination as the cpp file
if (outputFile) //fstream to read from RULES.txt file
{
getline(outputFile, input); //namefile, input reads file
while (outputFile)
    {
        cout << input <<endl;
        getline(outputFile,input); //getline gets the from the namefils it's input which holds the rules to the game
        cout << "When finished with life-line, type 'n' and enter to return to question.\n";
    }
        outputFile.close(); //file close after opening txt
}
    else //else statement if txt cannot be read
    {   
        cout<<"ERROR:cannot open file.\n"; //incase the file cannot be read this message will be shown
    }
}
    // if user is sure?
    if(areYouSure() == true) //if statement, IS THAT YOUR FINAL ANSWER? (yes/ no) function inside if
    { //if user inputs A/a they are correct
        if(toupper(userInput) == 'A') //toupper allows user to use the lowercase or uppercase A/a
        {
            cls (30); // pseudo clear screen after the correct answer is given
            cout << "YOU ARE CORRECT!\n";
            moneyPoint(500); //answer question4 correctly user gets $500
            questionFive(); // call next questionFunction() question 5
        }
        else //else statement for wrong answer
        { //cout WRONG ANSWER, GAME OVER, THANKS FOR PLAYING
            cout << "WRONG ANSWER! GAME OVER. THANKS FOR PLAYING!\n";
            moneyPoint(0); // $0 will be given if answer is wrong
            winlosefunction();
            winprint();
        }
            
    }
    else
    {
            questionFour(); //if areYouSure() == false question four will be called
    }
}

void questionFive() //function for question 5
{
    char userInput; //char user input is for the answer the user chooses for question 5
    ifstream outputFile;
    string input;
    cout << "E. Phone A Friend.\t\tF. Audience Poll";
    cout << "\n##QUESTION 5 ##################################################\n"; //question 5 title
    cout << "What is the class code for the c++ 17A 11:10AM ?\n"; //question 5 display
    cout << "A. 47023\t\t\t C. 48130\n"; //choose answer A,B,C,D
    cout << "B. 92577\t\t\t D. 741808\n";
    cout << "###############################################################\n";
    cout << "YOUR ANSWER IS: \n"; //user answer is:
    cin >> userInput; //cin >> user's selected answer
    if(toupper(userInput) == 'F')
{
    question1Audpo5();
    cout << "When finished with life-line, type 'n' and enter to return to question.\n";
}
//life line phone-a-friend
if(toupper(userInput) == 'E')
{
outputFile.open("PHONENUM.txt"); //opens file "RULES.txt"(will be placed in same destination as the cpp file
if (outputFile) //fstream to read from RULES.txt file
{
getline(outputFile, input); //namefile, input reads file
while (outputFile)
    {
        cout << input <<endl;
        getline(outputFile,input); //getline gets the from the namefils it's input which holds the rules to the game
        cout << "When finished with life-line, type 'n' and enter to return to question.\n";
    }
        outputFile.close(); //file close after opening txt
}
    else //else statement if txt cannot be read
    {   
        cout<<"ERROR:cannot open file.\n"; //incase the file cannot be read this message will be shown
    }
}
  // if user is sure?
    if(areYouSure() == true) //if statement, IS THAT YOUR FINAL ANSWER? (yes/ no) function inside if
    {
        if(toupper(userInput) == 'C') //toupper allows user to use the lowercase or uppercase C/c
        { //if user inputs C/c they are correct
            cls (30); // pseudo clear screen after the correct answer is given
            cout << "YOU ARE CORRECT!\n"; // if right answer give moneyPoints(value)
            moneyPoint(1000); //answer question 5 correctly user gets $100
            questionSix(); // call next questionFunction() question 5
        }
        else //else statement for wrong answer
        { //cout WRONG ANSWER, GAME OVER, THANKS FOR PLAYING
            cout << "WRONG ANSWER! GAME OVER. THANKS FOR PLAYING!\n";
            moneyPoint(1000); // $1000 will be given if answer is wrong
            winlosefunction();
            winprint();
        }
            
    }
    else
    {
            questionFive(); //if areYouSure() == false question five will be called
    }
}

void questionSix() //function for question 6
{
    char userInput; //char user input is for the answer the user chooses for question 6
    ifstream outputFile;
    string input;
    cout << "E. Phone A Friend.\t\tF. Audience Poll";
    cout << "\n##QUESTION 6 ##################################################\n"; //question 6 title
    cout << "In what year was the first manned mission to land on the moon ?\n"; //question 6 display
    cout << "A. 1920\t\t\t C. 2011\n"; //choose answer A,B,C,D
    cout << "B. 1969\t\t\t D. 1972\n";
    cout << "###############################################################\n";
    cout << "YOUR ANSWER IS: \n"; //user answer is:
    cin >> userInput; //cin >> user's selected answer
    if(toupper(userInput) == 'F')
{
    question1Audpo6();
    cout << "When finished with life-line, type 'n' and enter to return to question.\n";
}
//life line phone-a-friend
if(toupper(userInput) == 'E')
{
outputFile.open("PHONENUM.txt"); //opens file "RULES.txt"(will be placed in same destination as the cpp file
if (outputFile) //fstream to read from RULES.txt file
{
getline(outputFile, input); //namefile, input reads file
while (outputFile)
    {
        cout << input <<endl;
        getline(outputFile,input); //getline gets the from the namefils it's input which holds the rules to the game
        cout << "When finished with life-line, type 'n' and enter to return to question.\n";
    }
        outputFile.close(); //file close after opening txt
}
    else //else statement if txt cannot be read
    {   
        cout<<"ERROR:cannot open file.\n"; //incase the file cannot be read this message will be shown
    }
}
    // if user is sure?
    if(areYouSure() == true) //if statement, IS THAT YOUR FINAL ANSWER? (yes/ no) function inside if
    {
        if(toupper(userInput) == 'B') //toupper allows user to use the lowercase or uppercase B/b
        {  //if user inputs B/b they are correct
            cls (30); // pseudo clear screen after the correct answer is given
            cout << "YOU ARE CORRECT!\n"; // if right answer give moneyPoints(value)
            moneyPoint(2000);  //answer question 6 correctly user gets $2000
            questionSeven(); // call next questionFunction() question 6
        }
        else //else statement for wrong answer
        {  //cout WRONG ANSWER, GAME OVER, THANKS FOR PLAYING
            cout << "WRONG ANSWER! GAME OVER. THANKS FOR PLAYING!\n";
            moneyPoint(1000);  // $1000 will be given if answer is wrong
            winlosefunction();
            winprint();
        }
            
    }
    else
    {
            questionSix(); //if areYouSure() == false question six will be called
    }
}

void questionSeven() //function for question 7
{
    char userInput;//char user input is for the answer the user chooses for question 7
    ifstream outputFile;
    string input;
    cout << "E. Phone A Friend.\t\tF. Audience Poll";
    cout << "\n##QUESTION 7 ##########################################################\n"; //question 7 title
    cout << "Other than 'Global Variables', what is the sure way to fail the class ?\n"; //question 7 display
    cout << "A. Using 'doubles'\t\t\t C. Using 'global constants' \n";//choose answer A,B,C,D
    cout << "B. Using 'shorts'\t\t\t D. Using 'do-while'\n";
    cout << "#######################################################################\n";
    cout << "YOUR ANSWER IS: \n"; //user answer is:
    cin >> userInput; //cin >> user's selected answer
    if(toupper(userInput) == 'F')
{
    question1Audpo7();
    cout << "When finished with life-line, type 'n' and enter to return to question.\n";
}
//life line phone-a-friend
if(toupper(userInput) == 'E')
{
outputFile.open("PHONENUM.txt"); //opens file "RULES.txt"(will be placed in same destination as the cpp file
if (outputFile) //fstream to read from RULES.txt file
{
getline(outputFile, input); //namefile, input reads file
while (outputFile)
    {
        cout << input <<endl;
        getline(outputFile,input); //getline gets the from the namefils it's input which holds the rules to the game
        cout << "When finished with life-line, type 'n' and enter to return to question.\n";
    }
        outputFile.close(); //file close after opening txt
}
    else //else statement if txt cannot be read
    {   
        cout<<"ERROR:cannot open file.\n"; //incase the file cannot be read this message will be shown
    }
}
    // if user is sure?
    if(areYouSure() == true) //if statement, IS THAT YOUR FINAL ANSWER? (yes/ no) function inside if
    {
        if(toupper(userInput) == 'A') //toupper allows user to use the lowercase or uppercase A/a
        { //if user inputs A/a they are correct
            cls (30); // pseudo clear screen after the correct answer is given
            cout << "YOU ARE CORRECT!\n"; // if right answer give moneyPoints(value)
            moneyPoint(4000); //answer question 7 correctly user gets $4000
            questionEight();  // call next questionFunction() question 8
        }
        else  //else statement for wrong answer
        { //cout WRONG ANSWER, GAME OVER, THANKS FOR PLAYING
            cout << "WRONG ANSWER! GAME OVER. THANKS FOR PLAYING!\n";
            moneyPoint(1000);  // $1000 will be given if answer is wrong
            winlosefunction();
            winprint();
        }
            
    }
    else
    {
            questionSeven(); //if areYouSure() == false question seven will be called
    }
}

void questionEight() //function for question 8
{
    char userInput; //char user input is for the answer the user chooses for question 8
    ifstream outputFile;
    string input;
    cout << "E. Phone A Friend.\t\tF. Audience Poll";
    cout << "\n##QUESTION 8 ############################################################\n"; //question 8 title
    cout << "How many pieces are in the game of chess per side ?\n"; //question 8 display
    cout << "A. 15\t\t\t C. 16\n"; //choose answer A,B,C,D
    cout << "B. 17\t\t\t D. 18\n";
    cout << "##########################################################################\n";
    cout << "YOUR ANSWER IS: \n"; //user answer is:
    cin >> userInput; //cin >> user's selected answer
    if(toupper(userInput) == 'F')
{
    question1Audpo8();
    cout << "When finished with life-line, type 'n' and enter to return to question.\n";
}
//life line phone-a-friend
if(toupper(userInput) == 'E')
{
outputFile.open("PHONENUM.txt"); //opens file "RULES.txt"(will be placed in same destination as the cpp file
if (outputFile) //fstream to read from RULES.txt file
{
getline(outputFile, input); //namefile, input reads file
while (outputFile)
    {
        cout << input <<endl;
        getline(outputFile,input); //getline gets the from the namefils it's input which holds the rules to the game
        cout << "When finished with life-line, type 'n' and enter to return to question.\n";
    }
        outputFile.close(); //file close after opening txt
}
    else //else statement if txt cannot be read
    {   
        cout<<"ERROR:cannot open file.\n"; //incase the file cannot be read this message will be shown
    }
}
    // if user is sure?
    if(areYouSure() == true) //if statement, IS THAT YOUR FINAL ANSWER? (yes/ no) function inside if
    {
        if(toupper(userInput) == 'C') //toupper allows user to use the lowercase or uppercase C/c
        { //if user inputs C/c they are correct
            cls (30); // pseudo clear screen after the correct answer is given
            cout << "YOU ARE CORRECT!\n";
            moneyPoint(8000); //answer question 8 correctly user gets $8000
            questionNine(); // call next questionFunction() question 8
        }
        else //else statement for wrong answer
        {   //cout WRONG ANSWER, GAME OVER, THANKS FOR PLAYING
            cout << "WRONG ANSWER! GAME OVER. THANKS FOR PLAYING!\n";
            moneyPoint(1000); // $1000 will be given if answer is wrong
            winlosefunction();
            winprint();
        }
            
    }
    else
    {
            questionEight(); //if areYouSure() == false question eight will be called
    }
}

void questionNine() //function for question 9
{
    char userInput; //char user input is for the answer the user chooses for question 9
    ifstream outputFile;
    string input;
    cout << "E. Phone A Friend.\t\tF. Audience Poll";
    cout << "\n##QUESTION 9 ############################################################\n"; //question 9 title
    cout << "As of 2012 what is the estimated world population ?\n"; //question 9 display
    cout << "A. 7 Billion\t\t\t C. 3 Billion\n"; //choose answer A,B,C,D
    cout << "B. 5 Billion\t\t\t D. 9 Billion\n";
    cout << "#########################################################################\n";
    cout << "YOUR ANSWER IS: \n"; //user answer is:
    cin >> userInput; //cin >> user's selected answer
    if(toupper(userInput) == 'F')
{
    question1Audpo9();
    cout << "When finished with life-line, type 'n' and enter to return to question.\n";
}
//life line phone-a-friend
if(toupper(userInput) == 'E')
{
outputFile.open("PHONENUM.txt"); //opens file "RULES.txt"(will be placed in same destination as the cpp file
if (outputFile) //fstream to read from RULES.txt file
{
getline(outputFile, input); //namefile, input reads file
while (outputFile)
    {
        cout << input <<endl;
        getline(outputFile,input); //getline gets the from the namefils it's input which holds the rules to the game
        cout << "When finished with life-line, type 'n' and enter to return to question.\n";
    }
        outputFile.close(); //file close after opening txt
}
    else //else statement if txt cannot be read
    {   
        cout<<"ERROR:cannot open file.\n"; //incase the file cannot be read this message will be shown
    }
}
    // if user is sure?
    if(areYouSure() == true)  //if statement, IS THAT YOUR FINAL ANSWER? (yes/ no) function inside if
    {
        if(toupper(userInput) == 'A') //toupper allows user to use the lowercase or uppercase A/a
        {  //if user inputs A/a they are correct
            cls (30); // pseudo clear screen after the correct answer is given
            cout << "YOU ARE CORRECT!\n";
            moneyPoint(16000); //answer question 9 correctly user gets $160000
            questionTen(); // call next questionFunction() question 10
        }
        else
        {
            cout << "WRONG ANSWER! GAME OVER. THANKS FOR PLAYING!\n";
            moneyPoint(1000); // $1000 will be given if answer is wrong
            winlosefunction();
            winprint();
        }
            
    }
    else
    {
            questionNine(); //if areYouSure() == false question nine will be called
    }
}

void questionTen() //function for question 10
{
    char userInput; //char user input is for the answer the user chooses for question 9
    ifstream outputFile;
    string input;
    cout << "E. Phone A Friend.\t\tF. Audience Poll";
    cout << "\n##QUESTION 10 ############################################################\n"; //question 10 title
    cout << "What is the 5th planet in our solar system ?\n"; //question 10 display
    cout << "A. Jupiter\t\t\t C. Neptune\n"; //choose answer A,B,C,D
    cout << "B. Mars\t\t\t\t D. Uranus\n";
    cout << "##########################################################################\n";
    cout << "YOUR ANSWER IS: \n"; //user answer is:
    cin >> userInput; //cin >> user's selected answer
    if(toupper(userInput) == 'F')
{
    question1Audpo10();
    cout << "When finished with life-line, type 'n' and enter to return to question.\n";
}
//life line phone-a-friend
if(toupper(userInput) == 'E')
{
outputFile.open("PHONENUM.txt"); //opens file "RULES.txt"(will be placed in same destination as the cpp file
if (outputFile) //fstream to read from RULES.txt file
{
getline(outputFile, input); //namefile, input reads file
while (outputFile)
    {
        cout << input <<endl;
        getline(outputFile,input); //getline gets the from the namefils it's input which holds the rules to the game
        cout << "When finished with life-line, type 'n' and enter to return to question.\n";
    }
        outputFile.close(); //file close after opening txt
}
    else //else statement if txt cannot be read
    {   
        cout<<"ERROR:cannot open file.\n"; //incase the file cannot be read this message will be shown
    }
}
    // if user is sure?
    if(areYouSure() == true)  //if statement, IS THAT YOUR FINAL ANSWER? (yes/ no) function inside if
    {
        if(toupper(userInput) == 'A') //toupper allows user to use the lowercase or uppercase A/a
        { //if user inputs A/a they are correct
            cls (30); // pseudo clear screen after the correct answer is given
            cout << "YOU ARE CORRECT!\n";
            moneyPoint(32000); //answer question 10 correctly user gets $320000
            questionEleven(); // call next questionFunction() question 11
        }
        else
        {
            cout << "WRONG ANSWER! GAME OVER. THANKS FOR PLAYING!\n";
            moneyPoint(1000); // $1000 will be given if answer is wrong
            winlosefunction();
            winprint();
        }
            
    }
    else
    {
            questionTen();  //if areYouSure() == false question ten will be called
    }
}

void questionEleven() //function for question 11
{
    char userInput; //char user input is for the answer the user chooses for question 11
    ifstream outputFile;
    string input;
    cout << "E. Phone A Friend.\t\tF. Audience Poll";
    cout << "\n##QUESTION 11 ############################################################\n"; //question 11 title
    cout << "What is the largest animal on earth ?\n"; //question 11 display
    cout << "A. Blue Whale\t\t\t C. Anaconda\n"; //choose answer A,B,C,D
    cout << "B. African Elephant\t\t D. Giraffe\n";
    cout << "##########################################################################\n";
    cout << "YOUR ANSWER IS: \n"; //user answer is:
    cin >> userInput; //cin >> user's selected answer
    if(toupper(userInput) == 'F')
{
    
    cout << "When finished with life-line, type 'n' and enter to return to question.\n";
}
//life line phone-a-friend
if(toupper(userInput) == 'E')
{
outputFile.open("PHONENUM.txt"); //opens file "RULES.txt"(will be placed in same destination as the cpp file
if (outputFile) //fstream to read from RULES.txt file
{
getline(outputFile, input); //namefile, input reads file
while (outputFile)
    {
        cout << input <<endl;
        getline(outputFile,input); //getline gets the from the namefils it's input which holds the rules to the game
        cout << "When finished with life-line, type 'n' and enter to return to question.\n";
    }
        outputFile.close(); //file close after opening txt
}
    else //else statement if txt cannot be read
    {   
        cout<<"ERROR:cannot open file.\n"; //incase the file cannot be read this message will be shown
    }
}
    // if user is sure?
    if(areYouSure() == true) //if statement, IS THAT YOUR FINAL ANSWER? (yes/ no) function inside if
    {
        if(toupper(userInput) == 'A')  //toupper allows user to use the lowercase or uppercase A/a
        { //if user inputs A/a they are correct
            cls (30); // pseudo clear screen after the correct answer is given
            cout << "YOU ARE CORRECT!\n";
            moneyPoint(64000); //answer question 11 correctly user gets $640000
            questionTwelve(); // call next questionFunction() question 12
        }
        else
        {
            cout << "WRONG ANSWER! GAME OVER. THANKS FOR PLAYING!\n";
            moneyPoint(32000); // $32000 will be given if answer is wrong
            winlosefunction();
            winprint();
        }
            
    }
    else
    {
            questionEleven(); //if areYouSure() == false question eleven will be called
    }
}

void questionTwelve() //function for question 12
{
    char userInput; //char user input is for the answer the user chooses for question 12
    ifstream outputFile;
    string input;
    cout << "E. Phone A Friend.\t\tF. Audience Poll";
    cout << "\n##QUESTION 12 ############################################################\n"; //question 12 title
    cout << "In what year did the United States adopt its independence ?\n"; //question 12 display
    cout << "A. 1976\t\t\t C. 1476\n"; //choose answer A,B,C,D
    cout << "B. 1776\t\t\t D. 1876\n";
    cout << "##########################################################################\n";
    cout << "YOUR ANSWER IS: \n";  //user answer is:
    cin >> userInput; //cin >> user's selected answer
    if(toupper(userInput) == 'F')
{
    
    cout << "When finished with life-line, type 'n' and enter to return to question.\n";
}
//life line phone-a-friend
if(toupper(userInput) == 'E')
{
outputFile.open("PHONENUM.txt"); //opens file "RULES.txt"(will be placed in same destination as the cpp file
if (outputFile) //fstream to read from RULES.txt file
{
getline(outputFile, input); //namefile, input reads file
while (outputFile)
    {
        cout << input <<endl;
        getline(outputFile,input); //getline gets the from the namefils it's input which holds the rules to the game
        cout << "When finished with life-line, type 'n' and enter to return to question.\n";
    }
        outputFile.close(); //file close after opening txt
}
    else //else statement if txt cannot be read
    {   
        cout<<"ERROR:cannot open file.\n"; //incase the file cannot be read this message will be shown
    }
}
    // if user is sure?
    if(areYouSure() == true) //if statement, IS THAT YOUR FINAL ANSWER? (yes/ no) function inside if
    { //if user inputs B/b they are correct
        if(toupper(userInput) == 'B') //toupper allows user to use the lowercase or uppercase B/b
        { //if user inputs B/b they are correct
            cls (30); // pseudo clear screen after the correct answer is given
            cout << "YOU ARE CORRECT!\n";
            moneyPoint(125000); //answer question 12 correctly user gets $125000
            questionThirteen(); // call next questionFunction() question 13
        }
        else
        {
            cout << "WRONG ANSWER! GAME OVER. THANKS FOR PLAYING!\n";
            moneyPoint(32000);  // $32000 will be given if answer is wrong
            winlosefunction();
            winprint();
        }
            
    }
    else
    {
            questionTwelve(); //if areYouSure() == false question twelve will be called
    }
}

void questionThirteen() //function for question 13
{
    char userInput; //char user input is for the answer the user chooses for question 13
    ifstream outputFile;
    string input;
    cout << "E. Phone A Friend.\t\tF. Audience Poll";
    cout << "\n##QUESTION 13 ############################################################\n"; //question 13 title
    cout << "What country today was ancient Babylonia ?\n"; //question 13 display
    cout << "A. Iran\t\t\t C. Iraq\n"; //choose answer A,B,C,D
    cout << "B. Istanbul\t\t D. Poland\n";
    cout << "##########################################################################\n";
    cout << "YOUR ANSWER IS: \n"; //user answer is:
    cin >> userInput; //cin >> user's selected answer
    if(toupper(userInput) == 'F')
{
    
    cout << "When finished with life-line, type 'n' and enter to return to question.\n";
}
//life line phone-a-friend
if(toupper(userInput) == 'E')
{
outputFile.open("PHONENUM.txt"); //opens file "RULES.txt"(will be placed in same destination as the cpp file
if (outputFile) //fstream to read from RULES.txt file
{
getline(outputFile, input); //namefile, input reads file
while (outputFile)
    {
        cout << input <<endl;
        getline(outputFile,input); //getline gets the from the namefils it's input which holds the rules to the game
        cout << "When finished with life-line, type 'n' and enter to return to question.\n";
    }
        outputFile.close(); //file close after opening txt
}
    else //else statement if txt cannot be read
    {   
        cout<<"ERROR:cannot open file.\n"; //incase the file cannot be read this message will be shown
    }
}
    // if user is sure?
    if(areYouSure() == true) //if statement, IS THAT YOUR FINAL ANSWER? (yes/ no) function inside if
    {
        if(toupper(userInput) == 'C') //toupper allows user to use the lowercase or uppercase C/c
        { //if user inputs C/c they are correct
            cls (30); // pseudo clear screen after the correct answer is given
            cout << "YOU ARE CORRECT!\n";
            moneyPoint(250000);  //answer question 12 correctly user gets $250000
            questionFourteen(); // call next questionFunction() question 14
        }
        else
        {
            cout << "WRONG ANSWER! GAME OVER. THANKS FOR PLAYING!\n";
            moneyPoint(32000); // $32000 will be given if answer is wrong
            winlosefunction();
            winprint();
        }
            
    }
    else
    {
            questionThirteen(); //if areYouSure() == false question thirteen will be called
    }
}

void questionFourteen() //function for question 14
{
    char userInput;  //char user input is for the answer the user chooses for question 14
    ifstream outputFile;
    string input;
    cout << "E. Phone A Friend.\t\tF. Audience Poll";
    cout << "\n##QUESTION 14 ############################################################\n"; //question 14 title
    cout << "How many seconds are in 2 minutes? ?\n"; //question 14 display
    cout << "A. 180 \t\t\t C. 120\n"; //choose answer A,B,C,D
    cout << "B. 450 \t\t\t D. 240\n";
    cout << "##########################################################################\n";
    cout << "YOUR ANSWER IS: \n"; //user answer is:
    cin >> userInput; //cin >> user's selected answer
    if(toupper(userInput) == 'F')
{
    
    cout << "When finished with life-line, type 'n' and enter to return to question.\n";
}
//life line phone-a-friend
if(toupper(userInput) == 'E')
{
outputFile.open("PHONENUM.txt"); //opens file "RULES.txt"(will be placed in same destination as the cpp file
if (outputFile) //fstream to read from RULES.txt file
{
getline(outputFile, input); //namefile, input reads file
while (outputFile)
    {
        cout << input <<endl;
        getline(outputFile,input); //getline gets the from the namefils it's input which holds the rules to the game
        cout << "When finished with life-line, type 'n' and enter to return to question.\n";
    }
        outputFile.close(); //file close after opening txt
}
    else //else statement if txt cannot be read
    {   
        cout<<"ERROR:cannot open file.\n"; //incase the file cannot be read this message will be shown
    }
}
    // if user is sure?
    if(areYouSure() == true) //if statement, IS THAT YOUR FINAL ANSWER? (yes/ no) function inside if
    {
        if(toupper(userInput) == 'C') //toupper allows user to use the lowercase or uppercase C/c
        {//if user inputs C/c they are correct
            cls (30); // pseudo clear screen after the correct answer is given
            cout << "YOU ARE CORRECT!\n";
            moneyPoint(500000); //answer question 12 correctly user gets $500000
            questionFifteen(); // call next questionFunction() question 15
        }
        else
        {
            cout << "WRONG ANSWER! GAME OVER. THANKS FOR PLAYING!\n";
            moneyPoint(32000); // $32000 will be given if answer is wrong
            winlosefunction();
            winprint();
        }
            
    }
    else
    {
            questionFourteen(); //if areYouSure() == false question fourteen will be called
    }
}

void questionFifteen() //function for question 15
{
    char userInput; //char user input is for the answer the user chooses for question 15
    ifstream outputFile;
    string input;
    cout << "E. Phone A Friend.\t\tF. Audience Poll";
    cout << "\n##QUESTION 15 ############################################################\n"; //question 15 title
    cout << "What is the boiling point of water ?\n"; //question 15 display
    cout << "A. 101 F\t\t\t C. 198 F\n"; //choose answer A,B,C,D
    cout << "B. 212 F\t\t\t D. 72 C\n";
    cout << "##########################################################################\n";
    cout << "YOUR ANSWER IS: \n"; //user answer is:
    cin >> userInput; //cin >> user's selected answer
    if(toupper(userInput) == 'F')
{
    
    cout << "When finished with life-line, type 'n' and enter to return to question.\n";
}
//life line phone-a-friend
if(toupper(userInput) == 'E')
{
outputFile.open("PHONENUM.txt"); //opens file "RULES.txt"(will be placed in same destination as the cpp file
if (outputFile) //fstream to read from RULES.txt file
{
getline(outputFile, input); //namefile, input reads file
while (outputFile)
    {
        cout << input <<endl;
        getline(outputFile,input); //getline gets the from the namefils it's input which holds the rules to the game
        cout << "When finished with life-line, type 'n' and enter to return to question.\n";
    }
        outputFile.close(); //file close after opening txt
}
    else //else statement if txt cannot be read
    {   
        cout<<"ERROR:cannot open file.\n"; //incase the file cannot be read this message will be shown
    }
}
    // if user is sure?
    if(areYouSure() == true) //if statement, IS THAT YOUR FINAL ANSWER? (yes/ no) function inside if
    {
        if(toupper(userInput) == 'B')  //toupper allows user to use the lowercase or uppercase B/b
        {
            cls (30); // pseudo clear screen after the correct answer is given
            cout << "YOU ARE CORRECT!\n";
            moneyPoint(1000000);  //answer question 12 correctly user gets $1000000
            //char bonusInput;
            cout << "WOULD YOU LIKE TO ENTER BONUS ROUND\n";
            //cin >> bonusInput;
            // if user is sure?
            if(areYouSure() == true) //if statement, IS THAT YOUR FINAL ANSWER? (yes/ no) function inside if
            {
                bonusAb(); //if true, bonusAb function is called and bonus round begins
            }
            else
            {
                cls (30); // pseudo clear screen after the correct answer is given
                cout << "NICE TRY, WE'LL DO IT ANYWAY! =)\n"; //trick question, either answer will still call bonusAb function
                bonusAb(); //bonusAb "bonus round" function
            }
           
        }
        
        else
        {
            cout << "WRONG ANSWER! GAME OVER. THANKS FOR PLAYING!\n";
            moneyPoint(32000); // $32000 will be given if answer is wrong 
            winlosefunction();
            winprint();
        }
    }
    else
    {
	       questionFifteen(); //if areYouSure() == false question fifteen will be called
    }
}

void bonusAb() //bonusAb function, utilizes 2D Array
{
    ofstream outputFile; //reads callsign.txt for validation
    outputFile.open("callsign.txt"); //outputs file to "callsign.txt"
    
    string mpaUserInput[2][5] = { //using 2D Array, 2 Rows, 5 Columns
{"ROW0 COL0","ROW0 COL1","ROW0 COL2","ROW0 COL3","ROW0 COL4"},
{"ROW1 COL0","ROW1 COL1","ROW1 COL2","ROW1 COL3","ROW1 COL4"}
};
    //mpa1+2 compensate for string 2D array on ^
string mpa1[5] = {"ALPHA", "BRAVO", "CHARLIE", "DELTA", "ECHO"};
string mpa2[5] = {"FOXTROT", "GOLF", "HOTEL", "INDIA", "JULIET"};

    cout << "\n##BONUS QUESTION ##########################################################\n"; // bonus question title
    cout << "WHAT IS THE FIRST TEN MILITARY PHONETIC ALPHABETS ?\n"; //bonus question
    cout << "##########################################################################\n";
    cout << "ENTER PHONETIC ABCDEFGHIJ: " << endl;//bonus question prompt
// CIN
for(int row = 0; row < 2; row++)
{

for(int col = 0; col < 5; col++)
{
cout << "LETTER #" << (col+1) <<": ";
cin >> mpaUserInput[row][col];
}
cout << endl;
}

//VALIDATING ROW 1
cout << "VALIDATING ROW 1: "<< endl;
for(int col = 0; col < 5; col++)
{
// for loop to caps all columns //validates length of any column in first row
//i.e. userinput has 4 char (alfa)
// if 0 < userinput ++ until reaches length of userinput (4 chars)
  for(int i = 0; i < mpaUserInput[0][col].length(); i++)
{
//the char of userinput will (=) become uppercase (ALFA)
(mpaUserInput[0][col])[i] = toupper((mpaUserInput[0][col])[i]);
}
// VALIDATION FOR ROW 1 (see mpa1 arrays)
//if userinput in row 0 any column is the same as mpa1 any column
//i.e. is ALFA the same as ALPHA? if yes, CORRECT else, WRONG
    if(mpaUserInput[0][col] == mpa1[col])
{
cout << "CORRECT!" << endl; //validates in column the correct MPA
}
        else
{
cout << "WRONG!!!" << endl; //validates in column the wrong MPA
}
}
cout << endl; //cout<<endl;

//VALIDATING ROW 2
cout << "VALIDATING ROW 2: "<< endl;
                                    for(int col = 0; col < 5; col++)
{
                                for(int i = 0; i < mpaUserInput[1][col].length(); i++)
{
                        (mpaUserInput[1][col])[i] = toupper((mpaUserInput[1][col])[i]);
}
// VALIDATION FOR ROW2 (see mpa2 arrays)
                   if(mpaUserInput[1][col] == mpa2[col])
{
    cout << "CORRECT!" << endl;
}
            else
{
    cout << "WRONG!!!" << endl;
}
}
    cout << endl;

// show initial value AFTER cin
for(int row = 0; row < 2; row++)
{
    for(int col = 0; col < 5; col++)
{
cout << mpaUserInput[row][col] << endl;
outputFile << mpaUserInput[row][col] << "\r\n";
    }
    cout << endl;
    outputFile << "\r\n";
    }
    cout<<"###THANKS FOR PLAYING!###"<<endl;
    winlosefunction();
    winprint();
}
//**********************************************************************************
//**********************************************************************************
// Revalidate Question
bool areYouSure() //areYouSure function= called for every question
{
    char rysChar; //char holds the (Y/n) reply
    cout << "IS THAT YOUR FINAL ANSWER?(Y/n): ";// function msg
    cin >> rysChar; //user's input  (Y/n)
    
    if(toupper(rysChar) == 'Y') //toupper rysChar can either be Y/y
    {
        //test for return: comment out cout
        //cout << "return true\n";
        return true;
    }
    else
    {
        
        return false; //returns false
    }
}

void moneyPoint(int value) //moneyPoint function used for every question answer wrong/correct
{
    int money = value; //int money holds the given value for the 15 questions
    cout << "\nYOU HAVE EARNED: $" << money << endl; //output for money earned
}

void cls (int n) //psuedo clear screen function
{
        for (int i = 1;i<n;i++) //n holds the variable to determine how many spaces are used
        {
        cout << endl; //cout<<endl;
        }
}

//constant integer variable setting array size 2, corresponds to the ID #s for linear search
int searchList(int list[], int numElems, int value)
{
int index = 0; //subscript to search array
int position = -1; //record position of search value
bool found = false; // boolean to indicate if the value was found, found is set to false

while (index < numElems && !found)
{
    if (list[index] == value) // If the value is found
{
        found = true; // Set the flag
                position = index; // Record the value's subscript
}
                    index++; // Go to the next element
}
return position; // Return the position, or -1
}

void displayNumbers(int *nbr[], int rows, int columns) //Pointers with arrays 
//displays the money point "pay out structure" case: 5 in Menu function
{

    for(int i = 0; i < rows; i++)

        for(int j = 0; j < columns; j++)

            cout << "Money Point: $" << (*(nbr+i))[j] <<endl;
            cout << "Money Point: $1000000" <<endl;
}

struct poll1 //structure to create a audience poll for question 1

{
        int A; //A-D holds the % for audience poll "life line"
        int B;
        int C;
        int D;

}question1poll; //questionpoll object

struct poll2 //structure to create a audience poll for question 2

{
        int A; //A-D holds the % for audience poll "life line"
        int B;
        int C;
        int D;

}question2poll; //questionpoll object

struct poll3 //structure to create a audience poll for question 3

{
        int A; //A-D holds the % for audience poll "life line"
        int B;
        int C;
        int D;

}question3poll; //questionpoll object

struct poll4 //structure to create a audience poll for question 4

{
        int A; //A-D holds the % for audience poll "life line"
        int B;
        int C;
        int D;

}question4poll; //questionpoll object

struct poll5 //structure to create a audience poll for question 5

{
        int A; //A-D holds the % for audience poll "life line"
        int B;
        int C;
        int D;

}question5poll; //questionpoll object

struct poll6 //structure to create a audience poll for question 6

{
        int A; //A-D holds the % for audience poll "life line"
        int B;
        int C;
        int D;

}question6poll; //questionpoll object

struct poll7 //structure to create a audience poll for question 7

{
        int A; //A-D holds the % for audience poll "life line"
        int B;
        int C;
        int D;

}question7poll; //questionpoll object

struct poll8 //structure to create a audience poll for question 8

{
        int A; //A-D holds the % for audience poll "life line"
        int B;
        int C;
        int D;

}question8poll; //questionpoll object

struct poll9 //structure to create a audience poll for question 9

{
        int A; //A-D holds the % for audience poll "life line"
        int B;
        int C;
        int D;

}question9poll; //questionpoll object

struct poll10 //structure to create a audience poll for question 10

{
        int A; //A-D holds the % for audience poll "life line"
        int B;
        int C;
        int D;

}question10poll; //questionpoll object

struct poll11 //structure to create a audience poll for question 11

{
        int A; //A-D holds the % for audience poll "life line"
        int B;
        int C;
        int D;

}question11poll; //questionpoll object

struct poll12 //structure to create a audience poll for question 12

{
        int A; //A-D holds the % for audience poll "life line"
        int B;
        int C;
        int D;

}question12poll; //questionpoll object

struct poll13 //structure to create a audience poll for question 13

{
        int A; //A-D holds the % for audience poll "life line"
        int B;
        int C;
        int D;

}question13poll; //questionpoll object

struct poll14 //structure to create a audience poll for question 14

{
        int A; //A-D holds the % for audience poll "life line"
        int B;
        int C;
        int D;

}question14poll; //questionpoll object

struct poll15 //structure to create a audience poll for question 15

{
        int A; //A-D holds the % for audience poll "life line"
        int B;
        int C;
        int D;

}question15poll; //questionpoll object


void question1Audpol() //created an object to produce an audience poll life-line
{
    
        question1poll.A = 50; //answer A is likely the answer
        question1poll.B = 15; //answer B is 15%
        question1poll.C = 30; //answer C is 30%
        question1poll.D = 5; //answer 5 is 5%

        cout << "##########################################################\n";
	cout << "Audience Poll\n";
	cout << "A: " << question1poll.A << "%" << "\t\t\tC: " << question1poll.C << "%" << endl;
        cout << "B: " << question1poll.B << "%" << "\t\t\tD: " << question1poll.D << "%" << endl;
        cout << "##########################################################\n";
}

void question1Audpo2() //created an object to produce an audience poll life-line
{
    
        question2poll.A = 17; //answer A is 17%
        question2poll.B = 60; //answer B is likely the answer
        question2poll.C = 13; //answer C is 30%
        question2poll.D = 10; //answer D is 5%

	cout << "##########################################################\n";
	cout << "Audience Poll\n";
        cout << "A: " << question2poll.A << "%" << "\t\t\tC: " << question2poll.C << "%" << endl;
        cout << "B: " << question2poll.B << "%" << "\t\t\tD: " << question2poll.D << "%" << endl;
        cout << "##########################################################\n";
}

void question1Audpo3() //created an object to produce an audience poll life-line
{
    
        question3poll.A = 11; //answer A is 11%
        question3poll.B = 14; //answer B is 14%
        question3poll.C = 66; //answer C is likely the answer
        question3poll.D = 9; //answer D is 9%

	cout << "##########################################################\n";
	cout << "Audience Poll\n";
        cout << "A: " << question3poll.A << "%" << "\t\t\tC: " << question3poll.C << "%" << endl;
        cout << "B: " << question3poll.B << "%" << "\t\t\tD: " << question3poll.D << "%" << endl;
        cout << "##########################################################\n";
}

void question1Audpo4() //created an object to produce an audience poll life-line
{
    
        question4poll.A = 45; //answer A is likely the answer
        question4poll.B = 20; //answer B is 20%
        question4poll.C = 17; //answer C is 17%
        question4poll.D = 18; //answer D is 18%

	cout << "##########################################################\n";
	cout << "Audience Poll\n";
        cout << "A: " << question4poll.A << "%" << "\t\t\tC: " << question4poll.C << "%" << endl;
        cout << "B: " << question4poll.B << "%" << "\t\t\tD: " << question4poll.D << "%" << endl;
        cout << "##########################################################\n";
}

void question1Audpo5() //created an object to produce an audience poll life-line
{
    
        question5poll.A = 16; //answer A is 
        question5poll.B = 23; //answer B is 20%
        question5poll.C = 49; //answer C is likely the answer
        question5poll.D = 12; //answer D is 18%

	cout << "##########################################################\n";
	cout << "Audience Poll\n";
        cout << "A: " << question5poll.A << "%" << "\t\t\tC: " << question5poll.C << "%" << endl;
        cout << "B: " << question5poll.B << "%" << "\t\t\tD: " << question5poll.D << "%" << endl;
        cout << "##########################################################\n";
}

void question1Audpo6() //created an object to produce an audience poll life-line
{
    
        question6poll.A = 5; //answer A is 5%
        question6poll.B = 78; //answer B is likely the answer
        question6poll.C = 9; //answer C is 9%
        question6poll.D = 8; //answer D is 8%

	cout << "##########################################################\n";
	cout << "Audience Poll\n";
        cout << "A: " << question6poll.A << "%" << "\t\t\tC: " << question6poll.C << "%" << endl;
        cout << "B: " << question6poll.B << "%" << "\t\t\tD: " << question6poll.D << "%" << endl;
        cout << "##########################################################\n";
}

void question1Audpo7() //created an object to produce an audience poll life-line
{
    
        question7poll.A = 67; //answer A is likely the answer
        question7poll.B = 12; //answer B is 12%
        question7poll.C = 6; //answer C is 6%
        question7poll.D = 15; //answer D is 15%

	cout << "##########################################################\n";
	cout << "Audience Poll\n";
        cout << "A: " << question7poll.A << "%" << "\t\t\tC: " << question7poll.C << "%" << endl;
        cout << "B: " << question7poll.B << "%" << "\t\t\tD: " << question7poll.D << "%" << endl;
        cout << "##########################################################\n";
}

void question1Audpo8() //created an object to produce an audience poll life-line
{
    
        question8poll.A = 10; //answer A is 10%
        question8poll.B = 12; //answer B is 12%
        question8poll.C = 55; //answer C is is likely the answer
        question8poll.D = 23; //answer D is 23%

	cout << "##########################################################\n";
	cout << "Audience Poll\n";
        cout << "A: " << question8poll.A << "%" << "\t\t\tC: " << question8poll.C << "%" << endl;
        cout << "B: " << question8poll.B << "%" << "\t\t\tD: " << question8poll.D << "%" << endl;
        cout << "##########################################################\n";
}

void question1Audpo9() //created an object to produce an audience poll life-line
{
    
        question9poll.A = 72; //answer A is is likely the answer
        question9poll.B = 10; //answer B is 10%
        question9poll.C = 6; //answer C is 6%
        question9poll.D = 12; //answer D is 12%

	cout << "##########################################################\n";
	cout << "Audience Poll\n";
        cout << "A: " << question9poll.A << "%" << "\t\t\tC: " << question9poll.C << "%" << endl;
        cout << "B: " << question9poll.B << "%" << "\t\t\tD: " << question9poll.D << "%" << endl;
        cout << "##########################################################\n";
}

void question1Audpo10() //created an object to produce an audience poll life-line
{
    
        question10poll.A = 90; //answer A is is likely the answer
        question10poll.B = 3; //answer B is 3%
        question10poll.C = 6; //answer C is 6%
        question10poll.D = 1; //answer D is 1%

	cout << "##########################################################\n";
	cout << "Audience Poll\n";
        cout << "A: " << question10poll.A << "%" << "\t\t\tC: " << question10poll.C << "%" << endl;
        cout << "B: " << question10poll.B << "%" << "\t\t\tD: " << question10poll.D << "%" << endl;
        cout << "##########################################################\n";
}

void question1Audpol1() //created an object to produce an audience poll life-line
{
    
        question11poll.A = 65; //answer A is is likely the answer
        question11poll.B = 3; //answer B is 3%
        question11poll.C = 26; //answer C is 26%
        question11poll.D = 6; //answer D is 1%

	cout << "##########################################################\n";
	cout << "Audience Poll\n";
        cout << "A: " << question11poll.A << "%" << "\t\t\tC: " << question11poll.C << "%" << endl;
        cout << "B: " << question11poll.B << "%" << "\t\t\tD: " << question11poll.D << "%" << endl;
        cout << "##########################################################\n";
}

void question1Audpol2() //created an object to produce an audience poll life-line
{
    
        question12poll.A = 15; //answer A is 15%
        question12poll.B = 49; //answer B is is likely the answer
        question12poll.C = 20; //answer C is 20%
        question12poll.D = 16; //answer D is 16%

	cout << "##########################################################\n";
	cout << "Audience Poll\n";
        cout << "A: " << question12poll.A << "%" << "\t\t\tC: " << question12poll.C << "%" << endl;
        cout << "B: " << question12poll.B << "%" << "\t\t\tD: " << question12poll.D << "%" << endl;
        cout << "##########################################################\n";
}

void question1Audpol3() //created an object to produce an audience poll life-line
{
    
        question13poll.A = 4; //answer A is  4%
        question13poll.B = 3; //answer B is 3%
        question13poll.C = 88; //answer C is likely the answer
        question13poll.D = 5; //answer D is 5%

	cout << "##########################################################\n";
	cout << "Audience Poll\n";
        cout << "A: " << question13poll.A << "%" << "\t\t\tC: " << question13poll.C << "%" << endl;
        cout << "B: " << question13poll.B << "%" << "\t\t\tD: " << question13poll.D << "%" << endl;
        cout << "##########################################################\n";
}

void question1Audpol4() //created an object to produce an audience poll life-line
{
    
        question14poll.A = 14; //answer A is  14%
        question14poll.B = 13; //answer B is 13%
        question14poll.C = 63; //answer C is likely the answer
        question14poll.D = 10; //answer D is 10%

	cout << "##########################################################\n";
	cout << "Audience Poll\n";
        cout << "A: " << question14poll.A << "%" << "\t\t\tC: " << question14poll.C << "%" << endl;
        cout << "B: " << question14poll.B << "%" << "\t\t\tD: " << question14poll.D << "%" << endl;
        cout << "##########################################################\n";
}

void question1Audpol5() //created an object to produce an audience poll life-line
{
    
        question15poll.A = 2; //answer A is  2%
        question15poll.B = 92; //answer B is likely the answer
        question15poll.C = 4; //answer C is 4%
        question15poll.D = 2; //answer D is 2%

	cout << "##########################################################\n";
	cout << "Audience Poll\n";
        cout << "A: " << question15poll.A << "%" << "\t\t\tC: " << question15poll.C << "%" << endl;
        cout << "B: " << question15poll.B << "%" << "\t\t\tD: " << question15poll.D << "%" << endl;
        cout << "##########################################################\n";
}