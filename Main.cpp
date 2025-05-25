#include <iostream>
#include <vector>

#include "raylib.h"

#include "EatingParticle.h"

int main() {

	InitWindow(800, 450, "Particles");

    auto pop = std::vector<std::unique_ptr<Particle>>();

    for (size_t i = 0; i < 20; i++)
    {
        pop.push_back(std::make_unique<Particle>(Particle(400 + i * 10, 225 + i * 10, 0, 0)));
    }

    pop.push_back(std::make_unique<EatingParticle>(EatingParticle(1,1,20,20)));

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        for (size_t i = 0; i < pop.size(); i++) {
            if (pop[i]->destroyed == true) {
                pop.erase(pop.begin() + i);
            }
            for (size_t j = 0; j < pop.size(); j++) {
                if (i == j) continue;
                pop[i]->collide(*pop[j]);
            }
            pop[i]->update();
            pop[i]->draw();
        }

        EndDrawing();
    }

    CloseWindow();
	return 0;
}