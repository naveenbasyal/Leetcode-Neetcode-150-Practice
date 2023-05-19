class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
     
        int count =0;
        vector<int> ans;
        for(auto i:nums){
            if(i != val){
                ans.push_back(i);
            }
        }
        for(int i=0;i<ans.size();i++){
            nums[i] = ans[i];
        }
        return ans.size();
    }
};