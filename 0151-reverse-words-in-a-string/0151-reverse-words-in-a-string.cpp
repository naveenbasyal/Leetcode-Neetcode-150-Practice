class Solution {
public:
    string reverseWords(string s) {
        int i=0;
       while(s[i] == ' '){
           i++;
       }
        stack<string> st;
        string str = "";
        while(i < s.size()){
            if(s[i] == ' '){
                if(!str.empty()){
                st.push(str);
                str = "";
                    
                }
            }
            else{
                str += s[i];
            }
            i++;
        }
        if(!str.empty()){
            st.push(str);
        }
        str = "";
        while(st.size() > 1){
            str += st.top() + " ";
            st.pop();
        }
        str += st.top();
        st.pop();
        return str;
        
    }
};