#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct List{
    int v;
    struct List* next;
} List;


List* create_new_List(int element);
void append_element(List* l,int element);
void prepend_element(List** l,int element);
void print_list_r(List* l);
void print_list(List* l);
void delete_element(List** l,int element);
void insert_element(List** l,int pos,int element);
int getSize(List** l);
int searchElement(List** l,int element);


int main(int argc, char** argv){
    printf("Hello,world\n");
    struct List** head;
    struct List* l;
    l=create_new_List(3);

    head=&l;
    // in the head on stocke l'adresse de l;

    append_element(l,4);
    append_element(l,5);
    prepend_element(head,2);
    print_list(*head);
    printf("**************\n");
    //delete_element(head,3);
    insert_element(head,0,1);
    insert_element(head,4,9);
    print_list(*head);
    printf("Size is %d\n", getSize(head));
    int i=searchElement(head,10);
    if(i>=0){
        printf("found in %d th case\n",i);
    }
    else{
        printf("Not found\n");
    }
}

List* create_new_List(int element){
    List* l =malloc(sizeof(List));
    l->v=element;
    l->next=NULL;
    return l;
}

void append_element(List* l,int element){
    List* l1=malloc(sizeof(List));
    l1->v=element;
    l1->next=NULL;
    while(l->next!=NULL){
        l=l->next;
    }
    l->next=l1;
}

void prepend_element(List** l,int element){
    List* l1=malloc(sizeof(List));
    l1->v=element;
    l1->next=*l;
    *l=l1;
}

void print_list(List* l){
    int i=0;
    while(l!=NULL){
      printf("The %d element is %d\n", i,l->v);
      l=l->next;
      ++i;
    }
}

void print_list_r(List* l){
    if(l!=NULL){
        printf("The element is %d\n",l->v);
        print_list_r(l->next);
    }
}

void delete_element(List** l, int element){
    List* prev=NULL;
    List* temp=*l;
    while(temp->v!=element && temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    if(temp->v==element){
        if(prev==NULL){
            *l=temp->next;
        }
        else{
           prev->next=temp->next;
        }
        free(temp);
    }
    else{
      printf("Can't find the %d in the list\n",element);
    }
}



void insert_element(List** l,int pos,int element){
    if(pos==0){
        prepend_element(l,element);
    }
    else if(pos>=getSize(l)){
        append_element(*l,element);
    }
    else{
        List* prev=NULL;
        List* temp=*l;
        List* p1=malloc(sizeof(List));
        p1->next=NULL;
        p1->v=element;
        while(pos>0){
            prev=temp;
            temp=temp->next;
            pos=pos-1;
        }
        prev->next=p1;
        p1->next=temp;
    }
}

int getSize(List** l){
    List* a=(*l);
    int nb=0;
    while(a!=NULL){
        a=a->next;
        ++nb;
    }
    return nb;
}

int searchElement(List** l,int element){
    List* a=(*l);
    int i=0;
    while(a!=NULL){
        if(a->v!=element){
            a=a->next;
            i=i+1;
        }
        else{
             return i;
        }
    }
    return -1;
}
