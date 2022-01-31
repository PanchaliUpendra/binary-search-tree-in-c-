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

struct info{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

info largestBSTinBT(Node* root)
{
    if(root== NULL){
        return {0,INT_MIN,INT_MAX,0,true};
    }
    if(root->left==NULL && root->right==NULL){
        return {1,root->val,root->val,1,true};
    }

    info leftinfo= largestBSTinBT(root->left);
    info rightinfo = largestBSTinBT(root->right);

    info curr;
    curr.size =(1+leftinfo.size + rightinfo.size);

    if(leftinfo.isBST && rightinfo.isBST && leftinfo.max<root->val && rightinfo.min > root->val ){
        curr.min=min(leftinfo.min, min(rightinfo.min,root->val));
        curr.max=max(rightinfo.max,max(leftinfo.max,root->val));

        curr.ans=curr.size;
        curr.isBST=true;

        return curr;
    }

    curr.ans=max(leftinfo.ans,rightinfo.ans);
    curr.isBST=false;
    return curr;


}

int main()
{
     Node* root=new Node(15);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(5);

    cout<<"Largest BST in BT : "<<largestBSTinBT(root).ans<<endl;
    return 0;
}