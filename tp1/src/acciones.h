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
		simuladorTurno& unSimuladorTurno,
		const Equipo& otroEquipo
	) = 0;

	virtual void simularFracaso(
		simularTurno& unSimuladorTurno,
		const Equipo& otroEquipo
	) = 0;

	virtual void darReaccionDefensiva(
		const EstrategiaDefensiva& unaEstrategiaDefensiva
	) = 0;

	AccionOfensiva(
		Posicion& desde,
		const Equipo& equipo
	);
};

class Tiro3Puntos : AccionOfensiva
{
	public:
	bool triunfaConPases(int pases);

	void simularTriunfo(
		simuladorTurno& unSimuladorTurno,
		const Equipo& otroEquipo
	);

	void simularFracaso(
		simularTurno& unSimuladorTurno,
		const Equipo& otroEquipo
	);

	void darReaccionDefensiva(
		const EstrategiaDefensiva& unaEstrategiaDefensiva
	);

	using AccionOfensiva::AccionOfensiva;
};

class Tiro2Puntos : AccionOfensiva
{
	public:
	bool triunfaConPases(int pases);

	void simularTriunfo(
		simuladorTurno& unSimuladorTurno,
		const Equipo& otroEquipo
	);

	void simularFracaso(
		simularTurno& unSimuladorTurno,
		const Equipo& otroEquipo
	);

	void darReaccionDefensiva(
		const EstrategiaDefensiva& unaEstrategiaDefensiva
	);

	using AccionOfensiva::AccionOfensiva;
};

class Pase : AccionOfensiva
{
	public:
	const Posicion& hasta;
	const AccionOfensiva& proximo;

	bool triunfaConPases(int pases);

	void simularTriunfo(
		simuladorTurno& unSimuladorTurno,
		const Equipo& otroEquipo
	);

	void simularFracaso(
		simularTurno& unSimuladorTurno,
		const Equipo& otroEquipo
	);

	void darReaccionDefensiva(
		const EstrategiaDefensiva& unaEstrategiaDefensiva
	);

	Pase(
		Posicion& desde,
		Posicion& hasta,
		const Equipo& Equipo,
		const AccionOfensiva& proximo;
	);
};

class AccionDefensiva
{
	public:
	const Posicion& desde;
	const Equipo& equipo;

	bool verSiTriunfa() = 0;

	void simularTriunfo(
		simuladorTurno& unSimuladorTriunfo,
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	) = 0;

	AccionDefensiva(
		const POsicion& desde,
		const Equipo& equipo
	);
};

class InfercepcionDefensiva
{
	public:
	bool verSiTriunfa();

	void simularTriunfo(
		simuladorTurno& unSimuladorTriunfo,
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	);

	using AccionDefensiva::AccionDefensiva;
};

class InfercepcionContraofensiva
{
	public:
	bool verSiTriunfa();

	void simularTriunfo(
		simuladorTurno& unSimuladorTriunfo,
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	);

	using AccionDefensiva::AccionDefensiva;
};

class BloqueoDefensivo
{
	public:
	bool verSiTriunfa();

	void simularTriunfo(
		simuladorTurno& unSimuladorTriunfo,
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	);

	using AccionDefensiva::AccionDefensiva;
};

class BloqueoContraofensivo
{
	public:
	bool verSiTriunfa();

	void simularTriunfo(
		simuladorTurno& unSimuladorTriunfo,
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	);

	using AccionDefensiva::AccionDefensiva;
};

class Rebote
{
	public:
	bool verSiTriunfa();

	void simularTriunfo(
		simuladorTurno& unSimuladorTriunfo,
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	);

	using AccionDefensiva::AccionDefensiva;
};

#endif
