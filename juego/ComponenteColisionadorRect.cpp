#include "ComponenteColisionadorRect.h"

ComponenteColisionadorRect::ComponenteColisionadorRect(string nombre) {
	Tag_m = "" + nombre;
}

string ComponenteColisionadorRect::getColisionadorTag() {
	return Tag_m;
}

void ComponenteColisionadorRect::setOrMoveColisionador(
	float x, float y, float ancho, float alto) {

	Colisionador_m.left = x;
	Colisionador_m.top = y;
	Colisionador_m.width = ancho;
	Colisionador_m.height = alto;
}

FloatRect& ComponenteColisionadorRect::getColisionadorRectF() {
	return Colisionador_m;
}
