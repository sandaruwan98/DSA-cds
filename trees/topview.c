#include <stdio.h>
#include <stdlib.h>

// struct tree{
//     int data;
//     struct tree* left;
//     struct tree* right;
    
// };


struct tree{
    long data;
    struct tree* left;
    struct tree* right;
};


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
    printf("%ld ",root->data);
    if(root->right == NULL)
        return root;
    else 
        return MaxNode(root->right);

}



 

void PreorderPrint(node* root){
    if(root == NULL)
        return;
   // printf("%d\n",root->data);

    PreorderPrint(root->left);
    printf("%ld ",root->data);

}




int main(){

     
node* ptr;
int n;
int x;
    scanf("%d",&n);
    int i;
    for ( i = 0; i < n; i++)
    {
        scanf("%ld",&x);
        root =insert(root,x);
    }
   
   PreorderPrint(root);
    ptr = MaxNode(root->right);
	return 0;
}



