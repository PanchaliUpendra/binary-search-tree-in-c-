#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int value)
    {
        data=value;
        left=NULL;
        right=NULL;
    }
};
bool isBST(Node* root,Node* min=NULL,Node* max=NULL)
{
    if(root==NULL) return true;
    if(min!=NULL && root->data<=min->data) return false;
    if(max!=NULL && root->data>=max->data) return false;
    bool leftvalid=isBST(root->left,min,root);
    bool rightvalid=isBST(root->right,root,max);
    return (leftvalid and rightvalid);
}
int main()
{
    struct Node* root= new Node(3);
    root->left=new Node(2);
    root->right=new Node(5);
    root->left->left=new Node(1);
    root->right->left=new Node(4);
    root->right->right=new Node(6);
    if(isBST(root,NULL,NULL)){
        cout<<"valid BST"<<endl;
    }
    else{
        cout<<"not valid BST"<<endl;
    }
    return 0;
}