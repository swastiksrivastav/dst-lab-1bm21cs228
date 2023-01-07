#include<stdio.h>
#include<stdlib.h>
struct node{
struct node *llink;
int data;
struct node *rlink;
};

typedef struct node node;
node *start=NULL;

void create(){
    int choice;
node *new,*curr;
start=(node*)malloc(sizeof(node));
printf("enter the value\n");
scanf("%d",&start->data);
start->llink=NULL;
curr=start;
while(1){
    printf("do you want to enter another element\n");
    scanf("%d",&choice);
    if(choice==1){
        new =(node *)malloc(sizeof(node));
        curr->rlink=new;
        new->llink=curr;
        printf("eneter the value\n");
        scanf("%d",&new->data);
        curr=new;
    }
    else{
        curr->rlink=NULL;
        break;
    }
}
}

void insert_left()
{
    int ele;
    node *neww;
neww=(node*)malloc(sizeof(node));
printf("Enter ele:\n");
scanf("%d",&neww->data);
if(start==NULL)
{
neww->llink=NULL;
neww->rlink=NULL;
start=neww;
return;
}
neww->rlink=start;
start->llink=neww;
neww->llink=NULL;
start=neww;
}

void delete_val()
{
int ele;
node *temp;
if(start==NULL)
{
printf("DLL is empty\n");
return;
}
printf("Enter element to be deleted\n");
scanf("%d",&ele);
if(start->data==ele && start->llink!=NULL)
{
temp=start;
start=start->rlink;
start->llink=NULL;
free(temp);
}
temp=start;
while(temp->rlink!=NULL && temp->data!=ele)
{
temp=temp->rlink;
}
if(temp->data && temp->rlink==NULL)
{
temp->llink->rlink=NULL;
free(temp);
}
if(temp->data==ele && temp->rlink!=NULL)
{
temp->llink->rlink=temp->rlink;
temp->rlink->llink=temp->llink;
free(temp);
return;
}
printf("element not found\n");
}

void display(){
node *temp;
if(start==NULL){
    printf("linked list is empty\n");
    return;
}
temp=start;
while(temp!=NULL){
    printf("%d\t",temp->data);
    temp=temp->rlink;
}
}

void main(){
int choice;
while(1){
printf("Enter your choice\n");
printf("1.create_doublyll\t2.insert_left\t3.delete\t4.display\t5.exit\n");
scanf("%d",&choice);
switch(choice){
case 1:create();
break;
case 2:insert_left();
break;
case 3:delete_val();
break;
case 4:display();
break;
case 5:exit(0);
}
}
}
