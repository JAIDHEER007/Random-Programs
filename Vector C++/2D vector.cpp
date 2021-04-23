#include<iostream>
#include<vector>

using namespace std;

typedef vector<vector<int>> vector_2d;

//Typing vector<vector<int>> everytime we initialize a 2d vector is cumbersome
//So we define vector<vector<int>> as new userdefined data type called vector_2d. 
//It has all the properties of vector<vector<int>>. 

vector_2d sum(vector_2d &arr1, vector_2d &arr2){
	vector_2d result;
	for(int i=0;i<arr1.size();i++){
		result.push_back(vector<int>());
		for(int j=0;j<arr1[i].size();j++)
			result[i].push_back(arr1[i][j] + arr2[i][j]);
	}
	return result;
}

int main(){
	
	vector<vector<int>> arr1
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	
	for(vector<int> row:arr1){
		for(int element:row)
			cout<<element<<" ";
		cout<<endl;
	}
	
	vector<vector<int>> arr2;
	cout<<"Enter a 3X3 array:"<<endl;
	for(int i=0;i<3;i++){
		arr2.push_back(vector<int>());
		for(int j=0;j<3;j++){
			int val; cin>>val;
			arr2[i].push_back(val);
		}
	}
	
	cout<<"Array 2"<<endl;
	for(int i=0;i<arr2.size();i++){
		for(int j=0;j<arr2[i].size();j++)
			cout<<arr2[i][j]<<" ";
		cout<<endl;
	}
	
	vector_2d result = sum(arr1,arr2);
	
	cout<<"Sum of two arrays"<<endl;
	for(vector<int> row:result){
		for(int element:row)
			cout<<element<<" ";
		cout<<endl;
	}
	
	return 0;
}
