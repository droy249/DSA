// Question Link: https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/count-binary-strings-official/ojquestion
// Video Link: https://youtu.be/nqrXHJWMeBc?list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy
#include <stdio.h>

int recursive(int i, int n, int end0, int end1){
	if (n == 0)
		return 0;
	
	if (i == n)
		return end0 + end1;

	return recursive(i + 1, n, end1, end0 + end1);
}

// int memoize(int i, int n, int memo[][2]){
// 	if(n == 0){
// 		memo[i][1] = memo[i][0] = 0;
// 		return 0;
// 	}

// 	if(i == n)
// 		return memo[i][0] + memo[i][1];
	
// 	memo[i][0] = memo[i-1][1];
// 	memo[i][1] = memoize
// }

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
	printf("Enter length of binary string: ");
	int n; scanf("%d", &n);

	int noOfStrings = recursive(1, n, 1, 1);
	// int noOfStrings = memoize(n);
	// int noOfStrings = tabulate(n);
	// int noOfStrings = optimized(n);

	printf("Number of possible strings is: \n");
	printf("Recursive = %d\nMemoized = %d\nTabulated = %d\nOptimized = %d\n", recursive(1,n,1,1), optimized(n));
}