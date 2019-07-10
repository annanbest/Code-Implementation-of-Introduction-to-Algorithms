/****************************************
heapsort algorithm implementing by C++
****************************************/

#include<iostream>
#include<vector>

using namespace std;

class heapsort
{
public:
    void maxHeapify(vector<int> &A,int i,int heapSize) //i是下标，树从0开始,heapSize是建立的树的尺寸,从0开始的
    {
        int l,r,largest;
        l = 2*i + 1;
        r = 2*i + 2;

        if(l <= heapSize && A[l] > A[i])
        largest = l;
        else largest = i;
        if(r <= heapSize && A[r]> A[largest])
        largest = r;

        if(largest != i)
        {
            int t;
            t = A[largest];
            A[largest] = A[i];
            A[i] = t;
            maxHeapify(A,largest,heapSize);
        }
    }

    void buildMaxHeap(vector<int> &A)
    {
        for(int i = A.size()/2 - 1;i >= 0;i--)
            maxHeapify(A,i,A.size()-1);

    }

    vector<int> heapSort(vector<int> &A)
    {
        int heapSize = A.size()-1;
        buildMaxHeap(A);//建立树，将最大值浮到最上面
        for(int i = A.size()-1;i >= 0;i--)
        {
            int temp;
            temp = A[0];
            A[0] = A[i];
            A[i] = temp;//把最大的放到最后面
            /******************
            除去后面排好的大值，继续将剩余的最大值浮到最上面
            ******************/
            heapSize = heapSize - 1;
            maxHeapify(A,0,heapSize);
        }
        return A;
    }
};

int main()
{
    vector<int> test{1,2,4,5,3,2,5,66,88,66,55,43,934};
    heapsort solu;
//    solu.buildMaxHeap(test);
    solu.heapSort(test);

    for(auto c : test)
        cout << c << endl;
    return 0;

}
