// min heap ¸¸µé±â
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LCHILD(x) 2 * x + 1
#define RCHILD(x) 2 * x + 2
#define PARENT(x) (x - 1) / 2

typedef struct node {
    int data ;
} node ;

typedef struct minHeap {
    int size ;
    node *elem ;
} minHeap ;

minHeap initMinHeap() {
    minHeap hp ;
    hp.size = 0 ;
    return hp ;
}

void insertNode(minHeap *hp, int data) {
    // allocating space
    if(hp->size) {
        hp->elem = realloc(hp->elem, (hp->size + 1) * sizeof(node)) ;
    } else {
        hp->elem = malloc(sizeof(node)) ;
    }

    // initializing the node with value
    node nd ;
    nd.data = data ;

    // Positioning the node at the right position in the min heap
    int i = (hp->size)++ ;
    while(i && nd.data < hp->elem[PARENT(i)].data) {
        hp->elem[i] = hp->elem[PARENT(i)] ;
        i = PARENT(i) ;
    }
    hp->elem[i] = nd ;
}

int heapincrease(minHeap *hp,int i,int key)
{
    if (key < hp->elem[i].data)
    {
        printf("new key is smaller than current key");
        return 0;
    }
    hp->elem[i].data = key;
    while(i<hp->size&&(hp->elem[LCHILD(i)].data<hp->elem[i].data||hp->elem[RCHILD(i)].data<hp->elem[i].data))
    {
        int tmp;
        int smallest = i;
        if(hp->elem[LCHILD(i)].data>hp->elem[RCHILD(i)].data)
        {
            tmp = hp->elem[RCHILD(i)].data;
            smallest = RCHILD(i);
        }else {
            tmp = hp->elem[LCHILD(i)].data;
            smallest = LCHILD(i);
        }
        if(smallest!=i)
        {
            hp->elem[smallest].data = hp->elem[i].data;
            hp->elem[i].data = tmp;
        }
        i=smallest;
    }

    return 1;

}

int heapdecrease(minHeap *hp,int i,int key)
{
    if (key > hp->elem[i].data)
    {
        return 0;
    }
    hp->elem[i].data = key;
    while(i>0&&(hp->elem[PARENT(i)].data>hp->elem[i].data))
    {
        int tmp = hp->elem[PARENT(i)].data;
        hp->elem[PARENT(i)].data = hp->elem[i].data;
        hp->elem[i].data = tmp;
        i=PARENT(i);
    }
    return 1;

}

int main()
{
    minHeap hp = initMinHeap();

    printf("Min Heap\n");

    insertNode(&hp, 1);
    insertNode(&hp, 4);
    insertNode(&hp, 2);
    insertNode(&hp, 7);
    insertNode(&hp, 5);
    insertNode(&hp, 3);
    insertNode(&hp, 3);
    insertNode(&hp, 7);
    insertNode(&hp, 8);
    insertNode(&hp, 9);

    for (int i = 0; i < hp.size; i++)
        printf("%d\n", hp.elem[i].data);

    heapincrease(&hp,2,10);

    printf("case2\n");
    for (int i = 0; i < hp.size; i++)
        printf("%d\n", hp.elem[i].data);


    heapdecrease(&hp,3,3);

    printf("case3\n");
    for (int i = 0; i < hp.size; i++)
        printf("%d\n", hp.elem[i].data);

    return 0;
}
