#ifndef CLSDEPORTE_H_INCLUDED
#define CLSDEPORTE_H_INCLUDED



class Deporte{
private:
    int idDeporte;
    char nombre[30];
    int tipoDeporte;
    int yearOrigen;
    bool estado;
public:

    //setters
    void setNombre(const char *n){ strcpy(nombre, n);}
    void setTipoDeporte(int t){
        if(t > 0 && t <= 21) tipoDeporte = t;
        else{
                cout<<"DEBE SER UN NUMERO ENTRE 1 Y 21"<<endl;
                exit(-1);
            }
        }
    void setYearOrigen(int a){
        if(a >= 1800 && a <= 2023) yearOrigen = a;
        else{
                cout<<"EL ANIO DEBE ESTAR EN UN RANGO ENTRE 1800 Y 2023"<<endl;
                exit(-1);
            }
        }
    void setEstadoDeporte(bool es){ estado = es;}

    //Getters
    int getIdDeporte(){ return idDeporte;}
    const char* getNombre(){ return nombre;}
    int getTipoDeporte(){ return tipoDeporte;}
    int getYearOrigen(){ return yearOrigen;}
    bool getEstadoDeporte(){ return estado;}

    //Metodos
    void cargarDeporte();
    void mostrarDeporte();
    //Metodos con archivos
    bool grabarDeporteEnDisco();
    bool leerDeporteEnDisco();
    int chequearDeporteActivo(int id);
    int insertarIndice();
    int buscarDeporteId(int id);
    bool leerDeDisco(int pos);
    int chequearSiIdExiste(int id);
    bool leerDeDisco2(int pos);
    bool modificarEnDisco(int pos);
};
    bool chequearSiExiste();
    int autoIdConstructor();

    void Deporte::cargarDeporte(){
        TipoDeporte tipoDep;
        idDeporte = autoIdConstructor();
        cout<<"NOMBRE: ";
        cargarCadena(nombre, 29);
        cout<<"INGRESE TIPO DE DEPORTE, ESTE DEBE SER UN NUMERO ENTRE 1 Y 21 : ";
        int t;
        cin>>t;

        while(t<1 || t>21){
            cout<<"HOLAAA, EL NUMERO DEBE ESTAR ENTRE 1 Y 21, INGRESE DE NUEVO: ";
            cin>>t;
        }
        int chequeo;
        chequeo = tipoDep.chequearTipoDepActivo(t);

        while(chequeo < 0){
            if(chequeo == -1) cout<<"EL TIPO DE DEPORTE EXISTE PERO FUE DADO DE BAJA"<<endl;
            else if(chequeo == -2) cout<<"NO EXISTEN TIPOS DE DEPORTE CON ESE NUMERO"<<endl;
            else exit(-3);
            cout<<"INGRESE DE NUEVO"<<endl;
            cin>>t;
            chequeo = tipoDep.chequearTipoDepActivo(t);
        }

        setTipoDeporte(t);

        cout<<"ANIO DE ORIGEN: ";
        int year;
        cin>>year;
        while(year<1800 || year>2023){
            cout<<"EL ANIO DEBE ESTAR ENTRE 1800 Y 2023, INGRESE DE NUEVO: ";
            cin>>year;
        }
        yearOrigen = year;
        estado = true;
    }
    void Deporte::mostrarDeporte(){
        if(estado == true){
            cout<<"ID DE DEPORTE: ";
            cout<<idDeporte<<endl;
            cout<<"NOMBRE: ";
            cout<<nombre<<endl;
            cout<<"TIPO DE DEPORTE: ";
            cout<<tipoDeporte<<endl;
            cout<<"ANIO DE ORIGEN: ";
            cout<<yearOrigen<<endl;
            cout<<endl;
        }
    }
    bool Deporte::grabarDeporteEnDisco(){
        FILE * pArchivo;
        pArchivo =fopen("deportes.dat","ab");
        if(pArchivo == NULL){
            cout<<"ARCHIVO ERRONEO"<<endl;
            return false;}

        bool escribio = fwrite(this, sizeof(Deporte), 1, pArchivo);
        fclose(pArchivo);
        return escribio;
    }
    bool Deporte::leerDeporteEnDisco(){
        FILE *pArchivo;
        pArchivo = fopen("deportes.dat","rb");
        if(pArchivo == NULL){
            cout<<"ARCHIVO ERRONEO"<<endl;
            return false;}
        while(fread(this, sizeof(Deporte), 1, pArchivo)){
            this->mostrarDeporte();
        }
        fclose(pArchivo);
        return true;
    }
    int Deporte::chequearDeporteActivo(int id){
        FILE *pArchivo;
        pArchivo = fopen("deportes.dat","rb");
        if(pArchivo == NULL){
            cout<<"ARCHIVO ERRONEO"<<endl;
            return -3;}
        while(fread(this, sizeof(Deporte), 1, pArchivo)){
            if(this->getIdDeporte() == id && this->getEstadoDeporte() == true){
                return 1;
                fclose(pArchivo);
            }else if(this->getIdDeporte() == id && this->getEstadoDeporte() == false){
                return -1;
                fclose(pArchivo);
            }
        }

        return -2;
        fclose(pArchivo);
    }
    int Deporte::insertarIndice(){
        FILE *pArchivo;
        pArchivo = fopen("deportes.dat","rb");
        if(pArchivo == NULL){
            cout<<"ARCHIVO ERRONEO"<<endl;
            return -2;}
        int contarIndice = 0;

        while(fread(this,sizeof(Deporte),1, pArchivo)){
                contarIndice++;
        }
        fclose(pArchivo);
        return contarIndice;
    }

    int Deporte::buscarDeporteId(int id){
        FILE *pArchivo;
        pArchivo = fopen("deportes.dat","rb");
        if(pArchivo == NULL){
            cout<<"ARCHIVO ERRONEO"<<endl;
            return -2;}
        int pos = 0;
        while(fread(this, sizeof(Deporte), 1, pArchivo)){
            if(this->getIdDeporte() == id){
                fclose(pArchivo);
                return pos;
            }
            pos++;
        }

        fclose(pArchivo);
        return -1;
    }
    bool Deporte::leerDeDisco(int pos){
        FILE *pArchivo;
        pArchivo = fopen("deportes.dat","rb");
        if(pArchivo == NULL){
            cout<<"ARCHIVO ERRONEO"<<endl;
            return false;}
        fseek(pArchivo, sizeof(Deporte)*pos, 0);
        fread(this, sizeof(Deporte), 1, pArchivo);
        this->mostrarDeporte();
        return true;
    }

    bool chequearSiExiste(){
        FILE * pArchivo;
        pArchivo = fopen("deportes.dat","rb");
        if(pArchivo == NULL){
            return false;
        }
        return true;
    }
    void altaDeporte(){
        Deporte d;
        bool cargado;
        d.cargarDeporte();
        cargado = d.grabarDeporteEnDisco();
        if(cargado){
            cout<<"DEPORTE AGREGADO CON EXITO"<<endl;
            cout<<endl;
        }else{
            cout<<"SE PRODUJO UN ERROR EN LA CARGA"<<endl;
            cout<<endl;
        }
    }

    int autoIdConstructor(){
        int idAutomatico;
        Deporte aux;
        bool existe;
        existe = chequearSiExiste();
        if(existe){
            idAutomatico = aux.insertarIndice();
            idAutomatico++;
        }else{
            idAutomatico = 1;}
        return idAutomatico;
    }

    void lecturaDeDisco(){
        Deporte d;
        bool leido;
        leido = d.leerDeporteEnDisco();
        if(leido){
            cout<<"**** LECTURA EXITOSA ****"<<endl;
            cout<<endl;
        }else{
            cout<<"NO SE PUDO REALIZAR LA LECTURA"<<endl;
            cout<<endl;
        }
    }
    void listarDeportePorId(){
        Deporte d;
        int posicion;
        bool encontrado;
        int id;
        cout<<"INGRESE ID DE DEPORTE: ";
        cin>>id;

        system("cls");
        posicion = d.buscarDeporteId(id);
        if(posicion >= 0){
            encontrado = d.leerDeDisco(posicion);

            if(encontrado){
                    if(d.getEstadoDeporte() == true) cout<<"**** LECTURA EXITOSA ****"<<endl;
                    else cout<<"EL ID EXISTE PERO HA SIDO DADO DE BAJA"<<endl;
            }else{
                cout<<"NO SE HA PODIDO LEER EL REGISTRO"<<endl;
            }
        }else cout<<"EL ID NO EXISTE"<<endl;
    }
    int Deporte::chequearSiIdExiste(int id){
        FILE *pArchivo;
        pArchivo = fopen("deportes.dat","rb");
        if(pArchivo == NULL){
            cout<<"ARCHIVO ERRONEO"<<endl;
            return -2;}
        int pos = 0;
        while(fread(this, sizeof(Deporte), 1, pArchivo)){
            if(this->getIdDeporte() == id){
                fclose(pArchivo);
                return pos;
            }
            pos++;
        }
        fclose(pArchivo);
        return -1;
    }
    bool Deporte::leerDeDisco2(int pos){
        bool encontrado;
        FILE *pArchivo;
        pArchivo = fopen("deportes.dat","rb");
        if(pArchivo ==  NULL){
            cout<<"ARCHIVO ERRONEO"<<endl;
            return false;}
        fseek(pArchivo, sizeof(Deporte)*pos, 0);
        encontrado = fread(this, sizeof(Deporte), 1, pArchivo);
        fclose(pArchivo);
        return encontrado;
    }
    bool Deporte::modificarEnDisco(int pos){
        FILE *pArchivo;
        bool modificado;
        pArchivo = fopen("deportes.dat", "rb+");
        if(pArchivo == NULL){
            cout<<"ARCHIVO ERRONEO"<<endl;
            return false;
        }
        fseek(pArchivo, sizeof(Deporte)*pos, 0);
        modificado = fwrite(this, sizeof(Deporte), 1, pArchivo);
        fclose(pArchivo);
        return modificado;
    }

    bool modificarAnio(){
        int id, pos;
        bool anioEditado;
        Deporte aux;
        cout<<"INGRESE UN ID: ";
        cin>>id;
        pos = aux.chequearSiIdExiste(id);
        if(pos == -1){
            cout<<"NO EXISTE REGISTRO CON ESE ID"<<endl;
            return false;
        }
        aux.leerDeDisco2(pos);
        if(aux.getEstadoDeporte() == false){
            cout<<"ESTE DEPORTE YA HA SIDO DADO DE BAJA"<<endl;
            return false;
        }
        cout<<"EL DEPORTE ES: "<<aux.getNombre()<<endl;
        cout<<"INGRESE UN NUEVO ANIO DE ORIGEN: "<<endl;
        int nuevoAnio;
        cin>>nuevoAnio;
        system("cls");
        if(nuevoAnio >= 1800 && nuevoAnio <= 2023){
            aux.setYearOrigen(nuevoAnio);
            anioEditado = aux.modificarEnDisco(pos);
            if(anioEditado){
                cout<<"ANIO DE ORIGEN MODIFICADO CON EXITO!"<<endl;
                return anioEditado;
                }
            else{
            cout<<"NO SE PUDO REALIZAR EL CAMBIO"<<endl;}
            return anioEditado;
            }
        else{
            cout<<"EL ANIO INTRODUCIDO NO ES VALIDO"<<endl;
            return false;
    }
}
    bool bajaDeporte(){
        int id;
        int pos;
        bool dadoDeBaja;
        Deporte aux;
        cout<<"INGRESE UN ID: ";
        cin>>id;
        pos = aux.chequearSiIdExiste(id);
        if(pos == -1){
        cout<<"NO EXISTE REGISTRO CON ESE ID"<<endl;
        return false;
        }
        aux.leerDeDisco2(pos);
        if(aux.getEstadoDeporte() == false){
            cout<<"EL DEPORTE YA HA SIDO DADO DE BAJA"<<endl;
            return false;
        }
        cout<<"EL DEPORTE ES: "<<aux.getNombre()<<endl;
        cout<<"PROCEDEREMOS A SU BAJA LOGICA"<<endl;
        system("pause");
        system("cls");
        aux.setEstadoDeporte(false);
        dadoDeBaja = aux.modificarEnDisco(pos);
        if(dadoDeBaja){
            cout<<"DEPORTE DADO DE BAJA CON EXITO"<<endl;
            return true;
        }
        else{
            cout<<"NO SE PUDO REALIZAR LA BAJA"<<endl;
            return false;
        }
    }





#endif // CLSDEPORTE_H_INCLUDED
