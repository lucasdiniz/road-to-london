class Solution {
public:
	int countPrimes(int n) {
		bool prime[n+1];
		memset(prime, true, sizeof(prime));

		for (int p = 2; p * p <= n; p++) {
			if (prime[p]) {
				for (int i = p * 2; i <= n; i += p) {
					prime[i] = false;
				}
			}
		}

		int c = 0;
		for (int i = 2; i < n; i++) {
			if(prime[i])
				c++;
		}

		return c;
	}
    

};