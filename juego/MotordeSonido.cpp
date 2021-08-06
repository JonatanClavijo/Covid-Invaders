#include "MotordeSonido.h"

#include <SFML/Audio.hpp>
#include <assert.h>

using namespace std;
using namespace sf;

MotordeSonido* MotordeSonido::m_s_Instancia = nullptr;

MotordeSonido::MotordeSonido()
{
	assert(m_s_Instancia == nullptr);
	m_s_Instancia = this;

	DispararBuffer_m.loadFromFile("sound/shoot.ogg");
	JugadorExplotaBuffer_m.loadFromFile("sound/playerexplode.ogg");
	CovidExplotaBuffer_m.loadFromFile("sound/invaderexplode.ogg");
	ClickBuffer_m.loadFromFile("sound/click.ogg");

	SonidoDisparo_m.setBuffer(DispararBuffer_m);
	SonidoJugadorExplota_m.setBuffer(JugadorExplotaBuffer_m);
	SonidoCovidExplota_m.setBuffer(CovidExplotaBuffer_m);
	SonidoClick_m.setBuffer(ClickBuffer_m);
}

void MotordeSonido::playDisparo()
{
	m_s_Instancia->SonidoDisparo_m.play();
}

void MotordeSonido::playJugadorExplota()
{
	m_s_Instancia->SonidoJugadorExplota_m.play();
}

void MotordeSonido::playCovidExplota()
{
	m_s_Instancia->SonidoCovidExplota_m.play();
}

void MotordeSonido::playClick()
{
	m_s_Instancia->SonidoClick_m.play();
}
