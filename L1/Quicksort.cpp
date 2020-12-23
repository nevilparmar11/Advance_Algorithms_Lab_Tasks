/*
* @Author: nevil
* @Date:   2020-07-06 17:31:16
* @Last Modified by:   nevil
* @Last Modified time: 2020-07-06 17:43:29
*/
#include <bits/stdc++.h>
using namespace std;

int partitionChanges = 0;
int swaps = 0;
int comparisons = 0;

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}

int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element
	partitionChanges++;

	for (int j = low; j <= high - 1; j++)
	{
		comparisons++;
		if (arr[j] < pivot)
		{
			i++;
			swaps++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	swaps++;
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	comparisons++;
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int n ;
	cout << "Enter the number of elements : " << endl;
	cin >> n;
	int arr[n];

	cout << "Enter the " << n << " elements : " << endl;

	for (auto i = 0 ; i < n ; i++)
	{
		cin >> arr[i];
	}

	quickSort(arr, 0, n - 1);
	printf("Sorted array: \n");
	printArray(arr, n);

	cout << "Swaps : " << swaps << endl;
	cout << "Comparisons : " << comparisons << endl;
	cout << "partitionChanges : " << partitionChanges << endl;
	return 0;
}

