#ifndef CLSEQUIPO_H_INCLUDED
#define CLSEQUIPO_H_INCLUDED


class Equipo{
private:
    int idEquipo;
    char nombreEquipo[30];
    int nivel;
    bool estado;

public:

    //Setters
    void setNombreEquipo(const char *name){strcpy(nombreEquipo, name);}
    void setNivel(int nv){
        if(nv >=1 && nv <=3) nivel = nv;
        else{
            cout<<"EL NIVEL DEBE SER UN NUMERO ENTRE 1 Y 3"<<endl;
            exit(-1);
         }
        }
    void setEstadoEq(bool es){ estado = es;}

    //Getters
    int getIdEquipo(){ return idEquipo;}
    const char * getNombreEquipo(){ return nombreEquipo;}
    int getNivel(){ return nivel;}
    bool getEstadoEq(){ return estado;}

    //Metodos
    void cargarEquipo();
    void mostrarEquipo();
    //Metodos con archivos
    int insertarIndice();
    bool grabarEquipoEnDisco();
    int buscarEquipoId(int id);
    bool leerEquipoDeDisco(int pos);
    bool leerTodosEquipoDeDisco();
    int chequearEquipoActivo(int n);
    Equipo leerRegistroDeEquipo(int pos);
    bool modificarEquipoEndisco(int pos);

};

    int IdConstructor(const char *a);

    void Equipo::cargarEquipo(){
        idEquipo = IdConstructor("equipos.dat");
        cout<<"NOMBRE: ";
        cargarCadena(nombreEquipo, 29);
        cout<<"LOS NIVELES A ELEGIR SON:"<<endl;
        cout<<"1-PRINCIPIANTE"<<endl;
        cout<<"2-INTERMEDIO"<<endl;
        cout<<"3-AVANZADO"<<endl;
        cout<<"INGRESE NIVEL: ";
        int n;
        cin>>n;
        setNivel(n);
        estado = true;
    }

    void Equipo::mostrarEquipo(){
        if(estado == true){
            cout<<"ID DE EQUIPO: ";
            cout<<idEquipo<<endl;
            cout<<"NOMBRE: ";
            cout<<nombreEquipo<<endl;
            cout<<"NIVEL: ";
            cout<<nivel<<endl;
            cout<<endl;
        }
    }

     int Equipo::insertarIndice(){
        FILE *pArchivo;
        pArchivo = fopen("equipos.dat","rb");
        if(pArchivo == NULL){
            cout<<"ARCHIVO ERRONEO"<<endl;
            return -2;}
        int contarIndice = 0;

        while(fread(this,sizeof(Equipo),1, pArchivo)){
                contarIndice++;
        }
        fclose(pArchivo);
        return contarIndice;
    }

    bool Equipo::grabarEquipoEnDisco(){
        FILE * pArchivo;
        pArchivo =fopen("equipos.dat","ab");
        if(pArchivo == NULL){
            cout<<"ARCHIVO ERRONEO"<<endl;
            return false;}

        bool escribio = fwrite(this, sizeof(Equipo), 1, pArchivo);
        fclose(pArchivo);
        return escribio;
    }

    int Equipo::buscarEquipoId(int id){
        FILE *pArchivo;
        pArchivo = fopen("equipos.dat","rb");
        if(pArchivo == NULL){
            cout<<"ARCHIVO ERRONEO"<<endl;
            return -2;}
        int pos = 0;
        while(fread(this, sizeof(Equipo), 1, pArchivo)){
            if(this->getIdEquipo() == id){
                fclose(pArchivo);
                return pos;
            }
            pos++;
        }

        fclose(pArchivo);
        return -1;
    }

    bool Equipo::leerEquipoDeDisco(int pos){
        FILE *pArchivo;
        pArchivo = fopen("equipos.dat","rb");
        if(pArchivo == NULL){
            cout<<"ARCHIVO ERRONEO"<<endl;
            return false;}
        fseek(pArchivo, sizeof(Equipo)*pos, 0);
        fread(this, sizeof(Equipo), 1, pArchivo);
        this->mostrarEquipo();

        return true;
    }

    bool Equipo::leerTodosEquipoDeDisco(){
        FILE *pArchivo;
        pArchivo = fopen("equipos.dat","rb");
        if(pArchivo == NULL){
            cout<<"ARCHIVO ERRONEO"<<endl;
            return false;}
        while(fread(this, sizeof(Equipo), 1, pArchivo)){
            this->mostrarEquipo();
        }
        fclose(pArchivo);
        return true;
    }

    int Equipo::chequearEquipoActivo(int n){
        FILE *pArchivo;
        pArchivo = fopen("equipos.dat","rb");
        if(pArchivo == NULL){
            cout<<"ARCHIVO ERRONEO"<<endl;
            return -3;}
        while(fread(this, sizeof(Equipo), 1, pArchivo)){
            if(this->getIdEquipo() == n && this->getEstadoEq() == true){
                return 1;
                fclose(pArchivo);
            }else if(this->getIdEquipo() == n && this->getEstadoEq() == false){
                return -1;
                fclose(pArchivo);
            }
        }
        return -2;
        fclose(pArchivo);
    }

    Equipo Equipo::leerRegistroDeEquipo(int p){
        FILE *pArchivo;
        Equipo reg;
        pArchivo = fopen("equipos.dat","rb");
        if(pArchivo == NULL) exit(-1);
        fseek(pArchivo,sizeof reg*p, 0);
        fread(&reg, sizeof reg, 1, pArchivo);
        fclose(pArchivo);
        return reg;
    }

    bool Equipo::modificarEquipoEndisco(int pos){
        FILE *pArchivo;
        pArchivo = fopen("equipos.dat","rb+");
        if(pArchivo == NULL) return false;

        fseek(pArchivo, sizeof(Equipo)*pos, 0);
        bool modifico = fwrite(this, sizeof(Equipo), 1, pArchivo);
        fclose(pArchivo);
        return modifico;
    }



    int IdConstructor(const char *archi){
        int idAutomatico;
        Equipo aux;
        bool existe;
        existe = SiExiste(archi);
        if(existe){
            idAutomatico = aux.insertarIndice();
            idAutomatico++;
        }else{
            idAutomatico = 1;}
        return idAutomatico;
    }

    void altaEquipo(){
        Equipo reg;
        bool cargado;
        reg.cargarEquipo();
        cargado = reg.grabarEquipoEnDisco();
        if(cargado){
            cout<<"EQUIPO AGREGADO CON EXITO"<<endl;
            cout<<endl;
        }else{
            cout<<"SE PRODUJO UN ERROR EN LA CARGA"<<endl;
            cout<<endl;
        }
    }

    void listarEquipoPorId(){
        Equipo d;
        int posicion;
        bool encontrado;
        int id;
        cout<<"INGRESE ID DE EQUIPO: ";
        cin>>id;

        system("cls");
        posicion = d.buscarEquipoId(id);
        if(posicion >= 0){
            encontrado = d.leerEquipoDeDisco(posicion);

            if(encontrado){
                    if(d.getEstadoEq() == true) cout<<"**** LECTURA EXITOSA ****"<<endl;
                    else cout<<"EL ID EXISTE PERO HA SIDO DADO DE BAJA"<<endl;
            }else{
                cout<<"NO SE HA PODIDO LEER EL REGISTRO"<<endl;
            }
        }else cout<<"EL ID NO EXISTE"<<endl;
    }

    void listarEquipos(){
        Equipo d;
        bool leido;
        leido = d.leerTodosEquipoDeDisco();
        if(leido){
            cout<<"**** LECTURA EXITOSA ****"<<endl;
            cout<<endl;
        }else{
            cout<<"NO SE PUDO REALIZAR LA LECTURA"<<endl;
            cout<<endl;
        }
    }

    void modificarNombre(){
        Equipo reg,aux;
        bool modificado;
        int posicion;
        int id;
        cout<<"INSERTE UN ID DE EQUIPO A MODIFICAR: ";
        cin>>id;
        posicion = reg.buscarEquipoId(id);
        if(posicion >= 0){
            aux = reg.leerRegistroDeEquipo(posicion);
            if(aux.getEstadoEq() == false){
                cout<<"EL EQUIPO YA FUE DADO DE BAJA"<<endl;
                return;
            }
        }
        else{
            cout<<"EL ID NO EXISTE"<<endl;
            return;
        }
        cout<<"NOMBRE ACTUAL DEL EQUIPO: "<<aux.getNombreEquipo()<<endl;
        char nuevoNombre[30];
        cout<<"INSERTE EL NUEVO NOMBRE DEL EQUIPO: ";
        cargarCadena(nuevoNombre,29);
        aux.setNombreEquipo(nuevoNombre);
        modificado = aux.modificarEquipoEndisco(posicion);
        system("cls");
        if(modificado) cout<<"EQUIPO MODIFICADO CON EXITO!!!"<<endl;
    }

    void eliminarEquipo(){
        Equipo reg, aux;
        bool eliminado;
        int posicion;
        int id;
        cout<<"INSERTE UN ID DE EQUIPO A ELIMINAR: ";
        cin>>id;
        posicion = reg.buscarEquipoId(id);
        if(posicion >= 0){
            aux = reg.leerRegistroDeEquipo(posicion);
            if(aux.getEstadoEq() == false){
                cout<<"EL EQUIPO YA FUE DADO DE BAJA"<<endl;
                return;
            }
        }
        else{
            cout<<"EL ID NO EXISTE"<<endl;
            return;
        }
        cout<<"EL EQUIPO: "<<aux.getNombreEquipo()<<" SERA ELIMINADO"<<endl;
        system("pause");
        aux.setEstadoEq(false);
        eliminado = aux.modificarEquipoEndisco(posicion);
        system("cls");
        if(eliminado) cout<<"EQUIPO DADO DE BAJA CON EXITO!!!"<<endl;
    }





#endif // CLSEQUIPO_H_INCLUDED
