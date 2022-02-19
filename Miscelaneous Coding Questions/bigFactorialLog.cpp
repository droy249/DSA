// Problem link: https://www.geeksforgeeks.org/factorial-of-large-numbers-using-logarithmic-identity/

// C++ program to compute the 
// factorial of big numbers 

#include <bits/stdc++.h> 
using namespace std; 

// Maximum number of digits 
// in output 
#define MAX 1000 

// Function to find the factorial 
// of large number and return 
// them in string format 
string factorial(long long n) 
{ 
	if (n > MAX) { 
		cout << " Integer Overflow"
			<< endl; 
		return ""; 
	} 

	long long counter; 
	long double sum = 0; 

	// Base case 
	if (n == 0) 
		return "1"; 

	// Calculate the sum of 
	// logarithmic values 

	for (counter = 1; counter <= n; 
		counter++) { 
		sum = sum + log(counter); 
	} 

	// Number becomes too big to hold in 
	// unsigned long integers. 
	// Hence converted to string 
	// Answer is sometimes under 
	// estimated due to floating point 
	// operations so round() is used 
	string result 
		= to_string(round(exp(sum))); 

	return result; 
} 

// Driver code 
int main() 
{ 
	clock_t tStart = clock(); 
	string str; 
	str = factorial(100); 
	cout << "The factorial is: "
		<< str << endl; 

	// Calculates the time taken 
	// by the algorithm to execute 
	cout << "Time taken: " << setprecision(10) 
		<< ((double)(clock() - tStart) / CLOCKS_PER_SEC) << " s" << endl; // Outputs 0.000114 s
    
    return 0;
} 
