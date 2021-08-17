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
	(*p)->left = NULL, (*p)->right = NULL;
}
NODE* insert(NODE* p, int e) {
	NODE* new = NULL;
	getNode(&new);
	new->data = e;
	if (p == NULL) return new;
	if (p->data > e) {
		if (p->left == NULL) {
			p->left = new;
		}
		else {
			return insert(p->left, e);
		}
	}
	else {
		if (p->right == NULL) {
			p->right = new;
		}
		else {
			return insert(p->right, e);
		}
	}
	return new;
}
void delete(NODE* p, int e) {
	NODE* parent = NULL, * child = NULL;
	getNode(&parent);
	while (p != NULL) {
		parent = p;
		if (p->data > e) {
			p = p->left;
		}
		else if (p->data < e) {
			p = p->right;
		}
		else {
			break;
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
			else if (parent->right == p) {
				parent->right = NULL;
			}
		}
	}
	else if (p->left == NULL || p->right == NULL) {
		if (p->left != NULL) {
			child = p->left;
		}
		else if (p->right != NULL) {
			child = p->right;
		}
		if (parent == NULL) {
			p = child;
		}
		else {
			if (parent->left == p) {
				parent->left = child;
			}
			else if (parent->right == p) {
				parent->right = child;
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
		else if (succ_parent->right == succ) {
			succ_parent->right = succ->right;
		}
		p = succ;
	}
	free(p);
}
void inorder(NODE* p) {
	if (p->left != NULL) inorder(p->left);
	printf("%d ", p->data);
	if (p->right != NULL) inorder(p->right);
}
int main() {
	int e;
	NODE* p = NULL;
	getNode(&p);
	for (int i = 0; i < 10; i++) {
		scanf("%d", &e);
		if (i == 0) {
			p = insert(NULL, e);
		}
		else {
			insert(p, e);
		}
	}
	inorder(p);
	printf("\n");
	scanf("%d", &e);
	delete(p, e);
	inorder(p);
}