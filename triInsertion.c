#include <stdio.h>

void triInsertion(int tab[],int nb);
int arr[]={12,11,13,8,7,5,6,9,10};

int main(int argc, char** argv){
    printf("Hello world\n");
    int nb=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<nb;i++){
        printf("the %d element is %d\n",i,arr[i]);
    }
    triInsertion(arr,nb);
    printf("**********************************\n");
    for(int i=0;i<nb;i++){
        printf("the %d element is %d\n",i,arr[i]);
    }
}

void triInsertion(int tab[],int nb){
    int pos=1;
    int i;
    for(i=0;i<nb-1;i++){
        int temp=tab[i+1];
        int j;
        for(j=i;j>=0;j--){
            if(tab[j]>temp){
                tab[j+1]=tab[j];
            }
            else{
                break;
            }
        }
        tab[j+1]=temp;
    }
}
