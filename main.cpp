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
    std::cout<<"��ӭʹ������������,�����봢���������ļ���·��(�ԡ�/����β):\n";
    std::getline(std::cin,path);
    std::cout<<"�����������пո�ĸ���(0~64):";
    int k,n;
    std::cin>>k;
    std::cout<<"��������Ҫ���ɵ���������:";
    std::cin>>n;
    sudoku sud,ans;
    PIMAGE img=newimage(620,1230);
    std::cout<<"��ȴ��������,��Ҫ��Ŀ���ļ��н��в���...\n";
    for(int i=1;i<=n;i++){
        cleardevice(img);
        (ans=sud.generate(k)).output(10,620,600,img);
        sud.output(10,10,600,img);
        saveimage(img,(path+int2str(i)+".png").c_str());
    }
    std::cout<<"�������,��������˳�...";
    getch_console();
}
int main(){
    genimg();
    return 0;
}
