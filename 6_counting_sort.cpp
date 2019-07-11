#include<iostream>
#include<vector>

using namespace std;

class countingsort
{
public:
    vector<int> countingSort(vector<int> &A,int k)   //A中元素都不大于k
    {
        vector<int> C(k,0);
        for(int i = 0;i < A.size();i++)
            C[A[i]] = C[A[i]] + 1;                  //C[i]中的值是A中i的个数，且A中的值在C中当作下标排好了序
        for(int j = 1;j <= k;j++)
            C[j] = C[j] + C[j-1];             //C[i]中的值是不大于i的元素的个数
        /***************************
        接下来将i按顺序放入B中
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
    vector<int> test{1,2,4,5,3,2,5,66,88,66,55,43,9340};//934不行，不知道什么鬼bug
    countingsort solu;
    vector<int> ans;
    ans = solu.countingSort(test,9340);

    for(auto c : ans)
        cout << c << endl;
    return 0;
}
