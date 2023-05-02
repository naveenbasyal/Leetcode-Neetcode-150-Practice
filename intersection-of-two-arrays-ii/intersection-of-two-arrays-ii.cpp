class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
//         Create a hash map to store the frequency of elements in nums1.
//         Iterate through nums1 and increment the count of each element in the hash map.
//         Create a result list to store the common elements.
//         Iterate through nums2.
//         If the current element exists in the hash map and its count is greater than 0, add it to the result list and decrement its count in the hash map.
// Return the result list.
       
        unordered_map<int,int> mp; vector<int> ans;
        
        for(auto i:nums1){
            mp[i]++;
        }
        
        for(auto j:nums2){
            if(mp[j] > 0){
                ans.push_back(j);
                mp[j]--; //decrement its count in the hash map
            }
        }
        return ans;
        
    }
};