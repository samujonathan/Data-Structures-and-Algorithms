#include <stdio.h>
#include <stdlib.h>
#include "../../data_structure/linkedList/singlyLinkedList.c"


int main() {
	int coeff1[] = {6, 5, 3};
	int exp1[] = {4, 3, 1};
	struct Node* head1;

	int coeff2[] = {8, 6, 8};
	int exp2[] = {5, 3, 0};
	struct Node* head2;

	struct Node* result;

	createList(&head1, coeff1, exp1, 3);
	createList(&head2, coeff2,exp2,3);
	display(&head1);
	display(&head2);

	struct Node* temp1 = head1;
	struct Node* temp2 = head2;

	while (temp1 != NULL && temp2 != NULL) {
		int coeff, exp;
		if(temp1->exp > temp2->exp) {
			coeff = temp1->coeff;
			exp = temp1->exp;
			temp1 = temp1->next;
		} else if(temp1->exp < temp2->exp) {
			coeff = temp2->coeff;
			exp = temp2->exp;
			temp2 = temp2->next;
		} else {
			coeff = temp1->coeff + temp2->coeff;
			exp = temp1->exp;

			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		insertTail(&result, coeff, exp);
	}

	while (temp1 != NULL) {
		insertTail(&result, temp1->coeff, temp1->exp);
		temp1 = temp1->next;
	}

	while (temp2 != NULL) {
		insertTail(&result, temp2->coeff, temp2->exp);
		temp2 = temp2->next;
	}
	/** printf("%d %d\n", result->coeff, result->exp); */

	display(&result);
}
