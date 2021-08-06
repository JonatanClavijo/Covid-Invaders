#pragma once
#ifndef OBJETOPLANOANALIZADOR_H
#define OBJETOPLANOANALIZADOR_H

#include "ObjetoJuegoPlano.h"
#include <string>

using namespace std;

class ObjetoPlanoAnalizador
{
    private:
        string extraerStringEntreTags(
            string stringParaBuscar, string TagInicio, string TagFin);

    public:
        void SiguienteObjetoPlanoAnalizar(
            ifstream& reader, ObjetoJuegoPlano& bp);
    };

#endif
