#include <iostream>
#include <fstream>
using namespace std;

//tree structure
class node{
  public:
    int data;
    node* left;
    node* right;

  //constructor for tree node
  node(int data){
    this->data=data;
    left = nullptr;
    right = nullptr;
  }
};

// build tree
node* buildTree(){
  int d;
  cin>>d;
  if(d==-1){
    return nullptr;
  }

  node* root = new node(d);
  root->left = buildTree();
  root->right = buildTree();
  return root;
}

// Pre order traversal ROOT LEFT RIGHT
void printTree(node* root){
  if(root == nullptr){
    return;
  }
  cout<<root->data<<" ";
  printTree(root->left);
  printTree(root->right);
}

// post order traversal of the tree LEFT RIGHT ROOT
void postOrder(node* root){
  if(root==nullptr){
    return;
  }
  postOrder(root->left);
  postOrder(root->right);
  cout<<root->data<<" ";
}

// Inorder traversal of the tree
void inOrder(node* root){
  if(root==nullptr){
    return;
  }
  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
}

int height(node* root){
  if(root==nullptr){
    return 0;
  }
  return 1+max(height(root->left),height(root->right));
}

// print kth level
void kthLevel(node* root,int k){
  if(root==nullptr){
    return;
  }
  if(k==1){
    cout<<root->data<<" ";
    return;
  }
  kthLevel(root->left,k-1);
  kthLevel(root->right,k-1);
}

// recursive level order without queue
// level order = kth level print + height of tree concept.
void levelOrder(node* root,int hTree){
  for(int i=0;i<=hTree;i++){
    kthLevel(root,i);
    cout<<endl;
  }
}


int main(){
  int hTree = 0;
// level integer
  int k=3;
  
  // 3 4 -1 6 -1 -1 5 1 -1 -1 -1
  node* root = buildTree();
  // pre order traversal
  printTree(root);
  cout<<endl;
  // post order traversal
  postOrder(root);
  cout<<endl;
  // Inorder traversal
  inOrder(root);
  cout<<endl;
  hTree = height(root);
  cout<<"Height: "<<hTree;
  cout<<endl;
  kthLevel(root,k);
  cout<<endl;
  cout<<"Level Order";
  levelOrder(root,hTree);
}
