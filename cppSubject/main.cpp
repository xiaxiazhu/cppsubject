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

class Point{
public:
    int x;
    int y;
    Point():x(1),y(1){};
    Point(int _x,int _y):x(_x),y(_y){};
    
    bool operator==(const Point& other)const{
        return (x==other.x)&&(y==other.y);
    }
    bool operator < (const Point& other)const{
        return (x<other.x)||(x==other.x && y<other.y);
    }
};

class Robet{
public:
    //current postion
    int x=1;
    int y=1;
    int d=0;
    vector<vector<char>> map;
    int mapn=0;
    int mapm=0;
    int k=5;
    unsigned long step=1;
    vector<Point> lujingPoints;
    
    Robet( int _x,int _y,int _d,int _n,int _m,int _k):x(_x),y(_y),d(_d),mapn(_n),mapm(_m),k(_k){
        
        vector<vector<char>> nmMap(this->mapn+2,vector<char>(this->mapm+2,'0'));
        
        // 录入map数据
        for (int i = 1; i<=this->mapn;i++) {
            for (int j=1; j<=this->mapm; j++) {
                cin>>nmMap[i][j];
            }
        }
        
        this->map = nmMap;
        
        // 初始化位置
        this->lujingPoints.push_back(Point(x,y));
        
    }; // 初始化列表
    
    unsigned long duplicateLujing(){
        
        
        sort(this->lujingPoints.begin(), this->lujingPoints.end());
        
        auto last = unique(this->lujingPoints.begin(), this->lujingPoints.end());
        
        this->lujingPoints.erase(last,this->lujingPoints.end());
        
//        set<Point>uniquePointSet(this->lujingPoints.begin(),this->lujingPoints.end());//set 可以自动去重
//
//        vector<Point> uniqueLujing(uniquePointSet.begin(),uniquePointSet.end());
//
//        this->lujingPoints=uniqueLujing;
//
//        return lujingPoints.size();
        
        return  this->lujingPoints.size();
    }
    
    //d=0 代表向东， d = 1 d=1 代表向南， d = 2 d=2 代表向西， d = 3 d=3 代表向北
    
    int goNext(){
        
        if (this->k<=0) {
            return 100;
        }
        int nextX=0;
        int nextY=0;
        int direction = this->d;
        
        if (direction==0) {
            nextX=this->x;
            nextY=this->y+1;
        }
        if (direction==1) {
            nextX=this->x+1;
            nextY=this->y;
        }
        if (direction==2) {
            nextX=this->x;
            nextY=this->y-1;
        }
        if (direction==3) {
            nextX=this->x-1;
            nextY=this->y;
        }
        

        if (nextX<1||nextX>this->mapn||nextY<1||nextY>this->mapm) {
            
            this->d = (++direction)%4;
//            cout<<"changedir"<< this->d<<" ";
            this->k--;
            goNext();
        }
        // map
        if (this->map[nextX][nextY] == 'x') {
            // 往右转
            this->d = (++direction)%4;
//            cout<<"changedireright"<< d <<" ";

            this->k--;
            goNext();
        }
        if (this->map[nextX][nextY] == '.') {
            
            this->x=nextX;
            this->y=nextY;
            this->k--;
            this->step++;
            
            this->lujingPoints.push_back(Point(nextX,nextY));
            
//            cout<<"next"<<" "<<nextX<<" "<<nextY<<" ";

            goNext();
        }

        // out -1
        // not avalible 1
        // yes 2
        return -1;
    }
    
    
};

int main(){

    // 读入数据，
    // 数据组数
    // n,m,k
    //x0,y0,d0
    // 地图，n行，m列
    
    int zushu;
    cin>>zushu;
    
    Robet * robet[zushu];

    for (int z=0; z<zushu; z++) {
        
        int n[zushu],m[zushu],k[zushu],x0[zushu],y0[zushu],d0[zushu];
        // 第z组
        cin>>n[z]>>m[z]>>k[z];
        cin>>x0[z]>>y0[z]>>d0[z];
        
        //起始数据
        // n个类的实例
        robet[z]= new Robet(x0[z],y0[z],d0[z],n[z],m[z],k[z]);
        
    }
    
    for (int r=0; r<zushu; r++) {
        robet[r]->goNext();
        // lujing去重复的点
        
        robet[r]->step=robet[r]->duplicateLujing();
        
        cout<<robet[r]->step<<endl;
    }

    
    return 0;
}
