#ifndef SUBMENUDEPORTES_H_INCLUDED
#define SUBMENUDEPORTES_H_INCLUDED

void subMenuDeportes()
{

    int opc;
    while(true){
        system("cls");
        cout<<"MENU DEPORTES"<<endl;
        cout<<"-----------------------"<<endl<<endl;
        cout<<"1) AGREGAR DEPORTE"<<endl;
        cout<<"2) LISTAR DEPORTE POR ID"<<endl;
        cout<<"3) LISTAR TODO"<<endl;
        cout<<"4) MODIFICAR ANIO DE ORIGEN"<<endl;
        cout<<"5) ELIMINAR REGISTRO"<<endl;//--
        cout<<"-----------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl<<endl;
        cout<<"INSERTE OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: altaDeporte();
                break;
            case 2: listarDeportePorId();
                break;
            case 3: lecturaDeDisco();
                break;
            case 4: modificarAnio();
                break;
            case 5: bajaDeporte();
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


#endif // SUBMENUDEPORTES_H_INCLUDED
