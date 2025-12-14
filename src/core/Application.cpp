#include "../User.h"
#include "../Bank/AcountManager.h"

// Declaración de la función antes de su uso
void pedirDatosUsuario();


void runApplication() {
    rellenarCuentas();
    iniciarCuentas();
    pedirDatosUsuario();
}