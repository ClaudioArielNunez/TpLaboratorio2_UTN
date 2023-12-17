#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED



class Fecha{
    private:
        int dia, mes, anio;
    public:
        //Constructor Fecha Actual
        Fecha(){
            time_t tiempo = time(nullptr);
            tm* fecha = localtime(&tiempo);

            dia = fecha->tm_mday;
            mes = fecha->tm_mon + 1;
            anio = fecha->tm_year + 1900;
        }

        //Constructor
        Fecha(int dia, int mes, int anio){

              setDia(dia);
              setMes(mes);
              setAnio(anio);
        }
        void Cargar(){
            Fecha hoy;
            cout<<"DIA: ";
            cin>>dia;
            while(dia<1 || dia>31){
                cout<<"INGRESE UN DIA CORRECTO: "<<endl;
                cin>>dia;
            }
            setDia(dia);
            cout<<"MES: ";
            cin>>mes;
            while(mes<1 || mes>12){
                cout<<"INGRESE UN MES CORRECTO: "<<endl;
                cin>>mes;
            }
            setMes(mes);
            cout<<"ANIO: ";
            cin>>anio;
            while(anio<1900 || anio>2023){
                cout<<"DEBE INGRESAR UN ANIO ENTRE 1900 Y 2023: "<<endl;
                cin>>anio;
            }
            setAnio(anio);
            if(fechaCorrecta(hoy, dia, mes, anio)){ cout<<"FECHA CORRECTA"<<endl;}
            else {
                    cout<<"INGRESE DENUEVO"<<endl;
                    Cargar();
                 }
        }
        void Mostrar(){
            cout<<"DIA: "<<dia<<endl;
            cout<<"MES: "<<mes<<endl;
            cout<<"ANIO: "<<anio<<endl;
        }
        void mostrarEnLinea(){
            cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
        }
        //Setters

        void setDia(int d){dia = d;}

        void setMes(int m){mes = m;}

        void setAnio(int a){ anio = a;}


        //Getters
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}

        bool fechaCorrecta(Fecha hoy, int d, int m, int a);
};
    bool Fecha::fechaCorrecta(Fecha hoy, int d, int m, int a){
            if (a > hoy.anio || (a == hoy.anio && m > hoy.mes) || (a == hoy.anio && m == hoy.mes && d > hoy.dia)) {
                    cout<<"LA FECHA DE INSCRIPCION NO PUEDE SER SUPERIOR A LA FECHA ACTUAL"<<endl;
                    return false;
        }
        return true;
    }

#endif // CLSFECHA_H_INCLUDED
