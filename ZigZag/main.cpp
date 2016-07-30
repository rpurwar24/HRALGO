//
//  main.cpp
//  ZigZag
//
//  Created by Rishabh Purwar on 16/07/16.
//  Copyright © 2016 Rustyman. All rights reserved.
//

#include <iostream>
using namespace std;
int max(int a,int b){
    return a>b?a:b;
}
int zigzag(int *arr, int n){
    int lcs=0;
    int **res = new int*[n];
    for(int i=0;i<n;i++){
        res[i] = new int[2];
        for(int j=0;j<2;j++){
            res[i][j] = 1;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && res[i][0]<res[j][1]+1){
                res[i][0]=res[j][1]+1;
            }
            if(arr[i]<arr[j] && res[i][1]<res[j][0]+1){
                res[i][1]=res[j][0]+1;
            }
        }
    }
    lcs = max(res[0][0],res[0][1]);
    for(int i=1;i<n;i++){
        int m = max(res[i][0],res[i][1]);
        if(lcs<m){lcs = m;}
    }
    return lcs;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int *arr = new int[N];
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }
        cout<<zigzag(arr,N)<<endl;
    }
}