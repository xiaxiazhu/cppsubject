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
        
    string inputStr;
    getline(cin, inputStr);
    
    transform(inputStr.begin(), inputStr.end(), inputStr.begin(), [](unsigned char c){
        return toupper(c);
    });
    
    cout<<inputStr;
    
    return 0;
}
