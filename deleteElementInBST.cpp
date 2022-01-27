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
Node* Inordersucc(Node* root)
{
    Node* curr=root;
    while(curr && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
Node* DeleteNode(Node* root,int key)
{
    if(root==NULL) return NULL;
    if(key<root->val)
    {
        root->left=DeleteNode(root->left,key);
    }
    else if(key>root->val)
    {
        root->right=DeleteNode(root->right,key);
    }
    else{
        if(root->left==NULL)
        {
            Node* temp= root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            Node* temp=root->left;
            free(root);
            return temp;
        }
        else{
            Node* temp=Inordersucc(root->right);
            root->val=temp->val;
            root->right=DeleteNode(root->right,temp->val);
        }
        
    }
    return root;
}
void printInorder(Node* root)
{
    if(!root) return;
    printInorder(root->left);
    cout<<root->val<<" ";
    printInorder(root->right);
}
int main()
{
    struct Node* root=new Node(3);
    root->left=new Node(2);
    root->left->left=new Node(1);
    root->right=new Node(5);
    root->right->left=new Node(4);
    root->right->right=new Node(6);
    printInorder(root);
    root=DeleteNode(root,5);
    cout<<endl;
    printInorder(root);
    return 0;
}