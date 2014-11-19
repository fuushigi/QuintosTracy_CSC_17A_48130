//Tracy Quintos
//11/18/14
//17A Homework Gaddis7thEdChp14Prob14
#include <iostream>
#include "NumDays.h" //include header file NumDays

using namespace std;

int main()
{
    NumDays set1 = NumDays(); //setting hours to 0
    NumDays set2 = NumDays(8); //setting hours to 12/setting hours to 8
    NumDays set3 = NumDays(12);//setting hours to 12
    NumDays set4 = NumDays(18); //setting hours to 18
    NumDays set5 = NumDays(36);//setting hours to 36

    //displays the calculated work hours into days
    // for set 1-5
    cout << "Hours: " << set1.getHours() << endl; 
    cout << "Days: " << set1.getDays() << endl;
    cout << "------------\n";
    cout << "Hours: " << set2.getHours() << endl; 
    cout << "Days: " << set2.getDays() << endl;
    cout << "------------\n";
    cout << "Hours: " << set3.getHours() << endl; 
    cout << "Days: " << set3.getDays() << endl;
    cout << "------------\n";
    cout << "Hours: " << set4.getHours() << endl; 
    cout << "Days: " << set4.getDays() << endl;
    cout << "------------\n";
    cout << "Hours: " << set5.getHours() << endl; 
    cout << "Days: " << set5.getDays() << endl;
    cout << "------------\n";

    return 0;
}