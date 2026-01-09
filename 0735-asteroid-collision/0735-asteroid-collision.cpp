class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> asteroidStack;
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            if(asteroidStack.empty()) asteroidStack.push(asteroids[i]);
            else if((asteroidStack.top() < 0 && asteroids[i] < 0) || (asteroidStack.top() > 0 && asteroids[i] > 0)) asteroidStack.push(asteroids[i]);
            else if(asteroidStack.top() < 0 && asteroids[i] > 0) asteroidStack.push(asteroids[i]);
            else {
                int currEl = asteroids[i];
                while(!asteroidStack.empty() && asteroidStack.top() > 0 && asteroidStack.top()  != abs(currEl) && asteroidStack.top() < abs(currEl)) {
                    asteroidStack.pop();
                }
                if(asteroidStack.empty() || asteroidStack.top() < 0) asteroidStack.push(currEl);
                else if(asteroidStack.top() == abs(currEl)) asteroidStack.pop();
            }
         
        }

        while(!asteroidStack.empty()) {
            ans.push_back(asteroidStack.top());
            asteroidStack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};