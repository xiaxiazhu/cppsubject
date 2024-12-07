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

using namespace std;



int main(){
    
    string inputStr;
    getline(std::cin, inputStr);
    
    int num=0;
    
    for(char c: inputStr){
        if (isdigit(c)) {
            num++;
        }
    }
    cout<<num;
    return 0;
}
