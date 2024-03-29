class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = INT_MIN;
        for(auto i:candies){
            maxi = max(maxi,i);
        }
        vector<bool> ans(candies.size());
        
        for(int i = 0; i< candies.size(); i++){
            if(candies[i] + extraCandies >= maxi){
                ans[i] = true;
            }
            else{
                ans[i] = false;
            }
        }
        return ans;
    }
};