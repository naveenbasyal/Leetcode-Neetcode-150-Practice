class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string,vector<string>> mp;
        /*   aet  - [eat,tea,ate]*/
        vector<vector<string>> ans;
        /*
            First, We have to sort the string for: finding anagram
            Second, Map them with original one like:
            
                strs = ["eat","tea","tan","ate","nat","bat"]
                
             #The Map will Look like this :-
                aet - {eat,tea,ate}
                ant - {nat,tan}
                abt - {abt}     
        */
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            /* temp = eat */
            
            sort(temp.begin(),temp.end());
            /* temp = aet */
            
            mp[temp].push_back(strs[i]);
           /*aet - [eat,tea,ate]*/
            
        }
        /* Now we just push the second part of map into our ans */
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
        
    }
};