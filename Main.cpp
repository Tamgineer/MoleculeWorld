#include <iostream>
#include <vector>

#include "raylib.h"

#include "Bond.h"
#include "EatingParticle.h"

int main() {

	InitWindow(800, 450, "Particles");

    auto particles = std::vector<std::shared_ptr<Particle>>();
    auto bonds     = std::vector <std::shared_ptr<Bond>>();

    for (size_t i = 0; i < 20; i++)
    {
        particles.emplace_back(std::make_shared<Particle>(Particle(i * 11, i * 11, GetRandomValue(-1, 1), GetRandomValue(-1, 1))));
    }

    //for (size_t i = 1; i < particles.size(); i++) {
    //    bonds.emplace_back(std::make_shared<Bond>(Bond(*particles[0], *particles[i], 150, 4000)));
    //    //bonds.emplace_back(std::make_shared<Bond>(Bond(*particles[i], *particles[i - 1], 200, 1000)));
    //}

    for (size_t i = 0; i < particles.size(); i++) {
        for (size_t j = i; j < particles.size(); j++) {
            bonds.emplace_back(std::make_shared<Bond>(Bond(*particles[i], *particles[j], 200, 1000)));
        }
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