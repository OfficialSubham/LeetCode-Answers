class Solution {
public:

    double solve(double x, long long n) {
        if(n == 0) return 1;
        if(n < 0) {
            long long exponent = n;
            exponent = -exponent;
            return 1/solve(x, exponent);
        }
        if(n%2 == 0) {
            double ans = solve(x, n/2);
            return ans*ans;
        }
        else {
            return x * solve(x, n-1);
        }
    }

    double myPow(double x, int n) {
       return solve(x, n);
    }
};