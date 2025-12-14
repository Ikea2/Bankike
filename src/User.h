#pragma once

#include<iostream>
#include "User.h"
#include<string>

struct Datos_Ban {  //Datos de la cuenta de cada usuario 
	float saldo = 0;
	float Ult_Mov;
};

struct Usuario_Real {  //Datos guardados de cuentas validas
	std::string UserNameR;
	std::string PasswordR;

	struct Datos_Ban UserData;
};



struct Usuario_str {  //usuario que introduces en la interfaz
	std::string UserName;
	std::string Password;
};


void pedirDatosUsuario();
void menuUsuario();


extern Usuario_Real UsuariosR[6];
extern int l; // máximo de cuentas aux
