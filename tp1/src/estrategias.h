#ifndef ESTRATEGIAS_H
#define ESTRATEGIAS_H

#include "clases.h"

#include <memory>

using std::shared_ptr;

class EstrategiaOfensiva
{
	public:
	virtual shared_ptr<AccionOfensiva> darAccionDe(const Equipo& unEquipo) const = 0;
};

class ColectivaExternaDe3PuntosLuegoDeKPases : public EstrategiaOfensiva
{
	public:
	const int k;

	shared_ptr<AccionOfensiva> darAccionDe(const Equipo& unEquipo) const;
	ColectivaExternaDe3PuntosLuegoDeKPases(int k);
};

class ColectivaInternaDe2PuntosLuegoDeKPases : public EstrategiaOfensiva
{
	public:
	const int k;

	shared_ptr<AccionOfensiva> darAccionDe(const Equipo& unEquipo) const;
	ColectivaInternaDe2PuntosLuegoDeKPases(int k);
};

class MVP : public EstrategiaOfensiva
{
	public:
	shared_ptr<AccionOfensiva> darAccionDe(const Equipo& unEquipo) const;
};

class EstrategiaDefensiva
{
	public:

	int pepe;

	virtual shared_ptr<AccionDefensiva> responderPaseDe(
		const Equipo& unEquipo,
		shared_ptr<Posicion> unaPosicion
	) const = 0;

	virtual shared_ptr<AccionDefensiva> responderTiro2De(
		const Equipo& unEquipo,
		shared_ptr<Posicion> unaPosicion
	) const = 0;

	virtual shared_ptr<AccionDefensiva> responderTiro3De(
		const Equipo& unEquipo,
		shared_ptr<Posicion> unaPosicion
	) const = 0;
};

class HombreAHombre : public EstrategiaDefensiva
{
	public:

	shared_ptr<AccionDefensiva> responderPaseDe(
		const Equipo& unEquipo,
		shared_ptr<Posicion> unaPosicion
	) const;

	shared_ptr<AccionDefensiva> responderTiro2De(
		const Equipo& unEquipo,
		shared_ptr<Posicion> unaPosicion
	) const;

	shared_ptr<AccionDefensiva> responderTiro3De(
		const Equipo& unEquipo,
		shared_ptr<Posicion> unaPosicion
	) const;
};

class Contraataque : public EstrategiaDefensiva
{
	public:

	shared_ptr<AccionDefensiva> responderPaseDe(
		const Equipo& unEquipo,
		shared_ptr<Posicion> unaPosicion
	) const;

	shared_ptr<AccionDefensiva> responderTiro2De(
		const Equipo& unEquipo,
		shared_ptr<Posicion> unaPosicion
	) const;

	shared_ptr<AccionDefensiva> responderTiro3De(
		const Equipo& unEquipo,
		shared_ptr<Posicion> unaPosicion
	) const;
};

#endif
