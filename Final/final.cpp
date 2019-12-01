#include <bits/stdc++.h>
using namespace std;
int arr[1000000], n;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int count)
{
    int i, j;
    for (i = 0; i < count-1; i++)

    // Last i elements are already in place
    for (j = 0; j < count-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}

void selectionSort(int arr[], int count)
{
  int i, j, min_idx;
    for (i = 0; i < count-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

void insertionSort(int arr[], int count)
{
    int i, key, j;
    for (i = 1; i < count; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int shellSort(int arr[], int count)
{
    // Start with a big gap, then reduce the gap
    for (int gap = count/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < count; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int count)
{
    for (int i = count / 2 - 1; i >= 0; i--)
        heapify(arr, count, i);
          for (int i=count-1; i>=0; i--)
            {
              swap(arr[0], arr[i]);
                heapify(arr, i, 0);
  }
}

void printArray(int arr[], int count)
{
  ofstream myfile("rand.txt");
  if (myfile.is_open())
  {
    for (int i=0; i<count; i++)
    {
    myfile << arr[i] << " ";
    }
  myfile.close();
  }
  else
  {
  cout << "File could not be opened" << endl;
  }
}
void readArray()
{
  string STRING;
 ifstream myfile;
 myfile.open ("rand.txt");
 while(getline(myfile,STRING))
 {
   cout << "Reading completed " << endl;
  }
 myfile.close();
}

void heapTime(int lower, int upper, int count)
{
  readArray();
  auto t1 = std::chrono::high_resolution_clock::now();
  heapSort(arr, count);
  auto t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::seconds>( t2 - t1 ).count();
  cout << "HeapSort duration " << duration << " seconds" << endl;
}
void bubbleTime(int lower, int upper, int count)
{
  readArray();
  auto t1 = std::chrono::high_resolution_clock::now();
  bubbleSort(arr, count);
  auto t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::seconds>( t2 - t1 ).count();
  cout << "BubbleSort duration " << duration << " seconds" << endl;
}
void selectionTime(int lower, int upper, int count)
{
  readArray();
  auto t1 = std::chrono::high_resolution_clock::now();
  selectionSort(arr, count);
  auto t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::seconds>( t2 - t1 ).count();
  cout << "SelectionSort duration " << duration << " seconds" << endl;
}
void insertionTime(int lower, int upper, int count)
{
  readArray();
  auto t1 = std::chrono::high_resolution_clock::now();
  insertionSort(arr, count);
  auto t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::seconds>( t2 - t1 ).count();
  cout << "InsertionSort duration " << duration << " seconds" << endl;
}
void mergeTime(int lower, int upper, int count)
{
  readArray();
  auto t1 = std::chrono::high_resolution_clock::now();
  mergeSort(arr, 0, count - 1);
  auto t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::seconds>( t2 - t1 ).count();
  cout << "MergeSort duration " << duration << " seconds" << endl;
}
void shellTime(int lower, int upper, int count)
{
  readArray();
  auto t1 = std::chrono::high_resolution_clock::now();
  shellSort(arr, count);
  auto t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::seconds>( t2 - t1 ).count();
  cout << "ShellSort duration " << duration << " seconds" << endl;
}
void quickTime(int lower, int upper, int count)
{
  readArray();
  auto t1 = std::chrono::high_resolution_clock::now();
  quickSort(arr, 0, count - 1);
  auto t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::seconds>( t2 - t1 ).count();
  cout << "QuickSort duration " << duration << " seconds" << endl;
}
void defaultSort(int lower, int upper, int count)
{
  readArray();
  auto t1 = std::chrono::high_resolution_clock::now();
  sort(arr, arr+count);
  auto t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::seconds>( t2 - t1 ).count();
  cout << "Default Sort duration " << duration << " seconds" << endl;
}
void stableSort(int lower, int upper, int count)
{
  readArray();
  auto t1 = std::chrono::high_resolution_clock::now();
  stable_sort(arr, arr + count);
  auto t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::seconds>( t2 - t1 ).count();
  cout << "Stable Sort duration " << duration << " seconds" << endl;
}

int main()
{
  int lower = 1, upper = 1000000, count = 100000;
    srand(time(0));
    for (int i = 0; i < count; i++)
  {
        int num = (rand() %
            (upper - lower + 1)) + lower;
          arr[i] = num;
  }
printArray(arr, count);
bubbleTime(lower, upper, count);
/*quickTime(lower, upper, count);
shellTime(lower, upper, count);
mergeTime(lower, upper, count);
heapTime(lower, upper, count);
selectionTime(lower, upper, count);
insertionTime(lower, upper, count);
bubbleTime(lower, upper, count);
defaultSort(lower, upper, count);
stableSort(lower, upper, count);*/
return 0;
}
