#include "personas.h"

#include <algorithm>
#include <memory>
#include <random>

using std::shared_ptr;
using std::make_shared;

shared_ptr<const EstrategiaOfensiva> Tecnico::elegirEstrategiaOfensiva() const
{
	vector <int> pesos;
	for (auto& k : tacticasOfensivas)
		pesos.push_back(k.peso);

	std::discrete_distribution<> dist(pesos.begin(), pesos.end());

	std::random_device rd;
	return tacticasOfensivas.at(dist(rd)).estrategia;
}

shared_ptr<const EstrategiaDefensiva> Tecnico::elegirEstrategiaDefensiva() const
{
	vector <int> pesos;
	for (auto& k : tacticasDefensivas)
		pesos.push_back(k.peso);

	std::discrete_distribution<> dist(pesos.begin(), pesos.end());

	std::random_device rd;
	return tacticasDefensivas.at(dist(rd)).estrategia;
}

Preferencia::Preferencia(int peso)
 : peso(peso)
{
}

PreferenciaOfensiva::PreferenciaOfensiva(
	int peso,
	shared_ptr<const EstrategiaOfensiva> estrategia
) : Preferencia(peso),
    estrategia(estrategia)
{
}

PreferenciaDefensiva::PreferenciaDefensiva(
	int peso,
	shared_ptr<const EstrategiaDefensiva> estrategia
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
