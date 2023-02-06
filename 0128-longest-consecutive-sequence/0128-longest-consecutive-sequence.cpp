class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return 1;
        sort(nums.begin(),nums.end());
        /*
            we simply sort the array and compare them .
            and we store the max length of consecutive elts in the ans.
            .if the compare is failed we set the length to 1 again.
            we are taking length 1 because even if there is 1 element in the array 
            the length will be 1 .
        */
        int length = 1 , ans=1;
        for(int i = 0; i < n - 1; i++){
            if(nums[i]+1 == nums[i+1]){
                length ++;
                ans = max(ans,length);
            }
            else if(nums[i] == nums[i+1]) continue; // is duplicate we continue
            else length = 1;
        }
        return ans;
    }
    
};