#include "User.h"
#include <cstdlib>
#include <string.h>
#include <Windows.h>
#include <iostream>
#include <time.h>

using namespace std;

Usuario_Real UsuariosR[6];
Usuario_str Usuario;



HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
bool p = false; //si ha fallado la contraseña
int Valid = 0;
int l = 0; //maximo de cuentas aux
int n_user = 0; //el numero en el que el usuario ha creado su cuenta en el array 
int accion = 0;
int AdminUser = 0; // numero de cuenta buscado por el admin
int g = 0;
float ingreso = 0;
bool close = false;
bool vAdmin = false;
bool admin = false;
std::string respuesta;


void pedirDatosUsuario() {
    while (Valid == 0) {
        SetConsoleTextAttribute(h, 13);
        cout << "Bienvenido de Nuevo" << endl;
        SetConsoleTextAttribute(h, 7);
        if (l < 3) {
            cout << "\nDesea crearse una cuenta: ";
            cin >> respuesta;
            if (respuesta == "si") {
                cout << "\nIngrese el nombre de usuario de su nueva cuenta: ";
                cin >> UsuariosR[1 + l].UserNameR;
                cout << "Ingrese la contraseña de su nueva cuenta: ";
                cin >> UsuariosR[1 + l].PasswordR;
                n_user = 1 + l;
                l += 1;
            }
        }
        else {
            cout << "No se pueden crear más cuentas" << endl;
        }

        //pedir Datos al Usuario
        cout << "\nUsuario: ";
        cin >> Usuario.UserName;
        cout << "Contraseña: ";
        cin >> Usuario.Password;

        for (int i = 0; i < 6; i++) {  //revisa los 5 espacios de la memoria de cuantas validas
            if (Usuario.UserName == UsuariosR[i].UserNameR && Usuario.Password == UsuariosR[i].PasswordR) {
                Valid = 1;
                break;
            }
        }
        if (Usuario.UserName == UsuariosR[5].UserNameR && Usuario.Password == UsuariosR[5].PasswordR) {
            admin = true;
        }

        if (Valid == 0) {
            SetConsoleTextAttribute(h, 12);
            cout << "\nUsuario o contraseña incorrecta " << endl << endl;
            p = true;
            SetConsoleTextAttribute(h, 1);
        }
        SetConsoleTextAttribute(h, 7);
    }
}