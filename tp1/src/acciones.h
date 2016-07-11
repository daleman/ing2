#ifndef ACCIONES_H
#define ACCIONES_H

#include "desafio.h"
#include "clases.h"

#include <memory>

class AccionOfensiva
{
	public:
	shared_ptr<Posicion> desde;
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
		shared_ptr<const EstrategiaDefensiva> unaEstrategiaDefensiva
	) const = 0;

	AccionOfensiva(
		shared_ptr<Posicion> desde,
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
		shared_ptr<const EstrategiaDefensiva> unaEstrategiaDefensiva
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
		shared_ptr<const EstrategiaDefensiva> unaEstrategiaDefensiva
	) const;

	using AccionOfensiva::AccionOfensiva;
};

class Pase : public AccionOfensiva
{
	public:
	shared_ptr<Posicion> hasta;
	shared_ptr<const AccionOfensiva> proximo;

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
		shared_ptr<const EstrategiaDefensiva> unaEstrategiaDefensiva
	) const;

	Pase(
		shared_ptr<Posicion> desde,
		shared_ptr<Posicion> hasta,
		const Equipo& equipo,
		shared_ptr<const AccionOfensiva> proximo
	);
};

class AccionDefensiva
{
	public:
	shared_ptr<Posicion> desde;
	const Equipo& equipo;

	virtual bool verSiTriunfa() const = 0;

	virtual void simularTriunfo(
		SimuladorTurno& unSimuladorTriunfo,
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	) const = 0;

	virtual void simularFracaso(
		SimuladorTurno& unSimuladorTriunfo,
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	) const = 0;

	AccionDefensiva(
		shared_ptr<Posicion> desde,
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

	void simularFracaso(
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

	void simularFracaso(
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

	void simularFracaso(
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

	void simularFracaso(
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

	void simularFracaso(
		SimuladorTurno& unSimuladorTriunfo,
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	) const;

	using AccionDefensiva::AccionDefensiva;
};

#endif
