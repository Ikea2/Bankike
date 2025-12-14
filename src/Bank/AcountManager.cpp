#include<stdlib.h>

#include<time.h>

#include "../User.h"


#include "AcountManager.h"

void iniciarCuentas() {
	UsuariosR[5].UserNameR = "iker";
	UsuariosR[5].PasswordR = "admin";
	UsuariosR[5].UserData.saldo = 99999;
	UsuariosR[4].UserNameR = "juanjo";
	UsuariosR[4].PasswordR = "programador";
	UsuariosR[4].UserData.saldo = 50;
	UsuariosR[4].UserData.Ult_Mov = -120;
	UsuariosR[3].UserNameR = "gael";
	UsuariosR[3].PasswordR = "siena";
	UsuariosR[3].UserData.saldo = 1300;
	UsuariosR[3].UserData.Ult_Mov = -99;
}

void rellenarCuentas() {
	srand(time(NULL));
	for (int j = 1; j < 3; j++) {  //rellenar cuentas vacias o con valores basura 
		UsuariosR[j].PasswordR = "";
		for (int k = 0; k < 4; k++) { // contraseña de 4 letras 
			UsuariosR[j].PasswordR += char('A' + rand() % 26);
		}
	}
}