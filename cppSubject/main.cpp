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

int searchTableIndex(char c){
    
    char table[27]=
    {'^','A','B','C','D','E','F','G','H','I','G','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    
    for (int i =0; i<sizeof(table)/sizeof(table[0]); i++) {
        
        if (table[i] == c) {
            return i;
        }
    }
    
    return -1;
}

int main(){
        
    string HuixinName,xiaozuName;
    
    cin>>HuixinName;
    cin>>xiaozuName;
    
    int hxnNum=1,xzNum=1;
    
    for(char c : HuixinName){
        hxnNum *= searchTableIndex(c);
    }
//    searchTableIndex("A")*
    
    for(char c: xiaozuName){
        xzNum*= searchTableIndex(c);
    }
    
    if (hxnNum%47 == xzNum%47) {
        cout<<"GO";
    }else{
        cout<<"STAY";
    }
    
    return 0;
}
