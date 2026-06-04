#include <iostream>
#include <vector>
#include <memory>

#include "Constants.h"

#include "raylib.h"

#include "Bond.h"
#include "Molecule.h"
#include "EatingParticle.h"
#include "Neuron.h"

int main() {

	InitWindow(800, 800, "Particles");

    auto particles = std::vector<std::shared_ptr<Particle>>();
    auto bonds     = std::vector<std::shared_ptr<Bond>>();
    auto molecules = std::vector<std::shared_ptr<Molecule>>();

    for (int i = 0; i < 1; i++) {
        molecules.emplace_back(std::make_shared<Molecule>(3, particles, bonds, custom));
    }

    for (auto m : molecules) {
        m->init();
    }

    std::cout << "particles: " << particles.size() << "\n";
    std::cout << "Bonds    : " << bonds.size() << "\n";

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        /*for (auto m : molecules) {
            m->update();
        }*/

        //reset values
        for (const auto& p : particles) {
            if (auto n = std::dynamic_pointer_cast<Neuron>(p)) {
                n->value = 0;
            }
        }

        for (size_t i = 0; i < bonds.size(); i++) {
            bonds[i]->k = 200;

            //A -> B
            auto a = dynamic_cast<Neuron*>(&bonds[i]->a);
            auto b = dynamic_cast<Neuron*>(&bonds[i]->b);

            if (a) {
                bonds[i]->length = (a->stimulus() + 1) * 100;
            }

            if (a && b) {
                b->value += (a->stimulus() * bonds[i]->weight);
            }

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