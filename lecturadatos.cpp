
#include<iostream> 
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include "particula.h"    //incluimos la clase Particula
#include "lecturadatos.h"  //incluimos la clase Lecturadatos

Lecturadatos::Lecturadatos(){ //constructor por defecto
}

Lecturadatos::Lecturadatos(string _nombre_archivo){ //constructor que recibe el archivo
	nombre_archivo = _nombre_archivo;
}

void Lecturadatos::set_nombre_archivo(string _nombre_archivo){ //Se establece el nombre de archivo
	nombre_archivo = _nombre_archivo;
}


string Lecturadatos::get_nombre_archivo() //Obtenemos el nombre del archivo
{ 
	return nombre_archivo;
}

void Lecturadatos::set_VEC_PARTICULA() //Se establece el vector con las caracteristicas de las particulas
{ 
	                     
	string name;
	name = nombre_archivo;   //Se asigna el nombre del archivo ingresado
	
	ifstream datos(name);  //Se leen los datos		
	
	int i=0, N;                 
	datos >> N;   // Se lee la cantidad de particulas del sistema
	vector<Particula> vector_particula(N); // se crea un vector de largo N que recibira las caracteristicas de cada particula
	
	while(i<N)//Lee todo el archivo hasta el final
	{ 
		double a, b, c, d, e, f, g;
		                           
		datos>>a>>b>>c>>d>>e>>f>>g; //Se asignan estos valores a la cantidad de columnas del  archivo, donde a=Q,b=Ex,c=Ey,d=Ez,e=Bx,f=By,g=Bz
		                            
		
		Particula Q(a,b,c,d,e,f,g); //Se crea el objeto particula definido por (a,b,c,d,e,f,g)=(Q,Ex,Ey,Ez,Bx,By,Bz)
		 
		//cout << "La particula ("<<i+1<<") es: " << Q << endl; 
		
		vector_particula[i] = Q;  //El vector va siendo llenado con las particulas indicadas en el archivo, en orden 

		i=i+1;            
	
	VEC_PARTICULA = vector_particula;  // El vector con todos los elementos del archivo es ingresado a nuestro vector "VEC_PARTICULA" 
	}
}

vector<Particula> Lecturadatos::get_VEC_PARTICULA() //Se obtiene el vector con las caracteristicas de las particulas
{
	return VEC_PARTICULA;
}



