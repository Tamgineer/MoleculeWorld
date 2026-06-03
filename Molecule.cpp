#include "Molecule.h"
#include "Neuron.h"

Molecule::Molecule(int particleCount, moleculeType type) : particleCount(particleCount) {
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
	default: {
		for (size_t i = 0; i < particleCount - 1; i++) {
			Vector2 v{ i, i + 1 };
			edges.emplace_back(v);
		}
	}	
	}

}

void Molecule::init(std::vector<std::shared_ptr<Particle>>& uParticles, std::vector<std::shared_ptr<Bond>>& uBonds)
{
	for (int i = 0; i < nodes.size(); i++) {
		/*if (i == 0) {
			uParticles.emplace_back(std::make_shared<Neuron>(GetScreenWidth() / 2, GetScreenHeight() / 2, 100, 100));
		}
		else {
			uParticles.emplace_back(std::make_shared<Particle>(GetScreenWidth() / 2, GetScreenHeight() / 2, 100, 100));
		}*/
		uParticles.emplace_back(std::make_shared<Neuron>(GetScreenWidth() / 2, GetScreenHeight() / 2, 100, 100));
		particles.emplace_back(uParticles[uParticles.size() - 1]);
	}

	for (int i = 0; i < edges.size(); i++) {
		uBonds.emplace_back(std::make_shared<Bond>(*particles[edges[i].x], *particles[edges[i].y], 200, 200));
		bonds.emplace_back(uBonds[uBonds.size() - 1]);
	}
}
