// export LC_CTYPE=C
// LC_CTYPE=C cat /dev/urandom | tr -dc 'a-z' | fold -w 4 | head -n 1000000
// > nom.txt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100000

typedef struct List{
    char* key;
    int occurence;
    struct List* next;
} List;

List* tab[SIZE];
long hashCode(char* key);
List* create_new_List(char* key);
void append_element(List* l,char* key);
List* searchElement(List* l,char* key);
List** insert_key(List** p,char *key);
int collision;

int main(int argc, char** argv){
    printf("Hello world\n");
    collision=0;
    List* tab[SIZE]={NULL};
    char* a="zzzz";
    char* b="zzzz";
    char* c="zzzz";
    char* d="zzza";
    char* e="zzza";
    insert_key(tab,a);
    insert_key(tab,b);
    insert_key(tab,c);
    insert_key(tab,d);
    insert_key(tab,e);
    //printf("the length is %lu\n",strlen(a));
    //printf("the hashcode is %ld\n",codeS);
    return 0;
}



long hashCode(char* key) {
    long hashcode=0;
    for(int i=0;i<strlen(key);i++)
        hashcode=(key[i]-'a'+1)+hashcode*26;
    return (hashcode % SIZE);
}

List* create_new_List(char* key){
    List* l =malloc(sizeof(List));
    l->key=key;
    l->occurence=1;
    l->next=NULL;
    return l;
}

void append_element(List* l,char* key){
    List* l1=malloc(sizeof(List));
    l1->key=key;
    l1->occurence=1;
    l1->next=NULL;
    while(l->next!=NULL){
        l=l->next;
    }
    l->next=l1;
}

List* searchElement(List* l,char* key){
    while (l!=NULL) {
        if(strcmp(l->key,key)==0){
            return l;
        }
        else{
            l=l->next;
        }
    }
    return NULL;
}

List** insert_key(List** p,char *key){
    long hCode=hashCode(key);
    List* l;
    if(p[hCode]==NULL){
        l=create_new_List(key);
        p[hCode]=l;
    }
    else{
        l=searchElement(p[hCode],key);
        if(l==NULL){
            append_element(p[hCode],key);
        }else{
            l->occurence=l->occurence+1;
        }
        collision=collision+1;
        printf("Il y a %d collisions\n", collision);
    }

    return p;
}
