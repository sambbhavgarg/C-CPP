#include<iostream>
using namespace std;

class BST{
  int value;
  BST *left, *right;
public:
  BST(){
    value = 0;
    left = NULL;
    right = NULL;
  }
  BST(int);
  BST * insert(BST*, int);
  void inorder(BST*);
};

BST :: BST (int value){
  this->value = value;
  left = right = NULL;
}

BST * BST :: insert(BST * root, int value){
  if(root == NULL)
    return new BST(value);
  if(value >= root->value)
    root->right = insert(root->right, value);
  else
    root->left = insert(root->left, value);
  return root;
}

void BST::inorder(BST * root){
  if(!root)
    return;
  inorder(root->left);
  inorder(root->right);
  cout<<root->value<<" ";

}

int main(){
  BST b, * root = NULL;
  root = b.insert(root, 50);
  b.insert(root, 20);
  b.insert(root, 30);
  b.insert(root, 10);
  b.insert(root, 5);
  b.insert(root, 70);
  b.insert(root, 45);

  b.inorder(root);
  return 0;
}
