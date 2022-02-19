// Question Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/arrange-buildings-official/ojquestion
// Video Link: https://youtu.be/0nF-BMYy7tc?list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy
// Exact sam as CountBinaryStrings.c but with different story
#include <stdio.h>

int recursive(int n){
	return 0;
}

int memoize(int n){
	return 0;
}

int tabulate(const int n){
	int end0[n + 1], end1[n + 1];
	
	for(int i = 0; i <= n; ++i)
		end0[i] = end1[i] = 0;
	
	end0[1] = end1[1] = 1;

	for(int i = 2; i <= n; ++i){
		end0[i] = end1[i-1];
		end1[i] = end0[i-1] + end1[i-1];
	}

	return end1[n] + end0[n];
}

int optimized(const int n){
	int oldCount0 = 1, oldCount1 = 1;

	for(int i = 2; i <= n; ++i){
		int newCount1 = oldCount0 + oldCount1;
		int newCount0 = oldCount1;

		oldCount0 = newCount0;
		oldCount1 = newCount1;
	}

	return oldCount0 + oldCount1;
}

int main(void){
	printf("Enter length of road: ");
	int n; scanf("%d", &n);

	// int noOfStrings = recursive(n);
	// int noOfStrings = memoize(n);
	// int noOfStrings = tabulate(n);
	int noOfStrings = optimized(n);

	printf("Number of possible arrangements is %d\n", noOfStrings * noOfStrings);
}