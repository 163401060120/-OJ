#include <stdio.h>

inline int max(int a,int b)
{
    return a>b?a:b;
}
inline int min(int a,int b)
{
    return a<b?a:b;
}

//��ֻ���������󣬵����Ǳ���ԭ�������������ǰ���Խ����Ӱ��
int main()
{
    int N,len,n,d,t;
    int maxT,minT;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d%d",&len,&n);
        maxT=0;
        minT=0;
        while(n--)
        {
            scanf("%d",&d);
            t=len-d;
            minT=max(minT,min(d,t));
            maxT=max(maxT,max(d,t));
        }
        printf("%d %d\n",minT,maxT);
    }
    return 0;
}
