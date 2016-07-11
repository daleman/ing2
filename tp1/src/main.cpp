#include <random>
#include <tuple>

#include "simuladores.h"
#include "desafio.h"
#include "logger.h"
#include "posiciones.h"

Jugador jugadorRandom(string nombre)
{
	// Top kek
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dist(0, 1);

	return Jugador(
		nombre,
		dist(gen),
		dist(gen),
		dist(gen),
		dist(gen),
		dist(gen),
		dist(gen),
		dist(gen),
		dist(gen)
	);
}

std::pair<Equipo, Equipo> equiposDePrueba()
{
	Tecnico BillyDonovan(
		"Billy Donovan",
		{PreferenciaOfensiva(1, std::make_shared<ColectivaExternaDe3PuntosLuegoDeKPases>(3))},
		{PreferenciaDefensiva(1, std::make_shared<Contraataque>())});

	Tecnico DaveWohl(
		"Dave Wohl",
		{
			PreferenciaOfensiva(2, std::make_shared<ColectivaInternaDe2PuntosLuegoDeKPases>(2)),
			PreferenciaOfensiva(1, std::make_shared<MVP>())
		},
		{PreferenciaDefensiva(1, std::make_shared<HombreAHombre>())}
	);

	Equipo PipeAndFilter(
		"Pipe&Filter",
		BillyDonovan,
		jugadorRandom("Kevin Durant"),
		jugadorRandom("Paul George"),
		jugadorRandom("James Harden"),
		jugadorRandom("Damian Lillard"),
		jugadorRandom("LeBron James"),
		std::make_shared<AlaPivot>()
	);

	Equipo Batch(
		"Batch",
		DaveWohl,
		jugadorRandom("Deandre Jordan"),
		jugadorRandom("Dwight Howard"),
		jugadorRandom("Mason Plumlee"),
		jugadorRandom("Hassan Whiteside"),
		jugadorRandom("Draymond Green"),
		std::make_shared<Pivot>()
	);

	return std::make_pair(PipeAndFilter, Batch);
}

int main()
{
	std::pair<Equipo, Equipo> k = equiposDePrueba();

	const Equipo PipeAndFilter = k.first;
	const Equipo Batch = k.second;

	Monitor unMonitor(PipeAndFilter.nombre, Batch.nombre);
	Logger unLogger;

	SimuladorTurno simulador(unMonitor, unLogger);
	simulador.simular(PipeAndFilter, Batch);

	return 0;
}
