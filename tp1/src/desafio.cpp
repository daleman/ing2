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
	shared_ptr<Posicion> MVP
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

int Monitor::darPuntajeEquipo1() const
{
	return puntaje1;
}

int Monitor::darPuntajeEquipo2() const
{
	return puntaje2;
}

string Monitor::ganador() const
{
	assert(!empate());

	if (puntaje1 > puntaje2)
		return nombreEquipo1;

	return nombreEquipo2;
}

bool Monitor::empate() const
{
	return puntaje1 == puntaje2;
}
