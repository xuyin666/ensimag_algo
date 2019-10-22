#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max (int a, int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

int common_substring_long(char* str,int lA,int lenA,char* str1,int lB,int lenB){
    if(lA==lenA || lB==lenB)
        return 0;
    if(str[lA]==str1[lB]){
        return common_substring_long(str,lA+1,lenA,str1,lB+1,lenB)+1;
    }
    else{
        int a = common_substring_long(str,lA+1,lenA,str1,lB,lenB);
        int b = common_substring_long(str,lA,lenA,str1,lB+1,lenB);
        return max(a,b);
    }
    return 0;
}

int main(int argc, char** argv){
    //printf("Hello world\n");
    char* str="hello,world";
    char* str1="h1lo wwwor";
    int lenA=strlen(str);
    int lenB=strlen(str1);
    printf("s is %s\ns1 is %s\n",str,str1);
    int nb=common_substring_long(str,0,lenA,str1,0,lenB);
    printf("the common longest substring is %d\n",nb);
}
