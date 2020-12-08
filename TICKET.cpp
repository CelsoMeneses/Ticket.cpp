#include <iostream>
#include <stdlib.h>
#include <locale.h>
using namespace std;

class Productos{
      protected:
                 int prod1,prod2,prod3,compra1,compra2,compra3;
                 int count1,count2,count3,count4;

      public:
              //Sobrecargando el constructor
             Productos ();
             Productos(int,int,int,int,int,int);
             void impP();
             void comprarP();
};

Productos::Productos(int p1,int p2,int p3,int c1,int c2, int c3){

           prod1=p1;  prod2=p2;   prod3=p3;
           count1=c1;count2=c2;count3=c3;
};

void Productos::impP(){

    cout<<"   Productos           Precio"<<endl<<endl<<endl;
    cout<<"1.-Agua                 $"<<prod1<<endl<<endl;
    cout<<"2.-Refresco             $"<<prod2<<endl<<endl;
    cout<<"3.-Sabritas             $"<<prod3<<endl<<endl;
}

void Productos::comprarP(){
     int opc;
     cout<<"Cual desea adquirir? :";
     cin>>opc;
     cout<<endl<<endl<<endl;
     switch(opc){

            case 1: cout<<"Se subio el producto al carrito"; compra1=prod1; count1++; break;
            case 2: cout<<"Se subio el producto al carrito"; compra2=prod2; count2++; break;
            case 3: cout<<"Se subio el producto al carrito"; compra3=prod3; count3++; break;
}//switch
}
/******************************************************************************************************************************************************************************/

class Servicios{
       protected:
                 float ser1,ser2,ser3,compS1,compS2,compS3;
                  int countS1,countS2,countS3,countS4;
      public:
              //Sobrecarga
             Servicios();
             Servicios(float,float,float,int,int,int);
             void impS();
             void comprarS();
};

Servicios::Servicios(float s1,float s2,float s3,int cS1,int cS2, int cS3){

           ser1=s1;  ser2=s2;   ser3=s3;
           countS1=cS1;countS2=cS2;countS3=cS3;
};

void Servicios::impS(){

     cout<<"  Servicios                  Precio"<<endl<<endl<<endl;
     cout<<"1.-Mensualidad Luz                $"<<ser1<<endl<<endl;
     cout<<"2.-Mensualidad Agua               $"<<ser2<<endl<<endl;
     cout<<"3.-Mensualidad Gas natural        $"<<ser3<<endl<<endl;

}
void Servicios::comprarS(){

     int opc2;

     cout<<"Cual desea adquirir? :";
     cin>>opc2;
     cout<<endl<<endl<<endl;
     switch(opc2){

                 case 1: cout<<"  Se subio el producto al carrito"; compS1=ser1;  countS1++;  break;
                 case 2: cout<<"  Se subio el producto al carrito"; compS2=ser2; countS2++; break;
                 case 3: cout<<"  Se subio el producto al carrito"; compS3=ser3;  countS3++;break;
}//switch
}
/************************************************************************************************************************************************************************/

class tienda:public Productos,public Servicios{

      public:
              int contador;
      public:
                 tienda(int,int,int,int,int,int,float,float,float,int,int,int,int);
                 tienda& suma();

      //Haciendo uso de la amistad de clases
      friend class Ticket;
};

tienda::tienda(int p1,int p2,int p3,int c1,int c2, int c3,float s1,float s2,float s3,int cS1,int cS2, int cS3,int con) : Productos(p1,p2,p3,c1,c2,c3),Servicios(s1,s2,s3,cS1,cS2,cS3){

                ser1=s1;  ser2=s2;   ser3=s3;
                prod1=p1;  prod2=p2;   prod3=p3; count1=c1;count2=c2;count3=c3;
                 countS1=cS1;countS2=cS2;countS3=cS3;
                 contador=con;

}
tienda& tienda::suma(){
   contador++;
}

/***************************************************************************************************************************************************************************/

class Ticket{

      public:
              float total,cambio,dinero;
      public:
             Ticket(int t){total=t;}
             void imprimir(tienda obj);
             void contabilidad(tienda obj);


};

void Ticket::contabilidad(tienda obj){
	

     cout<<"    Compras  "<<endl<<endl<<endl;
     cout<<"              Productos  "<<endl<<endl<<endl;
     cout<<"Cantidad"<<endl<<endl;

     if(obj.count1>0){
     cout<<obj.count1<<"             Agua             $"<<obj.compra1*obj.count1<<endl;
                                               total=total+obj.compra1*obj.count1;
                 }

      if(obj.count2>0){
     cout<<obj.count2<<"             Refresco          $"<<obj.compra2*obj.count2<<endl;
                                                 total=total+obj.compra2*obj.count2;
                 }

      if(obj.count3>0){
     cout<<obj.count3<<"              Sabritas           $"<<obj.compra3*obj.count3<<endl;
                                                   total=total+obj.compra3*obj.count3;
                 }


     cout<<endl;

     cout<<"                Servicios "<<endl<<endl;
    cout<<"Cantidad"<<endl<<endl;
      if(obj.countS1>0){
     cout<<obj.countS1<<"                  Luz              $"<<obj.compS1*obj.countS1<<endl;
                                                       total=total+obj.compS1*obj.countS1;
                 }
      if(obj.countS2>0){
     cout<<obj.countS2<<"                 Agua              $"<<obj.compS2*obj.countS2<<endl;
                                                         total=total+obj.compS2*obj.countS2;
                 }
      if(obj.countS3>0){
     cout<<obj.countS3<<"                    Gas            $"<<obj.compS3*obj.countS3<<endl;
                                                         total=total+obj.compS3*obj.countS3;
                 }

     cout<<endl<<"Total a pagar: $"<<total<<endl<<endl;

     cout<<"Dinero que recibo: $";
     cin>>dinero;
     cout<<endl<<endl;
     while(dinero<total){
      cout<<"No le alcanza favor de dar una cantidad mas grande: $";
      cin>>dinero;
      cout<<endl;
      }
     cambio=dinero-total;
     cout<<"Compras realizadas, imprimiremos su Ticket"<<endl;

}

void Ticket::imprimir(tienda obj){

     cout<<"               **  Gracias por comprar en  TIENDA Doña Lupita **"<<endl;
    cout<<"                        Las compras que has realizado son: "<<endl<<endl;
     cout<<"*********************************************************************************"<<endl;
     cout<<"              *             Productos                       Precio         "<<endl<<endl;
     cout<<"     Cantidad"<<endl<<endl;
    
     if(obj.count1>0){
     cout<<"   "<<obj.count1<<"                    Agua                $"<<obj.compra1<<  " Total: $"<<obj.compra1*obj.count1<<endl;

                 }

      if(obj.count2>0){
     cout<<"   "<<obj.count2<<"                    Refresco            $"<<obj.compra2<<  " Total: $"<<obj.compra2*obj.count2<<endl;

                 }

      if(obj.count3>0){
     cout<<"   "<<obj.count3<<"                      Sabritas           $"<<obj.compra3<<  " Total: $"<<obj.compra3*obj.count3<<endl;

                 }


     cout<<"*********************************************************************************"<<endl<<endl;

     cout<<"               *          Servicios "<<endl<<endl;
    cout<<"      Cantidad"<<endl<<endl;
      if(obj.countS1>0){
     cout<<"   "<<obj.countS1<<"                          Luz                 $"<<obj.compS1<<  " Total: $"<<obj.compS1*obj.countS1<<endl;

                 }
      if(obj.countS2>0){
     cout<<"   "<<obj.countS2<<"                         Agua                 $"<<obj.compS2<<  " Total: $"<<obj.compS2*obj.countS2<<endl;

                 }
      if(obj.countS3>0){
     cout<<"   "<<obj.countS3<<"                         Gas                   $"<<obj.compS3<<  " Total: $"<<obj.compS3*obj.countS3<<endl;;

                 }

     cout<<"************************************************************************************"<<endl<<endl;
     cout<<"** Total de Productos y/o Servicios subidos al carrito:     "<<obj.contador<<endl<<endl;
     cout<<"** Total a pagar:                                                   $"<<total<<endl<<endl;
     cout<<"** Dinero recibido:                                                 $"<<dinero<<endl<<endl;
     cout<<"** Cambio:                                                          $"<<cambio<<endl<<endl;
     total=0;

}

/************************************************************************************************************************************************************************/
int main(){
    
    setlocale(LC_CTYPE,"Spanish");
    int  precio1=10,precio2=14,precio3=13;
    float  servicio1=230.34,servicio2=130.46,servicio3=300.50;

    Productos p();
    Servicios s();
    tienda x(precio1,precio2,precio3,0,0,0,servicio1,servicio2,servicio3,0,0,0,0);
    Ticket t(0);

    int opc,opc2,dinero,m=0;

    do{

        system("cls");

        cout<<endl;
        cout<<"             TIENDA Doña Lupita"<<endl<<endl<<endl<<endl;
        cout<<"     1.-Productos"<<endl<<endl;
        cout<<"     2.-Servicios"<<endl<<endl;
        cout<<"     3.-Impresion del Ticket"<<endl<<endl;
        cout<<"     4.-Salir"<<endl<<endl<<endl;
        cout<<"  Opcion: ";
        cin>>opc;

        switch(opc){
                    case 1:system("cls");
                           x.impP();
                           x.comprarP();
                           x.suma();
                           cout<<endl<<endl<<endl<<endl;system("pause");break;
                     case 2:system("cls");
                           x.impS();
                           x.comprarS();
                            x.suma();
                           cout<<endl<<endl<<endl<<endl;system("pause");break;
                     case 3:system("cls");
                            t.contabilidad(x);
                            system("cls");
                            t.imprimir(x);
                            cout<<endl<<endl;system("pause");break;
}
}while(opc!=4);
return 0;
}
