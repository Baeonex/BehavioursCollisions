#pragma once


enum Status
{
	BH_ALPHA,
	BH_BETA,
	BH_INVALID,
	BH_SUCCESS,
	BH_FAILURE,
	BH_RUNNING,
	BH_ABORTED
};
class Agent;

class Behaviour
{
public:
	Behaviour() : m_eStatus(BH_INVALID) {}
	virtual ~Behaviour() {}

	virtual Status update(Agent* agent, float deltaTime) = 0;
	virtual void onIntit() {}
	virtual void onTerminate(Status status) {}

	Status tick(Agent* agent, float deltatime);
	void reset();
	void abort();

	bool isTerminated() const;
	bool isRunning() const;

	Status getStatus() const;

private:
	Status m_eStatus;
};

