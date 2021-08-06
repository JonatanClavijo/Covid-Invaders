#pragma once
#ifndef COMPONENTEACTUALIZACIONCOVID_H
#define COMPONENTEACTUALIZACIONCOVID_H

#include "ComponenteActualizacion.h"
#include "TransformarComponente.h"
#include "CompartidordeObjetosdeJuego.h"
#include "ComponenteColisionadorRect.h"
#include "ObjetosJuego.h"

class GeneradorBalas;

class ComponenteActualizacionCovid : public ComponenteActualizacion
{
    private:
        string TipoEspacifico_m = "invader";

        shared_ptr<TransformarComponente> TC_m;
        shared_ptr <ComponenteColisionadorRect> RCC_m;
        shared_ptr <TransformarComponente> JugadorTC_m;
        shared_ptr <ComponenteColisionadorRect> JugadorRCC_m;

        GeneradorBalas* GeneradorBalas_m;

        float Velocidad_m = 10.0f;
        bool MoverDerecha_m = true;
        float TiempoDesdeUltimoDisparo_m;
        float TiempoEntreDisparos = 5.0f;
        float ModificadorPrecision_m;
        float ModificadorVelocidad_m = 0.05;
        int SemillaRand_m;

    public:
        void DesplegaryRevertir();
        bool SeMueveDerecha();
        void inicializarGeneradorBalas(GeneradorBalas*
            generadorBalas, int SemillaRand);

        string getTipoSpecifico() {
            return TipoEspacifico_m;
        }

        void iniciar(CompartidordeObjetosdeJuego* gos,
            ObjetosJuego* self) {

            JugadorTC_m = static_pointer_cast<TransformarComponente>(
                gos->EncontrarPrimerObjetoConEtiqueta("Player")
                .getComponentePorTipoyTipoEspecifico(
                    "transform", "transform"));

            JugadorRCC_m = static_pointer_cast<ComponenteColisionadorRect>(
                gos->EncontrarPrimerObjetoConEtiqueta("Player")
                .getComponentePorTipoyTipoEspecifico(
                    "collider", "rect"));

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
