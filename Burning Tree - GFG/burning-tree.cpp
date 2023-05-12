//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    
    Node* createMapping(Node* root , map<Node*,Node*> &nodeToParent , int target){
        queue<Node*> q;
        q.push(root);
        
        nodeToParent[root] = NULL;
        Node* targetNode = NULL;
        
        while(!q.empty()){
            Node* curr = q.front();  
            q.pop();
            if(curr->data == target){
                targetNode = curr;
            } 
            if(curr->left){
              nodeToParent[curr->left] = curr;  
              q.push(curr->left);
            }
            if(curr->right){
                nodeToParent[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return targetNode;
    }
    
    void burnTree(Node* targetNode , map<Node*,bool> &visited ,map<Node*,Node*> &nodeToParent , int &time){
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;
        
        while(!q.empty()){
            bool changes = false;
            int size = q.size();
            while(size--){
                Node* curr = q.front();
                q.pop();
                if(curr->left and !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                    changes = true;
                }
                if(curr->right and !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                    changes = true;
                }
                if(nodeToParent[curr] and !visited[nodeToParent[curr]]) {
                    q.push(nodeToParent[curr]);
                    visited[nodeToParent[curr]] = true;
                    changes = true;
                }
            }
            if(changes == true){
                time++;
            }
        }
    }
  
    int minTime(Node* root, int target) 
    {
        // step1: create mapping of nodetoparent
        // step2: go to target node
        // step3: mark visited nodes and burn the tree
        map<Node*, Node*> nodeToParent;
        map<Node*,bool> visited;
        Node* targetNode = createMapping(root , nodeToParent , target);
        int time;
        burnTree(targetNode , visited , nodeToParent , time);
        return time;
    }
};






//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends