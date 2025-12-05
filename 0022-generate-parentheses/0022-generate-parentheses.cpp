class Solution {
public:
    //26/11/25
/*
    void solve(string currString, int size, int depth, int currPair, vector<string> &ans) {
        if(currString.size() == size) {
            ans.push_back(currString);
            return;
        }
        if((currPair + depth) == size/2) {
            solve(currString + ')', size, depth - 1, currPair + 1, ans);
        }
        else {
            solve(currString + '(', size, depth + 1, currPair, ans);
            if(depth > 0) {
            solve(currString + ')', size, depth-1, currPair + 1, ans);
            }
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve("(", 2*n, 1, 0, ans);
        return ans;
    }
*/

void parenthesis(int n, string st, int p, int depth, vector<string> &ans) {
    if(st.size() == n*2) {
        ans.push_back(st);
        return;
    }
    if(depth + p == n) {
        parenthesis(n, st + ')', p+1, depth - 1, ans);
    }
    else {
        parenthesis(n, st + '(', p, depth + 1, ans);
        if(depth > 0) parenthesis(n, st + ')', p + 1, depth - 1, ans);
    }

}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    parenthesis(n, "(", 0, 1, ans);
    return ans;
}

};