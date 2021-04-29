//Printing address 

#include<iostream>
#include<sstream> //needed

using namespace std;

//Normally we can "print" address using cout stream but not work with it
//For directly working on pointer with string like easiness we have to code a bit

//using generic or void pointer instead of function overloading

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

//here we are using void pointer.
//It doesnot point to any data type
//So inorder to use it or dereference it, we have to type cast the pointer

//But in this use case, there is no need to type cast the pointer.

string inline to_string(void *address){
	stringstream ss;
	ss << address;		//similar to cin<<
	return ss.str();	//returns the string from the stream
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
	
	delete(test1);
	
	return 0;
}

