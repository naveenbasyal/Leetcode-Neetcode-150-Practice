class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return 1;
        sort(nums.begin(),nums.end());
        int count = 1 , ans=1;
        for(int i = 0; i < n - 1; i++){
            if(nums[i]+1 == nums[i+1]){
                count ++;
                ans = max(ans,count);
            }
            else if(nums[i]==nums[i+1]) continue;
            else count = 1;
        }
        return ans;
    }
    
};