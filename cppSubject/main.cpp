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
    
    vector<int> nArray,resultArray;
    
    for (int i =0; i<n; i++) {
        int x;
        cin>>x;
        nArray.push_back(x);
    }
    while (nArray.size()>0) {
        
        // 选择最小值
        int tempMinIndex=0;

        for (int j = 0 ; j<nArray.size(); j++) {
            if (nArray[tempMinIndex]> nArray[j]) {
                tempMinIndex =j;
            }
        }

        //返回从小排大的序列result
        cout<<nArray[tempMinIndex]<<" ";
        
        //erase element
        nArray.erase(nArray.begin()+tempMinIndex);
        
    }
    
    
    return 0;
}
