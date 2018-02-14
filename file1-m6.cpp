#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class employee{
//declarations
int N; // Number of employees to enter		
bool ask;// Inquiry value
ofstream fout;
public:
 void askdata();
public:
 employee();
~employee();
};//CLASS
	
int main(){
	employee worker;
	worker.askdata();
return 0;	
}//MAIN

employee::employee(){
	fout.open("file.out");
}//CONSTRUCTOR

employee::~employee(){
	fout.close();
}//DESTRUCTOR

void employee::askdata(){
	cout << "Please Enter number of Employees:";//ask this once
	cin >> N;// Number of employees to enter to be used for loop
	int i = 0;//initialize loop
	char ssid[5];
	float hrate;
	double hw;

	while(N > i){
	//instance for loop
		cout << "Salaried(s) or Hourly(h), answer s or h"<<endl;
		char c;
		cin >> c;
		int x = int{c};//integer promotion
    
		if(x==115){
			ask=false;
		}	
		if(x==104){
			ask=true;
		}//ifs
		
		if(ask==0){
			cout << "last four SS#:";
			cin >> ssid;
			fout <<ssid <<"  ";
			cout << "Enter yearly Salary:";		
			double salary, base;
			cin >> salary;
			base = salary/52;
			hrate = base/40;
			cout <<"base Rate = " <<base <<"/week -> "<< hrate<<"/hour" <<'\n';
			fout <<setprecision(2)<<setiosflags(ios::fixed | ios::showpoint)<< hrate << "   ";//printf
			cout <<"Hours Worked:";
			cin >>hw;
			if(hw<40){
			   hw=40;
			}//hw=40 ->for salaried employees always
			fout << hw << '\n';//printf
		
		}//ask is zero(0)		
		if(ask==1){
				cout << "last four SS#:";
				cin >> ssid;
			fout << ssid << "  ";//printf
				cout << "Hours worked:";
				cin >> hw;	
			fout << hw << "   ";//printf	
			  cout << "Hourly rate:";
		    cin >> hrate;		
			fout <<setprecision(2)<<setiosflags(ios::fixed | ios::showpoint)<< hrate << '\n';//printf
		}//ask is one(1)
	i++;
   }//loop
}//INQUIRY

