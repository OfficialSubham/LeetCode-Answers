class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                if(nums1[i] == nums2[j]) {
                    int num = -1;
                    while(j < nums2.size()) {
                        if(nums2[j] > nums1[i]) {
                            num = nums2[j];
                            break;
                        }
                        j++;
                    }
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};