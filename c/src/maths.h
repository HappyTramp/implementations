#ifndef __MATHS_H__
# define __MATHS_H__

#include <stdbool.h>
#include <stddef.h>

typedef unsigned int Natural;

Natural maths_factorial(Natural x);
Natural maths_fibonacci(Natural i);
double maths_pow(double base, double exponent);
bool maths_trial_division(Natural x);

#endif
