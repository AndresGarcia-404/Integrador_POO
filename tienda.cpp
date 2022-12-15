#include <iostream>
#include "tienda.h"
#include <sstream>
#include <fstream>
#define TIENDITA "inventario.csv"

Tienda::Tienda(string name){
    this->name = name;
    vector<Producto> productos;
}

string Tienda::getName(){
    return this->name;
}

void Tienda::iniciarProductos(){
    ifstream archivo(TIENDITA);
    string linea;
    char delimitador = ',';
    vector<string> p_add;
    while (getline(archivo,linea))
    {
        stringstream stream(linea);
        string id,nameproduct,price,stock;

        getline(stream,id,delimitador);
        getline(stream,nameproduct,delimitador);
        getline(stream,price,delimitador);
        getline(stream,stock,delimitador);

        Producto pnuevo(id,nameproduct,stof(price),stoi(stock));
        productos.push_back(pnuevo);
    };
    archivo.close();
}

void Tienda::mostrarProductos(){
    cout<<"Lista de productos: \n-------------------------------------------------------------\n";
    for(int i=0; i<productos.size(); i++)
    {   
        cout <<i<<": "<<productos[i].getNombre()<<" Precio: "<<productos[i].getPrice()<<" cantidad disponible: "<<productos[i].getStock()<<endl;
        cout<<"-------------------------------------------------------------\n";
    }

}

void Tienda::mostrarMenu(){
    cout<<"***** MENU PRINCIPAL *****"<<endl;
    cout<<"1) Seleccionar producto"<<endl;
    cout<<"2) Ver carrito de compras"<<endl;
    cout<<"3) Terminar compra"<<endl;
    cout<<"4) Salir"<<endl;
}

Producto Tienda::regresarProducto(int index){
    return productos[index];
}

int Tienda::cantidadProductos(){
    return productos.size();
}

void Tienda::newStock(int index,int cantidad){
    int newstock = productos[index].getStock()-cantidad;
    productos[index].setStock(newstock);
}

void Tienda::iniciarCompra(){
    string emailCliente,nameCliente;
    cout<<"antes de iniciar su compra ingrese su nombre: ";cin>>nameCliente;
    cout<<"ingrese su correo: ";cin>>emailCliente;
    Cliente cliente(emailCliente,nameCliente);
    Tienda tienda("Mitiendita.com!");
    tienda.iniciarProductos();
    int op;
    while(op!=4)
    {
        regresoInicio:
        tienda.mostrarMenu();
        cout<<"Selecciona una opcion: ";cin>>op;
        if(op == 1)
        {   
            int objCompra;
            int uniCompra;
            mostrarProd:
            tienda.mostrarProductos();
            cout<<"Que producto deseas comprar (0-"<<tienda.cantidadProductos()-1<<") ? (-1 para cancelar): ";cin>>objCompra;cout<<endl;
            if(objCompra == -1)
            {
                goto regresoInicio;
            } 
            else if(objCompra > (tienda.cantidadProductos()-1) || objCompra < 0)
            {
                cout<<"\nSelecciona una opcion correcta.\n";
                goto mostrarProd;
            }
            Producto pcompra = tienda.regresarProducto(objCompra);
            unidadesAd:
            cout<<"Cuantas unidades deseas adquirir?: ";cin>>uniCompra;cout<<endl;
            if(uniCompra <= 0)
            {
                cout<<"\nSelecciona una cantidad adecuada mayor que 0.\n";
                goto unidadesAd;
            } 
            else if(uniCompra > pcompra.getStock())
            {
                cout<<"\nNo hay Stock disponible para la venta.\n";
                goto unidadesAd;
            }
            pcompra.setStock(uniCompra);
            tienda.newStock(objCompra,uniCompra);
            cliente.comprar(pcompra);
        }
        else if(op == 2)
        {
            if(cliente.totalCompra() == 0)
            {
                cout<<"\nNo se han agregado productos.\n\n";
            }
            cliente.mostrarCarrito();
        }
        else if(op == 3)
        {
            cout<<cliente.getName()<<" El total de tu compra es: "<<cliente.totalCompra()<<endl;
            cout<<"Gracias por comprar en: "<<tienda.getName()<<endl;
            cout<<"su ticket sera enviado a: "<<cliente.getEmail()<<endl;
            break;
        }
    }
}