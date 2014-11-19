//Tracy Quintos
//11/18/14
//17A Homework 4
//Library includes Here!!!
#include <iostream>
#include <string>
using namespace std;

//Global Constants Here!!!

//Function Prototypes Here!!!
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
//---------------Chp13Prob3------------
class Car //Chp13 Prob 3
{
private:
    int year; //holds year
    int speed; //holds speed
    string make; //string holds the make of the vehicle
public:
    Car(int, string, int);
    int getYear() const /* const added */
    {
        return year;
    }
    string getMake() const /* const added */
    {
        return make;
    }
    int getSpeed() const /* const added */
    {
        return speed;
    }

    void accelerate() ; // added
    void brake() ; //  added

};

//Car::Car(int yr, string mk)
Car::Car(int yr, string mk, int sp = 0 )
{
    year = yr; //year equals yr
    make = mk; //make equals mk
    speed = sp ; //speed=0;
}

void Car::accelerate()
{
    speed +=5; //as instructed by book, speed = speed + 5
}
void Car::brake()
{
    if( speed > 5 ) //added
        speed -=5;
    else speed = 0 ; // added
}
//----------------Chp13Prob3----------------------------------
//------------------Chp13Prob4---------------------------------
class PersonalInfo //Gaddis7thEdChp13Prob4
//class named personal info

{
private:
	string name; //string holds names
	string address; //string holds the addresses
	int age; //holds the ages
	string phonenumber; //holds the phone numbers

public:
        //functions contains arguments renamed to "new" function name
        //these functions are used and prompts the user to enter the information
        void setName(string newName); //function to set name
	void setAddress(string newAddress); //function holds the set address
	void setAge(int newAge); //function to set the age
	void setPhonenumber(int newPhonenumber); // function to set the phone numbers
	string getName(); //string for name
	string getAddress(); //string for address
	int getAge(); //holds the age
        string getPhonenumber(); //holds phone number
	void AskInfo(); //

};


	void PersonalInfo::setName(string newName) //accessor for name
	{
		name = newName; //set for new: name, age. address, phone number for user, friend and family member
	}

	void PersonalInfo::setAddress(string newAddress) //accessor for address
	{
		address = newAddress;
	}

	void PersonalInfo::setAge(int newAge) //accessor for age
	{
		age = newAge;
	}

	void PersonalInfo::setPhonenumber(int newPhonenumber) //mutator for new phone number
	{
		phonenumber = newPhonenumber;
	}

	string PersonalInfo::getName()  
	{
		return name;
	}

	string PersonalInfo::getAddress() 
	{
		return address;
	}

	int PersonalInfo::getAge()
	{
		return age;
	}
	
	string PersonalInfo::getPhonenumber()
	{
		return phonenumber;
	}

	void PersonalInfo::AskInfo()
	{
		cout << "Enter name: "; //msg displays for user to enter the names
		getline (cin, name);
               
		
		cout << "Enter address: "; //msg displays for user to enter the addresses
		getline (cin, address);
                
		
		cout << "Enter age: "; //msg displays for user to enter the ages
		cin >>age;
                
		
		cout << "Enter phonenumber: "; //msg displays for user to enter the phonenumbers
		cin >> phonenumber;
                cin.ignore(); //prevents "Enter name for the friends information
		
	}
//-----------------------Chp13Prob4----------------------------
//--------------------chp13Prob6-----------------------------        
        
class Inventory //Gaddis7thEdchp13Prob6
{
	private:
		int itemNumber; //holds item number
		int quantity; //holds quantity of item
		int cost; //holds the cost of the item
                int totalCost; //holds the total cost
	public:
		Inventory() //class inventory setting private members to zero
		{
			itemNumber = 0;
			quantity = 0;
			cost = 0;
			totalCost = 0;

		}
		Inventory(int newItemNumber, int newQuantity, int newCost)
                {
                  itemNumber = newItemNumber;
                  quantity = newQuantity;
                  cost = newCost;
                  setTotalCost(quantity, cost); // this can be called as quantity and cost have now been initialized.
                }

		void setItemNumber(int)
		{
			itemNumber = itemNumber;
		}
		void setQuantity(int)
		{
			quantity = quantity;
		}
		void setCost(int)
		{
			cost = cost;
		}
		void setTotalCost(int, int)
		{
			totalCost = quantity * cost;
		}

		int getItemNumber()
		{
			return itemNumber;
		}
		int getQuantity()
		{
			return quantity;
		}
		int getCost()
		{
			return cost;
		}
		int getTotalCost()
		{
			return totalCost;
		}
};
//---------------chp13Prob6--------------------
//--------------chp13Prob7---------------------
class Widget //Gaddis7thEdChp13Prob7
//class name Widget
{
private://member variables holds
    int now;
    int nod;
public:
//Mutator function for widgets
void setWidgets(int w)
{
if(w > 0)
{
now = w;
nod = now/160; //calculation for the hours shift for factory
}
else
cout<<"Invalid number of widgets" <<endl;
}

//function for widgets
int getWidgets()
{
return nod;
}
};
//--------------------chp13Prob7-------------------
//-------------------------chp14Prob10------------------
struct CorpData  //Gaddis7thEdChp14Prob10
{
    
	int Quarter[4]; // member Quarter holds array size of 4 (for the cardinal divisions)
        int total;  //member total holds the total of each division
        int average; // member average holds the average of each division total sales
        string Division; // member string holds the name of the divisions in array (stored in main)
    
	CorpData(string st) 
	{
        Division = st;
    }
    
	int setQ(int qtr, int f) 
	{
            if (f > 0) 
            {
                Quarter[qtr] = f;
                return 1;
            }
        return 0;
    }

	void getInfo(int qtr) 
	{
		int total=0.0; //setting total to 0.0

		for(int m = 0; m < 4; m++) 
		{//for loop for the calculation to add all of the quarterly earning for total and dividing for average
			total = total + Quarter[m];
			average = total / 4;
		}
		//displays the annual total and as well as the average
                cout << "Annual Total : " << total << endl;
		cout << "Annual Average : " << average << endl;
                cout << "-----------------------------------" << endl;
        }
       
};
//-----------------------chp14Prob10-------------------------
//--------------------Chp14Prob2-------------------------
class DayOfYear //Chp14Prob2
//class name is tracydayOfYear given by book //prob2Chp14
{
public:
	int tracyday; 
	string Month;

	
	DayOfYear(int tracydayInput)
	{
		tracyday = tracydayInput; //tracyday is set equal to tracydayInput
		
		 
	} 

	void print() //print function for if statements
	{
		
			if(tracyday >= 1 && tracyday <= 31) //number of tracydays for January
			{
				cout << "January " << tracyday << endl;
			}
	
			if(tracyday >= 32 && tracyday <= 59)
			{
				cout << "February " << (tracyday - 31) << endl;
			}

			if(tracyday >= 60 && tracyday <= 90)
			{
				cout << "March " << (tracyday - 59)  << endl;
			}

			if(tracyday >= 91 && tracyday <= 120)
			{
				cout << "April " << (tracyday - 90)  << endl;
			}

			if(tracyday >= 121 && tracyday <= 151)
			{
				cout << "May " << (tracyday - 120)  << endl;
			}

			if(tracyday >= 152 && tracyday <= 181)
			{
				cout << "June" << (tracyday - 151)  << endl;
			}

			if(tracyday >= 182 && tracyday <= 212)
			{
				cout << "July " << (tracyday - 181)  << endl;
			}

			if(tracyday >= 213 && tracyday <= 243)
			{
				cout << "August " << (tracyday - 212)  << endl;
			}

			if(tracyday >= 244 && tracyday <= 273)
			{
				cout << "September " << (tracyday - 243)  << endl;
			}

			if(tracyday >= 274 && tracyday <= 304)
			{
				cout << "October " << (tracyday - 273)  << endl;
			}

			if(tracyday >= 305 && tracyday <= 334)
			{
				cout << "November " << (tracyday - 304)  << endl;
                        }
			

			if(tracyday >= 335 && tracyday <= 365)
			{
				cout << "December " << (tracyday - 334)  << endl;
			}
		

	} // end print function

		
}; // end Class tracydayOfYear
//--------------------Chp14Prob2-------------------------

//------------------chp14Prob7----------------------------
//------------Chp14Prob7----------------
//Define a class called Month that represents a month of the year.
class Month //Chp14Prob7
{
    //data member of type int to represent a month
private:
    int month;
public:
    void inputMonth();
    void outputMonth();
    void inputMonths();
    Month(int );
    Month();
    int getMonth();
    Month nextMonth();
    
};

void Month::inputMonth() //An input function to input the month number.
    {
        do{
            cout <<endl <<"Please enter a number of month(1-12): ";
            cin>>month;
        }
        while(month<1 || month>12); //while month is less than 1 and is more than 12
    }
    void Month::outputMonth() //An output function to output the month as an integer.
    {
        cout <<"Month: "<<month;   //displays the month given by user 
    }
    //Another output function to output the month as the first three characters of the month's name.(e.g. Jan)
    void Month::inputMonths()
    {
        switch(month) //switch statement used for determining what number the user chooses, proper month is then displayed
        {
            case 1:    cout <<"JAN";break;
            case 2:    cout <<"FEB";break;
            case 3:    cout <<"MAR";break;
            case 4:    cout <<"APR";break;
            case 5:    cout <<"MAY";break;
            case 6:    cout <<"JUN";break;
            case 7:    cout <<"JUL";break;
            case 8:    cout <<"AUG";break;
            case 9:    cout <<"SEP";break;
            case 10:    cout <<"OCT";break;
            case 11:    cout <<"NOV";break;
            case 12:    cout <<"DEC";break;
        }
    }
    //A constructor that takes an integer to initialize the month number
    Month::Month(int m)
    {
        month=m;
    }
    //A default constructor
    Month::Month()
    {
        month=1;
    }
    //An accessor function to allow access to the month number
    int Month::getMonth()
    {
        return month;
    }
    //A member function the returns the next month as a value of type Month.
    //For example if the Month object is for April it would return a Month object for May.
    Month Month:: nextMonth()
    {
        Month next;
        if(month==12)next.month=1;
        else next.month=month+1;
        return next;
    }
    //------------------------------chp14Prob7--------------------------------
//Begin Execution Here!!!
int main(int argv,char *argc[]){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        case 7:    problem7();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=7);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"Menu Chp 13 + 14"<<endl;
    cout<<"Type 1 for Chp13Prob3"<<endl;
    cout<<"Type 2 for Chp13Prob4"<<endl;
    cout<<"Type 3 for Chp13Prob6"<<endl;
    cout<<"Type 4 for Chp13Prob7"<<endl;
    cout<<"Type 5 for Chp14Prob10"<<endl;
    cout<<"Type 6 for Chp14Prob2"<<endl;
    cout<<"Type 7 for Chp14Prob7"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1(){
     
        
        int yr; // holds year of vehicle
    string mk; //string holds make of vehicle
    cout << "Please enter model year and make:";
    // cin >> yr,mk;
    cin >> yr >> mk ; //user is asked to enter the year and make

    Car tracyCar(yr,mk);
    
    for(int i=0; i < 5; i++) //for loop to display the speed of the vehicle
    {
        tracyCar.accelerate();
        cout << "The Speed of my car is: " << tracyCar.getSpeed()<<endl;
        //for(int i=0, i<5, i++)
        for(int j=0 ; j<5 ; j++)
        {
            //tracyCar.Brake();
            tracyCar.brake();
            cout << "The speed of my car is " << tracyCar.getSpeed()<<endl;
        }
        
    }
        
}

void problem2(){
        
        PersonalInfo you; //user's personal information
		PersonalInfo your_friend; //frieds personal information
		PersonalInfo your_family_member; //family members person information

		cout << "Enter your information" << endl;
                cout << "-----------------------" << endl;
		you.AskInfo(); //function for user's information
                cout << "-----------------------" << endl;
		cout << "Enter your friends' information" << endl;
		your_friend.AskInfo(); //function for friend's information
                cout << "-----------------------" << endl;
		cout << "Enter your family members' information" << endl;
		your_family_member.AskInfo(); //function call for a family member's information
}

void problem3(){
        
        
        int itemNumber; //holds item number
	int quantity; //holds quantity
	int cost; //holds the cost
	int totalCost; //holds total cost of items

	cout << "Enter the Item Number: "; //user is asked for the item number
	cin >> itemNumber;
	
        while (itemNumber < 0) //while loop for validation cannot be less than 0
	{
		cout << "Please enter a positive value for the Item Number: ";
		cin >> itemNumber;
	}
	cout << "Enter the Quantity of the item: ";
	cin >> quantity;
	
        while (quantity < 0) //while loop for validation cannot be less than 0
	{
		cout << "Please enter a positive value for the Quantity of the item: ";
		cin >> quantity;
	}
	cout << "Enter the Cost of the item: ";
	cin >> cost;
	
        while (cost < 0) //while loop for validation cannot be less than 0
	{
		cout << "Please enter a positive value for the Cost of the item: ";
		cin >> cost;
	}

	Inventory information(itemNumber, quantity, cost);

	totalCost = information.getTotalCost();
	itemNumber = information.getItemNumber();
	cost = information.getCost();
	quantity = information.getQuantity();
        
        // displays the given information by user
        cout << "--------------------------------" << endl;
	cout << "The Item Number is: " << itemNumber << endl;
	cout << "The Quantity is: " << quantity << endl;
	cout << "The Cost is: " << cost << endl;
	cout << "The Total Cost is: " << totalCost << endl;
}

void problem4(){
  
        
Widget w;

int d;

cout<<"Please enter the number of widgets desired." <<endl;
cin>>d;

w.setWidgets(d);
//Calculating the number of days it takes for
// given widgets number
cout << "It takes the Quintos factory " << w.getWidgets() << " days to manufacture " << d << " widgets." <<endl;  
}

void problem5(){
      CorpData **Datapoint;
    Datapoint = new CorpData *[4];
    int num;
    
	string Division_name[4] = {"North","South","East","West"}; //cardinal division names given by book

    for (int i = 0; i < 4; i++) 
	{
        cout << endl;
       
		Datapoint[i] = new CorpData(Division_name[i]);
        
		for (int q = 0; q < 4; q++) 
		{
            do
			{
                //displays the respective division names and asks for the quarterly sales
                cout << "Division: "<< Datapoint[i]->Division << endl << "Enter sales for quarter: "<< q+1 << ": ";
                cin >> num; //holds the sales
            } 
            while (!Datapoint[i]->setQ(q,num));
        }  
    }cout << endl;

	for (int j = 0; j < 4; j++)
	{
		cout << Datapoint[j]->Division << endl;
		Datapoint[j]->getInfo(j); //calls getInfo function to display the sum and the average of all the earnings
	}


	cout << endl;
}

void problem6(){
        // choose a tracyday to display
	DayOfYear ttracyday(70);
	// print tracyday (int) in Month and tracyday format
        
        ttracyday.print();
}

void problem7(){
    
    //checking default constructor
    Month m;
    //displaying month
    cout <<"Month: "<<m.getMonth();
    //displaying name of month
    cout <<endl <<"Name: ";m.inputMonths();
    //increamenting month by one
    m= m.nextMonth();
    //displaying month again
    cout <<endl <<"After increament ";m.outputMonth();
    //displaying name of month again after incrementing
    cout <<endl <<"Name: ";m.inputMonths();

    //creating another object using paramerized constructor
    
    cout <<endl <<"EXAMPLE.";
    Month m2(m.getMonth()+3);
    //displaying month
    cout <<endl <<"Month: "<<m2.getMonth();
    //displaying name of month
    cout <<endl <<"Name: ";m2.inputMonths();

    //geting user input
    m2.inputMonth();
    //displaying month
    cout <<endl <<"Month: "<<m2.getMonth();
    //displaying name of month
    cout <<endl <<"Name: ";m2.inputMonths();
    

}


void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}