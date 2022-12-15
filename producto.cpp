#include <iostream>
#include "producto.h"
using namespace std;

Producto::Producto(string id,string name,float price,int stock)
{
    this->id =id;
    this->name =name;
    this->price =price;
    this->stock =stock;
}


string Producto::getId(){
    return id;
}
float Producto::getPrice(){
    return price;
}
string Producto::getNombre(){
    return name;
}
int Producto::getStock(){
    return stock;
}

void Producto::setStock(int stock){
    this -> stock = stock;
}