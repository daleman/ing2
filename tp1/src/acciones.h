#ifndef ACCIONES_H
#define ACCIONES_H

#include "desafio.h"
#include "clases.h"

class AccionOfensiva
{
	public:
	const Posicion& desde;
	const Equipo& equipo;

	virtual bool triunfaConPases(int pases) = 0;

	virtual void simularTriunfo(
		SimuladorTurno& unSimuladorTurno,
		const Equipo& otroEquipo
	) = 0;

	virtual void simularFracaso(
		SimuladorTurno& unSimuladorTurno,
		const Equipo& otroEquipo
	) = 0;

	virtual void darReaccionDefensiva(
		const EstrategiaDefensiva& unaEstrategiaDefensiva
	) = 0;

	AccionOfensiva(
		const Posicion& desde,
		const Equipo& equipo
	);
};

class Tiro3Puntos : public AccionOfensiva
{
	public:
	bool triunfaConPases(int pases);

	void simularTriunfo(
		SimuladorTurno& unSimuladorTurno,
		const Equipo& otroEquipo
	);

	void simularFracaso(
		SimuladorTurno& unSimuladorTurno,
		const Equipo& otroEquipo
	);

	void darReaccionDefensiva(
		const EstrategiaDefensiva& unaEstrategiaDefensiva
	);

	using AccionOfensiva::AccionOfensiva;
};

class Tiro2Puntos : public AccionOfensiva
{
	public:
	bool triunfaConPases(int pases);

	void simularTriunfo(
		SimuladorTurno& unSimuladorTurno,
		const Equipo& otroEquipo
	);

	void simularFracaso(
		SimuladorTurno& unSimuladorTurno,
		const Equipo& otroEquipo
	);

	void darReaccionDefensiva(
		const EstrategiaDefensiva& unaEstrategiaDefensiva
	);

	using AccionOfensiva::AccionOfensiva;
};

class Pase : public AccionOfensiva
{
	public:
	const Posicion& hasta;
	const AccionOfensiva& proximo;

	bool triunfaConPases(int pases);

	void simularTriunfo(
		SimuladorTurno& unSimuladorTurno,
		const Equipo& otroEquipo
	);

	void simularFracaso(
		SimuladorTurno& unSimuladorTurno,
		const Equipo& otroEquipo
	);

	void darReaccionDefensiva(
		const EstrategiaDefensiva& unaEstrategiaDefensiva
	);

	Pase(
		const Posicion& desde,
		const Posicion& hasta,
		const Equipo& Equipo,
		const AccionOfensiva& proximo
	);
};

class AccionDefensiva
{
	public:
	const Posicion& desde;
	const Equipo& equipo;

	virtual bool verSiTriunfa() = 0;

	virtual void simularTriunfo(
		SimuladorTurno& unSimuladorTriunfo,
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	) = 0;

	AccionDefensiva(
		const Posicion& desde,
		const Equipo& equipo
	);
};

class InfercepcionDefensiva : public AccionDefensiva
{
	public:
	bool verSiTriunfa();

	void simularTriunfo(
		SimuladorTurno& unSimuladorTriunfo,
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	);

	using AccionDefensiva::AccionDefensiva;
};

class InfercepcionContraofensiva : public AccionDefensiva
{
	public:
	bool verSiTriunfa();

	void simularTriunfo(
		SimuladorTurno& unSimuladorTriunfo,
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	);

	using AccionDefensiva::AccionDefensiva;
};

class BloqueoDefensivo : public AccionDefensiva
{
	public:
	bool verSiTriunfa();

	void simularTriunfo(
		SimuladorTurno& unSimuladorTriunfo,
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	);

	using AccionDefensiva::AccionDefensiva;
};

class BloqueoContraofensivo : public AccionDefensiva
{
	public:
	bool verSiTriunfa();

	void simularTriunfo(
		SimuladorTurno& unSimuladorTriunfo,
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	);

	using AccionDefensiva::AccionDefensiva;
};

class Rebote : public AccionDefensiva
{
	public:
	bool verSiTriunfa();

	void simularTriunfo(
		SimuladorTurno& unSimuladorTriunfo,
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	);

	using AccionDefensiva::AccionDefensiva;
};

#endif
