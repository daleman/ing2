#ifndef POSICIONES_H
#define POSICIONES_H

#include "clases.h"

#include <string>

using std::string;

class Posicion
{
	public:
	virtual Jugador darPosicion(const Equipo& unEquipo) const = 0;
	virtual string nombre() const = 0;
};

class Base : public Posicion
{
	public:
	Jugador darPosicion(const Equipo& unEquipo) const;
	string nombre() const;
};

class Escolta : public Posicion
{
	public:
	Jugador darPosicion(const Equipo& unEquipo) const;
	string nombre() const;
};

class Alero : public Posicion
{
	public:
	Jugador darPosicion(const Equipo& unEquipo) const;
	string nombre() const;
};

class AlaPivot : public Posicion
{
	public:
	Jugador darPosicion(const Equipo& unEquipo) const;
	string nombre() const;
};

class Pivot : public Posicion
{
	public:
	Jugador darPosicion(const Equipo& unEquipo) const;
	string nombre() const;
};

#endif
