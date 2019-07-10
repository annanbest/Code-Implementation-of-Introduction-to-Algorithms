#include<iostream>
#include<vector>

using namespace std;

class quicksort
{
public :
    int PARTITION(vector<int> &A,int p,int r)
    {
        int x = A[r];
        int i = p - 1;
        for(int j = p;j <= r - 1;j++)//j�ǵ����ı���������i�Ǵ洢С��x��Ԫ�ص��±�
        {
            if(A[j] <= x)
            {
                i = i + 1;
                int temp1;
                temp1 = A[i];
                A[i] = A[j];
                A[j] = temp1;//�������������x��Ԫ��ȫ���Ƶ�i���Ҳ࣬��֤��i�����ȫ��С��x��ֵ
            }
        }
        int temp2;
        temp2 = A[i+1];
        A[i+1] = A[r];
        A[r] = temp2;//���x��i+1��ֵ������ʵ����i���ȫ������x���Ҳ�ȫ����x

        return i+1;//���طֽ��ߵ�ֵ
    }

    void quickSort(vector<int> &A,int p,int r)
    {
        if(p<r)
        {
            int q = PARTITION(A,p,r);
            quickSort(A,p,q-1);//�ݹ�
            quickSort(A,q+1,r);
        }
    }
};

int main()
{
    vector<int> test{1,2,4,5,3,2,5,66,88,66,55,43,934};
    quicksort solu;
    int n = test.size();
    solu.quickSort(test,0,n-1);

    for(auto c : test)
        cout << c << endl;
    return 0;

}
