//string to number
//using sstream function
#include<iostream>
#include<sstream>

using namespace std;

int main(){
	stringstream s;
	
	s << "12345";
	int num = 0;
	s >> num;
	cout<<num<<endl;

	s.clear(); //Must if you want to reuse the string stream

	s << "553007";
	s >> num;
	cout<<num<<endl;
		
	s.clear(); 

	s << "007";
	s >> num;
	cout<<num<<endl;
	
	s.clear(); 

	s << "-553";
	s >> num;
	cout<<num<<endl;		

	s.clear(); 

	s << "553.007"; //floating part will be discarded
	s >> num;
	cout<<num<<endl;
	
	s.clear(); 

	s << "7"; //does not work after floating point number
	s >> num;
	cout<<num<<endl;

	return 0;
}
