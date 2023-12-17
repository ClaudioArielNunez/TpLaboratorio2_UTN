#ifndef CLSJUGADOR_H_INCLUDED
#define CLSJUGADOR_H_INCLUDED


class Jugador{
private:
    int DNI;
    char nombre[30];
    char apellido[30];
    char email[30];
    char telefono[30];
    int claustro;
    int deporte;
    int nroEquipo;
    Fecha fechaInscripcion;
    float matricula;
    bool estado;

public:

    //Setters
    void setDNI(int d){
        if(d>0) DNI = d;
        else {
            cout<<"ERROR,EL NUMERO DE DNI NO PUEDE SER 0 (CERO) O UN NUMERO NEGATIVO"<<endl;
            exit(-1);
        }
    }
    void setNombre(const char *n){strcpy(nombre,n);}
    void setApellido(const char *a){strcpy(apellido, a);}
    void setEmail(const char *e){strcpy(email,e);}
    void setTelefono(const char *t){strcpy(telefono,t);}
    void setMatricula(float m){
        if(m >= 0) matricula = m;
        else matricula = 0;
    }
    void setFechaInsc(Fecha f){
        fechaInscripcion.setAnio(f.getAnio());
        fechaInscripcion.setMes(f.getMes());
        fechaInscripcion.setDia(f.getDia());
    }
    void setClaustro(int c){
        if(c > 0 && c < 5){ claustro = c; }
        else{
                cout<<"ERROR, EL NUMERO INGRESADO NO CORRESPONE A UN CLAUSTRO"<<endl;
                exit(-1);
        }
    }
    void setDeporte(int d){ deporte = d;}
    void setNroEquipo(int e){ nroEquipo = e;}
    void setEstado(bool es){ estado = es;}

    //Getters
    int getDni(){ return DNI;}
    Fecha getFechaInsc(){ return fechaInscripcion;}
    const char* getNombre(){return nombre;}
    const char* getApellido(){return apellido;}
    const char* getEmail(){return email;}
    const char* getTelefono(){return telefono;}
    float getMatricula(){ return matricula;}
    int getClaustro(){ return claustro;}
    int getDeporte(){ return deporte;}
    int getNroEquipo(){ return nroEquipo;}
    bool getEstado(){ return estado;}

    //Metodos
    void cargar(int n);
    void mostrar();
};
    void Jugador::cargar(int n){
        Deporte sport;
        Equipo team;
        setDNI(n);
        cout<<"NOMBRE: ";
        cargarCadena(nombre, 29);
        cout<<"APELLIDO: ";
        cargarCadena(apellido,29);
        cout<<"EMAIL: ";
        cargarCadena(email,29);
        cout<<"TELEFONO: ";
        cargarCadena(telefono,29);

        int cl;
        cout<<"LOS CLAUSTROS PERMITIDOS SON: "<<endl;
        cout<<"1-DOCENTE\n2-ALUMNO\n3-NO DOCENTE\n4-GRADUADO"<<endl;
        cout<<"INSERTE CLAUSTRO: ";
        cin>>cl;
        setClaustro(cl);
        int dep;
        int existe;
        cout<<"DEPORTE: ";
        cin>>dep;
        existe = sport.chequearDeporteActivo(dep);
        while(existe == -1 || existe == -2){
            system("cls");
            if(existe == -1) cout<<"EXISTE, PERO ESTA DADO DE BAJA"<<endl;
            else cout<<"NO EXISTE"<<endl;
            cout<<"INGRESE DE NUEVO: ";
                cin>>dep;
            existe = sport.chequearDeporteActivo(dep);
        }

        if(existe){deporte = dep;}
        else{ cout<<"EL ARCHIVO DEPORTES NO EXISTE"<<endl;}

        cout<<"NUMERO DE EQUIPO: ";
        int nroEq;
        int res;
        cin>>nroEq;
        res = team.chequearEquipoActivo(nroEq);

        while(res < 0){
            if(res == -1) cout<<"EL EQUIPO EXISTE PERO FUE DADO DE BAJA"<<endl;
            else if(res == -2) cout<<"NO EXISTEN EQUIPOS CON ESE NUMERO"<<endl;
            else exit(-3);
            cout<<"INGRESE DE NUEVO"<<endl;
            cin>>nroEq;
            res = team.chequearEquipoActivo(nroEq);
        }
        nroEquipo = nroEq;

        cout<<"FECHA DE INSCRIPCION: "<<endl;
        fechaInscripcion.Cargar();

        float mat;
        cout<<"MATRICULA: ";
        cin>>mat;
        while(mat < 0){
            cout<<"EL NUMERO DEBE SER MAYOR O IGUAL A 0"<<endl;
            cin>>mat;
        }
        matricula = mat;
        estado=true;
    }

    void Jugador::mostrar(){
        if(estado == true)
        {
            cout<<"DOCUMENTO: ";
            cout<<DNI<<endl;
            cout<<"NOMBRE: ";
            cout<<nombre<<endl;
            cout<<"APELLIDO: ";
            cout<<apellido<<endl;
            cout<<"EMAIL: ";
            cout<<email<<endl;
            cout<<"TELEFONO: ";
            cout<<telefono<<endl;
            cout<<"CLAUSTRO: ";
            cout<<claustro<<endl;
            cout<<"DEPORTE: ";
            cout<<deporte<<endl;
            cout<<"NUMERO DE EQUIPO: ";
            cout<<nroEquipo<<endl;
            cout<<"FECHA DE INSCRIPCION:"<<endl;
            fechaInscripcion.mostrarEnLinea();
            cout<<"MATRICULA: ";
            cout<<matricula<<endl<<endl;
        }
    }


    //metodos con archivos
    bool listarRegistros();
    int buscarRegistro(const char *cod);
    Jugador leerRegistro(int pos);
    bool modificarRegistro(int pos, Jugador jug);

    bool agregarRegistros(Jugador reg, int n);
    int chequearDni(int n);



bool altaJugador(){
    Jugador reg;
    int n, pos;
    bool cargado;
    FILE *pArchivo = fopen("Jugadores.dat","ab");
    if(pArchivo == NULL) {
        cout<<"ARCHIVO ERRONEO"<<endl;
        return false;
    }
    cout<<"INGRESE DNI: ";
    cin>>n;
    if(n <= 0){
        cout<<"EL NUMERO INGRESADO NO ES VALIDO"<<endl;
        return false;
    }
    pos = chequearDni(n);
    if(pos >= 0){
        cout<<"ESTE NRO DE DNI YA EXISTE"<<endl;
        return false;
    }
    cargado = agregarRegistros(reg, n);
    system("cls");
    return cargado;

}
int chequearDni(int n){
    Jugador reg;
    FILE *pArchivo;
    pArchivo = fopen("Jugadores.dat","rb");
    if(pArchivo == NULL){
        cout<<"ARCHIVO ERRONEO"<<endl;
        return -2;
    }
    int pos = 0;
    while(fread(&reg, sizeof(Jugador), 1,pArchivo)){
        if(reg.getDni() == n){
            return pos;
            fclose(pArchivo);
        }
        pos++;
    }
    fclose(pArchivo);
    return -1;
}
bool agregarRegistros(Jugador reg, int n){

    FILE *pArchivo = fopen("Jugadores.dat","ab");
    if(pArchivo == NULL){
        cout<<"ARCHIVO ERRONEO"<<endl;
        return false;
    }
    reg.cargar(n);
    bool agregado;
    agregado = fwrite(&reg, sizeof(Jugador), 1, pArchivo);
    fclose(pArchivo);
    if(agregado) cout<<"REGISTRO AGREGADO CON EXITO"<<endl;
    else cout<<"NO SE PUDO AGREGAR "<<endl;
    system("pause");
    return agregado;
}
bool listarPorDni(){

    int n, pos;
    cout<<"INGRESE UN DNI: ";
    cin>>n;
    system("cls");
    pos = chequearDni(n);
    if(pos <= -1){
        cout<<"NO EXISTE REGISTRO CON ESE NUMERO"<<endl;
        return false;
    }
    Jugador reg;
    FILE *pArchivo;
    pArchivo = fopen("Jugadores.dat","rb");
    if(pArchivo == NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    fseek(pArchivo, sizeof(Jugador)*pos,0);
    fread(&reg, sizeof(Jugador), 1, pArchivo);
    if(reg.getEstado() == true){
        reg.mostrar();
        fclose(pArchivo);
    }else{
        cout<<"EL REGISTRO EXISTE PERO HA SIDO DADO DE BAJA"<<endl;
        fclose(pArchivo);
    }

    return true;
}
bool listarTodosLosJugadores(){
    Jugador reg;
    FILE *pArchivo;
    pArchivo = fopen("Jugadores.dat","rb");
    if(pArchivo == NULL){
        cout<<"ARCHIVO ERRONEO"<<endl;
        return false;
    }
    while(fread(&reg,sizeof(Jugador), 1, pArchivo)){
        reg.mostrar();
    }
    fclose(pArchivo);
    return true;
}
Jugador leerDeDisco(int pos){
    Jugador reg;
    FILE *pArchivo;
    pArchivo = fopen("Jugadores.dat","rb");
    if(pArchivo == NULL){
        cout<<"ARCHIVO ERRONEO"<<endl;
        return reg;
    }
    fseek(pArchivo, sizeof(Jugador)*pos, 0);
    fread(&reg, sizeof(Jugador), 1, pArchivo);
    return reg;
    fclose(pArchivo);
}
bool modificarEnDisco(int pos, Jugador aux){
    FILE *pArchivo;
    bool resultado;
    pArchivo = fopen("Jugadores.dat","rb+");
    if(pArchivo == NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fseek(pArchivo, sizeof(Jugador)*pos,0);
    resultado = fwrite(&aux, sizeof(Jugador),1,pArchivo);
    fclose(pArchivo);
    return resultado;
}
bool modificarFecha(){
    int n, pos;
    bool fechaEditada;
    Jugador aux;
    cout<<"INGRESE UN DNI: ";
    cin>>n;
    pos = chequearDni(n);
    if(pos < 0){
        cout<<"NO EXISTE REGISTRO CON ESE NUMERO"<<endl;
        return false;
    }else{
        aux = leerDeDisco(pos);
        if(aux.getEstado() == false){
            cout<<"EL REGISTRO YA HA SIDO DADO DE BAJA"<<endl;
            return false;
        }
    }

    cout<<"INGRESE UNA NUEVA FECHA: "<<endl;
    Fecha nuevaFecha;
    nuevaFecha.Cargar();
    system("cls");
    aux.setFechaInsc(nuevaFecha);
    fechaEditada = modificarEnDisco(pos, aux);
    if(fechaEditada) {
        cout<<"FECHA MODIFICADA CON EXITO!"<<endl;
    }else{
        cout<<"NO SE PUDO REALIZAR EL CAMBIO"<<endl;
    }
    return fechaEditada;
}
bool eliminar(){
    int n, pos;
    bool dadoBaja;
    Jugador aux;
    cout<<"INGRESE UN DNI: ";
    cin>>n;
    pos = chequearDni(n);
    if(pos < 0){
        cout<<"NO EXISTE REGISTRO CON ESE NUMERO"<<endl;
        return false;
    }else{
        aux = leerDeDisco(pos);
        if(aux.getEstado() == false){
            cout<<"EL REGISTRO YA HA SIDO DADO DE BAJA"<<endl;
            return false;
        }
    }

    cout<<"DAREMOS DE BAJA ESTE REGISTRO"<<endl;
    system("pause");
    system("cls");
    aux.setEstado(false);
    dadoBaja = modificarEnDisco(pos,aux);
    if(dadoBaja) cout<<"EL REGISTRO HA SIDO DADO DE BAJA"<<endl;
    else cout<<"NO SE PUDO REAlIZAR LA BAJA"<<endl;
    return dadoBaja;
}









#endif // CLSJUGADOR_H_INCLUDED
