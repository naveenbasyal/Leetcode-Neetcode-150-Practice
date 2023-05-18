class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;
        
        for(auto i:asteroids){
            if(i > 0 or st.empty()){
                st.push(i);
            }
            else{
                
                while(!st.empty() and st.top() > 0 and st.top() < abs(i)){
                    st.pop();
                }
                if(!st.empty() and st.top() == abs(i)){
                    st.pop();      
                } 
                else if(st.empty() or st.top() < 0){
                    
                    st.push(i);
                }
            }
        }
        vector<int> ans(st.size());
        
        for(int i = ans.size() - 1; i >=0; i--){
            ans[i] = st.top();
            st.pop();
        }
       
        return ans;
    }
};