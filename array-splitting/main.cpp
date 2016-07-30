//
//  main.cpp
//  array-splitting
//
//  Created by Rishabh Purwar on 25/07/16.
//  Copyright © 2016 Rustyman. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
long long int max(long long int a,long long int b){
    return a>b?a:b;
}
long long int getSum(long long int *arr,long long int a, long long int b){
    long long int temp;
    if(a==0) temp = 0;
    else temp = arr[a-1];
    return arr[b]-temp;
}
int getIndexBs(long long int *arr,int a,int b,long long int sum){
    int bIndex = -1;
    int start = a;
    int end = b;
    while(start <= end){
        int mid = (start+end)/2;
        if(arr[mid] == sum){bIndex = mid;break;}
        else if(arr[mid] > sum){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return bIndex;
}
int split(long long int *arr, int s, int e,long long int sum){
    int bIndex = -1;
    if(s>0) sum+=arr[s-1];
    bIndex = getIndexBs(arr,s,e, sum);
    return bIndex;
}
int splitter(long long int *arr,int s, int e,int res){
    if(s<e){
        long long int reqSum = getSum(arr,s,e);
        if(reqSum%2==0){
            int bPoint = split(arr,s,e,reqSum/2);
            if(bPoint > -1){
                res = 1+ max(splitter(arr,s,bPoint,0),splitter(arr,bPoint+1,e,0));
            }
        }
    }
    return res;
}
int main(){
    long long int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        long long int *arr = new long long int[N];
        for(int i=0;i<N;i++){
            cin>>arr[i];
            if(i!=0){
                arr[i]+=arr[i-1];
            }
        }
        int res=0;
        if(arr[N-1] == 0){
            cout<<N-1<<endl;
            return 0;
        }
        int result = splitter(arr,0,N-1,res);
        cout<<result<<endl;
    }
    return 0;
}