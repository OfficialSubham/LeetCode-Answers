class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        int lastPtr = 0;
        int i = 0;
        int n = nums.size();
        int ans = 0;

        while(i < n) {
            while(lastPtr <= i && hashMap[0] >= k && nums[i] == 0) {
                hashMap[nums[lastPtr]]--;
                if(hashMap[nums[lastPtr]] == 0) hashMap.erase(nums[lastPtr]);
                lastPtr++;
            }
            hashMap[nums[i]]++;
            ans = max(ans, i - lastPtr + 1);
            i++;
        }

        return ans;

    }
};