#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <postgresql/libpq-fe.h>
#define ANSI_COLOR_RED     "\x1b[31m" // color rojo
#define ANSI_COLOR_RESET   "\x1b[0m"  // resetear color

void hacer_select();
int validar_entero();
char* validar_cadena();

char* menu_principal();

char* menu_pacientes();
void alta_pacientes();
void actualizar_pacientes();
void buscar_pacientes();

char* menu_laboratoristas();
void alta_laboratoristas();
void actualizar_laboratoristas();
void buscar_laboratoristas();
void despedir_laboratoristas();

char* menu_analisis();
void solicitar_analisis();
void realizar_analisis();
void entregar_analisis();
void buscar_analisis();
void consultas_analisis();
void agregar_nuevo_analisis();

char* menu_materiales();
void alta_materiales();
void baja_materiales();

char* menu_reactivos();
void alta_reactivos();
void baja_reactivos();

char* menu_reportes();
PGconn *conn;
PGresult *res;
PGresult *resultado;

int tamano_maloc=20;

    
int main(int argc, char *argv[]){
    char cadena_prueba[tamano_maloc];
    printf("Ingresa un texo: ");
    scanf("%s",cadena_prueba);
    if((strcmp(validar_cadena(cadena_prueba),"no")==0)){//SI VALIDAR_CADENA REGRESA "NO", NO ES UNA CADENA VALIDA
        printf("La cadena no es valida\n");
    }
    else{
        printf("La cadena si es valida\n");    
    }
    /*
    int opc, opc_paciente, opc_laboratorista, opc_analisis, opc_materiales,opc_reactivos, opc_reportes;

    do{
        //VALIDAR SI LA OPCION DEL MENU PRINCIPAL ES UN NUMERO
        do{
            char* cadena = malloc(tamano_maloc); //CREO UNA CADENA DE 20 CARACTERES   
            if(opc==-1){system("clear");
                printf(ANSI_COLOR_RED "Opcion no valida, intente de nuevo\n\n" ANSI_COLOR_RESET );  
            }       
            cadena=menu_principal();// cadena RECIBE EL VALOR QUE EL USUARIO DIGITE
            opc=validar_entero(cadena);//INVOCO A METODO QUE SE REGRESA EL NUMERO O 0 SI NO ES UN NUMERO
        }while(opc==-1);
        // FIN VALIDAR....................................................................................................

        switch (opc)
        {
        case 1: system("clear");
            do{
                //VALIDAR SI LA OPCION DEL MENU PACIENTE ES UN NUMERO
                do{
                    char* cadena = malloc(tamano_maloc); //CREO UNA CADENA DE 20 CARACTERES   
                    if(opc_paciente==-1){system("clear");
                        printf(ANSI_COLOR_RED "Opcion no valida, intente de nuevo\n\n" ANSI_COLOR_RESET );  
                    }       
                    cadena=menu_pacientes();// cadena RECIBE EL VALOR QUE EL USUARIO DIGITE
                    opc_paciente=validar_entero(cadena);//INVOCO A METODO QUE SE REGRESA EL NUMERO O 0 SI NO ES UN NUMERO
                }while(opc_paciente==-1);
                // FIN VALIDAR....................................................................................................
               switch (opc_paciente){
                    case 1: system("clear"); alta_pacientes(); break;
                    case 2: system("clear"); actualizar_pacientes(); break;
                    case 3: system("clear"); buscar_pacientes(); break;
                    case 4: system("clear"); break;
                    default: system("clear");
                    printf(ANSI_COLOR_RED "Opcion no valida, intente de nuevo\n\n" ANSI_COLOR_RESET ); break;
                }
            }while(opc_paciente != 4);
            break;

        case 2: system("clear");
            do{
                //VALIDAR SI LA OPCION DEL MENU PACIENTE ES UN NUMERO
                do{
                    char* cadena = malloc(tamano_maloc); //CREO UNA CADENA DE 20 CARACTERES   
                    if(opc_laboratorista==-1){system("clear");
                        printf(ANSI_COLOR_RED "Opcion no valida, intente de nuevo\n\n" ANSI_COLOR_RESET );  
                    
                    }       
                    cadena=menu_laboratoristas();// cadena RECIBE EL VALOR QUE EL USUARIO DIGITE
                    opc_laboratorista=validar_entero(cadena);//INVOCO A METODO QUE SE REGRESA EL NUMERO O 0 SI NO ES UN NUMERO
                }while(opc_laboratorista==-1);
                // FIN VALIDAR.................................................................................................... 
                switch (opc_laboratorista){
                    case 1: system("clear"); alta_laboratoristas(); break;
                    case 2: system("clear"); actualizar_laboratoristas(); break;
                    case 3: system("clear"); buscar_laboratoristas(); break;
                    case 4: system("clear"); despedir_laboratoristas(); break;
                    case 5: system("clear"); break;
                    default: system("clear");
                    printf(ANSI_COLOR_RED "Opcion no valida, intente de nuevo\n\n" ANSI_COLOR_RESET ); break;
                }
            }while(opc_laboratorista != 5);break;

        case 3: system("clear"); 
            do{
                //VALIDAR SI LA OPCION DEL MENU PACIENTE ES UN NUMERO
                do{
                    char* cadena = malloc(tamano_maloc); //CREO UNA CADENA DE 20 CARACTERES   
                    if(opc_analisis==-1){system("clear");
                        printf(ANSI_COLOR_RED "Opcion no valida, intente de nuevo\n\n" ANSI_COLOR_RESET );  
                    }       
                    cadena=menu_analisis();// cadena RECIBE EL VALOR QUE EL USUARIO DIGITE
                    opc_analisis=validar_entero(cadena);//INVOCO A METODO QUE SE REGRESA EL NUMERO O 0 SI NO ES UN NUMERO
                }while(opc_analisis==-1);
                // FIN VALIDAR....................................................................................................
                switch (opc_analisis){
                    case 1: system("clear"); solicitar_analisis(); break;
                    case 2: system("clear"); realizar_analisis(); break;
                    case 3: system("clear"); entregar_analisis(); break;
                    case 4: system("clear"); buscar_analisis(); break;
                    case 5: system("clear"); consultas_analisis(); break;
                    case 6: system("clear"); agregar_nuevo_analisis(); break;
                    case 7: system("clear"); break;
                    default: system("clear");
                    printf(ANSI_COLOR_RED "Opcion no valida, intente de nuevo\n\n" ANSI_COLOR_RESET ); break;
                }
            }while(opc_analisis != 7);break;

        case 4: system("clear"); 
        do{
            //VALIDAR SI LA OPCION DEL MENU PACIENTE ES UN NUMERO
                do{
                    char* cadena = malloc(tamano_maloc); //CREO UNA CADENA DE 20 CARACTERES   
                    if(opc_materiales==-1){system("clear");
                        printf(ANSI_COLOR_RED "Opcion no valida, intente de nuevo\n\n" ANSI_COLOR_RESET );  
                    }       
                    cadena=menu_materiales();// cadena RECIBE EL VALOR QUE EL USUARIO DIGITE
                    opc_materiales=validar_entero(cadena);//INVOCO A METODO QUE SE REGRESA EL NUMERO O 0 SI NO ES UN NUMERO
                }while(opc_materiales==-1);
                // FIN VALIDAR.................................................................................................... 
                switch (opc_materiales){
                    case 1: system("clear"); alta_materiales(); break;
                    case 2: system("clear"); baja_materiales(); break;
                    case 3: system("clear"); break;
                    default: system("clear");
                    printf(ANSI_COLOR_RED "Opcion no valida, intente de nuevo\n\n" ANSI_COLOR_RESET ); break;
                }
            }while(opc_materiales != 3);break;

        case 5: system("clear");
        do{
            //VALIDAR SI LA OPCION DEL MENU PACIENTE ES UN NUMERO
                do{
                    char* cadena = malloc(tamano_maloc); //CREO UNA CADENA DE 20 CARACTERES   
                    if(opc_reactivos==-1){system("clear");
                        printf(ANSI_COLOR_RED "Opcion no valida, intente de nuevo\n\n" ANSI_COLOR_RESET );  
                    }       
                    cadena=menu_reactivos();// cadena RECIBE EL VALOR QUE EL USUARIO DIGITE
                    opc_reactivos=validar_entero(cadena);//INVOCO A METODO QUE SE REGRESA EL NUMERO O 0 SI NO ES UN NUMERO
                }while(opc_reactivos==-1);
                // FIN VALIDAR.................................................................................................... 
                switch (opc_reactivos){
                    case 1: system("clear"); alta_reactivos(); break;
                    case 2: system("clear"); baja_reactivos(); break;
                    case 3: system("clear"); break;
                    default: system("clear");
                    printf(ANSI_COLOR_RED "Opcion no valida, intente de nuevo\n\n" ANSI_COLOR_RESET ); break;
                }
            }while(opc_reactivos != 3);break;

        case 6: system("clear"); 
        menu_reportes(); break;

        case 7: system("clear"); break;

        default: system("clear"); 
        printf(ANSI_COLOR_RED "Opcion no valida, intente de nuevo\n\n" ANSI_COLOR_RESET ); break;
        }

    }while (opc != 7);
*/
    //PQfinish(conn);
    return 0;
}

int validar_entero(char cadena[tamano_maloc]){    
    int z,valor=1, num;//Z ES UN CONTADOR, SI VALOR ES 0 SIGNIFICA QUE EL CARACTER NO ES UN NUMERO, SI ES 1 SIGNIFICA QUE EL CARACTER SI ES UN NUMERO
    char x[10]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (z=0; z<strlen(cadena);z++){//ESTE FOR RECORRE LA CADENA CARACTER POR CARACTER
        if(isdigit(cadena[z]) != 0){//ESTE IF VALIDA QUE LO INGRESADO SEA UN DIGITO     
                valor = 1;//SI LA CONDICION SE CUMPLE, TOMA EL VALOR DE 1 LO QUE SIGNIFICA QUE EL CARACTER ANALIZADO SI ES UN NUMERO
        }
        else{
            valor = 0; //SI LA CONDICION NO SE COMPLE, TOMA EL VALOR DE 0, ES DECIR, EL CARACTER ANALIZADO NO ES UN NUMERO  
        } 
        if(valor==0){//SI ALGUN CARACTER NO ES UN NUMERO SALE DEL FOR
            break;
        }
    }
    if(valor==1){//SI LA CADENA SI ES UN NUMERO CONVIERTE LA CADENA A ENTERO Y LO DEVUELVE
        num = atoi(cadena);
    }
    else{//SI LA CADENA NO ES UN NUMERO DEVUELVE -1
        num = -1;
    }
    return num;
}

char* validar_cadena(char cadena[tamano_maloc]){ 
    char* cadena_devolver = malloc(tamano_maloc);   
    int z,valor=1, num;//Z ES UN CONTADOR, SI VALOR ES 0 SIGNIFICA QUE EL CARACTER NO ES UNA LETRA, SI ES 1 SIGNIFICA QUE EL CARACTER SI ES UNA LETRA
    for (z=0; z<strlen(cadena);z++){//ESTE FOR RECORRE LA CADENA CARACTER POR CARACTER
        if(isalpha(cadena[z]) != 0){//ESTE IF VALIDA QUE LO INGRESADO SEA UN DIGITO
                valor = 1;//SI LA CONDICION SE CUMPLE, TOMA EL VALOR DE 1 LO QUE SIGNIFICA QUE EL CARACTER ANALIZADO SI ES UN NUMERO
        }
        else{
            valor = 0; //SI LA CONDICION NO SE COMPLE, TOMA EL VALOR DE 0, ES DECIR, EL CARACTER ANALIZADO NO ES UN NUMERO  
        } 
        if(valor==0){//SI ALGUN CARACTER NO ES UN NUMERO SALE DEL FOR
            break;
        }
    }
    if(valor==1){//SI LA CADENA TIENE PURAS LETRAS SE REGRESA LA CADENA
        cadena_devolver=cadena;
    }
    else{//SI LA CADENA NO ES UN NUMERO DEVUELVE -1
        cadena_devolver="no";
    }
    return cadena_devolver;
}
char* menu_principal(){
    char* opc = malloc(tamano_maloc);
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


char* menu_pacientes(){
    char* opc = malloc(tamano_maloc);
    printf("|------------------MENU PACIENTES------------------|");
    printf("\n[1] ALTA");
    printf("\n[2] ACTUALIZAR");
    printf("\n[3] BUSCAR");
    printf("\n[4] VOLVER AL MENU PRINCIPAL");
    printf("\n---------------------------------------------------\n");
    printf("Ingrese la opcion deseada : ");
    scanf("%s", opc);
    return opc;    
}
void alta_pacientes(){ 
    printf("|------------------ALTA PACIENTES------------------|\n");
    conn = PQsetdbLogin("localhost","5432",NULL,NULL,"lac","usuario1","usuario1");
    char correo_dado[80], sql[100];
    int i, j;
    //SE PIDE EL CORREO PARA VER SI YA ESTA REGISTRADO
    printf("Ingresa tu correo por por favor: ");
    scanf("%s",correo_dado);
    if (PQstatus(conn) != CONNECTION_BAD){
        sprintf(sql, "select folio_p from pacientes where correo ~ '^%s$';",correo_dado);
        res = PQexec(conn, sql);
        if (res != NULL && PQntuples(res)!=0){
            for (i = 0; i < PQntuples(res);i++){
                for (j = 0; j < PQnfields(res);j++){
                    printf("Folio del paciente %s\t",PQgetvalue(res,i,j));
                    printf("\n");
                }
                PQclear(res);
            }
        }
        else{
            printf("No se ha encontrado el correo en la base de datos\n");
        }
    }
    else{
        printf("Error de conexion a la base de datos\n");
    }
    PQfinish(conn);
    printf("---------------------------------------------------\n\n\n");
}
void actualizar_pacientes(){
    printf("|---------------ACTUALIZAR PACIENTES---------------|\n");
    printf("---------------------------------------------------\n\n\n");
}
void buscar_pacientes(){
    printf("|-----------------BUSCAR PACIENTES-----------------|\n");
    printf("---------------------------------------------------\n\n\n");
}


char* menu_laboratoristas(){
    char* opc = malloc(tamano_maloc);
    printf("|--------------MENU  LABORATORISTAS----------------|");
    printf("\n[1] ALTA");
    printf("\n[2] ACTUALIZAR");
    printf("\n[3] BUSCAR");
    printf("\n[4] DESPEDIR");
    printf("\n[5] VOLVER AL MENU PRINCIPAL");
    printf("\n---------------------------------------------------\n");
    printf("Ingrese la opcion deseada : ");
    scanf("%s", opc);
    return opc;    
}
void alta_laboratoristas(){
    printf("|----------------ALTA LABORATORISTA----------------|\n");
    printf("---------------------------------------------------\n\n\n");
}
void actualizar_laboratoristas(){
    printf("|-------------ACTUALIZAR LABORATORISTA-------------|\n");
    printf("---------------------------------------------------\n\n\n");
}
void buscar_laboratoristas(){
    printf("|---------------BUSCAR LABORATORISTA---------------|\n");
    printf("---------------------------------------------------\n\n\n");
}
void despedir_laboratoristas(){
    printf("|--------------DESPEDIR LABORATORISTA--------------|\n");
    printf("---------------------------------------------------\n\n\n");
}


char* menu_analisis(){
    char* opc = malloc(tamano_maloc);
    printf("|-----------------MENU  ANALISIS-------------------|");
    printf("\n[1] SOLICITAR ANALISIS");
    printf("\n[2] REALIZAR ANALISIS");
    printf("\n[3] ENTREGAR ANALISIS");
    printf("\n[4] BUSCAR ANALISIS");
    printf("\n[5] CONSULTAS ANALISIS");
    printf("\n[6] AGREGAR UN NUEVO ANALISIS");
    printf("\n[7] VOLVER AL MENU PRINCIPAL");
    printf("\n---------------------------------------------------\n");
    printf("Ingrese la opcion deseada : ");
    scanf("%s", opc);
    return opc; 
}
void solicitar_analisis(){
    printf("|----------------SOLICITAR ANALISIS----------------|\n");
    printf("---------------------------------------------------\n\n\n");
}
void realizar_analisis(){
    printf("|----------------REALIZAR  ANALISIS----------------|\n");
    printf("---------------------------------------------------\n\n\n");
}
void entregar_analisis(){
    printf("|----------------ENTREGAR  ANALISIS----------------|\n");
    printf("---------------------------------------------------\n\n\n");
}
void buscar_analisis(){
    printf("|-----------------BUSCAR  ANALISIS-----------------|\n");
    printf("---------------------------------------------------\n\n\n");
}
void consultas_analisis(){
    printf("|----------------CONSULTAS ANALISIS----------------|\n");
    printf("---------------------------------------------------\n\n\n");
}
void agregar_nuevo_analisis(){
    printf("|--------------AGREGAR NUEVO ANALISIS--------------|\n");
    printf("---------------------------------------------------\n\n\n");
}



char* menu_materiales(){
    char* opc = malloc(tamano_maloc);
    printf("|----------------MENU  MATERIALES------------------|");
    printf("\n[1] ALTA");
    printf("\n[2] BAJA");
    printf("\n[3] VOLVER AL MENU PRINCIPAL");
    printf("\n---------------------------------------------------\n");
    printf("Ingrese la opcion deseada : ");
    scanf("%s", opc);
    return opc; 
}
void alta_materiales(){
    printf("|-----------------ALTA  MATERIALES-----------------|\n");
    printf("---------------------------------------------------\n\n\n");
}
void baja_materiales(){
    printf("|-----------------BAJA  MATERIALES-----------------|\n");
    printf("---------------------------------------------------\n\n\n");
}


char* menu_reactivos(){
    char* opc = malloc(tamano_maloc);
    printf("|-----------------MENU REACTIVOS-------------------|");
    printf("\n[1] ALTA");
    printf("\n[2] BAJA");
    printf("\n[3] VOLVER AL MENU PRINCIPAL");
    printf("\n---------------------------------------------------\n");
    printf("Ingrese la opcion deseada : ");
    scanf("%s", opc);
    return opc; 
}
void alta_reactivos(){
    printf("|------------------ALTA REACTIVOS------------------|\n");
    printf("---------------------------------------------------\n\n\n");
}
void baja_reactivos(){
    printf("|------------------BAJA REACTIVOS------------------|\n");
    printf("---------------------------------------------------\n\n\n");    
}


char* menu_reportes(){system("clear");
    printf("reportes\n");
    return 0;
}
void hacer_select(){
    /*PGconn *conn;
    PGresult *res;*/
    int i,j;
    conn = PQsetdbLogin("localhost","5432",NULL,NULL,"lac","usuario1","usuario1");
    if (PQstatus(conn) != CONNECTION_BAD){
        res = PQexec(conn, "select folio_p, nom_p, edad_p, sexo_p, fecha_registro, correo, estado_p from pacientes;"); 

        if (res != NULL && PGRES_TUPLES_OK == PQresultStatus(res)){
            for (i = 0; i < PQntuples(res);i++)
            {
                for (j = 0; j < PQnfields(res);j++)
                printf("%s\t",PQgetvalue(res,i,j));
                printf("\n");
            }
            PQclear(res);
        }
    }

    PQfinish(conn);
}