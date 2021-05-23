#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& vec);
void insertionSort(vector<int>& vec);
void quicksort(vector<int>& vec, int low, int high);
int partition(vector<int>& vec, int low, int high);
void mergesort(vector<int>& vec, int low, int high);
void merge(vector<int>& vec, int low, int mid, int high);

int main()
{
    vector<int> vec_bubble = {2, 10, 5, 8, 2, 6, 5, 8, 9, 12};
    vector<int> vec_insertion = {2, 10, 5, 8, 2, 6, 5, 8, 9, 12};
    vector<int> vec_quick = {2, 10, 5, 8, 2, 6, 5, 8, 9, 12};
    vector<int> vec_merge = {2, 10, 5, 8, 2, 6, 5, 8, 9, 12};

    bubbleSort(vec_bubble); //O(n_square)
    insertionSort(vec_insertion); //O(n_square)
    quicksort(vec_quick,0,9); //O(nlogn)
    mergesort(vec_merge, 0, 9); //O(nlogn)

    cout << "The result of a sorted array using bubble sort\n";
    for(int a = 0; a < vec_bubble.size(); ++a)
    {
        cout << vec_bubble[a] << " ";
    }
    cout << endl;

    cout << "The result of a sorted array using insertion sort\n";
    for (int a = 0; a < vec_insertion.size(); ++a)
    {
        cout << vec_insertion[a] << " ";
    }
    cout << endl;

    cout << "The result of a sorted array using quick sort\n";
    for (int a = 0; a < vec_quick.size(); ++a)
    {
        cout << vec_quick[a] << " ";
    }
    cout << endl;

    cout << "The result of a sorted array using merge sort\n";
    for (int a = 0; a < vec_merge.size(); ++a)
    {
        cout << vec_merge[a] << " ";
    }
    cout << endl;

    return 0;
}

void bubbleSort(vector<int> &vec)
{
    //bool swapped = false;
    for(int i = 0; i<vec.size()-1; ++i)
    {
        //swapped = false;
        for(int j = vec.size()-1; j>=i+1; --j)
        {
            if(vec[j]<vec[j-1])
            {
                swap(vec[j], vec[j-1]);
                //swapped = true;
            }
        }
    }
}

void insertionSort(vector<int> &vec)
{
    int index;
    for(int i = 0; i<vec.size()-1; ++i)
    {
        index = i;
        for(int j = i+1; j<vec.size(); ++j)
        {
            if(vec[index]>vec[j])
            {
                index = j;
            }
        }
        swap(vec[index], vec[i]);
    }
}

int partition(vector<int> &vec, int low, int high)
{
    int item = vec[high];
    int start = low-1;

    for (int a = low; a < high; ++a)
    {
        if (item > vec[a])
        {
            start++;
            swap(vec[start], vec[a]);
        }
    }
    swap(vec[high], vec[start + 1]);

    return (start + 1);
}

void quicksort(vector<int> &vec, int low, int high)
{
    if(low < high)
    {
        int num = partition(vec, low, high);
        quicksort(vec, low, num-1);
        quicksort(vec, num+1, high);
    }
}

void mergesort(vector<int> &vec, int low, int high)
{
    int mid;
    if(low<high)
    {
        mid = low + (high - low)/2;
        mergesort(vec, low, mid);
        mergesort(vec, mid+1, high);
        merge(vec, low, mid, high);
    }
}

void merge(vector<int> &vec, int low, int mid, int high)
{
    int k = low;
    int l = 0;
    int r = 0;
    vector<int> left, right;
    
    for(int a = 0; a < mid-low+1; ++a)
    {
        left.push_back(vec[low+a]);
    }
    for(int b = 0; b < high-mid; ++b)
    {
        right.push_back(vec[mid+b+1]);
    }


    while(l<left.size() && r <right.size())
    {
        if(left[l]<=right[r])
        {
            vec[k++] = left[l++];
        }
        else
        {
            vec[k++] = right[r++];
        }
    }

    while (l < left.size())
    {
        vec[k++] = left[l++];
    }
    while (r < right.size())
    {
        vec[k++] = right[r++];
    }
}