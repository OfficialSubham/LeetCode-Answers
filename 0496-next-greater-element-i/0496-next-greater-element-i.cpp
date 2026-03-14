class Solution {
public:

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());
        for(int i = 0; i < nums1.size(); i++) {
            int idx = -1;
            for(int j = 0; j < nums2.size(); j++) {
                if(nums1[i] == nums2[j]) {
                    while(j < nums2.size() && nums2[j] <= nums1[i]) j++;
                    if(j >= nums2.size()) ans[i] = -1;
                    else ans[i] = nums2[j];
                }
            }
        }
        return ans;
    }
};