#include "estrategias.h"
#include "acciones.h"
#include "posiciones.h"

#include <cassert>

#include <iostream>

ColectivaExternaDe3PuntosLuegoDeKPases::ColectivaExternaDe3PuntosLuegoDeKPases(int k)
 : k(k)
{
}

// TODO: Cambiar esto para que haga K pases.
const AccionOfensiva& ColectivaExternaDe3PuntosLuegoDeKPases::darAccionDe(const Equipo& unEquipo) const
{
	return std::move(Pase(Base(), Escolta(), unEquipo,
		Pase(Escolta(), Alero(), unEquipo,
			Pase(Alero(), AlaPivot(), unEquipo,
				Tiro3Puntos(AlaPivot(), unEquipo)
			)
		)
	));
}

ColectivaInternaDe2PuntosLuegoDeKPases::ColectivaInternaDe2PuntosLuegoDeKPases(int k)
 : k(k)
{
}

const AccionOfensiva& ColectivaInternaDe2PuntosLuegoDeKPases::darAccionDe(const Equipo& unEquipo) const
{
	assert(("Not implemented", false));
}

const AccionOfensiva& MVP::darAccionDe(const Equipo& unEquipo) const
{
	assert(("Not implemented", false));
}

const AccionDefensiva& Contraataque::responderPaseDe(
	const Equipo& unEquipo,
	const Posicion& unaPosicion
) const
{
	assert(("Not implemented", false));
}

const AccionDefensiva& Contraataque::responderTiro2De(
	const Equipo& unEquipo,
	const Posicion& unaPosicion
) const
{
	assert(("Not implemented", false));
}

const AccionDefensiva& Contraataque::responderTiro3De(
	const Equipo& unEquipo,
	const Posicion& unaPosicion
) const
{
	assert(("Not implemented", false));
}

const AccionDefensiva& HombreAHombre::responderPaseDe(
	const Equipo& unEquipo,
	const Posicion& unaPosicion
) const
{
	return IntercepcionDefensiva(unaPosicion, unEquipo);
}

const AccionDefensiva& HombreAHombre::responderTiro2De(
	const Equipo& unEquipo,
	const Posicion& unaPosicion
) const
{
	assert(("Not implemented", false));
}

const AccionDefensiva& HombreAHombre::responderTiro3De(
	const Equipo& unEquipo,
	const Posicion& unaPosicion
) const
{
	assert(("Not implemented", false));
}
