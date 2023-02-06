class Solution {
private: 
    static bool cmp(pair<int, int>& a, pair<int, int>& b)
    {
        return a.second > b.second;
    }
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        vector<pair<int,int>> temp;
        map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto i:mp){
            temp.push_back(i);
        }
        sort(temp.begin(),temp.end(),cmp);
        
        for(auto i:temp){
            if(k>0){
                ans.push_back(i.first);
                k--;
            }
        }
        return ans;
    }
};