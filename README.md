Escribir un programa que permita a dos personas jugar el juego de sumar 15. La suma se irá obteniendo
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
deberá indicar el jugador ganador teniendo en cuenta la suma que más se aproxima a 15.
