#pragma once

#include <vector>

#include "Particle.h"
#include "Bond.h"

enum moleculeType
{
	fullyConnected,
	star,
	minimum,
	custom
};

class Molecule
{
public:
	//definition of molecule happens here
	Molecule(int particleCount, std::vector<std::shared_ptr<Particle>>& uP, std::vector<std::shared_ptr<Bond>>& uB, moleculeType type = minimum);
	//building the molecule into the world goes here.
	void init();
	
	void update();
	void die();
	
	int particleCount{};

	int id{};
	int LifeTime{};

	bool customEnabled{false};
	

	//NB: All particles must be connected regardless.

private:
	std::vector<std::shared_ptr<Particle>> particles;
	std::vector<std::shared_ptr<Bond>> bonds;

	std::vector<std::shared_ptr<Particle>>& uParticles;
	std::vector<std::shared_ptr<Bond>>& uBonds;

	std::vector<int> nodes;
	std::vector<Vector2> edges;
};

