#include <stdio.h>

int poster[10001][2];//����������Ϣ
int wall[10000001];//��¼������λ�������һ���հף���ʽ����ͨ����ʽ�ṹʹȫ����ÿһ��ֻ������һ��

int main()
{
    int c,n,i,j,temp,sum;
    scanf("%d",&c);
    while(c--)
    {
        for(i=0;i<=10000000;++i)
            wall[i]=i;
        scanf("%d",&n);
        for(i=0;i<n;++i)
            scanf("%d %d",&poster[i][0],&poster[i][1]);
        sum=0;
        while(i--)//������
        {
            temp=poster[i][0];
            while(wall[temp]!=temp&&temp<=poster[i][1])//Ѱ�������ڵ���һ���յ�
                temp=wall[temp];
            if(temp<=poster[i][1])//�ɼ�
            {
                sum++;
                for(j=temp;j<=poster[i][1];++j)//��������ڿհ�λ�õ�ֵΪ������һ���ֵ
                {
                    if(wall[j]==j)
                        wall[j]=poster[i][1]+1;
                    else
                    {
                        j=wall[j]-1;
                    }
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
