class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> ans;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            ans.push_back({nums[i],i});
        }
        sort(ans.begin(),ans.end());
        int i=0, j=ans.size()-1;
        
        while(i<j){
            if(ans[i].first+ans[j].first==target){
                v.push_back(ans[i].second);
                v.push_back(ans[j].second);
                break;//must: because we want the loop to stop ,otherwi
            }
            else if(ans[i].first + ans[j].first > target) {
                j--;
            }
            else{
                i++;
            }
        }
        return v;
        
    }
};