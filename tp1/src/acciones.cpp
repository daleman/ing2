#include "acciones.h"

#include "simuladores.h"

#include <random>

AccionOfensiva::AccionOfensiva(
	const Posicion& desde,
	const Equipo& equipo
) : desde(desde), equipo(equipo)
{
}

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
	unSimuladorTurno.logger.loguearPase(*this, true);

	unSimuladorTurno.agregarPase();
	unSimuladorTurno.simularJugada(equipo, otroEquipo, proximo, otroEquipo.tecnico.elegirEstrategiaDefensiva());
}

void Pase::simularFracaso(
	SimuladorTurno& unSimuladorTurno,
	const Equipo& otroEquipo
) const
{
	unSimuladorTurno.logger.loguearPase(*this, false);

	unSimuladorTurno.simularPelotaDividida(equipo, otroEquipo);
}

const AccionDefensiva& Pase::darReaccionDefensiva(
	const EstrategiaDefensiva& unaEstrategiaDefensiva
) const
{
	return unaEstrategiaDefensiva.responderPaseDe(equipo, desde);
}

bool Tiro3Puntos::triunfaConPases(int pases) const
{
	const Jugador& jugador = desde.darPosicion(equipo);
	return bernoulli(jugador.tppt + (jugador.ppg / 2) * .01 + std::min(jugador.apg * pases, .3f));
}

void Tiro3Puntos::simularTriunfo(
	SimuladorTurno& unSimuladorTurno,
	const Equipo& otroEquipo
) const
{
	unSimuladorTurno.monitor.sumarPuntaje(3, equipo.nombre);
}

void Tiro3Puntos::simularFracaso(
	SimuladorTurno& unSimuladorTurno,
	const Equipo& otroEquipo
) const
{
	unSimuladorTurno.simularPelotaDividida(equipo, otroEquipo);
}

const AccionDefensiva& Tiro3Puntos::darReaccionDefensiva(
	const EstrategiaDefensiva& unaEstrategiaDefensiva
) const
{
	return unaEstrategiaDefensiva.responderTiro3De(equipo, desde);
}

AccionDefensiva::AccionDefensiva(
	const Posicion& desde,
	const Equipo& equipo
) : desde(desde),
    equipo(equipo)
{
}

bool IntercepcionDefensiva::verSiTriunfa() const
{
	return bernoulli(desde.darPosicion(equipo).spg * .2);
}

void IntercepcionDefensiva::simularTriunfo(
	SimuladorTurno& unSimuladorTriunfo,
	const Equipo& unEquipo,
	const Equipo& otroEquipo
) const
{
	unSimuladorTriunfo.simular(otroEquipo, unEquipo);
}
