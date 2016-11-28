/*
 * spline.c
 *
 *  Created on: 05/11/2016
 *      Author: ES670A
 */


float CRSpline (float p0, float p1, float p2, float p3, float t){

    float fY;

    fY = 0.5f * ( (2.0f * p1) + (-p0 + p2)*t + (2.0f * p0 - 5.0f * p1 + 4 * p2 - p3) * t*t + (-p0 + 3.0f * p1 - 3.0f * p2 + p3) * t*t*t);

    return fY;

}

float getPosicaoLinha (float *pontos){

    float fError, ftemp, fMin;
    float t[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};

    /* Caso ponto 0-1 */
    for (int i = 0; i<9;i++){
        ftemp = CRSpline(pontos[0], pontos[0], pontos[1], pontos[2], t[i]);
        if (i == 0 ){
            fMin = ftemp;
        } else if(ftemp < fMin){
            fMin = ftemp;
            fError = -2.5 + t[i];
        }
    }

    /* Caso ponto 1-2 */
    if(pontos[1]< fMin){
        fMin = pontos[1];
        fError = -1.5;
    }
    for (int i = 0; i<9;i++){
        ftemp = CRSpline(pontos[0], pontos[1], pontos[2], pontos[3], t[i]);
        if(ftemp < fMin){
            fMin = ftemp;
            fError = -1.5 + t[i];
        }
    }

     /* Caso ponto 2-3 */
    if(pontos[2] < fMin){
        fMin = pontos[2];
        fError = -0.5;
    }
    for (int i = 0; i<9;i++){
        ftemp = CRSpline(pontos[1], pontos[2], pontos[3], pontos[4], t[i]);
        if(ftemp < fMin){
            fMin = ftemp;
            fError = -0.5 + t[i];
        }
    }

     /* Caso ponto 3-4 */
    if(pontos[3] < fMin){
        fMin = pontos[3];
        fError = 0.5;
    }
    for (int i = 0; i<9;i++){
        ftemp = CRSpline(pontos[2], pontos[3], pontos[4], pontos[5], t[i]);
        if(ftemp < fMin){
            fMin = ftemp;
            fError = -0.5 + t[i];
        }
    }

    /* Caso ponto 4-5 */
    if(pontos[4] < fMin){
        fMin = pontos[4];
        fError = 1.5;
    }
    for (int i = 0; i<9;i++){
        ftemp = CRSpline(pontos[3], pontos[4], pontos[5], pontos[5], t[i]);
        if(ftemp < fMin){
            fMin = ftemp;
            fError = 1.5 + t[i];
        }
    }

    /* Caso ponto 5 */
    if(pontos[5] < fMin){
        fMin = pontos[5];
        fError = 2.5;
    }

    return fError;
}
