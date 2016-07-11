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
	return std::make_shared<Pase>(std::make_shared<Base>(), std::make_shared<Escolta>(), unEquipo,
		std::make_shared<Pase>(std::make_shared<Escolta>(), std::make_shared<Alero>(), unEquipo,
			std::make_shared<Pase>(std::make_shared<Alero>(), std::make_shared<AlaPivot>(), unEquipo,
				std::make_shared<Tiro3Puntos>(std::make_shared<AlaPivot>(), unEquipo)
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
	shared_ptr<Posicion> unaPosicion
) const
{
	assert(("Not implemented", false));
}

shared_ptr<AccionDefensiva> Contraataque::responderTiro2De(
	const Equipo& unEquipo,
	shared_ptr<Posicion> unaPosicion
) const
{
	assert(("Not implemented", false));
}

shared_ptr<AccionDefensiva> Contraataque::responderTiro3De(
	const Equipo& unEquipo,
	shared_ptr<Posicion> unaPosicion
) const
{
	assert(("Not implemented", false));
}

shared_ptr<AccionDefensiva> HombreAHombre::responderPaseDe(
	const Equipo& unEquipo,
	shared_ptr<Posicion> unaPosicion
) const
{
	return std::make_shared<IntercepcionDefensiva>(unaPosicion, unEquipo);
}

shared_ptr<AccionDefensiva> HombreAHombre::responderTiro2De(
	const Equipo& unEquipo,
	shared_ptr<Posicion> unaPosicion
) const
{
	assert(("Not implemented", false));
}

shared_ptr<AccionDefensiva> HombreAHombre::responderTiro3De(
	const Equipo& unEquipo,
	shared_ptr<Posicion> unaPosicion
) const
{
	assert(("Not implemented", false));
}
