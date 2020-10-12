//Hackerrank HackFest 2020
//Game of maximization

#include<iostream>
#include<cmath>
using namespace std;

int main(){
	
	cout<<"Enter number of piles: ";
	int n; 
	cin>>n;
	int *arr = new int[n];
	
	cout<<"\nEnter number of stones in each pile:\n";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	int even_sum = 0, odd_sum = 0;
	
	for(int i=0,j=1; (i<n)||(j<n); i+=2,j+=2){
		even_sum += arr[j];
		odd_sum += arr[i];
	}

	int result = (even_sum + odd_sum) - abs(even_sum - odd_sum);
	
	cout<<"\nMaximum total number of stones which can be picked: "<<result;
	
	delete(arr);
	
	return 0;
}
