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
void printSpiral(struct node *root){
	int h = height(root);
	int i = 0;
	for(i=0;i<h;i++){
		traverseNthLevel(root,i,i%2);
		printf("\n");
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
int isHeightBalanced(struct node *root,int *height){	
	int lh = 0,rh = 0;
	int l = 0,r = 0;
	if(root == NULL) {
		*height = 0;
		return 1;
	}
	l = isHeightBalanced(root->left,&lh);
	r = isHeightBalanced(root->right,&rh);

	*height = max(lh,rh) + 1;
	if((lh - rh >= 2) || (rh - lh >=2)) return 0;
	else l && r;
}
void doubleTree(struct node *root){
	struct node *temp = NULL;
	if(root == NULL) return;
	doubleTree(root->left);
	doubleTree(root->right);
	temp = (struct node*)malloc(sizeof(struct node));
	temp->val = root->val;
	temp->left = root->left;
	root->left = temp;
}
int inorder(struct node *root){
	if(root == NULL) return;
	inorder(root->left);
	printf("%d\t",root->val);
	inorder(root->right);
}
int printAncestor(struct node *root,int num){
	if(root == NULL) return 0;
	if(root->val == num) return 1;
	if(printAncestor(root->left,num) || printAncestor(root->right,num)){
		printf("%d\n",root->val);
		return 1;
	}
	return 0;
}
int isSumTree(struct node *root,int *sum){
	
}
int main(){
	/*struct node *root = newNode(1);
	  root->left        = newNode(2);
	  root->right       = newNode(3);
	  root->left->left  = newNode(7);
	  root->left->right = newNode(6);
	  root->right->left  = newNode(5);
	  root->right->right = newNode(4);
	  printf("Spiral Order traversal of binary tree is \n");
	  printSpiral(root);
	struct node *root = newNode(1);
	root->left        = newNode(2);
	root->right       = newNode(3);
	root->left->left  = newNode(4);
	root->left->right = newNode(5);
	root->left->left->left  = newNode(7);
	printAncestor(root,7);

	printf("Inorder traversal of the original tree is \n");
	inorder(root);

	doubleTree(root);

	printf("\n Inorder traversal of the double tree is \n");  
	inorder(root);*/
	struct node *root  = newNode(26);
	root->left         = newNode(10);
	root->right        = newNode(3);
	root->left->left   = newNode(4);
	root->left->right  = newNode(6);
	root->right->right = newNode(3);
	if(isSumTree(root,0))
		printf("The given tree is a SumTree ");
	else
		printf("The given tree is not a SumTree ");

	return 0;
}
