class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int count = 0;
        int sz = flowerbed.size();
       
        for(int i = 0; i < flowerbed.size(); i++){
            if(flowerbed[i] == 0 and (i == 0 || flowerbed[i-1] ==0) and (i == sz - 1 || flowerbed[i+1] == 0)){
                flowerbed[i] = 1;
                count++;
                
            }    
        }
         
        return count >= n;
    }
};