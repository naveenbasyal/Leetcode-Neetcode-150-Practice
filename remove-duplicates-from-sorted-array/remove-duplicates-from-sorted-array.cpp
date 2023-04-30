class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        
        vector<int> ans(st.begin(),st.end());
        
        for(int i =0;i<st.size();i++){
            nums[i]= ans[i];
        }
        return st.size();
    }
};