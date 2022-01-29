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
void zigzag(Node* root)
{
    if(!root) return ;
    stack<Node*> curr_level;
    stack<Node*>next_level;
    bool LeftToRight=true;
    curr_level.push(root);
    while(!curr_level.empty())
    {
        Node* temp=curr_level.top();
        curr_level.pop();
        if(temp)
        {
            cout<<temp->val<<" ";
            if(LeftToRight)
            {
                if(temp->left) next_level.push(temp->left);
                if(temp->right) next_level.push(temp->right);
            }
            else{
                if(temp->right) next_level.push(temp->right);
                if(temp->left) next_level.push(temp->left);
            }
        }
        if(curr_level.empty()){
            LeftToRight = !LeftToRight;
            swap(curr_level,next_level);
        }


    }
}
int main()
{
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(4);
    root->right->right=new Node(5);
    root->left->right->left=new Node(6);
    root->left->right->right=new Node(7);
    zigzag(root);
    return 0;
}