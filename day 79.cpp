class Solution {
public:
    int countPrimes(int n) {
        // No primes less than 2
        if (n <= 2) return 0;
        // Sieve initialization: all numbers are potentially prime
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;
        // Iterate only up to sqrt(n)
        for (int i = 2; i * i < n; ++i) {
            if (isPrime[i]) {
                // Mark multiples of i as non-prime
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        // Count primes
        int primeCount = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) primeCount++;
        }
        return primeCount;
    }
};

// prblm:https://leetcode.com/problems/count-primes