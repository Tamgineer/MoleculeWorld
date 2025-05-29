#pragma once

#include <vector>

#include "Particle.h"
#include "Bond.h"

enum moleculeType
{
	fullyConnected,
	minimum,
};

class Molecule
{
public:
	//definition of molecule happens here
	Molecule(int particleCount, moleculeType type = minimum);
	//building the molecule into the world goes here.
	void init(std::vector<std::shared_ptr<Particle>>& uParticles, std::vector<std::shared_ptr<Bond>>& uBonds);
	int particleCount{};
	

	//NB: All particles must be connected regardless.

private:
	std::vector<std::shared_ptr<Particle>> particles;
	std::vector<std::shared_ptr<Bond>> bonds;

	std::vector<int> nodes;
	std::vector<Vector2> edges;
};

