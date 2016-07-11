#include "posiciones.h"
#include "personas.h"
#include "desafio.h"

Jugador Base::darPosicion(const Equipo& unEquipo) const
{
	return unEquipo.base;
}

Jugador Escolta::darPosicion(const Equipo& unEquipo) const
{
	return unEquipo.escolta;
}

Jugador Alero::darPosicion(const Equipo& unEquipo) const
{
	return unEquipo.alero;
}

Jugador AlaPivot::darPosicion(const Equipo& unEquipo) const
{
	return unEquipo.alapivot;
}

Jugador Pivot::darPosicion(const Equipo& unEquipo) const
{
	return unEquipo.pivot;
}
