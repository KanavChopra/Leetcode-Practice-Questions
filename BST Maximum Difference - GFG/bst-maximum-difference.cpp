//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
    Node* findNode(Node *root, int target) {
        if (!root || root -> data == target) {
            return root;   
        }
        if (root -> data > target) {
            return findNode(root -> left, target);
        }
        return findNode(root -> right, target);
    }
    int sum(Node *root, int target) {
        if (!root) {
            return 0;
        }
        if (root -> data == target) {
            return root -> data;
        }
        if (root -> data > target) {
            return root -> data + sum(root -> left, target);
        }
        return root -> data + sum(root -> right, target);
    }
    int findMinSum(Node *node) {
        if (!node) {
            return 0;
        }
        if (!node -> left && !node -> right) {
            return node -> data;
        }
        if (!node -> left) {
            return node -> data + findMinSum(node -> right);
        }
        if (!node -> right) {
            return node -> data + findMinSum(node -> left);
        }
        return node -> data + min(findMinSum(node -> left), findMinSum(node -> right));
    }
public:
    int maxDifferenceBST(Node *root,int target) {
        Node *node = findNode(root, target);
        if (node == NULL) {
            return -1;
        }
        int sum1 = sum(root, node -> data) - node -> data;
        int sum2 = findMinSum(node) - node -> data;
        return sum1 - sum2;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends