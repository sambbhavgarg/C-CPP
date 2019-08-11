#include<stdio.h>

int isBetter(int a[],int b[])
{
  if(a[0]<=b[0] && a[1]<=b[1] && a[2]<=b[2])
    {
      if(a[0]<b[0] || a[1]<b[1] || a[2]<b[2])
  return 1;
    }
  else if(b[0]<=a[0] && a[1]>=b[1] && a[2]>=b[2])
    {
      if(a[0]>b[0] || a[1]>b[1] || a[2]>b[2])
  return 1;
    }
  else return 0;
}

int main()
{
  int T;
  scanf("%d",&T);

  while(T--)
    {
      int i,count,a,b,c,s1[3],s2[3],s3[3];
      for(i=0;i<3;i++)
  {
    scanf("%d ",(s1+i));
  }
      for(i=0;i<3;i++)
  {
    scanf("%d ",(s2+i));
  }
      for(i=0;i<3;i++)
  {
    scanf("%d ",(s3+i));
  }
      a=isBetter(s1,s2);
      b=isBetter(s3,s2);
      c=isBetter(s1,s3);
      count=a+b+c;
      if(count==3)printf("yes\n");
      else printf("no\n");
    }
  return 0;
}
