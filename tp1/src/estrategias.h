#ifndef ESTRATEGIAS_H
#define ESTRATEGIAS_H

#include "clases.h"

class EstrategiaOfensiva
{
	public:
	virtual AccionOfensiva darAccionDe(const Equipo& unEquipo) const = 0;
};

class ColectivaExternaDe3PuntosLuegoDeKPases : EstrategiaOfensiva
{
	public:
	const int k;

	AccionOfensiva darAccionde(const Equipo& unEquipo);
	ColectivaExternaDe3PuntosLuegoDeKPases(int k);
};

class ColectivaExternaDe2PuntosLuegoDeKPases : EstrategiaOfensiva
{
	public:
	const int k;

	AccionOfensiva darAccionde(const Equipo& unEquipo);
	ColectivaExternaDe2PuntosLuegoDeKPases(int k);
};

class MVP : EstrategiaOfensiva
{
	public:
	AccionOfensiva darAccionde(const Equipo& unEquipo);
};

class EstrategiaDefensiva
{
	public:

	virtual AccionDefensiva responderPaseDe(
		const Equipo& unEquipo,
		Posicion& unaPosicion
	) = 0;

	virtual AccionDefensiva responderTiro2De(
		const Equipo& unEquipo,
		Posicion& unaPosicion
	) = 0;

	virtual AccionDefensiva responderTiro3De(
		const Equipo& unEquipo,
		Posicion& unaPosicion
	) = 0;
};

class HombreAHombre : EstrategiaDefensiva
{
	public:

	AccionDefensiva responderPaseDe(
		const Equipo& unEquipo,
		Posicion& unaPosicion
	);

	AccionDefensiva responderTiro2De(
		const Equipo& unEquipo,
		Posicion& unaPosicion
	);

	AccionDefensiva responderTiro3De(
		const Equipo& unEquipo,
		Posicion& unaPosicion
	);
};

class Contraataque : EstrategiaDefensiva
{
	public:

	AccionDefensiva responderPaseDe(
		const Equipo& unEquipo,
		Posicion& unaPosicion
	);

	AccionDefensiva responderTiro2De(
		const Equipo& unEquipo,
		Posicion& unaPosicion
	);

	AccionDefensiva responderTiro3De(
		const Equipo& unEquipo,
		Posicion& unaPosicion
	);
};

#endif
