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
        for(int j = p;j <= r - 1;j++)//j是迭代的遍历器，而i是存储小于x的元素的下标
        {
            if(A[j] <= x)
            {
                i = i + 1;
                int temp1;
                temp1 = A[i];
                A[i] = A[j];
                A[j] = temp1;//这个交换将大于x的元素全部移到i的右侧，保证了i的左侧全是小于x的值
            }
        }
        int temp2;
        temp2 = A[i+1];
        A[i+1] = A[r];
        A[r] = temp2;//最后将x与i+1的值互换，实现了i左侧全不大于x，右侧全大于x

        return i+1;//返回分界线的值
    }

    void quickSort(vector<int> &A,int p,int r)
    {
        if(p<r)
        {
            int q = PARTITION(A,p,r);
            quickSort(A,p,q-1);//递归
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
