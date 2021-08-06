#pragma once
#ifndef ADMINISTRADORNIVEL_H
#define ADMINISTRADORNIVEL_H

#include "ObjetosJuego.h"
#include <vector>
#include <string>
#include "CompartidordeObjetosdeJuego.h"

using namespace std;

class AdministradorNivel : public CompartidordeObjetosdeJuego
{
    private:
        vector<ObjetosJuego> ObjetosJuego_m;

        const std::string WORLD_FOLDER = "world";
        const std::string SLASH = "/";

        void EjecutarFaceInicio();
        void ActivarTodosObjetosJuego();

    public:
        vector<ObjetosJuego>& getObjetosdelJuego();
        void CargarObjetosJuegoParaModoJuego(string Cargar_pantalla);

        vector<ObjetosJuego>& getObjetosJuegoConGOS()
        {
            return ObjetosJuego_m;
        }

        ObjetosJuego& EncontrarPrimerObjetoConEtiqueta(string tag)
        {
            auto it = ObjetosJuego_m.begin();
            auto end = ObjetosJuego_m.end();
            for (it; it != end; ++it)
            {
                if ((*it).getTag() == tag)
                {
                    return (*it);
                }
            }

    #ifdef debuggingErrors
            cout <<
                "AdministradorNivel.h EncontrarPrimerObjetoConEtiqueta() "
                << "- TAG NOT FOUND ERROR!"
                << endl;
    #endif
            return ObjetosJuego_m[0];
        }
};

#endif
