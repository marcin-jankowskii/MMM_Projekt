#ifndef OBLICZENIA_H
#define OBLICZENIA_H

#include <QtCharts>
#include <QLineSeries>
#include <cmath>
#include <QDebug>
#include <complex>


#define h 0.01 // krok obliczeń
#define T 100 // całkowity czas symulacji – przedział [0 , T]
#define L 25 // liczba okresów sygnału sinus w przedziale T

#define PI 3.14159265 // liczba PI



class Obliczenia
{
public:
    Obliczenia();


    double checkMaksimum();
    double checkMinimum();


    double a_0=10;
    double a_1=10;
    double a_2=10;
    double b_1=10;
    double b_0=10;
    int total =  0;
    double M = 8; // ampliuda sygnału


    void sinus();
    void Obliczenia::metoda_eulera_fala_prostokatna();
    void wyjscie(double t);


    // pomocniczy typ – kolejne bajty danej ’double’
    typedef union { char c[sizeof(double)]; double d; } Box;
    // zmienne globalne w programie
    double u[(int)(1.0 * T / h) + 1]; // sygnał wejściowy
    double u1p[(int)(1.0 * T / h) + 1]; // pierwsza pochodna sygnału wejściowego

    // Euler
    double us[(int)(1.0*T/h)+1]; // sygnał wejściowy sinus
    double uf[(int)(1.0*T/h)+1]; // sygnał wejściowy fala prostokątna


    double y[(int)(1.0 * T / h) + 1]; // sygnał wyjściowy
    double y1p[(int)(1.0 * T / h) + 1]; // pierwsza pochodna sygnału wyjściowego
    double y2p[(int)(1.0 * T / h) + 1]; // druga pochodna sygnału wyjściowego
    double y3p[(int)(1.0 * T / h) + 1]; // trzecia pochodna sygnału wyjściowego

    Box z; // zmienna: pojedyncza wartość sygnału (u lub y)
    // program główny





    //---------------------
    // Do macierzy

    void wypelnienie_macierzy();
    void dodawanie_macierzy(double Macierz1[3][3], double Macierz2[3][3], double Macierzwyj[3][3]);
    void mnozenie_macierzy(double Macierz1[3][3], double Macierz2[3][3], double Macierzwyj[3][3]);
    void mnozenie_skalarne(double Macierz1[3][3], double mnoznik, double Macierzwyj[3][3]);


    double macierzA[3][3];
    double macierzB[3][3];  //[3][1]
    double macierzC[3][3];  //[1][3]
    double macierzD;       //Jeden element
    double macierzxi_1[3][3];
    double macierzxi[3][3];
    double macierz0[3][3];
    double Ax[3][3];
    double Bu[3][3];
    double Cx[3][3];
    double Du;




};

#endif // OBLICZENIA_H
