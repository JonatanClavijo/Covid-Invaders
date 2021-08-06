#pragma once
#ifndef COMPONENTEACTUALIZACIONJUGADOR_H
#define COMPONENTEACTUALIZACIONJUGADOR_H

#include "ComponenteActualizacion.h"
#include "TransformarComponente.h"
#include "CompartidordeObjetosdeJuego.h"
#include "ComponenteColisionadorRect.h"
#include "ObjetosJuego.h"

class ComponenteActualizacionJugador : public ComponenteActualizacion
{
    private:
        string TipoEspecifico_m = "player";

        shared_ptr<TransformarComponente> TC_m;
        shared_ptr<ComponenteColisionadorRect> RCC_m;

        float Velocidad_m = 50.0f;
        float GradoX_m = 0;
        float GradoY_m = 0;

        bool EstaSosteniendoIzquierda_m = false;
        bool EstaSosteniendoDerecha_m = false;
        bool EstaSosteniendoArriba_m = false;
        bool EstaSosteniendoAbajo_m = false;

    public:
        void actualizarNaveViajeconControlador(float x, float y);
        void moverIzquierda();
        void moverDerecha();
        void moverArriba();
        void moverAbajo();
        void detenerIzquierda();
        void detenerDerecha();
        void detenerArriba();
        void detenerAbajo();

        string getTipoSpecifico() {
            return TipoEspecifico_m;
        }

        void iniciar(CompartidordeObjetosdeJuego* gos, ObjetosJuego* self) {
            TC_m = static_pointer_cast<TransformarComponente>(self->
                getComponentePorTipoyTipoEspecifico(
                    "transform", "transform"));

            RCC_m = static_pointer_cast<ComponenteColisionadorRect>(self->
                getComponentePorTipoyTipoEspecifico(
                    "collider", "rect"));
        }

        void update(float fps) override;
};

#endif
