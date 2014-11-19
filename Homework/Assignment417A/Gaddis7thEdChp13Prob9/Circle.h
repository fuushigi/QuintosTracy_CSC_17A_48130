//Tracy Quintos
//11/18/14
//17A Homework Gaddis7thEdChp13Prob9
#ifndef CIRCLEH
#define CIRCLEH
 
#include <iostream>
#include <cstdlib>
 
using namespace std;
 
class Circle
{
      public:
             Circle();
             
             Circle(int radi);
             
             void setRadius(int r);
             
             int getRadius();
             
             int getArea();
             
             int getDiameter();
             
             int getCircumference();
             
             
      private:
              int radius;
             static const  int pi = 3.14159;     
};
 
#endif