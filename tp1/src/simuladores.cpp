#include "simuladores.h"
#include "acciones.h"

SimuladorTurno::SimuladorTurno(Monitor& unMonitor, Logger& logger)
 : cadenaPases(0), monitor(unMonitor), logger(logger)
{
}

void SimuladorTurno::simular(
	const Equipo& unEquipo,
	const Equipo& otroEquipo
)
{
	auto accionOfensiva = unEquipo.tecnico.elegirEstrategiaOfensiva()->darAccionDe(unEquipo);
	auto estrategiaDefensiva = otroEquipo.tecnico.elegirEstrategiaDefensiva();

	logger.loguearInicioTurno(unEquipo.nombre, accionOfensiva->desde->darPosicion(unEquipo).nombre);

	simularJugada(
		unEquipo,
		otroEquipo,
		accionOfensiva,
		estrategiaDefensiva
	);
}

void SimuladorTurno::simularJugada(
	const Equipo& unEquipo,
	const Equipo& otroEquipo,
	shared_ptr<const AccionOfensiva> unaAccionOfensiva,
	shared_ptr<const EstrategiaDefensiva> unaEstrategiaDefensiva
)
{
	// logger.loguearInicioJugada(unaAccionOfensiva->desde->darPosicion(unEquipo).nombre);
	shared_ptr<AccionDefensiva> accionDefensiva = unaAccionOfensiva->darReaccionDefensiva(unaEstrategiaDefensiva);

	if (accionDefensiva->verSiTriunfa())
		return accionDefensiva->simularTriunfo(*this, unEquipo, otroEquipo);

	if (unaAccionOfensiva->triunfaConPases(cadenaPases))
		return unaAccionOfensiva->simularTriunfo(*this, otroEquipo);

	return unaAccionOfensiva->simularFracaso(*this, otroEquipo);
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
	logger.loguearPelotaDividida();
	// TODO: Hacer que esto se comporte como quiera.
	SimuladorTurno(monitor, logger).simular(otroEquipo, unEquipo);
}
