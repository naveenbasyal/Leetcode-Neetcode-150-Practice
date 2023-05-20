class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int maxReach = 0 , n = nums.size();
        
        for(int i = n - 2; i >= 0; i--){
            maxReach++;
            if(nums[i] >= maxReach){
                maxReach = 0;
            }
        }
        
        if(maxReach == 0) return true;
        else return false;
    }
};