void alta_materiales()
{
    char sql[600];
    conn = PQsetdbLogin("localhost", "5432", NULL, NULL, "lac", "usuario1", "usuario1");
    printf("|-----------------ALTA  MATERIALES-----------------|\n");
     struct
    {
        char *codbarra;
        char *nombre;
        int *stockmax;
        int *stockmin;
        int stockactual;
    } materiales[1];
    materiales[0].codbarra = malloc(tamano_maloc);
    materiales[0].nombre = malloc(tamano_maloc);
    
     int opc_confirmacion;
            int salir = 0;
            printf("\nProcederemos al registro del material\n");

            materiales[0].nombre = pedir_cadena("NOMBRE DE MATERIAL"); //PEDIMOS NOMBRE

            materiales[0].stockmax = pedir_entero("Stock maximo del material"); //PEDIMOS EL STOCK MAXIMO QUE DEBE HABER

            materiales[0].stockmin = pedir_entero("Stock minimo del material"); //PEDIMOS EL STOCK MINIMO QUE DEBE HABER

            materiales[0].stockactual= pedir_entero("Cantidad"); //PEDIMOS CANTIDAD DE MATERIALES

            //IMPRIMIR LOS VALORES CAPTURADOS
            system("clear");
            printf("---------------------------------------------------\n");
            printf("\tDATOS RECOPILADOS\n");
            printf("---------------------------------------------------\n");
            printf("     - > MATERIAL: %s\n",materiales[0].nombre);
            printf("     - > STOCK MAXIMO: %d\n",materiales[0].stockmax);
            printf("     - > STOCK MINIMO: %d\n",materiales[0].stockmin);
            printf("     - > CANTIDAD %d\n",materiales[0].stockactual);
            printf("---------------------------------------------------");

            opc_confirmacion = pedir_dos_opciones("CONFIRMAR REGISTRO");
            system("clear");

            //char sql[400];
            if(opc_confirmacion == 1){//INSERTAMOS
               {//REGISTRAMOS EL MATERIAL
                    sprintf(sql, "insert into materiales (nom_m, stock_max_m, stock_min_m, stock_actual_m) values('%s', %d, %d, %d);",materiales[0].nombre, materiales[0].stockmax,materiales[0].stockmin,materiales[0].stockactual);
                }

                if (PQstatus(conn) != CONNECTION_BAD){
                    res = PQexec(conn, sql);
                    if(PQresultStatus(res) == PGRES_COMMAND_OK){
                        printf(ANSI_COLOR_GREEN "Se ha registrado el material de manera exitosa\n" ANSI_COLOR_RESET);
                    }else{
                        printf(ANSI_COLOR_RED "No se ha podido registrar el material, notifique el error\n" ANSI_COLOR_RESET);
                    }
                }
                else{
                printf("No conecto esta mierda\n");

                }
            }
            else{
                //INFORMAMOS QUE SE CANCELÓ
                    printf("CANCELADO\n");
            }

         PQfinish(conn);


    printf("---------------------------------------------------\n\n\n");
}