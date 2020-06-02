#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char s[30];
    struct node *next;
}*p,*q,*head;

int main(int argc, char *argv[])
{
   // freopen("in.txt","r",stdin);
    int n,s,e,i;
    char tmp[30];
    scanf("%d",&n);
    scanf("%s",&tmp);
    head=(struct node*)malloc(sizeof(struct node));
    strcpy(head->s,tmp);
    head->next=head;
    p=head;
    for(i=1;i<n;i++)
    {
        q=(struct node*)malloc(sizeof(struct node));
        scanf("%s",tmp);
        strcpy(q->s,tmp);
        q->next=head;
        p->next=q;
        p=q;
    }
   /* p=head;
    printf("%s\n",p->s);
    p=p->next;
    while(p!=head)
    {
        printf("%s\n",p->s);
        p=p->next;
    }*/
    scanf("%d,%d",&s,&e);
    p=head;
    for(i=1;i<s;i++)
    {
        q=p;
        p=p->next;
    }
    while(1)
    {
        if(p->next==p)
        {
            printf("%s\n",p->s);
            free(p);
            break;
        }
        for(i=1;i<e;i++)
        {
            q=p;
            p=p->next;
        }
        printf("%s\n",p->s);
        head=p;
        p=p->next;
        q->next=p;
        free(head);
        
    }
  
  //system("PAUSE");	
  //while(1);
  return 0;
}

