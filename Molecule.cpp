#include "Molecule.h"
#include "Neuron.h"
#include "InputNeuron.h"
#include "HiddenNeuron.h"

Molecule::Molecule(int particleCount, std::vector<std::shared_ptr<Particle>>& uP, std::vector<std::shared_ptr<Bond>>& uB, moleculeType type) : particleCount(particleCount), uParticles(uP), uBonds(uB) {
	nodes = std::vector<int>();

	for (int i = 0; i < particleCount; i++) {
		nodes.emplace_back(i);
	}

	edges = std::vector<Vector2>();

	switch (type) {
	case fullyConnected :
	{
		for (size_t i = 0; i < particleCount; i++) {
			for (size_t j = i; j < particleCount; j++) {
				Vector2 v{ i, j };
				edges.emplace_back(v);
			}
		}
	}
	break;
	case star: 
	{
		for (size_t i = 1; i < particleCount; i++) {
			Vector2 v{ 0, i };
			edges.emplace_back(v);
		}
	}
	break;
	case minimum: 
	{
		for (size_t i = 0; i < particleCount - 1; i++) {
			Vector2 v{ i, i + 1 };
			edges.emplace_back(v);
		}
	}
	break;
	case custom:
	{
		for (size_t i = 0; i < particleCount - 1; i++) {
			Vector2 v{ i, i + 1 };
			edges.emplace_back(v);
		}
	}
	}

}

void Molecule::init()
{
	if (customEnabled) {
		
		uParticles.emplace_back(std::make_shared<InputNeuron>(GetScreenWidth() / 2, GetScreenHeight() / 2, 100, 100));
		particles.emplace_back(uParticles[uParticles.size() - 1]);

		uParticles.emplace_back(std::make_shared<HiddenNeuron>(GetScreenWidth() / 2, GetScreenHeight() / 2, 100, 100));
		particles.emplace_back(uParticles[uParticles.size() - 1]);

		uParticles.emplace_back(std::make_shared<Neuron>(GetScreenWidth() / 2, GetScreenHeight() / 2, 100, 100));
		particles.emplace_back(uParticles[uParticles.size() - 1]);
		
		for (int i = 0; i < edges.size(); i++) {
			uBonds.emplace_back(std::make_shared<Bond>(*particles[edges[i].x], *particles[edges[i].y], 200, 200));
			bonds.emplace_back(uBonds[uBonds.size() - 1]);
		}
	}
	else {
		for (int i = 0; i < nodes.size(); i++) {
			uParticles.emplace_back(std::make_shared<InputNeuron>(GetScreenWidth() / 2, GetScreenHeight() / 2, 100, 100));
			particles.emplace_back(uParticles[uParticles.size() - 1]);
		}

		for (int i = 0; i < edges.size(); i++) {
			uBonds.emplace_back(std::make_shared<Bond>(*particles[edges[i].x], *particles[edges[i].y], 200, 200));
			bonds.emplace_back(uBonds[uBonds.size() - 1]);
		}
	}

	LifeTime = 10000 * particleCount;
}

void Molecule::update()
{
	LifeTime -= GetFrameTime();
	if (LifeTime <= 0) {
		die();
	}
}

void Molecule::die() 
{
	for (auto b : bonds) {
		uBonds.erase(std::find(uBonds.begin(), uBonds.end(), b));
	}

	bonds.clear();
}
