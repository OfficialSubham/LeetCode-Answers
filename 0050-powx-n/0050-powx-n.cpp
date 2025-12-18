class Solution {
public:
/*
    //24/11/25
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


    double solve(double x, long long n) {
        //basecase
        if(n < 0) {
            return 1/(solve(x, -n));
        }
        if(n == 0) return 1;
        //even
        if(n % 2 == 0) {
            double ans = solve(x, n/2);
            return ans * ans;
        }
        //odd
        else {
            double ans = x  * solve(x, n-1);
            return ans;
        }
    }

    double myPow(double x, int n) {
        return solve(x, n);
    }
*/
    double myPow(double x, int n) {
        double ans = 1;
        bool isNegative = n < 0 ? true : false;
        n = abs(n);
        while(n > 0) {
            if(n%2 == 0) {
                n = n/2;
                x =  x*x;
            }
            else {
                n = n - 1;
                ans = ans * x;
            }
        } 
        if(isNegative) return 1/ans;
        return ans;
    }

};