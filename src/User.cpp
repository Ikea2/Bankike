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

void menuUsuario() {
	SetConsoleTextAttribute(h, 10);
	cout << endl << "DATOS DE INICIO DE SESION CORRECTOS" << endl;

	if (admin == true) {
		do {
			SetConsoleTextAttribute(h, 13);
			cout << "\nMENU DE ADMIN: ";
			SetConsoleTextAttribute(h, 7);
			cout << "\nDigite ";
			SetConsoleTextAttribute(h, 2);
			cout << "1 ";
			SetConsoleTextAttribute(h, 7);
			cout << "para ver el saldo actual" << endl;
			cout << "Digite ";
			SetConsoleTextAttribute(h, 2);
			cout << "2 ";
			SetConsoleTextAttribute(h, 7);
			cout << "para ver los ultimos movimientos" << endl;
			cout << "Digite ";
			SetConsoleTextAttribute(h, 2);
			cout << "3 ";
			SetConsoleTextAttribute(h, 7);
			cout << "para ingresar dinero" << endl;
			cout << "Digite ";
			SetConsoleTextAttribute(h, 2);
			cout << "4 ";
			SetConsoleTextAttribute(h, 7);
			cout << "para extraer dinero" << endl;
			cout << "Digite ";
			SetConsoleTextAttribute(h, 2);
			cout << "5 ";
			SetConsoleTextAttribute(h, 7);
			cout << "para cerrar sesion" << endl;
			cin >> accion;
			switch (accion) {
			case 1: cout << "\nDigite el nombre del usuario del cual desea acceder a su saldo: ";
				cin >> Usuario.UserName;
				for (int i = 0; i < 6; i++) {
					if (Usuario.UserName == UsuariosR[i].UserNameR) {
						vAdmin = true;
						AdminUser = i;
					}
				}
				if (vAdmin == true) {
					cout << "Saldo de ";
					SetConsoleTextAttribute(h, 2);
					cout << UsuariosR[AdminUser].UserNameR << ": ";
					SetConsoleTextAttribute(h, 7);
					cout << endl << UsuariosR[AdminUser].UserData.saldo;
				}
				else {
					SetConsoleTextAttribute(h, 4);
					cout << "\nNOMBRE DE USUARIO NO ENCONTRADO";
					SetConsoleTextAttribute(h, 7);
				}
				cout << "\nDigite ";
				SetConsoleTextAttribute(h, 2);
				cout << "1 ";
				SetConsoleTextAttribute(h, 7);
				cout << "para volver al menu" << endl;
				cout << "Digite ";
				SetConsoleTextAttribute(h, 2);
				cout << "2 ";
				SetConsoleTextAttribute(h, 7);
				cout << "para cerrar sesion" << endl;
				cin >> accion;
				if (accion == 2) {
					close = true;
				} break;
			case 2: cout << "\nDigite el nombre del usuario del cual desea acceder a su ultimo movimineto: ";
				cin >> Usuario.UserName;
				for (int i = 0; i < 6; i++) {
					if (Usuario.UserName == UsuariosR[i].UserNameR) {
						vAdmin = true;
						AdminUser = i;
					}
				}
				if (vAdmin == true) {
					cout << "Ultimo movimiento de ";
					SetConsoleTextAttribute(h, 2);
					cout << UsuariosR[AdminUser].UserNameR << ": ";
					SetConsoleTextAttribute(h, 7);
					cout << endl << UsuariosR[AdminUser].UserData.Ult_Mov;
				}
				else {
					SetConsoleTextAttribute(h, 4);
					cout << "\nNOMBRE DE USUARIO NO ENCONTRADO";
					SetConsoleTextAttribute(h, 7);
				}
				cout << "\nDigite ";
				SetConsoleTextAttribute(h, 2);
				cout << "1 ";
				SetConsoleTextAttribute(h, 7);
				cout << "para volver al menu" << endl;
				cout << "Digite ";
				SetConsoleTextAttribute(h, 2);
				cout << "2 ";
				SetConsoleTextAttribute(h, 7);
				cout << "para cerrar sesion" << endl;
				cin >> accion;
				if (accion == 2) {
					close = true;
				} break;
			case 3: cout << "\nDigite el nombre del usuario al cual desea ingresar dinero: ";
				cin >> Usuario.UserName;
				for (int i = 0; i < 6; i++) {
					if (Usuario.UserName == UsuariosR[i].UserNameR) {
						vAdmin = true;
						AdminUser = i;
					}
				}
				if (vAdmin == true) {
					cout << "\nDigite la cantidad a ingresar: ";
					cin >> ingreso;
					UsuariosR[AdminUser].UserData.saldo += ingreso;
					cout << "Saldo de ";
					SetConsoleTextAttribute(h, 2);
					cout << UsuariosR[AdminUser].UserNameR << ": ";
					SetConsoleTextAttribute(h, 7);
					cout << endl << UsuariosR[AdminUser].UserData.saldo;
				}
				else {
					SetConsoleTextAttribute(h, 4);
					cout << "\nNOMBRE DE USUARIO NO ENCONTRADO";
					SetConsoleTextAttribute(h, 7);
				}
				cout << "\nDigite ";
				SetConsoleTextAttribute(h, 2);
				cout << "1 ";
				SetConsoleTextAttribute(h, 7);
				cout << "para volver al menu" << endl;
				cout << "Digite ";
				SetConsoleTextAttribute(h, 2);
				cout << "2 ";
				SetConsoleTextAttribute(h, 7);
				cout << "para cerrar sesion" << endl;
				cin >> accion;
				if (accion == 2) {
					close = true;
				} break;
			case 4: cout << "\nDigite el nombre del usuario al cual desea retirar dinero: ";
				cin >> Usuario.UserName;
				for (int i = 0; i < 6; i++) {
					if (Usuario.UserName == UsuariosR[i].UserNameR) {
						vAdmin = true;
						AdminUser = i;
					}
				}
				if (vAdmin == true) {
					cout << "\nDigite la cantidad a retirar: ";
					cin >> ingreso;
					UsuariosR[AdminUser].UserData.saldo -= ingreso;
					cout << "Saldo de ";
					SetConsoleTextAttribute(h, 2);
					cout << UsuariosR[AdminUser].UserNameR << ": ";
					SetConsoleTextAttribute(h, 7);
					cout << endl << UsuariosR[AdminUser].UserData.saldo;
				}
				else {
					SetConsoleTextAttribute(h, 4);
					cout << "\nNOMBRE DE USUARIO NO ENCONTRADO";
					SetConsoleTextAttribute(h, 7);
				}
				cout << "\nDigite ";
				SetConsoleTextAttribute(h, 2);
				cout << "1 ";
				SetConsoleTextAttribute(h, 7);
				cout << "para volver al menu" << endl;
				cout << "Digite ";
				SetConsoleTextAttribute(h, 2);
				cout << "2 ";
				SetConsoleTextAttribute(h, 7);
				cout << "para cerrar sesion" << endl;
				cin >> accion;
				if (accion == 2) {
					close = true;
				} break;

			case 5: close = true;
				break;
			}
		} while (close == false);
	}
	else {
		do {
			SetConsoleTextAttribute(h, 13);
			cout << "\nMENU: ";
			SetConsoleTextAttribute(h, 7);
			cout << "\nDigite ";
			SetConsoleTextAttribute(h, 2);
			cout << "1 ";
			SetConsoleTextAttribute(h, 7);
			cout << "para ver el saldo actual" << endl;
			cout << "Digite ";
			SetConsoleTextAttribute(h, 2);
			cout << "2 ";
			SetConsoleTextAttribute(h, 7);
			cout << "para ver los ultimos movimientos" << endl;
			cout << "Digite ";
			SetConsoleTextAttribute(h, 2);
			cout << "3 ";
			SetConsoleTextAttribute(h, 7);
			cout << "para ingresar dinero" << endl;
			cout << "Digite ";
			SetConsoleTextAttribute(h, 2);
			cout << "4 ";
			SetConsoleTextAttribute(h, 7);
			cout << "para extraer dinero" << endl;
			cout << "Digite ";
			SetConsoleTextAttribute(h, 2);
			cout << "5 ";
			SetConsoleTextAttribute(h, 7);
			cout << "para cerrar sesion" << endl;
			cin >> accion;


			switch (accion) {
			case 1: SetConsoleTextAttribute(h, 6);
				cout << endl << "SALDO:" << endl;
				SetConsoleTextAttribute(h, 7);
				cout << UsuariosR[n_user].UserData.saldo << endl;
				cout << "\nDigite ";
				SetConsoleTextAttribute(h, 2);
				cout << "1 ";
				SetConsoleTextAttribute(h, 7);
				cout << "para volver al menu" << endl;
				cout << "Digite ";
				SetConsoleTextAttribute(h, 2);
				cout << "2 ";
				SetConsoleTextAttribute(h, 7);
				cout << "para cerrar sesion" << endl;
				cin >> accion;
				if (accion == 2) {
					close = true;
				} break;
			case 2: SetConsoleTextAttribute(h, 6);
				cout << endl << "ULTIMO MOVIMIENTO:" << endl;
				SetConsoleTextAttribute(h, 7);
				cout << UsuariosR[n_user].UserData.Ult_Mov << endl;
				cout << "\nDigite ";
				SetConsoleTextAttribute(h, 2);
				cout << "1 ";
				SetConsoleTextAttribute(h, 7);
				cout << "para volver al menu" << endl;
				cout << "Digite ";
				SetConsoleTextAttribute(h, 2);
				cout << "2 ";
				SetConsoleTextAttribute(h, 7);
				cout << "para cerrar sesion" << endl;
				cin >> accion;
				if (accion == 2) {
					close = true;
				}break;
			case 3: cout << "\nDigite la cantidad a ";
				SetConsoleTextAttribute(h, 2);
				cout << "ingresar: ";
				SetConsoleTextAttribute(h, 7);
				cin >> ingreso;
				UsuariosR[n_user].UserData.saldo += ingreso;
				UsuariosR[n_user].UserData.Ult_Mov = ingreso;
				cout << "\nDigite ";
				SetConsoleTextAttribute(h, 2);
				cout << "1 ";
				SetConsoleTextAttribute(h, 7);
				cout << "para volver al menu" << endl;
				cout << "Digite ";
				SetConsoleTextAttribute(h, 2);
				cout << "2 ";
				SetConsoleTextAttribute(h, 7);
				cout << "para cerrar sesion" << endl;
				cin >> accion;
				if (accion == 2) {
					close = true;
				}break;

			case 4: cout << "\nDigite la cantidad a ";
				SetConsoleTextAttribute(h, 4);
				cout << "retirar: ";
				SetConsoleTextAttribute(h, 7);
				cin >> ingreso;
				UsuariosR[n_user].UserData.saldo -= ingreso;
				UsuariosR[n_user].UserData.Ult_Mov = ingreso * (-1);
				cout << "\nDigite ";
				SetConsoleTextAttribute(h, 2);
				cout << "1 ";
				SetConsoleTextAttribute(h, 7);
				cout << "para volver al menu" << endl;
				cout << "Digite ";
				SetConsoleTextAttribute(h, 2);
				cout << "2 ";
				SetConsoleTextAttribute(h, 7);
				cout << "para cerrar sesion" << endl;
				cin >> accion;
				if (accion == 2) {
					close = true;
				}break;

			case 5: close = true;
				break;
			}
		} while (close == false);
	}


	SetConsoleTextAttribute(h, 10);
	cout << endl << "\nSESION CERRADA CORRECTAMENTE" << endl << endl;
	SetConsoleTextAttribute(h, 7);
}