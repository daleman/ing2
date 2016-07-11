#include "desafio.h"

#include <string>
#include <cassert>

using std::string;

Equipo::Equipo(
	string nombre,
	Tecnico tecnico,
	Jugador base,
	Jugador escolta,
	Jugador alero,
	Jugador alapivot,
	Jugador pivot,
	const Posicion& MVP
) : nombre(nombre),
	tecnico(tecnico),
	base(base),
	escolta(escolta),
	alero(alero),
	alapivot(alapivot),
	pivot(pivot),
	MVP(MVP)
{
}

void Monitor::sumarPuntaje(
	int unPuntaje,
	string unEquipo
)
{
	if (nombreEquipo1 == unEquipo)
		puntaje1 += unPuntaje;
	else if (nombreEquipo2 == unEquipo)
		puntaje2 += unPuntaje;
	else
		assert(false);
}

Monitor::Monitor(
	const string& unEquipo,
	const string& otroEquipo
) : nombreEquipo1(unEquipo),
    nombreEquipo2(otroEquipo),
	puntaje1(0),
	puntaje2(0)
{
}
