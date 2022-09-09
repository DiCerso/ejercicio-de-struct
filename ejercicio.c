#include <stdio.h>
#include <string.h>
/*
Realizar un programa para la gestión de stock de materiales, en donde se debe
ingresar el nombre del material y su stock.
Para un material se pueden ir ingresando altas y bajas del stock.
Se desconoce la cantidad de materiales, pero se sabe que no
superará los 100 materiales.
El ingreso de datos finaliza con stock cero (0). Se debe verificar que los valores
ingresados sean mayores a cero (0).
Una vez finalizado el ingreso, se debe informar:
- stock promedio
- listar los materiales con stock inferiores al promedio
*/

#define char_name 20

struct materiales
{
    int stock;
    char name[char_name];
};

typedef struct materiales MATERIALES;

void resetArray(MATERIALES *);

int main(void)
{    
    MATERIALES dato[99];

    resetArray(dato);
    
    int i = 0, flag = 0, sum = 0;

    while (flag != 1)
    {
        MATERIALES *p = &dato[i];
        scanf("%s", &p->name);
        scanf("%d", &p->stock);
        sum += p->stock;
        if(p->stock < 0){
            printf("debe ingresar solo valores validos al stock");
            return 0;
        }
        if (p->stock == 0 || i == 100)
        {
            flag = 1;
        }
        else
        {
            i++;
        }
    }
    int promedio = sum / i;

    printf("el promedio del stock de los productos es: %d\n", promedio);
    printf("los productos que tienen un stock mayor al promedio son:\n");
    for (int num = 0; num < i; num++)
    {
        MATERIALES *punt = &dato[num];
        if(punt->stock > promedio){
            printf("%s\n", punt->name);
        }
    }
    return 0;
};

void resetArray(MATERIALES *dat)
{
    for (int i = 0; i < 99; i++)
    {
        dat[i].stock = 0;
        strcpy(dat[i].name, "no-name");
    }
    return;
};
