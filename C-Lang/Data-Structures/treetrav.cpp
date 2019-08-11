#include<iostream>
using namespace std;
struct node{
  int data;
  struct node *left;
  struct node *right;
};
struct node*newNode(int data){
  struct node* temp=new node;
  temp->data=data;
  temp->left=temp->right=NULL;
  return temp;
}
class empty{}
struct node * constructTreeUtil(int pre[],int *preIndex, int low, int high, int size){
  if(*preIndex>=size || low>high)
    return NULL;
  struct node* root=newNode(pre[*preIndex]);
  *preIndex=*preIndex+1;
  if(low==high)
    return root;
  int i;
  for(int i=low;i<=high;++i)
    if(pre[i]>root->data)
      break;
  root->left=constructTreeUtil(pre,preIndex,*preIndex,i-1,size);
  root->right=constructTreeUtil(pre,preIndex,i,high,size);
  return root;
}
struct node *constructTree(int pre[],int size){
  int preIndex=0;
  return constructTreeUtil(pre,&preIndex,0,size-1,size);
}
void printInorder(struct node *node){
  if(node==NULL)
    return;
  printInorder(node->left);
  cout<<node->data<<"\t";
  printInorder(node->right);
}
int main(){
  node n1;
    int pre[] = {10, 5, 1, 7, 40, 50};
  int size=sizeof(pre)/sizeof(pre[0]);
  struct node *root=constructTree(pre,size);
  cout<<"Inorder traversel of the constructed tree:\n";
  printInorder(root);
  return 0;
}
