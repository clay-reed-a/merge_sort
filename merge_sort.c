#include <stdio.h>
#include <math.h>

void merge(int arr[], int p, int q, int r);
void merge_sort(int arr[], int p, int r);

int main(int argc, char *argv[])
{
  int arr[] = {1, 2, -2, 7, 9, 8, 3, -1, 11, 12, 7, 0, -3, 4, 6, 5, 4}; 
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("The problem size is %d.\n", n);

  int i = 0; 
  while(i < n) {
    printf("%d ", 
      arr[i]);
    i++; 
  }
  printf("\n");

  merge_sort(arr, 0, n-1);

  i = 0;
  while(i < n) {
    printf("%d ", 
      arr[i]);
    i++; 
  }
  printf("\n");

  return 0; 
}

void merge(int arr[], int starts, int middle, int ends)
{
  int first_length = middle - starts + 1;
  int second_length = ends - middle;

  // create the subarrays
  int first_subarray[first_length]; 
  int second_subarray[second_length];

  for(int i = 0; i < first_length; i++) {
    first_subarray[i] = arr[starts+i];  
  }
  first_subarray[first_length] = INFINITY; 
  printf("The first subarray is: \n");
  int i = 0; 
  while(i <= first_length)
  {
    printf("%d ", 
      first_subarray[i]);
    i++; 
  }
  printf("\n");


  for(int j = 0; j < second_length; j++) {
    second_subarray[j] = arr[middle+1+j];
  }
  second_subarray[second_length] = INFINITY;
  printf("The second subarray is: \n");
  int j = 0;
  while(j <= second_length)
  {
    printf("%d ",
      second_subarray[j]);
    j++;
  } 
  printf("\n");

  

  i = 0; 
  j = 0; 

  for(int k = starts; k <= ends; k++) 
  {
    if(first_subarray[i] <= second_subarray[j]) 
    {
      arr[k] = first_subarray[i];
      i++; 
    }
    else 
    {
      arr[k] = second_subarray[j];
      j++; 
    }
  }
}
                          
void merge_sort(int arr[], int starts, int ends)
{
  if (starts < ends)
  {
    int middle = (starts + ends)/2; 
    merge_sort(arr, starts, middle);
    merge_sort(arr, middle+1, ends);
    merge(arr, starts, middle, ends);
  }
}