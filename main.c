/* Escribir un programa que permita a dos personas jugar el juego de sumar 15. La suma se irá obteniendo
a partir de los elementos ocultos almacenados en un vector generados de manera aleatoria. Cada
jugador deberá seleccionar por turno una posición del vector para que el programa sume el valor oculto
al puntaje del jugador. A continuación, las reglas del juego:
1. El programa deberá generar 20 números aleatorios del 1 al 10 que deberán ser almacenados en
un vector.
2. Los jugadores podrán elegir una posición del vector por turno. El jugador 1 elige primero.
3. Los jugadores no podrán ver los números aleatorios almacenados en el vector. Por lo tanto, cada
vez que un jugador elija una posición del vector, el programa deberá indicar el número que se
encuentra en dicha posición y la suma obtenida hasta el momento.
4. Una posición del vector solo puede ser elegida por un jugador. Por lo tanto, el programa deberá
realizar esta validación. El programa deberá mostrar en pantalla todas las posiciones ya elegidas
y el código del jugador quién realizó la elección.
5. El juego termina cuando uno de los jugadores obtiene la suma de 15.
6. Si en algún momento la suma supera 15, el programa deberá permitir al jugador ingresar un
número que deberá ser restado de la sumatoria del jugador para que pueda continuar en el
juego. Este procedimiento se podrá realizar hasta en tres ocasiones por cada jugador. Cuando
se supere esta cantidad, el jugador será descalificado, quedando como ganador el otro jugador.
7. Si ninguno de los jugadores obtiene suma 15 y ya no quedan posiciones a elegir, el programa
deberá indicar el jugador ganador teniendo en cuenta la suma que más se aproxima a 15.*/

//incluimos las librerias necesarias
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//funcion principal
int main()
{
    //vector donde se almacena los nros aleatorios
    int vector[20];

    //declarar e inicializar vector que almacena las posiciones elegidas
    int pos[20];
    for (int i = 0; i < 20; i++) pos[i] = 0;

    //indice para el vector de posiciones
    int c = 0;

    //bandera para comprobar si la posición ya fue ingresada
    int band = 0;

    //variable donde se almacenan la cantidad de puntos a restar
    int n;

    //contador de veces que se restaron puntos de forma manual
    int cA = 3;
    int cB = 3;

    //variables que almacenan las posiciones seleccionadas por los jugadores
    int a,b;

    //acumulador de puntos para los jugadores
    int sA = 0;
    int sB = 0;

    //definir la semilla que genera nros aleatorios con el tiempo de ejecución
    srand(time(NULL));

    for (int i = 0; i < 20; i++)        //cargar el vector con nros aleatorios
    {
        vector[i] = rand()%10 + 1;
    }

    //proceso principal
    do
    {
        //ingresar y validar las jugadas del jugador 1
        do
        {
            band = 0;
            printf("\nIngrese una posicion (1-20) para el jugador 1 :");
            scanf("%d",&a);
            for (int i = 0; i < 20; i++)
            {
                if (a==pos[i])
                {
                    printf("\nPosicion ya ingresada");
                    band=1;
                }
            }  
        }while(a<0||a>20||band==1);
        //almacenar y contar una posicion
        pos[c] = a;
        c++;
        //acumulacion de puntos
        sA+=vector[a-1];        
        printf("\nEl valor en la posicion %d es : %d",a,vector[a-1]);
        printf("\nCantidad de puntos acumulados %d",sA);
        //evaluacion de suma de puntos (si superan 15)
        if (sA>15)
        {
            do
            {
                printf("\nCantidad de puntos acumulados mayor a 15, ingrese puntos a restar :");
                scanf("%d",&n);
            } while (sA-n>=15);
            sA-=n;
            cA--;
        }
        //evaluar si el primer jugador llego a los 15 puntos para que el segundo jugador no vuelva a ingresar
        if(sA==15) break;
        
        //ingresar y validar las jugadas del jugador 2
        do
        {
            band = 0;
            printf("\nIngrese una posicion (1-20) para el jugador 2 :");
            scanf("%d",&b);
            for (int i = 0; i < 20; i++)
            {
                if (b==pos[i])
                {
                    printf("\nPosicion ya ingresada");
                    band=1;
                }
            }  
        }while(b<0||b>20||band==1);
        //almacenar y contar una posicion
        pos[c] = b;
        c++;
        //acumulacion de puntos
        sB+=vector[b-1];
        printf("\nEl valor en la posicion %d es : %d",b,vector[b-1]);
        printf("\nCantidad de puntos acumulados %d",sB);
        //evaluacion de suma de puntos (si superan 15)
        if (sB>15)
        {   
            do
            {
                printf("\nCantidad de puntos acumulados mayor a 15, ingrese puntos a restar :");
                scanf("%d",&n);
            } while (sB-n>=15);
            sB-=n;
            cB--;
        }
    } while (sA<15&&sB<15&&cA>0&&cB>0);

    //evaluacion e impresion de resultados
    if (sA==15) printf("\nEl ganador es el jugador 1");
    else if (sB == 15) printf("\nEl ganador es el jugador 2");
    else if (cA == 0) printf("\nJugador 1 descalificado - El ganador es el jugador 2");
    else if (cB == 0) printf("\nJugador 2 descalificado - El ganador es el jugador 1");
    
    return 0;
}
