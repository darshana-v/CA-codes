#include <bits/stdc++.h>
#include <string.h>
using namespace std;

// for n state CA

string shiftLeft(string &s1, int d) {
	string s = s1;
	reverse(s.begin(), s.begin()+d);
	reverse(s.begin()+d, s.end());
	reverse(s.begin(), s.end());
	return s;
}

string shiftRight(string &s1, int d) {
	string s = s1;
	s = shiftLeft(s, s.length()-d);
	return s;
}

int main() {
	ofstream myfile;
	string sibl, sibl0, siblTemp, sibl1;
	string a;
	int n;
	cout<<"Enter the value of n\n";
	cin>>n;
	cout<<"Input value of sibl0\nsibl0 would be a permutation of the string <012...(n-1)>\n\n";
	cin>>a;

	// adding seed value
	sibl += a;
	sibl0 = sibl.substr(0,n);

	for(int i=1; i<n; i++) {
	siblTemp = shiftRight(sibl0, i);
	sibl += siblTemp;
	}
	
	for(int j=n; j<=(pow(n,2)-1); j++) {
	sibl1 = shiftRight(sibl0, (j%n));
 	siblTemp = shiftRight(sibl1, floor(j/n));
	sibl += siblTemp;
	}
	
	cout<<"Rule: "<<sibl<<endl;
	myfile.open("nStateRules.txt", std::ios::out | std::ios::app);
	if(myfile.is_open()) myfile <<sibl<<endl;
	
	return 0;

}
