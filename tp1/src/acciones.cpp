#include "acciones.h"

#include "simuladores.h"

#include <random>

Pase::Pase(
	const Posicion& desde,
	const Posicion& hasta,
	const Equipo& equipo,
	const AccionOfensiva& proximo
)
 : AccionOfensiva(desde, equipo),
   hasta(hasta),
   proximo(proximo)
{
}

bool bernoulli(float p)
{
	std::random_device rd;
	return std::bernoulli_distribution(p)(rd);
}

bool Pase::triunfaConPases(int pases) const
{
	return bernoulli(1 - desde.darPosicion(equipo).to * .1);
}

void Pase::simularTriunfo(
	SimuladorTurno& unSimuladorTurno,
	const Equipo& otroEquipo
) const
{
	unSimuladorTurno.agregarPase();
	unSimuladorTurno.simularJugada(equipo, otroEquipo, proximo, otroEquipo.tecnico.elegirEstrategiaDefensiva());
}

void Pase::simularFracaso(
	SimuladorTurno& unSimuladorTurno,
	const Equipo& otroEquipo
) const
{
	unSimuladorTurno.simularPelotaDividida(equipo, otroEquipo);
}
