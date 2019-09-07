#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct tree
{
    char data;
    struct tree* left;
    struct tree* right;
    struct tree* parent;
};

typedef struct tree node;

node *newnode(node* parent){
    node* newnode;
    newnode = (node*) malloc(sizeof(node));
   // newnode->data = NULL;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = parent;

    return newnode;
}

void traversal(node* CurrentNode){
    if (CurrentNode->left != NULL &&  CurrentNode->left->data != 'x')
    {
        CurrentNode = CurrentNode->left;
        printf("%c\n",CurrentNode->data);
        CurrentNode->data = 'x';

    }else if (CurrentNode->right != NULL &&  CurrentNode->right->data != 'x')
    {
        CurrentNode = CurrentNode->right;
        printf("%c\n",CurrentNode->data);
        CurrentNode->data = 'x';

    }else
    {
       
        CurrentNode = CurrentNode->parent;
      
    }
    
    if(CurrentNode != NULL)
        traversal(CurrentNode);
    


}

int main(){
    char exp[100];
    int i = 0;
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

     printf("%c\n",root->data  );
    traversal(root);



    return 0;
}



