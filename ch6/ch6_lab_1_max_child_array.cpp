#include <iostream>

using namespace std;

int MaxSubSum1(int *arr,int len)
{
	int i,j;
	int MaxSum = 0;
	//每次开始累加的起始位置的循环
	for(i=0;i<len;i++)
	{
		int CurSum = 0;
		//向后累加的循环
		for(j=i;j<len;j++)
		{
			CurSum += arr[j];
			if(CurSum > MaxSum)
				MaxSum = CurSum;
		}
	}
	return MaxSum;
}

int main(int argc, char** argv)
{
    int num = 0;
    cin >> num;
    int* ptr = new int[num];

    for(int i=0; i<num; i++)
    {
        cin >> ptr[i];
    }
    cout << MaxSubSum1(ptr, num) << endl;

    delete[] ptr;
    return 0;
}