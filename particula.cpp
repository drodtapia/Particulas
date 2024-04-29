#include<iostream>
#include "particula.h"
#include<cmath>

Particula::Particula(){ //constructor por defecto
}

//Se define el constructor
Particula::Particula(double _Q, double _Ex, double _Ey, double _Ez, double _Bx, double _By, double _Bz)
{  
	Q = _Q; 
	Ex = _Ex;
	Ey = _Ey;
	Ez = _Ez; 
	Bx = _Bx;
	By = _By;
	Bz = _Bz; 
}

//Se establecen los valores de las componentes
void Particula::set_Q(double _Q)
{
	Q = _Q;
}

void Particula::set_Ex(double _Ex)
{ 
	Ex = _Ex;
}

void Particula::set_Ey(double _Ey)
{ 
	Ey = _Ey;
}

void Particula::set_Ez(double _Ez)
{
	Ez = _Ez;
}
void Particula::set_Bx(double _Bx)
{ 
	Bx = _Bx;
}

void Particula::set_By(double _By)
{ 
	By = _By;
}

void Particula::set_Bz(double _Bz)
{
	Bz = _Bz;
}

//Se obtienen los valores de las componentes
double Particula::get_Q()
{
	return Q;
}

double Particula::get_Ex()
{ 
	return Ex;
}

double Particula::get_Ey()
{
	return Ey;
}

double Particula::get_Ez()
{
	return Ez;
}

double Particula::get_Bx()
{ 
	return Bx;
}

double Particula::get_By()
{
	return By;
}

double Particula::get_Bz()
{
	return Bz;
}


ostream & operator << (ostream & os,Particula p) //Si se pidiera mostrar en pantalla las particulas , se imprimen  de la forma (Q,Ex,Ey,Ez,BX,BY,Bz)
{  
	os << "("<<p.get_Q()<<" , "<<p.get_Ex()<<" , "<<p.get_Ey()<<" , "<<p.get_Ez()<<" , "<<p.get_Bx()<<" , "<<p.get_By()<<" , "<<p.get_Bz()<<")";
	return os;
}



