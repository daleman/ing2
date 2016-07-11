#include "simuladores.h"
#include "acciones.h"

SimuladorTurno::SimuladorTurno(Monitor& unMonitor)
 : cadenaPases(0), monitor(unMonitor)
{
}

void SimuladorTurno::simular(
	const Equipo& unEquipo,
	const Equipo& otroEquipo
)
{
	simularJugada(
		unEquipo,
		otroEquipo,
		unEquipo.tecnico.elegirEstrategiaOfensiva().darAccionDe(unEquipo),
		otroEquipo.tecnico.elegirEstrategiaDefensiva()
	);
}

void SimuladorTurno::simularJugada(
	const Equipo& unEquipo,
	const Equipo& otroEquipo,
	const AccionOfensiva& unaAccionOfensiva,
	const EstrategiaDefensiva& unaEstrategiaDefensiva
)
{
	const AccionDefensiva& accionDefensiva = unaAccionOfensiva.darReaccionDefensiva(unaEstrategiaDefensiva);

	if (accionDefensiva.verSiTriunfa())
		return;

	if (unaAccionOfensiva.triunfaConPases(cadenaPases))
		unaAccionOfensiva.simularTriunfo(*this, otroEquipo);

	unaAccionOfensiva.simularFracaso(*this, otroEquipo);
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
	return SimuladorTurno(monitor).simular(otroEquipo, unEquipo);
}
