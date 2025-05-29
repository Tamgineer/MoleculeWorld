#include <iostream>
#include <vector>

#include "raylib.h"

#include "Bond.h"
#include "EatingParticle.h"
#include "Molecule.h"

int main() {

	InitWindow(800, 450, "Particles");

    auto particles = std::vector<std::shared_ptr<Particle>>();
    auto bonds     = std::vector <std::shared_ptr<Bond>>();

    Molecule a = Molecule(20, fullyConnected);
    a.init(particles, bonds);
    for (size_t i = 0; i < particles.size(); i++) {
        particles[i]->vel.x += -100;
    }

    Molecule b = Molecule(10);
    b.init(particles, bonds);

    std::cout << "particles: " << particles.size() << "\n";
    std::cout << "Bonds    : " << bonds.size() << "\n";

    //pop.push_back(std::make_unique<EatingParticle>(EatingParticle(1,1,20,20)));

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        for (size_t i = 0; i < bonds.size(); i++) {
            bonds[i]->update(GetFrameTime());
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
            particles[i]->update(GetFrameTime());
            particles[i]->draw();
        }

        EndDrawing();
    }

    CloseWindow();
	return 0;
}