class Solution {
public:
    bool isValid(string s) {
        
         stack<char> st;
        for(char c : s){
            if(c == '('|| c == '{' || c == '['){
                st.push(c);
            }else{
                if(st.empty() or (c == ']' and st.top() != '[') or
                   (c == '}' and st.top() != '{') or (c == ')' and st.top() != '(')){
                    return false;
                }        
                st.pop();
            }
        }
        return st.empty();
    }
};