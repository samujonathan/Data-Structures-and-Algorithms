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
    if(head != NULL) {
    	struct Node* temp = head; 
    	while(temp->next != NULL) {
    		temp = temp->next;
    	}
    	temp->next = newNode;
    } else {
        head = newNode;
    }

}

void insertAtPos(int val, int pos) {
	if (pos < count) {
		struct Node* newNode = createNode(val);
		struct Node* temp = head;
		struct Node* prev = head;
		int i = 1;
		while (temp->next != NULL && i <= pos) {
		    prev = temp;
			temp = temp->next;
			i++;
		}
		newNode->next = temp;
		prev->next = newNode;	
	}
}

void insertAfterVal(int val, int pos) {
    if(head != NULL) {
		struct Node* newNode = createNode(val);
		struct Node* temp = head;
		while (temp->next != NULL && temp->data != pos) {
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;        
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

		int i = 1;
		while (temp->next != NULL && i < pos) {
			prevNode = temp;
			temp = temp->next;
			i++;
		}
		prevNode->next = temp->next;
		free(temp);
	}
}

void deleteVal(int val) {
	if(head != NULL) {
		struct Node* temp = head;
		struct Node* prevNode = head;

		while (temp->next != NULL && temp->data != val) {
			prevNode = temp;
			temp = temp->next;
		}
		prevNode->next = temp->next;
		free(temp);
	}
}

int search(int val) {
    struct Node* temp = head;
    int pos = 1;
    while(temp != NULL) {
        if(temp->data == val) {
            printf("%d available at %d\n", val, pos);
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    printf("%d Not available\n", val);
    return -1;
    
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

void createList(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        insertTail(*(arr+i));
    }
}

int main() {
    int arr[] = {21, 14, 20, 51, 61, 30};
    createList(arr, 6);
    display();
    insertAtPos(32, 3);
    display();
    insertHead(9);
    display();
    deleteVal(32);
    display();
    deleteAtPos(2);
	display();
	
	search(51);
	search(90);
	return 0;
}
