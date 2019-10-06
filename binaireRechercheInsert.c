//
// Created by 徐家大少 on 04/10/2019.
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pair{
    int valeur0;
    int valeur1;
}pair;


typedef struct arbre{
    char * cle;
    struct arbre* g;
    struct arbre* d;
    struct pair* p;
}arbre;


arbre* droit(arbre* pere){
    return pere->d;
}


arbre* gauche(arbre* pere){
    return pere->g;
}


void insert(char* cle, pair* valeur, arbre* racine){

    if(strcmp(cle, racine->cle) > 0){
        if(racine->d != NULL)
            insert(cle,valeur,racine->d);
        else{
            arbre* noeud=malloc(sizeof(arbre));
            noeud->cle=cle;
            noeud->p=valeur;
            noeud->d=NULL;
            noeud->g=NULL;
            racine->d=noeud;
        }
    }
    else if (strcmp(cle, racine->cle) < 0){
        if(racine->g != NULL)
            insert(cle,valeur,racine->g);
        else{
            arbre* noeud=malloc(sizeof(arbre));
            noeud->cle=cle;
            noeud->p=valeur;
            noeud->d=NULL;
            noeud->g=NULL;
            racine->g=noeud;
            }
    }
    else {
        printf("Cle %s est deja existante", cle);
    }

}

pair* Recherche(char* cle, arbre* racine){
    if(strcmp(cle, racine->cle) == 0){
        return racine->p;
    }
    else if(strcmp(cle, racine->cle) > 0){
        if(racine->d == NULL){
            return NULL;
        }
        else{
            return Recherche(cle,racine->d);
        }
    }
    else{
        if(racine->g == NULL){
            return NULL;
        }
        else{
            return Recherche(cle,racine->g);
        }
    }

}

void display(arbre* arb){
    printf("\n");
    printf("%s",arb->cle);
    printf("\n");
    printf("%d",arb->p->valeur0);
    printf("\n");
    printf("%d",arb->p->valeur1);
    printf("\n");
}

void displayR(arbre* racine){
    if(racine->g!= NULL)
        displayR(racine->g);

    if(racine->d!= NULL)
        displayR(racine->d);

    display(racine);
}



int main() {

    pair* temp1 = malloc(sizeof(pair));
    temp1->valeur0=1;
    temp1->valeur1=1;

    pair* temp2 = malloc(sizeof(pair));
    temp2->valeur0=2;
    temp2->valeur1=2;

    pair* temp3 = malloc(sizeof(pair));
    temp3->valeur0=3;
    temp3->valeur1=3;

    pair* temp4 = malloc(sizeof(pair));
    temp4->valeur0=4;
    temp4->valeur1=4;

    pair* temp5 = malloc(sizeof(pair));
    temp5->valeur0=5;
    temp5->valeur1=5;

    pair* temp6 = malloc(sizeof(pair));
    temp6->valeur0=6;
    temp6->valeur1=6;

    pair* temp7 = malloc(sizeof(pair));
    temp7->valeur0=7;
    temp7->valeur1=7;




    arbre* a=malloc(sizeof(arbre));
    a->cle="nathan_e";
    a->p=temp1;
    a->g=NULL;
    a->d=NULL;

    insert("nathan_g",temp2,a);
    insert("nathan_d",temp3,a);
    insert("nathan_a",temp4,a);
    insert("nathan_b",temp5,a);
    insert("nathan_f",temp6,a);
    insert("nathan_h",temp7,a);
    displayR(a);

    pair* ptemp = malloc(sizeof(pair));
    ptemp=Recherche("nathan_f",a);
    if(ptemp==NULL){
        printf("Le noeud n'existe pas\n");
    }
    else{
        printf("\n");
        printf("%d",ptemp->valeur0);
        printf("\n");
        printf("%d",ptemp->valeur1);
        printf("\n");
    }
    printf("Hello, World!\n");
}
