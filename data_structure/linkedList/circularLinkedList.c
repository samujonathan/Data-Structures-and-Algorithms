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
		newNode->next = head;
	} else {
		struct Node* temp = head;
		while (temp->next != head) {
			temp = temp->next;
		}
		newNode->next = head;
		temp->next = newNode;
		head = newNode;
	}
}

void insertTail(int val) {
	if(head != NULL) {
		struct Node* newNode = createNode(val);
		struct Node* temp = head->next; 
		while(temp->next != head) {
			temp = temp->next;
		}
		newNode->next = head;
		temp->next = newNode;
	}
}

void insertAfter(int val, int pos) {
	if(head != NULL) {
		struct Node* newNode = createNode(val);
		struct Node* temp = head;	
		while (temp->data != pos) {
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
	}
}

void deleteNode(int val) {
	if(head != NULL) {
		struct Node* temp = head;
		struct Node* prev = head;
		while (temp->data != val) {
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;
		free(temp);
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
	insertHead(3);
	insertHead(6);
	insertHead(9);
	insertTail(5);
	insertAfter(15, 5);
	/** deleteNode(6); */

	display();
	return 0;
}

