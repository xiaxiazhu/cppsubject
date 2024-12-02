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

int getValue(vector<vector<char>>mat,int x,int y){
    
//    leiquNum[x-1][y]
    if (mat[x][y]=='0') {
        return 0;
    }
    if(mat[x][y]=='?'){//no bomb
        return 0;
    }
//    mat[x,y]
    if(mat[x][y]=='*'){
        return 1;
    }
    
    return 0;
}

int main() {
    int n,m;
    cin>>n>>m;
    
    vector<vector<char>>leiqu(n,vector<char>(m));
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>> leiqu[i][j];
        }
    }
    
    //雷区数字输出
    vector<vector<char>>leiquNum(n+2,vector<char>(m+2));
    
    int top=1,right=m+2,bottom=n+2,left=1;
    // 四个点
    // 四条边
    for (int t = top; t<=right; t++) {
        leiquNum[top-1][t-1] = '0';
    }

    for (int b = right; b>=left; b--) {
        leiquNum[bottom-1][b-1] ='0';
    }
    
    for (int r=top; r<=bottom; r++) {
        leiquNum[r-1][right-1] = '0';
    }

    for (int l=bottom; l>=top; l--) {
        leiquNum[l-1][left-1] = '0';
    }
    
    // 8value
    for (int a=0; a<n; a++) {
        for (int c=0; c<m;c++) {
            // 输入矩阵中，用向量加一输入
            leiquNum[a+1][c+1]=leiqu[a][c];
        }
    }
    
//    for(auto aa:leiquNum){
//        for(auto bb:aa){
//            cout<<bb;
//        }
//        cout<<"\n";
//    }

    
    for (int x=1; x<n+1; x++) {
        for (int y=1; y<m+1; y++) {
            
            if(leiquNum[x][y]!='*'){
                //search 8 direction
                //上下左右等
                leiquNum[x][y]= 48+(getValue(leiquNum,x-1,y)
                                                  +getValue(leiquNum,x-1,y+1)
                                                  +getValue(leiquNum,x,y+1)
                                                  +getValue(leiquNum,x+1,y+1)
                                                  +getValue(leiquNum,x+1,y)
                                                  +getValue(leiquNum,x+1,y-1)
                                                  +getValue(leiquNum,x,y-1)
                                                  +getValue(leiquNum,x-1,y-1)
                                                  );// ascii表，显示数字
            }
        }
    }
    
    for (int d=0; d<n; d++) {
        for (int e=0; e<m; e++) {
            leiqu[d][e]=leiquNum[d+1][e+1];
        }
    }
    
    for(auto zz:leiqu){
        for(auto vv:zz){
            cout<<vv;
        }
        cout<<"\n";
    }
    
}
