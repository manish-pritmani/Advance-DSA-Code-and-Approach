#include <iostream>
#include <fstream>
#include <queue>
// utility is used to form pair<node*,int>
#include<utility>

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
// Time complexity = O(n2)
void levelOrder(node* root,int hTree){
  for(int i=0;i<=hTree;i++){
    kthLevel(root,i);
    cout<<endl;
  }
}

// BFS using queue - Level order traversal
void bfs(node* root){
  queue<node*> q;
  q.push(root);
  while(!q.empty()){
    node* front = q.front();
    cout<<front->data<<" ";
    q.pop();
    if(front->left){
      q.push(front->left);
    }
    if(front->right){
      q.push(front->right);
    }
  }
}

// Approach 1 - BFS using queue - Level order printing
void bfsApproach1(node* root){
  queue<pair<node*,int>> q;
  q.push(make_pair(root,1));
  while(!q.empty()){
    node* front = q.front().first;
    int currentLevel = q.front().second;
    cout<<front->data<<" ";
    q.pop();
    if(q.front().second>currentLevel || q.empty()){
      cout<<endl;
    }
    if(front->left){
      q.push(make_pair(front->left,currentLevel+1));
    }
    if(front->right){
      q.push(make_pair(front->right,currentLevel+1));
    }
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
  cout<<endl;
  cout<<"BFS : ";
  bfsApproach1(root);





  return 0;
}
