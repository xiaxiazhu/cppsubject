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
    int top,bottom,left,right;
    int w;
    int h;
};

bool chongDie(Rectangle rect1,Rectangle rect2){
    
    if (rect2.y1-rect1.y2>=0||rect2.x2-rect1.x1>=0||rect2.y2<=rect1.y1||rect2.x1<=rect1.x2) {
        return  false;
    }
    
    return true;
}

int main(){
    
    Rectangle rect1;
    cin>>rect1.left;cin>>rect1.right;cin>>rect1.top;cin>>rect1.bottom;
    
    Rectangle rect2;
    cin>>rect2.left;cin>>rect2.right;cin>>rect2.top;cin>>rect2.bottom;
    
    //假设窗口很大，w=100000000；h=1000000000；
    int width = 10000;
    int height = 10000;
    
    rect1.w = width-rect1.left-rect1.right;
    rect1.h = height-rect1.top-rect1.bottom;
    rect1.x1 = rect1.top+rect1.h;
    rect1.y1 = rect1.left;
    rect1.x2 = rect1.top;
    rect1.y2 = rect1.left+rect1.w;
    
    rect2.w = width-rect2.left-rect2.right;
    rect2.h = height-rect2.top-rect2.bottom;
    rect2.x1 = rect2.top+rect2.h;
    rect2.y1 = rect2.left;
    rect2.x2 = rect2.top;
    rect2.y2 = rect2.left+rect2.w;
    
    if (chongDie(rect1, rect2)) {
        // 计算重叠区的w 和h
        int cw = rect2.h - abs(rect2.x1-rect1.x1);
        int ch = rect2.w - abs(rect2.y2-rect1.y2);
        
        cout<<cw*ch;
        
    }else{
        cout<<0;
    }
    
    
    
    
    
    
    
    
    
    return 0;
}
