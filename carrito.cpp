#include <iostream>
#include <string>
#include <vector>
#include "producto.h"
#include "carrito.h"
using namespace std;

Carrito::Carrito()
{
    this->price = 0.0;
    vector<Producto>inven;

}

float Carrito::getPrice(){
    float sum = 0;
    for (int i = 0; i < inven.size(); i++)
    {
        sum = sum + (inven[i].getPrice()*inven[i].getStock());
    }
    return sum;
}

void Carrito::agregarProducto(Producto nuevo){
    inven.push_back(nuevo);
}

void Carrito::mostrarProducto(){
    for (int i = 0; i < inven.size(); i++){
        cout<<"------------------------------------";
        cout<<"Producto: "<<i+1<<endl;
        cout<<"id: "<<inven[i].getId()<<endl;
        cout<<"name: "<<inven[i].getNombre()<<endl;
        cout<<"precio Unitario: "<<inven[i].getPrice()<<endl;
        cout<<"Cantidad a llevar: "<<inven[i].getStock()<<endl;
    }
}
