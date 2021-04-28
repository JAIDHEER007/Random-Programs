//Printing address 

#include<iostream>
#include<sstream> //needed

using namespace std;

//Normally we can "print" address using cout stream but not work with it
//For directly working on pointer with string like easiness we have to code a bit

//Normal centering logic
string center(int width,string text){
	int len = text.length();
	if(width < len){ return text; }
	int diff = width - len; 
	int padding1 = diff/2;
	int padding2 = diff - padding1; 
	return string(padding1,' ') + text + string(padding2,' ');
}

class node{
	public:
		string test = "test";
};

string inline to_string(node *address){
	stringstream ss;
	ss << address;		//similar to cin<<
	return ss.str();	//returns the string from the stream
}

string inline to_string(int *address){
	stringstream ss;
	ss << address;
	return ss.str();
}

string inline to_string(float *address){
	stringstream ss;
	ss << address;
	return ss.str();
}

string inline to_string(string *address){
	stringstream ss;
	ss << address;	
	return ss.str();
}


int main(){
	node *test1 = new node();
	int test2 = 553;
	float test3 = 533.007; 
	string test4 = "test";
	
	cout<<string(44,'-')<<endl;
	cout<<"|"<<center(20,"node class")<<"||"<<center(20,to_string(test1))<<"|"<<endl;
	cout<<string(44,'-')<<endl;
	cout<<"|"<<center(20,"int variable")<<"||"<<center(20,to_string(&test2))<<"|"<<endl;
	cout<<string(44,'-')<<endl;
	cout<<"|"<<center(20,"float variable")<<"||"<<center(20,to_string(&test3))<<"|"<<endl;
	cout<<string(44,'-')<<endl;
	cout<<"|"<<center(20,"string variable")<<"||"<<center(20,to_string(&test4))<<"|"<<endl;
	cout<<string(44,'-')<<endl;
		
	return 0;
}

