#ifndef SUBMENUTIPODEPORTE_H_INCLUDED
#define SUBMENUTIPODEPORTE_H_INCLUDED


void subMenuTipoDeporte()
{

    int opc;
    while(true){
        system("cls");
        cout<<"MENU TIPOS DE DEPORTE"<<endl;
        cout<<"-----------------------"<<endl<<endl;
        cout<<"1) AGREGAR TIPO"<<endl;
        cout<<"2) LISTAR TIPO POR ID"<<endl;
        cout<<"3) LISTAR TODO"<<endl;
        cout<<"4) MODIFICAR NIVEL DE DIFICULTAD"<<endl;
        cout<<"5) ELIMINAR REGISTRO"<<endl;//--
        cout<<"-----------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl<<endl;
        cout<<"INSERTE OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: altaTipoDeporte();
                break;
            case 2: listarTipoPorId();
                break;
            case 3: listarTiposDeDeporte();
                break;
            case 4: modificarTipo();
                break;
            case 5: eliminarTipoDeDeporte();
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




#endif // SUBMENUTIPODEPORTE_H_INCLUDED
