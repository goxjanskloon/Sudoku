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
    std::cout<<"请输入将用于储存数独的文件夹路径(以‘/’结尾):\n";
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
    std::cout<<"生成完毕,按任意键继续...\n";
    getch_console();
}
void solvesud(){
    sudoku sud;
    std::cout<<"请输入数独(空格分隔列,换行分割行,无需区分宫,空格子用0表示):\n";
    sud.input();
    std::cout<<"正在解数独,请稍等...(若有多个解,仅随机出一个)\n";
    if(sud.solve()) std::cout<<"数独无解!";
    else std::cout<<"数独的解为:\n",sud.print();
    std::cout<<"按任意键继续...\n";
}
int main(){
    while(1){
        std::cout<<"\n欢迎使用九宫标准数独工具,按g生成数独,s解数独,q退出:\n";
        switch(getch_console()){
        case 'g':genimg();break;
        case 's':solvesud();break;
        case 'q':std::cout<<"\n欢迎下次使用!按任意键退出...";getch_console();goto end;
        default:std::cout<<"无效操作!\n";
        }
    }
end:return 0;
}
