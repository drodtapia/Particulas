# Velocidad** y Fuerza de Lorentz de Particulas en C++

## Descripción

Este programa en C++ es una herramienta diseñada para analizar un conjunto de particulas cuya cinemática es descrita por,
$$\vec{r}_n(t,n)= \frac{2\pi t}{n}\cos^5(nt)\sin^3(\cos(t/n))\hat{x}+3n\pi t\cos^3(\cos(\sin(t/n)))\hat{y}+n\pi t^2\cos^4(\exp(-nt))\hat{z}$$
y determinar el modulo de la  **Velocidad** y **Fuerza de Lorentz** más alta y más baja dentro de este conjunto.
donde $n \geq 1$ representa la partıcula n-esima. El numero de partıculas lo leera de la
primera lınea de un archivo de la forma,

$$\begin{matrix}
 N  & & &  &  &  &  & &&&&&&&&
\end{matrix}\\$$

$$\begin{matrix}
 &Q_1& E_{1x} &E_{1y}  &E_{1z}  &B_{1x}  &B_{1y}  &B_{1z} \\ 
&\vdots &\vdots  &\vdots  &\vdots  &\vdots  & \vdots & \vdots\\ 
&Q_n& E_{nx} &E_{ny}  &E_{nz}  &B_{nx}  &B_{ny}  &B_{nz}& 
\end{matrix}$$

donde $N$ es el numero total de partıculas, $E_{ni}$ es el campo electrico en la componente
$i = x, y, z$ y $B_{ni}$ es el campo magnetico en la componente $i = x, y, z$. El valor de $N$ sera
arbitrario para cualquier conjunto de datos.
## Instrucciones de Uso
- El proyecto incluye un archivo Makefile para facilitar la compilación del programa.
- Asegúrate de que el directorio de fuente contenga todos los archivos del repositorio para compilar el programa.

## Funcionalidades del Makefile:
El Makefile proporciona las siguientes funcionalidades adicionales:
run: Para ejecutar el programa una vez compilado
```bash
make run
```
clean: Sirve para borrar los archivos con extensión .o y extensión .~
```bash
make clean
```
borra: Abarca un poco más que clean, solo que ahora además borra los .dat, png y .exe
```bash
make run
```
### Compilación:
- Abre una terminal en el directorio donde se encuentra los archivo del repositorio.
- Compila el programa utilizando el siguiente comando:
```bash
  make

```
### Ejecución:
Una vez compilado, ejecute el siguiente comando y siga las instrucciones proporcionadas en pantalla
```bash
  make run
```  
### Requisitos y Dependencias:
- Compilador de C++: Necesitarás un compilador de C++ instalado en tu sistema. Por ejemplo, GCC en sistemas Unix/Linux o MinGW en Windows.
- Make: Necesitarás tener la herramienta make instalada en tu sistema para poder utilizar el archivo Makefile y compilar tu proyecto.

### Ejemplos y Demostraciones:
A continuación se muestra un ejemplo del programa:
```bash
$ make run
Ingrese el nombre del archivo que contiene los datos de la particula (nombre_archivo.txt) o path: datos.dat

La partícula más rapida es: 𝑽_131: -3.0786x̂ + 207.854ŷ +8650.17 ẑ
La partícula más lenta es: 𝑽_1: 0.0110245x̂ + 4.85198ŷ +65.4154 ẑ
La partÍcula que se ve expuesta a una mayor fuerza de Lorentz es: F_131: 42144.2x̂ + 8536.09ŷ +-190.101 ẑ
La partÍcula que se ve expuesta a una menor fuerza de Lorentz es: F_1: -5.39228x̂ + -0.830447ŷ +-0.540302 ẑ

```
### Contribución y Colaboración

¡Tu contribución es bienvenida! Si deseas contribuir con mejoras, correcciones o nuevas características, aquí hay algunas formas de hacerlo:

1. **Informar Problemas:** Si encuentras errores o tienes ideas para nuevas características, por favor abre un problema en el [rastreador de problemas](https://github.com/drodtapia/Particulas/issues).
   
2. **Enviar Pull Requests:** Si has realizado mejoras en el código, puedes enviar un pull request. Asegúrate de que tu código esté bien probado y documentado.

3. **Comentar y Discutir:** Incluso si no puedes contribuir con código, puedes participar en las discusiones sobre problemas y características. Tus comentarios son valiosos para mejorar el proyecto.

4. **Compartir:** ¡Ayuda a difundir este proyecto compartiéndolo con tus amigos y colegas!

¡Gracias por tu interés en contribuir al proyecto!

### Licencia

Este proyecto está bajo la Licencia [Creative Commons Attribution-NonCommercial 4.0 International License](https://creativecommons.org/licenses/by-nc/4.0/).

Esto significa que puedes:

- Compartir: copiar y redistribuir el material en cualquier medio o formato.
- Adaptar: remezclar, transformar y construir sobre el material.

Bajo los siguientes términos:

- Atribución: debes dar crédito de manera adecuada, proporcionar un enlace a la licencia e indicar si se han realizado cambios. Puedes hacerlo de cualquier manera razonable, pero no de una manera que sugiera que el licenciante te respalda a ti o al uso que haces del material.
- No Comercial: no puedes utilizar el material con fines comerciales.

Leer el texto completo de la licencia [aquí](https://creativecommons.org/licenses/by-nc/4.0/legalcode).

### Créditos y Reconocimientos
Desarrollado por David Rodríguez.

### Contacto
Si tienes alguna pregunta o sugerencia, no dudes en contactar a drodtapia@gmail.com.
