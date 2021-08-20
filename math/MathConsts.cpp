#include "MathConsts.hpp"
#include <cmath>

double MathPI::PI = 3.1415926535897932384626433;
double MathPI::HALF_PI = 0.5 * MathPI::PI;
double MathPI::TWO_PI = 2. * MathPI::PI;
double MathPI::DIV_1_TWO_PI = 1. / MathPI::TWO_PI;

double MathAngles::DEG2RAD = 0.0174532925199432957692369;   // 2PI / 360 = PI / 180
double MathAngles::RAD2DEG = 57.2957795130823208767981548;  // 360 / 2PI = 180 / PI
double MathAngles::ARCDEG2RAD = DEG2RAD / 3600.;            // 2PI / (360 * 3600) = PI / (180 * 3600)

double MathConsts::FLOATING_EPSILON = 10e-6;