#include<bits/stdc++.h>
using namespace std;


struct tree{
    struct node{
        int data;
        node* left;
        node* right;
    };
     node* root;

    tree() {
        root = new node;
        root->data = 1;
        root->left = NULL;
        root->right = NULL;
    }
    

    void add(int parent_data, int child_data, char direction) {
        node* parent = findNode(root, parent_data);
        
        if (parent == NULL) {
            cout << "Parent not found!" << endl;
            return;
        }

        node* newNode = new node;
        newNode->data = child_data;
        newNode->left = NULL;
        newNode->right = NULL;

        if (direction == 'L') {
            if (parent->left == NULL)
                parent->left = newNode;
            else
                cout << "Left child of parent already exists!" << endl;
        } else if (direction == 'R') {
            if (parent->right == NULL)
                parent->right = newNode;
            else
                cout << "Right child of parent already exists!" << endl;
        } 
        else {
            cout << "Invalid direction!" << endl;
        }
    }

    node* findNode(node* root, int data) {
        if (root == NULL || root->data == data)
            return root;
        
        node* left = findNode(root->left, data);
        if (left != NULL)
            return left;
        
        return findNode(root->right, data);
    }

    void inorderTraversal( node* node) {
        if (node == NULL)
        return;

        inorderTraversal(node->left);
        cout <<"->"<< node->data;        
        inorderTraversal(node->right);
       
}
// Preorder traversal
void preorderTraversal(node* node) {
  if (node == NULL)
    return;

  cout << node->data << "->";
  preorderTraversal(node->left);
  preorderTraversal(node->right);
}

// Postorder traversal
void postorderTraversal(node* node) {
  if (node == NULL)
    return;

  postorderTraversal(node->left);
  postorderTraversal(node->right);
  cout << node->data << "->";
}


};

int main()
{
   int t;
    cin>>t;
    tree* T= new tree();
   

    while(t--)
    {
        char x;
        int p;
        int c;
        cin>>x>>p>>c;
        T->add(p,c,x);
    }
    cout<<"\ninorder ";
    T->inorderTraversal(T->root);
    cout<<"\npost\n";
    T->postorderTraversal(T->root);
    cout<<"\npre\n";
    T->preorderTraversal(T->root);

}
