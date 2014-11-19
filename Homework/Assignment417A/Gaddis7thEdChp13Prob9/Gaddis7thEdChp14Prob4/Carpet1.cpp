/* 
 * File:   Carpet1.cpp
 * Author: OWNER-PC
 * 
 * Created on November 18, 2014, 5:37 PM
 */

#include <stdio.h>
#include <iostream>
#include "Carpet.h"

using namespace std;

Carpet1::Carpet1() {
}

Carpet1::Carpet1(const Carpet1& orig) {
}

Carpet1::~Carpet1() {
}

void main()
{
Carpet c;

while (true)
{
& system("cls"); //clearing the console, for Windows only

& c.InputWidth();
& c.InputLength();
& c.InputPricePerSquareFoot();
& c.ShowPrice();

& cout << "\n\nDo you want to perform another calculations? (y/n): ";
& fflush(stdin);
& fflush(stdout);

& int a = toupper(getchar());
& if (a != 'Y')
& return;
}
} 
