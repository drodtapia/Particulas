#ifndef DUAL_H
#define DUAL_H

#include <iostream>
#include <cmath>

using namespace std;

template <class T>
class dual
{
private:
  T a;// valor de la funcion
  T b;// valor de la derivada de la funcion

public:
  dual(T=T(0), T=T(0));//constructor generico
  dual(const dual<T>&);//constructor de copia 
  ~dual();//destructor
  dual<T> operator=(const dual<T>&); 
  T & operator()(int);
  T operator()(int) const;
  dual<T> operator-()//operacion unaria
  {
    dual<T> y(-a,b);
    return y;
  }
};

template <class T>
dual<T>::dual(T x1, T x2):a(x1), b(x2)
{ 
}

template <class T>
dual<T>::dual(const dual<T> &h)
{
  a = h.a;
  b = h.b;
}

template <class T>
dual<T>::~dual()
{}

template <class T>
dual<T> dual<T>::operator=(const dual<T>&x)
{
  if(this!=&x)
    {
      a=x.a;
      b=x.b;
    }
  
  return *this;
}

template <class T>
T & dual<T>::operator()(int i)
{
  switch(i)
    {
    case 0:
      return a;
      break;
    case 1:
      return b;
      break;
    default:
      cout<<"indefinido!\n";
      return a;
      break;
    }
}

template <class T>
T dual<T>::operator()(int i) const
{
  switch(i)
    {
    case 0:
      return a;
      break;
    case 1:
      return b;
      break;
    default:
      cout<<"indefinido!\n";
      return a;
      break;
    }
}

template <class T>
dual<T> operator+(const dual<T> &x1, const dual<T> &x2)
{
  return dual<T>(x1(0)+x2(0),x1(1)+x2(1));
}

template <class T>
dual<T> operator*(const dual<T> &x1, const dual<T> &x2)
{
  return dual<T>(x1(0)*x2(0),x1(1)*x2(0)+x1(0)*x2(1));
}

template <class T>
dual<T> operator*(T s, const dual<T> &x2)
{
  return dual<T>(s*x2(0),s*x2(1));
}

template <class T>
dual<T> operator*(const dual<T> &x1, T s)
{
  return dual<T>(s*x1(0),s*x1(1));
}

template <class T>
dual<T> operator*(int s, const dual<T> &x2)
{
  return dual<T>(s*x2(0),s*x2(1));
}

template <class T>
dual<T> operator*(const dual<T> &x1, int s)
{
  return dual<T>(s*x1(0),s*x1(1));
}



template <class T>
dual<T> operator/(const dual<T> &x1, const dual<T> &x2)
{
  return dual<T>(x1(0)/x2(0),(x1(1)*x2(0)-x1(0)*x2(1))/(x2(0)*x2(0)));
}

template <class T>
dual<T> operator/(T s, const dual<T> &x2)
{
  return dual<T>(x2(0)/s,x2(1)/s);
}

template <class T>
dual<T> operator/(const dual<T> &x1, T s)
{
  return dual<T>(x1(0)/s,x1(1)/s);
}

template <class T>
dual<T> operator/(int s, const dual<T> &x2)
{
  return dual<T>(x2(0)/s,x2(1)/s);
}

template <class T>
dual<T> operator/(const dual<T> &x1, int s)
{
  return dual<T>(x1(0)/s,x1(1)/s);
}

template <class T>
dual<T> sin(const dual<T> &x)
{
  return dual<T>(sin(x(0)),cos(x(0))*x(1));
}

template <class T>
dual<T> cos(const dual<T> &x)
{
  return dual<T>(cos(x(0)),-sin(x(0))*x(1));
}
template <class T>
dual<T> exp(const dual<T> &x)
{
  return dual<T>(exp(x(0)),x(1)*exp(x(0)));
}
template <class T>
dual<T> sqrt(const dual<T> &x)
{
  return dual<T>(sqrt(x(0)),(x(1)/2)*(1/sqrt(x(0))));
}

template <class T>
dual<T> log(const dual<T> &x)
{
  return dual<T>(log(x(0)),x(1)/x(0));
}
template <class T>
dual<T> pow(const dual<T> &x, T s)
{
  return dual<T>(pow(x(0),s),x(1)*s*pow(x(0),(s-1)));
}
template <class T>
dual<T> pow(const dual<T> &x, int s)
{
  return dual<T>(pow(x(0),s),x(1)*s*pow(x(0),(s-1)));
}

template <class T>
ostream & operator<<(ostream &os, const dual<T> &x)
{
  os<<"("<<x(0)<<","<<x(1)<<")";
  return os;
}

#endif
