class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        
        for(auto i:arr) mp[i]++;
        
        vector<int> ans;
        
        for(auto i:mp){
            ans.push_back(i.second);
        }
        set<int> st(ans.begin(),ans.end());
        
        return st.size() == ans.size();        
    }
};