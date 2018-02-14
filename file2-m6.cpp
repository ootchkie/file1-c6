//four includes
#include <iomanip>   
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//class declaration
class payroll{
	ifstream fin;
	//all variables and funtion proto-types    
	char id[5], i;
	int hw, oth;
	float hr, tax;
	double gp, otp, reg;    
	double net, avg, sum;
	void printheadings();
	void myPays();
    void myTax();
	void myTable();
	//changed
	void myNet();
public: payroll();
~payroll();
	void printreport();//new
};

//class call  --run program
payroll::payroll(){	
fin.open("file.dat");  }//CONSTRUCTOR
payroll::~payroll(){
fin.close();  }//DESTRUCTOR  --end of program

//class function calls:
//main
int main(){
	payroll employee;
	employee.printreport();	    
return 0;
}//MAIN

//input
void payroll::printreport(){	
 	//int i = 0;
	printheadings();//myData();//myAverage();//
	//while(fin>>employeename>>employeeid>>maritalstatus>>hoursworked>>hourlyrate){
    while(fin>>id>>hw>>hr){
		myPays();//calculategrosspay();//
        myTax();//calculatetax();//
        myTable();//printdata();//
        i++;  }//WHILE
    myNet();    
}//PRINTREPORT  --to main

//visuals
void payroll::printheadings(){	
 	cout<<setw(45)        <<"-PAYROLL REPORT-"<<endl;
cout<<"------------------------------------------------------------------------------"<<endl;
  cout <<"SSID  HOURS  RATE   OTH   OTP     REG     GROSS   TAX     NET"<<endl;	   
cout<<"------------------------------------------------------------------------------"<<endl;     
}//PRINTHEADINGS

//logics
void payroll::myPays(){
	if (hw > 40){//logic for overtime hours
         oth = hw - 40;
         otp = oth*(hr* 1.5);//++time and a half overtime pay
         reg = hr*40;//compute reg pay
    }//IF
    //compute regpay
    else oth = 0, otp=0, reg= hw*hr;
    //grosspay
	gp = reg + otp;
}//MYPAYS
void payroll::myTax(){
	if (gp>1000){//logic for taxrates
                                tax=.03;
                        }
                
    else if (gp>800){
                                tax=.02;
                        }               
    else if (gp>500){  
                                tax=.01;
                        }
    else tax=.00;
    
	net=(gp-(gp*tax));//compute tax
	sum = sum + net;//compound netsum
}//MYTAX
               
//data output
void payroll::/***printdata(){	
 	cout<<setprecision(2)<<setiosflags(ios::fixed | ios::showpoint);
 	cout<<setw(6)<<employeename<<setw(12)<<employeeid<<setw(4)
 	<<hoursworked<<setw(3)<<overtime<<setw(8)<<regularpay<<setw(8)
 	<<overtimepay<<setw(8)<<grosspay<<setw(8)<<taxamount<<setw(8)
 	<<netpay<<endl;   }//PRINTDATA***/myTable(){	
    //for ( int i = 0; i<n; i++){ //tabular loop for ++output data arrays
               cout<<setprecision(2)<<setiosflags(ios::fixed | ios::showpoint);
            //    int wid = 22;// total column width of name
           //    cout<<  right  <<fname;//right helps with namespace 
			   cout<< id;    
                // differenc + length = total width ||  d=w-l  
          //      int dif =((wid)-((fname[i].length())+(lname[i].length())));//makes columns print evenly
          //      cout<<setw(4)<<id <<"  " ;//left helps with numeber spacing
                
                cout<<setw(6) <<right  << hw;
                cout<<setw(8) << hr;
                cout<<setw(4)  << oth;
                cout<<setw(8)  << otp;
                cout<<setw(8)  << reg;
                cout<<setw(8)  << gp;
                cout<<setw(8)   <<tax;
                cout<<setw(9)  <<net;
                cout << endl <<endl;
}//MYTABLE
        
void payroll::myNet(){
  double avg; 
  avg = sum / i;
  cout<<endl << "NET AVERAGE IS.. "<<avg <<endl;//print net avg  
}//MYNET
