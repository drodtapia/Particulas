#include<iostream>
#ifndef PARTICULA_H
#define PARTICULA_H



using namespace std;

class Particula{      //Se crea la clase
	private:
		double Q;   // se declaran los componentes de las particulas
		double Ex;
		double Ey; 
		double Ez;
		double Bx; 
		double By;     
		double Bz; 
	public:
		Particula();//constructor por defecto
		Particula(double,double,double,double,double,double,double); //Constructor
		void set_Q(double); //Se crean funciones para establecer los componentes
		void set_Ex(double);         
		void set_Ey(double);                
		void set_Ez(double);
		void set_Bx(double);         
		void set_By(double);                
		void set_Bz(double);                  

		double get_Q(); //Se devuelven los valores de las componentes
		double get_Ex();    
		double get_Ey();   
		double get_Ez();
		double get_Bx();    
		double get_By();   
		double get_Bz();    

};

//double operator * (Particula,Particula); //sobrecarga de los operadores 
//double operator - (Particula,Particula); 

ostream & operator << (ostream &,Particula);    //funcion no utilizada en el main final, sirve para mostrar los objetos
                                            	// particulas en pantalla de la forma (Q,Ex,Ey,Ez,Bx,By,Bz)
#endif
