#include<iostream>
#include<vector>

using namespace std;

class countingsort
{
public:
    vector<int> countingSort(vector<int> &A,int k)   //A��Ԫ�ض�������k
    {
        vector<int> C(k,0);
        for(int i = 0;i < A.size();i++)
            C[A[i]] = C[A[i]] + 1;                  //C[i]�е�ֵ��A��i�ĸ�������A�е�ֵ��C�е����±��ź�����
        for(int j = 1;j <= k;j++)
            C[j] = C[j] + C[j-1];             //C[i]�е�ֵ�ǲ�����i��Ԫ�صĸ���
        /***************************
        ��������i��˳�����B��
        ***************************/
        vector<int> B(A.size(),0);

        for(int i = 0;i < A.size();i++)
        {
            B[C[A[i]]-1] = A[i];
            C[A[i]] = C[A[i]] - 1;
        }

        return B;
    }
};

int main()
{
    vector<int> test{1,2,4,5,3,2,5,66,88,66,55,43,9340};//934���У���֪��ʲô��bug
    countingsort solu;
    vector<int> ans;
    ans = solu.countingSort(test,9340);

    for(auto c : ans)
        cout << c << endl;
    return 0;
}
