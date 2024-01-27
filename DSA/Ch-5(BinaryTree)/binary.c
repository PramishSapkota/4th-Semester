#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *left, *right;
};

struct node* newNode(int item)
{
	struct node* temp= (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}
struct node* insert(struct node* nnode, int item)
{

	if (nnode == NULL)
		return newNode(item);
	if (item < nnode->key)
		nnode->left = insert(nnode->left, item);
	else if (item > nnode->key)
		nnode->right = insert(nnode->right, item);

	return nnode;
}

int main()
{
	struct node* root = NULL;
	root = insert(root, 50);
	insert(root, 10);
	insert(root, 25);
	insert(root, 45);
	insert(root, 60);
	insert(root, 69);
	insert(root, 90);

	inorder(root);

	return 0;
}