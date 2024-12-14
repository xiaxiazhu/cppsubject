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
//#include <cmath>
#include <climits>
//#include <unordered_map>
//#include <stack>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <unordered_map>

using namespace std;

struct Rectangle{
    int x1;
    int y1;
    int x2;
    int y2;
}; // 取左上角和右下角的坐标

bool chongDie(Rectangle rect1,Rectangle rect2){
    
    if (rect1.x1>=rect2.x2 || rect2.y1>=rect1.y2 || rect2.x1>=rect1.x2 || rect2.y2<=rect1.y1) {
        return  false;
    }
    
    return true;
}

int main(){
    
    Rectangle rect1;
    cin>>rect1.y1;cin>>rect1.y2;cin>>rect1.x1;cin>>rect1.x2;
    
    Rectangle rect2;
    cin>>rect2.y1;cin>>rect2.y2;cin>>rect2.x1;cin>>rect2.x2;
    
    
    if (chongDie(rect1, rect2)) {
        // 计算重叠区的w 和h// 多个长方形重叠可以通过区间数来快速判断是否重叠。
        
        int overlapH = max(0, min(rect2.x2,rect1.x2)-max(rect1.x1, rect2.x1));
        int overlapW = max(0,min(rect2.y2,rect1.y2)-max(rect1.y1,rect2.y1));
        
        cout<< overlapH*overlapW;
        
    }else{
        cout<<0;
    }
    
    return 0;
}
