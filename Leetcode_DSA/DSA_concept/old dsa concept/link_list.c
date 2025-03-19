#include<stdio.h>
#include<stdlib.h>
struct node{
    int  data;
    struct node *next;
    struct node *prev;
};
struct node * create (struct node * head){
    int choice=1;
    head=0;
    while(choice){
        struct node *newnode=(struct node *)malloc (sizeof(struct node));
        struct node *temp;
        newnode->next =newnode->prev=0;
        printf("EEnter data ");
        scanf("%d",&newnode->data);
        if(head==0){
            head=newnode;
            temp=head;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=temp->next;
        }
        printf("enter 0 to exit and press 1 to continue");
        scanf("%d",&choice);
    }
    return head ;
}
void display(struct node * head){
    struct node * temp2=head;
    while(temp2!=NULL){
        printf("%d ",temp2->data);
        temp2=temp2->next;
    }
}
struct node * insert_at_given_position  (struct node * head,int pos){
            struct node *inserttemp,*inserttempo,*inserttemp2=head,*ins=head;
            int i=2,count=0;
            inserttemp=(struct node *)malloc (sizeof(struct node));
            printf("enter data ");
            scanf("%d",&inserttemp->data);
            while(ins!=0){
                count++;
                ins=ins->next;
            }
            if(pos>count+1){
                printf("Invalid position");
                return 0;
            }
            else if (pos==1){
                inserttemp->next=head;
                inserttemp->prev=0;
                head=inserttemp;
                display(head);
            }
            else if (pos == count+1){
                while(i<pos)
                {
                    inserttemp2=inserttemp2->next;
                    i++;
                }
                inserttemp2->next=inserttemp;
                inserttemp->next=0;
                inserttemp->prev=inserttemp2;
                display(head);
            }
            else{
                while(i<pos){
                    inserttemp2=inserttemp2->next;
                    i++;
                }
                inserttemp->next=inserttemp2->next;
                inserttemp->prev=inserttemp2;
                inserttemp2->next=inserttemp;
                display(head);
            }
            return head;
}
struct node * delete_from_given_position(struct node * head,int pos){
    struct node *deletetemp=head,*deletetemp2,*del=head;
            int count=0;
            while(del!=0){  //count the number of element
                count++;
                del=del->next;
            }
            if(pos>count){
                printf("Invalid position");
                return 0 ;
            }
            else if (pos==1){
                head=head->next;
                head->prev=0;
                free(deletetemp);
                display(head);
            }
            else if (pos == count){
                while(deletetemp->next!=0){
                    deletetemp2=deletetemp;
                    deletetemp=deletetemp->next;
                }
                deletetemp2->next=0;
                free(deletetemp);
                display(head);
            }
            else{
                deletetemp2=head;
                int i=1;
                while(i<pos-1){
                    deletetemp2=deletetemp2->next;
                    i++;
                }
                deletetemp=deletetemp2->next;
                deletetemp2->next=deletetemp->next;
                deletetemp->next->prev=deletetemp2;
                free (deletetemp);
                display(head);
            }
            return head;
}
struct node * insert_at_end(struct node *head,int datan){
    struct node *inserttemp,*inserttemp2=head;
            inserttemp=(struct node *)malloc (sizeof(struct node));
            inserttemp->data=datan;
            inserttemp->next=inserttemp->prev=0;
            if (inserttemp2==0){
                return inserttemp;
            }
            else if (inserttemp2->next==0)
            {
                inserttemp->prev=inserttemp2;
                inserttemp2->next=inserttemp;   
            }
            else {
                while(inserttemp2->next!=0){
                    inserttemp2=inserttemp2->next;
                }
                inserttemp2->next=inserttemp;
                inserttemp->next=0;
                inserttemp->prev=inserttemp2;
            }
            return inserttemp;
}
int count(struct node *head){
    struct node *temp=head;
    int counter0=0 ;
    while(temp!=0){
        counter0++;
        temp=temp->next;
    }
    return counter0;
}
struct node * seperate_positive(struct node *head,struct node *head1){
    struct node * temp=head,*temp0=head,*temp1=head1;
    int counter1 = count(temp);
    printf("\n%d",counter1);
    for (int i = 0; i < counter1; i++){
        printf("\nworking");
        if(temp0->data>0){
            temp0=insert_at_end(temp1,temp0->data);
        } 
        printf("\nworking");
        temp0=temp0->next; 
    }   
     printf("\nworking"); 
    return temp1; 
}
int main(){
    struct node *head,*head1=0,*head2=0;
    head=create(head);
    display(head);
    int temp0;
    temp0=count(head);
    printf("\n %d",temp0);
    head1=seperate_positive(head,head1);
    printf("\n");
    display(head1);
  //printf("\n");
  //display(head2);
   /* int choice,choice1;
    while (1)
    {
        printf("\nPress 1 for Inserion \n");
        printf("Press 2 for Deletion \n");   
        printf("Press 3 to Display \n");
        printf("Press 5 to exit\n");      
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            int pos1;
            printf("Enter position");
            scanf("%d",&pos1);
            head=insert_at_given_position(head,pos1);
            break;
        case 2:
            int pos;
            printf("Enter position");
            scanf("%d",&pos);
            head=delete_from_given_position(head,pos);
            break;
        case 3:
            display(head);
            break;
        case 5:
            return 0;
        }
        }*/
        return 0;
}
