#ifndef ACCIONES_H
#define ACCIONES_H

#include "desafio.h"
#include "clases.h"

#include <memory>

class AccionOfensiva
{
	public:
	const Posicion& desde;
	const Equipo& equipo;

	virtual bool triunfaConPases(int pases) const = 0;

	virtual void simularTriunfo(
		SimuladorTurno& unSimuladorTurno,
		const Equipo& otroEquipo
	) const = 0;

	virtual void simularFracaso(
		SimuladorTurno& unSimuladorTurno,
		const Equipo& otroEquipo
	) const = 0;

	virtual shared_ptr<AccionDefensiva> darReaccionDefensiva(
		const EstrategiaDefensiva& unaEstrategiaDefensiva
	) const = 0;

	AccionOfensiva(
		const Posicion& desde,
		const Equipo& equipo
	);
};

class Tiro3Puntos : public AccionOfensiva
{
	public:
	bool triunfaConPases(int pases) const;

	void simularTriunfo(
		SimuladorTurno& unSimuladorTurno,
		const Equipo& otroEquipo
	) const;

	void simularFracaso(
		SimuladorTurno& unSimuladorTurno,
		const Equipo& otroEquipo
	) const;

	shared_ptr<AccionDefensiva> darReaccionDefensiva(
		const EstrategiaDefensiva& unaEstrategiaDefensiva
	) const;

	using AccionOfensiva::AccionOfensiva;
};

class Tiro2Puntos : public AccionOfensiva
{
	public:
	bool triunfaConPases(int pases) const;

	void simularTriunfo(
		SimuladorTurno& unSimuladorTurno,
		const Equipo& otroEquipo
	) const;

	void simularFracaso(
		SimuladorTurno& unSimuladorTurno,
		const Equipo& otroEquipo
	) const;

	shared_ptr<AccionDefensiva> darReaccionDefensiva(
		const EstrategiaDefensiva& unaEstrategiaDefensiva
	) const;

	using AccionOfensiva::AccionOfensiva;
};

class Pase : public AccionOfensiva
{
	public:
	const Posicion& hasta;
	const AccionOfensiva& proximo;

	bool triunfaConPases(int pases) const;

	void simularTriunfo(
		SimuladorTurno& unSimuladorTurno,
		const Equipo& otroEquipo
	) const;

	void simularFracaso(
		SimuladorTurno& unSimuladorTurno,
		const Equipo& otroEquipo
	) const;

	shared_ptr<AccionDefensiva> darReaccionDefensiva(
		const EstrategiaDefensiva& unaEstrategiaDefensiva
	) const;

	Pase(
		const Posicion& desde,
		const Posicion& hasta,
		const Equipo& equipo,
		const AccionOfensiva& proximo
	);
};

class AccionDefensiva
{
	public:
	const Posicion& desde;
	const Equipo& equipo;

	virtual bool verSiTriunfa() const = 0;

	virtual void simularTriunfo(
		SimuladorTurno& unSimuladorTriunfo,
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	) const = 0;

	AccionDefensiva(
		const Posicion& desde,
		const Equipo& equipo
	);
};

class IntercepcionDefensiva : public AccionDefensiva
{
	public:
	bool verSiTriunfa() const;

	void simularTriunfo(
		SimuladorTurno& unSimuladorTriunfo,
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	) const;

	using AccionDefensiva::AccionDefensiva;
};

class IntercepcionContraofensiva : public AccionDefensiva
{
	public:
	bool verSiTriunfa() const;

	void simularTriunfo(
		SimuladorTurno& unSimuladorTriunfo,
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	) const;

	using AccionDefensiva::AccionDefensiva;
};

class BloqueoDefensivo : public AccionDefensiva
{
	public:
	bool verSiTriunfa() const;

	void simularTriunfo(
		SimuladorTurno& unSimuladorTriunfo,
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	) const;

	using AccionDefensiva::AccionDefensiva;
};

class BloqueoContraofensivo : public AccionDefensiva
{
	public:
	bool verSiTriunfa() const;

	void simularTriunfo(
		SimuladorTurno& unSimuladorTriunfo,
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	) const;

	using AccionDefensiva::AccionDefensiva;
};

class Rebote : public AccionDefensiva
{
	public:
	bool verSiTriunfa() const;

	void simularTriunfo(
		SimuladorTurno& unSimuladorTriunfo,
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	) const;

	using AccionDefensiva::AccionDefensiva;
};

#endif
