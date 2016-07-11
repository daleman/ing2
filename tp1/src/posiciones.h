#ifndef POSICIONES_H
#define POSICIONES_H

#include "clases.h"

class Posicion
{
	public:
	virtual Jugador darPosicion(const Equipo& unEquipo) const = 0;
};

class Base : public Posicion
{
	public:
	Jugador darPosicion(const Equipo& unEquipo) const;
};

class Escolta : public Posicion
{
	public:
	Jugador darPosicion(const Equipo& unEquipo) const;
};

class Alero : public Posicion
{
	public:
	Jugador darPosicion(const Equipo& unEquipo) const;
};

class AlaPivot : public Posicion
{
	public:
	Jugador darPosicion(const Equipo& unEquipo) const;
};

class Pivot : public Posicion
{
	public:
	Jugador darPosicion(const Equipo& unEquipo) const;
};

#endif
