#ifndef ESTRATEGIAS_H
#define ESTRATEGIAS_H

#include "clases.h"

class EstrategiaOfensiva
{
	public:
	virtual AccionOfensiva&& darAccionDe(const Equipo& unEquipo) const = 0;
};

class ColectivaExternaDe3PuntosLuegoDeKPases : public EstrategiaOfensiva
{
	public:
	const int k;

	AccionOfensiva&& darAccionDe(const Equipo& unEquipo) const;
	ColectivaExternaDe3PuntosLuegoDeKPases(int k);
};

class ColectivaInternaDe2PuntosLuegoDeKPases : public EstrategiaOfensiva
{
	public:
	const int k;

	AccionOfensiva&& darAccionDe(const Equipo& unEquipo) const;
	ColectivaInternaDe2PuntosLuegoDeKPases(int k);
};

class MVP : public EstrategiaOfensiva
{
	public:
	AccionOfensiva&& darAccionDe(const Equipo& unEquipo) const;
};

class EstrategiaDefensiva
{
	public:

	virtual AccionDefensiva&& responderPaseDe(
		const Equipo& unEquipo,
		const Posicion& unaPosicion
	) const = 0;

	virtual AccionDefensiva&& responderTiro2De(
		const Equipo& unEquipo,
		const Posicion& unaPosicion
	) const = 0;

	virtual AccionDefensiva&& responderTiro3De(
		const Equipo& unEquipo,
		const Posicion& unaPosicion
	) const = 0;
};

class HombreAHombre : public EstrategiaDefensiva
{
	public:

	AccionDefensiva&& responderPaseDe(
		const Equipo& unEquipo,
		const Posicion& unaPosicion
	) const;

	AccionDefensiva&& responderTiro2De(
		const Equipo& unEquipo,
		const Posicion& unaPosicion
	) const;

	AccionDefensiva&& responderTiro3De(
		const Equipo& unEquipo,
		const Posicion& unaPosicion
	) const;
};

class Contraataque : public EstrategiaDefensiva
{
	public:

	AccionDefensiva&& responderPaseDe(
		const Equipo& unEquipo,
		const Posicion& unaPosicion
	) const;

	AccionDefensiva&& responderTiro2De(
		const Equipo& unEquipo,
		const Posicion& unaPosicion
	) const;

	AccionDefensiva&& responderTiro3De(
		const Equipo& unEquipo,
		const Posicion& unaPosicion
	) const;
};

#endif
