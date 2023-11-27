#pragma once
#include<random>
inline int randn(const int &l,const int &r){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(l,r);
    return dist(gen);
}
