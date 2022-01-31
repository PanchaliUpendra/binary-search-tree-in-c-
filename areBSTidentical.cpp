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
bool isIdentical(Node* root1,Node* root2)
{
    if(root1==NULL && root2==NULL){
        return true;
    }
    else if(root1==NULL || root2==NULL)
    {
        return false;
    }
    else{
        bool cond1=(root1->val==root2->val);
        bool cond2=isIdentical(root1->left,root2->left);
        bool cond3=isIdentical(root1->right,root2->right);
        if(cond1 && cond2 && cond3)
        {
            return true;
        }
        return false;

    }
}
int main()
{
    struct Node* root=new Node(2);
    root->left=new Node(1);
    root->right=new Node(3);
    if(isIdentical(root,root))
    {
        cout<<"the given are Identical"<<endl;
    }
    else{
        cout<<"Not Identical"<<endl;
    }
    return 0;
}