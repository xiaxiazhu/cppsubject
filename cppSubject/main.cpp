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
    int n , m;
    cin >> n >> m;
    
    vector<vector<int>> pictureMatrix( n,vector<int>(m) );
    vector<vector<int>> pictureMatrixNew( n,vector<int>(m) );
    
    for (int i=0; i<n; i++) {
        for (int j =0; j<m; j++) {
            cin>>pictureMatrix[i][j];
        }
    }
    
    pictureMatrixNew = pictureMatrix;
    
    // 灰度处理
    for (int a = 1 ; a<=n-2; a++) {
        for (int b = 1; b<=m-2; b++) {
            // 上下左右取平均
            // (numerator + denominator / 2) / denominator 四舍五入，不需要用double
            pictureMatrixNew[a][b] = ( pictureMatrix[a][b] + pictureMatrix[a-1][b]+pictureMatrix[a+1][b]+pictureMatrix[a][b-1]+pictureMatrix[a][b+1] + 5/2 )/5;
            
        }
    }
    
    for (int d=0; d<n; d++) {
        for (int e=0; e<m; e++) {
            cout<< pictureMatrixNew[d][e]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}
