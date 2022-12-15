#ifndef _Carrito
#define _Carrito
#include <string>
#include <vector>
#include "producto.h"
using namespace std;

class Carrito
{ 

public:
    vector<Producto> inven;
    float price;

    Carrito();
    
    float getPrice();
    void mostrarProducto();
    void agregarProducto(Producto);

   
};

#endif