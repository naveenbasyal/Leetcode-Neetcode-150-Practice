class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /* Intuition:
                Create two pointers, "start" and "end", initially set to 0.
                Use a hash set to store the characters in the current substring.
                While "end" is less than the length of the string:
                a. If the character at "end" is not in the hash set, add it and
                     move the "end" pointer to the right.
                b. If the character at "end" is already in the hash set, remove the
                    character at "start" from the hash set and move the "start" pointer to the right.
                c. The length of the longest substring is the maximum distance between the 
                    "start" and "end" pointers.       
        */
        int start = 0, end = 0 , len = 0;
        set<char> st;
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