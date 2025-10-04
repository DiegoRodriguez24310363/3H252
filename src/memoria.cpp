#include<iostream>
using namespace std;

class Empleado{
    private: //Nacen de la relacion tienen
    char nombre[10];     // 10 B
    int edad;            // 4 B
    char direccion[255]; // 255 B
    int telefono;        //4 B
    public: //Interfaz y nacen de la relacion usa
    int LeerEdad(){
        return edad;
    }
}; // 273B

int main(int argc, char const *argv[])
{
    //Enteros
    cout<<"Tamaño de int " << sizeof(int) << endl;
    cout<<"Tamaño de int " << sizeof(long)<< endl;
    //Punto Flotante
    cout<<"Tamaño de float " << sizeof(float)<< endl;
    cout<<"Tamaño de double " << sizeof(double)<< endl;
    //Bytes
    cout<<"Tamaño de char " << sizeof(char)<< endl;
    cout<<"Tamaño de byte " << sizeof(byte)<< endl;
    cout<<"Tamaño de bool " << sizeof(bool)<< endl;

    cout<<"Tamaño puntero " << sizeof(int *)<< endl;
    
    Empleado empleados[10];  // 2730 B
    cout << "Tamaño Empleado " << sizeof(Empleado) << endl;
    cout << "Empleados" << empleados[0].LeerEdad() <<endl;

    int a= 64;
    char b= (char) a;
    cout << b << endl;
    return 0;
}