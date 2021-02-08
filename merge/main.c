#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode
{
    element data;
    struct ListNode *link;
}ListNode;


/* Function to bubble sort the given linked list */
void SelectionSort(ListNode *head);

/* Function to swap data of two nodes a and b*/
void swap(ListNode *p1, ListNode*p2);



ListNode* insert_first(ListNode *head, element value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

void print_list(ListNode *head)
{
    for(ListNode *p = head; p!=NULL;p=p->link)
        printf("%d->",p->data);
    printf("NULL \n");
}

ListNode* concat_list(ListNode *head1, ListNode *head2)
{

    if(head1 ==NULL) return head2;
    else if (head2 == NULL) return head1;
    else {
        ListNode *p;
        p = head1;
        while(p->link != NULL)
            p = p->link;
        p->link = head2;
        return head1;

    }
}

void SelectionSort(ListNode *head)
{
	ListNode *start = head;
	ListNode *traverse;
	ListNode *min;

	while(start->link)
	{
		min = start;
		traverse = start->link;

		while(traverse)
		{
			/* Find minimum element from array */
			if( min->data > traverse->data )
			{
				min = traverse;
			}

			traverse = traverse->link;
		}
		swap(start,min);			// Put minimum element on starting location
		start = start->link;
	}
}

/* swap data field of linked list */
void swap(ListNode *p1, ListNode*p2)
{
	int temp = p1->data;
	p1->data = p2->data;
	p2->data = temp;
}


int main()
{
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;

    head1 = insert_first(head1,1);
    head1 = insert_first(head1,2);
    head1 = insert_first(head1,5);
    head1 = insert_first(head1,10);
    head1 = insert_first(head1,15);
    head1 = insert_first(head1,20);
    head1 = insert_first(head1,25);
    print_list(head1);

    head2 = insert_first(head2,3);
    head2 = insert_first(head2,7);
    head2 = insert_first(head2,8);
    head2 = insert_first(head2,15);
    head2 = insert_first(head2,18);
    head2 = insert_first(head2,30);
    print_list(head2);

    ListNode *total = concat_list(head1,head2);
    print_list(total);

    SelectionSort(total);
    print_list(total);

    return 0;
}
