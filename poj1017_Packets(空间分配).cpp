#include <stdio.h>

int s[7];

int main()
{
    int sum,t,t2;
    while(1)
    {
        scanf("%d %d %d %d %d %d",s+1,s+2,s+3,s+4,s+5,s+6);

        sum=s[6];//size_6*1����

        sum+=s[5];//size_5*1��size_1*11����
        s[1]-=s[5]*11;//�޳�������size_5��size_1
        if(s[1]<0)
            s[1]=0;

        sum+=s[4];//size_4*1��size_2*5���䣬size_2��������size_1*4�滻
        s[2]-=s[4]*5;//�޳�������size_4��size_2
        if(s[2]<0)
        {
            t=s[2];//size_2�����䣬����ȱ��
            s[2]=0;
        }
        else
            t=0;
        s[1]+=t*4;//�޳�������size_4��size_1
        if(s[1]<0)
            s[1]=0;

        sum+=s[3]/4;//ʹ��size_3*4����
        t=s[3]-(s[3]/4)*4;
        if(t==3)//size_3*3��size_2*1��size_1*5���䣬size_2��������size_1*4�滻
        {
            sum++;
            if(s[2]==0)
                s[1]-=9;
            else
            {
                s[2]--;
                s[1]-=5;
            }
            if(s[1]<0)
                s[1]=0;
        }
        else if(t==2)//size_3*2��size_2*3��size_1*6���䣬size_2��������size_1*4�滻
        {
            sum++;
            s[2]-=3;
            if(s[2]<0)
            {
                t2=s[2];//size_2�����䣬����ȱ��
                s[2]=0;
            }
            else
                t2=0;
            s[1]+=t2*4-6;//�޳�������size_4��size_1
            if(s[1]<0)
                s[1]=0;
        }
        else if(t==1)//size_3*1��size_2*5��size_1*7���䣬size_2��������size_1*4�滻
        {
            sum++;
            s[2]-=5;
            if(s[2]<0)
            {
                t2=s[2];//size_2�����䣬����ȱ��
                s[2]=0;
            }
            else
                t2=0;
            s[1]+=t2*4-7;//�޳�������size_4��size_1
            if(s[1]<0)
                s[1]=0;
        }

        s[2]+=s[1]/4;//��size_1�ϲ���size_2�ϴ���
        s[1]-=(s[1]/4)*4;
        if(s[1]>0)
            s[2]++;
        sum+=s[2]/9;
        s[2]=s[2]-(s[2]/9)*9;
        if(s[2]>0)
            sum++;

        if(sum==0)
            break;
        printf("%d\n",sum);
    }
    return 0;
}
