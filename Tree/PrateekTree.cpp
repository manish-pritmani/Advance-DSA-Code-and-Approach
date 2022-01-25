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

// Height of the tree.
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
// pair of node with it's level.
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

// BFS approach level order traversal with NULL conditions
void bfsApp2(node* root){
  queue<node*> q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()){
    if(q.front()== NULL){
      cout<<endl;
      q.pop();
      if(!q.empty()){
        q.push(NULL);
      }
      continue;
    }
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

// countNodes complexity - O(N) as visiting every node
int countNodes(node* root){
  if(root == nullptr){
    return 0;
  }
  int leftCount = countNodes(root->left);
  int rightCount = countNodes(root->right);
  return 1+leftCount+rightCount;
}

// Sum of all nodes values
int sumAllNode(node* root){
  if(root == nullptr){
    return 0;
  }
  return root->data + sumAllNode(root->left)+sumAllNode(root->right);
}

// Sum of all nodes values
int sumInAll(node* root,int sum){
  if(root==nullptr){
    sum = 0;
    return sum;
  }
  sum+=root->data+sumInAll(root->left,root->data)+sumInAll(root->right,root->data);
}

// program to find diameter of tree.
// Time complexity - O(n*n)
int diameterTree(node* root){
  if(root == nullptr){
    return 0;
  }
  int h1 = height(root->left);
  int h2 = height(root->right);
  int dia = h1+h2;
  return max(dia,max(diameterTree(root->left),diameterTree(root->right)));
}

// Diameter of tree in O(n)
pair<int,int> diameterTreeBetter(node* root){
  pair<int,int> p;
  // first -> height
  // second -> diameter
  if(root == nullptr){
    p.first = 0;
    p.second = 0;
    return p;
  }
  pair<int,int> left = diameterTreeBetter(root->left);
  pair<int,int> right = diameterTreeBetter(root->right);
  p.first = max(left.first,right.first)+1;
  p.second = max(left.first+right.first,max(left.second,right.second));
  return p;
}

// Problem - Change node value to sum of values of all it's decendants
int sumAllNodeChange(node* root){
  if(root==nullptr)
    return 0;
  if(root->left == nullptr && root->right == nullptr)
    return root->data;
  int temp = root->data;
  root->data = sumAllNodeChange(root->left)+sumAllNodeChange(root->right);
  return root->data + temp;
}

// TODO: DRY RUN 
// Invert a Binary Tree
node* invertTree(node* root){
  if(root == nullptr){
    return nullptr;
  }  
  node* right = invertTree(root->right);
  node* left = invertTree(root->left);
  root->left = right;
  root->right = left;
  return root;
}

// To check if tree is balanced or not.
// pair.first = height, pair.second = boolean for balance check.
pair<int,bool> isBalanced(node* root){
  pair<int,bool> p;
  // Base case
  if(root == nullptr){
    p.first = 0;
    p.second = true;
    return p;
  }
  // Recursive Case
  pair<int,bool> left = isBalanced(root->left);
  pair<int,bool> right = isBalanced(root->right);

  // current node info updation.
  p.first = max(left.first,right.first)+1;
  // current node balance info updation.
  if(abs(left.first - right.first)<=1 && left.second && right.second){
    p.second = true;
  }else{
    p.second = false;
  }
  return p;
}

// given array build a tree from it.

node* buildArrayTree(int *arr,int start, int end){
  if(start>end){
    return NULL;
  }
  int mid = (start + end)/2;
  node* root = new node(arr[mid]);
  root->left = buildArrayTree(arr,start,mid-1);
  root->right = buildArrayTree(arr,mid+1,end);
  return root;
}

// Create tree from In-order and Pre-order traversals.
node* createFromInPre(int* in,int* pre,int start,int end){
  static int i = 0;
  if(start>end){
    return NULL;
  }
  node* root = new node(pre[i]);
  int index = 0;
  for(int j=start;j<=end;j++){
    if(in[j] == pre[i]){
      index = j;
      break;
    }
  }
  i=i+1;
  root->left = createFromInPre(in,pre,start,index-1);
  root->right = createFromInPre(in,pre,index+1,end);
  return root;
}

// Main Function
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
  // cout<<"Level Order";
  // levelOrder(root,hTree);
  cout<<endl;
  cout<<"BFS : "<<endl;
  bfsApp2(root);
  cout<<endl;
  cout<<"Number of nodes : "<<countNodes(root)<<endl;
  // cout<<"Sum of all nodes : "<<sumAllNode(root)<<endl;
  // cout<<"Sum of all nodes : "<<sumInAll(root,0)<<endl;
  // cout<<"Diameter of Tree : "<<diameterTree(root)<<endl;
  // cout<<"Height Better : "<<diameterTreeBetter(root).first<<endl;
  // cout<<"Diameter Better : "<<diameterTreeBetter(root).second<<endl;
  // sumAllNodeChange(root);

  // invert of binary tree
  // invertTree(root);
  
  // optimised level order traversal with new line each level
  bfsApp2(root);
  cout<<endl;
  // check if tree is balanced or not
  if(isBalanced(root).second){
    cout<<"Balanced Tree";
  }else{
    cout<<"Not Balanced"<<endl;
  }
  
// forming height balance binary tree.
  int arr[]={1,2,3,4,5,6,7};
  int n = 7;
  
  node* fRoot = buildArrayTree(arr,0,n-1);
  bfsApp2(fRoot);
  cout<<endl;
  int pre[] = {1,2,3,4,8,5,6,7};
  int in[] = {3,2,8,4,1,6,7,5};
  int size = sizeof(in)/sizeof(int);
  
  node* cRoot = createFromInPre(in,pre,0,size-1);
  bfsApp2(cRoot);
  return 0;
}

/* Notes Center -
 1. Balance tree always has height of O(log(n))
 2. Skew tree is like linked list with single chain of nodes.
*/