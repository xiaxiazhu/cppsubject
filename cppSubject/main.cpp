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
#include <climits>
#include <unordered_map>

using namespace std;

int main() {
    int n,x;
    
    cin>>n>>x;
    int rows = n, cols=n;
    
    int matrix[rows][cols];
    // 输入矩阵
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            cin>>matrix[i][j];
        }
    }
    
    //输出矩阵
    for (int m=0; m<rows; m++) {
        for (int h=0; h<cols; h++) {
            
            // 线段 y=x, 以及y=-x+n； +x
            if (h== n-1-m || h==m) {
                matrix[m][h]+=x;
            }
            
            cout<<matrix[m][h]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}
