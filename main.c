#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "tdas/list.h"
// #include "tdas/list.c"
// #include "tdas/map.h"

//Prototipo funciones 
void presioneTeclaParaContinuar();
void limpiarPantalla();
void opcionUsuario();
void opcionAdmin();
int login(int);

//Prototipos submenús
void mostrarMenuAdminAlumno();
void mostrarMenuAlumno();

// Función para limpiar la pantalla
void limpiarPantalla() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

//Función presione tecla para Continuar
void presioneTeclaParaContinuar() {
  puts("Presione una tecla para continuar...");
  getchar(); // Consume el '\n' del buffer de entrada
  getchar(); // Espera a que el usuario presione una tecla
}

void mostrarMenuAdminAlumno(){
  puts("===================================");
  puts(" Bienvenido al Programa de Gestión");
  puts("           de Becas");
  puts("====================================");
  puts("1) Alumno");
  puts("2) Administrador");
  puts("3) Salir");
}

void mostrarMenuAlumno(){
  puts("1) Ingresar o Completar perfil");
  puts("2) Postular a Beca");
  puts("3) Seguimiento de Postulación");
  puts("4) Volver");
}

void mostrarMenuAdmin(){
  puts("1) Gestión de Estudiantes");
  puts("2) Revisar solicitudes");
  puts("3) Gestión de Becas");
  puts("4) Gestionar el proceso de selección y aprobación de becas");
  puts("5) Seguimiento de Becas");
  puts("6) Volver");
}


int main() {
  int opcion;
  int resultadoAdmin, n;
  do{
    mostrarMenuAdminAlumno();
    printf("Ingrese su opción: ");
    scanf("%d", &opcion);
    switch(opcion){
      case 1:
        opcionUsuario();
        break;
      case 2:
        resultadoAdmin = login(n);
        if (resultadoAdmin == 1){
          opcionAdmin();
        }
        else{
          limpiarPantalla();
          puts("Contraseña incorrecta");
        }
        break;
      case 3:
        puts("Saliendo del programa...");
        break;
      default:
        puts("Opción no válida, intente de nuevo.");
    } 
  } while(opcion != 3);
  presioneTeclaParaContinuar();
  limpiarPantalla();
  return 0;
}

void opcionUsuario(){
  int opcion;

  do {
    limpiarPantalla();
    mostrarMenuAlumno();
    printf("Ingrese su opción: ");
    scanf("%d", &opcion);
    switch(opcion) {
      case 1:
        // Llamar a la función para ingresar o completar perfil
        break;
      case 2:
        // Llamar a la función para postular a beca
        break;
      case 3:
        // Llamar a la función para seguimiento de postulación
        break;
      case 4:
        puts("Volviendo al menú principal...");
        break;
      default:
        printf("Opción no válida, intente de nuevo.\n");
    }
    presioneTeclaParaContinuar();
  } while(opcion != 4);
  limpiarPantalla();
}

void opcionAdmin(){
  int opcion;
  do {
    limpiarPantalla();
    mostrarMenuAdmin();
    printf("Ingrese su opción: ");
    scanf("%d", &opcion);
    switch(opcion) {
      case 1:
        // Llamar a la función para registro de estudiantes
        break;
      case 2:
        // Llamar a la función para revisar solicitudes
        break;
      case 3:
        // Llamar a la función para gestionar becas
        break;
      case 4:
        // Llamar a la función para administrar el proceso de selección
        break;
      case 5:
        // Llamar a la función de seguimiento de beca
        break;
      case 6:
        puts("Volviendo al menú principal...");
        break;
      default:
        printf("Opción no válida, intente de nuevo.\n");
    }
    presioneTeclaParaContinuar();
  } while(opcion != 6);
  limpiarPantalla();
}

int login(int n){
  char contrasena[20];

  printf("Contraseña: ");
  scanf("%s", contrasena);
  if (strcmp(contrasena, "admin") == 0){
    n = 1;
  } 
  else{
    n = 0;
  }
  return n;
}