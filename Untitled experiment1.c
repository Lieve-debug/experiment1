#include<stdio.h>
#include<string.h>
#define N 128
struct data1/*���ڴ洢��ѡ����Ϣ*/
{
    char name[N];
    int a1;
    int a2;
};
struct data2/*���ڴ洢ͶƱ����Ϣ*/
{
    int b;
    char n1[N];
    char n2[N];
};
void main()
{
    int m,i,j,k,l,min,o,t,minj;
    char u[N],null[N];
    printf("�������ѡ������:");
    scanf("%d",&m);
    struct data1 d1[m];/*ϵͳ��ʼ��*/
    for(i=0;i<m;i++)
    {
        printf("�������%d����ѡ��������",i+1);
        scanf("%s",d1[i].name);
        d1[i].a1=0;
        d1[i].a2=0;
    }
    struct data2 d2[30];
    for(o=0;;o++)
    {
    for(i=0;i<30;i++)/*ѧ��ͶƱ*/
    {
        printf("������ѧ�����ͶƱ������-1��������");
        scanf("%d",&d2[i].b);
        for(j=0;j<i;j++)
        {
            if(d2[i].b==d2[j].b)
            {
                printf("��ѧ�������ͶƱ��\n");
                printf("������ѧ�����ͶƱ������-1��������");
                scanf("%d",&d2[i].b);
                break;
            }
        }
        if(d2[i].b==-1) break;
        for(j=0;j<m;j++)
        {
            printf("%s",d1[j].name);
            printf(" �೤��%d/%d ",d1[j].a1,i);
            printf("��֧�飺%d/%d\n",d1[j].a2,i);
        }
        printf("��������ѡ��İ೤��");
        scanf("%s",d2[i].n1);
        for(j=0;j<m;j++)
        {
            if(strcmp(d2[i].n1,d1[j].name)==0) d1[j].a1++;
        }
        printf("��������ѡ�����֧�飺");
        scanf("%s",d2[i].n2);
        for(j=0;strcmp(d2[i].n2,d2[i].n1)==0;j++)
        {
            printf("��ѡ�����֧����೤��������ͬһ�ˣ�������������ѡ�����֧�飺");
            scanf("%s",d2[i].n2);
        }
        for(j=0;j<m;j++)
        {
            if(strcmp(d2[i].n2,d1[j].name)==0) d1[j].a2++;
        }
        printf("�������ͶƱ��лл��\n");
    }
    printf("%d\n",i);/*��ʾͶƱѧ������*/
    for(k=0;k<i;k++)/*��ʾѧ���嵥*/
    {
        printf("%d\n",d2[k].b);
    }
    printf("��%d��ͶƱ\n",i);/*��ʾ��ѡ�˵�Ʊ���*/
    for(k=0;k<m;k++)
    {
        printf("%s���೤��%dƱ����֧���%dƱ��\n",d1[k].name,d1[k].a1,d1[k].a2);
    }
    for(k=0;k<m-1;k++)/*��ʾ�೤ͶƱ���*/
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
    printf("�೤��\n");
    for(k=0;k<m;k++)
    {
        printf("%s��%d/%d��\n",d1[k].name,d1[k].a1,i);
    }
    for(k=0;k<m-1;k++)/*��ʾ��֧��ѡ�ٽ��*/
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
    printf("��֧�飺\n");
    for(k=0;k<m;k++)
    {
        printf("%s��%d/%d��\n",d1[k].name,d1[k].a2,i);
    }
    for(i=0;i<m;i++)/*��ձ���ͶƱ���ݣ�׼����һ��ͶƱ*/
    {
        d1[i].a1=0;
        d1[i].a2=0;
    }
    }
}
