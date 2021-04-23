//Vector with a custom object
//Sorting the vector based on the attributes of the object

#include<iostream>
#include<vector>		//vector
#include<algorithm>		//sort
#include <ctime>		//time()

using namespace std;

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
		int a;
		int b;
		string txt;
		
		node(){
			a = (rand() * time(NULL)) % 1001;	//returns the current calendar time (seconds since Jan 1, 1970)
			b = (rand() * time(NULL)) % 1001;
			txt = randomAlphaNumeric(); 
		}
		
		string static randomAlphaNumeric(){
			string rand_an = "";
			static const string alphanum = "bX9LhB6yJskUvlTAM1HNpDweQgaWOznf7P0SCo4cIR2d3qmGYtZV58FuEKjxri";
			for(int i=0;i<10;i++)
				rand_an += alphanum[(rand() * time(NULL)) % 62];
			
			return rand_an; 
		}
		
		bool static inline comp_a_ascending(node &n1, node &n2){
			return n1.a < n2.a; 
		}
		bool static inline comp_a_descending(node &n1, node &n2){
			return n1.a > n2.a; 
		}
		bool static inline comp_b_ascending(node &n1, node &n2){
			return n1.b < n2.b; 
		}
		bool static inline comp_b_descending(node &n1, node &n2){
			return n1.b > n2.b; 
		}
		bool static inline comp_txt_ascending(node &n1, node &n2){
			return n1.txt < n2.txt; 
		}
		bool static inline comp_txt_descending(node &n1, node &n2){
			return n1.txt > n2.txt; 
		}
		
		
};

int main(){
	vector<node> arr(10);
	
	for(int i=0;i<15;i++)
		arr.push_back(node());
	
	{ //Printing Raw Data
		cout<<string(33,'-')<<endl;
		cout<<"|"<<center(31,"RAW DATA")<<"|"<<endl;
		cout<<string(33,'-')<<endl;
		cout<<"|"<<center(7,"a")<<"|"<<center(7,"b")<<"|"<<center(15,"text")<<"|"<<endl;	
		cout<<string(33,'-')<<endl;
		for(node n:arr)
			cout<<"|"<<center(7,to_string(n.a))<<"|"<<center(7,to_string(n.b))<<"|"<<center(15,n.txt)<<"|"<<endl;
		cout<<string(33,'-')<<endl;
	}
	
	sort(arr.begin(),arr.end(),node::comp_a_ascending);
	
	{ //Sorted based on a attribute. Ascending order.
		cout<<string(33,'-')<<endl;
		cout<<"|"<<center(31,"Sorted based on >a< attribute")<<"|"<<endl;
		cout<<string(33,'-')<<endl;
		cout<<"|"<<center(31,"ASCENDING ORDER")<<"|"<<endl;
		cout<<string(33,'-')<<endl;
		cout<<"|"<<center(7,"a")<<"|"<<center(7,"b")<<"|"<<center(15,"text")<<"|"<<endl;	
		cout<<string(33,'-')<<endl;
		for(node n:arr)
			cout<<"|"<<center(7,to_string(n.a))<<"|"<<center(7,to_string(n.b))<<"|"<<center(15,n.txt)<<"|"<<endl;
		cout<<string(33,'-')<<endl;
	}
	
	sort(arr.begin(),arr.end(),node::comp_a_descending);
	
	{ //Sorted based on a attribute. Descending order.
		cout<<string(33,'-')<<endl;
		cout<<"|"<<center(31,"Sorted based on >a< attribute")<<"|"<<endl;
		cout<<string(33,'-')<<endl;
		cout<<"|"<<center(31,"DESCENDING ORDER")<<"|"<<endl;
		cout<<string(33,'-')<<endl;
		cout<<"|"<<center(7,"a")<<"|"<<center(7,"b")<<"|"<<center(15,"text")<<"|"<<endl;	
		cout<<string(33,'-')<<endl;
		for(node n:arr)
			cout<<"|"<<center(7,to_string(n.a))<<"|"<<center(7,to_string(n.b))<<"|"<<center(15,n.txt)<<"|"<<endl;
		cout<<string(33,'-')<<endl;
	}
	
	sort(arr.begin(),arr.end(),node::comp_b_ascending);
	
	{ //Sorted based on b attribute. Ascending order.
		cout<<string(33,'-')<<endl;
		cout<<"|"<<center(31,"Sorted based on >b< attribute")<<"|"<<endl;
		cout<<string(33,'-')<<endl;
		cout<<"|"<<center(31,"ASCENDING ORDER")<<"|"<<endl;
		cout<<string(33,'-')<<endl;
		cout<<"|"<<center(7,"a")<<"|"<<center(7,"b")<<"|"<<center(15,"text")<<"|"<<endl;	
		cout<<string(33,'-')<<endl;
		for(node n:arr)
			cout<<"|"<<center(7,to_string(n.a))<<"|"<<center(7,to_string(n.b))<<"|"<<center(15,n.txt)<<"|"<<endl;
		cout<<string(33,'-')<<endl;
	}
	
	sort(arr.begin(),arr.end(),node::comp_b_descending);
	
	{ //Sorted based on b attribute. Descending order.
		cout<<string(33,'-')<<endl;
		cout<<"|"<<center(31,"Sorted based on >b< attribute")<<"|"<<endl;
		cout<<string(33,'-')<<endl;
		cout<<"|"<<center(31,"DESCENDING ORDER")<<"|"<<endl;
		cout<<string(33,'-')<<endl;
		cout<<"|"<<center(7,"a")<<"|"<<center(7,"b")<<"|"<<center(15,"text")<<"|"<<endl;	
		cout<<string(33,'-')<<endl;
		for(node n:arr)
			cout<<"|"<<center(7,to_string(n.a))<<"|"<<center(7,to_string(n.b))<<"|"<<center(15,n.txt)<<"|"<<endl;
		cout<<string(33,'-')<<endl;
	}
	
	sort(arr.begin(),arr.end(),node::comp_txt_ascending);
	
	{ //Sorted based on txt attribute. Ascending order.
		cout<<string(33,'-')<<endl;
		cout<<"|"<<center(31,"Sorted based on >txt< attribute")<<"|"<<endl;
		cout<<string(33,'-')<<endl;
		cout<<"|"<<center(31,"ASCENDING ORDER")<<"|"<<endl;
		cout<<string(33,'-')<<endl;
		cout<<"|"<<center(7,"a")<<"|"<<center(7,"b")<<"|"<<center(15,"text")<<"|"<<endl;	
		cout<<string(33,'-')<<endl;
		for(node n:arr)
			cout<<"|"<<center(7,to_string(n.a))<<"|"<<center(7,to_string(n.b))<<"|"<<center(15,n.txt)<<"|"<<endl;
		cout<<string(33,'-')<<endl;
	}
	
	sort(arr.begin(),arr.end(),node::comp_txt_descending);
	
	{ //Sorted based on txt attribute. Descending order.
		cout<<string(33,'-')<<endl;
		cout<<"|"<<center(31,"Sorted based on >txt< attribute")<<"|"<<endl;
		cout<<string(33,'-')<<endl;
		cout<<"|"<<center(31,"DESCENDING ORDER")<<"|"<<endl;
		cout<<string(33,'-')<<endl;
		cout<<"|"<<center(7,"a")<<"|"<<center(7,"b")<<"|"<<center(15,"text")<<"|"<<endl;	
		cout<<string(33,'-')<<endl;
		for(node n:arr)
			cout<<"|"<<center(7,to_string(n.a))<<"|"<<center(7,to_string(n.b))<<"|"<<center(15,n.txt)<<"|"<<endl;
		cout<<string(33,'-')<<endl;
	}
	
	return 0;
}
