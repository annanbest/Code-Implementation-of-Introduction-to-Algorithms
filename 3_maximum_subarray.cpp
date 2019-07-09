#include<iostream>
#include<vector>

using namespace std;

class maximum_subarray
{
public :
    struct maxSubarray
    {
        int low;
        int high;
        int maxSum;
    };

    maxSubarray findMaxCrossingSubarray(vector<int> &A,int low,int mid,int high)
    {
        int leftSum = INT_MIN;
        int Lsum = 0;
        int maxLeft;
        for(int i = 0;i <= (mid-low);i++)
        {
            Lsum = Lsum + A[mid - i];
            if(Lsum > leftSum)
            {
                leftSum = Lsum;
                maxLeft = mid - i;
            }
        }

        int rightSum = INT_MIN;
        int Rsum = 0;
        int maxRight;
        for(int i = 0;i <= (high - mid);i++)
        {
            Rsum = Rsum + A[mid + i];
            if(Rsum > rightSum)
            {
                rightSum = Rsum;
                maxRight = mid + i;
            }
        }

        int maxCrossingSubarray;
        maxCrossingSubarray = leftSum + rightSum;

        maxSubarray ans = {maxLeft,maxRight,maxCrossingSubarray};

        return ans;
    }



    maxSubarray findMaximunSubarray(vector<int> &A,int low,int high)
    {
        if(low == high)
        {
            maxSubarray ans1;
            ans1 = {low,high,A[low]};
            return ans1;
        }
        else
        {
            maxSubarray ans2,ans3,ans4;
            int mid = (low + high)/2;
            ans2 = findMaximunSubarray(A,low,mid);
            ans3 = findMaximunSubarray(A,mid + 1,high);
            ans4 = findMaxCrossingSubarray(A,low,mid,high);
            if(ans2.maxSum >= ans3.maxSum && ans2.maxSum >= ans4.maxSum)
                return ans2;
            else if(ans3.maxSum >=ans2.maxSum && ans3.maxSum >= ans4.maxSum)
                return ans3;
            else if(ans4.maxSum >= ans2.maxSum && ans4.maxSum >=ans3.maxSum)
                return ans4;
        }

    }
};

int main()
{
    vector<int> test{13,-3,-25,20,13,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    maximum_subarray solu;
    int n = test.size();
    solu.findMaximunSubarray(test,0,n);
    cout << solu.findMaximunSubarray(test,0,n).low <<endl;
    cout << solu.findMaximunSubarray(test,0,n).high <<endl;
    cout << solu.findMaximunSubarray(test,0,n).maxSum << endl;
    return 0;
}
