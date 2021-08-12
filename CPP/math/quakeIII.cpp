/**
 * AKA
 * Fast Inverse Square Root
 * Quake III Algorithm
 * 0x5F3759DF Algorithm
 */

float FastInvSqrt(float num) {
    long i;
    float x, y;
    const float threehalfs = 1.5F;
    const float half = 0.5F;

    x = num * half;
    y = num;
    i = * ( long * ) &y;
    i = 0x5F3759DF - (i >> 1);
    y = * (float * ) &i;
    y = y * ( threehalfs - (x * y * y ));

    return y;
}