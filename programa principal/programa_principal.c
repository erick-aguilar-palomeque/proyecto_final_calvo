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
char *consulta_rapida_cadenas();
void insertar();
void imprimir_resultados();

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
void imprimir_laboratoristas();
void buscar_laboratoristas();
void despedir_laboratoristas();

char *menu_analisis();
int seleccionar_analisis_del_catalogo();
int ver_si_cadena_existe();
char *seleccionar_laboratorista_para_analisis();
void solicitar_analisis();
void ejecutar_consulta();
void realizar_analisis();
void entregar_analisis();
void buscar_analisis();
void hacer_select_analisis();
void consultas_analisis();
void pedir_reactivos_atributos();
void agregar_atributos_analisis();
void pedir_materiales_analisis();
void confirmar_reactivos_atributos();
void pedir_atributos_analisis();
int ver_si_algo_esta_repetido();
int ver_si_algo_existe();
void confirmar_nuevo_analisis();
void agregar_nuevo_analisis();
void ver_catalogo_analisis();
void baja_analisis();

char *menu_materiales();
void alta_materiales();
void baja_materiales();

char *menu_reactivos();
void alta_reactivos();
void baja_reactivos();

char *menu_reportes();
PGconn *conn, *conn2, *conn3, *conn4, *conn5, *conn6;
PGresult *res, *res2;
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
                    ver_catalogo_analisis();
                    break;
                case 9:
                    system("clear");
                    baja_analisis();
                    break;
                case 10:
                    system("clear");
                    break;
                default:
                    system("clear");
                    printf(ANSI_COLOR_RED "Opcion no valida, intente de nuevo\n\n" ANSI_COLOR_RESET);
                    break;
                }
            } while (opc_analisis != 10);
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
        else if (strcmp(capturando, "TIEMPO DE REALIZACION") == 0)
        {
            printf("\nINGRESE UN VALOR PARA EL CAMPO [TIEMPO DE REALIZACION] *En horas* : ");
        }
        else if (strcmp(capturando, "CONFIRMAR REGISTRO ANALISIS") == 0)
        {
            printf("\n[1] REGISTRAR ANALISIS\t[2] DESCARTAR REGISTRO : ");
        }
        else if (strcmp(capturando, "OPCIÓN DE ANÁLISIS") == 0)
        {
            printf("\n[1] ANÁLISIS SOLICITADOS\t[2] ANÁLISIS REALIZADOS\t [3] ANÁLISIS ENTREGADOS : ");
        }
        else if (strcmp(capturando, "BUSCAR LABORATORISTA") == 0)
        {
            printf("\n[1] BUSQUEDA POR CEDULA\t[2] BUSQUEDA POR CORREO\t [3] BUSQUEDA POR NOMBRE : ");
        }
        else if (strcmp(capturando, "CONFIRMAR REGISTRO REALIZAR") == 0)
        {
            printf("\n[1] REGISTRAR RESULTADOS\t[2] DESCARTAR REGISTRO : ");
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
            conn2 = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //ABRO CONEXION 2
            sprintf(sql, "update pacientes set estado_p = true where folio_p = %d;", folio);
            res = PQexec(conn2, sql);
            if (PQresultStatus(res) == PGRES_COMMAND_OK)
            {
                printf(ANSI_COLOR_GREEN "Se ha actualizado el estado del paciente de manera exitosa\n" ANSI_COLOR_RESET);
            }
            else
            {
                printf(ANSI_COLOR_RED "No se ha podido actualizar el estado del paciente\n" ANSI_COLOR_RESET);
            }
            PQfinish(conn2); //CIERRO CONEXION 2
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

                conn3 = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //ABRO CONEXION 3
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
    int opc_busqueda, opc_nombre2, cedula;
    char sql[600];
    struct
    {
        char *cedula;
        char *nombre1;
        char *nombre2;
        char *apellido1;
        char *apellido2;
        char *correo;
    } laboratorista[1];
    laboratorista[0].correo = malloc(tamano_maloc);
    laboratorista[0].cedula = malloc(tamano_maloc);
    laboratorista[0].nombre1 = malloc(tamano_maloc);
    laboratorista[0].nombre2 = malloc(tamano_maloc);
    laboratorista[0].apellido1 = malloc(tamano_maloc);
    laboratorista[0].apellido2 = malloc(tamano_maloc);
    laboratorista[0].nombre2 = strdup("null");

    printf("|-----------------BUSCAR LABORATORISTA-----------------|\n");
    opc_busqueda = pedir_tres_opciones("BUSCAR LABORATORISTA");
    switch (opc_busqueda)
    {
    case 1:
        printf("\nINGRESE UN VALOR PARA EL CAMPO [CEDULA] : "); //PEDIMOS CORREO
        scanf("%s", laboratorista[0].cedula);
        //GENERAMOS LA CONSULTA
        sprintf(sql, "select cedula_lab, nom_lab, sexo_lab, correo, fecha_contratacion from laboratoristas where estado_lab = true and cedula_lab ~* '^%s$';", laboratorista[0].cedula); //comparar cadenas usar expresion regular
        imprimir_laboratoristas(sql);                                                                                                                                                    //HACER LA BUSQUEDA E IMPRIMIR
        break;
    case 2:
        printf("\nINGRESE UN VALOR PARA EL CAMPO [CORREO] : "); //PEDIMOS CORREO
        scanf("%s", laboratorista[0].correo);

        //GENERAMOS LA CONSULTA
        sprintf(sql, "select cedula_lab, nom_lab, sexo_lab, correo, fecha_contratacion from laboratoristas where estado_lab = true and correo ~* '^%s$';", laboratorista[0].correo);
        imprimir_laboratoristas(sql); //HACER LA BUSQUEDA Y IMPRIMIR

        break;

    case 3:
        laboratorista[0].nombre1 = pedir_cadena("NOMBRE"); //PEDIMOS NOMBRE

        opc_nombre2 = pedir_dos_opciones("SEGUNDO NOMBRE");            //SABER SI TIENE SEGUNDO NOMBRE
        if (opc_nombre2 == 1)                                          //SI TIENE SEGUNDO NOMBRE
        {                                                              //HAY QUE PEDIR SEGUNDO NOMBRE
            laboratorista[0].nombre2 = pedir_cadena("SEGUNDO NOMBRE"); //PEDIMOS SEGUNDO NOMBRE
        }
        laboratorista[0].apellido1 = pedir_cadena("PRIMER APELLIDO"); //PEDIMOS PRIMER APELLIDO

        laboratorista[0].apellido2 = pedir_cadena("SEGUNDO APELLIDO"); //PEDIMOS SEGUNDO APELLIDO

        if ((strcmp(laboratorista[0].nombre2, "null") == 0))
        { //NO TIENE SEGUNDO NOMBRE
            sprintf(sql, "select cedula_lab, nom_lab, sexo_lab, correo, fecha_contratacion from laboratoristas where estado_lab= true and nom_lab ~* '^%s %s %s$';", laboratorista[0].nombre1, laboratorista[0].apellido1, laboratorista[0].apellido2);
        }
        else
        {
            sprintf(sql, "select cedula_lab, nom_lab, sexo_lab, correo, fecha_contratacion from laboratoristas where estado_lab = true and nom_lab ~* '^%s %s %s %s$';", laboratorista[0].nombre1, laboratorista[0].nombre2, laboratorista[0].apellido1, laboratorista[0].apellido2);
        }
        imprimir_laboratoristas(sql); //HACER LA BUSQUEDA E IMPRIMIR
        break;
    }

    printf("---------------------------------------------------\n\n\n");
}

void imprimir_laboratoristas(char sql[600])
{

    conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //CREAMOS LA CONEXION

    system("clear");

    if (PQstatus(conn) != CONNECTION_BAD)
    {
        res = PQexec(conn, sql);
        if (res != NULL && PQntuples(res) != 0)
        { //SE ENCONTRARON PACIENTES
            printf("---------------------------------------------------\n");
            printf("\tLABORATORISTA ENCONTRADO\n");
            printf("---------------------------------------------------\n\n");
            //SE IMPRIMEN LOS PACIENTES ENCONTRADOS
            for (int i = 0; i < PQntuples(res); i++)
            {
                for (int j = 0; j < PQnfields(res); j++) //hay 5 campos
                {
                    switch (j)
                    {
                    case 0:
                        printf("     - > CEDULA : ");
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
                        printf("     - > CORREO : ");
                        printf(ANSI_COLOR_BLUE "%s\n\n" ANSI_COLOR_RESET, PQgetvalue(res, i, j));
                        break;
                    case 4:
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
            printf(ANSI_COLOR_RED "No se ha encontrado el laboratorista\n" ANSI_COLOR_RESET);
        }
    }
    else
    {
        printf("No conecto esta mierda\n");
    }

    PQfinish(conn); //FINALIZAMOS LA CONEXION
}
void despedir_laboratoristas()
{
    printf("|--------------DESPEDIR LABORATORISTA--------------|\n");
    char* cedula = malloc(tamano_maloc);
    char sql[600];
    printf("\nINGRESE UN VALOR PARA EL CAMPO [CEDULA LABORATORISTA A ELIMINAR] : "); //PEDIMOS CEDULA
    scanf("%s", cedula);
    
    sprintf(sql, "select cedula_lab from laboratoristas where estado_lab = true and cedula_lab ~* '^%s$';", cedula); //comparar cadenas usar expresion regular
    
    system("clear");
    conn5 = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //CREAMOS LA CONEXION
    if (PQstatus(conn5) != CONNECTION_BAD)
    {
        res = PQexec(conn5, sql);
        if (res != NULL && PQntuples(res) != 0)
        { //SE ENCONTRÓ LABORATORISTA
            strcpy(cedula, PQgetvalue(res, 0, 0));//GUARDO LA CEDULA EN MAYUSCULAS
            sprintf(sql, "select f_baja_laboratoristas('%s');",cedula);
            int despedir = consulta_rapida_enteros(sql);
            if(despedir == 0){
                printf(ANSI_COLOR_RED "El laboratorista no puede ser despedido aun, debe terminar con sus pendientes\n" ANSI_COLOR_RESET);
            }
            else{
                printf(ANSI_COLOR_GREEN "El laboratorista ha sido despedido exitosamente\n" ANSI_COLOR_RESET);
            }
            
        }
        else
        { //NO SE ENCONTRÓ LABORATORISTA
            printf(ANSI_COLOR_RED "No se ha encontrado el laboratorista\n" ANSI_COLOR_RESET);
        }
        PQclear(res);
    }
    PQfinish(conn5);

    
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
    printf("\n[8] VER CATALOGO ANALISIS");
    printf("\n[9] BAJA ANALISIS DEL CATALOGO");
    printf("\n[10] VOLVER AL MENU PRINCIPAL");
    printf("\n---------------------------------------------------\n");
    printf("Ingrese la opcion deseada : ");
    scanf("%s", opc);
    return opc;
}
int seleccionar_analisis_del_catalogo()
{
    int salir, opc_analisis;
    do
    { //CICLO PARA IMPRIMIR LOS NUMERO DE ATRIBUTO
        conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1");
        printf("\n|---------SELECCIONAR ANALISIS A REALIZAR---------|\n");
        //--------------------------------------------------------------------IMPRIMIR LOS ANALISIS DISPONIBLES
        if (PQstatus(conn) != CONNECTION_BAD)
        {
            res = PQexec(conn, "select num_a, nom_a from analisis where estado_a=true;");
            if (res != NULL && PQntuples(res) != 0)
            {
                for (int i = 0; i < PQntuples(res); i++)
                {
                    printf("[%s] %s\n", PQgetvalue(res, i, 0), PQgetvalue(res, i, 1)); //IMPRIMIR ANALISIS ENCONTRADO
                }
            }
            PQclear(res);
        }
        PQfinish(conn);
        //--------------------------------------------------------------------FIN IMPRIMIR LOS REACTIVOS DISPONIBLES
        opc_analisis = pedir_entero("NUMERO DE ANALISIS");  //SI LA OPCION NO ES CERO
        opc_analisis = ver_si_algo_existe(4, opc_analisis); //CHECAR SI EXISTE
        if (opc_analisis != -1)                             //SI EL VALOR EXISTE
        {                                                   //puts("existe");
            salir = 1;                                      //SI SALIR VALE UNO SALE DEL CICLO
        }
        else
        {
            salir = 0;
            printf(ANSI_COLOR_RED "\nEl valor ingresado no corresponde a ningun numero de analisis disponible\n" ANSI_COLOR_RESET);
        }
    } while (salir != 1); //FIN CICLO INGRESAR VALORES CORRECTOS

    return opc_analisis;
}
int ver_si_cadena_existe(int opc, char cadena[200])
{
    int devolver;
    char sql[600];
    char *var = malloc(200);
    conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //ESTABLESCO UNA CONEXION
    if (PQstatus(conn) != CONNECTION_BAD)
    {
        switch (opc)
        {
        case 1: //LABORATORISTAS
            sprintf(sql, "select cedula_lab from laboratoristas where cedula_lab ~* '^%s$' and estado_lab = true;", cadena);
            break;
        }
        //printf("%s\n",sql);
        res = PQexec(conn, sql);                //EJECUTA LA INSTRUCCION
        if (res != NULL && PQntuples(res) != 0) //SI EL SELECT DEVOLVIÓ ALGO
        {                                       //SI ENCONTRÓ ALGO
            var = PQgetvalue(res, 0, 0);        //OBTIENE EL CODIGO DE BARRAS DEL MATERIAL
            //printf("cadena: %s\n",var);
            devolver = 1;
        }
        else
        {
            devolver = -1;
        }
    }
    PQfinish(conn); //CIERRO LA CONEXION
    //printf("devolvió: %d\n",devolver);
    return devolver;
}
char *seleccionar_laboratorista_para_analisis()
{
    int salir, opc_lab;
    char *cedula = malloc(tamano_maloc);
    do
    { //CICLO PARA IMPRIMIR LOS NUMERO DE ATRIBUTO
        conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1");
        printf("\n|--SELECCIONAR AL LABORATORISTA QUE LLEVARA A CABO EL ANALISIS--|\n");
        //--------------------------------------------------------------------IMPRIMIR LOS LABORATORISTAS DISPONIBLES
        if (PQstatus(conn) != CONNECTION_BAD)
        {
            res = PQexec(conn, "select cedula_lab, nom_lab from laboratoristas where estado_lab=true;");
            if (res != NULL && PQntuples(res) != 0)
            {
                for (int i = 0; i < PQntuples(res); i++)
                {
                    printf("[%s] %s\n", PQgetvalue(res, i, 0), PQgetvalue(res, i, 1)); //IMPRIMIR LABORATORISTAS ENCONTRADOS
                }
            }
            PQclear(res);
        }
        PQfinish(conn);
        //--------------------------------------------------------------------FIN IMPRIMIR LOS LABORATORISTAS DISPONIBLES
        printf("\nINGRESE UN VALOR PARA EL CAMPO [CEDULA] : ");
        scanf("%s", cedula);                       //SI LA OPCION NO ES CERO
        opc_lab = ver_si_cadena_existe(1, cedula); //CHECAR SI EXISTE
        if (opc_lab != -1)                         //SI EL VALOR EXISTE
        {                                          //puts("existe");
            salir = 1;                             //SI SALIR VALE UNO SALE DEL CICLO
        }
        else
        {
            salir = 0;
            printf(ANSI_COLOR_RED "\nEl valor ingresado no corresponde a ninguna cedula de algun laboratorista\n" ANSI_COLOR_RESET);
        }
    } while (salir != 1); //FIN CICLO INGRESAR VALORES CORRECTOS

    system("clear");
    printf(ANSI_COLOR_GREEN "Se ha seleccionado el laboratorista correctamente\n" ANSI_COLOR_RESET);
    return cedula;
}
void solicitar_analisis()
{
    printf("|----------------SOLICITAR ANALISIS----------------|\n");
    int num_catalogos_analisis = consulta_rapida_enteros("select count(num_a) from analisis where estado_a=true;");

    if (num_catalogos_analisis == 0)
    { //SI NO HAY ANALISIS DISPONIBLES
        printf(ANSI_COLOR_RED "No hay analisis disponibles, por favor añada un nuevo analisis antes\n" ANSI_COLOR_RESET);
    }
    else
    { //SI ENTRA AL ELSE QUIERE DECIR QUE SI HAY ANALISIS DISPONIBLES
        int num_pacientes = consulta_rapida_enteros("select count(folio_p) from pacientes where estado_p=true;");
        int num_laboratoristas = consulta_rapida_enteros("select count(cedula_lab) from laboratoristas where estado_lab=true;");

        if (num_pacientes == 0 && num_laboratoristas == 0)
        { //SI NO HAY PACIENTES NI LABORATORISTAS
            printf(ANSI_COLOR_RED "No hay pacientes y laboratoristas para solicitar un analisis, por favor añadalos antes\n" ANSI_COLOR_RESET);
        }
        else if (num_laboratoristas == 0)
        { //SI NO HAY LABORATORISTAS
            printf(ANSI_COLOR_RED "No hay laboratoristas para solicitar un analisis, añada laboratoristas antes\n" ANSI_COLOR_RESET);
        }
        else if (num_pacientes == 0)
        { //SI NO HAY PACIENTES
            printf(ANSI_COLOR_RED "No hay pacientes para solicitar un analisis, por favor añada pacientes antes\n" ANSI_COLOR_RESET);
        }
        else
        { //SI ENTRA AL ELSE QUIERE DECIR QUE SI HAY LABORATORISTAS Y PACIENTES
            char *correo_dado = malloc(tamano_maloc);
            char sql[600];
            char *folio_cadena = malloc(tamano_maloc);
            int folio_paciente, num_analisis;
            char *cedula = malloc(tamano_maloc);

            //SE PIDE EL CORREO DEL PACIENTE
            printf("INGRESE UN VALOR PARA EL CAMPO [CORREO] : ");
            scanf("%s", correo_dado);

            conn2 = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //CREAMOS CONEXION 1

            if (PQstatus(conn2) != CONNECTION_BAD)
            {
                sprintf(sql, "select folio_p from pacientes where correo ~* '^%s$';", correo_dado);
                res = PQexec(conn2, sql);
                if (res != NULL && PQntuples(res) != 0) //SI SE ENCONTRÓ EN EL SISTEMA
                {
                    //SE IMPRIME SU FOLIO
                    for (int i = 0; i < PQntuples(res); i++)
                    {
                        for (int j = 0; j < PQnfields(res); j++)
                        {
                            folio_cadena = PQgetvalue(res, i, j); //SE OBTIENE SU FOLIO DEL PACIENTE
                            folio_paciente = atoi(folio_cadena);  // SE CONVIERTE EL FOLIO A ENTERO
                            system("clear");
                            printf(ANSI_COLOR_GREEN "Se ha encontrado el correo en el sistema\n" ANSI_COLOR_RESET);
                            printf("     - > FOLIO DEL PACIENTE : %d\t\n\n", folio_paciente); //SE IMPRIME SU FOLIO DEL PACIENTE
                        }
                        PQclear(res);
                    }

                    //SELECCIONAR EL ANALISIS A REALIZAR
                    num_analisis = seleccionar_analisis_del_catalogo();
                    sprintf(sql, "select ver_si_hay_recursos_para_analisis(%d);",num_analisis);
                    int continuar = consulta_rapida_enteros(sql);
                        system("clear");
                    if(continuar == 0){
                        printf(ANSI_COLOR_RED "No hay recursos suficientes para llevar a cabo el analisis\n" ANSI_COLOR_RESET);
                    }
                    else{
                        printf(ANSI_COLOR_GREEN "Se ha seleccionado el analisis correctamente\n" ANSI_COLOR_RESET);

                        //SELECCIONAR LABORATORISTA
                        cedula = seleccionar_laboratorista_para_analisis();

                        int ultimo_analisis = consulta_rapida_enteros("select count(folio_a) from historial_clinico;");
                        int analisis_a_insertar;
                        if (ultimo_analisis == 0)
                        {
                            analisis_a_insertar = 1;
                        }
                        else
                        {
                            analisis_a_insertar = consulta_rapida_enteros("select max(folio_a) from historial_clinico;");
                            analisis_a_insertar++;
                        }

                        sprintf(sql, "select nom_p from pacientes where folio_p = %d;", folio_paciente);
                        char *nom_paciente = malloc(tamano_maloc);
                        strcpy(nom_paciente, consulta_rapida_cadenas(sql));
                       //printf("%s\n",sql);

                        sprintf(sql, "select nom_lab from laboratoristas where cedula_lab ~* '^%s$';", cedula);
                        char *nom_lab = malloc(tamano_maloc);
                        strcpy(nom_lab, consulta_rapida_cadenas(sql));
                        //nom_lab = consulta_rapida_cadenas(sql);

                        sprintf(sql, "select nom_a from analisis where num_a = %d;", num_analisis);
                        //printf("%s\n", sql);
                        char *nom_analisis = malloc(tamano_maloc);
                        strcpy(nom_analisis, consulta_rapida_cadenas(sql));

                        //IMPRIMIR LOS VALORES CAPTURADOS
                        //system("clear");
                        printf("---------------------------------------------------\n");
                        printf("\tDATOS RECOPILADOS\n");
                        printf("---------------------------------------------------\n");
                        printf("     - > FOLIO DEL PACIENTE: %d\n", folio_paciente);
                        printf("     - > NOMBRE DEL PACIENTE: %s\n", nom_paciente);
                        printf("     - > NUMERO DE ANALISIS A REALIZAR: %d\n", num_analisis);
                        printf("     - > NOMBRE DEL ANALISIS A REALIZAR: %s\n", nom_analisis);
                        printf("     - > CEDULA DEL LABORATORISTA: %s\n", cedula);
                        printf("     - > NOMBRE DEL LABORATORISTA: %s\n", nom_lab);
                        printf("---------------------------------------------------");

                        int opc_confirmacion = pedir_dos_opciones("CONFIRMAR REGISTRO ANALISIS");
                        system("clear");
                        if (opc_confirmacion == 1)
                        { //INSERTAMOS
                            sprintf(sql, "insert into historial_clinico (folio_p, num_a, cedula_lab) values(%d, %d, UPPER('%s'));", folio_paciente, num_analisis, cedula);
                            //printf("%s\n",sql);
                            conn3 = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //ABRO CONEXION 3
                            if (PQstatus(conn3) != CONNECTION_BAD)
                            {
                                res = PQexec(conn3, sql);
                                if (PQresultStatus(res) == PGRES_COMMAND_OK)
                                {
                                    int ultimo_analisis = consulta_rapida_enteros("select max(folio_a) from historial_clinico;");
                                    printf(ANSI_COLOR_GREEN "Se ha registrado el analisis de manera exitosa, el folio es: %d\n" ANSI_COLOR_RESET, ultimo_analisis);
                                }
                                else
                                {
                                    printf(ANSI_COLOR_RED "No se ha podido registrar el analisis, notifique el error\n" ANSI_COLOR_RESET);
                                }
                            }
                            else
                            {
                                printf("No se logro la conexion con la base de datos\n");
                            }
                            sprintf(sql, "select inserta_inventarios(%d, %d);",analisis_a_insertar, num_analisis);
                            consulta_rapida_cadenas(sql);
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
                { //NO ENCONTRÓ EL CORREO EL PACIENTE
                    printf(ANSI_COLOR_RED "No se encontró el paciente\n" ANSI_COLOR_RESET);
                }
            }
            else
            {
                printf("Error de conexion a la base de datos\n");
            }
            PQfinish(conn2);
        }
    }
    printf("---------------------------------------------------\n\n\n");
}
void ejecutar_consulta(char sql[600])
{
    conn2 = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1");
    if (PQstatus(conn2) != CONNECTION_BAD)
    {
        res2 = PQexec(conn2, sql);
    }
    else
    {
        printf("La conexion no fue posible\n");
    }

    PQfinish(conn2);
}
void realizar_analisis()
{
    printf("|----------------REALIZAR  ANALISIS----------------|\n");
    int num_analisis_solicitados = consulta_rapida_enteros("select count(folio_a) from historial_clinico where status = 1;");
    if (num_analisis_solicitados == 0)
    { //SI NO HAY ANALISIS PENDIENTES
        printf(ANSI_COLOR_RED "No hay analisis pendientes\n" ANSI_COLOR_RESET);
    }
    else
    { //SI ENTRA AL ELSE QUIERE DECIR QUE SI HAY ANALISIS PARA INGRESAR SUS RESULTADOS
        int folio_analisis_a_realizar = pedir_entero("FOLIO DEL ANALISIS");
        folio_analisis_a_realizar = ver_si_algo_existe(5, folio_analisis_a_realizar);
        char sql[600];

        if (folio_analisis_a_realizar == -1)
        { //EL ANALISIS NO EXISTE
            system("clear");
            printf(ANSI_COLOR_RED "EL analisis no encontrado\n" ANSI_COLOR_RESET);
        }
        else
        { //SI ENTRA AL ELSE QUIERE DECIR QUE EL ANALISIS HA SIDO LOCALIZADO Y SI ESTA SOLICITADO(1)
            sprintf(sql, "select num_a from historial_clinico where folio_a = %d;", folio_analisis_a_realizar);
            int tipo_analisis = consulta_rapida_enteros(sql);

            //EMPEZAR A PEDIR LOS RESULTADOS--------------------------------------------------------------------
            conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1");
            sprintf(sql, "select atributos.num_atri, atributos.nom_atri, det_a_atributos.cons_det_a_atributos from det_a_atributos inner join atributos on det_a_atributos.num_atri = atributos.num_atri and det_a_atributos.num_a = %d order by det_a_atributos.cons_det_a_atributos;", tipo_analisis);

            if (PQstatus(conn) != CONNECTION_BAD)
            {
                res = PQexec(conn, sql);
                if (res != NULL && PQntuples(res) != 0)
                {
                    system("clear");
                    printf("|--------------REGISTRO DE RESULTADOS--------------|\n");

                    float resultado;
                    for (int i = 0; i < PQntuples(res); i++)
                    { //REGISTRAR LOS RESULTADOS DE LOS ATRIBUTOS UNO POR UNO
                        printf("\n[%s] %s\n", PQgetvalue(res, i, 0), PQgetvalue(res, i, 1));
                        resultado = pedir_decimal("VALOR DEL ATRIBUTO");
                        sprintf(sql, "insert into resultados (folio_a, cons_resultados, resultado, num_a, cons_det_a_atributos, num_atri) values(%d, %s, %f, %d, %s, %s);", folio_analisis_a_realizar, PQgetvalue(res, i, 2), resultado, tipo_analisis, PQgetvalue(res, i, 2), PQgetvalue(res, i, 0));

                        //INSERTAR--------------------------------------------------------
                        conn2 = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1");
                        if (PQstatus(conn2) != CONNECTION_BAD)
                        {
                            res2 = PQexec(conn2, sql);
                            if (PQresultStatus(res2) == PGRES_COMMAND_OK)
                            {
                                //printf(ANSI_COLOR_GREEN "Resultado ingresado correctamente\n" ANSI_COLOR_RESET);
                            }
                            else
                            {
                                printf(ANSI_COLOR_RED "No se ha podido ingresar el resultado, notifique el error\n" ANSI_COLOR_RESET);
                            }
                        }
                        else
                        {
                            printf("La conexion no fue posible\n");
                        }

                        PQfinish(conn2);
                        //----------------------------------------------------------FIN INSERTAR
                    }
                    PQclear(res);
                }
            }
            PQfinish(conn);

            //IMPRIMIR LOS DATOS RECOPILADOS
            system("clear");
            printf("---------------------------------------------------\n");
            printf("\tDATOS RECOPILADOS\n");
            printf("---------------------------------------------------\n");
            printf("     - > FOLIO DEL ANALISIS: %d\n", folio_analisis_a_realizar);
            printf("     - > NUMERO DE ANALISIS: %d\n", tipo_analisis);
            sprintf(sql, "select nom_a from analisis where num_a = %d;", tipo_analisis);
            printf("     - > NOMBRE DEL ANALISIS: %s\n", consulta_rapida_cadenas(sql));
            printf("---------------------------------------------------");
            printf("\n\tRESULTADOS\n");
            printf("---------------------------------------------------\n");
            sprintf(sql, "select atributos.num_atri, atributos.nom_atri, resultados.resultado from atributos inner join resultados on resultados.num_atri = atributos.num_atri and resultados.folio_a = %d;", folio_analisis_a_realizar);

            conn3 = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1");
            if (PQstatus(conn3) != CONNECTION_BAD)
            {
                res = PQexec(conn3, sql);
                if (res != NULL && PQntuples(res) != 0)
                {
                    for (int i = 0; i < PQntuples(res); i++)
                    {
                        printf("[%s] %s : %s\n", PQgetvalue(res, i, 0), PQgetvalue(res, i, 1), PQgetvalue(res, i, 2));
                    }
                    PQclear(res);

            printf("---------------------------------------------------\n");
                }
            }
            else
            {
                puts("La conexion a la base de datos no fue posible");
            }
            PQfinish(conn3);

            int opc_confirmacion = pedir_dos_opciones("CONFIRMAR REGISTRO REALIZAR");
            system("clear");
            if (opc_confirmacion == 1)
            { //SI CONFIRMA SOLAMENTE ACTUALIZAMOS EL ESTADO DEL ANALISIS
                sprintf(sql, "update historial_clinico set status = 2 where folio_a = %d;",folio_analisis_a_realizar);
                ejecutar_consulta(sql);
                printf(ANSI_COLOR_GREEN "Los resultados se han ingresado correctamente\n" ANSI_COLOR_RESET);
            }
            else
            { //SI DESCARTA BORRAMOS LOS RESULTADOS QUE INSERTAMOS
                sprintf(sql, "delete from resultados where folio_a = %d;",folio_analisis_a_realizar);
                ejecutar_consulta(sql);
                printf(ANSI_COLOR_RED "CANCELADO\n" ANSI_COLOR_RESET);
            }
        }
    }

    printf("---------------------------------------------------\n\n\n");
}

void imprimir_resultados(int folio_a){
    char sql[600], sql2[600];
    sprintf(sql2, "select analisis.nom_a from analisis inner join historial_clinico on historial_clinico.num_a = analisis.num_a and historial_clinico.folio_a = %d;", folio_a);
    
    char* nombre = malloc(tamano_maloc);
    nombre = consulta_rapida_cadenas(sql2);
    system("clear");
    puts("-----------------------------------------------------");
    printf("\tRESULTADOS DEL ANALISIS: %s\n", nombre);   
    puts("-----------------------------------------------------");
    sprintf(sql, "select resultados.cons_resultados num_resultado, atributos.nom_atri, atributos.min, atributos.max, resultados.resultado  from atributos inner join resultados on resultados.num_atri = atributos.num_atri and resultados.folio_a = %d;",folio_a);

    conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1");

    if (PQstatus(conn) != CONNECTION_BAD){
        res = PQexec(conn, sql);
        if(res != NULL && PQntuples(res) != 0){
            for (int i = 0; i < PQntuples(res); i++)
            {
                printf("[%s] %s : %s (%s - %s)\n",PQgetvalue(res, i, 0), PQgetvalue(res, i, 1), PQgetvalue(res, i, 4), PQgetvalue(res, i, 2), PQgetvalue(res, i, 3));
            }
        }
        PQclear(res);
    }
    else{
        puts("La conexion a la base de datos no fué posible");
    }
    PQfinish(conn);

}
void entregar_analisis()
{
    printf("|----------------ENTREGAR  ANALISIS----------------|\n");
    int num_analisis_realizados;

    num_analisis_realizados = consulta_rapida_enteros("select count (folio_a) from historial_clinico where status = 2;");

    if(num_analisis_realizados == 0){
        printf(ANSI_COLOR_RED "No hay analisis por entregar\n" ANSI_COLOR_RESET);
    }
    else{//SI ENTRA AL ELSE QUIERE DECIR QUE SI HAY ANALISIS POR ENTREGAR
        char sql[600];
        int folio_a = pedir_entero("FOLIO DEL ANALISIS A ENTREGAR");
        folio_a = ver_si_algo_existe(6, folio_a);
        if(folio_a == -1){
            system("clear");
            printf(ANSI_COLOR_RED "El folio del analisis no es correcto, asegurese de que no haya sido entregado o sea el folio sea correcto\n" ANSI_COLOR_RESET);
        }
        else{//SI ENTRA AL ELSE QUIERE DECIR QUE EL ANALISIS ESTA LISTO PARA SER ENTREGADO
            imprimir_resultados(folio_a);
            sprintf(sql, "update historial_clinico set status = 3 where folio_a = %d;",folio_a);
            insertar(sql);//ACTUALIZAMOS EL STATUS A ENTREGADO
        printf("---------------------------------------------------\n\n");
            printf(ANSI_COLOR_GREEN "El analisis ha sido entregado correctamente\n" ANSI_COLOR_RESET);
            
        }
    }
    printf("---------------------------------------------------\n\n\n");
}

void insertar(char sql[600]){
    conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1");
    if(PQstatus(conn) != CONNECTION_BAD){
        res = PQexec(conn, sql);
        PQclear(res);
    }
    else{
        puts("La conexion a la base de datos no ha sido posible");
    }
    PQfinish(conn);
}
void buscar_analisis()
{
    printf("|-----------------BUSCAR  ANALISIS-----------------|\n");
    int n_analisis = consulta_rapida_enteros("select count(folio_a) from historial_clinico;");

    if(n_analisis == 0){
        printf(ANSI_COLOR_RED "No hay ningun analisis para buscar\n" ANSI_COLOR_RESET);
    }
    else{//SI ENTRA EL ELSE QUIERE DECIR QUE HAY UNO O MÁS ANALISIS

        int folio_a = pedir_entero("FOLIO DEL ANALISIS");//PEDIR FOLIO DEL ANALISIS
        folio_a = ver_si_algo_existe(7, folio_a);
        if(folio_a == -1){//SI EL ANALISIS NO EXISTE
            system("clear");
            printf(ANSI_COLOR_RED "El folio ingresado no existe\n" ANSI_COLOR_RESET);
        }else{//SI ENTRA AL ELSE QUIERE DECIR QUE SI EXISTE EL ANALISIS

            char sql[600];
            //IMPRIMIR DATOS DEL ANALISIS
            system("clear");
            sprintf(sql, "select * from v_buscar_analisis where folio_a = %d;", folio_a);

            //---------------IMPRIMIR
            conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //CREAMOS LA CONEXION
            
            if (PQstatus(conn) != CONNECTION_BAD)
            {
                res = PQexec(conn, sql);
                if (res != NULL && PGRES_TUPLES_OK == PQresultStatus(res))
                {
                    printf("---------------------------------------------------\n");
                    printf("\tANALISIS ENCONTRADO\n");
                    printf("---------------------------------------------------\n\n");
                    int i = 0;
                    for (int j = 0; j < PQnfields(res); j++)
                    {
                        switch (j)
                        {
                        case 0: printf("\t - > FOLIO ANALISIS : "); printf(ANSI_COLOR_BLUE "%s\n\n" ANSI_COLOR_RESET,PQgetvalue(res, i, j));
                            break;
                        case 1: printf("\t - > FOLIO PACIENTE : "); printf(ANSI_COLOR_BLUE "%s\n\n" ANSI_COLOR_RESET,PQgetvalue(res, i, j));
                            break;
                        case 2: printf("\t - > NOMBRE PACIENTE : "); printf(ANSI_COLOR_BLUE "%s\n\n" ANSI_COLOR_RESET,PQgetvalue(res, i, j));
                            break;
                        case 3: printf("\t - > NUMERO ANALISIS : "); printf(ANSI_COLOR_BLUE "%s\n\n" ANSI_COLOR_RESET,PQgetvalue(res, i, j));
                            break;
                        case 4: printf("\t - > NOMBRE ANALISIS : "); printf(ANSI_COLOR_BLUE "%s\n\n" ANSI_COLOR_RESET,PQgetvalue(res, i, j));
                            break;
                        case 5: printf("\t - > CEDULA LABORATORISTA : "); printf(ANSI_COLOR_BLUE "%s\n\n" ANSI_COLOR_RESET,PQgetvalue(res, i, j));
                            break;
                        case 6: printf("\t - > NOMBRE LABORATORISTA : "); printf(ANSI_COLOR_BLUE "%s\n\n" ANSI_COLOR_RESET,PQgetvalue(res, i, j));
                            break;
                        case 7: printf("\t - > STATUS : "); printf(ANSI_COLOR_BLUE "%s\n\n" ANSI_COLOR_RESET,PQgetvalue(res, i, j));
                            break;
                        case 8: printf("\t - > FECHA SOLICITUD : "); printf(ANSI_COLOR_BLUE "%s\n\n" ANSI_COLOR_RESET,PQgetvalue(res, i, j));
                            break;
                        case 9: printf("\t - > FECHA REALIZACION : "); printf(ANSI_COLOR_BLUE "%s\n\n" ANSI_COLOR_RESET,PQgetvalue(res, i, j));
                            break;
                        case 10: printf("\t - > FECHA ENTREGA: "); printf(ANSI_COLOR_BLUE "%s\n\n" ANSI_COLOR_RESET,PQgetvalue(res, i, j));
                            break;
                        }
                    }
                    
                    PQclear(res);
                }
            }
            PQfinish(conn);
            //-----------FIN IMPRIMIR
        }
    }
    printf("---------------------------------------------------\n\n\n");
}
void consultas_analisis()
{
    int opc_consulta;
    char sql[600];
    printf("|-----------------CONSULTA ANÁLISIS-----------------|\n");
    opc_consulta = pedir_tres_opciones("OPCIÓN DE ANÁLISIS");

    switch (opc_consulta)
    {
        int num_analisis;
    case 1:
         num_analisis = consulta_rapida_enteros("select count(folio_a) from historial_clinico where status = 1;");
        system("clear");
        printf("---------------------------------------------------\n");
        printf("\tANÁLISIS SOLICITADOS\n");
        printf("---------------------------------------------------\n");
        if(num_analisis == 0){
            puts(ANSI_COLOR_RED "No hay analisis solicitados\n" ANSI_COLOR_RESET);
        }
        else{
            puts(ANSI_COLOR_BLUE "FOLIO ANALISIS\tFOLIO PACIENTE\tNUMERO ANALISIS\t\tFECHA\t\tCEDULA LABORATORISTA" ANSI_COLOR_RESET);
            sprintf(sql, "select folio_a, folio_p, num_a,fecha_solicitud, cedula_lab  from historial_clinico where status = 1;");
            hacer_select_analisis(sql); //HACER SELECT E IMPRIMIR
        }
        break;

    case 2:
        num_analisis = consulta_rapida_enteros("select count(folio_a) from historial_clinico where status = 2;");

        system("clear");
        printf("---------------------------------------------------\n");
        printf("\tANÁLISIS REALIZADOS\n");
        printf("---------------------------------------------------\n");

        if(num_analisis == 0){
            puts(ANSI_COLOR_RED "No hay analisis realizados\n" ANSI_COLOR_RESET);
        }
        else{
            puts(ANSI_COLOR_BLUE "FOLIO ANALISIS\tFOLIO PACIENTE\tNUMERO ANALISIS\t\tFECHA\t\tCEDULA LABORATORISTA" ANSI_COLOR_RESET);
            sprintf(sql, "select folio_a, folio_p, num_a,fecha_solicitud, cedula_lab  from historial_clinico where status = 2;");
            hacer_select_analisis(sql); //HACER SELECT E IMPRIMIR
        }
        break;

    case 3:
        num_analisis = consulta_rapida_enteros("select count(folio_a) from historial_clinico where status = 3;");
        system("clear");
        printf("---------------------------------------------------\n");
        printf("\tANÁLISIS ENTREGADOS\n");
        printf("---------------------------------------------------\n");

        if(num_analisis == 0){
            puts(ANSI_COLOR_RED "No hay analisis entregados\n" ANSI_COLOR_RESET);
        }
        else{
            puts(ANSI_COLOR_BLUE "FOLIO ANALISIS\tFOLIO PACIENTE\tNUMERO ANALISIS\t\tFECHA\t\tCEDULA LABORATORISTA" ANSI_COLOR_RESET);
            sprintf(sql, "select folio_a, folio_p, num_a,fecha_solicitud, cedula_lab  from historial_clinico where status = 3;");
            hacer_select_analisis(sql); //HACER SELECT E IMPRIMIR
        }
        break;
    }

    printf("---------------------------------------------------\n\n\n");
}

void hacer_select_analisis(char sql[600])
{
    int i, j;
    conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //CREAMOS LA CONEXION
    if (PQstatus(conn) != CONNECTION_BAD)
    {
        res = PQexec(conn, sql);
        if (res != NULL && PGRES_TUPLES_OK == PQresultStatus(res))
        {
            for (i = 0; i < PQntuples(res); i++)
            {
                for (j = 0; j < PQnfields(res); j++){
                    printf("\t%s\t", PQgetvalue(res, i, j));
                }
                    printf("\n");

            }
            PQclear(res);
        }
    }
    PQfinish(conn);
}
void pedir_reactivos_atributos(int num_atri)
{
    int salir, opc_reactivos, otro_reactivo;
    double cantidad_ocupada;
    char sql[600];
    do
    {
        do
        { //CICLO PARA IMPRIMIR LOS NUMERO DE ATRIBUTO
            conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1");
            printf("\n|----------AGREGAR REACTIVOS A ATRIBUTOS----------|\n");
            //--------------------------------------------------------------------IMPRIMIR LOS REACTIVOS DISPONIBLES
            if (PQstatus(conn) != CONNECTION_BAD)
            {
                res = PQexec(conn, "select codi_barra_r, nom_r from reactivos;");
                if (res != NULL && PQntuples(res) != 0)
                {
                    for (int i = 0; i < PQntuples(res); i++)
                    {
                        printf("[%s] %s\n", PQgetvalue(res, i, 0), PQgetvalue(res, i, 1)); //IMPRIMIR REACTIVO ENCONTRADO
                    }
                    printf("[0] CONTINUAR\n");
                }
                PQclear(res);
            }
            PQfinish(conn);
            //--------------------------------------------------------------------FIN IMPRIMIR LOS REACTIVOS DISPONIBLES
            opc_reactivos = pedir_entero("CODIGO DE BARRA DEL REACTIVO");

            if (opc_reactivos != 0)
            {                                                         //SI LA OPCION NO ES CERO
                opc_reactivos = ver_si_algo_existe(3, opc_reactivos); //CHECAR SI EXISTE
            }
            if (opc_reactivos != -1) //SI EL VALOR EXISTE
            {
                if (opc_reactivos != 0)
                {                                                         //SI ES 0 YA QUIERE SALIR, POR LO TANTO NO LE PIDE LA CANTIDAD OCUPADA
                    cantidad_ocupada = pedir_decimal("CANTIDAD OCUPADA"); //PEDIR CANTIDAD OCUPADA
                }
                salir = 1; //SI SALIR VALE UNO SALE DEL CICLO
            }
            else
            {
                salir = 0;
                printf(ANSI_COLOR_RED "\nEl valor ingresado no corresponde a ningun codigo de barra de algun reactivo disponible\n" ANSI_COLOR_RESET);
            }

        } while (salir != 1); //FIN CICLO INGRESAR VALORES CORRECTOS

        if (opc_reactivos != 0)
        {                                                                         //SI ELIGIÓ
            int repetido = ver_si_algo_esta_repetido(3, num_atri, opc_reactivos); //SABER SI ESTA REPETIDO, SI DEVUELVE -1 ESTA REPETIDO
            if (repetido != -1)
            { //SI ESTA REPETIDO
                printf(ANSI_COLOR_RED "\nEl reactivo no puede repetirse, intente con otro\n" ANSI_COLOR_RESET);
            }
            else
            { //SI NO ESTA REPETIDO, INSERTA
                //INICIO INSERTAR-----------------------------------------------------------------------------------------------------
                conn2 = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //CREO UNA CONEXION 1
                if (PQstatus(conn) != CONNECTION_BAD)
                {
                    sprintf(sql, "select max(cons_det_atributos) from Det_atributos where num_atri = %d;", num_atri);
                    int consecutivo_mas_actual = consulta_rapida_enteros(sql); //OBTENER EL CONSECUTIVO MAS ACTUAL
                    sprintf(sql, "insert into Det_atributos(num_atri, cons_det_atributos, codi_barra_r, cant_ocupada_r) values(%d, %d, %d, %lf);", num_atri, consecutivo_mas_actual + 1, opc_reactivos, cantidad_ocupada);
                    res = PQexec(conn2, sql);
                    if (PQresultStatus(res) == PGRES_COMMAND_OK) //PREGUNTA SI INSERTÓ
                    {
                        system("clear");
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
                PQfinish(conn2);
                //FIN INSERTAR---------------------------------------------------------------------------------------------------------
            }
        }

        otro_reactivo = opc_reactivos;
    } while (otro_reactivo != 0);
}
void confirmar_reactivos_atributos(int num_atri)
{
    char sql[600];

    sprintf(sql, "select num_atri, nom_atri, descrip_atri, min, max from atributos where num_atri = %d;", num_atri);

    system("clear");

    // IMPRIMIR DATOS DEL ATRIBUTO------------------------------------------------------------
    conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //CREAMOS LA CONEXION

    if (PQstatus(conn) != CONNECTION_BAD)
    {
        res = PQexec(conn, sql);
        if (res != NULL && PQntuples(res) != 0)
        { //SE ENCONTRÓ EL ATRIBUTO
            printf("---------------------------------------------------\n");
            printf("\tDATOS RECOPILADOS DEL ATRIBUTO A REGISTRAR\n");
            printf("---------------------------------------------------\n");
            //SE IMPRIMEN LOS PACIENTES ENCONTRADOS
            //for (int i = 0; i < PQntuples(res); i++)
            //{
            int i = 0;
            for (int j = 0; j < PQnfields(res); j++) //hay 5 campos
            {
                switch (j)
                {
                case 0:
                    printf("     - > NUMERO : ");
                    printf(ANSI_COLOR_BLUE "%s\n\n" ANSI_COLOR_RESET, PQgetvalue(res, i, j));
                    break;
                case 1:
                    printf("     - > NOMBRE : ");
                    printf(ANSI_COLOR_BLUE "%s\n\n" ANSI_COLOR_RESET, PQgetvalue(res, i, j));
                    break;
                case 2:
                    printf("     - > DESCRIPCION : ");
                    printf(ANSI_COLOR_BLUE "%s\n\n" ANSI_COLOR_RESET, PQgetvalue(res, i, j));
                    break;
                case 3:
                    printf("     - > VALOR MINIMO : ");
                    printf(ANSI_COLOR_BLUE "%s\n\n" ANSI_COLOR_RESET, PQgetvalue(res, i, j));
                    break;
                case 4:
                    printf("     - > VALOR MAXIMO : ");
                    printf(ANSI_COLOR_BLUE "%s\n\n" ANSI_COLOR_RESET, PQgetvalue(res, i, j));
                    break;
                }
            }
            PQclear(res);
            //}
        }
        else
        { //NO SE ENCONTRARON PACIENTES
            printf(ANSI_COLOR_RED "No se han encontrado pacientes\n" ANSI_COLOR_RESET);
        }
    }
    else
    {
        printf("La conexion no fue posible\n");
    }

    PQfinish(conn); //FINALIZAMOS LA CONEXION

    //FIN IMPRIMIR DATOS DEL ATRIBUTO-------------------------------------------------------

    sprintf(sql, "select det_atributos.codi_barra_r, reactivos.nom_r, det_atributos.cant_ocupada_r from det_atributos inner join reactivos on det_atributos.codi_barra_r = reactivos.codi_barra_r and det_atributos.num_atri = %d;", num_atri);

    //printf("%s\n",sql);
    //IMPRIMIR LOS REACTIVOS UTILIZADOS---------------------------------------
    conn2 = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //CREAMOS LA CONEXION 2

    if (PQstatus(conn2) != CONNECTION_BAD)
    {
        res = PQexec(conn2, sql);
        if (res != NULL && PGRES_TUPLES_OK == PQresultStatus(res))
        {
            printf("---------------------------------------------------\n");
            printf("\tREACTIVOS UTILIZADOS\n");
            printf("---------------------------------------------------\n");
            puts(ANSI_COLOR_BLUE "    COD_BARRA\tNOMBRE\t    CANTIDAD" ANSI_COLOR_RESET);
            for (int i = 0; i < PQntuples(res); i++)
            {
                printf("\t[%s]\t%s\t\t%s\n", PQgetvalue(res, i, 0), PQgetvalue(res, i, 1), PQgetvalue(res, i, 2));
            }
            PQclear(res);
            printf("---------------------------------------------------\n\n\n");
        }
    }
    else
    {
        printf("La conexion no fue posible\n");
    }
    PQfinish(conn2); //FINALIZAMOS LA CONEXION2
                     //FIN IMPRIMIR LOS REACTIVOS UTILIZADOS-------------------------------------------------

    //C O N F I R M A C I O N..........................................................
    int opc_confirmacion;

    opc_confirmacion = pedir_dos_opciones("CONFIRMAR REGISTRO ATRIBUTOS");
    system("clear");

    if (opc_confirmacion == 1) //SI DIJÓ QUE SI
    {
        printf(ANSI_COLOR_GREEN "Atributo registrado correctamente\n" ANSI_COLOR_RESET);
    }
    else
    { //INFORMAMOS QUE SE CANCELÓ Y ELIMINAMOS TODO LO INGRESADO

        //ELIMINAR LOS REACTIVOS DEL ATRIBUTO CANCELADO----------------------------------------------------------
        sprintf(sql, "delete from det_atributos where num_atri = %d;", num_atri);
        conn3 = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //CREAMOS LA CONEXION 3
        res = PQexec(conn3, sql);
        PQfinish(conn3);
        //FIN ELIMINAR REACTIVOS DEL ATRIBUTO CANCELADO

        //ELIMINAR EL ATRIBUTO CANCELADO-------------------------------------------------------------------------------
        sprintf(sql, "delete from atributos where num_atri = %d;", num_atri);
        conn4 = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //CREAMOS LA CONEXION 4
        res = PQexec(conn4, sql);
        PQfinish(conn4);
        //FIN ELIMINAR EL ATRIBUTO CANCELADO-----------------------------------------------------------------------------

        printf(ANSI_COLOR_RED "CANCELADO\n" ANSI_COLOR_RESET);
    }
    //F I N   C O N F I R M A CI O N....................................................
}
void agregar_atributos_analisis()
{
    char sql[600];
    printf("|----------AGREGAR ATRIBUTOS  DE ANALISIS----------|\n");

    int num_reactivos_disponibles = consulta_rapida_enteros("select count(codi_barra_r) from reactivos where estado_r=true;");
    if (num_reactivos_disponibles == 0)
    { //SI NO HAY REACTIVOS
        printf(ANSI_COLOR_RED "No hay atributos reactivos disponibles para agregar atributos, por favor añada reactivos antes\n" ANSI_COLOR_RESET);
    }
    else
    { //CUANDO ENTRA A ESTE ELSE QUIERE DECIR QUE SI HAY REACTIVOS
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

        atributos[0].nombre = pedir_cadena("NOMBRE"); //PEDIMOS NOMBRE

        printf("\nINGRESE UN VALOR PARA EL CAMPO [DESCRIPCION] : "); //PEDIMOS DESCRIPCION
        scanf("%s", atributos[0].descripcion);

        atributos[0].min = pedir_decimal("VALOR MINIMO DEL ATRIBUTO"); //PEDIMOS VALOR MINIMO

        atributos[0].max = pedir_decimal("VALOR MAXIMO DEL ATRIBUTO"); //PEDIMOS VALOR MAXIMO

        //INSERTAMOS
        { //REGISTRAMOS EL MATERIAL
            sprintf(sql, "insert into atributos (nom_atri, descrip_atri, min, max) values(UPPER('%s'), UPPER('%s'), %lf, %lf);", atributos[0].nombre, atributos[0].descripcion, atributos[0].min, atributos[0].max);
        }

        conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1");
        if (PQstatus(conn) != CONNECTION_BAD)
        {
            res = PQexec(conn, sql);
            if (PQresultStatus(res) == PGRES_COMMAND_OK)
            {
                PQfinish(conn);
                int num_atri = consulta_rapida_enteros("select max(num_atri) from atributos;"); //OBTENER EL ULTIMO ANALISIS INSERTADO

                pedir_reactivos_atributos(num_atri); //PEDIMOS LOS REACTIVOS QUE USA EL ATRIBUTO

                confirmar_reactivos_atributos(num_atri); //IMPRIMIR LO REGISTRADO Y CONFIRMAR
            }
            else
            {
                PQfinish(conn);
                printf(ANSI_COLOR_RED "No se ha podido registrar el atributo, notifique el error\n" ANSI_COLOR_RESET);
            }
        }
        else
        {
            printf("La conexion no fue posible\n");
        }
    }
    printf("---------------------------------------------------\n\n\n");
}
int ver_si_algo_existe(int opc, int algo)
{
    int devolver;
    char sql[600];
    conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //ESTABLESCO UNA CONEXION
    if (PQstatus(conn) != CONNECTION_BAD)
    {
        switch (opc)
        {
        case 1: //MATERIALES
            sprintf(sql, "select codi_barra_m from materiales where codi_barra_m = %d and estado_m = true;", algo);
            break;
        case 2: //ATRIBUTOS
            sprintf(sql, "select num_atri from atributos where num_atri = %d and estado_atri = true;", algo);
            break;
        case 3:
            sprintf(sql, "select codi_barra_r from reactivos where codi_barra_r = %d and estado_r = true;", algo);
            break;
        case 4:
            sprintf(sql, "select num_a from analisis where num_a = %d and estado_a = true;", algo);
            break;
        case 5:
            sprintf(sql, "select folio_a from historial_clinico where folio_a = %d and status = 1;", algo);
            break;
        case 6:
            sprintf(sql, "select folio_a from historial_clinico where folio_a = %d and status = 2;", algo);
            break;
        case 7:
            sprintf(sql, "select folio_a from historial_clinico where folio_a = %d;", algo);
            break;
        }
        res = PQexec(conn, sql); //EJECUTA LA INSTRUCCION
        //printf("%s\n",sql);
        if (res != NULL && PQntuples(res) != 0)     //SI EL SELECT DEVOLVIÓ ALGO
        {                                           //SI ENCONTRÓ ALGO
            devolver = atoi(PQgetvalue(res, 0, 0)); //OBTIENE EL CODIGO DE BARRAS DEL MATERIAL
        }
        else
        {
            devolver = -1;
        }
    }
    PQfinish(conn); //CIERRO LA CONEXION

    return devolver;
}
int ver_si_algo_esta_repetido(int opc, int analisis_recibido, int algo_recibido)
{
    char *material2 = malloc(tamano_maloc);
    int material;
    char sql[600];
    conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //ESTABLESCO UNA CONEXION
    if (PQstatus(conn) != CONNECTION_BAD)
    {
        switch (opc)
        {
        case 1: //MATERIALES
            sprintf(sql, "select codi_barra_m from Det_a_materiales where num_a = %d and codi_barra_m = %d;", analisis_recibido, algo_recibido);
            break;
        case 2: //ATRIBUTOS
            sprintf(sql, "select num_atri from det_a_atributos where num_a = %d and num_atri = %d;", analisis_recibido, algo_recibido);
            break;
        case 3: //REACTIVOS DE LOS ATRIBUTOS
            sprintf(sql, "select codi_barra_r from Det_atributos where num_atri = %d and codi_barra_r = %d;", analisis_recibido, algo_recibido);
            break;
        }
        res = PQexec(conn, sql);

        if (res != NULL && PQntuples(res) != 0)
        {                                           //SI ENCONTRÓ ALGO
            material = atoi(PQgetvalue(res, 0, 0)); //OBTIENE EL CODIGO DE BARRAS DEL MATERIAL
        }
        else
        {
            material = -1;
        }

        PQfinish(conn); //CIERRO LA CONEXION
    }

    return material;
}
void pedir_materiales_analisis(int num_a)
{
    int salir, opc_materiales, otro_material, cantidad_ocupada;
    char sql[600];
    do
    {
        do
        { //CICLO PARA IMPRIMIR LOS CODIGOS DE BARRA
            conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1");
            printf("\n|----------AGREGAR  MATERIALES UTILIZADOS----------|\n");
            //--------------------------------------------------------------------IMPRIMIR LOS MATERIALES DISPONIBLES
            if (PQstatus(conn) != CONNECTION_BAD)
            {
                res = PQexec(conn, "select codi_barra_m, nom_m from materiales;");
                if (res != NULL && PQntuples(res) != 0)
                {
                    for (int i = 0; i < PQntuples(res); i++)
                    {
                        printf("[%s] %s\n", PQgetvalue(res, i, 0), PQgetvalue(res, i, 1)); //IMPRIMIR MATERIAL ENCONTRADO
                    }
                    printf("[0] CONTINUAR\n");
                }
                PQclear(res);
            }
            PQfinish(conn);
            //--------------------------------------------------------------------FIN IMPRIMIR LOS MATERIALES DISPONIBLES
            opc_materiales = pedir_entero("CODIGO DE BARRA DE MATERIAL");

            if (opc_materiales != 0)
            {                                                           //SI LA OPCION NO ES CERO
                opc_materiales = ver_si_algo_existe(1, opc_materiales); //CHECAR SI EXISTE
            }
            if (opc_materiales != -1)
            {
                if (opc_materiales != 0)
                {                                                        //SI ES 0 YA QUIERE SALIR, POR LO TANTO NO LE PIDE LA CANTIDAD OCUPADA
                    cantidad_ocupada = pedir_entero("CANTIDAD OCUPADA"); //PEDIR CANTIDAD OCUPADA
                }
                salir = 1; //SI SALIR VALE UNO SALE DEL CICLO
            }
            else
            {
                salir = 0;
                printf(ANSI_COLOR_RED "\nEl valor ingresado no corresponde a ningun codigo de barras de algun material disponible\n" ANSI_COLOR_RESET);
            }

        } while (salir != 1); //FIN CICLO INGRESAR VALORES CORRECTOS

        if (opc_materiales != 0)
        { //SI ELIGIÓ

            int repetido = ver_si_algo_esta_repetido(1, num_a, opc_materiales); //SABER SI ESTA REPETIDO, SI DEVUELVE -1 ESTA REPETIDO
            if (repetido != -1)
            { //SI ESTA REPETIDO
                printf(ANSI_COLOR_RED "\nEl material no puede repetirse, intente con otro\n" ANSI_COLOR_RESET);
            }
            else
            { //SI NO ESTA REPETIDO, INSERTA
                //INICIO INSERTAR-----------------------------------------------------------------------------------------------------
                conn2 = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //CREO UNA CONEXION 1
                if (PQstatus(conn) != CONNECTION_BAD)
                {
                    sprintf(sql, "select max(cons_det_a_materiales) from Det_a_materiales where num_a = %d;", num_a);
                    int consecutivo_mas_actual = consulta_rapida_enteros(sql);

                    sprintf(sql, "insert into Det_a_materiales(num_a, cons_det_a_materiales, codi_barra_m,  cant_ocupada_m) values(%d, %d, %d, %d);", num_a, consecutivo_mas_actual + 1, opc_materiales, cantidad_ocupada);
                    res = PQexec(conn2, sql);
                    if (PQresultStatus(res) == PGRES_COMMAND_OK) //PREGUNTA SI INSERTÓ
                    {
                        system("clear");
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
                PQfinish(conn2);
                //FIN INSERTAR---------------------------------------------------------------------------------------------------------
            }
        }

        otro_material = opc_materiales;
    } while (otro_material != 0);
}
void pedir_atributos_analisis(int num_a)
{
    int salir, opc_atributos, otro_atributo;
    char sql[600];
    do
    {
        do
        { //CICLO PARA IMPRIMIR LOS NUMERO DE ATRIBUTO
            conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1");
            printf("\n|----------AGREGAR  ATRIBUTOS DEL ANALISIS----------|\n");
            //--------------------------------------------------------------------IMPRIMIR LOS ATRIBUTOS DISPONIBLES
            if (PQstatus(conn) != CONNECTION_BAD)
            {
                res = PQexec(conn, "select num_atri, nom_atri from atributos;");
                if (res != NULL && PQntuples(res) != 0)
                {
                    for (int i = 0; i < PQntuples(res); i++)
                    {
                        printf("[%s] %s\n", PQgetvalue(res, i, 0), PQgetvalue(res, i, 1)); //IMPRIMIR ATRIBUTO ENCONTRADO
                    }
                    printf("[0] CONTINUAR\n");
                }
                PQclear(res);
            }
            PQfinish(conn);
            //--------------------------------------------------------------------FIN IMPRIMIR LOS ATRIBUTOS DISPONIBLES
            opc_atributos = pedir_entero("NUMERO DE ATRIBUTO");

            if (opc_atributos != 0)
            {                                                         //SI LA OPCION NO ES CERO
                opc_atributos = ver_si_algo_existe(2, opc_atributos); //CHECAR SI EXISTE
            }
            if (opc_atributos != -1)
            {
                salir = 1; //SI SALIR VALE -UNO SALE DEL CICLO
            }
            else
            {
                salir = 0;
                printf(ANSI_COLOR_RED "\nEl valor ingresado no corresponde a ningun numero de atributo de algun atributo disponible\n" ANSI_COLOR_RESET);
            }

        } while (salir != 1); //FIN CICLO INGRESAR VALORES CORRECTOS

        if (opc_atributos != 0)
        { //SI ELIGIÓ

            int repetido = ver_si_algo_esta_repetido(2, num_a, opc_atributos); //SABER SI ESTA REPETIDO, SI DEVUELVE -1 ESTA REPETIDO
            if (repetido != -1)
            { //SI ESTA REPETIDO
                printf(ANSI_COLOR_RED "\nEl atributo no puede repetirse, intente con otro\n" ANSI_COLOR_RESET);
            }
            else
            { //SI NO ESTA REPETIDO, INSERTA
                //INICIO INSERTAR-----------------------------------------------------------------------------------------------------
                conn2 = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //CREO UNA CONEXION 1
                if (PQstatus(conn) != CONNECTION_BAD)
                {
                    sprintf(sql, "select max(cons_det_a_atributos) from Det_a_atributos where num_a = %d;", num_a);
                    int consecutivo_mas_actual = consulta_rapida_enteros(sql); //OBTENER EL CONSECUTIVO MAS ACTUAL

                    sprintf(sql, "insert into Det_a_atributos(num_a, cons_det_a_atributos, num_atri) values(%d, %d, %d);", num_a, consecutivo_mas_actual + 1, opc_atributos);
                    res = PQexec(conn2, sql);
                    if (PQresultStatus(res) == PGRES_COMMAND_OK) //PREGUNTA SI INSERTÓ
                    {
                        system("clear");
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
                PQfinish(conn2);
                //FIN INSERTAR---------------------------------------------------------------------------------------------------------
            }
        }

        otro_atributo = opc_atributos;
    } while (otro_atributo != 0);
}
void confirmar_nuevo_analisis(int num_a)
{
    char sql[600];

    sprintf(sql, "select num_a, nom_a, tiempo_realizacion from analisis where num_a = %d;", num_a);

    system("clear");
    // IMPRIMIR DATOS DEL ATRIBUTO------------------------------------------------------------
    conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //CREAMOS LA CONEXION

    if (PQstatus(conn) != CONNECTION_BAD)
    {
        res = PQexec(conn, sql);
        if (res != NULL && PQntuples(res) != 0)
        { //SE ENCONTRÓ EL ANALISIS
            printf("---------------------------------------------------\n");
            printf("\tDATOS RECOPILADOS DEL ANALISIS A REGISTRAR\n");
            printf("---------------------------------------------------\n");
            //SE IMPRIMEN LOS PACIENTES ENCONTRADOS

            printf("     - > NUMERO : ");
            printf(ANSI_COLOR_BLUE "%s\n\n" ANSI_COLOR_RESET, PQgetvalue(res, 0, 0));

            printf("     - > NOMBRE : ");
            printf(ANSI_COLOR_BLUE "%s\n\n" ANSI_COLOR_RESET, PQgetvalue(res, 0, 1));

            printf("     - > TIEMPO DE REALIZACION : ");
            printf(ANSI_COLOR_BLUE "%s HORAS\n\n" ANSI_COLOR_RESET, PQgetvalue(res, 0, 2));
        }
        else
        { //NO SE ENCONTRARON PACIENTES
            printf(ANSI_COLOR_RED "No se han encontrado pacientes\n" ANSI_COLOR_RESET);
        }
    }
    else
    {
        printf("La conexion no fue posible\n");
    }

    PQfinish(conn); //FINALIZAMOS LA CONEXION

    //FIN IMPRIMIR DATOS DEL ANALISIS-------------------------------------------------------

    sprintf(sql, "select det_a_materiales.codi_barra_m, materiales.nom_m, det_a_materiales.cant_ocupada_m from det_a_materiales inner join materiales on det_a_materiales.codi_barra_m = materiales.codi_barra_m and det_a_materiales.num_a = %d;", num_a);

    //printf("%s\n",sql);
    //IMPRIMIR LOS MATERIALES UTILIZADOS---------------------------------------
    conn2 = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //CREAMOS LA CONEXION 2

    if (PQstatus(conn2) != CONNECTION_BAD)
    {
        res = PQexec(conn2, sql);
        if (res != NULL && PGRES_TUPLES_OK == PQresultStatus(res))
        {
            printf("---------------------------------------------------\n");
            printf("\tMATERIALES UTILIZADOS\n");
            printf("---------------------------------------------------\n");
            puts(ANSI_COLOR_BLUE "    COD_BARRA\tNOMBRE\t    CANTIDAD" ANSI_COLOR_RESET);
            for (int i = 0; i < PQntuples(res); i++)
            {
                printf("\t[%s]\t%s\t\t%s\n", PQgetvalue(res, i, 0), PQgetvalue(res, i, 1), PQgetvalue(res, i, 2));
            }
            PQclear(res);
        }
    }
    else
    {
        printf("La conexion no fue posible\n");
    }
    PQfinish(conn2); //FINALIZAMOS LA CONEXION2
    //FIN IMPRIMIR LOS REACTIVOS UTILIZADOS-------------------------------------------------

    sprintf(sql, "select Det_a_atributos.num_atri, atributos.nom_atri from Det_a_atributos inner join atributos on Det_a_atributos.num_atri = atributos.num_atri and Det_a_atributos.num_a = %d;", num_a);

    //IMPRIMIR LOS ATRIBUTOS UTILIZADOS---------------------------------------
    conn5 = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //CREAMOS LA CONEXION 5

    if (PQstatus(conn5) != CONNECTION_BAD)
    {
        res = PQexec(conn5, sql);
        if (res != NULL && PGRES_TUPLES_OK == PQresultStatus(res))
        {
            printf("---------------------------------------------------\n");
            printf("\tATRIBUTOS UTILIZADOS\n");
            printf("---------------------------------------------------\n");
            puts(ANSI_COLOR_BLUE " NUMERO DE ATRIBUTO\tNOMBRE" ANSI_COLOR_RESET);
            for (int i = 0; i < PQntuples(res); i++)
            {
                printf("\t[%s]\t\t%s\t\n", PQgetvalue(res, i, 0), PQgetvalue(res, i, 1));
            }
            PQclear(res);
            printf("---------------------------------------------------\n\n\n");
        }
    }
    else
    {
        printf("La conexion no fue posible\n");
    }
    PQfinish(conn5); //FINALIZAMOS LA CONEXION 5

    //FIN IMPRIMIR LOS ATRIBUTOS UTILIZADOS-------------------------------------------------

    //C O N F I R M A C I O N..........................................................
    int opc_confirmacion;

    opc_confirmacion = pedir_dos_opciones("CONFIRMAR REGISTRO ANALISIS");
    system("clear");

    if (opc_confirmacion == 1) //SI DIJÓ QUE SI
    {
        printf(ANSI_COLOR_GREEN "Analisis registrado correctamente\n" ANSI_COLOR_RESET);
    }
    else
    { //INFORMAMOS QUE SE CANCELÓ Y ELIMINAMOS TODO LO INGRESADO

        //ELIMINAR LOS ATRIBUTOS DEL ANALISIS CANCELADO----------------------------------------------------------
        sprintf(sql, "delete from det_a_atributos where num_a = %d;", num_a);
        conn3 = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //CREAMOS LA CONEXION 3
        res = PQexec(conn3, sql);
        PQfinish(conn3);
        //FIN ELIMINAR ATRIBUTOS DEL ANALISIS CANCELADO

        //ELIMINAR LOS MATERIALES DEL ANALISIS CANCELADO-------------------------------------------------------------------------------
        sprintf(sql, "delete from det_a_materiales where num_a = %d;", num_a);
        conn6 = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //CREAMOS LA CONEXION 4
        res = PQexec(conn6, sql);
        PQfinish(conn6);
        //FIN ELIMINAR LOS MATERIALES DEL ANALISIS CANCELADO-----------------------------------------------------------------------------

        //ELIMINAR EL ANALISIS CANCELADO-------------------------------------------------------------------------------
        sprintf(sql, "delete from analisis where num_a = %d;", num_a);
        conn4 = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //CREAMOS LA CONEXION 4
        res = PQexec(conn4, sql);
        PQfinish(conn4);
        //FIN ELIMINAR EL ANALISIS CANCELADO-----------------------------------------------------------------------------

        printf(ANSI_COLOR_RED "CANCELADO\n" ANSI_COLOR_RESET);
    }
    //F I N   C O N F I R M A CI O N....................................................
}
void agregar_nuevo_analisis()
{

    printf("|--------------AGREGAR NUEVO ANALISIS--------------|\n");

    int num_materiales = consulta_rapida_enteros("select count(codi_barra_m) from materiales where estado_m = true;");
    int num_atributos = consulta_rapida_enteros("select count(num_atri) from atributos where estado_atri=true;");

    if (num_materiales == 0 && num_atributos == 0)
    { //SI NO HAY ATRIBUTOS NI MATERIALES
        printf(ANSI_COLOR_RED "No hay materiales y atributos para agregar un nuevo analisis, por favor añadalos antes\n" ANSI_COLOR_RESET);
    }
    else if (num_materiales == 0)
    { //SI NO HAY MATERIALES
        printf(ANSI_COLOR_RED "No hay materiales para agregar un nuevo analisis, por favor añada materiales primero\n" ANSI_COLOR_RESET);
    }
    else if (num_atributos == 0)
    { //SI NO HAY ATRIBUTOS
        printf(ANSI_COLOR_RED "No hay atributos para agregar un nuevo analisis, por favor añada atributos primero\n" ANSI_COLOR_RESET);
    }
    else
    { //CUANDO ENTRA A ESTE ELSE QUIERE DECIR QUE SI HAY ATRIBUTOS Y MATERIALES
        char sql[600];
        int opc_confirmacion;
        struct
        {
            char *nombre;
            int tiempo_realizacion;
        } analisis[1];
        analisis[0].nombre = malloc(tamano_maloc);

        analisis[0].nombre = pedir_cadena("NOMBRE DE ANALISIS"); //PIDO NOMBRE DE ANALISIS

        analisis[0].tiempo_realizacion = pedir_entero("TIEMPO DE REALIZACION"); //PIDO TIEMPO DE REALIZACION

        conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1"); //CREO UNA CONEXION 1
        if (PQstatus(conn) != CONNECTION_BAD)
        {
            sprintf(sql, "insert into analisis(nom_a, tiempo_realizacion) values(UPPER('%s'), %d);", analisis[0].nombre, analisis[0].tiempo_realizacion);
            res = PQexec(conn, sql);
            if (PQresultStatus(res) == PGRES_COMMAND_OK) //SI INSERTÓ
            {                                            //quitar printf
                PQfinish(conn);                          //FINALIZO CONEXION 1
                //printf(ANSI_COLOR_GREEN "Se ha registrado el analisis de manera exitosa\n" ANSI_COLOR_RESET);
                int num_a = consulta_rapida_enteros("select max(num_a) from analisis;"); //OBTENER EL ULTIMO ANALISIS INSERTADO

                pedir_materiales_analisis(num_a); //PEDIR LOS MATERIALES UTILIZADOS PARA EL ANALISIS

                pedir_atributos_analisis(num_a); //PEDIR LOS ATRIBUTOS QUE CALCULAR EL ANALISIS

                confirmar_nuevo_analisis(num_a); //CONFIRMAR REGISTRO DE ANALISIS Y RECHAZAR, ESO HARAS MAÑANA ERICK, TERMINALO, YA CASI QUEDÓ!!!!!!!!!!!!!!!!
            }
            else
            {                   //quitar printf
                PQfinish(conn); //FINALIZO CONEXION 1
                printf(ANSI_COLOR_RED "No se ha podido registrar el analisis, notifique el error\n" ANSI_COLOR_RESET);
            }
        }
        else
        {
            printf("La conexion no fue posible\n");
        }
    }
    printf("---------------------------------------------------\n\n\n");
}
void ver_catalogo_analisis(){
    system("clear");
    printf("---------------------------------------------------\n");
    printf("\tCATALOGO ANALISIS\n");
    printf("---------------------------------------------------\n");
    printf(ANSI_COLOR_BLUE "NUMERO ANALISIS\t\tNOMBRE ANALISIS\t   TIEMPO REALIZACION\n" ANSI_COLOR_RESET);
    conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1");
    char sql[600];
    if(PQstatus(conn) != CONNECTION_BAD){
        res = PQexec(conn, "select * from v_catalogo_analisis;");
        if(res != NULL && PQntuples(res) != 0){
            for(int i=0; i < PQntuples(res); i++){
                printf("\t%s\t\t%s\t\t\t%s\n",PQgetvalue(res, i, 0),PQgetvalue(res, i, 1),PQgetvalue(res, i, 2));
            }

        }
        PQclear(res);
    }
    PQfinish(conn);
    printf("---------------------------------------------------\n\n\n");

}
void baja_analisis(){
    printf("|------------------BAJA  ANALISIS------------------|\n");
    int num_a = pedir_entero("NUMERO DE ANALISIS A ELIMINAR");

    num_a = ver_si_algo_existe(4, num_a);
    system("clear");

    if(num_a == -1){
        printf(ANSI_COLOR_RED "El analisis especificado no existe\n" ANSI_COLOR_RESET);
    }
    else{//SI ENTRA AL ELSE QUIERE DECIR QUE QUE SI EXISTE
        char sql[600];
        sprintf(sql, "select f_baja_analisis(%d);",num_a);
        int saber_si_se_borro = consulta_rapida_enteros(sql);
        if(saber_si_se_borro == 1){
            printf(ANSI_COLOR_GREEN "El analisis ha sido dado de baja correctamente\n" ANSI_COLOR_RESET);
        }
        else{//SI ENTRA AL ELSE QUIERE DECIR QUE NO SE PUEDE BORRAR PORQUE NO TODOS HAN SIDO ENTREGADOS AUN
            printf(ANSI_COLOR_RED "El analisis no ha podido ser dado de baja porque aun no se entregan todos los analisis de este tipo\n" ANSI_COLOR_RESET);
        }
    }
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

char *menu_reactivos()
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

int consulta_rapida_enteros(char sql[600])
{
    //printf("recibí: %s\n",sql);
    conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1");
    int devolver = -1;
    if (PQstatus(conn) != CONNECTION_BAD)
    {
        res = PQexec(conn, sql);
        devolver = atoi(PQgetvalue(res, 0, 0)); //OBTIENE LO QUE DEVUELVA LA CADENA
        //puts("despues");
        //PQclear(res);
    }
    //printf("devolver: %d\n",devolver);

    PQfinish(conn);
    return devolver;
}

char *consulta_rapida_cadenas(char sql[600])
{
    conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1");
    char *devolver = malloc(tamano_maloc);
    if (PQstatus(conn) != CONNECTION_BAD)
    {
        res = PQexec(conn, sql);
        devolver = PQgetvalue(res, 0, 0); //OBTIENE LO QUE DEVUELVA LA CADENA
        PQclear(res);
    }

    PQfinish(conn);
    return devolver;
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
    imprimir_resultados(11);
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
        res = PQexec(conn, "select num_a, nom_a, tiempo_realizacion from analisis where num_a = 25;");

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