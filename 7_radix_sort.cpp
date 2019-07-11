#include<iostream>
#include<vector>

using namespace std;

class radixsort
{
public:
    int maxbit(vector<int> &data) //辅助函数，求数据的最大位数
    {
        int d = 1; //保存最大的位数
        int p = 10;
        int n = data.size();
        for(int i = 0; i < n; ++i)
        {
            while(data[i] >= p)
            {
                p *= 10;
                ++d;
            }
        }
        return d;
    }

    vector<int> radixSort(vector<int> &data) //基数排序
    {
        int n = data.size();
        int d = maxbit(data);
        int *tmp = new int[n];//申请一个动态整型数组，长度为n
        int *count = new int[10]; //计数器
        int i, j, k;
        int radix = 1;
        for(i = 1; i <= d; i++) //进行d次排序
        {
            for(j = 0; j < 10; j++)
                count[j] = 0; //每次分配前清空计数器
            for(j = 0; j < n; j++)
            {
                k = (data[j] / radix) % 10; //统计每个桶中的记录数
                count[k]++;                 //count[k]中的元素是此位数上为k的个数
            }
            for(j = 1; j < 10; j++)
                count[j] = count[j - 1] + count[j]; //count[j]表示此位上不大于j的元素个数
            for(j = n-1; j >= 0; j--) //将tmp中的位置依次分配给每个桶，将所有桶中记录依次收集到tmp中
            {
                k = (data[j] / radix) % 10;
                tmp[count[k] - 1] = data[j];
                count[k]--;
            }
            for(j = 0; j < n; j++) //将临时数组的内容复制到data中
                data[j] = tmp[j];
            radix = radix * 10;
        }
        delete[]tmp;
        delete[]count;

        return data;
    }
};

int main()
{
    vector<int> test{1,2,4,5,3,2,5,66,88,66,55,43,9340};
    radixsort solu;
    vector<int> ans;
    ans = solu.radixSort(test);

    for(auto c : ans)
        cout << c << endl;
    return 0;
}
