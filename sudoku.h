#pragma once
#include"EGE/graphics.h"
#include<iostream>
class sudoku{
    void solve_(const int &x,const int &y);
    int sum=0;
    bool prnt=0;
    std::ostream *ps=nullptr;
public:
    struct pos{int x,y;};
    int g[9][9]={};
    void input(std::istream &is=std::cin);
    void print(std::ostream &os=std::cout)const;
    void output(const int &x,const int &y,const int &l,PIMAGE img=NULL)const;
    void clear(){memset(g,0,sizeof(g));}
    bool solve(const bool &prnt_=1,std::ostream &os=std::cout){
        sum=0,prnt=prnt_,ps=&os,solve_(0,0);
        return sum==1;
    }
    bool check(const int &x,const int &y,const int &a)const;
    bool gensolve();
    sudoku generate(int n);
};
