
//scan details of 3 cities and find
//a. total population, find city w min pop, ratio of pop to area of each city
#include<stdio.h>
struct city
{ char name[20];
  int population;
  float area;
}a,b,c;
int main()
{int  i,tot;
 struct city *p=&a;
 struct city *q=&b;
 struct city *r=&c;
 int arr[3]={a.population,b.population,c.population};
 printf("Enter Name, population, and area of  city 1: ");
 scanf("%s",&p->name);
 scanf("%d",&p->population);
 scanf("%f",&p->area);
 printf("Enter Name, population, and area of  city 2: ");
 scanf("%s",&q->name);
 scanf("%d",&q->population);
 scanf("%f",&q->area);
 printf("Enter Name, population, and area of  city 3: ");
 scanf("%s",&r->name);
 scanf("%d",&r->population);
 scanf("%f",&r->area);
 tot=a.population+b.population+c.population;
 printf("total population is %d",tot);
int max=arr[0];
 for(i=0;i<3;i++)
 {
 if(max<arr[i])
  max=arr[i];
  }
  printf("minimum population is of city %d (%d people)",i,max);
  printf("ratio of population of area of city 1: %f\nratio of population of area of city 2: %f\nratio of population of area of city 3: %f",p->population/p->area,q->population/q->area,r->population/r->area);
}
/*
union union_tag
{
 //union members;
};
eg:
union book
{
int a;
float b;
char[10];
long int d;
}u;
//previous values are overwritten on initialization of

*/
