#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct emp
{
   char ename[20];
   int age;
}e1[100],t;

void write(struct emp e1[100],int n)
{
     FILE *fp2;
     int i;
     fp2=fopen("sortedemponage.txt","w");
     for(i=0;i<n;i++)
     {
       fprintf(fp2,"\n%s\t%d",e1[i].ename,e1[i].age);
     }
     fclose(fp2);
}

int quicksort(struct emp e1[100],int start,int end)
{
    int next,prev,pivot;
    if(start<end)
    {
       next=start+1;
       pivot=e1[start].age;
       prev=end;
       while(next<=prev)
       {
         while(e1[next].age<=pivot&&next<=end)
            next++;
         while(e1[prev].age>=pivot&&prev>=start)
             prev--;
          if(next<=prev)
           {
              t=e1[next];
             e1[next]=e1[prev];
             e1[prev]=t;
           }
       }

       t=e1[prev];
      e1[prev]=e1[start];
      e1[start]=t;

      quicksort(e1,start,prev-1);
      quicksort(e1,prev+1,end);
    }
}

 /*int mergesort(struct emp e1[100],int start,int mid,int end)
{
    struct emp b[100];
    int i,j,k;
    i=start;
    j=mid+1;
    k=start;

    while(i<=mid&&j<=end)
    {
       if(e1[i].age<e1[j].age)
        {
          b[k++]=e1[i++];
        }
       else
        {
          b[k++]=e1[j++];
        }
    }

    while(i<=mid)
     {
       b[k++]=e1[i++];
     }
    while(j<=mid)
    {
       b[k++]=e1[j++];
    }

    for(i=0;i<k;i++)
     {
        e1[start+i]=b[i];
     }
}

int divide(struct emp e1[100],int start,int end)
{
   int mid;
    if(start<end)
     {
        mid=(start+end)/2;
        divide(e1,start,mid);
        divide(e1,mid+1,end);
        mergesort(e1,start,mid,end);
     }
}*/

int main()
{
    int i,n;
    FILE *fp1;
    fp1=fopen("emp.txt","r");
    if(fp1==NULL)
    {
      printf("\nfile not found");
      exit(0);
    }

     i=0;
     while(!feof(fp1))
    {
       fscanf(fp1,"%s%d",e1[i].ename,&e1[i].age);
       i++;
    }

   n=i-1;

   //divide(e1,0,n);
   //write(e1,n);
   //printf("\nfile copy successfully");

   quicksort(e1,0,n-1);
   write(e1,n);
   printf("\nfile copy successfully");
}
