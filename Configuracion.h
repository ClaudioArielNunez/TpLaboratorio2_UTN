#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED



void copiaDeJugadores(){
    Jugador reg;
    FILE *pArchivoJug;
    FILE *pArchivoJugBack;

    pArchivoJug = fopen("Jugadores.dat", "rb");
     if (pArchivoJug == NULL) {
        cout <<"ARCHIVO ERRONEO"<<endl;
        return;
    }
    pArchivoJugBack = fopen("copiaJugadores.bkp", "wb");


     if (pArchivoJugBack == NULL) {
        cout << "ARCHIVO ERRONEO" << endl;
        return;
    }

    while (fread(&reg, sizeof(Jugador), 1, pArchivoJug)) {
            if(reg.getEstado() == true){
                fwrite(&reg, sizeof(Jugador), 1, pArchivoJugBack);
            }
    }
    fclose(pArchivoJug);
    fclose(pArchivoJugBack);
    cout << "COPIA REALIZADA CON EXITO" << endl;
}

void copiaDeDeportes(){
    Deporte reg;
    FILE *pArchivoDep;
    FILE *pArchivoDepBack;

    pArchivoDep = fopen("deportes.dat","rb");
    if(pArchivoDep == NULL){
        cout<<"ARCHIVO ERRONEO"<<endl;
        return;
    }

    pArchivoDepBack = fopen("copiaDeportes.bkp","wb");

    if(pArchivoDepBack == NULL){
        cout<<"ARCHIVO ERRONEO"<<endl;
        return;
    }

    while(fread(&reg, sizeof(Deporte), 1, pArchivoDep)){
        if(reg.getEstadoDeporte() == true){
            fwrite(&reg, sizeof(Deporte), 1, pArchivoDepBack);
        }
    }
    fclose(pArchivoDep);
    fclose(pArchivoDepBack);
    cout<<"ARCHIVO COPIADO CON EXITO"<<endl;
}

void copiaDeTipoDeDeportes(){
    TipoDeporte reg;
    FILE *pArchivoTipo;
    FILE *pArchivoTipoBack;

    pArchivoTipo = fopen("TipodeDeporte.dat","rb");
    if(pArchivoTipo == NULL){
        cout<<"ARCHIVO ERRONEO"<<endl;
        return;
    }

    pArchivoTipoBack = fopen("copiaTipodeDeporte.bkp","wb");


    if(pArchivoTipoBack == NULL){
        cout<<"ARCHIVO ERRONEO"<<endl;
        return;
    }

    while(fread(&reg, sizeof(TipoDeporte), 1, pArchivoTipo)){
        if(reg.getEstadoTD() == true){
            fwrite(&reg, sizeof(TipoDeporte), 1, pArchivoTipoBack);
        }
    }
    fclose(pArchivoTipo);
    fclose(pArchivoTipoBack);
    cout<<"ARCHIVO COPIADO CON EXITO"<<endl;
}

void copiaDeEquipos(){
    Equipo reg;
    FILE *pArchivoEquipo;
    FILE *pArchivoEquipoBack;

    pArchivoEquipo = fopen("equipos.dat","rb");
    if(pArchivoEquipo == NULL){
        cout<<"ARCHIVO ERRONEO"<<endl;
        return;
    }

    pArchivoEquipoBack = fopen("copiaEquipos.bkp","wb");



    if(pArchivoEquipoBack == NULL){
        cout<<"ARCHIVO ERRONEO"<<endl;
        return;
    }

    while(fread(&reg, sizeof(Equipo), 1, pArchivoEquipo)){
        if(reg.getEstadoEq() == true){
            fwrite(&reg, sizeof(Equipo), 1, pArchivoEquipoBack);
        }
    }
    fclose(pArchivoEquipo);
    fclose(pArchivoEquipoBack);
    cout<<"ARCHIVO COPIADO CON EXITO"<<endl;
}



void restaurarJugadores(){
    Jugador reg;
    FILE *pArchivoJugBack;
    FILE *pArchivoJug;

    pArchivoJugBack = fopen("copiaJugadores.bkp","rb");
    if(pArchivoJugBack == NULL){
        cout<<"ARCHIVO ERRONEO"<<endl;
        return;
    }
    pArchivoJug = fopen("Jugadores.dat","wb");
    if(pArchivoJug == NULL){
        cout<<"ARCHIVO ERRONEO"<<endl;
        return;
    }

    while(fread(&reg, sizeof(Jugador), 1, pArchivoJugBack)){
        fwrite(&reg, sizeof(Jugador), 1, pArchivoJug);
    }
    fclose(pArchivoJugBack);
    fclose(pArchivoJug);
    cout<<"ARCHIVO RESTAURADO"<<endl;
}

void restaurarDeportes(){
    Deporte reg;
    FILE *pArchivoDepBack;
    FILE * pArchivoDep;

    pArchivoDepBack = fopen("copiaDeportes.bkp","rb");
    if(pArchivoDepBack == NULL){
        cout<<"ARCHIVO ERRONEO"<<endl;
        return;
    }
    pArchivoDep = fopen("deportes.dat","wb");
    if(pArchivoDep == NULL){
        cout<<"ARCHIVO ERRONEO"<<endl;
        return;
    }

    while(fread(&reg, sizeof(Deporte), 1, pArchivoDepBack)){
        fwrite(&reg, sizeof(Deporte), 1, pArchivoDep);
    }
    fclose(pArchivoDepBack);
    fclose(pArchivoDep);
    cout<<"ARCHIVO RESTAURADO CON EXITO"<<endl;
}

void restaurarTipoDeDeportes(){
    TipoDeporte reg;
    FILE *pArchivoTipoBack;
    FILE *pArchivoTipo;

    pArchivoTipoBack = fopen("copiaTipodeDeporte.bkp","rb");
    if(pArchivoTipoBack == NULL){
        cout<<"ARCHIVO ERRONEO"<<endl;
        return;
    }
    pArchivoTipo = fopen("TipodeDeporte.dat","wb");
    if(pArchivoTipo == NULL){
        cout<<"ARCHIVO ERRONEO"<<endl;
        return;
    }

    while(fread(&reg, sizeof(TipoDeporte), 1, pArchivoTipoBack)){
        fwrite(&reg, sizeof(TipoDeporte), 1, pArchivoTipo);
    }
    fclose(pArchivoTipoBack);
    fclose(pArchivoTipo);
    cout<<"ARCHIVO RESTAURADO CON EXITO"<<endl;
}

void restaurarEquipos(){
    Equipo reg;
    FILE *pArchivoEquipoBack;
    FILE *pArchivoEquipo;

    pArchivoEquipoBack = fopen("copiaEquipos.bkp","rb");
    if(pArchivoEquipoBack == NULL){
        cout<<"ARCHIVO ERRONEO"<<endl;
        return;
    }
    pArchivoEquipo = fopen("equipos.dat","wb");
    if(pArchivoEquipo == NULL){
        cout<<"ARCHIVO ERRONEO"<<endl;
        return;
    }

    while(fread(&reg, sizeof(Equipo), 1, pArchivoEquipoBack)){
        fwrite(&reg, sizeof(Equipo), 1, pArchivoEquipo);
    }
    fclose(pArchivoEquipoBack);
    fclose(pArchivoEquipo);
    cout<<"ARCHIVO RESTAURADO CON EXITO"<<endl;
}


void inicioJugadores(){
    Jugador reg;
    FILE *pArchivoInicio;
    FILE *pArchivoJug;

    pArchivoInicio = fopen("copiaInicioJugadores.ini","rb");
    if(pArchivoInicio == NULL){
        cout<<"ARCHIVO ERRONEO"<<endl;
        return;
    }
    pArchivoJug = fopen("Jugadores.dat","wb");
    if(pArchivoJug == NULL){
        cout<<"ARCHIVO ERRONEO"<<endl;
        return;
    }

    while(fread(&reg, sizeof(Jugador), 1, pArchivoInicio)){
        fwrite(&reg, sizeof(Jugador), 1, pArchivoJug);
    }

    fclose(pArchivoInicio);
    fclose(pArchivoJug);

}

void inicioDeportes(){
    Deporte reg;
    FILE *pArchivoInicio;
    FILE *pArchivoDep;

    pArchivoInicio = fopen("copiaInicioDeportes.ini","rb");
    if(pArchivoInicio == NULL){
        cout<<"ARCHIVO ERRONEO"<<endl;
        return;
    }
    pArchivoDep = fopen("deportes.dat","wb");
    if(pArchivoDep == NULL){
        cout<<"ARCHIVO ERRONEO"<<endl;
        return;
    }

    while(fread(&reg, sizeof(Deporte), 1, pArchivoInicio)){
        fwrite(&reg, sizeof(Deporte), 1, pArchivoDep);
    }

    fclose(pArchivoInicio);
    fclose(pArchivoDep);
}

void inicioTipoDeDeportes(){
    TipoDeporte reg;
    FILE *pArchivoInicio;
    FILE *pArchivoTipo;

    pArchivoInicio = fopen("copiaInicioTipoDeDeportes.ini","rb");
    if(pArchivoInicio == NULL){
        cout<<"ARCHIVO ERRONEO"<<endl;
        return;
    }
    pArchivoTipo = fopen("TipodeDeporte.dat","wb");
    if(pArchivoTipo == NULL){
        cout<<"ARCHIVO ERRONEO"<<endl;
        return;
    }

    while(fread(&reg, sizeof(TipoDeporte), 1, pArchivoInicio)){
        fwrite(&reg, sizeof(TipoDeporte), 1, pArchivoTipo);
    }

    fclose(pArchivoInicio);
    fclose(pArchivoTipo);
}

void inicioEquipos(){
    Equipo reg;
    FILE *pArchivoInicio;
    FILE *pArchivoEquipo;

    pArchivoInicio = fopen("copiaInicioEquipos.ini","rb");
    if(pArchivoInicio == NULL){
        cout<<"ARCHIVO ERRONEO"<<endl;
        return;
    }
    pArchivoEquipo = fopen("equipos.dat","wb");
    if(pArchivoEquipo == NULL){
        cout<<"ARCHIVO ERRONEO"<<endl;
        return;
    }

    while(fread(&reg, sizeof(Equipo), 1, pArchivoInicio)){
        fwrite(&reg, sizeof(Equipo), 1, pArchivoEquipo);
    }

    fclose(pArchivoInicio);
    fclose(pArchivoEquipo);
}



void establecerDatosDeInicio(){

    inicioJugadores();
    inicioDeportes();
    inicioTipoDeDeportes();
    inicioEquipos();
    cout<<"***** ARCHIVOS DE INICIO RESTAURADOS *****"<<endl;
}


#endif // CONFIGURACION_H_INCLUDED
