class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int n=s.size(),m=t.size();
        int count=0;int ms=max(n,m);
        
        for(int i=0;i<ms;i++){
            if(s[i]==t[i]) count++;
        }
        
        if(count==ms){
            return true;
        }
        else{
            return false;
        }
        
    }
};