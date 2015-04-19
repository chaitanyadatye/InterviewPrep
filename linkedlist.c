#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int data;
	struct node *next;
} node;

typedef struct List {
	node *head;
} list;

list * create_list(list *l) {
	l = (list *) malloc(sizeof(list));
	l->head = NULL;
	return l;
}

node * create_node(node *n, int d) {
	n = (node *)malloc(sizeof(node));
	n->data = d;
	n->next = NULL;
	return n;
}

list * insert(node *new, list *l) {

	if(l->head == NULL) {
		l->head = new;
		return l;
	}
	else {
		node *temp = l->head;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new;
	}
	return l;
}

node* recursive_reverse(list *l, node *n) {
	if(n == NULL)
		return NULL;
	if(n->next == NULL) {
		l->head = n->next;
		return n;
	}
	
	node *rest = recursive_reverse(l,n->next);
	n->next->next = n;
	n->next = NULL;		

	return rest;
}
	
void reverse_list(list *l) {
	node *prev = NULL;
	node *curr = l->head;
	node *next;
	
	while(curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	l->head = prev;
	return;
}

void print_list(list *l) {
	node *temp = l->head;
	while(temp->next != NULL) {
		printf("%d->",temp->data);
		temp = temp->next;
	}
	printf("%d", temp->data);
}

list * delete_node(list *l, int key) {
	if(l->head->data == key) {
		l->head = l->head->next;
		return l;
	}
	
	node *temp = l->head;
	while(temp->next != NULL) {
		if(temp->next->data == key) {
			temp->next = temp->next->next;
			return l;
		}
		temp = temp->next;
	}
	return l;
}

node * bringtofront(list *l) {	
	
	node *ptr = l->head;
	
	while(ptr->next->next != NULL) {
		ptr = ptr->next;
	}
	
	ptr->next->next = l->head;
	l->head = ptr->next;
	ptr->next = NULL;
	
	return l->head;
}

int main() {
	list *l;
	l = create_list(l);
	int num;

	for(int i=0; i<5; i++) {
		scanf("%d", &num);
		node *new;
		new  = create_node(new, num);
		l = insert(new, l);
	}
	
	print_list(l);
	//l = delete_node(l,23);
	printf("\n\n");

	l->head=recursive_reverse(l,l->head);
	print_list(l);
	
	l->head = bringtofront(l);
	printf("\n");
	print_list(l);

	return 0;
}	
