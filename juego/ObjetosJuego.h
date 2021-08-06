#pragma once
#ifndef OBJETOSJUEGO_H
#define OBJETOSJUEGO_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>
#include "Componente.h"
#include "ComponenteGrafico.h"
#include "CompartidordeObjetosdeJuego.h"
#include "ComponenteActualizacion.h"

class ObjetosJuego {
    private:
        vector<shared_ptr<Componente>> Componentes_m;

        string Tag_m;
        bool Activo_m = false;
        int NumeroComponentesActualizados_m = 0;
        bool TieneComponenteActualizacion_m = false;
        int UbicacionPrimerComponenteActualizacion_m = -1;
        int UbicacionComponentesGraficos_m = -1;
        bool TieneComponenteGrafico_m = false;
        int UbicacionTransformarComponente_m = -1;
        int NumeroComponenteColisionesRect_m = 0;
        int UbicacionPrimerComponenteColisionesRect_m = -1;
        bool TieneColisionador_m = false;
        bool TieneComponenteEstado_m = false;
        int UbicacionComponenteEstado_m = -1;

    public:
        void update(float fps);
        void draw(RenderWindow& window);
        void addComponente(shared_ptr<Componente> componente);

        void setActivo();
        void setInactivo();
        bool estaActivo();
        void setTag(String tag);
        string getTag();

        void iniciar(CompartidordeObjetosdeJuego* gos);

        shared_ptr<Componente> getComponentePorTipoyTipoEspecifico(
            string tipo, string tipoEspecifico);

        FloatRect& getAbarcandoColisionadorRect();
        bool TieneColisionador();
        bool TieneComponenteActualizacion();
        string getAbarcandoColisionadorRectTag();

        shared_ptr<ComponenteGrafico> getComponenteGrafico();
        shared_ptr<TransformarComponente> getTransformarComponente();
        shared_ptr<ComponenteActualizacion> getPrimerComponenteActualizacion();
};

#endif
