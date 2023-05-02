class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int countZeros = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[countZeros++] = nums[i];
            }
        }
        
        while (countZeros < nums.size()) {
            nums[countZeros++] = 0;
        }
    }
};
