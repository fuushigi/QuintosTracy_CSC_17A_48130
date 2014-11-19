//Tracy Quintos
//11/18/14
//17A Homework Gaddis7thEdChp13Prob9
#include <iostream>
#include <cstdlib>
#include "Circle.h" //circle header
#include "ZeroException.h" //zero exception header
 
using namespace std;
 
             Circle::Circle()
             {
                  radius = 1.0;   
             }
              Circle::Circle(int radi)
             {
                 if( radi == 0 || radi == 0.0)
                 {
                     ZeroException ex;
                     ex.Checkradius(); 
                 }
                 else
                 {
                   radius = radi;  
                 }                   
               
             }
            
             
             void Circle::setRadius(int r)
             { 
              if( r == 0 || r == 0.0)
                 {
                     ZeroException ex;
                     ex.Checkradius(); 
                 }
                 else
                 {
                   radius = r;  
                 } 
             }
             
             int Circle::getRadius() //returns radius
             {
                return radius;   
             }
             
             int Circle::getArea() //returns area
             {
                return pi * radius * radius;
             }
             
             int Circle::getDiameter() //returns diameter
             {
                   return radius * 2;
             }
             
             int Circle::getCircumference() //returns the circumference
             {
                  return 2 * pi * radius;  
             }
             
             
             void  ZeroException::Checkradius() //throw 0.0 for radius
            {
                    throw 0.0;                   
            }