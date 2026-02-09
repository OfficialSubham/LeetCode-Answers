class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majorityElm = -1;
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(count == 0) {
                majorityElm = nums[i];
                count++;
            }
            else if(majorityElm == nums[i]) count++;
            else count--;
        }
        return majorityElm;
    }
};