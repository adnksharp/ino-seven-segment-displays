# Seven segment display CC
Mostrar numeros usando el display de siete segmentos de tipo catodo comun.

## Hardware y software necesarios
- Placa de desarrollo Arduino 
- Display de 7 segmentos catodo común
- 7 resistencias de $\displaystyle 200\Omega$ a 1 $\displaystyle K\Omega$
- [Arduino IDE](https://www.arduino.cc/en/software) o [Arduino CLI](https://arduino.github.io/arduino-cli/0.23/installation/)

## Funcionamiento
### Variables
- ```number```: Matrix que contiene el estado en el que debe estar cada LED para mostar el numero.
- ```segments```: Vector que contiene los pines en el que se conecta cada segmento.
- ```common```: Vector que contiene los pines en el que se conecta el common si se controlan varios displays.
- ```No``` y ```f```: Vector o variable que contiene el numero que mostrara cada display.
- ```c``` e ```i```: Variables para el funcionamiento de bucles tipo for


### Funcionamiento
```
  2 
7   3
  8  
6   4
  5  9
```

Dentro de una función se puede usar bucles ```for``` para poner el pin ```segments[c]``` en el estado ```number[c][i]```, donde: 
- ```c```: Variable correspondiente al bucle for.
- ```i```: Variable del numero que se mostrara en el display.

[![display.png](https://i.postimg.cc/zD9BbVnS/display.png)](https://postimg.cc/t7Ny8RvY)

##### Para el funcionamiento de varios displays, se pone el pin ```common[c]``` en el estado alto, se pone el pin ```segments[c]``` en el estado ```number[c][i]``` y se pone el pin ```common[c]``` en el estado bajo.
##### La función ```count``` se usa para cambiar el valor de ```No``` para el numero que se mostrara en cada display.
[![displays.png](https://i.postimg.cc/mgWKHGX5/displays.png)](https://postimg.cc/2VT0sgfQ)

El valor de cada elemento del vector cambia en unidades, decenas, centenas o miles segun la posicion que corresponde a cada display.

    No[3]++;
    if (No[3] > 9)
    {
        No[3] = 0;
        No[2]++;
        if (No[2] > 9)
        {
            No[2] = 0;
            No[1]++;
            if (No[1] > 9)
            {
                No[1] = 0;
                No[0]++;
                if (No[0] > 9)
                    No[0] = 0;
            }
        }
    }
