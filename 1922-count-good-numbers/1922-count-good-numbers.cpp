class Solution {
public:
    const long long MOD = 1000000007;

    long long myPow(int x, long long n) {
        if(n == 0) return 1;
        if(n%2 == 0) {
            long long ans = myPow(x, n/2);
            return (ans * ans) % MOD;
        }
        else {
            long long ans = x * myPow(x, n - 1);
            return ans % MOD;
        }
    }

    int countGoodNumbers(long long n) {
        //there are only 5 choice for single digit even number
        //there are only 4 choice for single digit prime number
        long long oddPlaces = n/2;
        long long evenPlaces = n - oddPlaces;

        long long goodNumber = (myPow(5, evenPlaces) * myPow(4, oddPlaces)) % MOD;

        return goodNumber;
    }
};