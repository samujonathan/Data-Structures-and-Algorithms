#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* node, int key)
{
    if (node == NULL)
        return newNode(key);
 
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
 
    return node;
}

int height(struct Node** root) {
    if(*root != NULL) {
        int left = height(&(*root)->left);
        int right = height(&(*root)->right);
        if(left >= right) {
            return left+1;
        } else {
            return right+1;
        }
    }
	return 0;
}

void printCurrLevel(struct Node** root, int height) {
    if(*root != NULL) {
        if(height == 0) {
            printf("%c ", (*root)->data);
        } else {
            printCurrLevel(&(*root)->left, height-1);
            printCurrLevel(&(*root)->right, height-1);
        }
    }
}

void levelOrder(struct Node** root) {
    int n = height(root);
    for(int i = 0; i < n; i++) {
        printCurrLevel(root, i);
    }
}

struct Node** inOrder(struct Node** root) {
    if(*root == NULL) {
        return root;
    }
    inOrder(&(*root)->left);
	printf("%d ", (*root)->data);
    inOrder(&(*root)->right);

	return root;
}

void preOrder(struct Node** root) {
    if(*root == NULL) {
        return;
    }
    printf("%d ", (*root)->data);
    preOrder(&(*root)->left);
    preOrder(&(*root)->right);
}

void postOrder(struct Node** root) {
    if(*root == NULL) {
        return;
    }
    postOrder(&(*root)->left);
    postOrder(&(*root)->right);
    printf("%c ", (*root)->data);
}

int main() {

	int n;
	scanf("%d", &n);
    struct Node* root;

	for (int i = 0; i < n; i++) {
		int digit;
		scanf("%d", &digit);
		root = insert(root, digit);

	}
	inOrder(&root);
	putchar('\n');
	preOrder(&root);
	putchar('\n');
	postOrder(&root);
	putchar('\n');
	levelOrder(&root);
	printf("%d\n", height(&root));
	putchar('\n');
    return 0;
}
