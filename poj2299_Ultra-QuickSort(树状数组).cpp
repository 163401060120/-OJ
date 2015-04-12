#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

#define lowbit(t) (t&(-t))

struct type{
    int num,index;
}num[500005];

int N,C[500005];//������ƶ�����ǰ׺��������״����

bool cmp(struct type a,struct type b)
{
    return a.num<b.num;
}

int sum(int *C,int e)
{
    int sum = 0;
    while(e > 0)
    {
        sum += C[e];
        e -= lowbit(e);
    }
    return sum;
}

void add(int *C,int pos, int num)
{
    while(pos <= N)
    {
        C[pos] += num;
        pos += lowbit(pos);
    }
}

//������ð��������������ݽ�������������±�ð�ݣ��������ۼӴ�������ǰ����е�δ�������ݸ���
int main()
{
    __int64 solve;
    while(1)
    {
        scanf("%d",&N);
        if(N==0)
            break;
        memset(C,0,(N+1)*sizeof(int));
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&num[i-1].num);//�������
            num[i-1].index=i;//��¼�±���
            add(C,i,1);//��ʼ����״����
        }
        add(C,1,-1);//��״�������ݴ���
        sort(num,num+N,cmp);//����
        solve=0;
        for(int i=0;i<N;i++)
        {
            solve+=sum(C,num[i].index);//�ۼ��ƶ�����
            add(C,num[i].index,-1);//ȡ���Ѵ������ݵı��
        }
        printf("%I64d\n",solve);
    }
    return 0;
}
