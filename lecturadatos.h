#ifndef LECTURADATOS_H
#define LECTURADATOS_H

#include<iostream> 
#include<fstream>
#include<stdlib.h>    
#include<string.h>
#include<vector>

#include "particula.h"  //incluimos la clase Particula

using namespace std;

class Lecturadatos{ //creamos la clase
	private:
		string nombre_archivo;        //contiene el nombre del archivo con el que se inicializa el objeto de la clase Lecturadatos
		vector<Particula> VEC_PARTICULA; //es el vector con elementos tipo Particula
		
	public:                                   
		Lecturadatos();                              //constructor
		Lecturadatos(string);                        //constructor que recibe el nombre de un archivo
		
		void set_nombre_archivo(string);        //establece el nombre del archivo manualmente
		string get_nombre_archivo();            //devuelve el nombre del archivo
		
		void set_VEC_PARTICULA();              //Se establece el vector con las caracteristicas de las particulas
		vector<Particula> get_VEC_PARTICULA();     //devuelve el vector con las cargas

};



#endif
