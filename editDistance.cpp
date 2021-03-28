//Author: Sean Dever
//Date: 3/28/2021
//Description: This application has been created to serve as a learning example of dynamic programming. The problem solved here is the edit distance problem. Two strings will be entered and compared. Using a dynamic programming array the program will determine the minimum amount of edits required to transform string0 into string1.
//References: https://www.geeksforgeeks.org/edit-distance-dp-5/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minOfVals(int x,int y,int z){
	if(x <= y && x <= z)
		return x;
	if(y <= x && y <= z)
		return y;
	if(z <= x && z <= y)
		return z;
}

int editDistance(string str0,string str1,int m,int n){
	// If the first/second string is empty then the only operations to perform are to add all characters of the other string
	if(m == 0)
		return n;
	if(n == 0)
		return m;
	
	// If the last two characters of the two strings are the same, ignore the last two characters and count remaining chars
	if(str0[m-1] == str1[n-1])
		return editDistance(str0,str1,m-1,n-1);

	// If the last characters are not the same, consider all three operations on the last character of the first string,
	// recursively compute minimum cost for all three
	// operations and take minimum values.A
	
	return 1 + minOfVals(editDistance(str0, str1, m, n - 1), editDistance(str0, str1, m - 1, n), editDistance(str0, str1, m - 1, n - 1));

}


int main(){
	
	int minVal;
	
	// testing the minOfVals function
	// minVal = minOfVals(3,5,10);
	//cout << minVal << endl;
	
	string str0 = "test";
	string str1 = "feast";

	cout << editDistance(str0,str1,str0.length(),str1.length());

	return 0;
}
