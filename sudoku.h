#pragma once
#include"EGE/graphics.h"
#include<iostream>
class sudoku{
    void multi_(const int &x,const int &y,int &sum);
public:
    struct pos{int x,y;};
    int g[9][9]={};
    void input(std::istream &is=std::cin);
    void print(std::ostream &os=std::cout)const;
    void output(const int &x,const int &y,const int &l,PIMAGE img=NULL)const;
    void clear(){ memset(g,0,sizeof(g)); }
    bool check(const int &x,const int &y,const int &a)const;
    bool solve();
    bool multi(){int sum=0;multi_(0,0,sum);return sum==1;}
    sudoku generate(int n);
};
