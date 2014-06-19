//
//  main.cpp
//  RDP
//
//  Created by Yongjiao Yu on 14-6-17.
//  Copyright (c) 2014年 ___RCPD___. All rights reserved.
//

#include "simplifyPath.h"
using std::vector;

int main(){
    vector<Point> Points(5);
    Points[0].x=0;
    Points[0].y=0;
    Points[1].x=5;
    Points[1].y=9;
    Points[2].x=10;
    Points[2].y=10;
    Points[3].x=15;
    Points[3].y=7;
    Points[4].x=20;
    Points[4].y=0;
    double epsilon=2;
    
    simplifyPath testobject;
    vector<Point> path=testobject.simplifyWithRDP(Points,epsilon);
    for(vector<Point>::const_iterator i = path.begin(); i < path.end(); ++i)
        std::cout <<'('<<i->x<< ", "<<i->y << ") ";
    std::cout<<std::endl;
    return EXIT_SUCCESS;
}