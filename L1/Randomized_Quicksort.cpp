/*
* @Author: nevil
* @Date:   2020-07-06 16:52:29
* @Last Modified by:   nevil
* @Last Modified time: 2020-07-18 04:24:26
*/
#include<bits/stdc++.h>
using namespace std;

int partitionChanges = 0;
int swaps = 0;
int comparisons = 0;

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {

		comparisons++;
		if (arr[j] <= pivot) {

			i++;
			swap(arr[i], arr[j]);
			swaps++;
		}
	}
	swap(arr[i + 1], arr[high]);
	swaps++;
	return (i + 1);
}

int partition_r(int arr[], int low, int high)
{
	srand(time(NULL));
	int random = low + rand() % (high - low);

	swap(arr[random], arr[high]);
	swaps++;
	partitionChanges++;

	return partition(arr, low, high);
}


void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		comparisons++;
		int pi = partition_r(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
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
