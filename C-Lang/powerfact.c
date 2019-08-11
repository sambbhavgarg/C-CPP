#include <stdio.h>
#include <math.h>
int main()
{
int counter,f_coun;
float sum=0,x,power,fact;
printf("Value of x : ");
scanf("%f",&x);
for(counter=0, power=0; power<=10; counter++,power=power+2)
{
fact=1;
for(f_coun=power; f_coun>=1; f_coun--)
{
fact *= f_coun;
}
sum=sum+(pow(-1,counter)*(pow(x,power)/fact));
}
printf("sum of series: %f",sum);
}
