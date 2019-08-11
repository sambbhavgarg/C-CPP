#include <iostream>
#include <cstdlib>
using namespace std;
struct allot
{
    int data;
    struct allot *left;
    struct allot *right;
}*root;
class BST
{
    public:
        void find(int, allot **, allot **);
        void insert(allot *, allot *);
        void del(int);
        void case_a(allot *,allot *);
        void case_b(allot *,allot *);
        void case_c(allot *,allot *);
        void preorder(allot *);
        void inorder(allot *);
        void postorder(allot *);
        void display(allot *, int);
        BST()
        {
            root = NULL;
        }
};
/*
 * Main Contains Menu
 */
int main()
{
    int choice, num;
    BST bst;
    allot *temp;
    while (1)
    {
        cout<<"1.Insert Element 2.Delete Element 3.Inorder Traversal 4.Preorder Traversal 5.Postorder Traversal 6.Display"<<endl;
        cout<<"7.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            temp = new allot;
            cout<<"Enter the number to be inserted : ";
	          cin>>temp->data;
            bst.insert(root, temp);break;

        case 2:
            if (root == NULL)
            {
                cout<<"Tree is empty, nothing to delete"<<endl;
                continue;
            }
            cout<<"Enter the number to be deleted : ";
            cin>>num;
            bst.del(num);
            break;
        case 3:
            cout<<"Inorder Traversal of BST:"<<endl;
            bst.inorder(root);
            cout<<endl;
            break;
	case 4:
            cout<<"Preorder Traversal of BST:"<<endl;
            bst.preorder(root);
            cout<<endl;
            break;
        case 5:
            cout<<"Postorder Traversal of BST:"<<endl;
            bst.postorder(root);
            cout<<endl;
            break;
        case 6:
            cout<<"Display BST:"<<endl;
            bst.display(root,1);
            cout<<endl;
            break;
        case 7:
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}


void BST::find(int item, allot **par, allot **loc)
{
    allot *ptr, *ptrsave;
    if (root == NULL)
    {
        *loc = NULL;
        *par = NULL;
        return;
    }
    if (item == root->data)
    {
        *loc = root;
        *par = NULL;
        return;
    }
    if (item < root->data)
        ptr = root->left;
    else
        ptr = root->right;
    ptrsave = root;
    while (ptr != NULL)
    {
        if (item == ptr->data)
        {
            *loc = ptr;
            *par = ptrsave;
            return;
        }
        ptrsave = ptr;
        if (item < ptr->data)
            ptr = ptr->left;
	else
	    ptr = ptr->right;
    }
    *loc = NULL;
    *par = ptrsave;
}


void BST::insert(allot *tree, allot *newnode)
{
    if (root == NULL)
    {
        root = new allot;
        root->data = newnode->data;
        root->left = NULL;
        root->right = NULL;
        cout<<"Root allot is Added"<<endl;
        return;
    }
    if (tree->data == newnode->data)
    {
        cout<<"Element already in the tree"<<endl;
        return;
    }
    if (tree->data > newnode->data)
    {
        if (tree->left != NULL)
        {
            insert(tree->left, newnode);
	}
	else
	{
            tree->left = newnode;
            (tree->left)->left = NULL;
            (tree->left)->right = NULL;
            cout<<"allot Added To Left"<<endl;
            return;
        }
    }
    else
    {
        if (tree->right != NULL)
        {
            insert(tree->right, newnode);
        }
        else
        {
            tree->right = newnode;
            (tree->right)->left = NULL;
            (tree->right)->right = NULL;
            cout<<"allot Added To Right"<<endl;
            return;
        }
    }
}

void BST::del(int item)
{
    allot *parent, *location;
    if (root == NULL)
    {
        cout<<"Tree empty"<<endl;
        return;
    }
    find(item, &parent, &location);
    if (location == NULL)
    {
        cout<<"Item not present in tree"<<endl;
        return;
    }
    if (location->left == NULL && location->right == NULL)
        case_a(parent, location);
    if (location->left != NULL && location->right == NULL)
        case_b(parent, location);
    if (location->left == NULL && location->right != NULL)
        case_b(parent, location);
    if (location->left != NULL && location->right != NULL)
        case_c(parent, location);
    free(location);
}


void BST::case_a(allot *par, allot *loc )
{
    if (par == NULL)
    {
        root = NULL;
    }
    else
    {
        if (loc == par->left)
            par->left = NULL;
        else
            par->right = NULL;
    }
}


void BST::case_b(allot *par, allot *loc)
{
    allot *child;
    if (loc->left != NULL)
        child = loc->left;
    else
        child = loc->right;
    if (par == NULL)
    {
        root = child;
    }
    else
    {
        if (loc == par->left)
            par->left = child;
        else
            par->right = child;
    }
}


void BST::case_c(allot *par, allot *loc)
{
    allot *ptr, *ptrsave, *suc, *parsuc;
    ptrsave = loc;
    ptr = loc->right;
    while (ptr->left != NULL)
    {
        ptrsave = ptr;
        ptr = ptr->left;
    }
    suc = ptr;
    parsuc = ptrsave;
    if (suc->left == NULL && suc->right == NULL)
        case_a(parsuc, suc);
    else
        case_b(parsuc, suc);
    if (par == NULL)
    {
        root = suc;
    }
    else
    {
        if (loc == par->left)
            par->left = suc;
        else
            par->right = suc;
    }
    suc->left = loc->left;
    suc->right = loc->right;
}


void BST::preorder(allot *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        cout<<ptr->data<<"  ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void BST::inorder(allot *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        inorder(ptr->left);
        cout<<ptr->data<<"  ";
        inorder(ptr->right);
    }
}


void BST::postorder(allot *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->data<<"  ";
    }
}


void BST::display(allot *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
	}
        cout<<ptr->data;
        display(ptr->left, level+1);
    }
}

