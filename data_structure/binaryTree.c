#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct Node** root, int val) {
    
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
	/** printf("val: %d ", (*root)->data); */
	int leftVal = (*root)->data;
    inOrder(&(*root)->right);
	int rightVal = (*root)->data;
	printf("%d %d %d\n", leftVal, rightVal);

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
    // Write C code here
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    
    root->right->left = createNode(6);
    root->right->right = createNode(7);

	inOrder(&root);
	putchar('\n');
	preOrder(&root);
	putchar('\n');
    /** postOrder(&root); */
    /** putchar('\n'); */
    /** levelOrder(&root); */
    /** printf("%d\n", height(&root)); */
    /** putchar('\n'); */
    return 0;
}
