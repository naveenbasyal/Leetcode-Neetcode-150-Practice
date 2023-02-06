class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        /*
            First we make the ans array with 1 for example nums[]=[1,2,3,4]
             ans[] =  [1,1,1,1]
             Now we take prefix with 1 and assign the value
             by multipying the prefix of every elements
             like: prefix = 1;
             ans[] = [1(nothing on left side) , 1( 1*1 ) , 2 ( 2*1) , 6 ( 3*2*1) ]
        */
        int prefix = 1;
        for(int i = 0; i < n; i++){  
            ans[i] = prefix;
            prefix = nums[i] * prefix;   
        }
        /*
             Now we take postfix with 1 and assign the value
             by multipying the postfix of every elements with the existing one in ans array
             like: postfix = 1; Starting from end of array
             ans[] = [1(1* 2*3*4) , 1( 1*3*  4 ) , 8 ( 2*  4) , 6 ( nothing on right side) ]
        */
        int postfix = 1;
        for(int i = n-1; i >= 0; i--){
            ans[i] = postfix * ans[i];
            postfix = nums[i] * postfix;
        }
        return ans;
    }
};