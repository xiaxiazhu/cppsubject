//
//  main.cpp
//  main2
//
//  Created by zhuzhuxia on 2024/12/28.
//

#include <iostream>
#include <vector>

using namespace std;

struct Time{
    int hour;
    int minite;
    int second;
};

Time timeFormat(Time t){
    Time rst = t;
    if (t.second>=60) {
        t.minite += (t.second/60);
        t.second=t.second%60;
    }
    
    if (t.minite>=60) {
        t.hour += (t.minite/60);
        t.minite = t.minite%60;
    }
    rst = t;
    
    return rst;
    
};

Time addTime(const Time&a,const Time&b ){
    Time rst {0,0,0};
    rst.hour= a.hour+b.hour;
    rst.minite = a.minite+b.minite;
    rst.second = a.second+b.second;
    return rst;
};

int main(int argc, const char * argv[]) {
    
    int n;
    cin>>n;
    
    vector<Time> tList(n);
    
    for (int i=0; i<n; i++) {
        cin>>tList[i].hour;
        cin>>tList[i].minite;
        cin>>tList[i].second;
    }
    
    Time rst{0,0,0};
    for (int j=0; j<n; j++) {
        rst = addTime(rst,tList[j]);
    }
    
    rst = timeFormat(rst);
    
    cout<<rst.hour<<"hour "<<rst.minite<<"minute "<<rst.second<<"second"<<"\n";
    
    return 0;
}
