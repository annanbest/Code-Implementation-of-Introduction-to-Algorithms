#include<iostream>
#include<vector>

using namespace std;

class radixsort
{
public:
    int maxbit(vector<int> &data) //���������������ݵ����λ��
    {
        int d = 1; //��������λ��
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

    vector<int> radixSort(vector<int> &data) //��������
    {
        int n = data.size();
        int d = maxbit(data);
        int *tmp = new int[n];//����һ����̬�������飬����Ϊn
        int *count = new int[10]; //������
        int i, j, k;
        int radix = 1;
        for(i = 1; i <= d; i++) //����d������
        {
            for(j = 0; j < 10; j++)
                count[j] = 0; //ÿ�η���ǰ��ռ�����
            for(j = 0; j < n; j++)
            {
                k = (data[j] / radix) % 10; //ͳ��ÿ��Ͱ�еļ�¼��
                count[k]++;                 //count[k]�е�Ԫ���Ǵ�λ����Ϊk�ĸ���
            }
            for(j = 1; j < 10; j++)
                count[j] = count[j - 1] + count[j]; //count[j]��ʾ��λ�ϲ�����j��Ԫ�ظ���
            for(j = n-1; j >= 0; j--) //��tmp�е�λ�����η����ÿ��Ͱ��������Ͱ�м�¼�����ռ���tmp��
            {
                k = (data[j] / radix) % 10;
                tmp[count[k] - 1] = data[j];
                count[k]--;
            }
            for(j = 0; j < n; j++) //����ʱ��������ݸ��Ƶ�data��
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
