#include <stdio.h>

int lst[14];
int main()
{
    int i,j;
    int s,m,t,k;
    // ���
    for(k=1;k<14;k++)
    {
        for(m=k;1;++m)
        {
            s=0;
            for(t=k*2;t>k;--t)//���������ݼ���ͬʱ�ı��׺�˵ı��
            {
                s=(s+m)%t;
                if(s<k)//�����˵ı�űش���k������ʧ��
                    break;
            }
            if(t==k)//�ɹ�
                break;
        }
        lst[k]=m+1;
    }
    while(1)
    {
        scanf("%d",&k);
        if(k==0)
            break;
        printf("%d\n",lst[k]);
    }
    return 0;
}
