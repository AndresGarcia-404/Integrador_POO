#ifndef _TIENDA
#define _TIENDA
#include <vector>
#include "producto.h"
#include "cliente.h"

class Tienda
{
private:
    string name;
    vector<Producto> productos;
    Cliente cliente;
public:
    Tienda(string);
    string getName();
    Producto regresarProducto(int);
    int cantidadProductos();
    void iniciarCompra();
    void iniciarProductos();
    void mostrarProductos();
    void mostrarMenu();
    void newStock(int,int);
};

#endif