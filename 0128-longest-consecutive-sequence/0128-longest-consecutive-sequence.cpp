class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return 1;
        sort(nums.begin(),nums.end());
        int c = 1 , res=1;
        for(int i = 0; i < n - 1; i++){
            if(nums[i+1]==nums[i]+1){
                c++;
                res=max(res,c);
            }
            else if(nums[i]==nums[i+1]) continue;
            else c=1;
        }
        return res;
    }
    
};