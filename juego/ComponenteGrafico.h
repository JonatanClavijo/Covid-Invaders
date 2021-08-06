#pragma once
#ifndef COMPONENTEGRAFICO_H
#define COMPONENTEGRAFICO_H

#include "Componente.h"
#include "TransformarComponente.h"
#include <string>
#include <SFML/Graphics.hpp>
#include "CompartidordeObjetosdeJuego.h"
#include <iostream>
#include <memory>

using namespace sf;
using namespace std;

class ComponenteGrafico : public Componente
{
    private:
        string Tipo_m = "graphics";
        bool Habilitar_m = false;

    public:
        virtual void draw(RenderWindow& window, shared_ptr<TransformarComponente> t) = 0;

        virtual void inicializarGrafico(
            string bitmapNombre,
            Vector2f ObjetoSize) = 0;

        string getTipo() {
            return Tipo_m;
        }

        void ComponenteDeshabilitado() {
            Habilitar_m = false;
        }

        void ComponenteHabilitado() {
            Habilitar_m = true;
        }

        bool Habilitar() {
            return Habilitar_m;
        }

        void iniciar(
            CompartidordeObjetosdeJuego* gos, ObjetosJuego* self) {}
};

#endif
