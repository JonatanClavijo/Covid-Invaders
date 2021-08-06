#pragma once
#ifndef PANELUI_H
#define PANELUI_H

#include <SFML/Graphics.hpp>
#include "Boton.h"
#include <memory>

using namespace std;

class PanelUI {
    private:
        RectangleShape PanelUI_m;
        bool Oculto_m = false;
        vector<shared_ptr<Boton>> Botones_m;

    protected:
        float BotonAncho_m = 0;
        float BotonAlto_m = 0;
        float BotonRelleno_m = 0;

        Font Fuente_m;
        Text Texto_m;

        void addBoton(float x, float y, int ancho, int alto,
            int rojo, int verde, int azul,
            string label);

    public:
        View vista_m;

        PanelUI(Vector2i res, int x, int y,
            float ancho, float alto,
            int alpha, int rojo, int verde, int azul);

        vector<shared_ptr<Boton>> getBotones();
        virtual void draw(RenderWindow& window);
        void mostrar();
        void esconder();
};

#endif
