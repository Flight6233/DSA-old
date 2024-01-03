/*Que.2 Remove duplicates from an unsorted doubly linked list
Input: 12->11->12->21->41->43->21
Output:12->11->21->41->43. */

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
ptr temp1=NULL;
ptr temp2=NULL;
ptr temp3=NULL;
ptr temp=NULL;
ptr shift=NULL;
ptr todelete=NULL;
ptr n1=NULL;
ptr node=NULL;
int siz=0;
int count=1;
int flag=0;

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
                scanf("%d",&node->data);
                temp->next=node;
                temp=temp->next;
            }
        }
    }
}
void size(ptr head)
{
    temp1=head;
    while(temp1)
    {
        siz++;
        temp1=temp1->next;
    }
}
void printlist(ptr head)
{
    temp3=head;
    while(temp3)
    {
        printf("%d ",temp3->data);
        temp3=temp3->next;
    }
}
void deletefromsecond_duplicate(ptr head)
{
    temp2=head;
    while(count!=siz+1)
    {
        int compare=temp2->data;
        if(temp2->next!=NULL)
        shift=temp2->next;
        else
        {
            break;
        }
        
        while(shift!=NULL)  //compare all others to the first
        {
            if((compare==(shift->data))&&(shift->next!=NULL))
            {
                todelete=shift;
                shift=shift->prev;
                todelete->prev->next=todelete->next;
                todelete->next->prev=todelete->prev;//delete sth which is shift
                free(todelete);
                siz=siz-1;
                
            }
            else if(((shift->data)==compare)&&(shift->next==NULL))
            {
                todelete=shift;
                shift=shift->prev;
                shift->next=NULL;
                free(todelete);
                siz=siz-1;
                break;
            }
            shift=shift->next;
        }
        temp2=temp2->next;
        count++;
    }
}

int main()
{
    int n=0;
    scanf("%d",&n);
    createdublylist(n);
    size(head);
    deletefromsecond_duplicate(head);
    printlist(head);
    return 0;
}