
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int sc(char* a, char* b){
    int i=0;
    int j=0;
    int lenA=strlen(a);
    int lenB=strlen(b);
    int trouve;
    for(i=0;i<=lenA-lenB;i++){
        trouve=1;
        for(j=0;j<=lenB-1;j++){
            if(a[i+j]!=b[j]){
                trouve=0;
                break;
            }
        }
        if(trouve==1){
            return 1;
        }
    }
    return 0;
}

bool scD(char* a, char* b){
    int i=0;
    int j=0;
    int lenA=strlen(a);
    int lenB=strlen(b);
    if(lenB==0)
        return true;
    if(lenA==0)
        return false;
    if(a[0]==b[0])
        return scD(++a,++b);
    else
        return scD(++a,b);
}

int min(int d1, int d2){
    if(d1<d2)
        return d1;
    else
        return d2;
}

int max(int d1,int d2){
    if(d1>d2)
        return d1;
    else
        return d2;
}

int d (char* a, char* b){
    int i=0;
    int j=0;
    int lenA=strlen(a);
    int lenB=strlen(b);
    if(lenA==lenB && lenB==0)
        return 0;
    if(lenA==0 || lenB==0)
        return max(lenA,lenB);

    if(a[0]==b[0])
        return d(++a,++b);
    else{
        int d1=d(++a,++b)+1;  //replacement
        int d2=d(a,++b)+1;    // add
        int d3=d(++a,b)+1;    // delete
        return min(d1,min(d2,d3));
    }


}


int main() {
    char A[]="abcdef";
    char B[]="abcd";
    char C[]="acf";
    char D[]="acef";
    if(sc(A,C)==1)
        printf("OK\n");
    else
        printf("NotOK\n");

    if(scD(A,D)==true)
        printf("OK\n");
    else
        printf("NotOK\n");

    char E[]="Nicolas";
    char F[]="Gilda";
    int a=d(E,F);
    printf("%d\n",a);


    printf("Hello, World!\n");
}

