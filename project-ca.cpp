#include <bits/stdc++.h>
using namespace std;

int main() {
	int i,j,n,p,w;
	char *x;
	char *x_old;

	cout<<"Pseudo Random Number Generator\n\n";
	cout<<"Enter window length w\n";
	cin>>w;

	// n is the total CA length decided by the window length given by user
	if(int(ceil(2.5*w))%2==0) {
		n=int(ceil(2.5*w)+1);
	}
	else if(int(ceil(2.5*w))%2!=0) {
		n=int(ceil(2.5*w));
	}
	
	x = new char[n+2];
	
	cout<<"Enter seed string of length w separated by spaces\n";
	for(int i=0; i<w; i++) {
		cin>>x[i];
	}

	// p is the no of cycles undertaken depending on the number of random numbers the user wants
	cout<<"How many random numbers do I generate?\n";
	cin>>p;
	p=(n-w+p);
	
	x_old = new char[n+2];
	
	for(i=w; i<n-1; i++) {
		x[i] = '0';
	}
	x[n-1] = '1';
	// only to show the initial CA configuration
	cout<<"Initial configuration of CA\n";
	for(i=0; i<n; i++) {
		cout<< x[i];
	}
	cout<<"\n\n\The random numbers generated are:\n";
	for(j=0; j<(n); j++) {
		for(i=0; i<n+2; i++) {
			x_old[i] = x[i];
		}

		// Implementing Rule R from 1 to n-w cycles
		for(i=1; i<=n; i++) {
				if( (x_old[i-1] == '2' && x_old[i] == '2' && x_old[i+1] == '0') ||
					(x_old[i-1] == '2' && x_old[i] == '1' && x_old[i+1] == '2') ||
					(x_old[i-1] == '2' && x_old[i] == '0' && x_old[i+1] == '0') ||
					(x_old[i-1] == '1' && x_old[i] == '2' && x_old[i+1] == '2') ||
					(x_old[i-1] == '1' && x_old[i] == '1' && x_old[i+1] == '2') ||
					(x_old[i-1] == '1' && x_old[i] == '0' && x_old[i+1] == '0') ||
					(x_old[i-1] == '0' && x_old[i] == '2' && x_old[i+1] == '2') ||
					(x_old[i-1] == '0' && x_old[i] == '1' && x_old[i+1] == '2') ||
			 		(x_old[i-1] == '0' && x_old[i] == '0' && x_old[i+1] == '0'))
			 		{
			 			x[i] = '0';
					}
				else if( (x_old[i-1] == '0' && x_old[i] == '0' && x_old[i+1] == '1') ||
					(x_old[i-1] == '2' && x_old[i] == '2' && x_old[i+1] == '2') ||
					(x_old[i-1] == '2' && x_old[i] == '1' && x_old[i+1] == '0') ||
					(x_old[i-1] == '2' && x_old[i] == '0' && x_old[i+1] == '2') ||
					(x_old[i-1] == '1' && x_old[i] == '2' && x_old[i+1] == '0') ||
					(x_old[i-1] == '1' && x_old[i] == '1' && x_old[i+1] == '0') ||
					(x_old[i-1] == '1' && x_old[i] == '0' && x_old[i+1] == '2') ||
					(x_old[i-1] == '0' && x_old[i] == '2' && x_old[i+1] == '0') ||
			 		(x_old[i-1] == '0' && x_old[i] == '1' && x_old[i+1] == '0'))
			 		{
			 			x[i] = '1';
					}
				else if( (x_old[i-1] == '2' && x_old[i] == '2' && x_old[i+1] == '1') ||
					(x_old[i-1] == '2' && x_old[i] == '1' && x_old[i+1] == '1') ||
					(x_old[i-1] == '2' && x_old[i] == '0' && x_old[i+1] == '1') ||
					(x_old[i-1] == '1' && x_old[i] == '2' && x_old[i+1] == '1') ||
					(x_old[i-1] == '1' && x_old[i] == '1' && x_old[i+1] == '1') ||
					(x_old[i-1] == '1' && x_old[i] == '0' && x_old[i+1] == '1') ||
					(x_old[i-1] == '0' && x_old[i] == '2' && x_old[i+1] == '1') ||
					(x_old[i-1] == '0' && x_old[i] == '1' && x_old[i+1] == '1') ||
			 		(x_old[i-1] == '0' && x_old[i] == '0' && x_old[i+1] == '2'))
			 		{
			 			x[i] = '2';
					}
			}
		
		x[0] = x[n];
		x[n+1] = x[1];
		
//		for(i=1; i<=n; i++) {
//			cout<<x[i];
//		}
//		cout<<"\n";
	}
	
	
for(j=(n-w); j<p; j++) {
		for(i=0; i<n+2; i++) {
			x_old[i] = x[i];
		}

		// Implementing Rule R from n-w to p cycles
		for(i=0; i<n; i++) {
				if( (x_old[i-1] == '2' && x_old[i] == '2' && x_old[i+1] == '0') ||
					(x_old[i-1] == '2' && x_old[i] == '1' && x_old[i+1] == '2') ||
					(x_old[i-1] == '2' && x_old[i] == '0' && x_old[i+1] == '0') ||
					(x_old[i-1] == '1' && x_old[i] == '2' && x_old[i+1] == '2') ||
					(x_old[i-1] == '1' && x_old[i] == '1' && x_old[i+1] == '2') ||
					(x_old[i-1] == '1' && x_old[i] == '0' && x_old[i+1] == '0') ||
					(x_old[i-1] == '0' && x_old[i] == '2' && x_old[i+1] == '2') ||
					(x_old[i-1] == '0' && x_old[i] == '1' && x_old[i+1] == '2') ||
			 		(x_old[i-1] == '0' && x_old[i] == '0' && x_old[i+1] == '0'))
			 		{
			 			x[i] = '0';
					}
				else if( (x_old[i-1] == '0' && x_old[i] == '0' && x_old[i+1] == '1') ||
					(x_old[i-1] == '2' && x_old[i] == '2' && x_old[i+1] == '2') ||
					(x_old[i-1] == '2' && x_old[i] == '1' && x_old[i+1] == '0') ||
					(x_old[i-1] == '2' && x_old[i] == '0' && x_old[i+1] == '2') ||
					(x_old[i-1] == '1' && x_old[i] == '2' && x_old[i+1] == '0') ||
					(x_old[i-1] == '1' && x_old[i] == '1' && x_old[i+1] == '0') ||
					(x_old[i-1] == '1' && x_old[i] == '0' && x_old[i+1] == '2') ||
					(x_old[i-1] == '0' && x_old[i] == '2' && x_old[i+1] == '0') ||
			 		(x_old[i-1] == '0' && x_old[i] == '1' && x_old[i+1] == '0'))
			 		{
			 			x[i] = '1';
					}
				else if( (x_old[i-1] == '2' && x_old[i] == '2' && x_old[i+1] == '1') ||
					(x_old[i-1] == '2' && x_old[i] == '1' && x_old[i+1] == '1') ||
					(x_old[i-1] == '2' && x_old[i] == '0' && x_old[i+1] == '1') ||
					(x_old[i-1] == '1' && x_old[i] == '2' && x_old[i+1] == '1') ||
					(x_old[i-1] == '1' && x_old[i] == '1' && x_old[i+1] == '1') ||
					(x_old[i-1] == '1' && x_old[i] == '0' && x_old[i+1] == '1') ||
					(x_old[i-1] == '0' && x_old[i] == '2' && x_old[i+1] == '1') ||
					(x_old[i-1] == '0' && x_old[i] == '1' && x_old[i+1] == '1') ||
			 		(x_old[i-1] == '0' && x_old[i] == '0' && x_old[i+1] == '2'))
			 		{
			 			x[i] = '2';
					}
			}
		
		// periodic boundary condition
		x[0] = x[n];
		x[n+1] = x[1];
		
		for(i=1; i<n; i++) {
			cout<<(int(x[i])-48);
		}
		cout<<"\n";

		// ternary to decimal number
		long double a=0;
		for(i=1; i<n; i++) {
			a += ((int(x[i])-48) * pow(3, (n-1-i)));
		}
		cout<<"Decimal: "<<a<<"\n";
	}
	
	delete [] x;
	delete [] x_old;
	cout<<"\nend";
}
