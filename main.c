

#include<stdlib.h>
#include<stdio.h>
struct student
{
    int numbers;
    char name[10];
    char sex[10];
    int  birth;
    char  classes[15];
    char phone[15];
    int score[10];
    double min;
    double max;
    double average;
};
int main()
{
    
    int j;
    struct student s[100];
    FILE *fp;
    int i=0;
    
    fp=fopen("//Users//s20171105121//Desktop//text707//studentdata.csv","r");
    if(fp==NULL)
    {
        printf("error");
        return -1;
    }
    else
    {
        
        fscanf(fp,"%*[^\n]%*c");
        while(!feof(fp))
        {
            fscanf(fp,"%d,%s,%s,%d,%s,%s,%d,%lf,%lf,%lf",&s[i].numbers,s[i].name,s[i].sex,&s[i].birth,s[i].classes,
                   s[i].phone,s[i].score,&s[i].min,&s[i].max,&s[i].average);
            
            i++;
        }
        
        j=i;
        for(i=0;i<j;i++)
        {
            printf("%d,%s,%s,%d,%s,%s,\n",s[i].numbers,s[i].name,s[i].sex,s[i].birth,s[i].classes,s[i].phone);
        }
        fclose(fp);
    }
    s[i].min=s[i].score[0];
    for(j=0;j<5;j++)
    {
        if(s[i].score[j]<s[i].min)
        {
            s[i].min=s[i].score[j];
        }
    }
    s[i].max=s[i].score[0];
    for(j=0;j<5;j++)
    {
        if(s[i].score[j]>s[i].max)
        {
            s[i].max=s[i].score[j];
        }
    }
    s[i].average=(s[i].score[0]+s[i].score[1]+s[i].score[2]+s[i].score[3]+s[i].score[4]+s[i].score[5]-s[i].min-s[i].max)/3;
}

