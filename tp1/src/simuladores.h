#ifndef SIMULADORES_H
#define SIMULADORES_H

#include "clases.h"
#include "logger.h"

#include <memory>

class SimuladorPartido
{
	bool single;

	public:
	void setSingle();

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
	Logger& logger;

	void simular(
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	);

	void simularJugada(
		const Equipo& unEquipo,
		const Equipo& otroEquipo,
		shared_ptr<const AccionOfensiva> unaAccionO,
		shared_ptr<const EstrategiaDefensiva> unaEstrategiaD
	);

	void agregarPase();

	void simularPelotaDividida(
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	);

	SimuladorTurno(Monitor& unMonitor, Logger& logger);
};

#endif
