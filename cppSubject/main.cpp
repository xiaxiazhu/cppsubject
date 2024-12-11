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


bool compare(const string &a,const string &b){
    return a+b>b+a; //精华就在这里
}

int main(){
    
    // 找出第一个数，然后排序，一个一个加起来
    int num;
    cin>>num;
    
    vector<int> numberList(num);
    
    for (int i=0; i<num; i++) {
        cin>>numberList[i];
    }
    
    vector<string> strList(num);
    
    for(int in:numberList){
        strList.push_back(to_string(in));
    };
    
    sort(strList.begin(), strList.end(), compare); // compare 函数用途于自定义的排序
    
    string result;
    
    for (int j=0; j<strList.size(); j++) {
        result+=strList[j];
    }
    
    cout<<result;
    
    return 0;
}
