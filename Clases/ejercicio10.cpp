#include <iostream>

using namespace std;

class Vehiculo{//Crea la clase vehiculo donde se añaden sus caracteristicas
    private:
        string placa;
        double velocidad;
        double posicion;
    public:
        //Modificar los valores
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
        //Obtener los valores
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

class SimuladorDeTrafico{//Clase de simulador de trafico donde almacenaremos los vehiculos de la simulación
    private:
        Vehiculo carros[180];
    public:
        void agregar(int& i){//Agrega un vehiculo a la simulación
            carros[i].setplaca();
            carros[i].setvelocidad();
            carros[i].setposicion(i);
            i++;
        }
        /*Crea una simulación de la distancia que avanzan los vehiculos en un tiempo determinado
        dependiendo del tiempo que proporciona el usuario*/
        void simular(int& i, double& tiempo){
            string respuestasim;
            for(int j=0;j<i;j++){
                double distancia=carros[j].getvelocidad()*tiempo;
                cout<<"El vehiculo en la posición "<<carros[j].getposicion()<<" avanzó "<<distancia<<" metros"<<endl;
            }
        }
        /*Respecto al tiempo que exista en la simulación detecta si algún vehiculo llegó a colisionar
        para ello es necesario que los vehiculos tengan una distancia en la simulacipon mayor a 100m
        que es el punto de impacto, y que además tengan la misma velocidad*/
        void detectar(int& i, double& tiempo){
            double choques[180];
            int q=0;
            for(int j=0;j<i;j++){
                double distancia=carros[j].getvelocidad()*tiempo;//Calcula la distancia recorrida
                if(distancia>=100){//Si la distancia es igual o mayor a 100
                    choques[q]=carros[j].getposicion();//Almacena el resultado en el arreglo choques
                    q++;
                    for(int k=j+1;k<i;k++){//Busca los vehiculos que tengan la misma velocidad y los almacena en el arreglo choques
                        if(carros[j].getvelocidad()==carros[k].getvelocidad()){
                            choques[q]=carros[k].getposicion();
                            q++;
                        }
                    }
                    if(q>1){//Si hubieron más de 1 vehiculo en la colisión los muestra
                        cout<<"Los vehiculos que impactaron fueron:"<<endl;
                        for(int g=0;g<q;g++){
                            cout<<"-"<<choques[g]<<endl;
                        }
                        j=i;
                    }else{//En caso detecte que unicamente el vehiculo alcanzó los 100m pero no colicionó reinicia el contador de choques
                        q=0;
                    }
                }
            }
            if(q==0){//Si choques está vacio quiere decir que no hubieron colisiones
                cout<<"Ningún vehiculo colisionó"<<endl;
            }
        }
};

int main(){
    SimuladorDeTrafico naves;
    int i=0, band=1;
    double tiempo=0;
    cout<<"\nPara esta simulación se comprende que los vehiculos se"<<endl;//Planteamiento de situación de programa
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
