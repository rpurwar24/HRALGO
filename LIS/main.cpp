//
//  main.cpp
//  LIS
//
//  Created by Rishabh Purwar on 14/07/16.
//  Copyright © 2016 Rustyman. All rights reserved.
//

#include <iostream>
using namespace std;

int lis(int *arr, int n){
    int *_lis = new int[n];
    int max=0;
    for(int i=0;i<n;i++){_lis[i] = 1;}
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && _lis[j]+1 > _lis[i]){
                _lis[i] = _lis[j]+1;
            }
        }
    }
    max = _lis[0];
    for(int i=1;i<n;i++){
        if(_lis[i]>max){max = _lis[i];}
    }
    free(_lis);
    return max;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int *arr = new int[N];
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }
        for(int i=0;i<N;i++){
            cout<<arr[i]<< " - ";
        }
        cout<<endl;
        cout<<lis(arr,N)<<endl;
    }
    return 0;
}
