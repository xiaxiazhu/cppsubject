//
//  main.cpp
//  sort
//
//  Created by zhuzhuxia on 2024/12/31.
//

#include <iostream>
using namespace std;

bool insertSort(int* arr,int n){
        
    for (int i=1; i<n; i++) {
        
        int j = i-1;
        int key = arr[i];
        
        while (j>=0 && arr[j]<key){
            arr[j+1]=arr[j];
            j--;
        }
        
        arr[j+1] = key;
    }
    
    return 0;
}

int main() {
    
    int n;
    cin>>n;
    
    int * arr = new int(n);
    
    for (int i=0; i<n; i++) {
        cin >>*(arr+i);
    }
    
    insertSort(arr,n);
      
    for (int a=0; a<n; a++) {
        cout<<arr[a]<<" ";
    }
    delete arr;
    
    return 0;
}
