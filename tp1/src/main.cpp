#include <random>
#include <tuple>
#include <iostream>

#include "simuladores.h"
#include "desafio.h"
#include "logger.h"
#include "posiciones.h"

Jugador jugadorRandom(string nombre)
{
	// Top kek
	std::random_device rd;
	std::mt19937 gen(rd());

	return Jugador(
		nombre,
		std::uniform_real_distribution<float> (0, 1) (gen),
		std::uniform_real_distribution<float> (0, 1) (gen),
		std::normal_distribution<float> (3.7, 1) (gen),
		std::normal_distribution<float> (4.0, 1) (gen),
		std::normal_distribution<float> (1.4, 1) (gen),
		std::normal_distribution<float> (0.3, 1) (gen),
		std::normal_distribution<float> (2.1, 1) (gen),
		std::normal_distribution<float> (14.1, 1) (gen)
	);
}

std::pair<Equipo, Equipo> equiposDePrueba()
{
	Tecnico BillyDonovan(
		"Billy Donovan",
		{
			PreferenciaOfensiva(3, std::make_shared<ColectivaExternaDe3PuntosLuegoDeKPases>(3)),
			PreferenciaOfensiva(2, std::make_shared<ColectivaInternaDe2PuntosLuegoDeKPases>(3)),
			PreferenciaOfensiva(1, std::make_shared<MVP>()),
		},
		{PreferenciaDefensiva(1, std::make_shared<HombreAHombre>())});

	Tecnico DaveWohl(
		"Dave Wohl",
		{
			PreferenciaOfensiva(2, std::make_shared<ColectivaInternaDe2PuntosLuegoDeKPases>(2)),
			PreferenciaOfensiva(5, std::make_shared<MVP>())
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

	std::random_device rd;
	if (std::uniform_int_distribution<> (0, 1) (rd) == 0)
		return std::make_pair(PipeAndFilter, Batch);
	else
		return std::make_pair(Batch, PipeAndFilter);
}

int main(int argc, char *argv[])
{
	bool single = false;
	for (int i = 1; i < argc; i++)
	{
		if (argv[i] == string("--single"))
			single = true;
		else
		{
			std::cerr << "Argument " << argv[i] << " not found!" << std::endl;
			exit(1);
		}
	}

	std::pair<Equipo, Equipo> k = equiposDePrueba();

	const Equipo PipeAndFilter = k.first;
	const Equipo Batch = k.second;

	SimuladorPartido simuladorPartido;

	if (single)
		simuladorPartido.setSingle();

	simuladorPartido.simular(PipeAndFilter, Batch);

	return 0;
}
