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
#include <unordered_map>

using namespace std;

char findFirstChar(string inputStr){
    unordered_map<char, int> strMap;
    
    for(char c:inputStr){
        strMap[c]++;
    }
    
    for(char c :inputStr){
        if(strMap[c]==1){
            return c;
        }
    }
    return '0';
}
int main(){
    string inputStr;
    
    cin>> inputStr;
    
    char fc = findFirstChar(inputStr);
    
    if (fc=='0') {
        cout<<"no"<<endl;
    }else{
        cout<< fc<<endl;
    }
    
    return 0;
}
