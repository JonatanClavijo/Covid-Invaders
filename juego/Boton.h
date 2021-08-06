#pragma once
#ifndef BOTON_H
#define BOTON_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Boton
{
    private:
        RectangleShape Boton_m;
        Text BotonTexto_m;
        Font Fuente_m;

    public:
        std::string Texto_m;
        FloatRect Colisionador_m;

        Boton(Vector2f posicion,
            float ancho, float alto,
            int rojo, int verde, int azul,
            std::string texto);

        void draw(RenderWindow& window);
};

#endif
