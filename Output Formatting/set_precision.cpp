//Setting precision for a floating point number

#include<iostream>
#include<iomanip> //Required for the job

using namespace std;

int main(){
	double pi = 3.1415926;
	
	cout<<pi<<endl;					//3.14159
	cout<<fixed<<setprecision(1)<<pi<<endl;		//3.1
	cout<<fixed<<setprecision(2)<<pi<<endl;		//3.14
	cout<<fixed<<setprecision(3)<<pi<<endl;		//3.142
	cout<<fixed<<setprecision(4)<<pi<<endl;		//3.1416
	cout<<fixed<<setprecision(5)<<pi<<endl;		//3.14159
	cout<<fixed<<setprecision(6)<<pi<<endl;		//3.141593
	cout<<fixed<<setprecision(7)<<pi<<endl;		//3.1415926
	
	cout<<fixed<<setprecision(8)<<pi<<endl;		//3.14159260
	cout<<fixed<<setprecision(9)<<pi<<endl;		//3.141592600
	cout<<fixed<<setprecision(10)<<pi<<endl;	//3.1415926000
	cout<<fixed<<setprecision(11)<<pi<<endl;	//3.14159260000
	cout<<fixed<<setprecision(0)<<pi<<endl;		//3
	
	cout<<fixed<<setprecision(1)<<553<<endl;	//553	
	cout<<fixed<<setprecision(2)<<553<<endl;	//533	
	cout<<fixed<<setprecision(3)<<553<<endl;	//533
	
	return 0;
}
