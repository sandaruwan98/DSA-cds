#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node *root;
struct node *head,*tail = NULL;


struct node *newNode(int val){
	struct node *newnode;
	newnode = (struct node*) malloc(sizeof(struct node));
	newnode->data = val;
	newnode->left = NULL;
	newnode->right = NULL;
	
	return newnode;
}

struct node *CreateNode(struct node *root,int val){
	if(root == NULL) 
		root = newNode(val);
	else if(val < root->data)
		root->left = CreateNode(root->left,val);
	else if(val > root->data)
		root->right = CreateNode(root->right,val);
	
	return root;
}


void convertbtToDLL(struct node *node) {
 
 if(node == NULL)
 return;

 
 convertbtToDLL(node->left);


 if(head == NULL) {
 
 head = tail = node;
 }
 
 else {
 
 tail->right = node;
 node->left = tail;
 tail = node;
 }


 convertbtToDLL(node->right);
} 

int main(){
	
	root = CreateNode(root,5);
	root = CreateNode(root,7);
	root = CreateNode(root,3);
	root = CreateNode(root,8);
	convertbtToDLL(root);
	return 0;
}
