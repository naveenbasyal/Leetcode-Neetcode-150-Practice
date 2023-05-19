class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;
        
        for(auto i:nums){
            mp[i]++;
        }
        int maxi = INT_MIN , ans =0;
        for(auto i:mp){
            if(i.second > maxi){
                maxi = i.second;
                ans = i.first;
            }
        }
        
        return ans;
    }
};