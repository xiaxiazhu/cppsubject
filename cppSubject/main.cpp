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
    
    // 删除偶数
    int nIndex = 0;
    
    while (nArray.size()>nIndex) {
        
        if (nArray[nIndex]%2==0 ) {
            //偶数
            nArray.erase(nArray.begin()+nIndex);
        }else{
            //奇数
            nIndex++;
        }
    }
    
    
    // nArray  3 2 1 5 4
    for (int a=0; a<nArray.size(); a++) {
        for (int b=0; b<nArray.size()-1; b++) {
            if (nArray[b]>nArray[b+1]) {
                swap(nArray[b], nArray[b+1]);
            }
        }
    }
    
    bool lastNum = false;
    for (int k = 0 ; k < nArray.size(); k++) {
        if (k == nArray.size()-1) {
            lastNum=true;
        }else{
            lastNum=false;
        }
        
        cout<< nArray[k]<<( lastNum ? " ":",");
    }
    
    return 0;
}
