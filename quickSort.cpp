#include<iostream>
#include<cstdlib>

void swap(int* a, int* b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int lIndex, int rIndex)
{
  int pivot = arr[rIndex];
  int i = lIndex - 1;
  for(int j= lIndex; j<= rIndex-1; j++)
  {
    if(arr[j] <= pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i+1], &arr[rIndex]);
  return i+1;
}

void quickSort(int arr[], int lIndex, int rIndex)
{
  if(lIndex < rIndex)
  {
    int pIndex =  partition(arr, lIndex, rIndex);

    quickSort(arr, lIndex, pIndex-1);
    quickSort(arr, pIndex+1, rIndex);
  }
}

void print(int arr[], int size)
{
  std::cout<<"Sorted array: ";
  for(int i= 0; i< size; i++)
  {
    std::cout<<arr[i]<<", ";
  }
  std::cout<<std::endl;
}

int main()
{
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr)/sizeof(arr[0]);
  quickSort(arr, 0, n-1);
  print(arr, n);
  return 0;
}
