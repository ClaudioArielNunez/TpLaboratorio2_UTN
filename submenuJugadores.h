#ifndef SUBMENUJUGADORES_H_INCLUDED
#define SUBMENUJUGADORES_H_INCLUDED

 void subMenuJugadores()
{

    int opc;
    while(true){
        system("cls");
        cout<<"MENU JUGADORES"<<endl;
        cout<<"-----------------------"<<endl<<endl;
        cout<<"1) AGREGAR JUGADOR"<<endl;
        cout<<"2) LISTAR JUGADOR POR DNI"<<endl;
        cout<<"3) LISTAR TODOS LOS JUGADORES"<<endl;
        cout<<"4) MODIFICAR FECHA DE INSCRIPCION"<<endl;
        cout<<"5) ELIMINAR REGISTRO DE JUGADOR"<<endl;//--
        cout<<"-----------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl<<endl;
        cout<<"INSERTE OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: altaJugador();
                break;
            case 2: listarPorDni();
                break;
            case 3: listarTodosLosJugadores();
                break;
            case 4: modificarFecha();
                break;
            case 5: eliminar();
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


#endif // SUBMENUJUGADORES_H_INCLUDED
