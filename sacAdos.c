#include <stdio.h>

# define N 10
int tab_poids[] = {3,7,1,2,8,2,9,1,3,1};
int tab_val[] =   {1,1,3,1,2,3,3,1,3,9};

int poids_max = 10;

int max(int d1,int d2){
    if(d1>d2)
        return d1;
    else
        return d2;
}

int valueMax(int nbObjet,int poidsReste){
    if(poidsReste<0)
        return -1000;
    if(nbObjet==0 || poidsReste==0)
        return 0;
    else
        return max(tab_val[nbObjet]
          +valueMax(nbObjet-1,poidsReste-tab_poids[nbObjet]),
          valueMax(nbObjet-1,poidsReste));
}

int* getElement(int nbObjet,int poidsReste){
    static int path[10] = {0,0,0,0,0,0,0,0,0,0};
    if(poidsReste<0)
        return NULL;
    if(nbObjet==0 || poidsReste==0)
        return path;
    else{
        if (max(tab_val[nbObjet]
          +valueMax(nbObjet-1,poidsReste-tab_poids[nbObjet]),
                valueMax(nbObjet-1,poidsReste))==(tab_val[nbObjet]
                  +valueMax(nbObjet-1,poidsReste-tab_poids[nbObjet]))){
            path[nbObjet]=1;
            return getElement(nbObjet-1,poidsReste-tab_poids[nbObjet]);
        }
        else{
            path[nbObjet]=0;
            return getElement(nbObjet-1,poidsReste);
        }
    }

}

int main() {

    int vM=valueMax(N-1,10);
    printf("value Max %d\n",vM);

    int* p=getElement(N-1,10);
    for(int i=0;i<=N-1;i++)
        printf("%d => %d\n",i,p[i]);

    printf("Hello, World!\n");
}
