//
//  main.cpp
//  TC_quicksums
//
//  Created by Rishabh Purwar on 19/07/16.
//  Copyright © 2016 Rustyman. All rights reserved.
//

#include <iostream>
using namespace std;

bool __quickSums(string inp,int &sum, int *ans,bool result,int iter){
    int len;
    len = (int)inp.length();
    if(iter<len && result == false){
        if(stoi(inp) == sum){
            return true; 
        }
        if(stoi(inp) > sum){
            //__quickSums(inp.substr(iter+1,len-1), sum-stoi(inp.substr(0,iter)), ans, false, iter);
        }
    }
    return result;
}

void quickSums(string inp, int &sum, int *ans){
    bool result  = false;
    int i=0;
    if(inp.length() > 1)
        __quickSums(inp,sum,ans,result,i);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string inp;
        int sum;
        cin>>inp>>sum;
        int ans=0;
        quickSums(inp,sum,&ans);
    }
}