#include "personas.h"

#include <algorithm>
#include <random>

using std::random_device;
using std::minstd_rand;
using std::discrete_distribution;

const EstrategiaOfensiva& Tecnico::elegirEstrategiaOfensiva() const
{
	vector <int> pesos;
	for (auto& k : tacticasOfensivas)
		pesos.push_back(k.peso);

	discrete_distribution<> dist(pesos.begin(), pesos.end());

	random_device rd;
	return tacticasOfensivas[dist(rd)].estrategia;
}

const EstrategiaDefensiva& Tecnico::elegirEstrategiaDefensiva() const
{
	vector <int> pesos;
	for (auto& k : tacticasDefensivas)
		pesos.push_back(k.peso);

	discrete_distribution<> dist(pesos.begin(), pesos.end());

	random_device rd;
	return tacticasDefensivas[dist(rd)].estrategia;
}
