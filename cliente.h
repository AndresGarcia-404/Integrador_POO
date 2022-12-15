#ifndef _CLIENTE
#define _CLIENTE
#include "carrito.h"
#include "producto.h"

class Cliente
{

private:
    string email;
    string name;
public:
    Carrito carrito;
    Cliente(string, string);
    Cliente();
    string getEmail();
    string getName();
    void setEmail(string);
    void setName(string);
    void comprar(Producto);
    void mostrarCarrito();
    float totalCompra();
};
#endif