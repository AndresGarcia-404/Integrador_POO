#include "cliente.h"
#include "carrito.h"
#include <iostream>


Cliente::Cliente(){
}
Cliente::Cliente(string email,string name){
    this->email = email;
    this->name = name;
}
string Cliente::getEmail(){
    return this->email;
}
string Cliente::getName(){
    return this->name;
}
void Cliente::setEmail(string email){
    this->email = email;
}
void Cliente::setName(string name){
    this->name = name;
}
void Cliente::comprar(Producto p1){
    carrito.agregarProducto(p1);
}
float Cliente::totalCompra(){
    return carrito.getPrice();
}
void Cliente::mostrarCarrito(){
    carrito.mostrarProducto();
}