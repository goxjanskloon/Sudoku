#define SHOW_CONSOLE
#include"EGE/graphics.h"
#include<iostream>
#include"sudoku.h"
#include<cstring>
#include"randn.h"
#include<vector>
void sudoku::input(std::istream &is){
    for(int (&p)[9]:g)
        for(int &x:p) is>>x;
}
void sudoku::print(std::ostream &os)const{
    for(const int (&p)[9]:g){
        for(const int &x:p){
            if(x) os<<x;
            else os<<' ';
            os<<' ';
        }
        os<<'\n';
    }
}
void sudoku::output(const int &x,const int &y,const int &l,PIMAGE img)const{
    setbkcolor(WHITE,img);
    setcolor(BLACK,img);
    setlinewidth(5,img);
    rectangle(x,y,x+l,y+l,img);
    const double b=l/3.0,c=l/9.0,d=l/30.0;
    line(x+b,y,x+b,y+l,img);
    line(x+b*2,y,x+b*2,y+l,img);
    line(x,y+b,x+l,y+b,img);
    line(x,y+b*2,x+l,y+b*2,img);
    setlinewidth(2,img);
    for(int i=0;i<9;i++){
        line(x+c*i,y,x+c*i,y+l,img);
        line(x,y+c*i,x+l,y+c*i,img);
    }
    setbkmode(TRANSPARENT,img);
    setfont(c,0,"Consolas",img);
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            if(g[i][j]) outtextxy(x+c*j+d,y+c*i,char('0'+g[i][j]),img);
}
bool sudoku::check(const int &x,const int &y,const int &a)const{
    for(int i=0;i<9;i++)
        if(i!=x&&g[i][y]==a) return 0;
    for(int i=0;i<9;i++)
        if(i!=y&&g[x][i]==a) return 0;
    for(int i=x/3*3,il=(x/3+1)*3;i<il;i++)
        for(int j=y/3*3,jl=(y/3+1)*3;j<jl;j++)
            if((i!=x||j!=y)&&g[i][j]==a) return 0;
    return 1;
}
bool sudoku::gensolve(){
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            if(!g[i][j]){
                std::vector<int> n;
                for(int k=1;k<=9;k++)
                    if(check(i,j,k)) n.push_back(k);
                while(!n.empty()){
                    int v=randn(0,n.size()-1);
                    g[i][j]=n[v];
                    if(gensolve()) return 1;
                    g[i][j]=0;
                    n.erase(n.begin()+v);
                }
                return 0;
            }
    return 1;
}
void sudoku::solve_(const int &x,const int &y){
    int mn=10,mx=0,my=0,ma[10];
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            if(!g[i][j]){
                int cnt[10]{},tn=0;
                for(int k=0;k<9;k++) cnt[g[i][k]]++,cnt[g[k][i]]++;
                for(int k=i/3*3,kl=k+3;k<kl;k++)
                    for(int l=j/3*3,ll=l+3;l<ll;l++) cnt[g[k][l]]++;
                for(int k=1;k<10;k++)
                    if(!cnt[k]) tn++;
                if(!tn){g[x][y]=0;return;}
                if(tn<mn){
                    mn=tn,mx=i,my=j;
                    memcpy(ma+1,cnt+1,sizeof(cnt)-sizeof(int));
                }
            }
    if(mn==10){
        sum++;
        if(prnt) print(*ps),*ps<<'\n';
        g[x][y]=0;return;
    }
    for(int i=1;i<10;i++)
        if(!ma[i]){
            g[mx][my]=i;
            solve_(mx,my);
        }
    g[x][y]=0;return;
}
sudoku sudoku::generate(int n){
    clear();
    gensolve();
    auto res=*this;
    std::vector<pos> np;
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            if(g[i][j]) np.push_back({i,j});
    while(n--){
        const int v=randn(0,np.size()-1),t=g[np[v].x][np[v].y];
        g[np[v].x][np[v].y]=0;
        if(!solve(0)) g[np[v].x][np[v].y]=t;
        else np.erase(np.begin()+v);
    }
    return res;
}
