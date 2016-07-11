#include "simuladores.h"
#include "acciones.h"

#include <iostream>

SimuladorTurno::SimuladorTurno(Monitor& unMonitor, Logger& logger)
 : cadenaPases(0), monitor(unMonitor), logger(logger)
{
}

void SimuladorTurno::simular(
	const Equipo& unEquipo,
	const Equipo& otroEquipo
)
{
	auto a = unEquipo;
	auto b = a.tecnico;
	auto c = b.elegirEstrategiaOfensiva();
	auto d = c->darAccionDe(unEquipo);
	// auto a = unEquipo.tecnico.elegirEstrategiaOfensiva().darAccionDe(unEquipo);

	/*
	simularJugada(
		unEquipo,
		otroEquipo,
		unEquipo.tecnico.elegirEstrategiaOfensiva().darAccionDe(unEquipo),
		otroEquipo.tecnico.elegirEstrategiaDefensiva()
	);
	*/
}

void SimuladorTurno::simularJugada(
	const Equipo& unEquipo,
	const Equipo& otroEquipo,
	shared_ptr<AccionOfensiva> unaAccionOfensiva,
	shared_ptr<const EstrategiaDefensiva> unaEstrategiaDefensiva
)
{
	shared_ptr<AccionDefensiva> accionDefensiva = unaAccionOfensiva->darReaccionDefensiva(unaEstrategiaDefensiva);

	logger.loguearInicioTurno(unEquipo.nombre);
	if (accionDefensiva->verSiTriunfa())
		accionDefensiva->simularTriunfo(*this, unEquipo, otroEquipo);

	if (unaAccionOfensiva->triunfaConPases(cadenaPases))
		unaAccionOfensiva->simularTriunfo(*this, otroEquipo);

	unaAccionOfensiva->simularFracaso(*this, otroEquipo);
}

void SimuladorTurno::agregarPase()
{
	cadenaPases += 1;
}

void SimuladorTurno::simularPelotaDividida(
	const Equipo& unEquipo,
	const Equipo& otroEquipo
)
{
	// TODO: Hacer que esto se comporte como quiera.
	return SimuladorTurno(monitor, logger).simular(otroEquipo, unEquipo);
}
