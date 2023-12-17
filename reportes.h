#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED


class ArchivoJugadores{
private:
    char nombre[30];
public:
    ArchivoJugadores(){
        strcpy(nombre, "Jugadores.dat");
    }
    Jugador leerRegistro(int pos){
        Jugador reg;
        reg.setEstado(false);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Jugador);
    }
    bool grabarRegistro(Jugador reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
};


class ArchivoDeportes{
private:
    char nombre[30];
public:
    ArchivoDeportes(){
        strcpy(nombre, "deportes.dat" );
    }
    Deporte leerRegistro(int pos){
        Deporte reg;
        reg.setEstadoDeporte(false);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Deporte);
    }
    bool grabarRegistro(Deporte reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
};


class ArchivoEquipos{
private:
    char nombre[30];
public:
    ArchivoEquipos(){
        strcpy(nombre, "equipos.dat");
    }
    Equipo leerRegistro(int pos){
        Equipo reg;
        reg.setEstadoEq(false);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Equipo);
    }
    bool grabarRegistro(Equipo reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }

};


class ArchivoTipos{
private:
    char nombre[30];
public:
    ArchivoTipos(){
        strcpy(nombre, "TipodeDeporte.dat");
    }
    TipoDeporte leerRegistro(int pos){
        TipoDeporte reg;
        reg.setEstadoTD(false);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(TipoDeporte);
    }
    bool grabarRegistro(TipoDeporte reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }

};













void subMenuReportes(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU REPORTES"<<endl;
        cout<<"-----------------------"<<endl<<endl;
        cout<<"1)  "<<endl;
        cout<<"2)  "<<endl;
        cout<<"3)  "<<endl;
        cout<<"-----------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl<<endl;
        cout<<"INSERTE OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                break;
            case 2:
                break;
            case 3:
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



#endif // REPORTES_H_INCLUDED
