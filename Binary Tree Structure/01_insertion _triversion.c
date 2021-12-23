#include<stdio.h>
#include<stdlib.h>

typedef struct Tree{
	int info;
	struct Tree *left;
	struct Tree *right;
}tree;

tree *insert(tree *root, int ele){
	if(root == NULL){
		tree *ptr = malloc(sizeof(tree));
		if(ptr == NULL){
			printf("Memory doesn't allocated");
		}else{
			ptr->info = ele;
			ptr->left = NULL;
			ptr->right = NULL;
			root = ptr;
		}
	}else{
		if(root->info < ele){
			root->right = insert(root->right,ele);
		}else{
			root->left = insert(root->left,ele);
		}
	}
	return root;
}

void inorder(tree *root){
    if(root != NULL){
	    inorder(root->left);
	    printf("%d\n",root->info);
	    inorder(root->right);
    }
}

tree *inorsucc(tree *root){
    tree* current = root;
    while(current->left != NULL){
        current = current->left;
    }
    return root;
}

tree *delete(tree *root,int key){
    if(root == NULL){
        return root;
    }
    else if(key < root->info) {
        root->left = delete(root->left,key);
    }
    else if(key > root->info){ 
        root->right = delete(root->right,key);
    }
    else
    {
        if(root->left == NULL && root->right==NULL)
        {
            free(root);
            root = NULL;
        }
        else if(root->left == NULL){
            tree *temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL){
            tree *temp = root;
            root = root->left;
            free(temp);
        }
        else {
            tree *temp = inorsucc(root->right);
            root->info = temp->info;
            root->right = delete(root->right, temp->info);
        }
    }
    return root;
}


int main(){
	int ch;
	tree *root = NULL;
	int ele;

	while(1){
		printf("1.Insertion in Binary Tree\n");
		printf("2.Deletion in Binary Tree\n");
		printf("3 Display Binary Tree\n");
		printf("4.Exit\n");
		scanf("%d",&ch);
		switch(ch){
		case 1: 
			printf("Enter the element to be insert\n");
			scanf("%d",&ele);
			root = insert(root,ele);
			break;
		case 2:
		    printf("Enter the element to be deleted\n");
		    scanf("%d",&ele);
		    root = delete(root,ele);
			break;
		case 3:
			inorder(root);
			break;
		case 4:
		    exit(0);
		default:
			printf("Choose correct option\n");
    	}  
    }
    
    
    return 0;
}
