#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DListNode {
	element data;
	struct DListNode *llink;
	struct DListNode *rlink;
} DListNode;

typedef struct {
	DListNode *top;
} LinkedStackType;

void init(LinkedStackType *s,DListNode *head)
{
	head->llink = head;
	head->rlink = head;
	s->top = head;
}

int is_empty(LinkedStackType *s,DListNode *head)
{
	return (s->top == head);
}

void push(LinkedStackType *s,DListNode *head, element data)
{
	DListNode *temp = (DListNode *)malloc(sizeof(DListNode));
	if (temp == NULL) {
		printf(stderr, "Memory allocation error\n");
			return;
	}

	else {
		temp->data = data;
		temp->llink = head;
		temp->rlink = s->top;
		head->rlink = temp;
		s->top->llink=temp;
		s->top = temp;
	}
}

element pop(LinkedStackType *s,DListNode *head)
{
    DListNode *temp = (DListNode *)malloc(sizeof(DListNode));
	if (is_empty(s,head)) {
		printf("Stack is empty\n");
		return;
	}
	else {
		temp = s->top;
		int item = temp->data;
		head->rlink=temp->rlink;
		temp->rlink->llink = head;
		s->top = temp->rlink;
		free(temp);
		return item;
	}
}

element peek(LinkedStackType *s,DListNode *head)
{
	if (is_empty(s,head)) {
		printf("Stack is empty\n");
		return;
	}
	else {
		return s->top->data;
	}
}

void main()
{
	LinkedStackType* s;
	DListNode *h = (DListNode *)malloc(sizeof(DListNode));
	init(s,h);
	push(s,h,1);
	push(s,h,2);
	push(s,h,3);

	printf("%d\n", pop(s,h));
	printf("%d\n", pop(s,h));
	printf("%d\n", pop(s,h));
}

