#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#define pow2(n) (1 << (n))
using namespace std;

struct nodeAVL
{
    int data;
    struct nodeAVL *left;
    struct nodeAVL *right;
}*root;

class avlTree
{
    public:
        int height(nodeAVL *);
        int diff(nodeAVL *);
        nodeAVL *rr_rotation(nodeAVL *);
        nodeAVL *ll_rotation(nodeAVL *);
        nodeAVL *lr_rotation(nodeAVL *);
        nodeAVL *rl_rotation(nodeAVL *);
        nodeAVL* balance(nodeAVL *);
        nodeAVL* insert(nodeAVL *, int );
        void display(nodeAVL *, int);
        void inorder(nodeAVL *);
        void preorder(nodeAVL *);
        void postorder(nodeAVL *);
        avlTree()
        {
            root = NULL;
        }
};

int main()
{
    int choice, item;
    avlTree avl;
    while (1)
    {
        cout<<"\n---------------------"<<endl;
        cout<<"AVL Tree Implementation"<<endl;
        cout<<"\n---------------------"<<endl;
        cout<<"1.Insert Element into the tree"<<endl;
        cout<<"2.Display Balanced AVL Tree"<<endl;
        cout<<"3.InOrder traversal"<<endl;
        cout<<"4.PreOrder traversal"<<endl;
        cout<<"5.PostOrder traversal"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter value to be inserted: ";
            cin>>item;
            root = avl.insert(root, item);
            break;
        case 2:
            if (root == NULL)
            {
                cout<<"Tree is Empty"<<endl;
                continue;
            }
            cout<<"Balanced AVL Tree:"<<endl;
            avl.display(root, 1);
            break;
        case 3:
            cout<<"Inorder Traversal:"<<endl;
            avl.inorder(root);
            cout<<endl;
            break;
        case 4:
            cout<<"Preorder Traversal:"<<endl;
            avl.preorder(root);
            cout<<endl;
            break;
        case 5:
            cout<<"Postorder Traversal:"<<endl;
            avl.postorder(root);
            cout<<endl;
            break;
        case 6:
            exit(1);
            break;
        default:
            cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;
}

int avlTree::height(nodeAVL *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

int avlTree::diff(nodeAVL *temp)
{
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}

nodeAVL *avlTree::rr_rotation(nodeAVL *parent)
{
    nodeAVL *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

nodeAVL *avlTree::ll_rotation(nodeAVL *parent)
{
    nodeAVL *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}


nodeAVL *avlTree::lr_rotation(nodeAVL *parent)
{
    nodeAVL *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}


nodeAVL *avlTree::rl_rotation(nodeAVL *parent)
{
    nodeAVL *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}


nodeAVL *avlTree::balance(nodeAVL *temp)
{
    int bal_factor = diff (temp);
    if (bal_factor > 1)
    {
        if (diff (temp->left) > 0)
            temp = ll_rotation (temp);
        else
            temp = lr_rotation (temp);
    }
    else if (bal_factor < -1)
    {
        if (diff (temp->right) > 0)
            temp = rl_rotation (temp);
        else
            temp = rr_rotation (temp);
    }
    return temp;
}


nodeAVL *avlTree::insert(nodeAVL *root, int value)
{
    if (root == NULL)
    {
        root = new nodeAVL;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
        root = balance (root);
    }
    else if (value >= root->data)
    {
        root->right = insert(root->right, value);
        root = balance (root);
    }
    return root;
}

void avlTree::display(nodeAVL *ptr, int level)
{
    int i;
    if (ptr!=NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");
        if (ptr == root)
        cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout<<ptr->data;
        display(ptr->left, level + 1);
    }
}


void avlTree::inorder(nodeAVL *tree)
{
    if (tree == NULL)
        return;
    inorder (tree->left);
    cout<<tree->data<<"  ";
    inorder (tree->right);
}

void avlTree::preorder(nodeAVL *tree)
{
    if (tree == NULL)
        return;
    cout<<tree->data<<"  ";
    preorder (tree->left);
    preorder (tree->right);

}


void avlTree::postorder(nodeAVL *tree)
{
    if (tree == NULL)
        return;
    postorder ( tree ->left );
    postorder ( tree ->right );
    cout<<tree->data<<"  ";
}
