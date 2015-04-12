#include <stdio.h>

int animal[50001];
int eat[50001];
int deeat[50001];

int fid(int t)//���ұ���
{
    if(animal[t]==t)
        return t;
    return animal[t]=fid(animal[t]);
}
int fideat(int t)//���ҳԼ�
{
    int e=eat[fid(t)];
    if(e!=-1)
        return eat[t]=fid(e);
    return -1;
}
int fiddeeat(int t)//���ұ��Լ�
{
    int de=deeat[fid(t)];
    if(de!=-1)
        return deeat[t]=fid(de);
    return -1;
}

void mrg(int a,int b)//a��bͬ���ϵ�ϲ�
{
    a=fid(a);
    b=fid(b);

    if(a==b)//ͬһ����
        return;

    int ae=fideat(a),be=fideat(b);//��a�ĳԼ�׷�ӵ�b�ĳԼ���
    if(ae!=-1)
    {
        if(be!=-1)
            animal[ae]=be;
        else
        {
            eat[b]=ae;
            be=ae;
        }
    }
    int ade=fiddeeat(a),bde=fiddeeat(b);//��b�ĳԼ�׷�ӵ�a�ĳԼ���
    if(ade!=-1)
    {
        if(bde!=-1)
            animal[ade]=bde;
        else
        {
            deeat[b]=ade;
            bde=ade;
        }
    }
    animal[a]=b;//��a�ļ���׷�ӵ�b�ļ�����

    //��֤���Ϲ�ϵһ����
    if(be!=-1)
    {
        int bee=fideat(be);
        if(bee==-1&&bde!=-1)
            eat[be]=bde;
    }
    if(bde!=-1)
    {
        int bdede=fiddeeat(bde);
        if(bdede==-1&&be!=-1)
            deeat[bde]=be;
    }
}
void mrgeat(int a,int b)//a��b��ϵ�ϲ�
{
    int ae=fideat(a);
    b=fid(b);

    if(ae==b)
        return;

    a=fid(a);
    int ade=fiddeeat(a);
    int be=fideat(b),bde=fiddeeat(b);
    if(bde!=-1)
        animal[a]=bde;
    else
    {
        deeat[b]=a;
        bde=a;
    }
    if(ae!=-1)
        animal[ae]=b;
    if(ade!=-1)
    {
        if(be!=-1)
            animal[ade]=be;
        else
        {
            eat[b]=ade;
            be=ade;
        }
    }

    //��֤���Ϲ�ϵһ����
    int bdee=fideat(bde);
    if(bdee!=b)
        eat[bde]=b;
    if(be!=-1)
    {
        int bee=fideat(be);
        if(bee==-1&&bde!=-1)
            eat[be]=bde;
        int bede=fiddeeat(be);
        if(bede=-1)
            deeat[be]=b;
        int bdede=fiddeeat(bde);
        if(bdede==-1&&be!=-1)
            deeat[bde]=be;
    }
}

int main()
{
    int N,K,sum=0;
    int x,y,d;
    scanf("%d %d",&N,&K);
    for(int i=0;i<=N;i++)//��ʼ��
    {
        animal[i]=i;
        eat[i]=-1;
        deeat[i]=-1;
    }
    for(int i=0;i<K;i++)
    {
        scanf("%d %d %d",&d,&x,&y);
        if(x>N||y>N)//������Χ���ٻ�
        {
            sum++;
            continue;
        }
        x=fid(x);
        y=fid(y);
        if(d==1)//ͬ���ϵ�������
        {
            int xe=fideat(x),ye=fideat(y);
            if(xe!=-1)
            {
                if(xe==y)//x��y���ٻ�
                {
                    sum++;
                    continue;
                }
            }
            if(ye!=-1)
            {
                if(ye==x)//y��x���ٻ�
                {
                    sum++;
                    continue;
                }
            }
            int xde=fiddeeat(x),yde=fiddeeat(y);
            if(xde!=-1)
            {
                if(xde==y)//x��y�ԣ��ٻ�
                {
                    sum++;
                    continue;
                }
            }
            if(yde!=-1)
            {
                if(yde==x)//y��x�ԣ��ٻ�
                {
                    sum++;
                    continue;
                }
            }

            mrg(x,y);//ͬ��ϲ�
        }
        else//x��y��ϵ
        {
            if(x==y)//ͬ�࣬�ٻ�
            {
                sum++;
                continue;
            }
            int ye=fideat(y);
            if(ye!=-1&&ye==x)//y��x���ٻ�
            {
                sum++;
                continue;
            }

            mrgeat(x,y);//�Թ�ϵ�ϲ�
        }
    }
    printf("%d\n",sum);
    return 0;
}

//������˼·�ο���http://blog.csdn.net/jxust_tj/article/details/43668901
