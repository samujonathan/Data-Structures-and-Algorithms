#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node* prev;
	int data;
	struct Node* next;
};

struct Node* start;

struct Node* createNode(int val) {
	struct Node* newNode;
	newNode = malloc(sizeof(struct Node));

	newNode->prev = NULL;
	newNode->data = val;
	newNode->next = NULL;
	return newNode;
}
void insertHead(int val) {
	struct Node* newNode = createNode(val);
	if(start == NULL) {
		start = newNode;
	} else {
		newNode->next = start;
		start->prev = newNode;
		start = newNode;
	}
}

void insertTail(int val) {
	struct Node* newNode = createNode(val);
	if (start == NULL) {
		start = newNode;
	} else {
		struct Node* temp = start;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
	}
}

void insertAfter(int val, int pos) {
	struct Node* newNode = createNode(val);
	if (start == NULL) {
		start = newNode;
	} else {
		struct Node* temp = start;
		while (temp->data != pos && temp->next != NULL) {
			temp = temp->next;
		}
		if (temp->next != NULL) {
			newNode->next = temp->next;
			temp->next->prev = newNode;
			temp->next = newNode;
			newNode->prev = temp;
		} else {
			temp->next = newNode;
			newNode->prev = temp;
		}
	}
}

void insertBefore(int val, int pos) {
	struct Node* newNode = createNode(val);
	if (start == NULL) {
		start = newNode;
	} else {
		struct Node* temp = start;
		while (temp->data != pos && temp->next != NULL) {
			temp = temp->next;
		}
		if (temp->next != NULL) {
			newNode->next = temp->next;
			temp->next->prev = newNode;
			temp->next = newNode;
			newNode->prev = temp;
		} else {
			temp->next = newNode;
			newNode->prev = temp;
		}
	}
}

void display() {
	struct Node* temp = start;
	while (temp->next != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("%d ", temp->data);
	putchar('\n');
}

int main() {

	insertHead(13);
	insertHead(5);
	insertTail(7);
	insertAfter(14, 13);

	display();
	/** printf("%d %d %d\n", start->data, start->next->data, start->next->next->data); */
	return 0;
}
