/*
* File: testmain.cpp
* Author: Tracy Quintos
* Created on December 6, 2014
* Purpose: project 2 17A 48130
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include "MyFunctions.h" //header file that holds functins for normal game mode
#include "Mother1.h" //mother class holds functions that will be inherited by daughter1
#include "Daughter1.h" //derived class that will inherit from mother1

using namespace std;

Mother1::Mother1() {
}

//inputException 1-5 has exception handling for UserCHinput
void Mother1::inputException1() //challenger question 1 from mother1 class
{
    clsCH (5); // pseudo clear screen for challenger mode
    char userCHinput; //user challenger input
    try {
        cout << "\n##CHALLENGE 1##############################################\n";
        cout << "What is the capital of New Mexico ?\n";
        cout << "A. Miami\t\t\t C. New York City\n"; //choose answer A,B,C,D
        cout << "B. Santa Fe\t\t\t D. Jackson\n";
        cout << "###########################################################\n";
        cin >> userCHinput;
        
        if (toupper(userCHinput) != 'A' &&(userCHinput) != 'B' &&(userCHinput) != 'C'
                &&(userCHinput) != 'D' &&(userCHinput) != 'E')
            throw 99;
        }
    catch (int x)
    {
        cout << "INVALID ENTRY, Enter only A, B, C, D." << endl;
        inputException1(); //exception handling calls challenger question 1
    }
    if (toupper(userCHinput) == 'B') //if B is chosen Answer is correct
    {
        clsCH (30); //pseudo clear screen for challenger mode
        cout << "YOU ARE CORRECT!\n"; //msg that displays you are correct
        moneyPointCH(300000); //money point for challenger mode
        inputException2(); //calls challenger question 2
    }
    else //if answer is wrong player is not given a ARE YOU SURE function
        //game will end and go back to normal game menu
    {
        cout << "WRONG ANSWER! GAME OVER. THANKS FOR PLAYING!\n";
        cout <<"RETURNING TO NORMAL GAME MENU\n";
    }
}

void Mother1::inputException2() //exception handling for challenger question 2
{
    clsCH (5);
    char userCHinput; //user challenger input
    try {
        cout << "\n##CHALLENGE 2##############################################\n";
        cout << "How many Spartans were at the battle of Thermopylae ?\n";
        cout << "A. 300\t\t\t C. 200\n"; //choose answer A,B,C,D
        cout << "B. 500\t\t\t D. 700\n";
        cout << "###########################################################\n";
        cin >> userCHinput;
        
        if (toupper(userCHinput) != 'A' &&(userCHinput) != 'B' &&(userCHinput) != 'C'
                &&(userCHinput) != 'D')
            throw 99;
        }
    catch (int x)
    {
        cout << "INVALID ENTRY::Enter only A, B, C, D." << endl;
        inputException2(); 
    }
    
    if (toupper(userCHinput) == 'A')
    {
        clsCH (30);
        cout << "YOU ARE CORRECT!\n";
        moneyPointCH(400000);
        inputException3();
    }
    else
    {
        cout << "WRONG ANSWER! GAME OVER. THANKS FOR PLAYING!\n";
        cout <<"RETURNING TO NORMAL GAME MENU\n";
    }
}

void Mother1::inputException3() //exception handling for challenger question 3
{
    char userCHinput; //user challenger input
    try {
        cout << "\n##CHALLENGE 3##############################################\n";
        cout << "How many amendments are there in the US Constitution ?\n";
        cout << "A. 33\t\t\t C. 27\n"; //choose answer A,B,C,D
        cout << "B. 11\t\t\t D. 28\n";
        cout << "###########################################################\n";
        cin >> userCHinput;
        
        if (toupper(userCHinput) != 'A' &&(userCHinput) != 'B' &&(userCHinput) != 'C'
                &&(userCHinput) != 'D')
            throw 99;
        }
    catch (int x)
    {
        cout << "INVALID ENTRY::Enter only A, B, C, D." << endl;
        inputException3(); 
    }
    if (toupper(userCHinput) == 'C')
    {
        clsCH (30);
        cout << "YOU ARE CORRECT!\n";
        moneyPointCH(500000);
        inputException4();
    }
    else
    {
        cout << "WRONG ANSWER! GAME OVER. THANKS FOR PLAYING!\n";
        cout <<"RETURNING TO NORMAL GAME MENU\n";
    }
}

void Mother1::inputException4() //exception handling for challenger question 4
{
    char userCHinput; //user challenger input
    try {
        cout << "\n##CHALLENGE 4##############################################\n";
        cout << "What galaxy is the planet Earth residing in ?\n";
        cout << "A. Milky Way\t\t\t C. Cartwheel\n"; //choose answer A,B,C,D
        cout << "B. Andromeda\t\t\t D. Pinwheel\n";
        cout << "###########################################################\n";
        cin >> userCHinput;
        
        if (toupper(userCHinput) != 'A' &&(userCHinput) != 'B' &&(userCHinput) != 'C'
                &&(userCHinput) != 'D')
            throw 99;
        }
    catch (int x)
    {
        cout << "INVALID ENTRY::Enter only A, B, C, D." << endl;
        inputException4(); 
    }
    if (toupper(userCHinput) == 'A')
    {
        clsCH (30);
        cout << "YOU ARE CORRECT!\n";
        moneyPointCH(600000);
        inputException5();
    }
    else
    {
        cout << "WRONG ANSWER! GAME OVER. THANKS FOR PLAYING!\n";
        cout <<"RETURNING TO NORMAL GAME MENU\n";
    }
}

void Mother1::inputException5() //exception handling for challenger question 5
{
    char userCHinput; //user challenger input
    try {
        cout << "\n##CHALLENGE 5##############################################\n";
        cout << "When was instant coffe invented ?\n";
        cout << "A. 2003\t\t\t C. 1458\n"; //choose answer A,B,C,D
        cout << "B. 1901\t\t\t D. 1878\n";
        cout << "###########################################################\n";
        cin >> userCHinput;
        
        if (toupper(userCHinput) != 'A' &&(userCHinput) != 'B' &&(userCHinput) != 'C'
                &&(userCHinput) != 'D')
            throw 99;
        }
    catch (int x)
    {
        cout << "INVALID ENTRY::Enter only A, B, C, D." << endl;
        inputException5(); 
    }
    if (toupper(userCHinput) == 'B')
    {
        clsCH (30);
        cout << "YOU ARE CORRECT!\n";
        moneyPointCH(1500000);
        cout << "IF YOU HAVE NOT DONE SO, PLEASE CONTINUE TO NORMAL GAME MODE!\n";
        mainMenu();
    }
    else
    {
        cout << "WRONG ANSWER! GAME OVER. THANKS FOR PLAYING!\n";
        cout <<"RETURNING TO NORMAL GAME MENU\n";
    }
}

void Mother1::clsCH (int n) //psuedo clear screen function for challenger modeB
{
        for (int i = 1;i<n;i++) //n holds the variable to determine how many spaces are used
        {
        cout << endl; //cout<<endl;
        }
}

void Mother1::moneyPointCH(int value) //moneyPoint function used for every question answer wrong/correct
{
    int money = value; //int money holds the given value for the 15 questions
    cout << "\nYOU HAVE EARNED: $" << money << endl; //output for money earned
}