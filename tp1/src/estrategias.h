#ifndef ESTRATEGIAS_H
#define ESTRATEGIAS_H

#include "clases.h"

class EstrategiaOfensiva
{
	public:
	virtual const AccionOfensiva& darAccionDe(const Equipo& unEquipo) const = 0;
};

class ColectivaExternaDe3PuntosLuegoDeKPases : public EstrategiaOfensiva
{
	public:
	const int k;

	const AccionOfensiva& darAccionDe(const Equipo& unEquipo) const;
	ColectivaExternaDe3PuntosLuegoDeKPases(int k);
};

class ColectivaInternaDe2PuntosLuegoDeKPases : public EstrategiaOfensiva
{
	public:
	const int k;

	const AccionOfensiva& darAccionDe(const Equipo& unEquipo) const;
	ColectivaInternaDe2PuntosLuegoDeKPases(int k);
};

class MVP : public EstrategiaOfensiva
{
	public:
	const AccionOfensiva& darAccionDe(const Equipo& unEquipo) const;
};

class EstrategiaDefensiva
{
	public:

	int pepe;

	virtual const AccionDefensiva& responderPaseDe(
		const Equipo& unEquipo,
		const Posicion& unaPosicion
	) const = 0;

	virtual const AccionDefensiva& responderTiro2De(
		const Equipo& unEquipo,
		const Posicion& unaPosicion
	) const = 0;

	virtual const AccionDefensiva& responderTiro3De(
		const Equipo& unEquipo,
		const Posicion& unaPosicion
	) const = 0;
};

class HombreAHombre : public EstrategiaDefensiva
{
	public:

	const AccionDefensiva& responderPaseDe(
		const Equipo& unEquipo,
		const Posicion& unaPosicion
	) const;

	const AccionDefensiva& responderTiro2De(
		const Equipo& unEquipo,
		const Posicion& unaPosicion
	) const;

	const AccionDefensiva& responderTiro3De(
		const Equipo& unEquipo,
		const Posicion& unaPosicion
	) const;
};

class Contraataque : public EstrategiaDefensiva
{
	public:

	const AccionDefensiva& responderPaseDe(
		const Equipo& unEquipo,
		const Posicion& unaPosicion
	) const;

	const AccionDefensiva& responderTiro2De(
		const Equipo& unEquipo,
		const Posicion& unaPosicion
	) const;

	const AccionDefensiva& responderTiro3De(
		const Equipo& unEquipo,
		const Posicion& unaPosicion
	) const;
};

#endif
