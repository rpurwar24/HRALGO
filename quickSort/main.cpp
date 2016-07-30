//
//  main.cpp
//  quickSort
//
//  Created by Rishabh Purwar on 05/05/16.
//  Copyright © 2016 Rustyman. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> & arr,int low,int high)
{
    for(int i = low;i<=high;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int partition(vector <int> &arr, int low, int high)
{
    int pivot,i,j;
    pivot = low;
    i = low;
    j = high;
    while(i<j){
        while(arr[i]<=arr[pivot] && i<=high){
            i++;
        }
        while(arr[j]>arr[pivot] && j>=low){
            j--;
        }
        if(i<j)
        {
            swap(&arr[i],&arr[j]);
        }
        if(i>=j){
            break;
        }
    }
    if(i > low){
        i = i-1;
    }
    swap(&arr[pivot],&arr[i]);
    return i;
}
void quickSortUtil(vector <int> &arr,int low, int high){
    int pivot;
    pivot = partition(arr,low,high);
    if(low<pivot){
        quickSortUtil(arr,low,pivot-1);
        if(low!=pivot-1)
            printArray(arr,low,pivot-1);
    }
    if(high>pivot){
        quickSortUtil(arr,pivot+1,high);
        if(high!=pivot+1)
            printArray(arr,pivot+1,high);
    }
}

void quickSort(vector <int> &arr) {
    int len = int(arr.size());
    int low = 0,high = len-1;
    if(low<high)
        quickSortUtil(arr,low,high);
}

int main()
{
    //int n;
    //cin >> n;
    
    vector <int> arr = {5,8,1,3,7,9,2};
//    for(int i = 0; i < (int)n; ++i) {
//        cin >> arr[i];
//    }
    
    quickSort(arr);
    //printArray(arr);
    
    return 0;
}

