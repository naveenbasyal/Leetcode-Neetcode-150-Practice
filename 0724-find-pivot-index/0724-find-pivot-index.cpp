class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        int leftsum = 0 , rightsum = 0;
        int totalSum = 0;
        
        for(auto i : nums){
            totalSum += i;
        }
        for(int i = 0; i < n; i++){
            rightsum = totalSum - leftsum - nums[i];
            
            if(leftsum == rightsum){
                return  i;
            }

             leftsum += nums[i];

        }
         return -1;
        
    }
};