class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pro = 0, mini = INT_MAX, n = prices.size();
        
        for(int i = 0; i < n; i++){
            /* First find and check the mini*/
            if(prices[i] < mini){
                mini = prices[i];
            }
            /* Now, calc the diff(i.e profit) b/w current price and the mini value*/
            int diff = prices[i] - mini;
            /* at iteration 3 when i is it index 2
            prices = [7,1,5,3,6,4]
                          i      */
            if(pro < diff){
            /*  0  < 5 - 1 */
                pro = diff;
            }
            
        }
        return pro;
    }
};