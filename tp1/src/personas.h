#ifndef PERSONAS_H
#define PERSONAS_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class Jugador
{
	public:

	const string nombre;
	const float fgpt, tppt, rpg, apt, bpg, spg, to, ppg;

	Jugador(
		string nombre,
		float fgpt,
		float tppt,
		float rpg,
		float apt,
		float bpg,
		float spg,
		float to,
		float ppg
	);
};

class Tecnico
{
	const vector <PreferenciaOfensiva> tacticasOfensivas;
	const vector <PreferenciaDefensiva> tacticasDefensivas;

	public:
	const string nombre;

	const EstrategiaOfensiva& elegirEstrategiaOfensiva() const;
	const EstrategiaDefensiva& elegirEstrategiaDefensiva() const;

	Tecnico(
		string nombre,
		vector <PreferenciaOfensiva> tacticasOfensivas,
		vector <PreferenciaDefendiva> tacticasDefensivas
	);
};

class Preferencia
{
	public:
	const int peso;

	Preferencia() = delete;
};

class PreferenciaOfensiva : Preferencia
{
	public:
	const EstrategiaOfensiva estrategia;

	PreferenciaOfensiva(
		int peso,
		EstrategiaOfensiva estrategia
	);
};

class PreferenciaDefensiva : Preferencia
{
	public:
	const EstrategiaDefensiva estrategia;

	PreferenciaDefensiva(
		int peso,
		EstrategiaDefensiva estrategia
	);
};

#endif
