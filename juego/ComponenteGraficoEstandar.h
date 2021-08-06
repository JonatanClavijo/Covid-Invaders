#pragma once
#ifndef COMPONENTEGRAFICOESTANDAR_H
#define COMPONENTEGRAFICOESTANDAR_H

#include "Componente.h"
#include "ComponenteGrafico.h"
#include <string>

class Componente;

class ComponenteGraficoEstandar : public ComponenteGrafico
{
    private:
        sf::Sprite Sprite_m;
        string TipoEspacifico_m = "standard";

    public:

        string getTipoSpecifico() {
            return TipoEspacifico_m;
        }

        void iniciar(
            CompartidordeObjetosdeJuego* gos, ObjetosJuego* self) {
        }

        void draw(
            RenderWindow& window,
            shared_ptr<TransformarComponente> t) override;

        void inicializarGrafico(
            string bitmapNombre,
            Vector2f SizeObjeto) override;
};

#endif
