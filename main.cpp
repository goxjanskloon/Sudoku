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
    std::cout<<"�����뽫���ڴ����������ļ���·��(�ԡ�/����β):\n";
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
    std::cout<<"�������,�����������...\n";
    getch_console();
}
void solvesud(){
    sudoku sud;
    std::cout<<"����������(�ո�ָ���,���зָ���,�������ֹ�,�ո�����0��ʾ):\n";
    sud.input();
    std::cout<<"���ڽ�����,���Ե�...(���ж����,�������һ��)\n";
    if(sud.solve()) std::cout<<"�����޽�!";
    else std::cout<<"�����Ľ�Ϊ:\n",sud.print();
    std::cout<<"�����������...\n";
}
int main(){
    while(1){
        std::cout<<"\n��ӭʹ�þŹ���׼��������,��g��������,s������,q�˳�:\n";
        switch(getch_console()){
        case 'g':genimg();break;
        case 's':solvesud();break;
        case 'q':std::cout<<"\n��ӭ�´�ʹ��!��������˳�...";getch_console();goto end;
        default:std::cout<<"��Ч����!\n";
        }
    }
end:return 0;
}
