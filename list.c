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

	p1 = (Tnode*)malloc(sizeof(Tnode));
	p1->next = NULL;
	
	printf("Please add new data for list\n");
	scanf("%d", &p1->num);

	if (head == NULL) {
		printf("List is NULL, add the new node as head\n");
		head = p1;	
	}
	else {
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
		printf("%d ", p->num);
		p = p->next;
	}
	printf("\n");
	printf("End to print list\n");
}

Tnode* list_merge(Tnode *head1, Tnode *head2) {
	Tnode *p = head2;
	Tnode *q = head2;
	while(p) {
		p = q->next;
		head1 = insert_node(head1, q);
		q = p;
	}
	return head1;	
}

int main() {
	Tnode *head1 = NULL;
	Tnode *head2 = NULL;
	Tnode *head = NULL;
	
	printf("Ready to print list 1\n");
	for (int i = 0; i < 5; i++) {
		head1 = list_create(head1);
	}

	printf("Ready to print list 2\n");
	for (int j = 0; j < 5; j++) {
		head2 = list_create(head2);
	}

	if (!head1 || !head2) {
		printf("ERROR The head is NULL\n");
	}
	list_print(head1);
	list_print(head2);
	
	head = list_merge(head1, head2);
	if (!head) {
		printf("ERROR The head is NULL\n");
	}

	list_print(head);

	list_del(head);

	return 0;
}
