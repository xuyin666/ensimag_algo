#include <stdio.h>


void triFusion(int tab[], int l, int r);
void merge(int tab[], int l, int mid, int r);
int arr[]={12,11,13,8,7,5,6,9,10};

int main(int argc, char** argv){
    printf("Hello, world\n");
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++){
        printf("the %d element is %d\n",i,arr[i]);
    }
    printf("**********************************\n");
    triFusion(arr,0,size-1);
    for(int i=0;i<size;i++){
        printf("the %d element is %d\n",i,arr[i]);
    }
}

void triFusion(int tab[], int l, int r){
    if(l<r){
        int mid=(l+r)/2;
        triFusion(tab,l,mid);
        triFusion(tab,mid+1,r);
        merge(tab,l,mid,r);
    }
    else{
        if(tab[l]>tab[r]){
            int temp;
            temp=tab[r];
            tab[r]=tab[l];
            tab[l]=temp;
        }
        //printf("l is %d r is %d tab[l] is (%d) tab[r] is (%d)\n",l,r,tab[l],tab[r]);
    }
}


void merge(int tab[], int l, int mid, int r){

    //for(int i=l;i<r-1;i++){
      //  printf("the %d element is %d\n",i,tab[i]);
      //  printf("----------------------\n" );
    //}
    //printf("the l is %d the mid is %d the r is %d\n",l,mid,r);
    int teml[mid-l+1];
    int temr[r-mid];
    for(int i=0;i<=mid-l;i++){
        teml[i]=tab[l+i];
        //printf("the teml %d element is %d\n",l+i,teml[i]);
    }

    for(int j=0;j<=r-mid-1;j++){
        temr[j]=tab[mid+1+j];
        //printf("the temr %d element is %d\n",mid+1+j,temr[j]);
    }

    int i=0;
    int j=0;
    int k=l;
    while(l+i<=mid && mid+1+j<=r){
        if(teml[i]<temr[j]){
            tab[k]=teml[i];
            ++i;
        }
        else{
            tab[k]=temr[j];
            ++j;
        }
        ++k;
    }

    while(l+i<=mid){
        tab[k]=teml[i];
        ++i;
        ++k;
    }

    while(mid+1+j<=r){
        tab[k]=temr[j];
        ++j;
        ++k;
    }
}
