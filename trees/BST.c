#include <stdio.h>
#include <stdlib.h>
#include "NodeTypeQueueInt.h"

// struct tree{
//     int data;
//     struct tree* left;
//     struct tree* right;
    
// };

typedef struct tree node;

node* root = NULL;



node *newnode(int data){
    node* newnode;
    newnode = (node*) malloc(sizeof(node));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = data;
    

    return newnode;
}

node* insert(node* root,int val){
    if (root == NULL) 
        root = newnode(val);   
    else if(val <= root->data)
            root->left = insert( root->left ,val);
    else if(val >= root->data)
            root->right =insert(root->right,val);
    
    return root;
    
}


node* MaxNode(node* root){
    if(root->right == NULL)
        return root;
    else 
        return MaxNode(root->right);

}

node* MinNode(node* root){
    if(root->left == NULL)
        return root;
    else 
        return MaxNode(root->left);

}


node* DeleteNode(node* root,int val){
    if (root == NULL) printf("Threre's no node contains %d",val);
    else if (val < root->data) root->left = DeleteNode(root->left,val);  
    else if (val > root->data) root->right = DeleteNode(root->right,val);
    else if (root->left != NULL && root->right != NULL){//when deleting node contains two subtrees
        node* temp = MaxNode(root->left);
       // printf("%d\n",temp->data);
        root->data = temp->data;
       // printf("Thr");
        root->left = DeleteNode(root->left,temp->data); 
    }else{
        node* temp = root;
        if (root->left == NULL && root->right == NULL){
            root=NULL;
        }
            
        else if (root->left != NULL){
            root = root->left;    
                   
        }
            
        else {
           root = root->right;    

        }

        free(temp);
      
        
    }
    
    return root;
    
    
}


node* Search(node* root,int val){
    if((root == NULL) ||  (root->data == val))
        return root;
    else if (root->data > val) 
        return Search(root->left,val);
    else 
        return Search(root->right,val);

}

 

void PreorderPrint(node* root){
    if(root == NULL)
        return;
    printf("%d\n",root->data);

    PreorderPrint(root->left);
    PreorderPrint(root->right);

}


void LevelOrderPrint(node* root){
	enqueue(root);
	while (!isEmpty())
	{
	   root =  dequeue();
	   printf("%d\n",root->data);
	   if(root->left != NULL)
			enqueue(root->left);
       if(root->right != NULL)
	   		enqueue(root->right);
	}

}


int main(){

    root =insert(root,7);
    root =insert(root,2);
    root =insert(root,9);
    root =insert(root,1);
    root =insert(root,8);
    root =insert(root,6);
    root =insert(root,10);
    
//     LevelOrderPrint(root);
//     root = DeleteNode(root,7);
//     printf("\n\n\n");
//    LevelOrderPrint(root);


node* ptr;
int option, val;

do
{
    printf("\n ******MAIN MENU******* \n");
    printf("\n 1. Insert Element");
    printf("\n 2. Preorder Traversal");
    printf("\n 3. Inorder Traversal");
    printf("\n 4. Postorder Traversal");
    printf("\n 5. Find the smallest element");
    printf("\n 6. Find the largest element");
    printf("\n 7. Delete an element");
    // printf("\n 8. Count the total number of nodes");
    // printf("\n 9. Count the total number of external nodes");
    // printf("\n 10. Count the total number of internal nodes");
    // printf("\n 11. Determine the height of the tree");
    // printf("\n 12. Find the mirror image of the tree");
    // printf("\n 13. Delete the tree");
    printf("\n 0. Exit");
    printf("\n\n Enter your option : ");
    scanf("%d", &option);
switch(option)
{
case 1:
    printf("\n Enter the value of the new node : ");
    scanf("%d", &val);
    root = insert(root,val);
    break;
case 2:
    printf("\n The elements of the tree are : \n");
    PreorderPrint(root);
    break;
case 3:
    printf("\n The elements of the tree are : \n");
    LevelOrderPrint(root);
    break;
case 4:
    printf("\n The elements of the tree are : \n");
    break;
case 5: 
    printf("\n Smallest element is :%d",MinNode(root)->data);
    break;
case 6:
    printf("\n Largest element is : %d", MaxNode(root)->data);
    break;
case 7:
    printf("\n Enter the element to be deleted : ");
    scanf("%d", &val);
    root = DeleteNode(root,val);
    break;
}
}while(option!=0);


   
	return 0;
}



