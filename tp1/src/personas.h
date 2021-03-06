#ifndef PERSONAS_H
#define PERSONAS_H

#include <string>
#include <vector>

#include "clases.h"
#include "estrategias.h"

using std::string;
using std::vector;

class Jugador
{
	public:

	const string nombre;
	const float fgpt, tppt, rpg, apg, bpg, spg, to, ppg;

	Jugador(
		string nombre,
		float fgpt,
		float tppt,
		float rpg,
		float apg,
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

	shared_ptr<const EstrategiaOfensiva> elegirEstrategiaOfensiva() const;
	shared_ptr<const EstrategiaDefensiva> elegirEstrategiaDefensiva() const;

	Tecnico(
		string nombre,
		vector <PreferenciaOfensiva> tacticasOfensivas,
		vector <PreferenciaDefensiva> tacticasDefensivas
	);
};

class Preferencia
{
	public:
	const int peso;

	protected:
	Preferencia(int peso);
};

class PreferenciaOfensiva : public Preferencia
{
	public:
	shared_ptr<const EstrategiaOfensiva> estrategia;

	PreferenciaOfensiva(
		int peso,
		shared_ptr<const EstrategiaOfensiva> estrategia
	);
};

class PreferenciaDefensiva : public Preferencia
{
	public:
	shared_ptr<const EstrategiaDefensiva> estrategia;

	PreferenciaDefensiva(
		int peso,
		shared_ptr<const EstrategiaDefensiva> estrategia
	);
};

#endif
