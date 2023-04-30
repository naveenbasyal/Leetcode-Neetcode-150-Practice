class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
     set<int> st;
        for(auto i:nums){
            st.insert(i);
        }
        if(st.size()<nums.size()) return true;
        else return false;
    }
};