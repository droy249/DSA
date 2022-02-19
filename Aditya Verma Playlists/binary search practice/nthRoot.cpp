/* 
Write a program to find the nth root of given number.
HINT: Try binary search

Expected Time Complexity: O(log n)
*/

#include <stdio.h>

double multiply(double number, int n) {
	return !n ? 1.0 : number * multiply(number,n-1);
}

double nthRoot(int base, int power, double low, double high) {
	double low = 1, high = base;
	const double epsilon = 1e-6;
	while(high - low > epsilon) {
		const double mid = high + (high - low) / 2.0;
		(multiply(mid,power) < base ? low : high) = mid;
	}
	return 
	// return multiply(mid,power) < base ? nthRoot(base,power,mid,high) : nthRoot(base,power,low,mid) ;
}

int main(){
	int base, power;
	// while(true) {
		printf("Enter base and exponent: ");
		scanf("%d %d", &base, &power);
		
		printf("Required radical is = %lf\n", nthRoot(base,power,1,base));
	// }
	// printf("Exiting...\n\n");
}