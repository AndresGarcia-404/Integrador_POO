#ifndef _Producto
#define _Producto
#include <string>
using namespace std;

class Producto
{ 

private:
    string id;
    string name;
    float price;

public:
    int stock;

    Producto(string,string,float,int);

    //getters
    string getNombre();
    string getId();
    float getPrice();
    int getStock();
    //setters
    void setStock(int);    
};

#endif