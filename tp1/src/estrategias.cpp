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
AccionOfensiva&& ColectivaExternaDe3PuntosLuegoDeKPases::darAccionDe(const Equipo& unEquipo) const
{
	return std::move(
		Pase(Base(), Escolta(), unEquipo,
			Pase(Escolta(), Alero(), unEquipo,
				Pase(Alero(), AlaPivot(), unEquipo,
					Tiro3Puntos(AlaPivot(), unEquipo)
				)
			)
		)
	);
}

ColectivaInternaDe2PuntosLuegoDeKPases::ColectivaInternaDe2PuntosLuegoDeKPases(int k)
 : k(k)
{
}

AccionOfensiva&& ColectivaInternaDe2PuntosLuegoDeKPases::darAccionDe(const Equipo& unEquipo) const
{
	assert(("Not implemented", false));
}

AccionOfensiva&& MVP::darAccionDe(const Equipo& unEquipo) const
{
	assert(("Not implemented", false));
}

AccionDefensiva&& Contraataque::responderPaseDe(
	const Equipo& unEquipo,
	const Posicion& unaPosicion
) const
{
	assert(("Not implemented", false));
}

AccionDefensiva&& Contraataque::responderTiro2De(
	const Equipo& unEquipo,
	const Posicion& unaPosicion
) const
{
	assert(("Not implemented", false));
}

AccionDefensiva&& Contraataque::responderTiro3De(
	const Equipo& unEquipo,
	const Posicion& unaPosicion
) const
{
	assert(("Not implemented", false));
}

AccionDefensiva&& HombreAHombre::responderPaseDe(
	const Equipo& unEquipo,
	const Posicion& unaPosicion
) const
{
	std::cerr << "Haciendo cosas" << std::endl;
	return std::move(IntercepcionDefensiva(unaPosicion, unEquipo));
}

AccionDefensiva&& HombreAHombre::responderTiro2De(
	const Equipo& unEquipo,
	const Posicion& unaPosicion
) const
{
	assert(("Not implemented", false));
}

AccionDefensiva&& HombreAHombre::responderTiro3De(
	const Equipo& unEquipo,
	const Posicion& unaPosicion
) const
{
	assert(("Not implemented", false));
}
