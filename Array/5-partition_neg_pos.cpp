#include<iostream>
#include<algorithm>
using namespace std;
/*Swagoto Check this function*/
void rearrange(int* arr, int n)
{
	int i, j;
	i = -1;

	for(j = 0;j < n;j++)
	{
		//if arr[j] is positive
		//considering that 0 is also positive
		if(arr[j] >= 0){
			
			if(i == -1)
				i = j;
		}
		//for negetive
		else
		{
			if(i != -1){
				swap(arr[i], arr[j]);
				i++;
			}
		}
	}
}

void rearrange_double_pointer(int arr[],int n)
{
    int left = 0, right = n - 1;
    while(left < right)
    {
        if(arr[left] >= 0)
         left++;
        else if(arr[right] < 0)
          right--;
        else
            swap(arr[left], arr[right]);
    }
}

void print(int* arr, int n)
{
	for(int i = 0;i < n;i++)
		cout << arr[i] << " ";
	cout << endl;
}
int main()
{
	int arr[] = {-1, 2, 3, 4, -5};
	int size = sizeof(arr) / sizeof(int);
	rearrange(arr, size);
	cout << "After Rearrange: " << endl;
	print(arr, size);
}
/*
-12, -13, -5, 6, 11, -7, 5, -3, -6
i = 4
j = 4

*/