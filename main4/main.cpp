//
//  main.cpp
//  main4
//
//  Created by zhuzhuxia on 2024/12/29.
//

#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    
    int n;
    cin>>n;
    //16704 31898 29814 2071 12487 19559 14120 503 29835 1848 9637 17909 13680 27695 5395 23792 32745 4600 8235 26475 11630 13585 6800 29867 2111286
    
    int * arrPoint = new int(n);
    
    for (int i=0; i<n; i++) {
        cin >> *(arrPoint+i);
    }
    
//    for (int j=n-1; j>=0; j--) {
//        cout<< *(arrPoint+j)<<" ";
//    }
    
    for (int k=0; k<n; k++) {
        cout<< *(arrPoint+k)<<" ";
    }
    
    delete arrPoint;
    
    return 0;
}
