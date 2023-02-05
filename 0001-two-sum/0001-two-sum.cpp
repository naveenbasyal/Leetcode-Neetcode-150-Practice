class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> ans;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            ans.push_back({nums[i],i});//storing elts with indexes in vector
        }
        sort(ans.begin(),ans.end());
        int i=0, j=ans.size()-1;
        
        while(i<j){     //doing a left right search 
            if(ans[i].first+ans[j].first==target){
                v.push_back(ans[i].second);
                v.push_back(ans[j].second);
                break; //must: because we want the loop to stop ,otherwise it will lead to TLE
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