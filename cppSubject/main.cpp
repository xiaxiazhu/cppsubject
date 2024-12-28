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
////#include <cmath>
//#include <climits>
////#include <unordered_map>
////#include <stack>
//#include <sstream>
//#include <algorithm>
//#include <cctype>
//#include <unordered_map>
#include <list>
#include <iterator>

using namespace std;

struct Time{
    int hi;
    int mi;
};
Time timeFormat(Time t){
    Time r;
    if (t.mi>=60) {
        r.mi = t.mi%60;
        r.hi = t.hi+ t.mi/60;
    }else{
        return t;
    }
    return r;
};

Time addTime(const Time &a,const Time &b){
    Time result ;
    result.hi = a.hi + b.hi;
    result.mi = a.mi + b.mi;
    return result;
};

int main(){
    int n;
    cin>>n;
    
    
    vector<Time> tList(n);
    
    for (int i = 0 ; i < n; i++) {
        cin >> tList[i].hi;
        cin >> tList[i].mi;
    }
    
    Time result{0,0};
    
    for (int j =0; j<n; j++) {
        result = addTime( result , tList[j]);
    }
    
    result = timeFormat(result);
    
    cout<< result.hi<<" "<<result.mi<<"\n";
    
    return 1;
}

