//Program to print every color

#include<iostream>
#include<stdio.h> //for using printf
#include<windows.h>
using namespace std;

void color(int ForgC = 15, int BackC = 0){
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
               //Get the handle to the current output buffer...
 	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
 	SetConsoleTextAttribute(hStdOut, wColor);
}

int main(){
	cout<<"c(i,j) represents color(foreground,background)"<<endl<<endl;
	for(int i = 0;i <= 15;i++){
		for(int j = 0;j<=15;j++){
			color(i,j);
			printf(" c(%d,%d)",i,j);
		}
		cout<<endl;
	}
	color(); //Resets to default
	
	cout<<endl<<"Default"<<endl;
	
	return 0;
}
