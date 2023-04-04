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
       
        int i = 0  , j = 0 , len = 0;
        
        set<char> st;
        
        while( j < s.size()){
            
            if(st.find(s[j]) == st.end()){
                st.insert(s[j]);
                j++;
                len = max(len, j - i);
                
            }
            else{
                st.erase(s[i]);
                i++;
            }
        }
        return len;
    }
};