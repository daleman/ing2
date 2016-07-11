#include "simuladores.h"
#include "acciones.h"

void SimuladorTurno::simularJugada(
	const Equipo& unEquipo,
	const Equipo& otroEquipo,
	const AccionOfensiva& unaAccionOfensiva,
	const EstrategiaDefensiva& unaEstrategiaDefensiva
)
{
	AccionDefensiva& accionDefensiva = unaAccionOfensiva.darReaccionDefensiva(unaEstrategiaDefensiva);

	if (accionDefensiva.verSiTriunfa())
		return;

	if (unaAccionOfensiva.triunfaConPases(cadenaPases))
		unaAccionOfensiva.simularTriunfo(*this, otroEquipo);

	unaAccionOfensiva.simularFracaso(*this, otroEquipo);
}
