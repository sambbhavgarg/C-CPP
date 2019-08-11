#include<stdio.h>
int main(){
    FILE *fp1,*fp2;

    fp1=fopen("day.txt","r");
    fp2=fopen("night.txt","r");
    
    fclose(fp1,fp2);
    return 0;
}
