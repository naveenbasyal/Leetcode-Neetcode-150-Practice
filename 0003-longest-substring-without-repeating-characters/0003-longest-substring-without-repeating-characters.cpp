class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int start = 0, end = 0 , len = 0;
        set<int> st;
        while(end < s.size()){
            
            if(st.find(s[end]) == st.end()){
                
                st.insert(s[end]);
                end++;
                len = max(len, end - start);
                
            }
            else {
                st.erase(s[start]);
                start++;
            }
        }
        return len;
    }
};