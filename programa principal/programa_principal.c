#include <stdio.h>
#include <stdlib.h>
#include <postgresql/libpq-fe.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void hacer_select();
int menu_principal();

int menu_pacientes();
void alta_pacientes();
void actualizar_pacientes();
void buscar_pacientes();

int menu_laboratoristas();
void alta_laboratoristas();
void actualizar_laboratoristas();
void buscar_laboratoristas();
void despedir_laboratoristas();

int menu_analisis();
void solicitar_analisis();
void realizar_analisis();
void entregar_analisis();
void buscar_analisis();
void consultas_analisis();
void agregar_nuevo_analisis();

int menu_materiales();
void alta_materiales();
void baja_materiales();

int menu_reactivos();
void alta_reactivos();
void baja_reactivos();

int menu_reportes();
PGconn *conn;
PGresult *res;
PGresult *resultado;
int main(int argc, char *argv[]){
    int opc, opc_paciente, opc_laboratorista, opc_analisis, opc_materiales,opc_reactivos, opc_reportes;
    conn = PQsetdbLogin("localhost","5432",NULL,NULL,"lac","usuario1","usuario1");
    if(PQstatus(conn) != CONNECTION_BAD){
        printf("La conexion a la base de datos ha sido correcta\n");
    }
    do{
        opc=menu_principal();
        switch (opc)
        {
        case 1: system("clear");
            do{
            opc_paciente=menu_pacientes(); 
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
            opc_laboratorista=menu_laboratoristas(); 
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
            opc_analisis=menu_analisis(); 
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
            opc_materiales=menu_materiales(); 
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
            opc_reactivos=menu_reactivos(); 
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

    PQfinish(conn);
    return 0;
}
int menu_principal(){
    int opc;
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
    scanf("%d", &opc);
    return opc;    
}


int menu_pacientes(){
 int opc;
    printf("|------------------MENU PACIENTES------------------|");
    printf("\n[1] ALTA");
    printf("\n[2] ACTUALIZAR");
    printf("\n[3] BUSCAR");
    printf("\n[4] VOLVER AL MENU PRINCIPAL");
    printf("\n---------------------------------------------------\n");
    printf("Ingrese la opcion deseada : ");
    scanf("%d", &opc);
    return opc;    
}
void alta_pacientes(){ 
    printf("|------------------ALTA PACIENTES------------------|\n");
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


int menu_laboratoristas(){
    int opc;
    printf("|--------------MENU  LABORATORISTAS----------------|");
    printf("\n[1] ALTA");
    printf("\n[2] ACTUALIZAR");
    printf("\n[3] BUSCAR");
    printf("\n[4] DESPEDIR");
    printf("\n[5] VOLVER AL MENU PRINCIPAL");
    printf("\n---------------------------------------------------\n");
    printf("Ingrese la opcion deseada : ");
    scanf("%d", &opc);
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


int menu_analisis(){
    int opc;
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
    scanf("%d", &opc);
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



int menu_materiales(){
    int opc;
    printf("|----------------MENU  MATERIALES------------------|");
    printf("\n[1] ALTA");
    printf("\n[2] BAJA");
    printf("\n[3] VOLVER AL MENU PRINCIPAL");
    printf("\n---------------------------------------------------\n");
    printf("Ingrese la opcion deseada : ");
    scanf("%d", &opc);
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


int menu_reactivos(){
    int opc;
    printf("|-----------------MENU REACTIVOS-------------------|");
    printf("\n[1] ALTA");
    printf("\n[2] BAJA");
    printf("\n[3] VOLVER AL MENU PRINCIPAL");
    printf("\n---------------------------------------------------\n");
    printf("Ingrese la opcion deseada : ");
    scanf("%d", &opc);
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


int menu_reportes(){system("clear");
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