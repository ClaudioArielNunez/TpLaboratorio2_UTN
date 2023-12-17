#include <iostream>
#include <cstring>
#include <cstdio>
#include <ctime>

using namespace std;

#include "funcionesGlobales.h"
#include "clsFecha.h"

#include "clsTipoDeporte.h"
#include "clsDeporte.h"

#include "clsEquipo.h"
#include "clsJugador.h"

#include "Configuracion.h"
#include "submenuJugadores.h"
#include "subMenuDeportes.h"
#include "subMenuConfiguracion.h"
#include "subMenuEquipos.h"
#include "subMenuTipoDeporte.h"

#include "reportes.h"




int main()
{



    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"-----------------------"<<endl<<endl;
        cout<<"1) MENU JUGADORES"<<endl;
        cout<<"2) MENU DEPORTES"<<endl;
        cout<<"3) MENU EQUIPOS"<<endl;
        cout<<"4) MENU TIPOS DE DEPORTE"<<endl;
        cout<<"5) REPORTES"<<endl;
        cout<<"6) CONFIGURACION"<<endl;

        cout<<"-----------------------"<<endl;
        cout<<"0) FIN DEL PROGRAMA"<<endl<<endl;
        cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: subMenuJugadores();
                break;
            case 2: subMenuDeportes();
                break;
            case 3: subMenuEquipos();
                break;
            case 4: subMenuTipoDeporte();
                break;
            case 5: subMenuReportes();
                break;
            case 6: subMenuConfig();
                break;
            case 0: cout<<"GRACIAS POR USAR LA APLICACION"<<endl;
                    return 0;
                break;
            default: cout<<"LA OPCION ELEGIDA NO ES VALIDA"<<endl;
                break;
        }
        cout<<endl;
        system("pause");
    }
    return 0;
}
