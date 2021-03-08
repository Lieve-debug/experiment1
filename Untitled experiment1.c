#include<stdio.h>
#include<string.h>
#define N 128
struct data1/*用于存储候选人信息*/
{
    char name[N];
    int a1;
    int a2;
};
struct data2/*用于存储投票人信息*/
{
    int b;
    char n1[N];
    char n2[N];
};
void main()
{
    int m,i,j,k,l,min,o,t,minj;
    char u[N],null[N];
    printf("请输入候选人人数:");
    scanf("%d",&m);
    struct data1 d1[m];/*系统初始化*/
    for(i=0;i<m;i++)
    {
        printf("请输入第%d个候选人姓名：",i+1);
        scanf("%s",d1[i].name);
        d1[i].a1=0;
        d1[i].a2=0;
    }
    struct data2 d2[30];
    for(o=0;;o++)
    {
    for(i=0;i<30;i++)/*学生投票*/
    {
        printf("请输入学号完成投票（输入-1结束）：");
        scanf("%d",&d2[i].b);
        for(j=0;j<i;j++)
        {
            if(d2[i].b==d2[j].b)
            {
                printf("该学号已完成投票！\n");
                printf("请输入学号完成投票（输入-1结束）：");
                scanf("%d",&d2[i].b);
                break;
            }
        }
        if(d2[i].b==-1) break;
        for(j=0;j<m;j++)
        {
            printf("%s",d1[j].name);
            printf(" 班长：%d/%d ",d1[j].a1,i);
            printf("团支书：%d/%d\n",d1[j].a2,i);
        }
        printf("请输入你选择的班长：");
        scanf("%s",d2[i].n1);
        for(j=0;j<m;j++)
        {
            if(strcmp(d2[i].n1,d1[j].name)==0) d1[j].a1++;
        }
        printf("请输入你选择的团支书：");
        scanf("%s",d2[i].n2);
        for(j=0;strcmp(d2[i].n2,d2[i].n1)==0;j++)
        {
            printf("你选择的团支书与班长不允许是同一人，请重新输入你选择的团支书：");
            scanf("%s",d2[i].n2);
        }
        for(j=0;j<m;j++)
        {
            if(strcmp(d2[i].n2,d1[j].name)==0) d1[j].a2++;
        }
        printf("你已完成投票，谢谢！\n");
    }
    printf("%d\n",i);/*显示投票学生人数*/
    for(k=0;k<i;k++)/*显示学号清单*/
    {
        printf("%d\n",d2[k].b);
    }
    printf("共%d人投票\n",i);/*显示候选人得票情况*/
    for(k=0;k<m;k++)
    {
        printf("%s（班长得%d票，团支书得%d票）\n",d1[k].name,d1[k].a1,d1[k].a2);
    }
    for(k=0;k<m-1;k++)/*显示班长投票结果*/
    {
        min=k;
        minj=d1[k].a1;
        for(l=k+1;l<m;l++)
        {
            if(d1[l].a1>minj)
            {
                min=l;
                minj=d1[l].a1;
            }
        }
        if(min!=k)
        {
            t=d1[k].a1;
            d1[k].a1=d1[min].a1;
            d1[min].a1=t;
            t=d1[k].a2;
            d1[k].a2=d1[min].a2;
            d1[min].a2=t;
            strcpy(u,d1[k].name);
            strcpy(d1[k].name,d1[min].name);
            strcpy(d1[min].name,u);
        }
    }
    printf("班长：\n");
    for(k=0;k<m;k++)
    {
        printf("%s（%d/%d）\n",d1[k].name,d1[k].a1,i);
    }
    for(k=0;k<m-1;k++)/*显示团支书选举结果*/
    {
        minj=d1[k].a2;
        min=k;
        for(l=k+1;l<m;l++)
        {
            if(d1[l].a2>minj)
            {
                min=l;
                minj=d1[l].a2;
            }
        }
        if(min!=k)
        {
            t=d1[k].a1;
            d1[k].a1=d1[min].a1;
            d1[min].a1=t;
            t=d1[k].a2;
            d1[k].a2=d1[min].a2;
            d1[min].a2=t;
            strcpy(u,d1[k].name);
            strcpy(d1[k].name,d1[min].name);
            strcpy(d1[min].name,u);
        }
    }
    printf("团支书：\n");
    for(k=0;k<m;k++)
    {
        printf("%s（%d/%d）\n",d1[k].name,d1[k].a2,i);
    }
    for(i=0;i<m;i++)/*清空本次投票数据，准备下一轮投票*/
    {
        d1[i].a1=0;
        d1[i].a2=0;
    }
    }
}
