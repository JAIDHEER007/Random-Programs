#include<iostream>
using namespace std; 

string center(int width,string text){
	int len = text.length();
	if(width < len){ return text; }
	int diff = width - len; 
	int padding1 = diff/2;
	int padding2 = diff - padding1; 
	return string(padding1,' ') + text + string(padding2,' ');
}

int main(){
	cout<<string(44,'-')<<endl;
	cout<<"|"<<center(21,"Roll Number")<<"|"<<center(20,"Name")<<"|"<<endl;
	cout<<string(44,'-')<<endl;
	cout<<"|"<<center(21,"19A91A0502")<<"|"<<center(20,"B. YASWANTH")<<"|"<<endl;
	cout<<"|"<<center(21,"19A91A0507")<<"|"<<center(20,"K. KARTHIKEYA")<<"|"<<endl;
	cout<<"|"<<center(21,"19A91A0524")<<"|"<<center(20,"K. SIDDARTHA REDDY")<<"|"<<endl;
	cout<<"|"<<center(21,"19A91A0532")<<"|"<<center(20,"M. RAJKUMAR")<<"|"<<endl;
	cout<<"|"<<center(21,"19A91A0560")<<"|"<<center(20,"S. JAIDHEER")<<"|"<<endl;
	cout<<string(44,'-')<<endl<<endl;
	
	
	//Using to_string method for numeric to string convsion
	cout<<string(43,'-')<<endl;
	cout<<"|"<<center(20,"Name")<<"|"<<center(20,"Sem CGPA")<<"|"<<endl;
	cout<<string(43,'-')<<endl;
	cout<<"|"<<center(20,"B. YASWANTH")<<"|"<<center(20,to_string(9.23))<<"|"<<endl;
	cout<<"|"<<center(20,"K. KARTHIKEYA")<<"|"<<center(20,to_string(7.71))<<"|"<<endl;
	cout<<"|"<<center(20,"K. SIDDARTHA REDDY")<<"|"<<center(20,to_string(8.5))<<"|"<<endl;
	cout<<"|"<<center(20,"M. RAJKUMAR")<<"|"<<center(20,to_string(7.86))<<"|"<<endl;
	cout<<"|"<<center(20,"S. JAIDHEER")<<"|"<<center(20,to_string(8.5))<<"|"<<endl;
	cout<<string(43,'-')<<endl<<endl;
	return 0;
}
