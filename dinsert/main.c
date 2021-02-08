#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

void display(DListNode* phead) {
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink)
	{
		printf("<---| %x | %d | %x | --->\n", p->llink,p->data,p->rlink);
	}

	printf("\n");
}

void dinsert_first_node(DListNode* before, DListNode* new_node) {
    new_node->llink = before;
    new_node->rlink = before->rlink;
    before->rlink->llink = new_node;
    before->rlink = new_node;
}

void dinsert_last_node(DListNode* before, DListNode* new_node) {
	new_node->llink = before -> llink;
	new_node->rlink = before->llink->rlink;
	before->llink->rlink = new_node;
	before->llink = new_node;
}



void main()
{
    DListNode head_node;
    DListNode *p[10];

    init(&head_node);
	for (int i = 0; i < 5; i++)
	{
	    p[i] = (DListNode*)malloc(sizeof(DListNode));
		p[i]->data = i;
		dinsert_first_node(&head_node, p[i]);
	}
	display(&head_node);


    init(&head_node);
	for (int i = 0; i < 5; i++)
	{
		p[i] = (DListNode*)malloc(sizeof(DListNode));
		p[i]->data = i;
		dinsert_last_node(&head_node, p[i]);
	}
	display(&head_node);


}
