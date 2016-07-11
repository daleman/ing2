#include <string>

#include "desafio.h"

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
