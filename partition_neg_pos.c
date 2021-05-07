#include"utils.h"
#define MAX 10000
void partition_neg_pos(int* arr, int size)
{
	int left = 0, right = size - 1;
	while(left < right)
	{
		while(arr[left] < 0 && left < size)
			left++;
		while(arr[right] > 0 && right >= 0)
			right--;
		if(left < right)
			swap(arr, left, right);	
	}
}
int main()
{
	int arr[MAX];
	int size = input(arr, MAX);
	partition_neg_pos(arr, size);
	print(arr, size);

}