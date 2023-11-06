
#include <bits/stdc++.h>
using namespace std;

int partition(int* arr, int low, int high, int* lp);

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void dualPivotQuickSort(int* arr, int low, int high)
{
	if (low < high)
    {
		int leftPivot, rightPivot;
		rightPivot = partition(arr, low, high, &leftPivot);
		dualPivotQuickSort(arr, low, leftPivot - 1);
		dualPivotQuickSort(arr, leftPivot + 1, rightPivot - 1);
		dualPivotQuickSort(arr, rightPivot + 1, high);
	}
}

int partition(int* arr, int low, int high, int* leftPivot)
{
	if (arr[low] > arr[high])
    {
		swap(&arr[low], &arr[high]);
    }
	int j = low + 1;
	int g = high - 1, k = low + 1, p = arr[low], q = arr[high];
	while (k <= g)
    {
		if (arr[k] < p)
        {
			swap(&arr[k], &arr[j]);
			j++;
		}
		else if (arr[k] >= q)
        {
			while (arr[g] > q && k < g)
            {
				g--;
            }
			swap(&arr[k], &arr[g]);
			g--;
			if (arr[k] < p)
            {
				swap(&arr[k], &arr[j]);
				j++;
			}
		}
		k++;
	}
	j--;
	g++;
	swap(&arr[low], &arr[j]);
	swap(&arr[high], &arr[g]);
	*leftPivot = j;
	return g;
}

int main()
{
    int n;
    cout<<"Enter the size of the array.\n";
	cin>>n;
	int *arr = new int[n];
    cout<<"Enter the elements.\n";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
	dualPivotQuickSort(arr, 0, n - 1);
	cout<<"The sorted elements are as follows:\n";
	for (int i = 0; i < n; i++)
    {
		cout<<arr[i]<<" ";
    }
	cout << endl;
}