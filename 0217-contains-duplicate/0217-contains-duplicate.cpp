class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> hashSet;

        for(int i = 0; i < nums.size(); i++) {
            hashSet.insert(nums[i]);
        }

        return hashSet.size() != nums.size();

    }
};