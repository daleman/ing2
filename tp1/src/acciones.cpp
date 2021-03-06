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
	shared_ptr<const AccionOfensiva> proximo
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
}

shared_ptr<AccionDefensiva> Pase::darReaccionDefensiva(
	shared_ptr<const EstrategiaDefensiva> unaEstrategiaDefensiva,
	const Equipo& conEquipo
) const
{
	return unaEstrategiaDefensiva->responderPaseDe(equipo, desde, conEquipo);
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
	unSimuladorTurno.logger.loguearTiro3(*this, true);
	unSimuladorTurno.monitor.sumarPuntaje(3, equipo.nombre);
}

void Tiro3Puntos::simularFracaso(
	SimuladorTurno& unSimuladorTurno,
	const Equipo& otroEquipo
) const
{
	unSimuladorTurno.logger.loguearTiro3(*this, false);
	unSimuladorTurno.simularPelotaDividida(equipo, otroEquipo);
}

shared_ptr<AccionDefensiva> Tiro3Puntos::darReaccionDefensiva(
	shared_ptr<const EstrategiaDefensiva> unaEstrategiaDefensiva,
	const Equipo& conEquipo
) const
{
	return unaEstrategiaDefensiva->responderTiro3De(equipo, desde, conEquipo);
}

bool Tiro2Puntos::triunfaConPases(int pases) const
{
	const Jugador& jugador = desde->darPosicion(equipo);
	return bernoulli(jugador.tppt + (jugador.ppg / 2) * .01 + std::min(jugador.apg * pases, .3f));
}

void Tiro2Puntos::simularTriunfo(
	SimuladorTurno& unSimuladorTurno,
	const Equipo& otroEquipo
) const
{
	unSimuladorTurno.logger.loguearTiro2(*this, true);
	unSimuladorTurno.monitor.sumarPuntaje(2, equipo.nombre);
}

void Tiro2Puntos::simularFracaso(
	SimuladorTurno& unSimuladorTurno,
	const Equipo& otroEquipo
) const
{
	unSimuladorTurno.logger.loguearTiro2(*this, false);
	unSimuladorTurno.simularPelotaDividida(equipo, otroEquipo);
}

shared_ptr<AccionDefensiva> Tiro2Puntos::darReaccionDefensiva(
	shared_ptr<const EstrategiaDefensiva> unaEstrategiaDefensiva,
	const Equipo& conEquipo
) const
{
	return unaEstrategiaDefensiva->responderTiro2De(equipo, desde, conEquipo);
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
	SimuladorTurno& unSimuladorTurno,
	const Equipo& unEquipo,
	const Equipo& otroEquipo
) const
{
	unSimuladorTurno.logger.loguearIntersepcionDefensiva(*this, true);
	unSimuladorTurno.simular(otroEquipo, unEquipo);
}


void IntercepcionDefensiva::simularFracaso(
	SimuladorTurno& unSimuladorTurno,
	const Equipo& unEquipo,
	const Equipo& otroEquipo
) const
{
	unSimuladorTurno.logger.loguearIntersepcionDefensiva(*this, false);
}

bool IntercepcionContraofensiva::verSiTriunfa() const
{
	return true;
}

void IntercepcionContraofensiva::simularTriunfo(
	SimuladorTurno& unSimuladorTurno,
	const Equipo& unEquipo,
	const Equipo& otroEquipo
) const
{
	unSimuladorTurno.logger.loguearIntersepcionContraofensiva(*this, true);

}

void IntercepcionContraofensiva::simularFracaso(
	SimuladorTurno& unSimuladorTurno,
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
	SimuladorTurno& unSimuladorTurno,
	const Equipo& unEquipo,
	const Equipo& otroEquipo
) const
{
	unSimuladorTurno.logger.loguearBloqueoDefensivo(*this, true);
	unSimuladorTurno.simularPelotaDividida(equipo, otroEquipo);
}

void BloqueoDefensivo::simularFracaso(
	SimuladorTurno& unSimuladorTurno,
	const Equipo& unEquipo,
	const Equipo& otroEquipo
) const
{
	unSimuladorTurno.logger.loguearBloqueoDefensivo(*this, false);
}

bool BloqueoContraofensivo::verSiTriunfa() const
{
	return true;
}

void BloqueoContraofensivo::simularTriunfo(
	SimuladorTurno& unSimuladorTurno,
	const Equipo& unEquipo,
	const Equipo& otroEquipo
) const
{
	assert(("Not implemented", false));
}

void BloqueoContraofensivo::simularFracaso(
	SimuladorTurno& unSimuladorTurno,
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
	SimuladorTurno& unSimuladorTurno,
	const Equipo& unEquipo,
	const Equipo& otroEquipo
) const
{
	unSimuladorTurno.logger.loguearRebote(*this, true);
	unSimuladorTurno.simular(unEquipo, otroEquipo);
}

void Rebote::simularFracaso(
	SimuladorTurno& unSimuladorTurno,
	const Equipo& unEquipo,
	const Equipo& otroEquipo
) const
{
	unSimuladorTurno.logger.loguearRebote(*this, false);
}
