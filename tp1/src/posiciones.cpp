#include "posiciones.h"
#include "personas.h"
#include "desafio.h"

Jugador Base::darPosicion(const Equipo& unEquipo) const
{
	return unEquipo.base;
}

string Base::nombre() const
{
	return "Base";
}

Jugador Escolta::darPosicion(const Equipo& unEquipo) const
{
	return unEquipo.escolta;
}

string Escolta::nombre() const
{
	return "Escolta";
}

Jugador Alero::darPosicion(const Equipo& unEquipo) const
{
	return unEquipo.alero;
}

string Alero::nombre() const
{
	return "Alero";
}

Jugador AlaPivot::darPosicion(const Equipo& unEquipo) const
{
	return unEquipo.alapivot;
}

string AlaPivot::nombre() const
{
	return "AlaPivot";
}

Jugador Pivot::darPosicion(const Equipo& unEquipo) const
{
	return unEquipo.pivot;
}

string Pivot::nombre() const
{
	return "Pivot";
}
