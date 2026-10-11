#include<iostream>
using namespace std;
struct Node
{
    int code;
    Node* left;
    Node* right;
    Node(int value):code(value),left(nullptr),right(nullptr){}
};
Node* insert(Node* root,int code)
{
    if(!root)return new Node(code);
    if(code<root->code)root->left=insert(root->left,code);
    else if(code>root->code)root->right=insert(root->right,code);
    return root;
}
void inorder(Node* root)
{
    if(!root)return;
    inorder(root->left);
    cout<<root->code<<" ";
    inorder(root->right);
}
int main()
{
    int n,code;
    cout<<"Enter number of elements in BST: ";
    cin>>n;
    Node* root=nullptr;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>code;
        root=insert(root,code);
    }
    cout<<"BST elements in sorted order: ";
    inorder(root);
    cout<<"\n";
    return 0;
}