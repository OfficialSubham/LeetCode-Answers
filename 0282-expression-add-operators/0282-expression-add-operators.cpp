class Solution {
public:

    void generatePossibilities(string num, int target, int idx, long long sum, string ansString, vector<string> &ans, int lastNum) {
        if(idx == num.size()) {
            if(sum == target) {
                ans.push_back(ansString);
            }
            return;
        }
        int digit = num[idx] - '0';
        vector<char> signOperator = {'+', '-', '*'};
        for(char c : signOperator) {
            switch(c) {
                case '+' : 
                    generatePossibilities(num, target, idx+1, sum + digit, ansString + c + num[idx], ans, digit);
                    break;
                case '-' :
                    generatePossibilities(num, target, idx+1, sum - digit, ansString + c + num[idx], ans, digit);
                    break;
                case '*' :
                    generatePossibilities(num, target, idx+1, sum - lastNum + (lastNum  * digit), ansString + c + num[idx], ans, digit);
                    break;
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string ansString = "";
        int i = 0;
        while(num[i] == '0') i++;
        ansString += num[i];
        long long sum = 0;
        int digit = num[i] - '0';
        sum += digit;
        generatePossibilities(num, target, i + 1, sum, ansString, ans, digit);
        return ans;
    }
};