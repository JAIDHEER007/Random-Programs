//adding semicolon at the end of for loop

#include<iostream>
using namespace std;

int main(){
	int i;
	for(i=0;i<10;i++);	//For block is limited to this line
	
	cout<<i<<endl; //10
	
	return 0;
}
