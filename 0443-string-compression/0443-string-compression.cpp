class Solution {
public:
    int compress(vector<char>& chars) {
        
       int count = 1;
        string str="";
        if(chars.size() == 1) return 1;
        
        for(int i = 0; i< chars.size() - 1;i++){
            if(chars[i] == chars[i+1]){
                count++;
            }
            else{
                str += chars[i];
                
                if(count > 1){
                    str += to_string(count);
                }
                count = 1;
            }
        }
        
        if(count > 1){
            str += chars[chars.size() - 1];
            str += to_string(count);
        }
        else{
            str+=chars[chars.size() -1];
        }
         int j = 0;
        for (int i = 0; j < str.size(); i++) {
            chars[i] = str[j];
            j++;
        }
    
        
        return str.size();
    }
};