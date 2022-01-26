#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int value)
    {
        val=value;
        left=NULL;
        right=NULL;
    }
};
Node* searchINBST(Node* root,int key)
{
    if(root==NULL) return NULL;
    if(root->val==key) return root;
    if(root->val > key)
    {
        return searchINBST(root->left,key);
    }
    return searchINBST(root->right,key);
}
int main()
{
    struct Node* root=new Node(5);
    root->left=new Node(1);
    root->right=new Node(7);
    root->left->right=new Node(3);
    root->left->right->left=new Node(2);
    root->left->right->right=new Node(4);
    if(searchINBST(root,10)==NULL)
    {
        cout<<"the key doesn't exist in BST\n";
    }
    else{
        cout<<"the key exist's\n";
    }

    return 0;
}