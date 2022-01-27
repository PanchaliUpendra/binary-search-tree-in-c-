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
Node* constructBST(int preorder[],int* preorderId,int key,int min,int max,int n)
{
    if(*preorderId>=n) return NULL;
    Node* root=NULL;
    if(key>min && key<max){
        root=new Node(key);
        *preorderId+=1;
        if(*preorderId<n){
            root->left=constructBST(preorder, preorderId,preorder[*preorderId],min,key,n);
        }
        if(*preorderId<n){
            root->right=constructBST(preorder, preorderId,preorder[*preorderId],key,max,n);
        }
    }
    return root;
}
void printpreorder(Node* root)
{
    if(!root) return;
    cout<<root->val<<" ";
    printpreorder(root->left);
    printpreorder(root->right);
}
int main()
{
    int preorder[]={10,2,1,14,13};
    int n=5;
    int preorderId=0;
    Node* root=constructBST(preorder,&preorderId,preorder[0],INT_MIN,INT_MAX,n);
    printpreorder(root);

    return 0;
}