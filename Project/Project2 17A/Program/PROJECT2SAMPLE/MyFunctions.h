/*
* File: testmain.cpp
* Author: Tracy Quintos
* Created on December 6, 2014
* Purpose: project 2 17A 48130
*/

#ifndef MYFUNCTIONS_H
#define	MYFUNCTIONS_H
// header file to separate most of the functions from the main.cpp
//the following are function declarations that is used throughout the games

void bonusAb(); //bonus question function
bool areYouSure(); //is this your final answer function
void mainMenu(); //void function for main menu
void moneyPoint(int); //void function for moneypoint/money prize
void cls (int); //pseudo clear screen, int for spaces in between questions
int searchList(int [], int, int); //linear search for user ID #
void displayNumbers(int *Nbr[], int r, int c); //Pointers with arrays //displays the prize money structure

void mainCHMenu(); //challenger mode main menu function/ can be accessed by entering 6
void displayCHNumbers();//void displayCHNumbers(); using vector //displays the money prize in main menu
void phoneCHfriend(); //phone a friend function utilizes cstring to search contact for challenger mode

void initialize(); //initializes the player information
void input();  //function for player to input their information after bonus/or after Wrong answers   
void print(); //function to print player information at end game
void winlosefunction();//functions with structures
void winprint(); //functions with structures

//15 questions functions
void questionOne(); //void function for question 1
void questionTwo(); //void function for question 2
void questionThree(); //void function for question 3
void questionFour(); //void function for question 4
void questionFive(); //void function for question 5
void questionSix(); //void function for question 6
void questionSeven(); //void function for question 7
void questionEight(); //void function for question 8
void questionNine(); //void function for question 9
void questionTen(); //void function for question 10
void questionEleven(); //void function for question 11
void questionTwelve(); //void function for question 12
void questionThirteen(); //void function for question 13
void questionFourteen(); //void function for question 14
void questionFifteen(); //void function for question 15

//15 audience polls life-line
void question1Audpol(); //audience poll 1
void question1Audpo2(); //audience poll 2
void question1Audpo3(); //audience poll 3
void question1Audpo4(); //audience poll 4
void question1Audpo5(); //audience poll 5
void question1Audpo6(); //audience poll 6
void question1Audpo7(); //audience poll 7
void question1Audpo8(); //audience poll 8
void question1Audpo9(); //audience poll 9
void question1Audpo10(); //audience poll 10
void question1Audpol1(); //audience poll 11
void question1Audpol2(); //audience poll 12
void question1Audpol3(); //audience poll 13
void question1Audpol4(); //audience poll 14
void question1Audpol5(); //audience poll 15

#endif	/* MYFUNCTIONS_H */