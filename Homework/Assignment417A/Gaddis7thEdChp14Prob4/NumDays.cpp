//Tracy Quintos
//11/18/14
//17A Homework Gaddis7thEdChp14Prob14
//HEADER FILE FOR Gaddis7thEdChp14Prob4
#ifndef NUMDAYS_H
#define NUMDAYS_H

using namespace std;

class NumDays //class NumDays
{
private:
    int workHours;
    int workDays;
public:
    // Constructors
    NumDays() //intializing work hours and work days to 0
    {
        workHours = 0;
        workDays = 0;
    }

    NumDays(int hours) //work hours = hours then hours is divided 8
    {
        workHours = hours;
        workDays = hours / 8;
    }

    // Accessors
    int getHours()
    { 
        return workHours; 
    }

    int getDays()
    { 
        return workDays; 
    }

    // Mutators
    void setHours(int hours)
    { 
        workHours = hours; 
    }

    void setDays(int days)
    { 
        workDays = days; 
    }

    // Overloaded Operators as instructed by gaddis book
    //overloaded operators +, ++, -, --
    int operator + (const NumDays &right)
    {
        return workHours + right.workHours;
    }
    int operator - (const NumDays &right)
    {
        return workHours - right.workHours;
    }
    NumDays operator ++ ()
    {
        ++workHours;
        workDays = workHours / 8;
        return *this;
    }
    NumDays operator ++ (int)
    {
        NumDays temp(workHours);
        workHours++;
        workDays = (workHours + 1) / 8;
        return temp;
    }
    NumDays operator -- ()
    {
        --workHours;
        workDays = workHours / 8;
        return *this;
    }
    NumDays operator -- (int)
    {
        NumDays temp(workHours);
        workHours--;
        workDays = (workHours - 1) / 8;
        return temp;
    }
};
#endif //end of header file