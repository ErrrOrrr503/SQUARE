#include <math.h>
#include <assert.h>

//! Константа обозначает бескнечное кол-во корней
#define INFIN -1

//! Константа указывает точность сранение чисел с плавабщей точкой (кол-во знаков после запятой)
#define PRECISION 0.00000000000000000000000000000001L

int flCOMP (long double t1, long double t2, long double pres);
void LinearRes (long double a, long double b, long double* x);

int SquareRes (long double a, long double b, long double c, long double *x1, long double *x2)
{
        /**
        Записывает корни по адресам *x1 *x2
        @param[in] a (long double) 1й коэф-т
        @param[in] b (long double) 2й коэф-т
        @param[in] c (long double) 3й коэф-т
        @param[in] x1 (*long double) указатель на 1й корень
        @param[in] x2 (*long double) указатель на 2й корень
        @return Количество корней (0, 1, 2) или INFIN - бесконечное кол-во решений
        */

    assert (isfinite(a)); //Проверка входных данных
    assert (isfinite(b));
    assert (isfinite(c));
    assert (x1 != x2);

    long double D = b * b - 4 * a * c; //Дискриминант
    if (D < 0) return 0;
    if (!flCOMP (a, 0, PRECISION)) {
        if (!flCOMP (b, 0, PRECISION)) {
            if (!flCOMP (c, 0, PRECISION)) return INFIN;
            else return 0;
        }
        LinearRes (b, c, x1);
        return 1;
    }
    long double sqrtD = sqrt(D);
    *x1 = (-b + sqrtD) / 2 / a;
    if (!flCOMP (D, 0, PRECISION)) {
        return 1;
    }
    *x2 = (-b - sqrtD) / 2 / a;
    return 2;
}

int flCOMP (long double t1, long double t2, long double pres)
{
        /**
        Сравнивает 2 числа с точностью до precision знаков после запятой
        @param[in] t1 (long double) 1е число
        @param[in] t2 (long double) 2е число
        @param[in] pres (long double) точность
        @return 1 Если t1>t2; -1 Если t2>t1; 0 если t1=t2
        */

    if (t1 - t2 > pres) return 1;
    if (t2 - t1 > pres) return -1;
    return 0;
}

void LinearRes (long double a, long double b, long double* x)
{
        /**
        Решает линейное уравнение
        @param[in] a (long double) коэф-т при 1й степени
        @param[in] b (long double) коэф-т при 0й степени
        @param[in] x (long double*) указатель на корень
        */

    assert (isfinite(a)); //Проверка входных данных
    assert (isfinite(b));
    assert (a != 0);

    *x = -b / a;
}
