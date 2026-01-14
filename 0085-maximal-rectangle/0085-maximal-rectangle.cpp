class Solution {
public:

    vector<vector<int>> makePrefixMatrix(vector<vector<char>> &matrix) {
        vector<vector<int>> prefixMatrix(matrix.size(), vector<int>(matrix[0].size()));
        for(int i = 0; i < matrix[0].size(); i++) {
            int height = 0;
            for(int j = 0; j < matrix.size(); j++) {
                if(matrix[j][i] == '0') {
                    height = 0;
                    prefixMatrix[j][i] = height;
                }
                else {
                    height++;
                    prefixMatrix[j][i] = height;
                }
            }
        }
        return prefixMatrix;
    }

    vector<int> prevMin(vector<int> &matrix) {
        int n = matrix.size();
        vector<int> ans(n);
        stack<int> hashStack;

        for(int i = 0; i < n; i++) {
            while(!hashStack.empty() && matrix[hashStack.top()] > matrix[i]) hashStack.pop();
            if(hashStack.empty()) ans[i] = -1;
            else ans[i] = hashStack.top();

            hashStack.push(i);
        }
        return ans;
    }

    vector<int> nextMin(vector<int> &matrix) {
        int n = matrix.size();
        vector<int> ans(n);
        stack<int> hashStack;

        for(int i = n - 1; i >= 0; i--) {
            while(!hashStack.empty() && matrix[hashStack.top()] >= matrix[i]) hashStack.pop();
            if(hashStack.empty()) ans[i] = n;
            else ans[i] = hashStack.top();

            hashStack.push(i);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> prefixMatrix = makePrefixMatrix(matrix);
        vector<vector<int>> prevMinMatrix(n);
        vector<vector<int>> nextMinMatrix(n);

        for(int i = 0; i < n; i++) {
            vector<int> prevMinArr = prevMin(prefixMatrix[i]);
            vector<int> nextMinArr = nextMin(prefixMatrix[i]);
            prevMinMatrix[i] = prevMinArr;
            nextMinMatrix[i] = nextMinArr;
        }
        int maxi = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                int freq = (nextMinMatrix[i][j] - prevMinMatrix[i][j])-1;
                int val = prefixMatrix[i][j] * freq;
                maxi = max(maxi, val);
            }
        }
        return maxi;
    }
};