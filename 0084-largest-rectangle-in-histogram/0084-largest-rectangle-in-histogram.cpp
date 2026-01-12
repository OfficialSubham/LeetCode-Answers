class Solution {
public:

    vector<int> prevMin(vector<int> &heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> heightsHash;
        for(int i = 0; i < n; i++) {
            while(!heightsHash.empty() && heights[heightsHash.top()] > heights[i]) heightsHash.pop();
            if(heightsHash.empty()) ans[i] = -1;
            else ans[i] = heightsHash.top();
            heightsHash.push(i);
        }
        return ans;
    }


    vector<int> nextMin(vector<int> &heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> heightsHash;
        for(int i = n - 1; i >= 0; i--) {
            while(!heightsHash.empty() && heights[heightsHash.top()] >= heights[i]) heightsHash.pop();
            if(heightsHash.empty()) ans[i] = n;
            else ans[i] = heightsHash.top();
            heightsHash.push(i);
        }
        return ans;
    }

    // int largestRectangleArea(vector<int>& heights) {
    //     int n = heights.size();
    //     int largestRec = -1;
    //     for(int i = 0; i < n; i++) {
    //         int mini = heights[i]; //Minimum in that subarray
    //         for(int j = i; j < n; j++) {
    //             mini = min(heights[j], mini);
    //             int area = mini * ((j - i) + 1);
    //             largestRec = max(largestRec, area);
    //         }
    //     }
    //     return largestRec;
    // }

    //Optimal
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> NMElm = nextMin(heights);
        vector<int> PMElm = prevMin(heights);
        int largestRec = -1;
        for(int i = 0; i < n; i++) {
            int left = i - PMElm[i];
            int right = NMElm[i] - i;
            int freq = right + left - 1;
            // int totalSubArrParticipation = NMElm[i] - PMElm[i];
            int recArea = freq*heights[i];
            largestRec = max(recArea, largestRec);
        }

        return largestRec;
    }
};