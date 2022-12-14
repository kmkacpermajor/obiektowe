#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include "lab4.h"


int main(){
    Samochod s1(123, "audi");
    Samochod s2(0, "bmw");
    Samochod s3(200, "");

    if(s1){
        std::cout << "Model nie jest pustym stringiem i pojemność baku większa niż 0" << std::endl;
    }

    if(!s1){
        std::cout << "Model jest pustym stringiem i pojemność baku nie jest większa niż 0" << std::endl;
    }

    if(s1<s2){
        std::cout << "prawda" << std::endl;
    }

    std::vector <Samochod> v;
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    sort(v.begin(),v.end());
    
    for(auto it=v.begin(); it!=v.end(); ++it){
        std::cout<<*it<<std::endl;
    }

    std::set <Samochod,cmp>s;
    s.insert(s1);
    s.insert(s2);
    s.insert(s3);

    for(auto it=s.begin();it!=s.end();++it){
        std::cout << *it << std::endl;
    }

    std::cout << "Poziom " << s1.getPoziomPaliwa() << std::endl;
    std::cout << "Nazwa " << s2.getModel() << std::endl;
    std::cout << "Pojemnosc " << s3.getPojemnoscBaku() << std::endl;

    s1++;
    s2,"x5";
    s3|= 50;

    std::cout << "Poziom " << s1.getPoziomPaliwa() << std::endl;
    std::cout << "Nazwa " << s2.getModel() << std::endl;
    std::cout << "Pojemnosc " << s3.getPojemnoscBaku() << std::endl;

    return 0;
}