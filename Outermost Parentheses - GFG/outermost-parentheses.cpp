//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        // code here
        int count = 0; string ans ="";
        for(auto i: s){
            if(i == '('){
                if(count > 0){
                    ans += i;
                }
                count++;
            }
            else{
                if(count >1){
                    ans += i;
                }
                count--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends