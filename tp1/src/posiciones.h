#ifndef POSICIONES_H
#define POSICIONES_H

#include "clases.h"

class Posicion
{
	virtual Jugador darPosicion(const Equipo& unEquipo) = 0;
};

class Base : Posicion
{
	Jugador darPosicion(const Equipo& unEquipo);
};

class Escolta : Posicion
{
	Jugador darPosicion(const Equipo& unEquipo);
};

class Alero : Posicion
{
	Jugador darPosicion(const Equipo& unEquipo);
};

class AlaPivot : Posicion
{
	Jugador darPosicion(const Equipo& unEquipo);
};

class Pivot : Posicion
{
	Jugador darPosicion(const Equipo& unEquipo);
};

#endif
