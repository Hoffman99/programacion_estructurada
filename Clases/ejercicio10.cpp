#include <iostream>

using namespace std;

class Vehiculo{
    private:
        string placa;
        double velocidad;
        double posicion;
    public:
        void setplaca(){
            string _placa;
            cout<<"Placa ==> ";
            cin>>_placa;
            this->placa=_placa;
        }
        void setvelocidad(){
            double _velocidad;
            cout<<"Velocidad (m/s) ==> ";
            cin>>_velocidad;
            this->velocidad=_velocidad;
        }
        void setposicion(int& i){
            this->posicion=i;
            cout<<"Posición ==>"<<posicion<<endl;
        }
        string getplaca(){
            return this->placa;
        }
        double getvelocidad(){
            return this->velocidad;
        }
        double getposicion(){
            return this->posicion;
        }
};

class SimuladorDeTrafico{
    private:
        Vehiculo carros[180];
    public:
        void agregar(int& i){
            carros[i].setplaca();
            carros[i].setvelocidad();
            carros[i].setposicion(i);
            i++;
        }

        void simular(int& i, double& tiempo){
            string respuestasim;
            for(int j=0;j<i;j++){
                double distancia=carros[j].getvelocidad()*tiempo;
                cout<<"El vehiculo en la posición "<<carros[j].getposicion()<<" avanzó "<<distancia<<" metros"<<endl;
            }
        }
        void detectar(int& i, double& tiempo){
            double choques[180];
            int q=0;
            for(int j=0;j<i;j++){
                double distancia=carros[j].getvelocidad()*tiempo;
                if(distancia>=100){
                    choques[q]=carros[j].getposicion();
                    q++;
                    for(int k=j+1;k<i;k++){
                        if(carros[j].getvelocidad()==carros[k].getvelocidad()){
                            choques[q]=carros[k].getposicion();
                            q++;
                        }
                    }
                    if(q>1){
                        cout<<"Los vehiculos que impactaron fueron:"<<endl;
                        for(int g=0;g<q;g++){
                            cout<<"-"<<choques[g]<<endl;
                        }
                        j=i;
                    }else{
                        q=0;
                    }
                }
            }
            if(q==0){
                cout<<"Ningún vehiculo colisionó"<<endl;
            }
        }
};

int main(){
    SimuladorDeTrafico naves;
    int i=0, band=1;
    double tiempo=0;
    cout<<"\nPara esta simulación se comprende que los vehiculos se"<<endl;
    cout<<"colocan en un semicirculo y todos van en dirección al centro"<<endl;
    cout<<"la distancia entre estos y el centro es de 100m, que es el"<<endl;
    cout<<"el punto en donde podrían colisionar\n"<<endl;
    cout<<"Para iniciar el programa agregue al menos un vehiculo"<<endl;
    naves.agregar(i);
    while(band==1){
        int respuesta;
        cout<<"Qué desea realizar? (ingrese el número)"<<endl;
        cout<<" ==> Agregar un vehiculo (1)"<<endl;
        cout<<" ==> Simular movimiento de los vehiculos (2)"<<endl;
        cout<<" ==> Detectar colisiones (3)"<<endl;
        cout<<" ==> Salir (4)"<<endl;
        cin>>respuesta;
        switch(respuesta){
            case 1:
                naves.agregar(i);
                break;
            case 2:
                cout<<"Ingrese el tiempo que desea hacer la simulación (s) ==> ";
                cin>>tiempo;
                naves.simular(i, tiempo);
                break;
            case 3:
                naves.detectar(i, tiempo);
                break;
            case 4:
                band=0;
                break;
            default:
                cout<<"Opción inválida";
        }
    }
    return 0;
}