class Solution {
public:
    bool isAnagram(string s, string t) {
        
       unordered_map<char,int> mp;
        if(s.size() != t.size()) return false;
        for(auto i:s)
            mp[i]++;
        
        
        for(auto j:t){
            if(mp.find(j) != mp.end() and mp[j] > 0){
                mp[j]--;
            }
            else{
                return false;
            }
        }
        
        
        return true;
    }
};