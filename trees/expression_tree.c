#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NodeTypeQueueChar.h"


node *newnode(node* parent){
	node* newnode;
	newnode = (node*) malloc(sizeof(node));
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->parent = parent;

	return newnode;
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


void PreorderPrint(node* root){
	if(root == NULL)
		return;
	printf("%c\n",root->data);

	PreorderPrint(root->left);
	PreorderPrint(root->right);

}


int SizeOfTree(node* n){
	if(n == NULL)
		return 0;
	else
	{
		return 1 + SizeOfTree(n->left) + SizeOfTree(n->right);
	}

}

// void IneorderPrint(node* root){
//     if(root == NULL)
//         return;
//     printf("%c\n",root->data);

//     PreorderPrint(root->left);
//     PreorderPrint(root->right);

// }

int main(){
	char exp[100];
	int i = 0;
	printf("Enter Expression : ");
	scanf("%s",exp);
	node* root = newnode(NULL);
	node* CurrentNode = root;

for (i = 0; i < strlen(exp); i++)
{

	char c = exp[i];

	if (c == '(' )
	{
		CurrentNode ->left = newnode(CurrentNode);
		CurrentNode =  CurrentNode ->left;

	}else if (c == '*' || c == '/' || c == '+' || c == '-' )
	{
		CurrentNode ->data = c;
		CurrentNode ->right = newnode(CurrentNode);
		CurrentNode =  CurrentNode ->right;

	}else if (c == ')')
	{
		if (CurrentNode ->parent != NULL)
			CurrentNode = CurrentNode ->parent;
	}else
	{
		CurrentNode ->data = c;
		CurrentNode = CurrentNode ->parent;
	}




}


  	PreorderPrint(root);
	printf("\n");

	LevelOrderPrint(root);

	printf("\n\n");
 	printf("%d",SizeOfTree(root));
	printf("\n\n");



	return 0;
}



