#include<iostream>
using namespace std;
void heapify(int arr[], int n, int j)
{
int temp;
int largest = j;
int left = 2 * j + 1; //left=9
int right = 2 * j + 2; //right=10
if (left < n && arr[left] > arr[largest]) //left<10 true and arr[9]=25 >arr[4] =10
largest = left; //largest =9
if (right < n && arr[right] > arr[largest]) //right!<10
largest = right;
if (largest != j) {
temp = arr[j];
arr[j] = arr[largest];
arr[largest] = temp; //20 7 1 54 25 15 90 23 77 10
heapify(arr, n, largest); //arr, 10,largest=9
}
}
void heapSort(int arr[], int n) {
int temp;
for (int i = n / 2 - 1; i >= 0; i--)
heapify(arr, n, i); //n=10,i=4
for (int k = n - 1; k >= 0; k--) //i=9 to 0
{
temp = arr[0]; //This is used to delete element
arr[0] = arr[k];
arr[k] = temp; //10 7 1 54 25 15 90 23 77 20
heapify(arr, k, 0); //k=9 will be copied into n therefore now 9 elements will be considered
}
}
int main() {
int arr[] = { 20, 7, 1, 54, 10, 15, 90, 23, 77, 25};
int n = 10;
int i;
cout<<"Given array is: "<<endl;
for (i = 0; i<n; i++)
cout<<arr[i]<<" ";
cout<<endl;
heapSort(arr, n);
cout<<"\nSorted array is: \n";
for (i = 0; i < n; i++)
cout<<arr[i]<<" ";
}