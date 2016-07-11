#include "estrategias.h"
#include "acciones.h"
#include "posiciones.h"

#include <cassert>
#include <memory>
#include <random>

using std::shared_ptr;
using std::make_shared;

class Arbitrarizaje
{
	std::random_device rd;
	int last;

	public:
	shared_ptr<Posicion> posicionArbitraria(int min, int max)
	{
		assert(min >= 1 && max <= 5);
		assert(min < max || last != min);

		std::uniform_int_distribution<> dist(min, max);

		int n;
		do
			n = dist(rd);
		while (n != last);

		last = n;
		switch (n)
		{
			case 1:
				return make_shared<Base>();

			case 2:
				return make_shared<Escolta>();

			case 3:
				return make_shared<Alero>();

			case 4:
				return make_shared<AlaPivot>();

			case 5:
				return make_shared<Pivot>();
		}
	}

	Arbitrarizaje() : last(0) {}
};

ColectivaExternaDe3PuntosLuegoDeKPases::ColectivaExternaDe3PuntosLuegoDeKPases(int k)
 : k(k)
{
}

// TODO: Cambiar esto para que haga K pases.
shared_ptr<AccionOfensiva> ColectivaExternaDe3PuntosLuegoDeKPases::darAccionDe(const Equipo& unEquipo) const
{
	return make_shared<Pase>(make_shared<Base>(), make_shared<Escolta>(), unEquipo,
		make_shared<Pase>(make_shared<Escolta>(), make_shared<Alero>(), unEquipo,
			make_shared<Pase>(make_shared<Alero>(), make_shared<AlaPivot>(), unEquipo,
				make_shared<Tiro3Puntos>(make_shared<AlaPivot>(), unEquipo)
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
	Arbitrarizaje a;
	shared_ptr<AccionOfensiva> jugada = make_shared<Tiro2Puntos>(a.posicionArbitraria(4, 5), unEquipo);

	for (int i = 0; i < k - 1; i++)
		jugada = make_shared<Pase>(a.posicionArbitraria(1 + (i == k - 2), 5), jugada->desde, unEquipo, jugada);

	return make_shared<Pase>(make_shared<Base>(), jugada->desde, unEquipo, jugada);
}

shared_ptr<AccionOfensiva> MVP::darAccionDe(const Equipo& unEquipo) const
{
	std::random_device rd;
	std::uniform_int_distribution<> puntaje(2, 3);

	shared_ptr<AccionOfensiva> tiro;

	if (puntaje(rd) == 2)
		tiro = make_shared<Tiro2Puntos>(unEquipo.MVP, unEquipo);
	else
		tiro = make_shared<Tiro3Puntos>(unEquipo.MVP, unEquipo);

	return make_shared<Pase>(make_shared<Base>(), unEquipo.MVP, unEquipo, tiro);
}

shared_ptr<AccionDefensiva> Contraataque::responderPaseDe(
	const Equipo& unEquipo,
	shared_ptr<Posicion> unaPosicion
) const
{
	return make_shared<IntercepcionContraofensiva>(unaPosicion, unEquipo);
}

shared_ptr<AccionDefensiva> Contraataque::responderTiro2De(
	const Equipo& unEquipo,
	shared_ptr<Posicion> unaPosicion
) const
{
	return make_shared<BloqueoContraofensivo>(unaPosicion, unEquipo);
}

shared_ptr<AccionDefensiva> Contraataque::responderTiro3De(
	const Equipo& unEquipo,
	shared_ptr<Posicion> unaPosicion
) const
{
	return make_shared<BloqueoContraofensivo>(unaPosicion, unEquipo);
}

shared_ptr<AccionDefensiva> HombreAHombre::responderPaseDe(
	const Equipo& unEquipo,
	shared_ptr<Posicion> unaPosicion
) const
{
	return make_shared<IntercepcionDefensiva>(unaPosicion, unEquipo);
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
	return make_shared<BloqueoDefensivo>(unaPosicion, unEquipo);
}