class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size() , col = matrix[0].size();
        
        // for(int i = 0; i < matrix.size(); i++){
        //     for(int j = 0; j < matrix[0].size(); j++){
        //         if(matrix[i][j] == target){
        //             return true;
        //         }
        //     }
        // }
        // return false;
        
        for(int i = 0; i < row; i++){
            int left = 0 , right = col - 1;
            
            while(left <= right){
                int mid = left + (right- left)/2;
                
                if(matrix[i][mid] == target){
                    return true;
                }
                else if ( matrix[i][mid] < target){
                    left = mid+1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
            return false;
        
    }
};