class Solution {
public:
    int trap(vector<int>& height) {
        int left[height.size()];
        int right[height.size()];
        
        int maxi = INT_MIN;
        
        for(int i = 0; i < height.size(); i++){  
            maxi = max(maxi, height[i]);
            left[i] = maxi;
        }
        maxi = INT_MIN;
        for(int i = height.size() - 1; i >= 0 ; i--){  
            maxi = max(maxi, height[i]);
            right[i] = maxi;
        }
        
        int ans=0;
        
        for(int i=0;i<height.size();i++){
            ans += min(right[i],left[i]) - height[i];
        }
        return ans;
    }
};