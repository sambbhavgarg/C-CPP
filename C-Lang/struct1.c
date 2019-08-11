/*array draw back: only one type of data types, fixed size(without malloc), insertion and deletion and deletion of array is tough, contiguousity 
char s1[20];
//s1="Hello";// wrong.
strcpy(s1,"hello");
structure: collection of elements of different data types. 
syntax:
struct student//struct student is a data-type, initialization: struct student s1->data_type variable; global or local fn. variable: 
{
10 char name[10];
4  int sapid;
8  float cgpa;
//size 22
}s1,
s2
;individual tokens, global structure variable by default.
-> dot operator is used to access structure member using structure variable(s1.sapid=25;s1.cgpa=2.4;)
1.WAP to declare structure of a student, scan and display values.

#include<stdio.h>
struct stud
{
 char name[20];
 int sapid;
 float cgpa;
};
int main()
{
 struct stud s;
 printf("Enter name, sapid, and cgpa of student: ");
 gets(name);
 scanf("%d %f", &s.sapid,&s.cgpa);
 printf("name: ");puts(name);
 printf("cgpa: %f sapid: %d",s.cgpa,s.sapid);
 return 0;
} 
2. WAP to scan details of three students and find sum of cgpa of three

#include<stdio.h>
struct stud
{
 char name[20];
 int sapid;
 float cgpa;
};
int main()
{
 struct stud s1,s2,s3;
 float sum;
 printf("Enter name, sapid, and cgpa of student 1: ");
 scanf("%s",s1.name);
 scanf("%d %f", &s1.sapid,&s1.cgpa);
 printf("Enter name, sapid, and cgpa of student 2: ");
 scanf("%s",s2.name);
 scanf("%d %f", &s2.sapid,&s2.cgpa);
 printf("Enter name, sapid, and cgpa of student 3: ");
 scanf("%s",s3.name);
 scanf("%d %f", &s3.sapid,&s3.cgpa);
 sum=s1.cgpa+s2.cgpa+s3.cgpa;
 printf("sum of three CGPAs is: %f",sum);
 }
 
 #include<stdio.h>
struct stud
{
 int marks;
};
int main()
{int n,i,hmarks;
struct stud s[10];
 
 //printf("enter number of students: ");
 //scanf("%d",n);
 //struct stud st[n];
 for(i=1;i<=10;i++)
 {
 printf("Enter marks(on 100) of student %d: ",i);
 scanf("%d",&s[i].marks);
 }
 hmarks=s[1].marks;
 n=1;
 for(i=2;i<=10;i++)
 { 
 if(s[i].marks>hmarks)
  {
  hmarks=s[i].marks;
  n=i;
  }
  }
  printf("highest marks student = %d",i);
  
  }
  //complete code
  */


 
 


