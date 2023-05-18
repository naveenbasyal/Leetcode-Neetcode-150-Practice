class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count = 0;
        
        for(auto i:nums){
            if(mp[k - i] > 0){
                count++;
                mp[k - i]--;
            }
            else{
                mp[i]++;
            }
        }
        
        return count;
    }
};