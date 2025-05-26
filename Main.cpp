#define VELOCITY
#define ACCELERATION

#include <iostream>
#include <vector>

#include "raylib.h"

#include "Bond.h"
#include "EatingParticle.h"

int main() {

	InitWindow(800, 450, "Particles");

    auto particles = std::vector<std::unique_ptr<Particle>>();
    auto bonds     = std::vector <std::unique_ptr<Bond>>();

    for (size_t i = 0; i < 20; i++)
    {
        particles.push_back(std::make_unique<Particle>(Particle(i * 11, i * 11, 100, 100)));
    }

    for (size_t i = 1; i < particles.size(); i++) {
        bonds.push_back(std::make_unique<Bond>(Bond(*particles[0], *particles[i], 200, 100)));
    }


    //pop.push_back(std::make_unique<EatingParticle>(EatingParticle(1,1,20,20)));

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        for (size_t i = 0; i < bonds.size(); i++) {
            bonds[i]->update();
            bonds[i]->draw();
        }

        for (size_t i = 0; i < particles.size(); i++) {
            if (particles[i]->destroyed == true) {
                particles.erase(particles.begin() + i);
            }
            for (size_t j = 0; j < particles.size(); j++) {
                if (i == j) continue;
                particles[i]->collide(*particles[j]);
            }
            particles[i]->update();
            particles[i]->draw();
        }

        EndDrawing();
    }

    CloseWindow();
	return 0;
}