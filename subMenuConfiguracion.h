#ifndef SUBMENUCONFIGURACION_H_INCLUDED
#define SUBMENUCONFIGURACION_H_INCLUDED

 void subMenuConfig()
{

    int opc;
    while(true){
        system("cls");
        cout<<"MENU CONFIGURACION"<<endl;
        cout<<"-----------------------"<<endl<<endl;
        cout<<"1) COPIA DE SEGURIDAD DEL ARCHIVO DE JUGADORES"<<endl;
        cout<<"2) COPIA DE SEGURIDAD DEL ARCHIVO DE DEPORTES"<<endl;
        cout<<"3) COPIA DE SEGURIDAD DEL ARCHIVO DE TIPO DE DEPORTES"<<endl;
        cout<<"4) COPIA DE SEGURIDAD DEL ARCHIVO DE EQUIPOS"<<endl;
        cout<<"5) RESTAURAR EL ARCHIVO DE JUGADORES"<<endl;
        cout<<"6) RESTAURAR EL ARCHIVO DE DEPORTES"<<endl;
        cout<<"7) RESTAURAR EL ARCHIVO DE TIPO DE DEPORTES"<<endl;
        cout<<"8) RESTAURAR EL ARCHIVO DE EQUIPOS"<<endl;
        cout<<"9) ESTABLECER DATOS DE INICIO"<<endl;
        cout<<"-----------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl<<endl;
        cout<<"INSERTE OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: copiaDeJugadores();
                break;
            case 2: copiaDeDeportes();
                break;
            case 3: copiaDeTipoDeDeportes();
                break;
            case 4: copiaDeEquipos();
                break;
            case 5: restaurarJugadores();
                break;
            case 6: restaurarDeportes();
                break;
            case 7: restaurarTipoDeDeportes();
                break;
            case 8: restaurarEquipos();
                break;
            case 9: establecerDatosDeInicio();
                break;
            case 0: return;
                break;
            default: cout<<"LA OPCION ELEGIDA NO ES VALIDA"<<endl;
                break;
        }
        cout<<endl;
        system("pause");
    }

}


#endif // SUBMENUCONFIGURACION_H_INCLUDED
