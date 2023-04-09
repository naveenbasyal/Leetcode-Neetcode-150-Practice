class Solution {
public:
//   Initialize two pointers, left and right, to point to the first and last element of the array respectively.
//   While the left pointer is less than the right pointer:
//      a. Calculate the middle element index as mid = left + (right - left) / 2.
//      b. If the middle element is greater than the last element, then the minimum element must be in the right half of the array, so set left = mid + 1.
//      c. Otherwise, the minimum element must be in the left half of the array, so set right = mid.
//       When the loop ends, the left pointer will be pointing to the minimum element in the array, so return nums[left].
    int findMin(vector<int>& nums) {
        
        int left = 0 , right = nums.size()-1 ;
       
        while(left < right){
            if(nums[left] < nums[right]) return nums[left];
            
            int mid = left + (right-left)/2;
            
            if(nums[mid] > nums[right]){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        
        return nums[left];
        
        
    }
};