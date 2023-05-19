class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> ans;
        for(int i=0; i<m;i++){
            ans.push_back(nums1[i]);
        }
        for(auto i:nums2){
            ans.push_back(i);
        }
        
        for(int i=0;i<ans.size();i++){
            nums1[i] = ans[i];
        }
        sort(nums1.begin() , nums1.end());
    }
};