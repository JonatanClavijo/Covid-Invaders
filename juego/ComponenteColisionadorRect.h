#pragma once
#ifndef COMPONENTECOLISIONADORRECT_H
#define COMPONENTECOLISIONADORRECT_H

#include "ComponenteColisionador.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class ComponenteColisionadorRect : public ComponenteColisionador
{
    private:
        string TipoEspecifico_m = "rect";
        FloatRect Colisionador_m;
        string Tag_m = "";
    public:
        ComponenteColisionadorRect(string nombre);
        string getColisionadorTag();
        void setOrMoveColisionador(
            float x, float y, float ancho, float alto);

        FloatRect& getColisionadorRectF();

        string getTipoSpecifico() {
            return TipoEspecifico_m;
        }

        void iniciar(
            CompartidordeObjetosdeJuego* gos, ObjetosJuego* self) {}
};

#endif
