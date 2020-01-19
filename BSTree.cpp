#include <iostream>
using namespace std;

BinarySearchTree {
    struct node {
        struct node* leftChild;
        struct node* rightChild;
        int val;
    }
    struct node* root;
    public:
    node* addNode(node* root, int data){   
        if(root == NULL){       
            return createNode(data);    
        }   
        if(data < root->val){        
            root->left = addNode(root->leftChild);    
        } else if(data > root->val){        
            root->right = addNode(root->rightChild);    
        }
    }
    int FindMin(Node *root) {
        if (root == NULL) {
            return INT_MAX; 
        }
        if (root->left != NULL) {
            return FindMin(root->left); 
        }
        return root->data;
    }

    node* Delete(int data) {
        if (root == NULL) {
            return NULL;
        }
        if (data < root->data) {  
            root->left = Delete(root->left, data);
        } else if (data > root->data) { 
            root->right = Delete(root->right, data);
        } else {
            // case 1: no children
            if (root->left == NULL && root->right == NULL) {
                delete(root);
                root = NULL;
            }
            // case 2: one child (right)
            else if (root->left == NULL) {
                node *temp = root; 
                root = root->right;
                delete temp;
            }
            // case 3: one child (left)
            else if (root->right == NULL) {
                node *temp = root; 
                root = root->left;
                delete temp;
            }
            // case 4: two children
            else {
                node *temp = FindMin(root->right); 
                root->data = temp->data; 
                root->right = Delete(root->right, temp->data); 
            }
        }
        return root;
    }

    void inorder(node* root) {
        if(root == NULL) return;
        inorder(root->left);
        cout << (root->data) << endl;
        inroder(root->right);
   }

   void preorder(node* root) {
        if(root == NULL) return;
        cout<< (root->val) << endl;
        preorder(root->left);
        preorder(root->right);
   }
    
     void postorder(node* root) {
        if(root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        cout<< (root->val) << endl;
    }
}


int main(){


    return 0;
}
