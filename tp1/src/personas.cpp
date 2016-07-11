#include "personas.h"

#include <algorithm>
#include <random>

#include <iostream>
#include <memory>

using std::random_device;
using std::minstd_rand;
using std::discrete_distribution;
using std::make_shared;

shared_ptr<const EstrategiaOfensiva> Tecnico::elegirEstrategiaOfensiva() const
{
	vector <int> pesos;
	for (auto& k : tacticasOfensivas)
		pesos.push_back(k.peso);

	discrete_distribution<> dist(pesos.begin(), pesos.end());

	random_device rd;
	return shared_ptr<const EstrategiaOfensiva>(&tacticasOfensivas.at(dist(rd)).estrategia);
}

shared_ptr<const EstrategiaDefensiva> Tecnico::elegirEstrategiaDefensiva() const
{
	vector <int> pesos;
	for (auto& k : tacticasDefensivas)
		pesos.push_back(k.peso);

	discrete_distribution<> dist(pesos.begin(), pesos.end());

	random_device rd;
	return shared_ptr<const EstrategiaDefensiva>(&tacticasDefensivas.at(dist(rd)).estrategia);
}

Preferencia::Preferencia(int peso)
 : peso(peso)
{
}

PreferenciaOfensiva::PreferenciaOfensiva(
	int peso,
	const EstrategiaOfensiva& estrategia
) : Preferencia(peso),
    estrategia(estrategia)
{
}

PreferenciaDefensiva::PreferenciaDefensiva(
	int peso,
	const EstrategiaDefensiva& estrategia
) : Preferencia(peso),
    estrategia(estrategia)
{
}

Tecnico::Tecnico(
	string nombre,
	vector <PreferenciaOfensiva> tacticasOfensivas,
	vector <PreferenciaDefensiva> tacticasDefensivas
) : tacticasOfensivas(tacticasOfensivas),
	tacticasDefensivas(tacticasDefensivas),
	nombre(nombre)
{
}

Jugador::Jugador(
	string nombre,
	float fgpt,
	float tppt,
	float rpg,
	float apg,
	float bpg,
	float spg,
	float to,
	float ppg
) : nombre(nombre),
	fgpt(fgpt),
	tppt(tppt),
	rpg(rpg),
	apg(apg),
	bpg(bpg),
	spg(spg),
	to(to),
	ppg(ppg)
{
}
