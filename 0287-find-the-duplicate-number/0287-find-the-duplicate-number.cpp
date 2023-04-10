class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> st;
        int ans;
        
        for(int i =0;i<nums.size();i++){
            if(st.find(nums[i]) == st.end()){
                st.insert(nums[i]);
            }
            else{
                ans= nums[i];
            }
        }
        return ans;
    }
};