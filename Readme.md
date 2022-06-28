
# Seven segment display CC
[![dsegment-bb.png](https://i.postimg.cc/sgWXH3hb/dsegment-bb.png)](https://postimg.cc/TKRfpMQc)

Mostrar numeros usando el display de siete segmentos de tipo catodo comun.

      2 
    7   3
      8  
    6   4
      5  9

| Variables | Tipo | Descripcion |
| --------- | ---- | ----------- |
| **number** | bool | Matrix que contienen el estado en el que debe estar cada LED para mostar el numero |
| **segments** | byte | Vector que contiene los pines en el que se conecta cada segmento |
| **common** | byte | Vector que contiene los pines en el que se conecta el common si se controlan varios displays |
| **No** y **f**| byte | Vector o variable que contiene el numero que mostrara cada display |
| **c** e **i** | byte | Variables para el control de bucles |
[![dsegments-bb.png](https://i.postimg.cc/WztpGVVW/dsegments-bb.png)](https://postimg.cc/n9btx6CB)

## Un display de 7 segmentos
Para mostra un numero de 7 segmentos se define el estado de cada uno de los segmentos usando la matriz number y una variable f que contiene el numero que se mostrara.

    digitalWrite(segments[c], number[f][c]);

[![dsegment-esquem-tico.png](https://i.postimg.cc/V6fkNMVc/dsegment-esquem-tico.png)](https://postimg.cc/QBz34BD6)

## Multiples displays de 7 segmentos
Para mostrar varios numeros de 7 segmentos se define un vector que contiene el numero que se mostrara y una matriz que contiene el estado de cada uno de los segmentos.

    digitalWrite(segments[c], number[No[i]][c]);

[![dsegments-esquem-tico.png](https://i.postimg.cc/90Sm1kFW/dsegments-esquem-tico.png)](https://postimg.cc/SY6bxDM5)

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