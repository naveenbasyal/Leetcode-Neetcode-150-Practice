class Solution {
public:
    string reverseVowels(string s) {
        vector<pair<char,int>> vowels;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                vowels.push_back(make_pair(s[i],i));
            }
        }
        if(vowels.size() > 0){
            int i = 0 , j = vowels.size() - 1;
            while(i <= j){
                char temp = vowels[i].first;
                vowels[i].first = vowels[j].first;
                vowels[j].first = temp;
                i++,j--;
            }
        }
        else{
            return s;
        }
        for(auto i:vowels){
            s[i.second] = i.first;
        }
        return s;
        
    }
};