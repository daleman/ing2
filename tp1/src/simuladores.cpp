#include "simuladores.h"
#include "acciones.h"

#include <vector>
#include <memory>

using std::make_shared;

Monitor SimuladorPartido::simular(
	const Equipo& unEquipo,
	const Equipo& otroEquipo
)
{
	Monitor monitor(unEquipo.nombre, otroEquipo.nombre);
	Logger logger;

	for (int i = 0; i < 40; i++)
	{
		logger.loguearEstado(monitor);

		SimuladorTurno simulador(monitor, logger);
		simulador.simular(unEquipo, otroEquipo);
	}

	while (monitor.empate())
	{
		logger.loguearEmpate();
		logger.loguearEstado(monitor);

		for (int i = 0; i < 6; i++)
		{
			logger.loguearEstado(monitor);

			SimuladorTurno simulador(monitor, logger);
			simulador.simular(unEquipo, otroEquipo);
		}
	}

	logger.loguearEstado(monitor);
	logger.loguearGanador(monitor);

	return monitor;
}

SimuladorTurno::SimuladorTurno(Monitor& unMonitor, Logger& logger)
 : cadenaPases(0), monitor(unMonitor), logger(logger)
{
}

void SimuladorTurno::simular(
	const Equipo& unEquipo,
	const Equipo& otroEquipo
)
{
	auto accionOfensiva = unEquipo.tecnico.elegirEstrategiaOfensiva()->darAccionDe(unEquipo);
	auto estrategiaDefensiva = otroEquipo.tecnico.elegirEstrategiaDefensiva();

	logger.loguearInicioTurno(unEquipo.nombre, otroEquipo.nombre, accionOfensiva->desde->darPosicion(unEquipo).nombre);

	simularJugada(
		unEquipo,
		otroEquipo,
		accionOfensiva,
		estrategiaDefensiva
	);
}

void SimuladorTurno::simularJugada(
	const Equipo& unEquipo,
	const Equipo& otroEquipo,
	shared_ptr<const AccionOfensiva> unaAccionOfensiva,
	shared_ptr<const EstrategiaDefensiva> unaEstrategiaDefensiva
)
{
	// logger.loguearInicioJugada(unaAccionOfensiva->desde->darPosicion(unEquipo).nombre);
	shared_ptr<AccionDefensiva> accionDefensiva = unaAccionOfensiva->darReaccionDefensiva(unaEstrategiaDefensiva);

	if (accionDefensiva->verSiTriunfa())
		return accionDefensiva->simularTriunfo(*this, unEquipo, otroEquipo);

	if (unaAccionOfensiva->triunfaConPases(cadenaPases))
		return unaAccionOfensiva->simularTriunfo(*this, otroEquipo);

	return unaAccionOfensiva->simularFracaso(*this, otroEquipo);
}

void SimuladorTurno::agregarPase()
{
	cadenaPases += 1;
}

void SimuladorTurno::simularPelotaDividida(
	const Equipo& unEquipo,
	const Equipo& otroEquipo
)
{
	logger.loguearPelotaDividida();
	vector <shared_ptr<Posicion>> p = {
		make_shared<Pivot>(),
		make_shared<AlaPivot>(),
		make_shared<Alero>(),
		make_shared<Escolta>(),
		make_shared<Base>(),
	};

	vector <const Equipo*> e = {
		&otroEquipo,
		&unEquipo
	};

	for (auto& k : p)
	{
		for (auto &h : e)
		{
			auto b = make_shared<Rebote>(k, *h);

			if (b->verSiTriunfa())
				return b->simularTriunfo(*this, *h, *e.at(h->nombre == e[0]->nombre));
			else
				b->simularFracaso(*this, *h, *e.at(h->nombre == e[0]->nombre));
		}
	}

	e.clear();
	logger.loguearFinTurno();
}
