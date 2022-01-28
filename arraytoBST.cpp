
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
Node* buildBST(Node* root,int l,int r,int arr[])
{
    if(l<=r)
    {
        int mid=l+(r-l)/2;
        root=new Node(arr[mid]);
        root->left=buildBST(root->left,l,mid-1,arr);
        root->right=buildBST(root->right,mid+1,r,arr);
        return root;
    }
    return NULL;
}
void printINorder(Node* root)
{
    if(root==NULL) return;
    printINorder(root->left);
    cout<<root->val<<" ";
    printINorder(root->right);
}
int main()
{
    int vect[]={1,2,3,4,5,6};
    int l=0;
    int r=5;
    struct Node* root=NULL;
    root=buildBST(root,l,r,vect);
    printINorder(root);

    return 0;
}
