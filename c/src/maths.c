#include "maths.h"

Natural maths_factorial(Natural x)
{
    if (x < 2)
        return 1;
    return x * maths_factorial(x - 1);
}

Natural maths_fibonacci(Natural i)
{
    if (i == 0)
        return 0;
    if (i < 3)
        return 1;
    return maths_fibonacci(i - 1) + maths_fibonacci(i - 2);
}

double maths_pow(double base, double exponent)
{
    if (exponent > 0)
        return base * maths_pow(base, exponent - 1);
    if (exponent < 0)
        return base / maths_pow(base, exponent + 1);
    return 1;
}

bool maths_trial_division(Natural x)
{
    if (x < 2)
        return false;
    if (x == 2 || x == 3)
        return true;
    if (x % 2 == 0 || x % 3 == 0)
        return false;
    for (int i = 5; i * i <= x; i += 6)
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    return true;
}
