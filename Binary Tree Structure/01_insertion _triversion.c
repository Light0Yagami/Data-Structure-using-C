#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
    int info;
    struct Tree *left;
    struct Tree *right;
}tree;

tree *create(int num){
    tree *ptr = malloc(sizeof(tree));
    if(ptr == NULL){
        printf("Not enough memory");
    }else{
        ptr->info = num;
        ptr->left = NULL;
        ptr->right = NULL;
    }
    return(ptr);
}



void insert(tree *root, tree *temp){
    if(root->info > temp->info){
        if(root->left == NULL){
            root->left = temp;
        }else{
            insert(root->left,temp);
        }
    }else{
        if(root->right == NULL){
            root->right = temp;
        }else{
            insert(root->right,temp);
        }
    }
}

void inorder(tree *root){
    if(root != NULL){
	    inorder(root->left);
	    printf("%d\t",root->info);
	    inorder(root->right);
    }
}


    
}









int main()
{
    tree *root = NULL, *temp;
    int num;
    int opt;
    while(1){
        printf("Enter the element \n");
        scanf("%d",&num);
        temp = create(num);
        
        if(root == NULL){
            root = temp;
        }
        else{
            insert(root, temp);
        }
        
        printf("Enter 1 to exit\n");
        scanf("%d",&opt);
        
        if(opt){
            break;
        }
    }
    inorder(root);
    
    return 0;
}


