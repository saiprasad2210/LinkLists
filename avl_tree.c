/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: saitanne
 *
 * Created on May 21, 2016, 5:08 PM
 */


#include<stdlib.h>
#include<stdio.h>
/*
 * 
 */

// An AVL tree node
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

// A utility function to get height of the tree
int height(struct node *node) {
    if(!node)
        return 0;
    return(node->height);
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
struct node* newNode(int key)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct node *rightRotate(struct node *y)
{
    struct node *x  = y->left;
    struct node *T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    x->height = max(height(x->left),height(x->right)) + 1;
    y->height  = max(height(y->left),height(y->right))+ 1;
    
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    x->height = max(height(x->left),height(x->right)) + 1;
    y->height  = max(height(y->left),height(y->right))+ 1;
    
    return y;
}

// Get Balance factor of node N
int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct node* avl_insert(struct node* node, int key)
{
    /* 1.  Perform the normal BST search */
    if(!node){
        return(newNode(key));
    }
    
    if(key < node->key) {
      node->left  =  avl_insert(node->left,key);     
    } else {
      node->right =  avl_insert(node->right,key); 
    }
    
    // update the height
    
    node->height = max(height(node->left),height(node->right))+1;
    
    /* 3. Get the balance factor of this ancestor node to check whether
       this node became unbalanced */
    int balance = getBalance(node);
    
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    
    // Left Right Case
    
    if (balance > 1 && key < node->left->key) {
        node->left = leftRotate(node->left);
        return(rightRotate(node));
    }
    
    // Right Left Case
    
    if(balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return(leftRotate(node));
    }
    
    // return unchanged node pointer    
    return node;
}
// A utility function to print preorder traversal of the tree.
// The function also prints height of every node
void preOrder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
 
/* Drier program to test above function*/
int main()
{
  struct node *root = NULL;
 
  /* Constructing tree given in the above figure */
  root = avl_insert(root, 10);
  root = avl_insert(root, 20);
  root = avl_insert(root, 30);
  root = avl_insert(root, 40);
  root = avl_insert(root, 50);
  root = avl_insert(root, 25);
 
  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */
 
  printf("Pre order traversal of the constructed AVL tree is \n");
  preOrder(root);

  return 0;
}

