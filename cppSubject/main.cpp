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
    //Hello      world.This is    c language.
    
    string inputStr;
    string outStr;
    
    getline(cin, inputStr);
    
//    int tempDel=0;// 连续空格数
    
    for (int i=0; i<inputStr.size();) {
        
        if(inputStr[i] != ' '){
            
            outStr+=inputStr[i];
            
            i++;
        }
        if (inputStr[i]==' ') {
            // 只有一个空格
//            if (inputStr[i+1]!=' ') {
//
//            }
            // 越过连续空格
            int k = 1;
            
            while (inputStr[i+k]==' ') {
                k++;
            }
            
            i=i+k; // 指针跳过指向下一个字符
            
            outStr+=' ';
            
        }
    }
    

    cout<< outStr;
    return 0;
}
