/*
Approach: Basic Sieve of Eratosthenes

Time Complexity: ~O(n log log n)
Space Complexity: O(n)
*/

class Solution {
public:
int countPrimes(int n) {

```
    int cnt = 0;
    vector<bool> prime(n, true);

    if(n <= 2) return 0;

    prime[0] = prime[1] = false;

    for(int i = 2; i < n; i++){
        if(prime[i]){
            cnt++;

            for(int j = 2*i; j < n; j += i){
                prime[j] = false;
            }
        }
    }

    return cnt;
}
```

};
