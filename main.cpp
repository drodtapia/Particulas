#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
#include "dual.h"
#include "particula.h"
#include "lecturadatos.h"
//#include <Windows.h> 
using namespace std;

void vel_max(vector<double>, vector<double> ,vector<double>);
void vel_min(vector<double>, vector<double> ,vector<double>);
void F_max(vector<double>, vector<double> ,vector<double>);
void F_min(vector<double>, vector<double> ,vector<double>);

int main()
{
	//SetConsoleOutputCP(65001);
	dual<double> t(1,1);
	vector<double> xv,yv,zv,Fx,Fy,Fz;
	double sx,sy,sz;
	string name;        //creamos el objeto tipo string name
	vector<Particula> v;   //creamos el vector v cuyas que contendra las particulas y sus caracteristicas.
	
	cout<<"Ingrese el nombre del archivo que contiene ";
	cout<<"los datos de la particula (nombre_archivo.txt) o path: " ; 
	cin>>name; 
	cout << endl;


	Lecturadatos lect = Lecturadatos(name);//Se incializa la variable tipo Lecturadatos llamada lect, con el nombre o path entregado en la terminal
	
	//cout << lect.get_nombre_archivo() << endl;
	
	lect.set_VEC_PARTICULA(); //Se establece el vector con objetos tipo Particulas del objeto lect
	v = lect.get_VEC_PARTICULA(); //Se iguala el vector v al vector con particulas del objeto lect 
	
	ifstream archivo(lect.get_nombre_archivo());  
	int i=0, N;	
	archivo >> N;

	for (double n = 1; n <= N; n+=1)
	{
		for (double i = 1; i < 20; i+=0.19)
		{ t(0)=i;
			dual<double> rx = ((2*M_PI*t)/n)*pow(cos(n*t),5)*pow(sin(cos(t/n)),3);
			dual<double> ry =(3*n*M_PI*t)*pow(cos(cos(sin(t/n))),3);
			dual<double> rz =(n*M_PI*t*t)*pow(cos(exp(-1*n*t)),4);
			
			sx += rx(1);
			sy += ry(1);
			sz += rz(1);
		}
	sx /= 100;
	sy /= 100;
	sz /= 100;
	
	xv.push_back(sx);
	yv.push_back(sy);
	zv.push_back(sz);


	}

	for (int j = 0; j < N; ++j)
	{ 	
		Fx.push_back(v[j].get_Q()*(yv[j]*v[j].get_Bz()-zv[j]*v[j].get_By()+v[j].get_Ex()));    
		Fy.push_back(v[j].get_Q()*(zv[j]*v[j].get_Bx()-xv[j]*v[j].get_Bz()+v[j].get_Ey()));
		Fz.push_back(v[j].get_Q()*(xv[j]*v[j].get_By()-yv[j]*v[j].get_Bx()+v[j].get_Ez()));
	}
	
	vel_max(xv, yv, zv);
	vel_min(xv, yv, zv);
	F_max(Fx, Fy, Fz);
	F_min(Fx, Fy, Fz);
	return 0;
}

void vel_max(vector<double> xv, vector<double> yv,vector<double> zv)
{	vector<double> vmax;
	
	for (int i = 0; i < xv.size(); ++i)
	{
		vmax.push_back(sqrt(xv[i]*xv[i]+yv[i]*yv[i]+zv[i]*zv[i]));

	}
	double max = vmax[0];
	for (int j = 0; j < vmax.size(); ++j)
	{
		if (vmax[j] > max)
		{
			max = vmax[j];
		}
	}
	for (int k = 0; k < vmax.size(); ++k)
	{
		if(max==vmax[k])
		{
			cout<<"La partícula más rapida es: 𝑽_"<<k+1<<": "<<xv[k]<<"x̂ + "<<yv[k]<<"ŷ +"<<zv[k]<<" ẑ"<<endl;
		}
	}

}
void vel_min(vector<double> xv, vector<double> yv,vector<double> zv)
{	vector<double> vmin;
	
	for (int i = 0; i < xv.size(); ++i)
	{
		vmin.push_back(sqrt(xv[i]*xv[i]+yv[i]*yv[i]+zv[i]*zv[i]));
	}
	double min = vmin[0];
	for (int j = 0; j < vmin.size(); ++j)
	{
		if (min > vmin[j] )
		{
			min = vmin[j];
		}
	}
	for (int k = 0; k < vmin.size(); ++k)
	{
		if(min==vmin[k])
		{
		cout<<"La partícula más lenta es: 𝑽_"<<k+1<<": "<<xv[k]<<"x̂ + "<<yv[k]<<"ŷ +"<<zv[k]<<" ẑ"<<endl;
		}
	}

}

void F_max(vector<double> Fx, vector<double> Fy,vector<double> Fz)
{	vector<double> Fmax;
	
	for (int i = 0; i < Fx.size(); ++i)
	{
		Fmax.push_back(sqrt(Fx[i]*Fx[i]+Fy[i]*Fy[i]+Fz[i]*Fz[i]));

	}
	double max = Fmax[0];
	for (int j = 0; j < Fmax.size(); ++j)
	{
		if (Fmax[j] > max)
		{
			max = Fmax[j];
		}
	}
	for (int k = 0; k <= Fmax.size(); ++k)
	{
		if(max==Fmax[k])
		{	
			cout<<"La partÍcula que se ve expuesta a una mayor fuerza de Lorentz es: F_"<<k+1<<": "<<Fx[k]<<"x̂ + "<<Fy[k]<<"ŷ +"<<Fz[k]<<" ẑ"<<endl;
		}
	}

}
void F_min(vector<double> Fx, vector<double> Fy,vector<double> Fz)
{	vector<double> Fmin;
	
	for (int i = 0; i < Fx.size(); ++i)
	{
		Fmin.push_back(sqrt(Fx[i]*Fx[i]+Fy[i]*Fy[i]+Fz[i]*Fz[i]));
	}
	double min = Fmin[0];
	for (int j = 0; j < Fmin.size(); ++j)
	{
		if (min > Fmin[j] )
		{
			min = Fmin[j];
		}
	}
	for (int k = 0; k < Fmin.size(); ++k)
	{
		if(min==Fmin[k])
		{
		cout<<"La partÍcula que se ve expuesta a una menor fuerza de Lorentz es: F_"<<k+1<<": "<<Fx[k]<<"x̂ + "<<Fy[k]<<"ŷ +"<<Fz[k]<<" ẑ"<<endl;
		}
	}

}

