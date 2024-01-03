/*Que.1 Find the difference between largest number and smallest number in the doubly linked list
Input: 2,6, 1, 5, 9
Output: 8 (9-1)

Input: 2,4,16,10, 15
Output: 14 (16-2)

Input: 3, 6, 8, 18, 5
Output: 15 (18-3)*/

#include<stdio.h>
#include<stdlib.h>
typedef struct node* ptr;
struct node
{
    int data;
    ptr next;
    ptr prev;
};
ptr head=NULL;
ptr temp=NULL;
ptr n1=NULL;
ptr node=NULL;
int lgest;
int smest;

void createdublylist(int n)
{
    n1=(ptr)malloc(sizeof(struct node));
    if(!n1)
    {
        printf("space not allocated");
    }
    else
    {
        head=n1;            //first node address
        n1->next=NULL;
        n1->prev=NULL;
        //printf("give value");
        scanf("%d",&n1->data);
        temp=n1;                                //that node address(first)to be used in for loop as previous
        for(int i=2;i<=n;i++)
        {
            node=(ptr)malloc(sizeof(struct node));
            if(!n)
            {
                printf("space unavailable");
            }
            else
            {
                node->prev=temp;
                node->next=NULL;
                //printf("giv node data value");
                scanf("%d",&node->data);
                temp->next=node;
                temp=temp->next;
            }
        }
    }
}
int findest(ptr head)
{
    temp=head;
    lgest=temp->data;
    smest=temp->data;
    while(temp)
    {
        if(((temp->data)>lgest)||((temp->data)==lgest))
        {
            lgest=temp->data;
        }
        else if(((temp->data)<smest)||((temp->data)==smest))
        {
            smest=temp->data;
        }
        temp=temp->next;
    }
    return (lgest-smest);
}
int main()
{
    int n=0;
    //printf("giv list size");
    scanf("%d",&n);
    createdublylist(n);
    printf("%d",findest(head));
    return 0;
}