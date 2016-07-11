#ifndef SIMULADORES_H
#define SIMULADORES_H

#include "clases.h"

class SimuladorPartido
{
	public:

	Monitor& darMonitor();

	Monitor simular(
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	);
};

class SimuladorTurno
{
	int cadenaPases;
	// Monitor monitor;

	public:
	void simular(
		const Equipo& unEquipo,
		const Equipo& otroEquipo,
		Monitor& unMontor
	);

	void simularJugada(
		const Equipo& unEquipo,
		const Equipo& otroEquipo,
		const JugadaOfensiva unaJugadaO,
		const JugadaDefensiva unaJugadaD,
	);

	void agregarPase();

	void simularPelotaDividida(
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	);
};

#endif
