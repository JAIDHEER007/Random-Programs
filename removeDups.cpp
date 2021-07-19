#include <bits/stdc++.h>
using namespace std;

string removeDups(string S) 
{
    vector<int> alphabets(26);
    string res = "";
    for(char ch:S){
        if(alphabets[ch-'a'] == 0){
            res += ch;
            alphabets[ch-'a'] = 1; 
        }
    }
    return res; 
}

int main()
{
	cout<<removeDups("abbac")<<endl;
	return 0;
}


//Explanation

//We are using Hashing to remove the duplicates

//First we will create a table of length 26 all initialized to ZERO 
//Each space is for each alphabet 

//  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  
//  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z


//Now create an empty string named 'res' for storing the result string


//Consider "abbac" as input

// a  b  b  a  c
// ^

// For character 'a' check the table 
// If the value is zero, Then add it to the 'res' string

//  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  
//  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
//  ^

// Now res = "a"

// Update the value of 'a' in the table. Change it to one. 
// In this way, if again 'a' occurs in the input string we will ignore it

//  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  
//  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
//  ^

// =============================================================================

// a  b  b  a  c
//    ^

// For character 'b' check the table 
// If the value is zero, Then add it to the 'res' string

//  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  
//  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
//     ^

// Now res = "ab"

// Update the value of 'b' in the table. Change it to one. 
// In this way, if again 'b' occurs in the input string we will ignore it

//  1  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  
//  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
//     ^

// =============================================================================

// a  b  b  a  c
//       ^

// For character 'b' check the table 
// If the value is one, just ignore it. 

//  1  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  
//  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
//     ^

// Now res = "ab"

// =============================================================================

// a  b  b  a  c
//          ^

// For character 'a' check the table 
// If the value is one, just ignore it. 

//  1  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  
//  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
//     ^

// Now res = "ab"

// =============================================================================

// a  b  b  a  c
//       	   ^	

// For character 'c' check the table 
// If the value is zero, add it to the 'res'. 

//  1  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  
//  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
//        ^

// Now res = "abc"

// Update the table

//  1  1  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  
//  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
//        ^

//=======================================================================

//Final result: abc

















