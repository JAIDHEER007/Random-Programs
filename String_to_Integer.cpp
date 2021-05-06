//string to number
//using stoi function
#include<iostream>

using namespace std;

int main(){
	cout<<stoi("12345")<<endl;
	cout<<stoi("553007")<<endl;
	cout<<stoi("553.007")<<endl; //floating part will be discarded
	cout<<stoi("-553")<<endl;
		
	return 0;
}
