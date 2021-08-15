#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct NODE {
	struct NODE* left, * right;
	int data;
}NODE;
void getNode(NODE** p) {
	(*p) = (NODE*)malloc(sizeof(NODE));
}
NODE *Search(NODE* p, int e) {
	while (p != NULL) {
		if (p->data == e) {
			return p;
		}
		else if (p->data > e) {
			p = p->left;
		}
		else {
			p = p->right;
		}
	}
	return NULL;
}
NODE *insert(NODE* p, int e) {
	NODE* parent = NULL, * new = NULL;
	getNode(&parent);
	getNode(&new);
	new->data = e;
	new->left = new->right = NULL;
	while (p != NULL) {
		parent = p;
		if (p->data == e) {
			return p;
		}
		else if (p->data > e) {
			p = p->left;
		}
		else {
			p = p->right;
		}
	}
	if (parent != NULL) {
		if (parent->data < e) {
			parent->right = new;
		}
		else {
			parent->left = new;
		}
	}
	return new;
}
void delete(NODE* p, int e) {
	NODE* parent = NULL, * new = NULL;
	getNode(&parent);
	while (p != NULL && p->data != e) {
		parent = p;
		if (p->data > e) {
			p = p->left;
		}
		else {
			p = p->right;
		}
	}
	if (p->left == NULL && p->right == NULL) {
		if (parent == NULL) {
			p = NULL;
		}
		else {
			if (parent->left == p) {
				parent->left = NULL;
			}
			if (parent->right == p) {
				parent->right = NULL;
			}
		}
	}
	else if (p->left == NULL || p->right == NULL) {
		if (p->left != NULL) new = p->left;
		else if (p->right != NULL) new = p->right;
		if (parent == NULL) {
			p = new;
		}
		else {
			if (parent->left == p) {
				parent->left = new;
			}
			if (parent->right == p) {
				parent->right = new;
			}
		}
	}
	else {
		NODE* succ_parent = p;
		NODE* succ = p->right;
		while (succ->left != NULL) {
			succ_parent = succ;
			succ = succ->left;
		}
		p->data = succ->data;
		if (succ_parent->left == succ) {
			succ_parent->left = succ->right;
		}
		if (succ_parent->right == succ) {
			succ_parent->right = succ->right;
		}
		p = succ;
	}
	free(p);
}
void inorder(NODE* p) {
	if (p != NULL) {
		if (p->left != NULL) inorder(p->left);
		printf("%d ", p->data);
		if (p->right != NULL) inorder(p->right);
	}
}
int main() {
	NODE* root = NULL;
	getNode(&root);
	root = insert(NULL, 6);
	insert(root, 3);
	insert(root, 1);
	insert(root, 7);
	insert(root, 9);
	insert(root, 5);
	delete(root, 5);
	inorder(root);
}