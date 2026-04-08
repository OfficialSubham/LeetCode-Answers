class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> hashMap;
        hashMap[0] = 1;
        int i = 0;

        int prefixSum = 0;
        int ans = 0;
        while(i < n) {
            prefixSum += nums[i];
            int remSum = prefixSum - goal;

            if(hashMap.count(remSum)) ans += hashMap[remSum];

            hashMap[prefixSum]++;
            i++;
        }

        return ans;

    }
};