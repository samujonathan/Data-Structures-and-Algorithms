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
		newNode->next = newNode;
		head = newNode;
	} else {
		newNode->next = head->next;
		head->next = newNode;
	}
}

void insertTail(int val) {
	if(head != NULL) {
		struct Node* newNode = createNode(val);
		struct Node* temp = head->next; 
		while(temp->next != head) {
			temp = temp->next;
		}
		/** int i = 0; */
		/** while(i < count) { */
		/**     temp = temp->next; */
		/**     i++; */
		/** } */
		newNode->next = head->next;
		temp->next = newNode;
	}
}

void display() {
	if (head != NULL) {
		struct Node* temp = head->next;
		while (temp != head->next){
			printf("%d-> ", temp->data);
			temp = temp->next;
		} ; 
		printf("\n");
	} else {
		printf("List is empty\n");
	}
}

int main() {
	insertHead(3);
	insertHead(6);
	insertHead(9);
	insertTail(4);
	/** insertTail(5); */
	/** insertAtPos(40, 1); */
	display();
	return 0;
}

