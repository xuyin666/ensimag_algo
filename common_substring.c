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

int common_substring_long(char* str,char* str1){
    char* s;
    char* s1;
    int lenA=strlen(str);
    int lenB=strlen(str1);
    s=malloc(sizeof(char)*lenA);
    s1=malloc(sizeof(char)*lenB);
    strcpy(s,str);
    strcpy(s1,str1);
    if(strlen(s)<0 || strlen(s1)<0)
        return -1000;
    if(strlen(s)==0 || strlen(s1)==0)
        return 0;
    if(s[0]==s1[0]){
        return common_substring_long(++str,++str1)+1;
    }
    else{
        int a = common_substring_long(++str,str1);
        int b = common_substring_long(str,++str1);
        return max(a,b);
    }
    return 0;
}

int main(int argc, char** argv){
    printf("Hello world\n");
    char* str="hello,world";
    char* str1="h1lo wwwor";
    printf("s is %s\ns1 is %s\n",str,str1);
    int nb=common_substring_long(str,str1);
    printf("the common longest substring is %d\n",nb);
}
