#include "FTaylor.h"

double taylor(double x, FType type, int n) {
	double res = 0.0;

	switch (type) {
		case FUNC_EXP: {
			double t = 1.0;
			for (int i = 0; i < n; i++) {
				res += t;
				t *= x / (i + 1);
			}
			break;
		}
		case FUNC_SIN: {
			double t = x;
			res = t;
			for (int i = 1; i < n; i++) {
				t *= -x * x / ((2 * i) * (2 * i + 1));
				res += t;
			}
			break;
		}
		case FUNC_COS: {
			double t = 1.0;
			res = t;
			for (int i = 1; i < n; i++) {
				t *= -x * x / ((2 * i - 1) * (2 * i));
				res += t;
			}
			break;
		}
		case FUNC_LN: {
			if (fabs(x) >= 1.0) {
				printf("Ошибка. |x| < 1\n");
				return 0.0;
			}
			double t = x;
			res = t;
			for (int i = 1; i < n; i++) {
				t *= -x * i / (i + 1);
				res += t;
			}
			break;
		}
	}
	return res;
}