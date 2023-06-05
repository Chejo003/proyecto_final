#include <iostream>
#include <Windows.h>
#include <string>
#include <direct.h>
#include <stdlib.h>
#include <random>
#include <windows.graphics.h>
#include <chrono>
#include <thread>


#define ANCHO 38
#define ALTO 24
using namespace std;
int matrizweb[7][7];
int posicionyicial;

void gotoxy(int x, int y)
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}


void dibujarEje() {

    for (int i = 0; i <= ANCHO+8; i++) {
        gotoxy(i, (ALTO / 5));
        cout << char(95);
        gotoxy(i, (ALTO / 5)+4);
        cout << char(95);
        gotoxy(i, ((ALTO / 5)*2)+4);
        cout << char(95);
        gotoxy(i, ((ALTO / 5) * 3)+4);
        cout << char(95);
        gotoxy(i, ((ALTO / 5) * 4)+4);
        cout << char(95);
        gotoxy(i, ((ALTO / 5) * 5)+4);
        cout << char(95);

    }
    for (int i = 1; i < ALTO-4; i++) {
        gotoxy((ANCHO/4), i+4);
        cout << char(179);
        gotoxy((ANCHO / 4)*2, i+4);
        cout << char(179);
        gotoxy(((ANCHO / 4)*3), i+4);
        cout << char(179);
        gotoxy((ANCHO / 4) * 4, i+4);
        cout << char(179);
        gotoxy(((ANCHO / 4) * 5), i+4);
        cout << char(179);
        

    }

}
void posicionU(int posiciony, int posicionx, int metax, int metay)
{
        gotoxy(posicionx, (posiciony));
        cout << ":)";

        gotoxy(metax*7.5, (metay*4)+2);
        cout << "Meta";
}

void colocar_datos()
{
    for (int i = 1; i < 6; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            if (matrizweb[i][j] != 0)
            {
                gotoxy((i * 7), (j * 4.5)+1);
                cout << "\t" + to_string(matrizweb[i][j]);
                
            }
        }
    }
}

int solucionar_matriz(int &index, int &indexy)
{
    int solucion = ((matrizweb[index][indexy - 1] + matrizweb[index - 1][indexy - 1] + matrizweb[index + 1][indexy - 1]) * matrizweb[index + 1][indexy]) - ((matrizweb[index][indexy + 1] + matrizweb[index + 1][indexy + 1] + matrizweb[index - 1][indexy + 1]) * matrizweb[index - 1][indexy]);
    return solucion;
}

void iociones(int &cont,int &index, int &indexy)
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            matrizweb[i][j] = 0;
        }
    }
    if (cont == 2)
    {
        //aqui ponemos todos los numeros aleatorios
       //ojo si y solo si las casillas no llegan a tocar las orillas
        
                if(index - 1 != 0 )
                matrizweb[index - 1][indexy] = 1 + rand() % 10;
                if (index + 1 != 6)
                matrizweb[index + 1][indexy] = 1 + rand() % 10;
                if (index - 1 != 0 && indexy + 1 != 6)
                matrizweb[index - 1][indexy + 1] = 1 + rand() % 10;
                if (index - 1 != 0 && indexy - 1 != 0)
                matrizweb[index - 1][indexy - 1] = 1 + rand() % 10;
                if (index + 1 != 6 && indexy + 1 != 6)
                matrizweb[index + 1][indexy + 1] = 1 + rand() % 10;
                if (index + 1 != 6 && indexy - 1 != 0)
                matrizweb[index + 1][indexy - 1] = 1 + rand() % 10;
                if (indexy + 1 != 6)
                matrizweb[index][indexy + 1] = 1 + rand() % 10;
                if (indexy - 1 != 0)
                matrizweb[index][indexy - 1] = 1 + rand() % 10;
            
        //aqui llamamos al procedimiento para llenar la matriz graficada
                colocar_datos();
    }
}




int main()
{
    system("cls");
    system("Color 30");
    bool rest = true, subOp = true;
    int opcion;
    string direccion;
   srand(time(NULL));
   while (rest)
   {
       system("cls");
       cout << "Bienvenido \nEmpezar juego 1\nSalir 0\n";
       cin >> opcion;
       if (opcion == 0)
       {
           rest = false;
       }
       else
       {
           subOp = true;
           int posicionyicial = 1 + rand() % 5;
           int yd = (posicionyicial * 4)+2;
           int xd = 1;
           int index = 1;
           int indexy = posicionyicial;
           int cont = 2;
           int intentos = 8;
           int inicialx = 1;
           int inicialy = indexy;
           int posicionMwta = 1 + rand() % 5;
           int posicionMwetax = 5;
           int xd2 = xd;
           int yd2 = yd;
           while (subOp)
           { 
               matrizweb[posicionMwetax][posicionMwta] = 11;
               if (intentos == 0)
               {
                   system("cls");
                   cout << "Sin intentos. Juego terminado";
                   this_thread::sleep_for(std::chrono::seconds(3));
                   
                   break;
               }
               if (index == posicionMwetax && indexy == posicionMwta)
               {
                   system("cls");
                   cout << "Ganaste!!!. Juego terminado";
                   this_thread::sleep_for(std::chrono::seconds(3));

                   break;
               }
               system("cls");

               cout << "D para moverse a la derecha.\nI para moverse a la izquierda.\nU para moverse arriba.\nA para moverse abajo.\n";
               gotoxy(45, 1);
               cout << "Intentos: " + to_string(intentos);
               this_thread::sleep_for(std::chrono::seconds(1));

               dibujarEje();
               posicionU(yd, xd, posicionMwetax, posicionMwta);
               if (cont == 2)
                   iociones(cont, (index), indexy);
               
               this_thread::sleep_for(std::chrono::seconds(1));
               CONSOLE_SCREEN_BUFFER_INFO screenInfo;
               GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screenInfo);
               gotoxy(screenInfo.dwCursorPosition.X, screenInfo.dwCursorPosition.Y);
               
               if (cont != 2)
               {
                   gotoxy(45, 2);
                   cout << "Moverse: ";
                   cin >> direccion;
                   if (direccion == "D")
                   {
                       xd += 12;
                       index++;
                       cont++;
                   }
                   else if (direccion == "I")
                   {
                       xd -= 12;
                       index--;
                       cont++;
                   }
                   else if (direccion == "U")
                   {
                       yd -= 4;
                       indexy--;
                       cont++;
                   }
                   else if (direccion == "A")
                   {
                       yd += 4;
                       indexy++;
                       cont++;
                   }
                   else
                   {
                       subOp = false;
                   }
                   
                  
               }
               else
               {
                   gotoxy(45, 2);
                   cout << "Ingrese el resultado: ";
                   cin >> direccion;
                   if (solucionar_matriz(index, indexy) == stoi(direccion))
                   {
                       gotoxy(45, 5);
                       cout << "Correcto";
                       this_thread::sleep_for(std::chrono::seconds(2));
                       cont = 0;
                   }
                   else {
                       gotoxy(45, 5);
                       cout << "Incorrecto";
                       index = inicialx;
                       indexy = inicialy;
                       yd = yd2;
                       xd = xd2;
                       this_thread::sleep_for(std::chrono::seconds(2));
                       cont = 2;
                       intentos--;
                   }
                
               }
           }
       }
    }
   
   
   
    

    
    





    
    return 0;

    

}

