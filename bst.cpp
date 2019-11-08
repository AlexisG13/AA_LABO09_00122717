#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

struct node{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item){
    struct node *temp = new node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root){
    if (root != NULL){
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void boca(struct node *root,int val1,int val2){
    if (val1>val2){
        int val3 = val1;
        val1 = val2;
        val2 = val3;
    } 
    if(root->key>val1&&root->key<val2) {
        cout << root->key;
        return;
    }
    if(root->key>val1&&root->key>val2){
        root = root->left;
        boca(root,val1,val2);
    }
    if(root->key<val1&&root->key<val2){ 
        root = root->right;
        boca(root,val1,val2);
    }
}

struct node* insert(struct node* node, int key){
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}


struct node * minValueNode(struct node* node){
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct node * maxValueNode(struct node* node){
    struct node* current = node;
    while (current && current->right != NULL)
        current = current->right;
    return current;
}



int main(){

/* Let us create following BST
            8
        /       \
    3              10
 /      \             \
1       6             14 
    /       \        /
   4         7      13
*/

    struct node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 14);
    root = insert(root, 13);
    
    //printf("Inorder traversal of the given tree \n");
    //inorder(root);
    boca(root,1,14);
    return 0;
}