#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <postgresql/libpq-fe.h>
#define ANSI_COLOR_RED "\x1b[31m"   // color rojo
#define ANSI_COLOR_GREEN "\x1b[32m" // color verde
#define ANSI_COLOR_RESET "\x1b[0m"  // resetear color
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
int consulta_rapida_enteros();

void hacer_select();

char *pedir_cadena();
int pedir_entero();
char *pedir_fecha();
double pedir_decimal();
int pedir_menu();
int validar_entero();
char *validar_cadena();
char *validar_fecha();
double validar_decimal();
int pedir_dos_opciones();
int pedir_tres_opciones();
int pedir_unidad_medida();

char *menu_principal();

char *menu_pacientes();
void alta_pacientes();
void buscar_pacientes();
void imprimir_pacientes();

char *menu_laboratoristas();
void alta_laboratoristas();
void buscar_laboratoristas();
void despedir_laboratoristas();

char *menu_analisis();
void solicitar_analisis();
void realizar_analisis();
void entregar_analisis();
void buscar_analisis();
void consultas_analisis();
void agregar_atributos_analisis();
void agregar_nuevo_analisis();

char *menu_materiales();
void alta_materiales();
void baja_materiales();

char *menu_reactivos();
void alta_reactivos();
void baja_reactivos();

char *menu_reportes();
PGconn *conn, *conn2, *conn3;
PGresult *res;
PGresult *resultado;

int tamano_maloc = 50;

int main(int argc, char *argv[])
{
    int opc, opc_paciente, opc_laboratorista, opc_analisis, opc_materiales, opc_reactivos, opc_reportes;

    do
    {
        opc = pedir_menu(1);
        switch (opc)
        {
        case 1:
            system("clear");
            do
            {
                opc_paciente = pedir_menu(2);
                switch (opc_paciente)
                {
                case 1:
                    system("clear");
                    alta_pacientes();
                    break;
                case 2:
                    system("clear");
                    buscar_pacientes();
                    break;
                case 3:
                    system("clear");
                    break;
                default:
                    system("clear");
                    printf(ANSI_COLOR_RED "Opcion no valida, intente de nuevo\n\n" ANSI_COLOR_RESET);
                    break;
                }
            } while (opc_paciente != 3);
            break;

        case 2:
            system("clear");
            do
            {
                opc_laboratorista = pedir_menu(3);
                switch (opc_laboratorista)
                {
                case 1:
                    system("clear");
                    alta_laboratoristas();
                    break;
                case 2:
                    system("clear");
                    buscar_laboratoristas();
                    break;
                case 3:
                    system("clear");
                    despedir_laboratoristas();
                    break;
                case 4:
                    system("clear");
                    break;
                default:
                    system("clear");
                    printf(ANSI_COLOR_RED "Opcion no valida, intente de nuevo\n\n" ANSI_COLOR_RESET);
                    break;
                }
            } while (opc_laboratorista != 4);
            break;

        case 3:
            system("clear");
            do
            {
                opc_analisis = pedir_menu(4);
                switch (opc_analisis)
                {
                case 1:
                    system("clear");
                    solicitar_analisis();
                    break;
                case 2:
                    system("clear");
                    realizar_analisis();
                    break;
                case 3:
                    system("clear");
                    entregar_analisis();
                    break;
                case 4:
                    system("clear");
                    buscar_analisis();
                    break;
                case 5:
                    system("clear");
                    consultas_analisis();
                    break;
                case 6:
                    system("clear");
                    agregar_atributos_analisis();
                    break;
                case 7:
                    system("clear");
                    agregar_nuevo_analisis();
                    break;
                case 8:
                    system("clear");
                    break;
                default:
                    system("clear");
                    printf(ANSI_COLOR_RED "Opcion no valida, intente de nuevo\n\n" ANSI_COLOR_RESET);
                    break;
                }
            } while (opc_analisis != 8);
            break;

        case 4:
            system("clear");
            do
            {
                opc_materiales = pedir_menu(5);
                switch (opc_materiales)
                {
                case 1:
                    system("clear");
                    alta_materiales();
                    break;
                case 2:
                    system("clear");
                    baja_materiales();
                    break;
                case 3:
                    system("clear");
                    break;
                default:
                    system("clear");
                    printf(ANSI_COLOR_RED "Opcion no valida, intente de nuevo\n\n" ANSI_COLOR_RESET);
                    break;
                }
            } while (opc_materiales != 3);
            break;

        case 5:
            system("clear");
            do
            {
                opc_reactivos = pedir_menu(6);
                switch (opc_reactivos)
                {
                case 1:
                    system("clear");
                    alta_reactivos();
                    break;
                case 2:
                    system("clear");
                    baja_reactivos();
                    break;
                case 3:
                    system("clear");
                    break;
                default:
                    system("clear");
                    printf(ANSI_COLOR_RED "Opcion no valida, intente de nuevo\n\n" ANSI_COLOR_RESET);
                    break;
                }
            } while (opc_reactivos != 3);
            break;

        case 6:
            system("clear");
            menu_reportes();
            break;

        case 7:
            system("clear");
            break;

        default:
            system("clear");
            printf(ANSI_COLOR_RED "Opcion no valida, intente de nuevo\n\n" ANSI_COLOR_RESET);
            break;
        }

    } while (opc != 7);

    return 0;
}

int pedir_unidad_medida()
{
    int opc_unidad_medida;

    int n_unidades = consulta_rapida_enteros("select count(num_unidad) from unidad_medida");

    int folios[n_unidades];
    int salir;

    do
    {
        conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1");
        printf("\n\tUNIDADES DE MEDIDA\n");
        //--------------------------------------------------------------------Pedir unidad de medida
        if (PQstatus(conn) != CONNECTION_BAD)
        {
            res = PQexec(conn, "select num_unidad, nom_unidad from unidad_medida;");
            if (res != NULL && PQntuples(res) != 0)
            {
                for (int i = 0; i < PQntuples(res); i++)
                {
                    folios[i] = atoi(PQgetvalue(res, i, 0));
                    printf("[%d] %s\n", i + 1, PQgetvalue(res, i, 1)); //imprime todos las unidades
                }
            }
            PQclear(res);
        }
        //--------------------------------------------------------------------Fin pedir unidad de medida
        opc_unidad_medida = pedir_entero("UNIDAD DE MEDIDA");
        if (opc_unidad_medida > 0 && opc_unidad_medida <= n_unidades)
        {
            salir = 1; //SI SALIR VALE UNO SALE DEL CICLO
        }
        else
        {
            salir = 0;
            printf(ANSI_COLOR_RED "\nEl valor ingresado no corresponde a ninguna unidad de medida\n" ANSI_COLOR_RESET);
        }

        PQfinish(conn);

    } while (salir != 1);

    opc_unidad_medida = folios[opc_unidad_medida - 1]; //FOLIOS GUARDA LOS NUM_UNIDAD EN ORDEN, ASI QUE SI QUIERO LA SEGUNDA UNIDAD DEVOLVERÉ EL FOLIO[2-1] OSEA EL SEGUNDO FOLIO EN MOSTRARSE

    return opc_unidad_medida;
}

double pedir_decimal(char capturando[tamano_maloc])
{
    double numero;
    do
    { //Inicio del do-while que realiza la validacion
        char *cadena = malloc(tamano_maloc);
        printf("\nINGRESE UN VALOR PARA EL CAMPO [%s] : ", capturando);
        scanf("%s", cadena);
        numero = validar_decimal(cadena);
        if (numero == -1)
        { //SI NUMERO VALE -1 SIGNIFICA QUE LA CADENA EL NUMERO NO ES VALIDO
            printf(ANSI_COLOR_RED "\nEl valor ingresado para el campo [%s] no es valido\n" ANSI_COLOR_RESET, capturando);
        }
        if (numero == -2)
        { // SI NUMERO VALE -2 SIGNIFICA QUE EL LIMITE ESTABLECIDO PARA LA CADENA HA SIDO EXCEDIDO
            printf(ANSI_COLOR_RED "\nCadena maxima excedida\n" ANSI_COLOR_RESET);
        }
        if (numero == -3)
        {
            printf(ANSI_COLOR_RED "\nNumero de decimales excedido\n" ANSI_COLOR_RESET);
        }
    } while (numero == -1 || numero == -2 || numero == -3); //Fin del do-while que realiza la validacion

    return numero;
}

int pedir_entero(char capturando[tamano_maloc])
{
    int numero;
    do
    { //Inicio del do-while que realiza la validacion
        char *cadena = malloc(tamano_maloc);
        if ((strcmp(capturando, "SEGUNDO NOMBRE") == 0))
        {
            printf("\n[1] SI TIENES SEGUNDO NOMBRE\t[2] SI NO TIENES SEGUNDO NOMBRE : ");
        }
        else if (strcmp(capturando, "SEXO") == 0)
        {
            printf("\n\tSELECCIONA TU SEXO\n[1] MASCULINO\t[2] FEMENINO : ");
        }
        else if (strcmp(capturando, "CONFIRMAR REGISTRO") == 0)
        {
            printf("\n[1] REGISTRAR PACIENTE\t[2] DESCARTAR REGISTRO : ");
        }
        else if (strcmp(capturando, "CONFIRMAR REGISTRO MATERIALES") == 0)
        {
            printf("\n[1] REGISTRAR MATERIAL\t[2] DESCARTAR REGISTRO : ");
        }
        else if (strcmp(capturando, "CONFIRMAR REGISTRO LAB") == 0)
        {
            printf("\n[1] REGISTRAR LABORATORISTA\t[2] DESCARTAR REGISTRO : ");
        }
        else if (strcmp(capturando, "BUSCAR PACIENTES") == 0)
        {
            printf("\n[1] BUSQUEDA POR FOLIO\t[2] BUSQUEDA POR CORREO\t [3] BUSQUEDA POR NOMBRE : ");
        }
        else if (strcmp(capturando, "CONFIRMAR REGISTRO ATRIBUTOS") == 0)
        {
            printf("\n[1] REGISTRAR ATRIBUTO\t[2] DESCARTAR REGISTRO : ");
        }
        else if (strcmp(capturando, "CONFIRMAR REGISTRO REACTIVOS") == 0)
        {
            printf("\n[1] REGISTRAR REACTIVO\t[2] DESCARTAR REGISTRO : ");
        }
        else
        { //SI NO IMPRIME EL PRINTF POR DEFECTO
            printf("\nINGRESE UN VALOR PARA EL CAMPO [%s] : ", capturando);
        }
        scanf("%s", cadena);
        numero = validar_entero(cadena);
        //printf("\nNum: %d\nCapturando: %s\n\n",numero,capturando);
        if (numero == -1)
        { //SI NUMERO VALE -1 SIGNIFICA QUE LA CADENA EL NUMERO NO ES VALIDO
            if (strcmp(capturando, "opcion") == 0)
            { //SI CAPTURANDO ES IGUAL A: "opcion" SE IMPRIME EL SIGUIENTE PRINTF
                //system("clear");
                printf(ANSI_COLOR_RED "\nEl valor ingresado no es valido\n" ANSI_COLOR_RESET);
            }
            else
            { //SI NO IMPRIME EL PRINTF POR DEFECTO
                printf(ANSI_COLOR_RED "\nEl valor ingresado para el campo [%s] no es valido\n" ANSI_COLOR_RESET, capturando);
            }
        }
        if (numero == -2)
        { // SI NUMERO VALE -2 SIGNIFICA QUE EL LIMITE ESTABLECIDO PARA LA CADENA HA SIDO EXCEDIDO
            printf(ANSI_COLOR_RED "\nCadena maxima excedida\n" ANSI_COLOR_RESET);
        }
    } while (numero == -1 || numero == -2); //Fin del do-while que realiza la validacion

    return numero;
}

char *pedir_cadena(char capturando[tamano_maloc])
{
    char *cadena_a_devolver = malloc(tamano_maloc);
    do
    { //Inicio del do-while que realiza la validacion
        char *cadena = malloc(tamano_maloc);
        printf("\nINGRESE EL VALOR PARA EL CAMPO [%s] : ", capturando);
        scanf("%s", cadena);
        cadena_a_devolver = validar_cadena(cadena);
        if ((strcmp(cadena_a_devolver, "-1") == 0))
        { //SI cadena_a_devolver VALE -1 SIGNIFICA QUE LA CADENA NO ES VALIDA
            printf(ANSI_COLOR_RED "\nEl valor ingresado para el campo [%s] no es valido\n" ANSI_COLOR_RESET, capturando);
        }
        if ((strcmp(cadena_a_devolver, "-2") == 0))
        { // SI cadena_a_devolver VALE -2 SIGNIFICA QUE EL LIMITE ESTABLECIDO PARA LA CADENA HA SIDO EXCEDIDO
            printf(ANSI_COLOR_RED "\nCadena maxima excedida\n" ANSI_COLOR_RESET);
        }
    } while ((strcmp(cadena_a_devolver, "-1") == 0) || (strcmp(cadena_a_devolver, "-2") == 0)); //SI LA CADENA NO ES VALIDA O SE PASA DEL RANGO DE CARACTERES, SE REPITE

    return cadena_a_devolver;
}

char *pedir_fecha()
{
    char *cadena_a_devolver = malloc(tamano_maloc);
    do
    { //Inicio del do-while que realiza la validacion
        char *cadena = malloc(tamano_maloc);
        printf("\nINGRESE LA FECHA DE NACIMIENTO (EJ. : 01/02/2020) : ");
        scanf("%s", cadena);
        cadena_a_devolver = validar_fecha(cadena);
        if ((strcmp(cadena_a_devolver, "-1") == 0))
        { //SI cadena_a_devolver VALE -1 SIGNIFICA QUE LA FECHA NO ES VALIDA
            printf(ANSI_COLOR_RED "\nLa fecha no es valida, intente de nuevo\n" ANSI_COLOR_RESET);
        }
        if ((strcmp(cadena_a_devolver, "-2") == 0))
        { // SI cadena_a_devolver VALE -2 SIGNIFICA QUE EL LIMITE ESTABLECIDO PARA LA CADENA HA SIDO EXCEDIDO
            printf(ANSI_COLOR_RED "\nLa fecha no tiene el numero de caracteres permitido\n" ANSI_COLOR_RESET);
        }
    } while ((strcmp(cadena_a_devolver, "-1") == 0) || (strcmp(cadena_a_devolver, "-2") == 0)); //SI LA CADENA NO ES VALIDA O SE PASA DEL RANGO DE CARACTERES, SE REPITE

    return cadena_a_devolver;
}

int pedir_menu(int num_menu)
{
    int opc;
    //VALIDAR SI LA OPCION DEL MENU PRINCIPAL ES UN NUMERO
    do
    {
        char *cadena = malloc(tamano_maloc); //CREO UNA CADENA DE 20 CARACTERES
        if (opc == -1)
        {
            system("clear");
            printf(ANSI_COLOR_RED "Opcion no valida, intente de nuevo\n\n" ANSI_COLOR_RESET);
        }
        if (opc == -2)
        {
            system("clear");
            printf(ANSI_COLOR_RED "Cadena maxima excedida\n\n" ANSI_COLOR_RESET);
        }
        switch (num_menu)
        {
        case 1:
            cadena = menu_principal(); // cadena RECIBE EL VALOR QUE EL USUARIO DIGITE
            break;

        case 2:
            cadena = menu_pacientes(); // cadena RECIBE EL VALOR QUE EL USUARIO DIGITE
            break;

        case 3:
            cadena = menu_laboratoristas(); // cadena RECIBE EL VALOR QUE EL USUARIO DIGITE
            break;

        case 4:
            cadena = menu_analisis(); // cadena RECIBE EL VALOR QUE EL USUARIO DIGITE
            break;

        case 5:
            cadena = menu_materiales(); // cadena RECIBE EL VALOR QUE EL USUARIO DIGITE
            break;

        case 6:
            cadena = menu_reactivos(); // cadena RECIBE EL VALOR QUE EL USUARIO DIGITE
            break;

        case 7:
            cadena = menu_reportes(); // cadena RECIBE EL VALOR QUE EL USUARIO DIGITE
            break;
        }

        opc = validar_entero(cadena); //INVOCO A METODO QUE SE REGRESA EL NUMERO O 0 SI NO ES UN NUMERO
    } while (opc == -1 || opc == -2);
    // FIN VALIDAR....................................................................................................
    return opc;
}

char *validar_fecha(char cadena[tamano_maloc])
{
    char *fecha_devolver = malloc(tamano_maloc);
    char diagonal[1] = "/";
    int valor;
    if (strlen(cadena) == 10)
    { //LA CADENA TIENE 10 CARACTERES A FUERZA 01/12/2020
        for (int i = 0; i < strlen(cadena); i++)
        {
            if (i == 2 || i == 5)
            { //SIGNIFICA QUE AHI DEBEN HABER DIAGONALES
                if (cadena[i] == '/')
                { //SI EL CARACTER ES DIAGONAL
                    valor = 1;
                }
                else
                {
                    valor = 0;
                }
            }
            else
            { //SIGNIFICA QUE AHI DEBEN HABER NUMEROS
                if (isdigit(cadena[i]) != 0)
                { //SI EL CARACTER ES DIGITO
                    valor = 1;
                }
                else
                {
                    valor = 0;
                }
            }
            if (valor == 0)
            {
                break;
            }
        } //FIN FOR
    }     // FIN IF
    else
    { //SI LA CADENA EXCEDE LA CANTIDAD PERMITIDA, fecha_devolver VALE -2 LO CUAL SIGNIFICA QUE LA CADENA NO ES CORRECTA
        valor = 3;
        fecha_devolver = "-2";
    }

    if (valor == 0)
    { //SI LA CADENA NO ES VALIDA
        fecha_devolver = "-1";
    }
    if (valor == 1)
    { //SI LA CADENA ES VALIDA
        fecha_devolver = strdup(cadena);
    }
    return fecha_devolver;
}

int validar_entero(char cadena[tamano_maloc])
{
    int z, valor = 1, num; //Z ES UN CONTADOR, SI VALOR ES 0 SIGNIFICA QUE EL CARACTER NO ES UN NUMERO, SI ES 1 SIGNIFICA QUE EL CARACTER SI ES UN NUMERO
    if (strlen(cadena) > tamano_maloc)
    { //SI LA CADENA EXCEDE LA CANTIDAD PERMITIDA, NUM VALE -2 LO CUAL SIGNIFICA QUE LA CADENA ESTA EXCEDIDA
        num = -2;
        valor = 3;
    }
    else
    {
        for (z = 0; z < strlen(cadena); z++)
        { //ESTE FOR RECORRE LA CADENA CARACTER POR CARACTER
            if (isdigit(cadena[z]) != 0)
            {              //ESTE IF VALIDA QUE LO INGRESADO SEA UN DIGITO
                valor = 1; //SI LA CONDICION SE CUMPLE, TOMA EL VALOR DE 1 LO QUE SIGNIFICA QUE EL CARACTER ANALIZADO SI ES UN NUMERO
            }
            else
            {
                valor = 0; //SI LA CONDICION NO SE COMPLE, TOMA EL VALOR DE 0, ES DECIR, EL CARACTER ANALIZADO NO ES UN NUMERO
            }
            if (valor == 0)
            { //SI ALGUN CARACTER NO ES UN NUMERO SALE DEL FOR
                break;
            }
        }
        if (valor == 1)
        { //SI LA CADENA SI ES UN NUMERO CONVIERTE LA CADENA A ENTERO Y LO DEVUELVE
            num = atoi(cadena);
        }
        if (valor == 0)
        { //SI LA CADENA NO ES UN NUMERO DEVUELVE -1
            num = -1;
        }
    }
    return num;
}

char *validar_cadena(char cadena[tamano_maloc])
{
    char *cadena_devolver = malloc(tamano_maloc);
    int z, valor = 1, num; //Z ES UN CONTADOR, SI VALOR ES 0 SIGNIFICA QUE EL CARACTER NO ES UNA LETRA, SI ES 1 SIGNIFICA QUE EL CARACTER SI ES UNA LETRA
    if (strlen(cadena) > tamano_maloc)
    { //SI LA CADENA EXCEDE LA CANTIDAD PERMITIDA, NUM VALE -2 LO CUAL SIGNIFICA QUE LA CADENA ESTA EXCEDIDA
        cadena_devolver = "-2";
        valor = 3;
    }
    else
    {
        for (z = 0; z < strlen(cadena); z++)
        { //ESTE FOR RECORRE LA CADENA CARACTER POR CARACTER

            if (isalpha(cadena[z]) != 0)
            {              //ESTE IF VALIDA QUE LO INGRESADO SEA UN DIGITO
                valor = 1; //SI LA CONDICION SE CUMPLE, TOMA EL VALOR DE 1 LO QUE SIGNIFICA QUE EL CARACTER ANALIZADO SI ES UN NUMERO
            }
            else
            {
                valor = 0; //SI LA CONDICION NO SE COMPLE, TOMA EL VALOR DE 0, ES DECIR, EL CARACTER ANALIZADO NO ES UN NUMERO
            }
            if (valor == 0)
            { //SI ALGUN CARACTER NO ES UN NUMERO SALE DEL FOR
                break;
            }
        }
    }
    if (valor == 1)
    {                                     //SI LA CADENA TIENE PURAS LETRAS SE REGRESA LA CADENA
        cadena_devolver = strdup(cadena); //USAMOS STRDUP PORQUE NO DA EL PROBLEMA DE VIOLACION DE SEGMENTO QUE SI DA STRCPY
    }
    if (valor == 0)
    { //SI LA CADENA NO ES UNA CADENA DEVUELVE -1
        cadena_devolver = "-1";
    }
    return cadena_devolver;
}

double validar_decimal(char cadena[tamano_maloc])
{
    double decimal_devolver;
    int z, valor = 1, puntos = 0, decimales = 0;
    if (strlen(cadena) > tamano_maloc)
    {
        decimal_devolver = -2;
        valor = 3;
    }
    else
    {
        for (z = 0; z < strlen(cadena); z++)
        {
            if (puntos == 0)
            {
                if (isdigit(cadena[z]) != 0)
                {
                    valor = 1;
                }
                else if (cadena[z] == '.')
                {
                    valor = 1;
                    puntos++;
                }
                else
                {
                    valor = 0;
                }
                continue; //PROCEDE CON LA SIGUIENTE ITERACION
            }
            if (puntos >= 1)
            {
                if (isdigit(cadena[z]) != 0)
                {
                    valor = 1;
                    decimales++;
                }
                else if (cadena[z] == '.')
                {
                    valor = 1;
                    puntos++;
                }
                else
                {
                    valor = 0;
                }
            }

            if (valor == 0)
            {
                break;
            }
        }

        if (valor == 1)
        {

            if (puntos < 2)
            {
                decimal_devolver = atof(cadena);
            }
            else
            {
                decimal_devolver = -1;
            }
        }
        else if (valor == 0)
        {
            decimal_devolver = -1;
        }
        if (decimales > 4)
        {
            decimal_devolver = -3; //-3 SIGNIFICA QUE HAY MAS DE 4 DECIMALES
        }
    }

    return decimal_devolver;
}
char *menu_principal()
{
    char *opc = malloc(tamano_maloc);
    printf("|-------------------MENU PRINCIPAL-------------------|");
    printf("\n[1] PACIENTES");
    printf("\n[2] LABORATORISTAS");
    printf("\n[3] ANALISIS");
    printf("\n[4] MATERIALES");
    printf("\n[5] REACTIVOS");
    printf("\n[6] REPORTES");
    printf("\n[7] SALIR");
    printf("\n----------------------------------------------------\n");
    printf("Ingrese la opcion deseada : ");
    scanf("%s", opc);
    return opc;
}

char *menu_pacientes()
{
    char *opc = malloc(tamano_maloc);
    printf("|------------------MENU PACIENTES------------------|");
    printf("\n[1] ALTA");
    printf("\n[2] BUSCAR");
    printf("\n[3] VOLVER AL MENU PRINCIPAL");
    printf("\n---------------------------------------------------\n");
    printf("Ingrese la opcion deseada : ");
    scanf("%s", opc);
    return opc;
}
void alta_pacientes()
{
    char sql[600];
    printf("|------------------ALTA PACIENTES------------------|\n");
    struct
    {
        char *folio;
        char *nombre1;
        char *nombre2;
        char *apellido1;
        char *apellido2;
        int edad;
        char *sexo_p;
        char *correo;
    } paciente[1];
    paciente[0].folio = malloc(tamano_maloc);
    paciente[0].correo = malloc(tamano_maloc);
    paciente[0].nombre1 = malloc(tamano_maloc);
    paciente[0].nombre2 = malloc(tamano_maloc);
    paciente[0].apellido1 = malloc(tamano_maloc);
    paciente[0].apellido2 = malloc(tamano_maloc);
    paciente[0].nombre2 = strdup("null");
    paciente[0].sexo_p = malloc(tamano_maloc);

    char correo_dado[200];
    int i, j;
    //SE PIDE EL CORREO PARA VER SI YA ESTA REGISTRADO
    printf("INGRESE UN VALOR PARA EL CAMPO [CORREO] : ");
    scanf("%s", correo_dado);
    paciente[0].correo = strdup(correo_dado); //COPIIO EL CORREO QUE EL PACIENTE DIÓ AL STRUCT PACIENTE

    conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1");
    if (PQstatus(conn) != CONNECTION_BAD)
    {
        sprintf(sql, "select folio_p from pacientes where correo ~* '^%s$';", correo_dado);
        res = PQexec(conn, sql);
        if (res != NULL && PQntuples(res) != 0) //SI SE ENCONTRÓ EN EL SISTEMA
        {
            int folio;
            //SE IMPRIME SU FOLIO
            for (i = 0; i < PQntuples(res); i++)
            {
                for (j = 0; j < PQnfields(res); j++)
                {
                    paciente[0].folio = PQgetvalue(res, i, j); //SE OBTIENE SU FOLIO DEL PACIENTE
                    folio = atoi(paciente[0].folio);           // SE CONVIERTE EL FOLIO A ENTERO
                    printf(ANSI_COLOR_GREEN "Se ha encontrado el correo en el sistema\n" ANSI_COLOR_RESET);
                    printf("\n     - > FOLIO DEL PACIENTE : %d\t\n\n", folio); //SE IMPRIME SU FOLIO DEL PACIENTE
                }
                PQclear(res);
            }
            //SE LE ACTUALIZA SU ESTADO A TRUE POR SI LO TENÍA EN FALSE
            conn2 = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1");//ABRO CONEXION 2
            sprintf(sql, "update pacientes set estado_p = true where folio_p = %d;", folio);
            res = PQexec(conn2, sql);
            if (PQresultStatus(res) == PGRES_COMMAND_OK)
            {
                printf(ANSI_COLOR_GREEN "Se ha actualizar el estado del paciente de manera exitosa\n" ANSI_COLOR_RESET);
            }
            else
            {
                printf(ANSI_COLOR_RED "No se ha podido actualizar el estado del paciente\n" ANSI_COLOR_RESET);
            }
            PQfinish(conn2);//CIERRO CONEXION 2
        }
        else
        { //SI NO SE ENCONTRO SU CORREO SE DA DE ALTA:
            // PQfinish(conn);
            int opc_correo, opc_nombre2, opc_sexo, opc_confirmacion;
            int salir = 0;
            printf("\nNo se ha encontrado el correo en la base de datos, procederemos con el registro\n");

            paciente[0].nombre1 = pedir_cadena("NOMBRE"); //PEDIMOS NOMBRE

            opc_nombre2 = pedir_dos_opciones("SEGUNDO NOMBRE");       //SABER SI TIENE SEGUNDO NOMBRE
            if (opc_nombre2 == 1)                                     //SI TIENE SEGUNDO NOMBRE
            {                                                         //HAY QUE PEDIR SEGUNDO NOMBRE
                paciente[0].nombre2 = pedir_cadena("SEGUNDO NOMBRE"); //PEDIMOS SEGUNDO NOMBRE
            }

            paciente[0].apellido1 = pedir_cadena("PRIMER APELLIDO"); //PEDIMOS PRIMER APELLIDO

            paciente[0].apellido2 = pedir_cadena("SEGUNDO APELLIDO"); //PEDIMOS SEGUNDO APELLIDO

            paciente[0].edad = pedir_entero("EDAD"); //PEDIMOS EDAD

            opc_sexo = pedir_dos_opciones("SEXO");
            if (opc_sexo == 1)
            { //ES MASCULINO
                paciente[0].sexo_p = strdup("masculino");
            }
            else
            { //ES FEMENINO
                paciente[0].sexo_p = strdup("femenino");
            }

            //IMPRIMIR LOS VALORES CAPTURADOS
            system("clear");
            printf("---------------------------------------------------\n");
            printf("\tDATOS RECOPILADOS\n");
            printf("---------------------------------------------------\n");
            printf("     - > CORREO: %s\n", paciente[0].correo);
            printf("     - > NOMBRE: %s\n", paciente[0].nombre1);
            if ((strcmp(paciente[0].nombre2, "null") == 0))
            { //SI NO TIENE SEGUNDO NOMBRE
                //NO IMPRIMIMOS SEGUNDO NOMBRE
            }
            else
            {
                printf("     - > SEGUNDO NOMBRE: %s\n", paciente[0].nombre2);
            }
            printf("     - > PRIMER APELLIDO: %s\n", paciente[0].apellido1);
            printf("     - > SEGUNDO APELLIDO: %s\n", paciente[0].apellido2);
            printf("     - > EDAD: %d\n", paciente[0].edad);
            printf("     - > SEXO: %s\n", paciente[0].sexo_p);
            printf("---------------------------------------------------");

            opc_confirmacion = pedir_dos_opciones("CONFIRMAR REGISTRO");
            system("clear");

            //char sql[400];
            if (opc_confirmacion == 1)
            { //INSERTAMOS
                if ((strcmp(paciente[0].nombre2, "null") == 0))
                { //SI NO TIENE SEGUNDO NOMBRE
                    //NO IMPRIMIMOS SEGUNDO NOMBRE
                    sprintf(sql, "insert into pacientes (nom_p, edad_p, sexo_p, correo) values(UPPER('%s %s %s'), %d, UPPER('%s'), UPPER('%s'));", paciente[0].nombre1, paciente[0].apellido1, paciente[0].apellido2, paciente[0].edad, paciente[0].sexo_p, paciente[0].correo);
                }
                else
                {
                    //SI TIENE SEGUNDO NOMBRE
                    sprintf(sql, "insert into pacientes (nom_p, edad_p, sexo_p, correo) values(UPPER('%s %s %s %s'), %d, UPPER('%s'), UPPER('%s'));", paciente[0].nombre1, paciente[0].nombre2, paciente[0].apellido1, paciente[0].apellido2, paciente[0].edad, paciente[0].sexo_p, paciente[0].correo);
                }

                conn3 = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1");//ABRO CONEXION 3
                if (PQstatus(conn3) != CONNECTION_BAD)
                {
                    res = PQexec(conn3, sql);
                    if (PQresultStatus(res) == PGRES_COMMAND_OK)
                    {
                        printf(ANSI_COLOR_GREEN "Se ha registrado el paciente de manera exitosa\n" ANSI_COLOR_RESET);
                    }
                    else
                    {
                        printf(ANSI_COLOR_RED "No se ha podido registrar el paciente, notifique el error\n" ANSI_COLOR_RESET);
                    }
                }
                else
                {
                    printf("No conecto esta mierda\n");
                }
                PQfinish(conn3); //CIERRO CONEXION 3
            }
            else
            {
                //INFORMAMOS QUE SE CANCELÓ
                printf(ANSI_COLOR_RED "CANCELADO\n" ANSI_COLOR_RESET);
            }
        }
    }
    else
    {
        printf("Error de conexion a la base de datos\n");
    }
    PQfinish(conn);
    printf("---------------------------------------------------\n\n\n");
}
int pedir_dos_opciones(char palabra_clave[tamano_maloc])
{
    int salir, opc;
    do
    {
        salir = 0;
        opc = pedir_entero(palabra_clave); //SE PIDE UN ENTERO Y SE MANDA LA PALABRA CLAVE PARA UN MENSAJE PERSONALIZADO
        if ((opc == 1) || (opc == 2))
        {
            salir = 1; //SI LAS OPCION ELEGIDA ES 1 O 2 SALIR=1 PARA QUE SALGA DEL CICLO
        }
        else
        {
            printf(ANSI_COLOR_RED "\nEl valor recibido no es 1 o 2\n" ANSI_COLOR_RESET);
        }
    } while (salir != 1);
    return opc;
}
void buscar_pacientes()
{
    int opc_busqueda, opc_nombre2, folio;
    char sql[600];
    struct
    {
        int folio;
        char *nombre1;
        char *nombre2;
        char *apellido1;
        char *apellido2;
        char *correo;
    } paciente[1];
    paciente[0].correo = malloc(tamano_maloc);
    paciente[0].nombre1 = malloc(tamano_maloc);
    paciente[0].nombre2 = malloc(tamano_maloc);
    paciente[0].apellido1 = malloc(tamano_maloc);
    paciente[0].apellido2 = malloc(tamano_maloc);
    paciente[0].nombre2 = strdup("null");

    printf("|-----------------BUSCAR PACIENTES-----------------|\n");
    opc_busqueda = pedir_tres_opciones("BUSCAR PACIENTES");
    switch (opc_busqueda)
    {
    case 1:
        paciente[0].folio = pedir_entero("FOLIO"); //PIDO FOLIO
        //GENERAMOS LA CONSULTA
        sprintf(sql, "select folio_p, nom_p, sexo_p, edad_p, correo, fecha_registro from pacientes where estado_p = true and folio_p = %d;", paciente[0].folio);
        imprimir_pacientes(sql); //HACER LA BUSQUEDA Y IMPRIMIR
        break;
    case 2:
        printf("\nINGRESE UN VALOR PARA EL CAMPO [CORREO] : "); //PEDIMOS CORREO
        scanf("%s", paciente[0].correo);

        //GENERAMOS LA CONSULTA
        sprintf(sql, "select folio_p, nom_p, sexo_p, edad_p, correo, fecha_registro from pacientes where estado_p = true and correo ~* '^%s$';", paciente[0].correo);
        imprimir_pacientes(sql); //HACER LA BUSQUEDA Y IMPRIMIR

        break;

    case 3:
        paciente[0].nombre1 = pedir_cadena("NOMBRE"); //PEDIMOS NOMBRE

        opc_nombre2 = pedir_dos_opciones("SEGUNDO NOMBRE");       //SABER SI TIENE SEGUNDO NOMBRE
        if (opc_nombre2 == 1)                                     //SI TIENE SEGUNDO NOMBRE
        {                                                         //HAY QUE PEDIR SEGUNDO NOMBRE
            paciente[0].nombre2 = pedir_cadena("SEGUNDO NOMBRE"); //PEDIMOS SEGUNDO NOMBRE
        }
        paciente[0].apellido1 = pedir_cadena("PRIMER APELLIDO"); //PEDIMOS PRIMER APELLIDO

        paciente[0].apellido2 = pedir_cadena("SEGUNDO APELLIDO"); //PEDIMOS SEGUNDO APELLIDO

        if ((strcmp(paciente[0].nombre2, "null") == 0))
        { //NO TIENE SEGUNDO NOMBRE
            sprintf(sql, "select folio_p, nom_p, sexo_p, edad_p, correo, fecha_registro from pacientes where estado_p = true and nom_p ~* '^%s %s %s$';", paciente[0].nombre1, paciente[0].apellido1, paciente[0].apellido2);
        }
        else
        {
            sprintf(sql, "select folio_p, nom_p, sexo_p, edad_p, correo, fecha_registro from pacientes where estado_p = true and nom_p ~* '^%s %s %s %s$';", paciente[0].nombre1, paciente[0].nombre2, paciente[0].apellido1, paciente[0].apellido2);
        }
        imprimir_pacientes(sql); //HACER LA BUSQUEDA Y IMPRIMIR
        break;
    }

    printf("---------------------------------------------------\n\n\n");
}

void imprimir_pacientes(char sql[600])
{

    conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //CREAMOS LA CONEXION

    system("clear");

    if (PQstatus(conn) != CONNECTION_BAD)
    {
        res = PQexec(conn, sql);
        if (res != NULL && PQntuples(res) != 0)
        { //SE ENCONTRARON PACIENTES
            printf("---------------------------------------------------\n");
            printf("\tPACIENTE ENCONTRADO\n");
            printf("---------------------------------------------------\n\n");
            //SE IMPRIMEN LOS PACIENTES ENCONTRADOS
            for (int i = 0; i < PQntuples(res); i++)
            {
                for (int j = 0; j < PQnfields(res); j++) //hay 5 campos
                {
                    switch (j)
                    {
                    case 0:
                        printf("     - > FOLIO : ");
                        printf(ANSI_COLOR_BLUE "%s\n\n" ANSI_COLOR_RESET, PQgetvalue(res, i, j));
                        break;
                    case 1:
                        printf("     - > NOMBRE : ");
                        printf(ANSI_COLOR_BLUE "%s\n\n" ANSI_COLOR_RESET, PQgetvalue(res, i, j));
                        break;
                    case 2:
                        printf("     - > SEXO : ");
                        printf(ANSI_COLOR_BLUE "%s\n\n" ANSI_COLOR_RESET, PQgetvalue(res, i, j));
                        break;
                    case 3:
                        printf("     - > EDAD : ");
                        printf(ANSI_COLOR_BLUE "%s\n\n" ANSI_COLOR_RESET, PQgetvalue(res, i, j));
                        break;
                    case 4:
                        printf("     - > CORREO : ");
                        printf(ANSI_COLOR_BLUE "%s\n\n" ANSI_COLOR_RESET, PQgetvalue(res, i, j));
                        break;
                    case 5:
                        printf("     - > FECHA DE REGISTRO : ");
                        printf(ANSI_COLOR_BLUE "%s\n\n" ANSI_COLOR_RESET, PQgetvalue(res, i, j));
                        break;
                    }
                }
                PQclear(res);
            }
        }
        else
        { //NO SE ENCONTRARON PACIENTES
            printf(ANSI_COLOR_RED "No se han encontrado pacientes\n" ANSI_COLOR_RESET);
        }
    }
    else
    {
        printf("No conecto esta mierda\n");
    }

    PQfinish(conn); //FINALIZAMOS LA CONEXION
}

int pedir_tres_opciones(char palabra_clave[tamano_maloc])
{
    int salir, opc;
    do
    {
        salir = 0;
        opc = pedir_entero(palabra_clave); //SE PIDE UN ENTERO Y SE MANDA LA PALABRA CLAVE PARA UN MENSAJE PERSONALIZADO
        if ((opc == 1) || (opc == 2) || (opc == 3))
        {
            salir = 1; //SI LAS OPCION ELEGIDA ES 1, 2 o 3 SALIR=1 PARA QUE SALGA DEL CICLO
        }
        else
        {
            printf(ANSI_COLOR_RED "\nEl valor recibido no es 1, 2 o 3\n" ANSI_COLOR_RESET);
        }
    } while (salir != 1);
    return opc;
}

char *menu_laboratoristas()
{
    char *opc = malloc(tamano_maloc);
    printf("|--------------MENU  LABORATORISTAS----------------|");
    printf("\n[1] ALTA");
    printf("\n[2] BUSCAR");
    printf("\n[3] DESPEDIR");
    printf("\n[4] VOLVER AL MENU PRINCIPAL");
    printf("\n---------------------------------------------------\n");
    printf("Ingrese la opcion deseada : ");
    scanf("%s", opc);
    return opc;
}
void alta_laboratoristas()
{
    char sql[600];
    conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1");
    printf("|----------------ALTA LABORATORISTA----------------|\n");
    struct
    {
        char *cedula;
        char *nombre1;
        char *nombre2;
        char *apellido1;
        char *apellido2;
        char *sexo_lab;
        char *correo;
        char *fecha_nac;
    } laboratorista[1];
    laboratorista[0].cedula = malloc(tamano_maloc);
    laboratorista[0].correo = malloc(tamano_maloc);
    laboratorista[0].nombre1 = malloc(tamano_maloc);
    laboratorista[0].nombre2 = malloc(tamano_maloc);
    laboratorista[0].apellido1 = malloc(tamano_maloc);
    laboratorista[0].apellido2 = malloc(tamano_maloc);
    laboratorista[0].nombre2 = strdup("null");
    laboratorista[0].sexo_lab = malloc(tamano_maloc);
    laboratorista[0].fecha_nac = malloc(tamano_maloc);

    if (PQstatus(conn) != CONNECTION_BAD)
    {
        //SE DA DE ALTA:
        // PQfinish(conn)
        printf("\n INGRESE UN VALOR PARA EL CAMPO [CEDULA] : "); //PEDIR CEDULA
        scanf("%s", laboratorista[0].cedula);
        //laboratorista[0].cedula = pedir_cadena("CEDULA"); //PEDIMOS CEDULA

        int opc_correo, opc_nombre2, opc_sexo, opc_confirmacion;
        int salir = 0;

        laboratorista[0].nombre1 = pedir_cadena("NOMBRE"); //PEDIMOS NOMBRE

        opc_nombre2 = pedir_dos_opciones("SEGUNDO NOMBRE");            //SABER SI TIENE SEGUNDO NOMBRE
        if (opc_nombre2 == 1)                                          //SI TIENE SEGUNDO NOMBRE
        {                                                              //HAY QUE PEDIR SEGUNDO NOMBRE
            laboratorista[0].nombre2 = pedir_cadena("SEGUNDO NOMBRE"); //PEDIMOS SEGUNDO NOMBRE
        }

        laboratorista[0].apellido1 = pedir_cadena("PRIMER APELLIDO"); //PEDIMOS PRIMER APELLIDO

        laboratorista[0].apellido2 = pedir_cadena("SEGUNDO APELLIDO"); //PEDIMOS SEGUNDO APELLIDO

        laboratorista[0].fecha_nac = pedir_fecha("FECHA DE NACIMIENTO"); //PEDIMOS FECHA DE NACIMIENTO

        char correo_dado[200];
        int i, j;

        printf("\nINGRESE UN VALOR PARA EL CAMPO [CORREO] : ");
        scanf("%s", correo_dado);
        laboratorista[0].correo = strdup(correo_dado);

        opc_sexo = pedir_dos_opciones("SEXO");
        if (opc_sexo == 1)
        { //ES MASCULINO
            laboratorista[0].sexo_lab = strdup("masculino");
        }
        else
        { //ES FEMENINO
            laboratorista[0].sexo_lab = strdup("femenino");
        }

        //IMPRIMIR LOS VALORES CAPTURADOS
        system("clear");
        printf("---------------------------------------------------\n");
        printf("\tDATOS RECOPILADOS\n");
        printf("---------------------------------------------------\n");
        printf("     - > CEDULA: %s\n", laboratorista[0].cedula);
        printf("     - > NOMBRE: %s\n", laboratorista[0].nombre1);
        if ((strcmp(laboratorista[0].nombre2, "null") == 0))
        { //SI NO TIENE SEGUNDO NOMBRE
            //NO IMPRIMIMOS SEGUNDO NOMBRE
        }
        else
        {
            printf("     - > SEGUNDO NOMBRE: %s\n", laboratorista[0].nombre2);
        }
        printf("     - > PRIMER APELLIDO: %s\n", laboratorista[0].apellido1);
        printf("     - > SEGUNDO APELLIDO: %s\n", laboratorista[0].apellido2);
        printf("     - > SEXO: %s\n", laboratorista[0].sexo_lab);
        printf("     - > FECHA DE NACIMIENTO: %s\n", laboratorista[0].fecha_nac);
        printf("     - > CORREO: %s\n", laboratorista[0].correo);

        printf("---------------------------------------------------");

        opc_confirmacion = pedir_dos_opciones("CONFIRMAR REGISTRO LAB");
        system("clear");

        //char sql[400];
        if (opc_confirmacion == 1)
        { //INSERTAMOS
            if ((strcmp(laboratorista[0].nombre2, "null") == 0))
            { //SI NO TIENE SEGUNDO NOMBRE
                //NO IMPRIMIMOS SEGUNDO NOMBRE
                sprintf(sql, "insert into laboratoristas (cedula_lab,nom_lab, sexo_lab, correo,fecha_nac_lab) values(UPPER('%s'),UPPER('%s %s %s'),UPPER('%s'), UPPER('%s'),'%s');", laboratorista[0].cedula, laboratorista[0].nombre1, laboratorista[0].apellido1, laboratorista[0].apellido2, laboratorista[0].sexo_lab, laboratorista[0].correo, laboratorista[0].fecha_nac);
            }
            else
            {
                //SI TIENE SEGUNDO NOMBRE
                sprintf(sql, "insert into laboratoristas (cedula_lab,nom_lab, sexo_lab, correo,fecha_nac_lab) values(UPPER('%s'),UPPER('%s %s %s %s'), UPPER('%s'), UPPER('%s'), '%s');", laboratorista[0].cedula, laboratorista[0].nombre1, laboratorista[0].nombre2, laboratorista[0].apellido1, laboratorista[0].apellido2, laboratorista[0].sexo_lab, laboratorista[0].correo, laboratorista[0].fecha_nac);
            }
            if (PQstatus(conn) != CONNECTION_BAD)
            {
                res = PQexec(conn, sql);
                if (PQresultStatus(res) == PGRES_COMMAND_OK)
                {
                    printf(ANSI_COLOR_GREEN "Se ha registrado el laboratorista de manera exitosa\n" ANSI_COLOR_RESET);
                }
                else
                {
                    printf(ANSI_COLOR_RED "No se ha podido registrar el laboratorista, notifique el error\n" ANSI_COLOR_RESET);
                }
            }
            else
            {
                printf("No conecto esta mierda\n");
            }
        }
        else
        {
            //INFORMAMOS QUE SE CANCELÓ
            printf(ANSI_COLOR_RED "CANCELADO\n" ANSI_COLOR_RESET);
        }
    }
    else
    {
        printf("Error de conexion a la base de datos\n");
    }
    PQfinish(conn);
    printf("---------------------------------------------------\n\n\n");
}
void buscar_laboratoristas()
{
    printf("|---------------BUSCAR LABORATORISTA---------------|\n");
    printf("---------------------------------------------------\n\n\n");
}
void despedir_laboratoristas()
{
    printf("|--------------DESPEDIR LABORATORISTA--------------|\n");
    printf("---------------------------------------------------\n\n\n");
}

char *menu_analisis()
{
    char *opc = malloc(tamano_maloc);
    printf("|-----------------MENU  ANALISIS-------------------|");
    printf("\n[1] SOLICITAR ANALISIS");
    printf("\n[2] REALIZAR ANALISIS");
    printf("\n[3] ENTREGAR ANALISIS");
    printf("\n[4] BUSCAR ANALISIS");
    printf("\n[5] CONSULTAS ANALISIS");
    printf("\n[6] AGREGAR ATRIBUTOS DE ANALISIS");
    printf("\n[7] AGREGAR UN NUEVO ANALISIS");
    printf("\n[8] VOLVER AL MENU PRINCIPAL");
    printf("\n---------------------------------------------------\n");
    printf("Ingrese la opcion deseada : ");
    scanf("%s", opc);
    return opc;
}
void solicitar_analisis()
{
    printf("|----------------SOLICITAR ANALISIS----------------|\n");
    printf("---------------------------------------------------\n\n\n");
}
void realizar_analisis()
{
    printf("|----------------REALIZAR  ANALISIS----------------|\n");
    printf("---------------------------------------------------\n\n\n");
}
void entregar_analisis()
{
    printf("|----------------ENTREGAR  ANALISIS----------------|\n");
    printf("---------------------------------------------------\n\n\n");
}
void buscar_analisis()
{
    printf("|-----------------BUSCAR  ANALISIS-----------------|\n");
    printf("---------------------------------------------------\n\n\n");
}
void consultas_analisis()
{
    printf("|----------------CONSULTAS ANALISIS----------------|\n");
    printf("---------------------------------------------------\n\n\n");
}
void agregar_atributos_analisis()
{
    char sql[600];
    conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1");
    printf("|----------AGREGAR ATRIBUTOS  DE ANALISIS----------|\n");
    struct
    {
        char *nombre;
        char *descripcion;
        double min;
        double max;
        int stockactual;
    } atributos[1];
    atributos[0].nombre = malloc(tamano_maloc);
    atributos[0].descripcion = malloc(70);

    int opc_confirmacion;
    int salir = 0;
    printf("\nProcederemos al registro del atributo\n");

    atributos[0].nombre = pedir_cadena("NOMBRE"); //PEDIMOS NOMBRE

    printf("\nINGRESE UN VALOR PARA EL CAMPO [DESCRIPCION] : "); //PEDIMOS DESCRIPCION
    scanf("%s",atributos[0].descripcion);


    atributos[0].min = pedir_decimal("VALOR MINIMO DEL ATRIBUTO"); //PEDIMOS VALOR MINIMO

    atributos[0].max = pedir_decimal("VALOR MAXIMO DEL ATRIBUTO"); //PEDIMOS VALOR MAXIMO

    //IMPRIMIR LOS VALORES CAPTURADOS
    system("clear");
    printf("---------------------------------------------------\n");
    printf("\tDATOS RECOPILADOS\n");
    printf("---------------------------------------------------\n");
    printf("     - > ATRIBUTO: %s\n", atributos[0].nombre);
    printf("     - > DESCRIPCION: %s\n", atributos[0].descripcion);
    printf("     - > VALOR MINIMO: %lf\n", atributos[0].min);
    printf("     - > VALOR MAXIMO: %lf\n", atributos[0].max);
    printf("---------------------------------------------------");

    opc_confirmacion = pedir_dos_opciones("CONFIRMAR REGISTRO ATRIBUTOS");
    system("clear");

    if (opc_confirmacion == 1)
    {     //INSERTAMOS
        { //REGISTRAMOS EL MATERIAL
            sprintf(sql, "insert into atributos (nom_atri, descrip_atri, min, max) values(UPPER('%s'), UPPER('%s'), %lf, %lf);", atributos[0].nombre, atributos[0].descripcion, atributos[0].min, atributos[0].max);
        }

        if (PQstatus(conn) != CONNECTION_BAD)
        {
            res = PQexec(conn, sql);
            if (PQresultStatus(res) == PGRES_COMMAND_OK)
            {
                printf(ANSI_COLOR_GREEN "Se ha registrado el atributo de manera exitosa\n" ANSI_COLOR_RESET);
            }
            else
            {
                printf(ANSI_COLOR_RED "No se ha podido registrar el atributo, notifique el error\n" ANSI_COLOR_RESET);
            }
        }
        else
        {
            printf("La conexion no fue posible\n");
        }

    }
    else
    {
        //INFORMAMOS QUE SE CANCELÓ
        printf(ANSI_COLOR_RED "CANCELADO\n" ANSI_COLOR_RESET);
    }
    PQfinish(conn);
    printf("---------------------------------------------------\n\n\n");
}
void agregar_nuevo_analisis()
{
    printf("|--------------AGREGAR NUEVO ANALISIS--------------|\n");
    printf("---------------------------------------------------\n\n\n");
}

char *menu_materiales()
{
    char *opc = malloc(tamano_maloc);
    printf("|----------------MENU  MATERIALES------------------|");
    printf("\n[1] ALTA");
    printf("\n[2] BAJA");
    printf("\n[3] VOLVER AL MENU PRINCIPAL");
    printf("\n---------------------------------------------------\n");
    printf("Ingrese la opcion deseada : ");
    scanf("%s", opc);
    return opc;
}
void alta_materiales()
{
    char sql[600];
    conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1");
    printf("|-----------------ALTA  MATERIALES-----------------|\n");
    struct
    {
        char *codbarra;
        char *nombre;
        int stockmax;
        int stockmin;
        int stockactual;
    } materiales[1];
    materiales[0].codbarra = malloc(tamano_maloc);
    materiales[0].nombre = malloc(tamano_maloc);

    int opc_confirmacion;
    int salir = 0;
    printf("\nProcederemos al registro del material\n");

    materiales[0].nombre = pedir_cadena("NOMBRE"); //PEDIMOS NOMBRE

    materiales[0].stockmax = pedir_entero("STOCK MAXIMO"); //PEDIMOS EL STOCK MAXIMO QUE DEBE HABER

    materiales[0].stockmin = pedir_entero("STOCK MINIMO"); //PEDIMOS EL STOCK MINIMO QUE DEBE HABER

    materiales[0].stockactual = pedir_entero("STOCK ACTUAL"); //PEDIMOS EL STOCK ACTUAL

    //IMPRIMIR LOS VALORES CAPTURADOS
    system("clear");
    printf("---------------------------------------------------\n");
    printf("\tDATOS RECOPILADOS\n");
    printf("---------------------------------------------------\n");
    printf("     - > MATERIAL: %s\n", materiales[0].nombre);
    printf("     - > STOCK MAXIMO: %d\n", materiales[0].stockmax);
    printf("     - > STOCK MINIMO: %d\n", materiales[0].stockmin);
    printf("     - > STOCK ACTUAL: %d\n", materiales[0].stockactual);
    printf("---------------------------------------------------");

    opc_confirmacion = pedir_dos_opciones("CONFIRMAR REGISTRO MATERIALES");
    system("clear");

    //char sql[400];
    if (opc_confirmacion == 1)
    {     //INSERTAMOS
        { //REGISTRAMOS EL MATERIAL
            sprintf(sql, "insert into materiales (nom_m, stock_max_m, stock_min_m, stock_actual_m) values(UPPER('%s'), %d, %d, %d);", materiales[0].nombre, materiales[0].stockmax, materiales[0].stockmin, materiales[0].stockactual);
        }

        if (PQstatus(conn) != CONNECTION_BAD)
        {
            res = PQexec(conn, sql);
            if (PQresultStatus(res) == PGRES_COMMAND_OK)
            {
                printf(ANSI_COLOR_GREEN "Se ha registrado el material de manera exitosa\n" ANSI_COLOR_RESET);
            }
            else
            {
                printf(ANSI_COLOR_RED "No se ha podido registrar el material, notifique el error\n" ANSI_COLOR_RESET);
            }
        }
        else
        {
            printf("La conexion no fue posible\n");
        }
    }
    else
    {
        //INFORMAMOS QUE SE CANCELÓ
        printf(ANSI_COLOR_RED "CANCELADO\n" ANSI_COLOR_RESET);
    }

    PQfinish(conn);

    printf("---------------------------------------------------\n\n\n");
}
void baja_materiales()
{
    printf("|-----------------BAJA  MATERIALES-----------------|\n");
    printf("---------------------------------------------------\n\n\n");
}

char *menu_reactivos(char palabra_clave[tamano_maloc])
{
    char *opc = malloc(tamano_maloc);
    printf("|-----------------MENU REACTIVOS-------------------|");
    printf("\n[1] ALTA");
    printf("\n[2] BAJA");
    printf("\n[3] VOLVER AL MENU PRINCIPAL");
    printf("\n---------------------------------------------------\n");
    printf("Ingrese la opcion deseada : ");
    scanf("%s", opc);
    return opc;
}

int consulta_rapida_enteros(char sql[100])
{
    conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1");
    int devolver;
    if (PQstatus(conn) != CONNECTION_BAD)
    {
        res = PQexec(conn, sql);
        devolver = atoi(PQgetvalue(res, 0, 0)); //OBTIENE LO QUE DEVUELVA LA CADENA
    }

    PQfinish(conn);
    return devolver;
}
void alta_reactivos()
{
    char sql[600];
    printf("|------------------ALTA  REACTIVO------------------|\n");
    struct
    {
        char *codbarra;
        char *nombre;
        int numunidad;
        double stockmax;
        double stockmin;
        double stockactual;
    } reactivos[1];
    reactivos[0].codbarra = malloc(tamano_maloc);
    reactivos[0].nombre = malloc(tamano_maloc);

    int opc_confirmacion, opc_unidad_medida, n_unidades;
    printf("\nProcederemos al registro del reactivo\n");

    reactivos[0].nombre = pedir_cadena("NOMBRE"); //PEDIMOS NOMBRE

    reactivos[0].numunidad = pedir_unidad_medida(); //PEDIMOS UNIDAD DE MEDIDA

    reactivos[0].stockmax = pedir_decimal("STOCK MAXIMO"); //PEDIMOS EL STOCK MAXIMO QUE DEBE HABER

    reactivos[0].stockmin = pedir_decimal("STOCK MINIMO"); //PEDIMOS EL STOCK MINIMO QUE DEBE HABER

    reactivos[0].stockactual = pedir_decimal("STOCK ACTUAL"); //PEDIMOS EL STOCK ACTUAL

    //IMPRIMIR LOS VALORES CAPTURADOS
    system("clear");
    printf("---------------------------------------------------\n");
    printf("\tDATOS RECOPILADOS\n");
    printf("---------------------------------------------------\n");
    printf("     - > REACTIVO: %s\n", reactivos[0].nombre);
    printf("     - > UNIDAD DE MEDIDA: %d\n", reactivos[0].numunidad);
    printf("     - > STOCK MAXIMO: %lf\n", reactivos[0].stockmax);
    printf("     - > STOCK MINIMO: %lf\n", reactivos[0].stockmin);
    printf("     - > STOCK ACTUAL %lf\n", reactivos[0].stockactual);
    printf("---------------------------------------------------");

    opc_confirmacion = pedir_dos_opciones("CONFIRMAR REGISTRO REACTIVOS");
    system("clear");

    if (opc_confirmacion == 1)
    {     //INSERTAMOS
        { //REGISTRAMOS EL REACTIVO
            sprintf(sql, "insert into reactivos (nom_r, num_unidad, stock_max_r, stock_min_r, stock_actual_r) values(UPPER('%s'), %d, %lf, %lf, %lf);", reactivos[0].nombre, reactivos[0].numunidad, reactivos[0].stockmax, reactivos[0].stockmin, reactivos[0].stockactual);
        }

        conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //ESTABLESCO UNA CONEXION
        if (PQstatus(conn) != CONNECTION_BAD)
        {
            res = PQexec(conn, sql);
            if (PQresultStatus(res) == PGRES_COMMAND_OK)
            {
                printf(ANSI_COLOR_GREEN "Se ha registrado el reactivo de manera exitosa\n" ANSI_COLOR_RESET);
            }
            else
            {
                printf(ANSI_COLOR_RED "No se ha podido registrar el reactivo, notifique el error\n" ANSI_COLOR_RESET);
            }
        }
        else
        {
            printf("La conexion no fue posible\n");
        }
        PQfinish(conn);
    }
    else
    {
        //INFORMAMOS QUE SE CANCELÓ
        printf(ANSI_COLOR_RED "CANCELADO\n" ANSI_COLOR_RESET);
    }

    printf("---------------------------------------------------\n\n\n");
}
void baja_reactivos()
{
    printf("|------------------BAJA REACTIVOS------------------|\n");
    printf("---------------------------------------------------\n\n\n");
}

char *menu_reportes()
{
    system("clear");
    printf("|-----------------MENU REPORTES------------------|\n");
    double prueba = pedir_decimal("PRECIO");
    printf("Prueba: %lf\n", prueba);
    printf("---------------------------------------------------\n\n\n");
    return "0";
}
void hacer_select()
{
    /*PGconn *conn;
    PGresult *res;*/
    int i, j;
    conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1");
    if (PQstatus(conn) != CONNECTION_BAD)
    {
        res = PQexec(conn, "select num_unidad, nom_unidad from unidad_medida;");

        if (res != NULL && PGRES_TUPLES_OK == PQresultStatus(res))
        {
            for (i = 0; i < PQntuples(res); i++)
            {
                for (j = 0; j < PQnfields(res); j++)
                    printf("%s\t", PQgetvalue(res, i, j));
                printf("\n");
            }
            PQclear(res);
        }
    }

    PQfinish(conn);
}