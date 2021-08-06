#pragma once
#ifndef TRANSFORMARCOMPONENTE_H
#define TRANSFORMARCOMPONENTE_H

#include "Componente.h"
#include<SFML/Graphics.hpp>

using namespace sf;

class Componente;

class TransformarComponente : public Componente
{
    private:
        const string Tipo_m = "transform";
        Vector2f Location_m;
        float Alto_m;
        float Ancho_m;

    public:
        TransformarComponente(
            float ancho, float alto, Vector2f location);

        Vector2f& getLocation();

        Vector2f getSize();

        string getTipo()
        {
            return Tipo_m;
        }

        string getTipoSpecifico()
        {
            return Tipo_m;
        }

        void ComponenteDeshabilitado() {}

        void ComponenteHabilitado() {}

        bool Habilitar()
        {
            return false;
        }

        void iniciar(CompartidordeObjetosdeJuego* gos, ObjetosJuego* self) {}

};

#endif
