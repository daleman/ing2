#ifndef POSICIONES_H
#define POSICIONES_H

#include "clases.h"

class Posicion
{
	virtual Jugador darPosicion(const Equipo& unEquipo) = 0;
};

class Base : public Posicion
{
	Jugador darPosicion(const Equipo& unEquipo);
};

class Escolta : public Posicion
{
	Jugador darPosicion(const Equipo& unEquipo);
};

class Alero : public Posicion
{
	Jugador darPosicion(const Equipo& unEquipo);
};

class AlaPivot : public Posicion
{
	Jugador darPosicion(const Equipo& unEquipo);
};

class Pivot : public Posicion
{
	Jugador darPosicion(const Equipo& unEquipo);
};

#endif
