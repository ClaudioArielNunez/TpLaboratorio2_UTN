#ifndef SUBMENUEQUIPOS_H_INCLUDED
#define SUBMENUEQUIPOS_H_INCLUDED

void subMenuEquipos()
{

    int opc;
    while(true){
        system("cls");
        cout<<"MENU EQUIPOS"<<endl;
        cout<<"-----------------------"<<endl<<endl;
        cout<<"1) AGREGAR EQUIPO"<<endl;
        cout<<"2) LISTAR EQUIPO POR ID"<<endl;
        cout<<"3) LISTAR TODO"<<endl;
        cout<<"4) MODIFICAR NOMBRE"<<endl;
        cout<<"5) ELIMINAR REGISTRO"<<endl;//--
        cout<<"-----------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl<<endl;
        cout<<"INSERTE OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: altaEquipo();
                break;
            case 2: listarEquipoPorId();
                break;
            case 3: listarEquipos();
                break;
            case 4: modificarNombre();
                break;
            case 5: eliminarEquipo();
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



#endif // SUBMENUEQUIPOS_H_INCLUDED
