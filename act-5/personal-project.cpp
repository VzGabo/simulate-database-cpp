#include <time.h>
#include <windows.h>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <string>
using namespace std;

// ---------------- VARIABLES GLOBALES DEL SISTEMA ----------------
int day, month, year, hour, mins, secs; // Fecha actual
int x, y;                               // Moverme en el eje X y Y
int level;                              // Nivel del administrador
int quantUser = 0;                      // Iterador de usuarios
int users;                              // Cantidad de usuarios
char user[8];                           // Caracter de usuario
char password[10];                      // Contraseña final
int cedula;                             // Cédula para los usuarios que entren al programa
int id;

// ---------------- DECLARANDO FUNCIONES A USAR ----------------

void Box(int x1, int y1, int x2, int y2);
void gotoxy(int x, int y); // Función para moverme en el eje xy
void Performance();        // Portada del juego
void UserAccess();         // Asignación de usuarios
void WindowsAccess();      // Pantalla de validación de usuario y clave
void Time();               // Agregar fecha de ingreso de datos
int CountPersons();        // Personas registradas en la base de datos
int ExistPerson();

// =========== FUNCIONES CRUD ===========

void CreatePerson();  // Almacenar usuarios
void ReadPersons();   // Leer a los usuarios
void ReadOnePerson(); // Ver a un usuario en la base de datos
void UpdatePerson();  // Modificar a los usuarios
void DeletePerson();  // Eliminar a los usuarios
void SetAudit();      // Auditoria al momento de guardar un usuario en la base de datos

// ---------------- ESTRUCTURAS A USAR ----------------

struct Person
{
    int idUser;    // Id único
    char name[50]; // Nombre del usuario
    char tlf[11];  // Teléfono del usuario
    int ci;        // Cédula de identidad del usuario
    int age;       // Edad
} person;
struct Audit
{ // Fecha de registro
    // Fecha en que se agrega los datos
    int addYear;
    int addMonth;
    int addDay;
    int addHour;
    int addMin;
    int addSec;

    // Fecha en que se modifican los datos
    int updYear = 0;
    int updDay = 0;
    int updMonth = 0;
    int updHour = 0;
    int updMin = 0;
    int updSec = 0;

    // Fecha en que se eliminan los datos
    int delYear = 0;
    int delMonth = 0;
    int delDay = 0;
    int delHour = 0;
    int delMin = 0;
    int delSec = 0;
};

Audit *audit = new Audit[50]; // Capacidad máxima de auditoria

struct Access
{
    char user[8];
    char passwordUser[10];
    int cedulaUser;
    int levelUser;

    char updUser[8]; // Usuario quien modifica los datos
    char delUser[8]; // Usuario quien elimina los datos
};

Access *accessUser = new Access[40]; // Creando los 4 niveles de usuario

// ---------------- PROGRAMA FINAL ----------------
// ---------------- PROGRAMA FINAL ----------------
int main()
{
    // Variables del programa
    bool active = true;
    int opc;
    // Presentación del programa
    system("color 80");
    Performance();
    system("cls");
    WindowsAccess();
    x = 50;
    y = 0;
    gotoxy(x, y);

    if (level == 1)
    { // Nivel 1 (USUARIO)
        while (active) {

            system("cls");

            y = 3;
            y = y + 1;
            gotoxy(x, y);

            printf("OPCIONES DISPONIBLES PARA USUARIO NIVEL 1");
            y = y + 2;
            gotoxy(x, y);

            printf("1. Agregar personas a la base de datos");
            y = y + 1;
            gotoxy(x, y);

            printf("2. Ver a las personas en la base de datos");
            y = y + 1;
            gotoxy(x, y);

            printf("3. Ver a una persona en la base de datos");
            y = y + 1;
            gotoxy(x, y);

            printf("4. Salir del programa");
            y = y + 1;
            gotoxy(x, y);

            printf("Tu opci\242n: ");
            scanf("%d", &opc);
            y = y + 1;
            gotoxy(x, y);

            switch (opc)
            {
            case 1:

                CreatePerson();
                break;

            case 2:

                ReadPersons();
                break;

            case 3:

                ReadOnePerson();
                break;

            case 4:

                exit(1);
                break;

            default:

                printf("Opci\242n no disponible en el programa!");
                break;
            }
        }


        }
    }
    else if (level == 2)
    { // Nivel 2 del (ALUMNO)

        while ((opcMenu != 'n') && (opcMenu != 'N'))
        {
            system("cls");

            y = 3;
            y = y + 1;
            gotoxy(x, y);

            printf("OPCIONES DISPONIBLES PARA USUARIO NIVEL 2");
            y = y + 2;
            gotoxy(x, y);

            printf("1. Agregar personas a la base de datos");
            y = y + 1;
            gotoxy(x, y);

            printf("2. Ver a las personas en la base de datos");
            y = y + 1;
            gotoxy(x, y);

            printf("3. Ver a una persona en la base de datos");
            y = y + 1;
            gotoxy(x, y);

            printf("4. Modificar a una persona en la base de datos");
            y = y + 1;
            gotoxy(x, y);

            printf("5. Salir del programa");
            y = y + 1;
            gotoxy(x, y);

            printf("Tu opci\242n: ");
            scanf("%d", &opc);
            y = y + 1;
            gotoxy(x, y);

            switch (opc)
            {
            case 1:

                CreatePerson();
                break;

            case 2:

                ReadPersons();
                break;

            case 3:

                ReadOnePerson();
                break;

            case 4:

                UpdatePerson();
                break;

            case 5:

                exit(1);
                break;

            default:

                printf("Opci\242n no disponible en el programa!");
                break;
            }

            printf("\250Deseas volver al men\243? (s/n): ");
            fflush(stdin);
            scanf("%c", &opcMenu);
        }
    }
    else if (level == 3){ // Nivel 3 del usuario

        while ((opcMenu != 'n') && (opcMenu != 'N'))
        {
            system("cls");

            y = 3;
            y = y + 1;
            gotoxy(x, y);

            printf("OPCIONES DISPONIBLES PARA USUARIO NIVEL 3");
            y = y + 2;
            gotoxy(x, y);

            printf("1. Agregar personas a la base de datos");
            y = y + 1;
            gotoxy(x, y);

            printf("2. Ver a las personas en la base de datos");
            y = y + 1;
            gotoxy(x, y);

            printf("3. Ver a una persona en la base de datos");
            y = y + 1;
            gotoxy(x, y);

            printf("4. Modificar a una persona en la base de datos");
            y = y + 1;
            gotoxy(x, y);

            printf("5. Eliminar a una persona de la base de datos");
            y = y + 1;
            gotoxy(x, y);

            printf("6. Salir del programa");
            y = y + 1;
            gotoxy(x, y);

            printf("Tu opci\242n: ");
            scanf("%d", &opc);
            y = y + 1;
            gotoxy(x, y);

            switch (opc)
            {
            case 1:

                CreatePerson();
                break;

            case 2:

                ReadPersons();
                break;

            case 3:

                ReadOnePerson();
                break;

            case 4:

                UpdatePerson();
                break;

            case 5:

                DeletePerson();
                break;

            case 6:

                exit(1);
                break;

            default:

                printf("Opci\242n no disponible en el programa!");
                break;
            }

            printf("\250Deseas volver al men\243? (s/n): ");
            fflush(stdin);
            scanf("%c", &opcMenu);
        }
    } 
    //else if (level == 4){ // Nivel 4 del usuario

    // }

    // Usuario no encontrado
    else if (level == 0)
    {
        y = y + 2;
        gotoxy(x, y);
        printf("Error en Usuario o Clave ");
        y = y + 1;
        gotoxy(x, y);
        system("pause");
        return 0;
    }
    else
    {
        y = y + 2;
        gotoxy(x, y);
        printf("No est\240 registrado");
        return 0;
    }

    y = y + 1;
    gotoxy(x + 10, y);
    system("cls");

    printf("Cerrando el programa...");
    y = y + 1;
    gotoxy(x, y);
    system("pause");
    return 0;
}

// ---------------- FUNCIONES UTILIZADAS EN EL PROGRAMA ----------------
// ---------------- FUNCIONES UTILIZADAS EN EL PROGRAMA ----------------
void Time() // Hora del sistema
{

    time_t current_time;
    struct tm *local_time;
    time(&current_time);

#if _MSC_VER
    localtime_s(localTM, localTime);
    year = local_time.tm_year + 1900; // Años transcurridos desde 1900
    month = local_time.tm_mon + 1;    // Número del mes (0-11)
    day = local_time.tm_mday;         // Día del mes (1-31)
    hour = local_time.tm_hour;        // Horas desde medianoche (0-23)
    min = local_time.tm_min;          // Minutos pasados de la hora (0-59)
    sec = local_time.tm_sec;          // Segundos pasados del minuto (0-61)
#else
    local_time = localtime(&current_time);
    year = 1900 + local_time->tm_year;
    month = 1 + local_time->tm_mon;
    day = local_time->tm_mday;
    hour = local_time->tm_hour;
    mins = local_time->tm_min;
    secs = local_time->tm_sec;

#endif
}
void Box(int x1, int y1, int x2, int y2) // Caja decorativa
{

    int i;

    // Lineas horizontales
    for (i = x1; i < x2; i++)
    {
        gotoxy(i, y1);
        printf("�"); // linea horizontal superior
        gotoxy(i, y2);
        printf("�"); // linea horizontal inferior
    }

    // Lineas verticales
    for (i = y1; i < y2; i++)
    {
        gotoxy(x1, i);
        printf("*"); // linea vertical izquierda
        gotoxy(x2, i);
        printf("*"); // linea vertical derecha
    }

    gotoxy(x1, y1);
    printf("*");
    gotoxy(x1, y2);
    printf("*");
    gotoxy(x2, y1);
    printf("*");
    gotoxy(x2, y2);
    printf("*");
}
void gotoxy(int x, int y) // Mover me en la pantalla
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
void Performance() // Función de portada
{
    Time();
    // ENCABEZADO
    x = 40;
    y = 0;
    gotoxy(x, y);
    cout << "Rep\243blica Bolivariana de Venezuela" << endl;

    x = 30;
    y = y + 1;
    gotoxy(x, y);
    cout << "Universidad Nacional Experimental de la Gran Caracas" << endl;

    x = 40;
    y = y + 1;
    gotoxy(x, y);
    cout << "Programa: Trayecto I Semetres II" << endl;

    x = 38;
    y = y + 1;
    gotoxy(x, y);
    cout << "Materia: Programaci\242n y Algor\241tmica" << endl;

    y = y + 1;
    gotoxy(x, y);
    cout << "Turno: Vespertino" << endl;

    // TITULO
    x = 35;
    y = y + 8;
    gotoxy(x, y);
    cout << "ALMACENAMIENTO DE USUARIOS EN UNA BASE DE DATOS" << endl;

    // INFORMACIÓN DEL ESTUDIANTE Y PROFESORA
    // Profesora
    x = 5;
    y = y + 8;
    gotoxy(x, y);
    cout << "Profesora: " << endl;
    y = y + 1;
    gotoxy(x, y);
    cout << "Rosario Verd\243 " << endl;

    // Estudiante
    x = 85;
    y = 19;
    gotoxy(x, y);
    cout << "Estudiante: " << endl;
    y = y + 1;
    gotoxy(x, y);
    cout << "Gabriel Gonz\240lez " << endl;

    y = y + 3;
    x = 50;
    gotoxy(x, y);
    printf("Caracas, %2i/%2i/%4i", day, month, year);

    getch();
}
void UserAccess() // Uusuarios con acceso al programa
{                 // CUsuarios con acceso al programa

    users = 4;
    // CREANDO LOS USUARIOS PARA ACCEDER
    // Usuario nivel 1: C, R
    strcpy(accessUser[0].user, "USUARIO");
    strcpy(accessUser[0].passwordUser, "UNO");
    accessUser[0].levelUser = 1;
    accessUser[0].cedulaUser = 79433028;

    // Usuario nivel 2: C, R, U
    strcpy(accessUser[1].user, "ALUMNO");
    strcpy(accessUser[1].passwordUser, "ALUMNO");
    accessUser[1].levelUser = 2;
    accessUser[1].cedulaUser = 32884983;

    // Usuario nivel 3: C, R, U, D
    strcpy(accessUser[2].user, "CLASE");
    strcpy(accessUser[2].passwordUser, "CLASE");
    accessUser[2].levelUser = 3;
    accessUser[2].cedulaUser = 23492847;

    // Usuario nivel 4: C, R, U, D, A
    strcpy(accessUser[3].user, "ADMIN");
    strcpy(accessUser[3].passwordUser, "ADMIN");
    accessUser[3].levelUser = 4;
    accessUser[3].cedulaUser = 32235546;
}
void WindowsAccess()
{                // Darle acceso a los usuarios
    int cont;    // Enmascarar contraseña
    int con = 1; // Contador de claves erroneas
    char c;

    // ACTIVAR DATOS DEL USUARIO
    UserAccess();

    x = 10;
    y = 10;
    level = 0;
    gotoxy(x, y);

    y = y + 2;
    gotoxy(x, y);

    // Entrada del usuario
    printf("Introduce tu usuario: ");
    scanf("%s", user);
    strupr(user);

    // Verifica usuarios
    for (quantUser = 0; quantUser < users; quantUser++)
    {

        if (strcmp(accessUser[quantUser].user, user) == 0)
        {
            // Usuario encontrado
            y = y + 2;
            gotoxy(x, y);
            printf("Introduce la contrase\244a: ");
            fflush(stdin);

            // Entrada de la contraseña con máscara
            cont = 0;
            while (c != 13){

                // ingreso clave mascara
                fflush(stdin);
                c = getch();
                printf("*");
                password[cont] = c;
                cont++;
            }

            password[cont - 1] = '\0';
            strupr(password);

            if ((strcmp(accessUser[quantUser].passwordUser, password) == 0))
            {
                level = accessUser[quantUser].levelUser;
                cedula = accessUser[quantUser].cedulaUser;
                con++;
            }
            else
            {

                do
                {
                    y = y + 2;
                    gotoxy(x, y);

                    printf("Ratifique Clave : ");
                    gotoxy(x + 18, y);
                    fflush(stdin);
                    cont = 0;
                    do
                    {
                        c = getch();
                        printf("*");
                        password[cont] = c;
                        cont++;
                    } while (c != 13); // mientras no sea enter
                    password[cont - 1] = '\0';
                    strupr(password);

                    // Validación de contraseña
                    if (strcmp(accessUser[quantUser].passwordUser, password) != 0)
                    {
                        level = 0;
                    }
                    else
                    {
                        con = 4;
                        level = accessUser[quantUser].levelUser;
                    }
                    fflush(stdin);
                    con++;
                } while (con < 3);
            } // else
        }
    }
    // Si no se encontró el usuario o contraseña incorrecta
    if (level == 0)
    {

        y = y + 2;
        gotoxy(x, y);
        printf("Error en usuario o clave ");
        y = y + 1;
        gotoxy(x, y);
    }
}
int CountPersons()
{ // Contar los usuarios en la base de datos

    FILE *file;
    file = fopen("data_base.txt", "r");

    char line[1024];
    int count = 0;
    fflush(stdin);

    if (file == NULL)
    {

        printf("ERROR AL MOMENTO DE ABRIR EL ARCHIVO");
        exit(1);
    }
    else
    {

        while (fgets(line, sizeof(line), file))
        {
            // Verificar si la línea no está vacía
            if (line[0] != '\n')
            {
                count++;
            }
        }
    }

    fclose(file);
    return count;
}
int ExistPerson()
{

    char opcUpdate;
    int flyer = 0; // 0: No está el usuario. 1: Está el usuario a modificar
    int idOne = 0;

    y = 3;
    x = 10;
    system("cls");

    FILE *file;
    file = fopen("data_base.txt", "r");

    if (file == NULL)
    {

        y = y + 2;
        gotoxy(x, y);
        printf("Error de apertura en el archivo o no lo has creado.");
        y = y + 1;
        gotoxy(x, y);
        system("pause");
    }
    else
    {

        Box(2, 2, 78, 25);

        y = y + 2;
        gotoxy(x, y);

        printf("ID del usuario a modificar: ");
        scanf("%i", &idOne);
        fflush(stdin);

        fseek(file, 0, 0);
        while (feof(file) == 0)
        {

            // Leer la base de datos para pasarlo al temporal
            fscanf(file, "%5i %12s %10i %11s %2d %4d %2d %2d %2i %2i %2i %4d %2d %2d %2i %2i %2i %4d %2d %2d %2i %2i %2i %8s %10i \n", &person.idUser, person.name, &person.ci, person.tlf, &person.age, &audit->addYear, &audit->addMonth, &audit->addDay, &audit->addHour, &audit->addMin, &audit->addSec, &audit->updYear, &audit->updMonth, &audit->updDay, &audit->updHour, &audit->updMin, &audit->updSec, &audit->delYear, &audit->delMonth, &audit->delDay, &audit->delHour, &audit->delMin, &audit->delSec, user, &cedula);

            if (person.idUser == idOne)
            {

                system("cls");
                flyer = 1;
            }
        }
    }

    if (fclose(file) != 0)
    {
        printf("Problemas para cerrar el archivo");
    }
    else
    {
        fclose(file);
    }

    return flyer;
}

// ============================ FUNCIONES CRUD INICIALIZADAS ============================
void CreatePerson()
{ // Almacenar a las personas en la base de datos

    char opcCreate;
    y = 10;
    x = 10;

    system("cls");
    gotoxy(x, y);
    y = y + 2;
    FILE *file;

    file = fopen("data_base.txt", "a+");
    if (file == NULL)
    { // NULL   archivo NO  fue  abierto con �xito
        printf("Error de apertura del archivo Acceso. ");
        y = y + 2;
        gotoxy(x, y);

        system("pause");

        exit(1);
    }
    else
    {
        system("cls");
        y = y + 2;
        gotoxy(x, y);

        printf("\250Desea ingresar datos de los usuarios? (s/n): ");
        fflush(stdin); // vacia el bufer de teclado
        scanf("%c", &opcCreate);

        do
        {
            Time();
            system("cls");
            Box(2, 2, 78, 24);
            y = 5;
            x = 10;

            id = CountPersons() + 1; // Id de la persona
            gotoxy(x + 10, y);
            printf("DATOS DE LOS USUARIOS");
            y = y + 2;
            gotoxy(x, y);

            person.idUser = id;
            printf("El id es: %d", person.idUser);
            fflush(stdin); // vacia el bufer de teclado
            y = y + 1;
            gotoxy(x, y);

            // Pidiendo los datos del usuario a almacenar en la base de datos
            // NOMBRE
            printf("Ingresa el nombre (20 letras m\240ximo): ");
            scanf("%s", person.name);
            strupr(person.name);
            y = y + 1;
            gotoxy(x, y);

            // CÉDULA
            printf("Ingresa la c\202dula de Identidad: ");
            fflush(stdin); // vacia el bufer de teclado
            scanf("%i", &person.ci);
            y = y + 1;
            gotoxy(x, y);

            // NÚMERO DE TELÉFONO
            printf("Ingresa el n\243mero telef\242nico:  ");
            scanf("%s", person.tlf);
            y = y + 1;
            gotoxy(x, y);

            // EDAD
            printf("Ingresa tu edad: ");
            scanf("%d", &person.age);

            // Almacenando los datos en la base de datos
            audit->addYear = year;
            audit->addMonth = month;
            audit->addDay = day;
            audit->addHour = hour;
            audit->addMin = mins;
            audit->addSec = secs;

            gotoxy(x, y);

            fprintf(file, "%5i %12s %10i %11s %2d %4d %2d %2d %2i %2i %2i %4d %2d %2d %2i %2i %2i %4d %2d %2d %2i %2i %2i %8s %10i \n", person.idUser, person.name, person.ci, person.tlf, person.age, audit->addYear, audit->addMonth, audit->addDay, audit->addHour, audit->addMin, audit->addSec, audit->updYear, audit->updMonth, audit->updDay, audit->updHour, audit->updMin, audit->updSec, audit->delYear, audit->delMonth, audit->delDay, audit->delHour, audit->delMin, audit->delSec, user, cedula);

            y = y + 3;
            gotoxy(x, y);

            printf("LOS DATOS FUERON ALMACENADOS EXITOSAMENTE");
            y = y + 1;
            gotoxy(x, y);

            printf("\250Deseas agregar otro usuario? (s/n): ");
            fflush(stdin); // vacia el bufer de teclado
            scanf("%c", &opcCreate);

        } while ((opcCreate == 's') || (opcCreate == 'S'));

        if ((opcCreate == 'n') || (opcCreate == 'N'))
        { // Selecciono (N o n) se cierra el archivo  personal.txt
            y = y + 1;
            gotoxy(x, y);

            if (fclose(file) != 0)
            {
                printf("Problemas al cerrar el fichero");
            } else {
                fclose(file);
            }
        }
        else
        {

            if (fclose(file) != 0)
            {
                printf("Problemas al cerrar el fichero");
            }
            else
            {
                fclose(file);
            }
        }
    }

    y = y + 1;
    gotoxy(x, y);
    if (fclose(file) != 0)
    {
        printf("Problemas al cerrar el fichero");
    }
    else
    {
        fclose(file);
    }
    y = y + 1;
    gotoxy(x, y);
}
void ReadPersons()
{ // Leer a los usuarios almacenados en la base de datos

    char opcRead;

    y = 5;
    x = 10;
    gotoxy(x, y);
    system("cls");

    FILE *file;
    file = fopen("data_base.txt", "r");

    if (file == NULL)
    { // Si el archivo no abre

        y = y + 2;
        gotoxy(x, y);

        printf("Error en la apertura del archivo o no has creado el archivo");
        y = y + 1;
        gotoxy(x, y);
        system("pause");
    }
    else
    { // si el archivo abre, leer la información

        fseek(file, 0, 0);
        if (CountPersons != 0)
        {

            while (feof(file) == 0)
            {

                fscanf(file, "%5i %12s %10i %11s %2d %4d %2d %2d %2i %2i %2i %4d %2d %2d %2i %2i %2i %4d %2d %2d %2i %2i %2i %8s %10i \n", &person.idUser, &person.name, &person.ci, person.tlf, &person.age, &audit->addYear, &audit->addMonth, &audit->addDay, &audit->addHour, &audit->addMin, &audit->addSec, &audit->updYear, &audit->updMonth, &audit->updDay, &audit->updHour, &audit->updMin, &audit->updSec, &audit->delYear, &audit->delMonth, &audit->delDay, &audit->delHour, &audit->delMin, &audit->delSec, user, &cedula);

                Box(2, 2, 78, 24);
                gotoxy(x + 10, y);

                printf("DATOS EN LA BASE DE DATOS");
                y = y + 3;
                gotoxy(x, y);

                printf("ID: %i", person.idUser);
                y = y + 1;
                gotoxy(x, y);

                printf("Nombre: %s", person.name);
                y = y + 1;
                gotoxy(x, y);

                printf("C\202dula: %i", person.ci);
                y = y + 1;
                gotoxy(x, y);

                printf("Tel\202fono: %s", person.tlf);
                y = y + 1;
                gotoxy(x, y);

                printf("Edad: %d", person.age);
                y = y + 1;
                gotoxy(x, y);

                printf("Fecha de registro: %d/%d/%d %i:%i:%i", audit->addYear, audit->addMonth, audit->addDay, audit->addHour, audit->addMin, audit->addSec);
                y = y + 1;
                gotoxy(x, y);
                printf("Fecha de modificaci\242n: %d/%d/%d %i:%i:%i", audit->updYear, audit->updMonth, audit->updDay, audit->updHour, audit->updMin, audit->updSec);
                y = y + 1;
                gotoxy(x, y);
                printf("Fecha de eliminaci\242n: %d/%d/%d %i:%i:%i", audit->delYear, audit->delMonth, audit->delDay, audit->delHour, audit->delMin, audit->delSec);
                y = y + 5;
                gotoxy(x, y);
                printf("**************************************");
                y = y + 1;
                gotoxy(x, y);

                system("pause");

                if (feof(file) != 0)
                { // final de archivo

                    y = y + 1;
                    gotoxy(x, y);

                    printf("Fin");
                    y = y + 1;
                    gotoxy(x, y);
                }
                else
                {
                    system("cls");
                    y = 5;
                    x = 10;

                    Box(2, 2, 78, 24);
                }
            }
        }
        else
        {
            y = y + 2;

            printf("No hay usuarios registrados");
            y = y + 2;
            gotoxy(x, y);
            system("pause");
        }
    }

    if (fclose(file) != 0)
    { // cierra el archivo personal.txt
        printf("Problemas al cerrar el fichero");
    }
    else
    {
        fclose(file);
    }

    y = y + 1;
    gotoxy(x, y);
}
void ReadOnePerson()
{ // Buscar a una persona en la base de datos

    char opcReadOne;
    int flyer = 0;
    int idOne;

    y = 3;
    x = 10;
    system("cls");
    fflush(stdin);

    FILE *file;

    file = fopen("data_base.txt", "r");

    if (file == NULL)
    { // El archivo no existe

        y = y + 2;
        gotoxy(x, y);

        printf("Error en la apertura del archivo o no has creado el archivo");
        y = y + 1;
        gotoxy(x, y);
        system("pause");
    }
    else
    {

        Box(2, 2, 78, 25);
        y = y + 2;
        gotoxy(x, y);

        // Consultar el ID a buscar
        printf("Dime el ID que est\240s buscando: ");
        scanf("%i", &idOne);
        fflush(stdin);

        // Leyendo el TXT
        fseek(file, 0, 0);
        if (CountPersons != 0)
        {

            while (feof(file) == 0)
            {

                fscanf(file, "%5i %12s %10i %11s %2d %4d %2d %2d %2i %2i %2i %4d %2d %2d %2i %2i %2i %4d %2d %2d %2i %2i %2i %8s %10i \n", &person.idUser, &person.name, &person.ci, person.tlf, &person.age, &audit->addYear, &audit->addMonth, &audit->addDay, &audit->addHour, &audit->addMin, &audit->addSec, &audit->updYear, &audit->updMonth, &audit->updDay, &audit->updHour, &audit->updMin, &audit->updSec, &audit->delYear, &audit->delMonth, &audit->delDay, &audit->delHour, &audit->delMin, &audit->delSec, user, &cedula);

                if (person.idUser == idOne)
                {
                    system("cls");
                    Box(2, 2, 78, 25);
                    y = 3;
                    x = 10;
                    flyer = 1;
                    gotoxy(x, y);

                    printf("Usuario encontrado!. ID: %i", person.idUser);
                    gotoxy(x + 10, y);
                    y = y + 2;
                    gotoxy(x, y);

                    printf("CONSULTA DE DATOS");
                    y = y + 2;
                    gotoxy(x, y);

                    printf("Nombre: %s", person.name);
                    y = y + 1;
                    gotoxy(x, y);

                    printf("C\202dula: %i", person.ci);
                    y = y + 1;
                    gotoxy(x, y);

                    printf("Tel\202fono: %s", person.tlf);
                    y = y + 1;
                    gotoxy(x, y);

                    printf("Edad: %d", person.age);
                    y = y + 1;
                    gotoxy(x, y);

                    printf("Fecha de registro: %d/%d/%d %i:%i:%i", audit->addYear, audit->addMonth, audit->addDay, audit->addHour, audit->addMin, audit->addSec);
                    y = y + 1;
                    gotoxy(x, y);
                    printf("Fecha de modificaci\242n: %d/%d/%d %i:%i:%i", audit->updYear, audit->updMonth, audit->updDay, audit->updHour, audit->updMin, audit->updSec);
                    y = y + 1;
                    gotoxy(x, y);
                    printf("Fecha de eliminaci\242n: %d/%d/%d %i:%i:%i", audit->delYear, audit->delMonth, audit->delDay, audit->delHour, audit->delMin, audit->delSec);
                    y = y + 5;
                    gotoxy(x, y);

                    printf("***********************************");
                    y = y + 1;
                    gotoxy(x, y);

                    system("pause");
                    if (flyer == 1)
                    {
                        system("cls");
                        y = 3;
                        x = 10;
                        Box(2, 2, 78, 25);
                    } else {
                        y = y + 1;
                        gotoxy(x, y);
                        printf("La persona que est\240s buscando, no se encuentra en la base de datos");
                    }
                }
            }
        }
        else
        {

            y = y + 2;
            gotoxy(x, y);
            printf("No hay personas en la base de datos");
        }
    }

    if ((feof(file) == 0) && flyer == 0)
    {
        y = y + 2;
        gotoxy(x, y);
        system("cls");

        printf("El usuario no se encuentra en la base de datos");
        y = y + 1;
        gotoxy(x, y);
        system("pause");
    }

    if (fclose(file) != 0)
    {
        printf("Error al cerrar el archivo");
        y = y + 1;
        gotoxy(x, y);
    }
    else
    {
        fclose(file);
    }

    y = y + 1;
    gotoxy(x, y);
}
void UpdatePerson()
{

    char opc2;
    int flyer = 0, cedulaR;
    int idOne = 0;

    FILE *file, *file2;
    file = fopen("data_base.txt", "r");
    if (file == NULL)
    {
        // En caso de no tener el archivo
        y = y + 2;
        gotoxy(x, y);
        printf("Error en la apertura del archivo.");
        y = y + 1;
        gotoxy(x, y);
        printf("Verificar si cre\242 el archivo.");
        y = y + 1;
        gotoxy(x, y);
    }
    else
    {
        // Crear el archivo temporal

        file2 = fopen("temporal.txt", "w");
        // En caso de no tener el archivo
        if (file2 == NULL)
        {
            y = y + 2;
            gotoxy(x, y);
            printf("Error en la apertura del archivo.");
            y = y + 1;
            gotoxy(x, y);
            printf("Verificar si creó el archivo.");
        }
        else
        {

            // Pasando información al archivo temporal
            system("cls");
            y = 3;
            x = 10;
            gotoxy(x, y);
            Box(2, 2, 78, 25);

            printf("MODIFICACI\326N DE DATOS");
            flyer = ExistPerson();

            // Verificar existencia del usuario
            if (flyer != 1)
            {
                y = y + 2;
                gotoxy(x, y);

                printf("La persona no existe");
                y = y + 1;
                gotoxy(x, y);
                system("pause");

                // Cerrar el archivo 1
                if (fclose(file) != 0)
                {
                    printf("Problemas para cerrar el archivo");
                }
                else
                {
                    fclose(file);
                }

                // Cerrar el archivo 2
                if (fclose(file2) != 0)
                {
                    printf("Problemas para cerrar el archivo temporal");
                }
                else
                {
                    fclose(file2);
                }
            }
            else
            { // En caso de que la persona exista
                system("cls");

                fseek(file, 0, 0);
                while (feof(file) == 0)
                {

                    // Leer el archivo 1 para pasarlo al archivo temporal
                    fscanf(file, "%5i %12s %10i %11s %2d %4d %2d %2d %2i %2i %2i %4d %2d %2d %2i %2i %2i %4d %2d %2d %2i %2i %2i %8s %10i \n", &person.idUser, person.name, &person.ci, person.tlf, &person.age, &audit->addYear, &audit->addMonth, &audit->addDay, &audit->addHour, &audit->addMin, &audit->addSec, &audit->updYear, &audit->updMonth, &audit->updDay, &audit->updHour, &audit->updMin, &audit->updSec, &audit->delYear, &audit->delMonth, &audit->delDay, &audit->delHour, &audit->delMin, &audit->delSec, user, &cedulaR);

                    Box(2, 2, 78, 25);
                    y = 3;
                    x = 10;
                    gotoxy(x, y);

                    printf("Validaci\242n del id: ");
                    scanf("%i", &idOne);

                    // Modificando los datos del id igual al que se busca
                    if (person.idUser == idOne)
                    {

                        y = y + 2;
                        gotoxy(x, y);
                        printf("Modificaci\242n de datos");
                        y = y + 2;
                        gotoxy(x, y);

                        // Modificar el nombre en caso de que seleccione 'si'
                        printf("\250Desea modificar el nombre? (s/n): ");
                        fflush(stdin);
                        scanf("%c", &opc2);

                        if ((opc2 == 's') || (opc2 == 'S'))
                        {
                            y = y + 1;
                            gotoxy(x, y);

                            printf("Nombre (12 letras): ");
                            fflush(stdin);
                            scanf("%s", &person.name);
                            strupr(person.name);
                        }

                        // Modificando la cédula
                        y = y + 2;
                        gotoxy(x, y);

                        printf("\250Desea modificar la c\202dula? (s/n): ");
                        fflush(stdin);
                        scanf("%c", &opc2);

                        if ((opc2 == 's') || (opc2 == 'S'))
                        {
                            y = y + 1;
                            gotoxy(x, y);
                            printf("C\202dula: ");
                            fflush(stdin);
                            scanf("%i", &person.ci);
                        }
                        
                        // Modificando el teléfono
                        y = y + 2;
                        gotoxy(x, y);

                        printf("\250Desea modificar el tel\202fono? (s/n): ");
                        fflush(stdin);
                        scanf("%c", &opc2);

                        if ((opc2 == 's') || (opc2 == 'S'))
                        {
                            y = y + 1;
                            gotoxy(x, y);
                            
                            printf("Tel\202fono: ");
                            fflush(stdin);
                            scanf("%s", &person.tlf);
                        }

                        y = y + 2;
                        gotoxy(x, y);

                        printf("\250Desea modificar la edad? (s/n): ");
                        fflush(stdin);
                        scanf("%c", &opc2);

                        if ((opc2 == 's') || (opc2 == 'S'))
                        {
                            y = y + 1;
                            gotoxy(x, y);
                            
                            printf("Edad: ");
                            fflush(stdin);
                            scanf("%i", &person.age);
                        }
                    } else {

                        // Colocar los otros datos no modificados en el nuevo archivo
                        fprintf(file2, "%5i %12s %10i %11s %2d %4d %2d %2d %2i %2i %2i %4d %2d %2d %2i %2i %2i %4d %2d %2d %2i %2i %2i %8s %10i \n", person.idUser, person.name, person.ci, person.tlf, person.age, audit->addYear, audit->addMonth, audit->addDay, audit->addHour, audit->addMin, audit->addSec, audit->updYear, audit->updMonth, audit->updDay, audit->updHour, audit->updMin, audit->updSec, audit->delYear, audit->delMonth, audit->delDay, audit->delHour, audit->delMin, audit->delSec, user, cedulaR);
                    }

                    flyer = 1;
                }

                // Obteniendo los datos para la modificación
                strcpy(accessUser->updUser, accessUser->user);
                accessUser->cedulaUser = cedula;
                Time();
                audit->updYear = year;
                audit->updMonth = month;
                audit->updDay = day;
                audit->updHour = hour;
                audit->updMin = mins;
                audit->updSec = secs;

                // Insertando los datos a temporal.txt
                fprintf(file2, "%5i %12s %10i %11s %2d %4d %2d %2d %2i %2i %2i %4d %2d %2d %2i %2i %2i %4d %2d %2d %2i %2i %2i %8s %10i \n", person.idUser, person.name, person.ci, person.tlf, person.age, audit->addYear, audit->addMonth, audit->addDay, audit->addHour, audit->addMin, audit->addSec, audit->updYear, audit->updMonth, audit->updDay, audit->updHour, audit->updMin, audit->updSec, audit->delYear, audit->delMonth, audit->delDay, audit->delHour, audit->delMin, audit->delSec, accessUser->updUser, cedula);
            }

            system("cls");
            y = y + 2;
            gotoxy(x, y);

            // Cerrar primer archivo
            if (fclose(file) != 0)
            {
                printf("Problemas al cerrar el data_base.txt");
            }
            else
            {
                fclose(file);
            }
            // Cerrar segundo archivo
            if (fclose(file2) != 0)
            {
                printf("Problemas al cerrar el archivo temporal");
            }
            else
            {
                fclose(file2);
            }
        }

        // Si la bandera es igual a 1
        if (flyer == 1)
        {
            system("cls");
            x = 18;
            y = y + 2;
            gotoxy(x, y);

            // Si se encontró al usuario eliminamos el archivo
            if (remove("data_base.txt") == 0)
            {
                printf("El archivo se elimin\242 con \202xito");
                y = y + 1;
                gotoxy(x, y);
                system("pause");
            }
            else
            {
                printf("No se logr\242 eliminar el archivo");
            }

            y = y + 2;
            gotoxy(x, y);

            // Si se encontró al usuario modificar el archivo temporal
            if (rename("temporal.txt", "data_base.txt") == 0)
            {
                printf("El archivo se modific\242 con \202xito");
                y = y + 1;
                gotoxy(x, y);
                system("pause");
            }
            else
            {
                printf("No se pudo renombrar el archivo");
                y = y + 1;
                system("pause");
            }

            return;
        }
    }
}
void DeletePerson(){

    char opc2;
    int idOne, flyer;

    FILE *file, *fileHistory, *fileTemp;
    file = fopen("data_base.txt", "r");

    if (file == NULL){
        // En caso de no tener el archivo
        y = y + 2;
        gotoxy(x, y);
        printf("Error en la apertura del archivo.");
        y = y + 1;
        gotoxy(x, y);
        printf("Verificar si cre\242 el archivo.");
        y = y + 1;
        gotoxy(x, y);
    } else {

        fileTemp = fopen("temporal.txt", "w");

        if (fileTemp == NULL){

            y = y + 2;
            gotoxy(x, y);
            printf("Error en la apertura del archivo.");
            y = y + 1;
            gotoxy(x, y);
            printf("Verificar si cre\242 el archivo.");
            y = y + 1;
            gotoxy(x, y);
        } else {

            fileHistory = fopen("history.txt", "a+");

            if (fileHistory == NULL){
                y = y + 2;
                gotoxy(x, y);

                printf("Error en la apertura del archivo.");
                y = y + 1;
                gotoxy(x, y);

                printf("Verificar si cre\242 el archivo.");
                y = y + 1;

                gotoxy(x, y);
                
                // Cerrar los dos archivos en caso de que haya problemas con el histórico
                if (fclose(file) != 0){
                    printf("Problemas al cerrar el archivo");

                    if (fclose(fileTemp) != 0){

                        printf("Problemas al cerrar el archivo");
                        exit(1);
                    }
                }

            } else {

                system("cls");
                Box(2, 2, 78, 25);

                y = 3;
                x = 10;
                y = y + 2;
                gotoxy(x, y);

                printf("Eliminaci\242n de datos");
                flyer = ExistPerson();

                if (flyer != 1){
                    // Cerrar todo en caso de que la persona no exista
                    y = y + 2;
                    gotoxy(x, y);
                    
                    printf("No existe la persona");

                    y = y + 2;
                    gotoxy(x, y);

                    system("pause");

                    gotoxy(x,y);
                    system("pause");

                    if (fclose(file)!= 0){
                        printf("Problemas al cerrar el fichero\n");
                    } else {
                        fclose(file);
                    }

                    y = y + 2;
                    gotoxy(x, y);

                    if (fclose(fileTemp)!= 0){
                        printf("Problemas al cerrar el fichero\n" );
                    } else {
                        fclose(fileTemp);
                    }

                    y = y + 2;
                    gotoxy(x, y);


                    if (fclose(fileHistory)!= 0){
                    printf("Problemas al cerrar el fichero\n" );
                    } else {
                        fclose(fileHistory);
                    }
                    
                    y = y + 2;
                    gotoxy(x, y);
                    return;

                } else {

                    system("cls");

                    y = 3;
                    x = 10;
                    y = y + 2;

                    gotoxy(x, y);

                    

                    fseek(file, 0, 0);
                    while (feof(file) == 0){

                        fscanf(file, "%5i %12s %10i %11s %2d %4d %2d %2d %2i %2i %2i %4d %2d %2d %2i %2i %2i %4d %2d %2d %2i %2i %2i %8s %10i \n", &person.idUser, &person.name, &person.ci, person.tlf, &person.age, &audit->addYear, &audit->addMonth, &audit->addDay, &audit->addHour, &audit->addMin, &audit->addSec, &audit->updYear, &audit->updMonth, &audit->updDay, &audit->updHour, &audit->updMin, &audit->updSec, &audit->delYear, &audit->delMonth, &audit->delDay, &audit->delHour, &audit->delMin, &audit->delSec, user, &cedula);
                        
                        printf("Id a eliminar: ");
                        fflush(stdin);
                        scanf("%i", &idOne);

                        y = y + 2;
                        gotoxy(x, y);

                        if (person.idUser == idOne){

                            printf("\250Deseas eliminar al usuario?(s/n): ");
                            fflush(stdin);
                            scanf("%c", &opc2);

                            // Guardar en el historial al eliminado
                            if ((opc2 == 's') || (opc2 == 'S')){
                                
                                Time();
                                audit->delYear = year;
                                audit->delMonth = month;
                                audit->delDay = day;
                                audit->delHour = hour;
                                audit->delMin = mins;
                                audit->delSec = secs;

                                fprintf(fileHistory, "%5i %12s %10i %11s %2d %4d %2d %2d %2i %2i %2i %4d %2d %2d %2i %2i %2i %4d %2d %2d %2i %2i %2i %8s %10i \n", person.idUser, person.name, person.ci, person.tlf, person.age, audit->addYear, audit->addMonth, audit->addDay, audit->addHour, audit->addMin, audit->addSec, audit->updYear, audit->updMonth, audit->updDay, audit->updHour, audit->updMin, audit->updSec, audit->delYear, audit->delMonth, audit->delDay, audit->delHour, audit->delMin, audit->delSec, user, cedula);

                            } else {
                                
                                fprintf(fileTemp, "%5i %12s %10i %11s %2d %4d %2d %2d %2i %2i %2i %4d %2d %2d %2i %2i %2i %4d %2d %2d %2i %2i %2i %8s %10i \n", person.idUser, person.name, person.ci, person.tlf, person.age, audit->addYear, audit->addMonth, audit->addDay, audit->addHour, audit->addMin, audit->addSec, audit->updYear, audit->updMonth, audit->updDay, audit->updHour, audit->updMin, audit->updSec, audit->delYear, audit->delMonth, audit->delDay, audit->delHour, audit->delMin, audit->delSec, user, cedula);
                            }
                            
                            
                        // Guardar en el temporal el resto que no está eliminado
                        } else {

                            fprintf(fileTemp, "%5i %12s %10i %11s %2d %4d %2d %2d %2i %2i %2i %4d %2d %2d %2i %2i %2i %4d %2d %2d %2i %2i %2i %8s %10i \n", person.idUser, person.name, person.ci, person.tlf, person.age, audit->addYear, audit->addMonth, audit->addDay, audit->addHour, audit->addMin, audit->addSec, audit->updYear, audit->updMonth, audit->updDay, audit->updHour, audit->updMin, audit->updSec, audit->delYear, audit->delMonth, audit->delDay, audit->delHour, audit->delMin, audit->delSec, user, cedula);;
                        }
                    }

                    // Cerrar archivos luego de pasar datos
                    if (fclose(file) != 0){

                            printf("Problemas al cerrar la base de datos\n");
                    } else {
                        fclose(file);
                    }

                    if (fclose(fileTemp)!= 0){

                        printf("Problemas al cerrar el temporal\n");
                    } else {
                        fclose(fileTemp);
                    }

                    if (fclose(fileHistory)!= 0){
                        printf("Problemas al cerrar el Hist\242rico\n");
                    }
                    else {
                        fclose(fileHistory);
                    }

                    if (flyer == 1) {

                        if (remove("data_base.txt") == 0){

                            y = y + 2;
                            gotoxy(x, y);
                            printf("El archivo fue eliminado exitosamente");

                        } else {

                            y = y + 2;
                            gotoxy(x, y);

                            printf("No se pudo eliminar el archivo");
                        }

                        if (rename("temporal.txt", "data_base.txt") == 0) {

                            y = y + 2;
                            gotoxy(x, y);
                            printf("El archivo se renombr\242 exitosamente");

                        } else {

                            y = y + 2;
                            gotoxy(x, y);
                            printf("El archivo no se pudo renombrar");
                        }
                    }

                }


                y= y + 1;
                gotoxy(x,y);

                system("pause");
                return;
            }
        }
    }
}