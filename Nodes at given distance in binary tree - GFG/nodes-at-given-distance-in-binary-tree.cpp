//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
 
//  A binary Tree node
// struct Node
// {
//     int data;
//     struct Node *left, *right;
// };


class Solution
{


public:

    Node* createMapping(Node* root , unordered_map<Node*,Node*> &nodeToParent , int target){
        if(root == NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        Node* targetNode = NULL;
        nodeToParent[root] = NULL;
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                Node* curr = q.front();
                q.pop();
                if(curr->data == target){
                  targetNode = curr;  
                } 
                if(curr->left){
                    q.push(curr->left);
                    nodeToParent[curr->left] = curr;
                }
                if(curr->right){
                    q.push(curr->right);
                    nodeToParent[curr->right] = curr;
                }
            }
        }
        return targetNode;
    }
    
    void findNodes(Node* targetNode,unordered_map<Node*,bool> &visited,unordered_map<Node*,Node*> &nodeToParent,vector<int> &ans , int k){
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;
        while(!q.empty() and k > 0){
            int size = q.size();
            while(size--){
                Node* curr = q.front();
                q.pop();
                if(curr->left and !visited[curr->left]){
                    q.push(curr->left);
                     visited[curr->left] = true;
                }
                if(curr->right and !visited[curr->right]){
                    q.push(curr->right);
                     visited[curr->right] = true;
                }
                if(nodeToParent[curr] and !visited[nodeToParent[curr]]){
                    q.push(nodeToParent[curr]);
                     visited[nodeToParent[curr]] = true;
                }
                // visited[curr] = true;
            }
            k--;
        }
        while(!q.empty()){
            ans.push_back(q.front()->data);
            q.pop(); 
        }
        sort(ans.begin(),ans.end());
        
    }
    
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        vector<int> ans;
        if(root == NULL) return ans;
        unordered_map<Node*,Node*> nodeToParent;
        unordered_map<Node*,bool> visited;

        Node* targetNode = createMapping(root ,nodeToParent, target);
        findNodes(targetNode, visited , nodeToParent , ans, k);
        
        return ans;
    }
};











//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends