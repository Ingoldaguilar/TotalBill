#ifndef SHOPPING_H
#define SHOPPING_H
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class Shopping {
public:
    Shopping();
    virtual ~Shopping();
    
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void remove();
    void list();
    void receipt();
    
private:
    int pcode;
    float price;
    float dis;
    string pname;
};

#endif 

