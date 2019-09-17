//! @file main.cpp
//! @file SquareRes.cpp
//! @mainpage Решатель квадратных ур-ний V0.0.0-000
//! \n
//! @author Titov EM
//! \n
//! Files:
//! \n
//! - main.cpp
//! - SquareRes.cpp
#include <stdio.h>
#include "SquareRes.cpp"

//typedef unsigned size_t;
//typedef unsigned long long size_t;

int UserFrRead(unsigned int NumElem, long double* Elements, const char* Greeting, int MaxTries);
int Fill(long double* mas, unsigned int NUM, long double filler);

//!Макс. кол-во попыток ввода
const int MAXTRIES = 3;

int main()
{
        /**
        @return Номер ошибки
        \n
        1 - ошибка выполнения SquareRes()
        \n
        2 - ошибка ввода
        */
    long double coeff[3], x1 = NAN, x2 = NAN;
    Fill(coeff, 3, NAN);

    if (UserFrRead(3, coeff, "Введите коэфиценты a, b, c квадратного уравнения через пробел\n", MAXTRIES))
        return 2;

    int RootNum = SquareRes(coeff[0], coeff[1], coeff[2], &x1, &x2);
    switch (RootNum) {
        case 0: printf("Нет Решений\n");
            break;
        case 1: printf("X = %Lg", x1);
            break;
        case 2: printf("X1 = %Lg X2 = %Lg", x1, x2);
            break;
        case INFIN: printf("ANY NUMBER");
            break;
        default: printf("ERROR %d", RootNum);
            return 1;
    }
    return 0;
}

int UserFrRead(unsigned int NumElem, long double* Elements, const char* Greeting, int MaxTries)
{
        /**
        Считывает числа в массив
        @param[in] NumElem (unsigned int) число элементов массива
        @param[in] Elements (long double*) указатель на массив
        @param[in] Greeting (const char*) Приветствие на ввод
        @param[in] MaxTries (int) Макимальное кол-во попыток ввода элемента
        @return 0 - считывание успешно; 1 - превышено макс кол-во попыток ввода
        */

    printf(Greeting);
    unsigned int i = 0;
    while(i < NumElem && MaxTries) {
        printf("[%d/%d]: ", i+1, NumElem);
        char check = 0;
        if(scanf("%Lg", (Elements + i)) == 1 && (check = getchar()) == '\n')
            i++;
        else {
            if (check == ',')
                printf ("В качесте разделителя целой и дробной частей используйте точку\n");
            else {
                MaxTries--;
                if (MaxTries == 0) {
                    printf("Превышено макс. количество попыток ввода\n");
                    return 1;
                }
                printf("Неверные данные введите элемент снова\n");
            }
            while (getchar() != '\n') ;
        }
    }
    return 0;
}

int Fill(long double* mas, unsigned int NUM, long double filler)
{
        /**
        Заполняет(инициализирует) массив указанными числами
        @param[in] mas (long double*) указатель на массив
        @param[in] NUM (unsigned int) число элементов массива
        @param[in] filler (long double) число для заполнения
        */
    for(unsigned int i = 0; i < NUM; i++)
        *(mas+i) = filler;
    return 0;
}
