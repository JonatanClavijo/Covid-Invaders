#pragma once
#ifndef COMPONENTEACTUALIZACIONBALA_H
#define COMPONENTEACTUALIZACIONBALA_H

#include "ComponenteActualizacion.h"
#include "TransformarComponente.h"
#include "CompartidordeObjetosdeJuego.h"
#include "ComponenteColisionadorRect.h"
#include "ObjetosJuego.h"

class ComponenteActualizacionBala : public ComponenteActualizacion
{
    private:
        string TipoEspecifico_m = "bullet";

        shared_ptr<TransformarComponente> TC_m;
        shared_ptr<ComponenteColisionadorRect> RCC_m;

        float Velocidad_m = 75.0f;

        int ModificadorVelocidadBalaCovid_m;
        int ModificadorComponenteAleatorio_m = 5;
        int ModificadorAdicionalMinimo_m = 5;

        bool Subiendo_m = true;

    public:
        bool PertenecealJugador_m = false;
        bool EsGenerado_m = false;

        void GenerarParaJugador(Vector2f spawnPosition);
        void GenerarParaCovid(Vector2f spawnPosition);
        void Desaparecer();
        bool Esta_Subiendo();

        string getTipoSpecifico() {
            return TipoEspecifico_m;
        }

        void iniciar(
            CompartidordeObjetosdeJuego* gos, ObjetosJuego* self) {
            TC_m = static_pointer_cast<TransformarComponente>(
                self->getComponentePorTipoyTipoEspecifico(
                    "transform", "transform"));

            RCC_m = static_pointer_cast<ComponenteColisionadorRect>(
                self->getComponentePorTipoyTipoEspecifico(
                    "collider", "rect"));
        }

        void update(float fps) override;
};

#endif
