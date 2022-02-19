// Gfg Link: https://www.geeksforgeeks.org/sieve-of-eratosthenes/
// Leetcode Link: https://leetcode.com/problems/count-primes/
#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n log log n)
// Space Complexity: O(n)
void sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int number{2}; number * number <= n; ++number)
        if (isPrime[number])
            for (int multiple{number * number}; multiple <= n; multiple += number)
                isPrime[multiple] = false;

    for (int i{}; i < isPrime.size(); ++i)
        if (isPrime[i])
            cout << i << ' ';
}

int main() {
    cout << "Enter number: ";
    int n;
    cin >> n;

    if (n < 2) {
        cout << "No prime numbers\n";
        return 0;
    }

    cout << "The prime numbers from 1 to " << n << " are:\n";
    sieveOfEratosthenes(n);
    cout << "\n\n";
}