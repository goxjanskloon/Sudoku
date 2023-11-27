#define SHOW_CONSOLE
#include"EGE/graphics.h"
#include"sudoku.h"
#include<algorithm>
#include<iostream>
#include<string>
int getch_console();
std::string int2str(int a){
    std::string res;
    for(;a;a/=10) res+=char('0'+a%10);
    std::reverse(res.begin(),res.end());
    return res;
}
void genimg(){
    std::string path;
    std::cout<<"欢迎使用数度生成器,请输入储存数独的文件夹路径(以‘/’结尾):\n";
    std::getline(std::cin,path);
    std::cout<<"请输入数独中空格的个数(0~64):";
    int k,n;
    std::cin>>k;
    std::cout<<"请输入需要生成的数独个数:";
    std::cin>>n;
    sudoku sud,ans;
    PIMAGE img=newimage(620,1230);
    std::cout<<"请等待生成完毕,不要对目标文件夹进行操作...\n";
    for(int i=1;i<=n;i++){
        cleardevice(img);
        (ans=sud.generate(k)).output(10,620,600,img);
        sud.output(10,10,600,img);
        saveimage(img,(path+int2str(i)+".png").c_str());
    }
    std::cout<<"生成完毕,按任意键退出...";
    getch_console();
}
int main(){
    genimg();
    return 0;
}
