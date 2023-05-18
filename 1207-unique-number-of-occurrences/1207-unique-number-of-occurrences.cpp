class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        
        for(auto i:arr) mp[i]++;
        
        vector<int> ans;
        
        for(auto i:mp){
            ans.push_back(i.second);
        }
        sort(ans.begin(),ans.end());
        for(int i = 0; i < ans.size() - 1 ; i++){
            if(ans[i] == ans[i+1]) return false;
        }
        return true;
        
    }
};