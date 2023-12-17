#ifndef CLSTIPODEPORTE_H_INCLUDED
#define CLSTIPODEPORTE_H_INCLUDED

class TipoDeporte{
private:
    int idTipoDeporte;
    char nombreTipoD[30];
    int nivelDific;
    bool estado;

public:

    //Setters
    void setIdTipoDeporte(int id){
        if(id >= 1 && id <= 21) idTipoDeporte = id;
        else{
            cout<<"EL PROGRAMA YA CUENTA CON LA CANTIDAD DE TIPOS DE DEPORTE SUFICIENTES"<<endl;
            exit(-1);

         }
        }
    void setNombreTipoDep(const char *name){ strcpy(nombreTipoD, name);}
    void setNivelDif(int nvD){
        if(nvD >= 1 && nvD <= 8) nivelDific = nvD;
        else{
            cout<<"EL NIVEL DE DIFICULTAD PUEDE SER DE 1 A 8"<<endl;
            exit(-1);
         }
        }
    void setEstadoTD(bool es){ estado = es;}

    //Getters
    int getIdTipoDeporte(){ return idTipoDeporte;}
    const char *getNombreTipoDep(){ return nombreTipoD;}
    int getNivelDif(){ return nivelDific;}
    bool getEstadoTD(){ return estado;}

    //Metodos
    void cargarTipoDep();
    void mostrarTipoDep();
    //Metodos con archivos
    int insertarIndice();
    bool grabarTipoDepEnDisco();
    int chequearTipoDepActivo(int idTipo);
    int buscarTipoId(int id);
    bool leerTipoDeDisco(int pos);
    bool leerTodosLosTiposDeDisco();
    TipoDeporte leerRegDeTipoDeporte(int p);
    bool modificarTipoDeporteEndisco(int pos);


};
    int IdBuilder(const char *a);

    void TipoDeporte::cargarTipoDep(){
        int idTipoD = IdBuilder("TipodeDeporte.dat");
        setIdTipoDeporte(idTipoD);
        cout<<"NOMBRE: ";
        cargarCadena(nombreTipoD, 29);
        cout<<"NIVEL DE DIFICULTAD: ";
        int n;
        cin>>n;
        while(n<1 || n>8){
            cout<<"LOS NIVELES DE DIFICULTAD A ELEGIR VAN DE 1 A 8"<<endl;
            cout<<"INGRESE DE NUEVO EL NIVEL: ";
            cin>>n;
            system("cls");
        }
        nivelDific = n;
        estado = true;
    }

    void TipoDeporte::mostrarTipoDep(){
        if(estado == true){
            cout<<"ID DE TIPO DE DEPORTE: ";
            cout<<idTipoDeporte<<endl;
            cout<<"NOMBRE: ";
            cout<<nombreTipoD<<endl;
            cout<<"NIVEL DE DIFICULTAD: ";
            cout<<nivelDific<<endl;
            cout<<endl;
        }
    }

    int TipoDeporte::insertarIndice(){
        FILE *pArchivo;
        pArchivo = fopen("TipodeDeporte.dat","rb");
        if(pArchivo == NULL){
            cout<<"ARCHIVO ERRONEO"<<endl;
            return -2;}
        int contarIndice = 0;

        while(fread(this,sizeof(TipoDeporte),1, pArchivo)){
                contarIndice++;
        }
        fclose(pArchivo);
        return contarIndice;
    }

    bool TipoDeporte::grabarTipoDepEnDisco(){
        FILE *pArchivo;
        pArchivo =fopen("TipodeDeporte.dat","ab");
        if(pArchivo == NULL){
            cout<<"ARCHIVO ERRONEO"<<endl;
            return false;}

        bool escribio = fwrite(this, sizeof(TipoDeporte), 1, pArchivo);
        fclose(pArchivo);
        return escribio;
    }

    int TipoDeporte::chequearTipoDepActivo(int n){
        FILE *pArchivo;
        pArchivo = fopen("TipodeDeporte.dat","rb");
        if(pArchivo == NULL){
            cout<<"ARCHIVO ERRONEO"<<endl;
            return -3;}
        while(fread(this, sizeof(TipoDeporte), 1, pArchivo)){
            if(this->getIdTipoDeporte() == n && this->getEstadoTD() == true){
                return 1;
                fclose(pArchivo);
            }else if(this->getIdTipoDeporte() == n && this->getEstadoTD() == false){
                return -1;
                fclose(pArchivo);
            }
        }
        return -2;
        fclose(pArchivo);
    }

    int TipoDeporte::buscarTipoId(int id){
        FILE *pArchivo;
        pArchivo = fopen("TipodeDeporte.dat","rb");
        if(pArchivo == NULL){
            cout<<"ARCHIVO ERRONEO"<<endl;
            return -2;}
        int pos = 0;
        while(fread(this, sizeof(TipoDeporte), 1, pArchivo)){
            if(this->getIdTipoDeporte() == id ){
                fclose(pArchivo);
                return pos;
            }
            pos++;
        }

        fclose(pArchivo);
        return -1;
    }

    bool TipoDeporte::leerTipoDeDisco(int pos){
        FILE *pArchivo;
        pArchivo = fopen("TipodeDeporte.dat","rb");
        if(pArchivo == NULL){
            cout<<"ARCHIVO ERRONEO"<<endl;
            return false;}
        fseek(pArchivo, sizeof(TipoDeporte)*pos, 0);
        fread(this, sizeof(TipoDeporte), 1, pArchivo);
        this->mostrarTipoDep();
        //cout<<"REGISTRO LEIDO CON EXITO"<<endl;
        return true;
    }

    bool TipoDeporte::leerTodosLosTiposDeDisco(){
        FILE *pArchivo;
        pArchivo = fopen("TipodeDeporte.dat","rb");
        if(pArchivo == NULL){
            cout<<"ARCHIVO ERRONEO"<<endl;
            return false;}
        while(fread(this, sizeof(TipoDeporte), 1, pArchivo)){
            this->mostrarTipoDep();
        }
        fclose(pArchivo);
        return true;
    }

    TipoDeporte TipoDeporte::leerRegDeTipoDeporte(int p){
        FILE *pArchivo;
        TipoDeporte reg;
        pArchivo = fopen("TipodeDeporte.dat","rb");
        if(pArchivo == NULL) exit(-1);
        fseek(pArchivo,sizeof reg*p, 0);
        fread(&reg, sizeof reg, 1, pArchivo);
        fclose(pArchivo);
        return reg;
    }

    bool TipoDeporte::modificarTipoDeporteEndisco(int pos){
        FILE *pArchivo;
        pArchivo = fopen("TipodeDeporte.dat","rb+");
        if(pArchivo == NULL) return false;

        fseek(pArchivo, sizeof(TipoDeporte)*pos, 0);
        bool modifico = fwrite(this, sizeof(TipoDeporte), 1, pArchivo);
        fclose(pArchivo);
        return modifico;
    }


    int IdBuilder(const char *archi){
        int idAutomatico;
        TipoDeporte aux;
        bool existe;
        existe = SiExiste(archi);
        if(existe){
            idAutomatico = aux.insertarIndice();
            idAutomatico++;
        }else{
            idAutomatico = 1;}
        return idAutomatico;
    }

    void altaTipoDeporte(){
        TipoDeporte reg;
        bool cargado;
        reg.cargarTipoDep();
        cargado = reg.grabarTipoDepEnDisco();
        if(cargado){
            cout<<"TIPO DE DEPORTE AGREGADO CON EXITO"<<endl;
            cout<<endl;
        }else{
            cout<<"SE PRODUJO UN ERROR EN LA CARGA"<<endl;
            cout<<endl;
        }
    }

    void listarTipoPorId(){
        TipoDeporte t;
        int posicion;
        bool encontrado;
        int id;
        cout<<"INGRESE ID DE TIPO DE DEPORTE: ";
        cin>>id;

        system("cls");
        posicion = t.buscarTipoId(id);
        if(posicion >= 0){
            encontrado = t.leerTipoDeDisco(posicion);

            if(encontrado){
                    if(t.getEstadoTD() == true) cout<<"**** LECTURA EXITOSA ****"<<endl;
                    else cout<<"EL ID EXISTE PERO HA SIDO DADO DE BAJA"<<endl;
            }else{
                cout<<"NO SE HA PODIDO LEER EL REGISTRO"<<endl;
            }
        }else cout<<"EL ID NO EXISTE"<<endl;
    }

    void listarTiposDeDeporte(){
        TipoDeporte t;
        bool leido;
        leido = t.leerTodosLosTiposDeDisco();
        if(leido){
            cout<<"**** LECTURA EXITOSA ****"<<endl;
            cout<<endl;
        }else{
            cout<<"NO SE PUDO REALIZAR LA LECTURA"<<endl;
            cout<<endl;
        }
    }

    void modificarTipo(){
        TipoDeporte reg,aux;
        bool modificado;
        int posicion;
        int id;
        cout<<"INSERTE UN ID DE TIPO DE DEPORTE A MODIFICAR: ";
        cin>>id;
        posicion = reg.buscarTipoId(id);
        if(posicion >= 0){
            aux = reg.leerRegDeTipoDeporte(posicion);
            if(aux.getEstadoTD() == false){
                cout<<"EL TIPO DE DEPORTE YA FUE DADO DE BAJA"<<endl;
                return;
            }
        }
        else{
            cout<<"EL ID NO EXISTE"<<endl;
            return;
        }
        cout<<"NIVEL DE DIFICULTAD ACTUAL DEL DEPORTE: "<<aux.getNivelDif()<<endl;
        int nuevoNivel;
        cout<<"INSERTE EL NUEVO NIVEL DE DIFICULTAD DEL DEPORTE: ";
        cin>>nuevoNivel;
        while(nuevoNivel >8 || nuevoNivel <1){
            system("cls");
            cout<<"LOS VALORES PERMITIDOS VAN DEL 1 A 8"<<endl;
            cin>>nuevoNivel;
        }
        aux.setNivelDif(nuevoNivel);
        modificado = aux.modificarTipoDeporteEndisco(posicion);
        system("cls");
        if(modificado) cout<<"NIVEL DE DIFICULTAD MODIFICADO CON EXITO!!!"<<endl;
    }

    void eliminarTipoDeDeporte(){
        TipoDeporte reg, aux;
        bool eliminado;
        int posicion;
        int id;
        cout<<"INSERTE ID DE TIPO DE DEPORTE A ELIMINAR: ";
        cin>>id;
        posicion = reg.buscarTipoId(id);
        if(posicion >= 0){
            aux = reg.leerRegDeTipoDeporte(posicion);
            if(aux.getEstadoTD() == false){
                cout<<"EL TIPO DE DEPORTE YA FUE DADO DE BAJA"<<endl;
                return;
            }
        }
        else{
            cout<<"EL ID NO EXISTE"<<endl;
            return;
        }
        cout<<"EL TIPO DE DEPORTE: "<<aux.getNombreTipoDep()<<" SERA ELIMINADO"<<endl;
        system("pause");
        aux.setEstadoTD(false);
        eliminado = aux.modificarTipoDeporteEndisco(posicion);
        system("cls");
        if(eliminado) cout<<"TIPO DE DEPORTE DADO DE BAJA CON EXITO!!!"<<endl;
    }







#endif // CLSTIPODEPORTE_H_INCLUDED
