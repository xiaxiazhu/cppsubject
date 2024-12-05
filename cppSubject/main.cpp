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
    

int main(){
    string tString;
    
    getline(std::cin, tString);
    
    char A;
    char B;
    
    cin>>A>>B;
    
//  string tp = tString.find("a");
    
    replace(tString.begin(), tString.end(), A,B);
    

    cout<<tString<<"\n";
    
    return 0;
}
