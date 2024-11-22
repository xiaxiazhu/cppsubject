//
//  main.cpp
//  cppSubject
//
//  Created by zhuzhuxia on 2024/11/13.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;




int main() {
    
    // n个整数 ;
    int n;
    
    cin>>n;
    
    vector<int> nArray;
    
    for (int i =0; i<n; i++) {
        int x;
        cin>>x;
        nArray.push_back(x);
    }

    // nArray  3 2 1 5 4
    for (int a=0; a<n; a++) {
        for (int b=0; b<n-1; b++) {
            if (nArray[b]>nArray[b+1]) {
                swap(nArray[b], nArray[b+1]);
            }
        }
    }
    
    for (int k = 0 ; k < nArray.size(); k++) {
        cout<< nArray[k]<<" ";
    }
    
    return 0;
}
