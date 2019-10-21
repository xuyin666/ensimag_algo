#include <stdio.h>


void TriRapide(int tab[],int start,int end);
void swap(int tab[], int a, int b);
int arr[]={12,11,13,8,7,5,6,9,10,15,10,17};

int main(int argc, char** argv){
    printf("Hello world\n");
    int nb=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<nb;i++){
        printf("the %d element is %d\n",i,arr[i]);
    }
    printf("**********************************\n");
    TriRapide(arr,0,nb-1);
    for(int i=0;i<nb;i++){
        printf("the %d element is %d\n",i,arr[i]);
    }
}

void swap(int tab[], int a, int b){
    int temp=tab[a];
    tab[a]=tab[b];
    tab[b]=temp;
}

void TriRapide(int tab[],int start,int end){
    if(start<end){
        int pivot=tab[start];
        int i=start;
        int j=end;
        while(i!=j){
            while(tab[j]>=pivot && i<j){
                --j;
            }
            while(tab[i]<=pivot && i<j){
                ++i;
            }
            if(i<j){
                swap(tab,i,j);
            }
        }
        tab[start]=tab[i];
        tab[i]=pivot;

        TriRapide(tab,start,i-1);
        TriRapide(tab,i+1,end);
    }

}
