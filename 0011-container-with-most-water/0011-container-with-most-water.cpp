class Solution {
public:
    int maxArea(vector<int>& height) {
     /*
        Approach : 
                We Calculate the maximum area i.e (length * min height)
                    length for the longest from right to left to maximize the area and
                    min height , otherwise the water will spill out
                        
        Implementation :
                    We set the left and right ptr at 0 and n-1;
                    then, cal the max of (minHeight b/w left and right ptr and
                    multiply it with the longest area i.e right - left)
        Check: 
                We also check if our left height is less then left++,
                if right height is less then right++; */
                    
        int maxi = 0;
        int i = 0, j = height.size()-1;
        while(i < j){
            int lh = height[i];
            int rh = height[j];
            int minh = min(lh,rh);
            
            maxi = max(minh * (j-i) , maxi);
            if(lh < rh) i++;
            else j--;
        }
        return maxi;
        
        
    }
};