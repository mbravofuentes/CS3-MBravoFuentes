#include <bits/stdc++.h>
using namespace std;
int n;

struct Node
{
    int data;
    Node* left, * right;
};
Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
Node* insertLevelOrder(vector<int>arr, Node* root, int i, int count)
{
    // Base case for recursion
    if (i < count)
    {
        Node* temp = newNode(arr[i]);
        root = temp;

        // insert left child
        root->left = insertLevelOrder(arr,
                   root->left, 2 * i + 1, count);

        // insert right child
        root->right = insertLevelOrder(arr,
                  root->right, 2 * i + 2, count);
    }
    return root;
}
void inOrder(Node* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data <<" ";
        inOrder(root->right);
    }
}
bool ifNodeExists(struct Node* node, int x)
{
    if (node == NULL)
        return false;

    if (node->data == x)
        return true;

    /* then recur on left sutree */
    bool res1 = ifNodeExists(node->left, x);

    /* now recur on right subtree */
    bool res2 = ifNodeExists(node->right, x);

    return res1 || res2;
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(vector<int>arr, int count)
{
    int i, j;
    for (i = 0; i < count-1; i++)

    // Last i elements are already in place
    for (j = 0; j < count-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}

void selectionSort(vector<int>arr, int count)
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

void insertionSort(vector<int>arr, int count)
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

int shellSort(vector<int>arr, int count)
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

int partition (vector<int>arr, int low, int high)
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
void quickSort(vector<int>arr, int low, int high)
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

void merge(vector<int>arr, int l, int m, int r)
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
void mergeSort(vector<int>arr, int l, int r)
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

void heapify(vector<int>arr, int n, int i)
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
void heapSort(vector<int>arr, int count)
{
    for (int i = count / 2 - 1; i >= 0; i--)
        heapify(arr, count, i);
          for (int i=count-1; i>=0; i--)
            {
              swap(arr[0], arr[i]);
                heapify(arr, i, 0);
  }
}

void printArray(vector<int>arr, int count)
{
  ofstream myfile("rand.txt");
  if (myfile.is_open())
  {
    for (int i=0; i<count; i++)
      myfile << arr[i] << " ";
        myfile.close();
  }
  else
  {
     cout << "File could not be opened" << endl;
  }

}
void heapTime(vector<int>arr, int lower, int upper, int count, ofstream& a)
{
  float sum = 0, avg;
  for (int i = 0; i < 10; i++)
  {
  auto t1 = std::chrono::high_resolution_clock::now();
  heapSort(arr, count);
  auto t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
  cout << "HeapSort " << duration << endl;
  sum += duration;
  }
  avg = sum / 10;
  a << "HEAPSORT_AVG " << avg << " milliseconds " << endl;
}
void bubbleTime(vector<int>arr, int lower, int upper, int count, ofstream& a)
{
  float sum = 0, avg;
  for (int i = 0; i < 10; i++)
  {
  auto t1 = std::chrono::high_resolution_clock::now();
  bubbleSort(arr, count);
  auto t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
  cout << "BubbleSort " << duration << endl;
  sum += duration;
}
avg = sum / 10;
a << "BubbleSort_AVG " << avg << " milliseconds " << endl;
}
void selectionTime(vector<int>arr, int lower, int upper, int count, ofstream& a)
{
  float sum = 0, avg;
  for (int i = 0; i < 10; i++)
  {
  auto t1 = std::chrono::high_resolution_clock::now();
  selectionSort(arr, count);
  auto t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
  cout << "SelectionSort " << duration << endl;
  sum += duration;
}
avg = sum / 10;
a << "SelectionSort_AVG " << avg << " milliseconds " << endl;
}
void insertionTime(vector<int>arr, int lower, int upper, int count, ofstream& a)
{
  float sum = 0, avg;
  for (int i = 0; i < 10; i++)
  {
  auto t1 = std::chrono::high_resolution_clock::now();
  insertionSort(arr, count);
  auto t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
  cout << "InsertionSort " << duration << endl;
  sum += duration;
  }
  avg = sum / 10;
  a << "InsertionSort_AVG " << avg << " milliseconds " << endl;
}
void mergeTime(vector<int>arr, int lower, int upper, int count, ofstream& a)
{
  float sum = 0, avg;
  for (int i = 0; i < 10; i++)
  {
  auto t1 = std::chrono::high_resolution_clock::now();
  mergeSort(arr, 0, count - 1);
  auto t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
  cout << "MergeSort " << duration << endl;
  sum += duration;
}
  avg = sum / 10;
  a << "MergeSort_Avg " << avg << " milliseconds " << endl;
}
void shellTime(vector<int>arr, int lower, int upper, int count, ofstream& a)
{
  float sum = 0, avg;
  for (int i = 0; i < 10; i++)
  {
  auto t1 = std::chrono::high_resolution_clock::now();
  shellSort(arr, count);
  auto t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
  cout << "ShellSort " << duration << endl;
  sum += duration;
}
  avg = sum / 10;
  a << "ShellSort_Avg " << avg << " milliseconds " << endl;
}
void quickTime(vector<int>arr, int lower, int upper, int count, ofstream& a)
{
  float sum = 0, avg;
  for (int i = 0; i < 10; i++)
  {
  auto t1 = std::chrono::high_resolution_clock::now();
  quickSort(arr, 0, count - 1);
  auto t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
  cout << "QuickSort " << duration << endl;
  sum += duration;
}
  avg = sum / 10;
  a << "QuickSort_Avg " << avg << " milliseconds " << endl;
}
void defaultSort(vector<int>arr, int lower, int upper, int count, ofstream& a)
{
  float sum = 0, avg;
  for (int i = 0; i < 10; i++)
  {
  auto t1 = std::chrono::high_resolution_clock::now();
  sort(arr.begin(), arr.end());
  auto t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
  cout << "DefaultSort " << duration << endl;
  sum += duration;
}
avg = sum / 10;
a << "DefaultSort " << avg << " milliseconds " << endl;
}
void stableSort(vector<int>arr, int lower, int upper, int count, ofstream& a)
{
  float sum = 0, avg;
  for (int i = 0; i < 10; i++)
  {
  auto t1 = std::chrono::high_resolution_clock::now();
  stable_sort(arr.begin(), arr.end());
  auto t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
  cout << "StableSort " << duration << endl;
  sum += duration;
}
  avg = sum / 10;
  a << "StableSort_Avg " << avg << " milliseconds " << endl;
}
int sequentialSearch(vector<int>arr, int count, ofstream& a)
{
  float sum = 0, avg;
  for (int i = 0; i < 10; i++)
  {
  int key;
  bool found = false;
  cout << "Enter the value to search: ";
  cin >> key;
  auto t1 = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < count; i++) {
       if (key == arr[i]) {
           found = true;
           cout << "The value is found at index arr[" << i << "]" << endl;
       }
   }
   if (!found)
   {
       cout << "Key not found!";
   }
   auto t2 = std::chrono::high_resolution_clock::now();
   auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
   cout << "SequentialSearch " << duration << endl;
   sum += duration;
 }
 avg = sum / 10;
 a << "SequentialSearch " << avg << " milliseconds " << endl;
}
int binaryS(vector<int>arr, int count, ofstream& a)
{
  float sum = 0, avg;
  for (int i = 0; i < 10; i++)
  {
  int x;
  cout << "What do you wanna search for? " << endl;
  cin >> x;
  auto t1 = std::chrono::high_resolution_clock::now();
  if (binary_search(arr.begin(), arr.end(), x))
          cout << "Element found in the array" << endl;
      else
          cout << "Element not found in the array" << endl;
      auto t2 = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
      cout << "BinarySearch " << duration << endl;
      sum += duration;
    }
    avg = sum / 10;
    a << "BinarySearchAVG " << avg << " milliseconds " << endl;
}
void BSTfind(vector<int>arr, int count, int x, ofstream& a)
{
  float sum = 0, avg;
  for (int i = 0; i < 10; i++)
  {
  Node* root = insertLevelOrder(arr, root, 0, count);
  cout << "What you looking for? " << endl;
  cin >> x;
  auto t1 = std::chrono::high_resolution_clock::now();
  if(ifNodeExists(root, x))
      cout << "Number found" << endl;
    else
      cout << "Number not in array" << endl;
      auto t2 = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
      cout << "BSTSearch " << duration << endl;
      sum += duration;
    }
    avg = sum / 10;
    a << "BSTFind " << avg << " milliseconds " << endl;
}

void hundredruns(vector<int>arr, ofstream& a)
{
  int lower = 1, upper = 1000000, count = 100000, x;
    srand(time(0));
    for (int i = 1; i < count; i++)
  {
        int num = (rand() %
            (upper - lower + 1)) + lower;
          arr.push_back(num);
  }
printArray(arr, count);
BSTfind(arr, count, x, a);
quickTime(arr, lower, upper, count, a);
shellTime(arr, lower, upper, count, a);
mergeTime(arr, lower, upper, count, a);
heapTime(arr, lower, upper, count, a);
selectionTime(arr, lower, upper, count, a);
insertionTime(arr, lower, upper, count, a);
defaultSort(arr, lower, upper, count, a);
stableSort(arr, lower, upper, count, a);
binaryS(arr, count, a);
sequentialSearch(arr, count, a);
bubbleTime(arr, lower, upper, count, a);

}
void fivehundredruns(vector<int>arr, ofstream& a)
{
  int lower = 1, upper = 1000000, count = 500000, x;
    srand(time(0));
    for (int i = 1; i < count; i++)
  {
        int num = (rand() %
            (upper - lower + 1)) + lower;
          arr.push_back(num);
  }
printArray(arr, count);
BSTfind(arr, count, x, a);
quickTime(arr, lower, upper, count, a);
shellTime(arr, lower, upper, count, a);
mergeTime(arr, lower, upper, count, a);
heapTime(arr, lower, upper, count, a);
selectionTime(arr, lower, upper, count, a);
insertionTime(arr, lower, upper, count, a);
defaultSort(arr, lower, upper, count, a);
stableSort(arr, lower, upper, count, a);
binaryS(arr, count, a);
sequentialSearch(arr, count, a);
bubbleTime(arr, lower, upper, count, a);
}
void onemilruns(vector<int>arr, ofstream& a)
{
  int lower = 1, upper = 1000000, count = 1000000, x;
    srand(time(0));
    for (int i = 1; i < count; i++)
  {
        int num = (rand() %
            (upper - lower + 1)) + lower;
          arr.push_back(num);
  }
printArray(arr, count);
BSTfind(arr, count, x, a);
quickTime(arr, lower, upper, count, a);
shellTime(arr, lower, upper, count, a);
mergeTime(arr, lower, upper, count, a);
heapTime(arr, lower, upper, count, a);
selectionTime(arr, lower, upper, count, a);
insertionTime(arr, lower, upper, count, a);
defaultSort(arr, lower, upper, count, a);
stableSort(arr, lower, upper, count, a);
binaryS(arr, count, a);
sequentialSearch(arr, count, a);
bubbleTime(arr, lower, upper, count, a);
}


int main()
{
  vector<int>arr;
  ofstream a("timecomplexity.txt");
  a.is_open();
  a << "First 100000 numbers " << endl;
  hundredruns(arr, a);
  a << "Second 500000 numbers " << endl;
  fivehundredruns(arr, a);
  a << "Third 1000000 numbers " << endl;
  onemilruns(arr, a);
  /*vector<double>arr2;
  vector<string>arr3;
  ifstream file("timecomplexity.txt");
  if (file) {
    double value;
    string wri;
    while ( file >> wri >> value ) {
      arr3.push_back(wri);
        arr2.push_back(value);
    }
}
/*sort(arr2.begin(), arr2.end(), std::greater<>());
a << "These are how the Avg Times went in milliseconds " << endl;
a << "The numbers go descend from 1.BST Search, 2"*/
a.close();
return 0;
}
