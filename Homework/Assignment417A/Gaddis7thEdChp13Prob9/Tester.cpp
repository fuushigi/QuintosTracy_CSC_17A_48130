//Tracy Quintos
//11/18/14
//17A Homework Gaddis7thEdChp13Prob9
//Library includes Here!!!
#include <cstdlib>
#include <iostream>
#include "Circle.h" //circle header file
 
using namespace std;
 
int main(int argc, char *argv[])
{
    
           for(;;)
           {
            try
             {
               int radius;
               cout<<"Enter the radius: ";
               cin>>radius;  
              Circle cir(radius);
              cout<<"Radius: " << cir.getRadius() <<endl;
              cout<<"Area: " << cir.getArea() <<endl;
              cout<<"Diameter: " << cir.getDiameter() <<endl;
              cout<<"Circumference: " <<cir.getCircumference() <<endl;
              break;      
              } 
              catch(int e)
              {
                    cout<<"The radius cannot be 0.0"<<endl<<endl;
                    continue; 
              } 
              }
   
    
   
    return 0;
}