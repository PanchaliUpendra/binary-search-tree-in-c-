// Constructing a BINARY SEARCH TREE using array//
/*
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
Node* BuildBST(Node* root,int data)
{
    if(root== NULL) return new Node(data);
    if(root->val>data)
    {
        root->left=BuildBST(root->left,data);
    }
    else{
        root->right=BuildBST(root->right,data);
    }
    return root;
}
void printINorder(Node* root)
{
    if(root==NULL) return;
    printINorder(root->left);
    cout<<root->val<<ends;
    printINorder(root->right);
}
int main()
{
    struct Node* root=new Node(5);
    root=BuildBST(root,1);
    BuildBST(root,3);
    BuildBST(root,4);
    BuildBST(root,2);
    BuildBST(root,7);
    cout<<"printing the binary search tree in an INOrDER: "<<endl;
    printINorder(root);

    return 0;
}
*/
