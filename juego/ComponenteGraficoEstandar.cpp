#include "ComponenteGraficoEstandar.h"
#include "TiendadeMapadeBits.h"
#include <iostream>

void ComponenteGraficoEstandar::inicializarGrafico(
	string bitmapNombre,
	Vector2f SizeObjeto)
{
	TiendadeMapadeBits::addMapaBits("graphics/" + bitmapNombre + ".png");
	Sprite_m.setTexture(TiendadeMapadeBits::getMapaBits(
		"graphics/" + bitmapNombre + ".png"));

	auto textureSize = Sprite_m.getTexture()->getSize();
	Sprite_m.setScale(float(SizeObjeto.x) / textureSize.x,
		float(SizeObjeto.y) / textureSize.y);
	Sprite_m.setColor(sf::Color(0, 255, 0));
}

void ComponenteGraficoEstandar::draw(
	RenderWindow& window,
	shared_ptr<TransformarComponente> t)
{
	Sprite_m.setPosition(t->getLocation());
	window.draw(Sprite_m);
}
