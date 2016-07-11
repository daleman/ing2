#ifndef SIMULADORES_H
#define SIMULADORES_H

#include "clases.h"

class SimuladorPartido
{
	public:
	Monitor simular(
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	);
};

class SimuladorTurno
{
	int cadenaPases;

	public:
	Monitor& monitor;

	void simular(
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	);

	void simularJugada(
		const Equipo& unEquipo,
		const Equipo& otroEquipo,
		const AccionOfensiva& unaAccionO,
		const EstrategiaDefensiva& unaEstrategiaD
	);

	void agregarPase();

	void simularPelotaDividida(
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	);

	SimuladorTurno(Monitor& unMonitor);
};

#endif
