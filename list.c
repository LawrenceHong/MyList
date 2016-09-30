#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num;
	struct node *next;
} Tnode;

Tnode* insert_node(Tnode* head, Tnode* newNode) {
	Tnode *temp = NULL;

	//Judge the head of list is NULL or not, if NULL return error.
	if (head == NULL) {
		printf("ERROR, list is NULL\n");
		return NULL;
	}
	//If the data of head bigger than newNode's, newNode replace the head.
	if (newNode->num < head->num) {
		printf("Replace head by using new node\n");
		newNode->next = head;
		return newNode;
	}
	//if the data of head smaller than newNode's and the list only have one node. Return the head.
	if (head->next == NULL)	{
		printf("Insert new node after head\n");
		head->next = newNode;
		return head;
	}
	//if the data of head smaller than newNode's and the list have more than one node, find the place between two nodes.
	if (head->next) {
		Tnode  *p = NULL;
		for (p = head; p->next != NULL;p = p->next) {
			if ((p->num <= newNode->num) && (p->next->num > newNode->num)) {
				printf("In the middle of list, we find a place to insert new node\n");
				temp = p->next;
				p->next = newNode;
				newNode->next = temp;
				return head;
			}
		}
		if (p&&!p->next) {
			printf("In the end of list, we find a place to insert new node\n");
			p->next = newNode;
			return head;
		}
	}
	
	printf("ERROR, can't find sutiable place to insert new node\n");
	return NULL;
}

Tnode* list_create(Tnode *head) {
	Tnode *p1 = NULL;
	Tnode *p2 = NULL;
	//Tnode *insert = NULL;

	p1 = (Tnode*)malloc(sizeof(Tnode));
	p1->next = NULL;
	
	printf("Please add new data for list\n");
	scanf("%d", &p1->num);

	if (head == NULL) {
		printf("List is NULL, add the new node as head\n");
		head = p1;	
	}
	else {
		//p2 = insert = insert_node(head, p1);
		//insert->next = p1;
		//p1->next = p2->next;
		head = insert_node(head, p1);
	}
	
	return head;
}

void list_del(Tnode *head) {
	Tnode *p = head;
	Tnode *q = head;
	while (p) {
		p = q->next;
		printf("Free the data of the node %d\n", q->num);
		free(q);
		q = p;		
	}
	printf("Delete list successfully\n");
}

void list_print(Tnode *head) {
	Tnode *p = head;
	while(p) {
		printf("%d", p->num);
		p = p->next;
	}
	printf("\n");
	printf("End to print list\n");
}

int main() {
	Tnode *head = NULL;
	for (int i = 0; i < 5; i++) {
		head = list_create(head);
	}
	if (!head) {
		printf("ERROR The head is NULL");
	}
	list_print(head);
	list_del(head);

	return 0;
}
