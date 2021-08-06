#pragma once
#ifndef OBJETOJUEGOPLANO_H
#define OBJETOJUEGOPLANO_H

#include<vector>
#include<string>
#include<map>

using namespace std;

class ObjetoJuegoPlano
{
    private:
        string Nombre_m = "";
        vector<string> ListaComponente_m;
        string BitmapNombre_m = "";
        float Ancho_m;
        float Alto_m;
        float LocationX_m;
        float LocationY_m;
        float Velocidad_m;
        bool AbarcandoColisionadorRect_m = false;
        string AbarcandoColisionadorRectLabel_m = "";

    public:
        float getAncho();
        void setAncho(float ancho);
        float getAlto();
        void setAlto(float alto);
        float getLocationX();
        void setLocationX(float locationX);
        float getLocationY();
        void setLocationY(float locationY);
        void setNombre(string nombre);
        string getNombre();
        vector<string>& getListaComponente();
        void addAListaComponente(string newComponente);
        string getBitmapNombre();
        void setBitmapNombre(string bitmapNombre);
        string getAbarcandoColisionadorRectLabel();
        bool getAbarcandoColisionadorRect();
        void setAbarcandoColisionadorRect(string label);
};

#endif
