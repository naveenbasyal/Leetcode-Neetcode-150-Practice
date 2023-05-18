class Solution {
public:
    string removeStars(string s) {
        
        stack<char> st;
        int countstar =0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '*'){
                st.push(s[i]);
            }
            else if(s[i] == '*'){
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
        
    }
};