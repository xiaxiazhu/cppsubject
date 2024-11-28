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
#include <stack>

using namespace std;

int main() {
    int n,m;
    
    cin>>n>>m;
    
    int rows = n, cols=m;
    
    int matrix[rows][cols];
    // 输入矩阵
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            cin>>matrix[i][j];
        }
    }
    
    stack<int> sAP;

    int angPoint = 0 ;
    
    
    for (int a=0; a<rows; a++) {
        // 横向迭代，纵向比较出最小值坐标
        int minTemp=INT_MAX;
        
        int maxTemp = INT_MIN;
        
        int colsIndexArray=-1;
        
        for (int b=0; b<cols; b++) {
            // 先查重
            if (matrix[a][b] == maxTemp) {
                sAP.push(b);
            }
            if (matrix[a][b] > maxTemp) {
                
                maxTemp=matrix[a][b];
                
                colsIndexArray = b; // 最da值
                
                // reset sap
                while (!sAP.empty()) {
                    sAP.pop();
                }
                                
            }
        }
        
        sAP.push(colsIndexArray);
        
        while (!sAP.empty()) {
            // a==0, colsindex = b;(a,colsindex)
            bool isDoodleNum = true;

            int sapcols=sAP.top();
            sAP.pop();
        
            for (int k =0; k<rows; k++) {
                if (matrix[a][sapcols] > matrix[k][sapcols]) {
                    isDoodleNum=false;
                    break;
                }
            }
            
            if (isDoodleNum) {
                angPoint++;
            }
        }

    }
    
    cout<<angPoint<<endl;

    return 0;
}
