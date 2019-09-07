#include <stdio.h>
#include <stdlib.h>
#include "NodeTypeQueueChar.h"


node *newnode(node* parent,char data){
    node* newnode;
    newnode = (node*) malloc(sizeof(node));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = data;
    newnode->parent = parent;

    return newnode;
}



void PreorderPrint(node* root){
    if(root == NULL)
        return;
    printf("%c\n",root->data);

    PreorderPrint(root->left);
    PreorderPrint(root->right);

}


void LevelOrderPrint(node* root){
	enqueue(root);
	while (!isEmpty())
	{
	   root =  dequeue();
	   printf("%c\n",root->data);
	   if(root->left != NULL)
			enqueue(root->left);
       if(root->right != NULL)
	   		enqueue(root->right);
	}

}



int main(){
    node* root = newnode(NULL,'A');
    root->left = newnode(root,'B');
    root->left->left = newnode(root->left,'D');
    root->left->right = newnode(root->left,'E');
    root->right = newnode(root,'C');

    root->right->left = newnode(root->right,'F');
    root->right->right = newnode(root->right,'G');
    PreorderPrint(root);

     printf("\n");

    LevelOrderPrint(root);
   
	return 0;
}



