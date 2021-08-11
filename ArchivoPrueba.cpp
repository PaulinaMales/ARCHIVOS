#include <iostream>
using namespace std;
#include <fstream>

//Variable local
string nombrearchivo; 

void escribirArchivo();
void leerArchivo();
int MenuOpciones();




//<------------------>
int main(){ 
int opcion = 1;
char k = 's';


 while ( opcion != 0 ){

  switch (MenuOpciones()){

     case 1:
     escribirArchivo();
     break;

     case 2:
     leerArchivo();
     break;

     default:
     break;
 

     }

    cout << "Desea continuar? "<<endl;
    cout << "s = SI <--> n = NO"<<endl;
    cin >> k;

    if (k == 's'){
        opcion = 1;

    }else { opcion = 0 ; }

    



 }

  return 0;
}
//<------------------>




int MenuOpciones(){
int op;
    cout << "\tMenu"<<endl;
    cout << "1. Ingresar Datos"<<endl;
    cout << "2. Mostrar Datos"<<endl;
    cin >> op;
    cin.ignore();
    return op;
}



void escribirArchivo()
{
  string nombre;
  string apellido;
  string carrera;
  int edad;
  char r;
  ofstream archivoprueba;
  cout<<"Ingrese el nombre del archivo: ";
  getline(cin,nombrearchivo);

  archivoprueba.open(nombrearchivo.c_str(),ios::out);
  do
  {
    cout<<"\t Ingrese el nombre:";
    getline(cin,nombre); 
    cout<<"\t Ingrese el apellido:";
    getline(cin,apellido); 
    cout<<"\t Ingrese el edad:";
    cin>>edad;
    cin.get();
    cout <<"\t Ingrese la carrera:";
    getline(cin,carrera);

    archivoprueba<<nombre<<" "<<apellido<<" "<<edad<<" "<<carrera<<endl;

    cout<<"Desea ingresar otro contacto s/n ";

    cin>>r;

    cin.ignore();

  }
   while(r=='s');

  archivoprueba.close();

}




void leerArchivo()
{
  string nombre;
  string apellido;
  string carrera;
  int edad;
  ifstream archivolectura(nombrearchivo);
  string texto;

  while(!archivolectura.eof()){
      archivolectura>>nombre>>apellido>>edad>>carrera;

      if(!archivolectura.eof()){
              cout<<"\t CONTACTOS "<<endl;
              cout<<" Nombre : "<<nombre<<endl;
              cout<<" Apellido : "<<apellido<<endl;
              cout<<" Edad : "<<edad<<endl;
              cout<<" Carrera : "<<carrera<<endl; 
              cout<< "\n\n";
            }
    }
  archivolectura.close();

}
