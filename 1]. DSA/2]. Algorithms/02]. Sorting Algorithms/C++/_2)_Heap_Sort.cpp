#include <bits/stdc++.h>
using namespace std;

bool minHeap = false; // It will make MaxHeap
// bool minHeap = true; // To make MinHeap

bool compare(int a, int b)
{
    if (minHeap)
    {
        return a < b;
    }
    else
    {
        return a > b;
    }
}

void print(vector<int> v)
{
    for (int x = 1; x < v.size(); x++)
    {
        cout << v[x] << " ";
    }
    cout << endl;
}

void heapify(vector<int> &v, int index, int size)
{
    int left = 2 * index;
    int right = (2 * index) + 1;

    int min_index = index;
    int last = size - 1;

    if (left <= last and compare(v[left], v[index]))
    {
        min_index = left;
    }

    if (right <= last and compare(v[right], v[min_index]))
    {
        min_index = right;
    }

    if (min_index != index)
    {
        swap(v[index], v[min_index]);
        heapify(v, min_index, size);
    }
}

// O(n)
void BuildHeapOptimised(vector<int> &v)
{
    for (int i = (v.size() - 1) / 2; i >= 1; i--)
    {
        heapify(v, i, v.size());
    }
}

void HeapSort(vector<int> &arr)
{
    BuildHeapOptimised(arr);
    int n = arr.size();

    // Remove n - 1 elements from the heap
    while (n > 1)
    {
        swap(arr[1], arr[n - 1]);
        // Remove that element from the heap
        n--;
        heapify(arr, 1, n);
    }
}

int main()
{
    vector<int> v;
    v.push_back(-1);
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    HeapSort(v);
    print(v);
    return 0;
}