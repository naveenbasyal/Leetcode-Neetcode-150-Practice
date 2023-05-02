class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       
        int i=0,j=1;
        
        while(j < nums.size()){
            if(nums[i] == 0  and nums[j] != 0 ){
                swap(nums[i],nums[j]);
                i++,j++;
            }
            else if(nums[i]==0 and nums[j] ==0){
                j++;
            }
            else if(nums[i] != 0 and nums[j] ==0){
                i++,j++;
            }
            else if(nums[i] != 0 and nums[j] != 0){
                i++,j++;
            }
        }
    }
    
};
