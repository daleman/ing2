#include "acciones.h"

#include "simuladores.h"
#include "estrategias.h"

#include <cassert>
#include <random>

using std::shared_ptr;

AccionOfensiva::AccionOfensiva(
	shared_ptr<Posicion> desde,
	const Equipo& equipo
) : desde(desde), equipo(equipo)
{
}

Pase::Pase(
	shared_ptr<Posicion> desde,
	shared_ptr<Posicion> hasta,
	const Equipo& equipo,
	shared_ptr<AccionOfensiva> proximo
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
	return bernoulli(1 - desde->darPosicion(equipo).to * .1);
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

shared_ptr<AccionDefensiva> Pase::darReaccionDefensiva(
	shared_ptr<const EstrategiaDefensiva> unaEstrategiaDefensiva
) const
{
	return unaEstrategiaDefensiva->responderPaseDe(equipo, desde);
}

bool Tiro3Puntos::triunfaConPases(int pases) const
{
	const Jugador& jugador = desde->darPosicion(equipo);
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

shared_ptr<AccionDefensiva> Tiro3Puntos::darReaccionDefensiva(
	shared_ptr<const EstrategiaDefensiva> unaEstrategiaDefensiva
) const
{
	return unaEstrategiaDefensiva->responderTiro3De(equipo, desde);
}

AccionDefensiva::AccionDefensiva(
	shared_ptr<Posicion> desde,
	const Equipo& equipo
) : desde(desde),
    equipo(equipo)
{
}

bool IntercepcionDefensiva::verSiTriunfa() const
{
	return bernoulli(desde->darPosicion(equipo).spg * .2);
}

void IntercepcionDefensiva::simularTriunfo(
	SimuladorTurno& unSimuladorTriunfo,
	const Equipo& unEquipo,
	const Equipo& otroEquipo
) const
{
	unSimuladorTriunfo.simular(otroEquipo, unEquipo);
}

bool IntercepcionContraofensiva::verSiTriunfa() const
{
	return true;
}

void IntercepcionContraofensiva::simularTriunfo(
	SimuladorTurno& unSimuladorTriunfo,
	const Equipo& unEquipo,
	const Equipo& otroEquipo
) const
{
	assert(("Not implemented", false));
}

bool BloqueoDefensivo::verSiTriunfa() const
{
	return bernoulli(desde->darPosicion(equipo).bpg * .2);
}

void BloqueoDefensivo::simularTriunfo(
	SimuladorTurno& unSimuladorTriunfo,
	const Equipo& unEquipo,
	const Equipo& otroEquipo
) const
{
	assert(("Not implemented", false));
}

bool BloqueoContraofensivo::verSiTriunfa() const
{
	return true;
}

void BloqueoContraofensivo::simularTriunfo(
	SimuladorTurno& unSimuladorTriunfo,
	const Equipo& unEquipo,
	const Equipo& otroEquipo
) const
{
	assert(("Not implemented", false));
}

bool Rebote::verSiTriunfa() const
{
	return bernoulli(desde->darPosicion(equipo).rpg * .05);
}

void Rebote::simularTriunfo(
	SimuladorTurno& unSimuladorTriunfo,
	const Equipo& unEquipo,
	const Equipo& otroEquipo
) const
{
	assert(("Not implemented", false));
}
