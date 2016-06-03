/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: saitanne
 *
 * Created on May 7, 2016, 9:09 AM
 */

#include<stdlib.h>
#include<stdio.h>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left, *right;
};

/* Function protoypes */
void printGivenLevel(struct node* root, int level);
int height(struct node* node);
struct node* newNode(int data);
 
/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level)
{
   if(!root)
       return;
   
   if(level == 1) {
       printf("%d ",root->data);
   }  
  
   printGivenLevel(root->left,level-1);
   printGivenLevel(root->right,level-1);
}

void traverselevelOrder(struct node* root)
{
    int i=1;
    
    for (i=1;i<=height(root);i++) {
        printGivenLevel(root,i);
        printf("\n");
    }
}

void inorder(struct node *root) {
    if(!root)
        return;
    
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

struct node* parent(struct node *root,int key) {
    struct node* tmp = NULL;
    struct node* par = root;
    
    if(!root || root->data == key)
        return (root);
    
   
    for(tmp=root; tmp != NULL && tmp->data != key;) {
        if(key < tmp->data) {
            par =tmp;
            tmp = tmp->left;
        } else {
            par = tmp;
            tmp = tmp->right;
        }
    }
    
    if(tmp != NULL) {
       return(par);
    } else {
        return (NULL);
    }
}

/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/

int height(struct node* node) {
    
    int ltree=0,rtree=0;
    if(!node)
        return (0);
    
    ltree = 1 + height(node->left);
    rtree = 1 + height(node->right);
    
    if(ltree > rtree ) {
        return ltree;
    } else {
        return rtree;
    }
}


/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return(node);
}
 

void createSampleTree(struct node** root) {
    *root = newNode(1);
    (*root) ->left        = newNode(2);
    (*root) ->right       = newNode(3);
    
    (*root) ->left->left  = newNode(4);
    (*root) ->left->right = newNode(5);
    
    (*root) ->right->left  = newNode(6);
    (*root) ->right->right = newNode(7);
}

node* find_min_node_bst(struct node *node) {
    
    struct node* min;
    if(!node)
        return (NULL);
    
    if(node->left == NULL) {
        printf("min val is %d\n",node->data);
        return (node);
    } else {
        find_min_node_bst(node->left);
    }
    
}
node* insert_bst(struct node *node,int key) {
    
    if(!node)
      return(newNode(key));  
    
    if(key < node->data) {
        node->left  = insert_bst(node->left,key);
    } else {
        node->right = insert_bst(node->right,key);
    }
}

void insert_bst_new(struct node **root,int key) {
    struct node *tmp,*par;
    
    if(*root == NULL){
        *root = newNode(key);
    }
    for(tmp = *root;tmp != NULL;){
        if(key < tmp->data ){
            par = tmp;
            tmp = tmp->left;
        } else {
            par = tmp;
            tmp = tmp->right;
        }
    }
    if(key < par->data)
        par->left = newNode(key);
    else 
        par->right = newNode(key);
}

/* A function that constructs Balanced Binary Search Tree from a sorted array */
struct node* sortedArrayToBST(int arr[], int start, int end)
{
    /* Base Case */
    if (start > end)
      return NULL;
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    struct node *root = newNode(arr[mid]);
 
    /* Recursively construct the left subtree and make it
       left child of root */
    root->left =  sortedArrayToBST(arr, start, mid-1);
 
    /* Recursively construct the right subtree and make it
       right child of root */
    root->right = sortedArrayToBST(arr, mid+1, end);
 
    return root;
}

node* delete_bst(struct node *root,int key) {
    struct node * temp;
    if(!root)
        return(root);
    
    if(root->data < key) {
        root->left = delete_bst(root->left,key);
    } else if(root->data >key) {
        root->right = delete_bst(root->right,key);
    } else {
        //case 1 : leaf node
        if(root->left == NULL && root->right == NULL) { 
           free(root); 
           root = NULL;
           return(root);
        } else if(root->left == NULL) {
            temp = root->right;
            free(root);
            return(temp);
        } else if(root->right == NULL) {
            temp = root->left;
            free(root);
            return(temp);
        } else {
            temp = find_min_node_bst(root->right);
            root->data = temp->data;
            root->right = delete_bst(root->right,temp->data);
            return(root);
        }
    }
    
} 

node* search_bst(struct node *node,int key) {
    if(!node || node->data == key)
        return (node);
    
    if(key < node->data ) {
        search_bst(node->left,key);
    } else if (key > node->data) {
         search_bst(node->right,key);
    }
}

bool printAncestors(struct node *root, int target)
{
    if(root == NULL)
        return (0);
    
    if(root->data == target) {
        return(1);
    }
    
    if(printAncestors(root->left,target) || printAncestors(root->right,target)) {
        printf("%d ->",root->data);
        return (1);
    }
    
    return(0);
}

int getOddOccurrence(int ar[], int ar_size)
{
     int i;
     int res = 0; 
     for (i=0; i < ar_size; i++)  { 
         
        res = res ^ ar[i];
        printf("res:  %d-> ",res) ;
     }
     
     return res;
}
void print_leaf_paths(struct node *root) {
    if(!root)
        return;
    
    if(!(root->left || root->right) ) {
        printf("%d ",root->data);
        
        return;
    }
    
    printf(" %d-> ", root->data);
    print_leaf_paths(root->left);
    printf("\n");
    printf(" %d-> ", root->data);
    print_leaf_paths(root->right);
}
struct node * inOrderSuccessor(struct node *root, struct node *n) {
    
    struct node *tmp = root;
    struct node *succ = NULL;
    
    // if right node is not null successor should be min value in right subtree
    if(n ->right != NULL) {
        return(find_min_node_bst(n->right));
    }
    
    //other wise  inorder successor should be some ancestor of this node
    while(tmp!=NULL) {
        if(n->data < tmp->data) {
            succ = tmp;
            tmp = tmp->left;
        } else if (n->data > tmp->data) {
            tmp = tmp->right;
        } else {
            break;
        }
    }
    
    return (succ);
}


node * least_common_ancestor(node *root,int n1,int n2) {
    if(!root)
        return (root);
    //lca value should be between node n1 and node n2  
    if(root->data > n1 && root->data > n2){
       return(least_common_ancestor(root->left,n1,n2)); 
    } else if (root->data < n1 && root->data < n2) {
       return(least_common_ancestor(root->right,n1,n2)); 
    } else {
        //all other cases
        return root;
    }
}
void createSampleBST(struct node** root) {
 
    *root = insert_bst(*root, 50);
    insert_bst(*root, 30);
    insert_bst(*root, 20);
    insert_bst(*root, 40);
    insert_bst(*root, 70);
    insert_bst(*root, 60);
    insert_bst(*root, 80);
}

bool checkIfBST(node *root, int *prev) {
    if(!root){
        return 1;
    }
    
    if(checkIfBST(root->left,prev)){
       if(root->data < *prev){
          return(0);
        } else {
          printf("prev:%d curr:%d\n",*prev,root->data); 
          *prev = root ->data;
          
        }
        if(checkIfBST(root->right,prev)) {
           return(1);
        }
    } else {
        return 0;
    }
}

void sort_array_to_bst(node** root,int *arr,int i,int j) {
    
    int k;
    
    if(i <= j) {
       k = (i+j)/2;
       insert_bst_new(root,arr[k]);
       printf("%d",arr[k]);
       sort_array_to_bst(root,arr,i,k-1);
       sort_array_to_bst(root,arr,k+1,j);
    }
}

/*
 * 
 */
int main(int argc, char** argv) {

    struct node *root = NULL;
    struct node *var  = NULL;
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int prev = -1;
    
    sort_array_to_bst(&root,arr,0,9);
    inorder(root);
    //createSampleBST(&root);
    //createSampleTree(&root);    
    
    //createSampleTree(&root);
    /*
    
    printf("Height of tree is %d\n",height(root));

    traverselevelOrder(root);
    
    printf("\n");
    inorder(root);
    
    printf("\n");
    //printAncestors(root,80);
    print_leaf_paths(root);
    //find_min_node_bst(root);*/    
    return 0;
}

