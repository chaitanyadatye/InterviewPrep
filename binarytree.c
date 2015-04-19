#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node * left;
	struct node * right;
	struct node * parent;
}node;

typedef struct tree{
	node *root;
}tree;

tree *T;

void inorderTraversal(node *root) {
	if(root == NULL)
		return;
	inorderTraversal(root->left);
	printf("%d ",root->data);
	inorderTraversal(root->right);
}

tree * createTree() {
	T = (tree *)malloc(sizeof(T));
	T->root = NULL;
	return T;
}

void insert(node *n) {
	if(T == NULL)
		createTree();
	if(T->root == NULL) {
		T->root = n;
		return;
	}

	node *x = T->root;
	node *y = NULL;
	
	while(x!= NULL) {
		y = x;
		if(n->data < x->data)
			x = x->left;
		else
			x = x->right;
	}
	
	n->parent = y;
	if(n->data < y->data)
		y->left = n;
	else
		y->right = n;

	return;
}

node * createNode(node *n, int d) {
	n = (node *)malloc(sizeof(node));
	n->left = NULL;
	n->right = NULL;
	n->parent = NULL;
	n->data = d;
	
	return n;
}

int main() {
	
	T = createTree();
	int key;
	while(1) {
	printf("Enter node: ");
	scanf("%d", &key);
	if(key == -99)
		break;
	
	node *n;
	n = createNode(n, key);
	insert(n);
	}

	inorderTraversal(T->root);

	return 0;
}			
