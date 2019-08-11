#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i=0,n,sum=0;
    int arr[5];
    /*
    do{
        if(scanf("%d",&n)){
        arr[i]=scanf("%d",&n);
        i++;
    }
        else
            arr[i]=0;
    }while(scanf("%d",&n));
*/
    for(int i=0;i<50;i++){
        sum+=arr[i];
    }
    for(int i=1;i<=20;i++){
        if((pow(i,2)-sum)>0)
        {
            int a=pow(i,2)-sum;
            unsigned int b=pow(i-1,2)-sum;
            if(a>b)
                arr[0]+=a;
            else
                arr[0]+=b;
        }
    }
    for(int i=0;i<50;i++){
        if(arr[i]=0)
            continue;
        else
            printf("%d ",arr[i]);
    }
    return 0;
}
