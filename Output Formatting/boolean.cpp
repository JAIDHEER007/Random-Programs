//printing true or false for given boolean input

#include<iostream>
using namespace std;

string inline tf(bool tf){
	return (tf)?"true":"false";
}

int main(){
	//using helper function
	cout<<tf(2 == 3)<<endl;
	cout<<tf(7 == 7)<<endl<<endl;
	
	//without helper function
	cout<<boolalpha<<(2 == 3)<<endl;
	cout<<boolalpha<<(7 == 7)<<endl;
	
	return 0;
}
