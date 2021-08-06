#include "TiendadeMapadeBits.h"

#include <assert.h>

using namespace sf;
using namespace std;

TiendadeMapadeBits* TiendadeMapadeBits::m_s_Instancia = nullptr;

TiendadeMapadeBits::TiendadeMapadeBits()
{
	assert(m_s_Instancia == nullptr);
	m_s_Instancia = this;
}

void TiendadeMapadeBits::addMapaBits(std::string const& filename)
{
	auto& mapadeMapadeBits = m_s_Instancia->mapadeMapadeBits_m;

	auto keyValuePair = mapadeMapadeBits.find(filename);

	if (keyValuePair == mapadeMapadeBits.end())
	{
		auto& texture = mapadeMapadeBits[filename];
		texture.loadFromFile(filename);
	}

}

sf::Texture& TiendadeMapadeBits::getMapaBits(std::string const& filename)
{
	auto& m = m_s_Instancia->mapadeMapadeBits_m;
	auto keyValuePair = m.find(filename);
	if (keyValuePair != m.end())
	{
		return keyValuePair->second;
	}
	else
	{
#ifdef debuggingOnConsole
		cout <<
			"TiendadeMapadeBits::getMapaBits()Texture not found Crrrashh!"
			<< endl;
#endif
		return keyValuePair->second;
	}
}
