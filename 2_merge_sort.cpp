#include<iostream>
#include<vector>
#include<limits>

using namespace std;

class mergeSort {
public :
    void mergeSortSubroutine(vector<int> &A,int p, int q, int r)
    {
        int n1 = q - p + 1;
        int n2 = r - q;
        vector<int> L(n1+1);
        vector<int> R(n2+1);
        for(int i = 0;i < n1;i++)
        {
            L[i] = A[i+p];
        }
        L[n1] = INT_MAX;
        for(int i = 0;i < n2;i++)
        {
            R[i] = A[i+q+1];
        }
        R[n2] = INT_MAX;

        int x = 0,y = 0;
        for(int i = p;i <= r;i++)
        {
            if(L[x] <= R[y])
            {
                A[i] = L[x];
                x++;
            }
            else
            {
                A[i] = R[y];
                y++;
            }
        }
    }

    void mergeSortFun(vector<int> &A, int p, int r)
    {
        if(r <= p)
            return;
        int q = (p + r) / 2;
        mergeSortFun(A,p,q);
        mergeSortFun(A,q+1,r);
        mergeSortSubroutine(A,p,q,r);
    }
};

int main()
{
    vector<int> test{1,2,4,5,3,2,5,66,88,66,55,43,934};
    int n = test.size()-1;
    mergeSort sort1;
    sort1.mergeSortFun(test,0,n);
    for(auto c : test)
        cout << c << endl;
    return 0;
}
