#include <stdio.h>
#include <stdlib.h>
#include <postgresql/libpq-fe.h>
void hacer_select();
int menu_principal();
int menu_pacientes();
int menu_laboratoristas();
int menu_analisis();
int menu_materiales_reactivos();
int menu_reportes();
PGconn *conn;
PGresult *res;
PGresult *resultado;
int main(int argc, char *argv[]){
    int opc, opc_paciente, opc_laboratorista, opc_analisis, opc_materiales, opc_reportes;
    conn = PQsetdbLogin("localhost","5432",NULL,NULL,"lac","usuario1","usuario1");
    if(PQstatus(conn) != CONNECTION_BAD){
        printf("La conexion a la base de datos ha sido correcta\n");
    }
    do{
        opc=menu_principal();
        switch (opc)
        {
        case 1: 
            do{
            opc_paciente=menu_pacientes(); 
                switch (opc_paciente){
                    case 1: break;
                    case 2: break;
                    case 3: break;
                    case 4: break;
                    default: printf("Opcion no valida, intente de nuevo\n"); break;
                }
            }while(opc != 4);
            break;

        case 2: menu_laboratoristas(); break;

        case 3: menu_analisis(); break;

        case 4: menu_materiales_reactivos(); break;

        case 5: menu_reportes(); break;

        case 6: break;

        default: printf("Opcion no valida, intente de nuevo\n"); break;
        }

    }while (opc != 6);

    PQfinish(conn);
    return 0;
}
int menu_principal(){
    int opc;
    printf("\n\n|-------------------MENU PRINCIPAL-------------------|\n");
    printf("\n[1] PACIENTES");
    printf("\n[2] LABORATORISTAS");
    printf("\n[3] ANALISIS");
    printf("\n[4] MATERIALES/REACTIVOS");
    printf("\n[5] REPORTES");
    printf("\n[6] SALIR");
    printf("\n------------------------------------------------------\n");
    printf("Ingrese la opcion deseada : ");
    scanf("%d", &opc);
    return opc;    
}
int menu_pacientes(){system("clear");
    printf("Pacientes\n");
    return 0;
}
int menu_laboratoristas(){system("clear");
    printf("Laboratoristas\n");
    return 0;
}
int menu_analisis(){system("clear");
    printf("Analisis\n");
    return 0;
}
int menu_materiales_reactivos(){system("clear");
    printf("Materiales/Reactivos\n");
    return 0;
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