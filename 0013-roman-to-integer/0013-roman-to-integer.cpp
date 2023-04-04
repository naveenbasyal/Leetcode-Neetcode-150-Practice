class Solution {
public:
    int romanToInt(string s) {
        vector<int> ans;
        for(int i=0; i < s.size();i++){
            if(s[i]== 'I')
            {
                ans.push_back(1)  ;  
            }
            else if(s[i] == 'V')
                ans.push_back(5);
            
            else if(s[i] == 'X')
                ans.push_back(10);
            else if(s[i] == 'L')
                ans.push_back(50);
            else if(s[i] == 'C')
                ans.push_back(100);
            else if(s[i] == 'D')
                ans.push_back(500);
             else if(s[i] == 'M')
                ans.push_back(1000);
        }
        
         int res = 0;
        for(int i=0;i<ans.size();i++){
            if(i < ans.size() - 1 && ans[i] < ans[i+1]){
                res -= ans[i];
            }
            else {
                res += ans[i];
            }
        }
        return res;
        
    }
};