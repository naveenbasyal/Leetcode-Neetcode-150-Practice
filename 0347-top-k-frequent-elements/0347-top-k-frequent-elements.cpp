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
        
        /* First : mapping elements
                nums[]= [1,1,1,2,2,3] and k=2;
           After mapping: 
                    1 - 3
                    2 - 2
                    3 - 1
            
        */
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        /* Storing the above elts in vector
            temp = [ {1,3} ,{3,1}, {2,2} ]
        */
        for(auto i:mp){
            temp.push_back(i);
        }
        /*Sorting it so that we can get the elts inorder
            After Sorting in descending order:-
            nums[] = {1,3},{2,2},{3,1}
            
        */
        sort(temp.begin(),temp.end(),cmp);
        
        /* Now , until k is 0 , we keep pushing the 1st part of our temp into ans*/
        for(auto i:temp){
            if(k>0){
                ans.push_back(i.first);
                k--;
            }
        }
        return ans;
    }
};