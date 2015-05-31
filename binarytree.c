//Binary Tree Programs -- Author Nayan
#include<stdio.h>
#include<malloc.h>
struct node{
	int val;
	struct node *left;
	struct node *right;
};
struct node* newNode(int num){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->val = num;
	temp->left = NULL;
	temp->right = NULL;
}
int max(int x,int y){
	return (x>y)?x:y;
}
int height(struct node *root){
	if(root == NULL) return 0;
	else return 1 + max(height(root->left),height(root->right));
}
void printSpiral(struct node *root){
	int h = height(root);
	int i = 0;
	for(i=0;i<h;i++){
		traverseNthLevel(root,i,i%2);
		printf("\n");
	}
}
void traverseNthLevel(struct node *root,int level,int direction){
	if(root == NULL) return;
	if(level == 0){
		printf("%d\t",root->val);
	}else{
		level = level - 1;
		if(direction){
			traverseNthLevel(root->left,level,direction);
			traverseNthLevel(root->right,level,direction);
		}else{
			traverseNthLevel(root->right,level,direction);
			traverseNthLevel(root->left,level,direction);
		}
	}
}
int isSumProperty(struct node *root){
	int sum = 0;
	if(root == NULL) return 0;
	else if(root->left == NULL && root->right == NULL) return 0;
	else{
		if(root->left != NULL) sum += root->left->val;
		if(root->right != NULL) sum += root->right->val;
		return (root->val == sum) && isSumProperty(root->left) && isSumProperty(root->right);
	}		
}
int main(){
	struct node *root = newNode(1);
	root->left        = newNode(2);
	root->right       = newNode(3);
	root->left->left  = newNode(7);
	root->left->right = newNode(6);
	root->right->left  = newNode(5);
	root->right->right = newNode(4);
	printf("Spiral Order traversal of binary tree is \n");
	printSpiral(root);
	return 0;
}
