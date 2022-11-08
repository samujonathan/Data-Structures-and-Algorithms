#include<stdio.h>
#include <stdlib.h>

/** struct Node* head; */
int count = 0;

struct Node {
	int coeff;
	int exp;
	struct Node* next;
};

struct Node* createNode(int coeff, int exp) {
	struct Node* newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->coeff = coeff;
	newNode->exp = exp;
	newNode->next = NULL; 
	count++;
	return newNode;
}

void insertHead(struct Node** head, int coeff, int exp) {
	struct Node* newNode = createNode(coeff, exp);
	if(head == NULL) {
		(*head) = newNode;
	} else {
		newNode->next = *head;
		(*head) = newNode;
	}
}

void insertTail(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if(*head != NULL) {
    	struct Node* temp = *head; 
    	while(temp->next != NULL) {
    		temp = temp->next;
    	}
    	temp->next = newNode;
    } else {
        (*head) = newNode;
    }

}

void insertAtPos(struct Node** head, int coeff, int exp, int pos) {
	if (pos < count) {
		struct Node* newNode = createNode(coeff, exp);
		struct Node* temp = *head;
		struct Node* prev = *head;
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

void insertAfterVal(struct Node** head, int coeff, int exp, int pos) {
    if(*head != NULL) {
		struct Node* newNode = createNode(coeff, exp);
		struct Node* temp = *head;
		while (temp->next != NULL && temp->coeff != pos) {
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;        
    }
	
}

void deleteHead(struct Node** head) {
	if(head != NULL) {
		struct Node* temp = *head;
		*head = (*head)->next;
		free(temp);
	} else {
		printf("Underflow\n");
	}
}

void deleteTail(struct Node** head) {
	if(head != NULL) {
		struct Node* temp = *head;
		struct Node* prevNode = *head;
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

void deleteAtPos(struct Node** head, int pos) {
	if(head != NULL && pos < count) {
		struct Node* temp = *head;
		struct Node* prevNode = *head;

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

void deleteVal(struct Node** head, int val) {
	if(head != NULL) {
		struct Node* temp = *head;
		struct Node* prevNode = *head;

		while (temp->next != NULL && temp->coeff != val) {
			prevNode = temp;
			temp = temp->next;
		}
		prevNode->next = temp->next;
		free(temp);
	}
}

int search(struct Node** head, int val) {
    struct Node* temp = *head;
    int pos = 1;
    while(temp != NULL) {
        if(temp->coeff == val) {
            printf("%d available at %d\n", val, pos);
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    printf("%d Not available\n", val);
    return -1;
    
}

void display(struct Node** head) {
	if (head != NULL) {
		struct Node* temp = *head;
		while (temp->next != NULL) {
			printf("(%d %d)-> ", temp->coeff, temp->exp);
			temp = temp->next;
		}
		printf("(%d %d)\n", temp->coeff, temp->exp);
	} else {
		printf("List is empty\n");
	}
}

void createList(struct Node** head, int* coeff, int* exp, int n) {
    for(int i = 0; i < n; i++) {
        insertTail(head, *(coeff+i), *(exp+i));
    }
}

/** int main() { */
/**     int arr[] = {21, 14, 20, 51, 61, 30}; */
/**     createList(arr, 6); */
/**     display(); */
/**     insertAtPos(32, 3); */
/**     display(); */
/**     insertHead(9); */
/**     display(); */
/**     deleteVal(32); */
/**     display(); */
/**     deleteAtPos(2); */
/**     display(); */
/**  */
/**     search(51); */
/**     search(90); */
/**     return 0; */
/** } */
