#include<stdio.h>
#include<algorithm>

using namespace std;

int prime[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,51};

struct stick
{
    int len;//ľ����
    int num;//ʣ��ľ������
};
bool cmpn(struct stick a,struct stick b)
{
    return a.num>b.num;
}
bool cmpl(struct stick a,struct stick b)
{
    return a.len>b.len;
}

struct stick sticks1[51],sticks[51];

bool dfs(int limit,int value,int leave,int num,int start)
{
    int i;
    if(leave==0)//ƥ����һ��ľ��
    {
        if(num<=2)//ȫ��ľ��ƥ�䣬���һ��ľ���Զ�ƥ��
            return true;
        else
            return dfs(limit,value,value,num-1,0);
    }
    if(sticks[limit-1].len>leave)
        return false;
    for(i=start;i<limit;i++)//�Ӵ�С����ѡ��
    {
        if(sticks[i].num>0)
        {
            if(sticks[i].len<=leave)
            {
                sticks[i].num--;
                if(dfs(limit,value,leave-sticks[i].len,num,i))
                    return true;
                sticks[i].num++;
                if(sticks[i].len==leave)//����ǡ��ƥ��ľ�����ѡ������ſ��Ǹ�С��ľ��
                    return false;
            }
            if(leave==value)//��һ��ľ����ѡ���
                return false;
        }
    }
    return false;
}

int main()
{
    int i,j,k,limit,t;
    int sum,num1;
    while(1)
    {
        scanf("%d",&num1);
        if(num1==0)
            break;
        sum=0;
        for(i=0;i<=50;i++)
        {
            sticks1[i].len=i;
            sticks1[i].num=0;
        }
        for(i=0;i<num1;i++)
        {
            scanf("%d",&j);
            sticks1[j].num++;
            sum+=j;
        }
        sort(sticks1,sticks1+51,cmpn);//����������
        for(i=0;i<=51;i++)
            if(sticks1[i].num==0)
                break;
        limit=i;//ľ��������
        sort(sticks1,sticks1+limit,cmpl);//����������
        for(i=num1;i>1;i--)//ԭ��i��ľ��
        {
            if(sum%i!=0)//С�����Ȳ�Ϊ����
                continue;
            if(sum/i<sticks1[0].len)//�����޷������С��
                continue;
            t=i;
            for(j=0;j<limit;j++)//��ȡľ������
                sticks[j]=sticks1[j];
            for(k=1;prime[k]<=t;k++)
            {
                if(t%prime[k]!=0)
                    continue;
                for(j=0;j<limit;j++)
                    if(sticks[j].num%prime[k]!=0)
                        break;
                if(j==limit)//�Թ�����Ѱ��ͬ����
                {
                    for(j=0;j<limit;j++)
                        sticks[j].num/=prime[k];
                    t/=prime[k];
                    k--;
                }
            }
            if(t==1)
                break;
            if(dfs(limit,sum/i,sum/i,t,0))//ƥ��ɹ�
                break;
        }
        printf("%d\n",sum/i);
    }
    return 0;
}
