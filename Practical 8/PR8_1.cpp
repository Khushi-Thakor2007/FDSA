#include<iostream>
#include<queue>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int value):data(value),left(nullptr),right(nullptr){}
};
Node* buildTree()
{
    int value;
    cin>>value;
    if(value==-1)return nullptr;
    Node* root=new Node(value);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
void inorder(Node* root)
{
    if(!root)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node* root)
{
    if(!root)return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root)
{
    if(!root)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void levelOrder(Node* root)
{
    if(!root)return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* current=q.front();
        q.pop();
        cout<<current->data<<" ";
        if(current->left)q.push(current->left);
        if(current->right)q.push(current->right);
    }
}
int main()
{
    cout<<"Enter tree nodes in preorder (-1 for no node): ";
    Node* root=buildTree();
    cout<<"Inorder: ";
    inorder(root);
    cout<<"\nPreorder: ";
    preorder(root);
    cout<<"\nPostorder: ";
    postorder(root);
    cout<<"\nLevel order: ";
    levelOrder(root);
    cout<<"\n";
    return 0;
}