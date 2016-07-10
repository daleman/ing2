#ifndef PERSONAS_H
#define PERSONAS_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class Jugador
{
	string nombre;
	float fgpt, tppt, rpg, apt, bpg, spg, to, ppg;

	public:
	string darNombre() const;

	float darFgpt() const;
	float darTppt() const;
	float darRpg() const;
	float darApt() const;
	float darBpg() const;
	float darSpg() const;
	float darTo() const;
	float darPpg() const;

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
	const string nombre;

	const vector <PreferenciaOfensiva> tacticasOfensivas;
	const vector <PreferenciaDefendiva> tacticasDefensivas;

	public:
	string darNombre() const;

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
	int peso;

	public:
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
