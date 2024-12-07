//
//  main.cpp
//  cppSubject
//
//  Created by zhuzhuxia on 2024/11/13.
//

#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>
//#include <cmath>
//#include <climits>
//#include <unordered_map>
//#include <stack>
#include <sstream>
#include <algorithm>
#include <cctype>


using namespace std;


int main(){
    
    int n,m;
    cin>>n>>m;
    vector<vector<char>> tableMatrix(n,vector<char>(m));
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>tableMatrix[i][j];
        }
    }

    //矩阵外面围一层0。
    vector<vector<char>>waiweiMatrix(n+2,vector<char>(m+2,0));
    
    for (int k=1; k<n+1; k++) {
        for (int l =1; l<m+1; l++) {
            waiweiMatrix[k][l]=tableMatrix[k-1][l-1];
        }
    }
    
    for (int c=1; c<n+1;c++) {
        for (int d=1; d<m+1; d++) {
            // 避开*
            if (waiweiMatrix[c][d]!= '*'&&waiweiMatrix[c][d]=='?') {
                char num = '0';
                //上下左右
                if(waiweiMatrix[c-1][d]=='*'){
                    num++;
                }
                if (waiweiMatrix[c+1][d]=='*') {
                    num++;
                }
                if (waiweiMatrix[c][d-1]=='*') {
                    num++;
                }
                if (waiweiMatrix[c][d+1] =='*') {
                    num++;
                }
                //左上，右上，左下，右下
                if(waiweiMatrix[c-1][d-1]=='*'){
                    num++;
                }
                if(waiweiMatrix[c-1][d+1]=='*'){
                    num++;
                }
                if(waiweiMatrix[c+1][d-1]=='*'){
                    num++;
                }
                if(waiweiMatrix[c+1][d+1]=='*'){
                    num++;
                }
                                
                // 采集周围的数据
                waiweiMatrix[c][d]=static_cast<char>(num);
            }
            
        }
    }
    
    for (int a =1; a<n+1; a++) {
        for (int b=1; b<m+1; b++) {
            cout<<waiweiMatrix[a][b];
        }
        cout<<"\n";
    }
    
    return 0;
}
