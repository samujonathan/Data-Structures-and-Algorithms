#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node* prev;
	int data;
	struct Node* next;
};

struct Node* head;

struct Node* createNode(int val) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->prev = NULL;
	newNode->data = val;
	newNode->next = NULL;
	return newNode;
}

void insertHead(int val) {
	struct Node* newNode = createNode(val);
	if (head == NULL) {
		head = newNode;
		newNode->next = head;
		newNode->prev = head;
	} else {
		struct Node* temp = head;
		newNode->next = temp;
		temp->prev = newNode;
		while (temp->next != head) {
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
		head = newNode;
	}
}

void insertTail(int val) {
	struct Node* newNode = createNode(val);
	if(head != NULL) {
		struct Node* temp = head->prev;
		head->prev = newNode;
		newNode->next = head;
		temp->next = newNode;
		newNode->prev = temp;
	}
}

void insertAfter(int val) {
	struct Node* newNode = createNode(val);
	if (head != NULL) {
		struct Node* temp = head;
	}
}

void display() {
	if (head != NULL) {
		struct Node* temp = head;
		while (temp->next != head){
			printf("%d-> ", temp->data);
			temp = temp->next;
		}; 
		printf("%d-> ", temp->data);
		printf("\n");
	} else {
		printf("List is empty\n");
	}
}

int main() {
	insertHead(7);
	display();
	insertHead(9);
	display();
	insertHead(10);
	display();
	insertTail(19);
	display();
	return 0;
}
