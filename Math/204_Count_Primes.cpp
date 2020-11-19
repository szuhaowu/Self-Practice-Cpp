// Count the number of prime numbers less than a non-negative number, n.

 

// Example 1:

// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
// Example 2:

// Input: n = 0
// Output: 0
// Example 3:

// Input: n = 1
// Output: 0

//參考 https://mp.weixin.qq.com/s/EVhp3D_hwI8RFZlu5sQaIA
//time complexity  O(n^2) => O(n*loglogn)
class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<bool> isPrime(n,true);
        for(int i=2; i*i<n; i++){
            if(isPrime[i]){
                for(int j=i*i; j<n; j+=i) isPrime[j] = false;
            }
        }
        for(int i=2; i<n; i++) res += (isPrime[i])? 1:0;
        return res;
    }
};