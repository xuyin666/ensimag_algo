#include <stdio.h>


int min(int a, int b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}

int monnaie(int n, int sommes,int* v){
    if(n<0) return 1000;
    if(sommes<0) return 1000;
    if(sommes==0) return 0;
    int m1=1+monnaie(n,sommes-v[n],v);
    int m2=monnaie(n-1,sommes,v);
    if(min(m1,m2)==m1){
        return m1;
    }else{
        return m2;
    }
}


int main (int argc, char** argv){
    //printf("Hello world\n");
    int tab[4]={1,3,4,10};
    int a[4]={0,0,0,0};
    int tt=monnaie(3,8,tab);
    printf("we choose %d monnaie\n",tt);
    return 0;
}
