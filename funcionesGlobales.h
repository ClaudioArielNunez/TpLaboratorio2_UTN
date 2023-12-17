#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED




    void cargarCadena(char *palabra, int tam){
    int i = 0;
    fflush(stdin);
    for (i = 0 ; i < tam ; i++ ){
        palabra[i] = cin.get();
        if(palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
    }

    bool SiExiste(const char *archivo){
        FILE * pArchivo;
        pArchivo = fopen(archivo ,"rb");
        if(pArchivo == NULL){
            return false;
        }
        return true;
    }








#endif // FUNCIONESGLOBALES_H_INCLUDED
