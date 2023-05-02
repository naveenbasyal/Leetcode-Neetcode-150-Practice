class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n= strs.size();
        sort(strs.begin(),strs.end());
        
        string a = strs[0] , b = strs[n-1];
        
        for(int i=0;i<min(a.size(),b.size());i++){
            if(a[i] == b[i]){
                ans+=a[i];
            }
            else{
                return ans;
            }
        }
        return ans;
    }
};