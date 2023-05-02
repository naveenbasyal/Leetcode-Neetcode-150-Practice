class Solution {
public:
    bool isPalindrome(string s) {
        stack<char> st;
        for(auto i:s){
            if(isalnum(i)){
                st.push(tolower(i));
            }
        }
        for(auto i:s){
            
            if(isalnum(i)){
                
                if(st.top()== tolower(i)){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};