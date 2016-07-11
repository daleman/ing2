#include <tuple>
#include <random>

#include "simuladores.h"
#include "desafio.h"

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
		{PreferenciaOfensiva(1, ColectivaExternaDe3PuntosLuegoDeKPases(3))},
		{PreferenciaDefensiva(1, Contraataque())}
	);

	Tecnico DaveWohl(
		"Dave Wohl",
		{
			PreferenciaOfensiva(2, ColectivaInternaDe2PuntosLuegoDeKPases(2)),
			PreferenciaOfensiva(1, MVP())
		},
		{PreferenciaDefensiva(1, HombreAHombre())}
	);

	Equipo PipeAndFilter(
		"Pipe&Filter",
		BillyDonovan,
		jugadorRandom("Kevin Durant"),
		jugadorRandom("Paul George"),
		jugadorRandom("James Harden"),
		jugadorRandom("Damian Lillard"),
		jugadorRandom("LeBron James"),
		AlaPivot()
	);

	Equipo Batch(
		"Batch",
		DaveWohl,
		jugadorRandom("Deandre Jordan"),
		jugadorRandom("Dwight Howard"),
		jugadorRandom("Mason Plumlee"),
		jugadorRandom("Hassan Whiteside"),
		jugadorRandom("Draymond Green"),
		Base()
	);

	return std::make_pair(PipeAndFilter, Batch);
}

int main()
{
	std::pair<Equipo, Equipo> k = equiposDePrueba();
	Equipo PipeAndFilter = k.first;
	Equipo Batch = k.second;
}
