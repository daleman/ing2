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
shared_ptr<AccionOfensiva> ColectivaExternaDe3PuntosLuegoDeKPases::darAccionDe(const Equipo& unEquipo) const
{
	return std::make_shared<Pase>(Base(), Escolta(), unEquipo,
		Pase(Escolta(), Alero(), unEquipo,
			Pase(Alero(), AlaPivot(), unEquipo,
				Tiro3Puntos(AlaPivot(), unEquipo)
			)
		)
	);
}

ColectivaInternaDe2PuntosLuegoDeKPases::ColectivaInternaDe2PuntosLuegoDeKPases(int k)
 : k(k)
{
}

shared_ptr<AccionOfensiva> ColectivaInternaDe2PuntosLuegoDeKPases::darAccionDe(const Equipo& unEquipo) const
{
	assert(("Not implemented", false));
}

shared_ptr<AccionOfensiva> MVP::darAccionDe(const Equipo& unEquipo) const
{
	assert(("Not implemented", false));
}

shared_ptr<AccionDefensiva> Contraataque::responderPaseDe(
	const Equipo& unEquipo,
	const Posicion& unaPosicion
) const
{
	assert(("Not implemented", false));
}

shared_ptr<AccionDefensiva> Contraataque::responderTiro2De(
	const Equipo& unEquipo,
	const Posicion& unaPosicion
) const
{
	assert(("Not implemented", false));
}

shared_ptr<AccionDefensiva> Contraataque::responderTiro3De(
	const Equipo& unEquipo,
	const Posicion& unaPosicion
) const
{
	assert(("Not implemented", false));
}

shared_ptr<AccionDefensiva> HombreAHombre::responderPaseDe(
	const Equipo& unEquipo,
	const Posicion& unaPosicion
) const
{
	return std::make_shared<IntercepcionDefensiva>(unaPosicion, unEquipo);
}

shared_ptr<AccionDefensiva> HombreAHombre::responderTiro2De(
	const Equipo& unEquipo,
	const Posicion& unaPosicion
) const
{
	assert(("Not implemented", false));
}

shared_ptr<AccionDefensiva> HombreAHombre::responderTiro3De(
	const Equipo& unEquipo,
	const Posicion& unaPosicion
) const
{
	assert(("Not implemented", false));
}
