#include<iostream>
#include<vector>

using namespace std;

class insertionSort {
public:
    vector<int> insertionSortFun(vector<int> &a)
    {
        int i = 1,j;
        int n = a.size();
        for(i;i < a.size();i++)
        {
            int temp = a[i];
            j = i-1;
            while(a[j] > temp && j >= 0)
            {
                a[j+1] = a[j];
//                j = j-1;
//                a[j+1] = temp;
                a[j] = temp;
                j = j-1;
            }
        }
        return a;
    }
};

int main()
{
    vector<int> test{1,2,4,5,3,2,5,7,2,4,2,4223,12,0};
    insertionSort sort1;
    vector<int> ans;
    ans = sort1.insertionSortFun(test);
    for(auto c : ans)
        cout << c << endl;
    return 0;
}
