#include<bits/stdc++.h>
using namespace std;
struct node
{
    node* left;
    int data;
    node* right;
};
struct node* root=NULL;
struct node* f=NULL;
struct node* createnode(int x)
{
    node* temp = new node();
    temp->left=NULL;
    temp->data=x;
    temp->right=NULL;
    return temp;
};
node* insertnode(node* root,int x)
{
    if(root==NULL)
    {
        root=createnode(x);

    }
    else if(x <= root->data)
    {
        root->left=insertnode(root->left,x);
    }
    else if(x > root->data)
        root->right=insertnode(root->right,x);
    return root;
}

int searchnode(node* root,int x )
{
    if(root==NULL)
        return false;

    else if(root->data==x)
        return true;
    else if(x <= root->data)
    {
        searchnode(root->left,x);
    }
    else if(x>root->data)
        searchnode(root->right,x);

}
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int findmax(node* root)
{
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root->data;
}
int findmin(node* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root->data;
}
int main()
{
    while(1)
    {   int c,n;
        cout<<"1. Insert\n";
        cout<<"2. Search\n";
        cout<<"3. Print\n";
        cout<<"4. Find Max\n";
        cout<<"5. Find Min\n";
        cout<<"6. Exit\n";
        cin>>c;
        if(c==1)
        {
            cout<<"Enter the element to be inserted\n";
            cin>>n;
            root=insertnode(root,n);
        }
        if(c==2)
        {
            cout<<"Enter the element to be searched\n";
            cin>>n;
            if(searchnode(root,n))
                cout<<"Found\n";
            else
                cout<<"Not found\n";

        }
        if(c==3)
        {
            inorder(root);
            cout<<endl;
        }
        if(c==4)
            cout<<findmax(root)<<endl;
        if(c==5)
            cout<<findmin(root)<<endl;
        if(c==6)
            exit(0);

    }
}
