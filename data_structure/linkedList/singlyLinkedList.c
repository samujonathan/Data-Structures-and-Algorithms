#include<stdio.h>
#include <stdlib.h>

struct Node* head;
int count = 0;

struct Node {
	int data;
	struct Node* next;
};

struct Node* createNode(int val) {
	struct Node* newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = val;
	newNode->next = NULL; 
	count++;
	return newNode;
}

void insertHead(int val) {
	struct Node* newNode = createNode(val);
	if(head == NULL) {
		head = newNode;
	} else {
		newNode->next = head;
		head = newNode;
	}
}

void insertTail(int val) {
	struct Node* newNode = createNode(val);
	struct Node* temp = head; 
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
}

void insertAtPos(int val, int pos) {
	if (pos < count) {
		struct Node* newNode = createNode(val);
		struct Node* temp = head;
		struct Node* prevNode = head;
		int i = 1;
		while (temp->next != NULL && i < pos) {
			prevNode = temp;
			temp = temp->next;
		}
		newNode->next = temp;
		prevNode->next = newNode;	
	}
}

void deleteHead() {
	if(head != NULL) {
		struct Node* temp = head;
		head = head->next;
		free(temp);
	} else {
		printf("Underflow\n");
	}
}

void deleteTail() {
	if(head != NULL) {
		struct Node* temp = head;
		struct Node* prevNode = head;
		while (temp->next != NULL) {
			prevNode = temp;
			temp = temp->next;
		}
		prevNode->next = NULL;
		free(temp);
	} else {
		printf("Underflow\n");
	}
}

void deleteAtPos(int pos) {
	if(head != NULL && pos < count) {
		struct Node* temp = head;
		struct Node* prevNode = head;

		int i = 0;
		while (temp->next != NULL && i < pos) {
			prevNode = temp;
			temp = temp->next;
			i++;
		}
		prevNode->next = temp->next;
		free(temp);
	}
}

void display() {
	if (head != NULL) {
		struct Node* temp = head;
		while (temp->next != NULL) {
			printf("%d-> ", temp->data);
			temp = temp->next;
		}
		printf("%d\n", temp->data);
	} else {
		printf("List is empty\n");
	}
}

int main() {
	insertHead(3);
	insertHead(67);
	insertTail(40);
	insertAtPos(50, 2);

	display();
	deleteAtPos(1);
	display();
	return 0;
}
