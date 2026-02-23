#ifndef TAYLOR_H
#define TAYLOR_H
#include <math.h>
typedef enum {
	FUNC_EXP,
	FUNC_SIN,
	FUNC_COS,
	FUNC_LN
}FType;

double taylor(double x, FType type, int n);

#endif