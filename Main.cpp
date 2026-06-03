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
    auto bonds     = std::vector <std::shared_ptr<Bond>>();

    //Molecule a = Molecule(20, fullyConnected);
    Molecule b = Molecule(10, fullyConnected);

    //a.init(particles, bonds);
    //b.init(particles, bonds);

    /*for(auto var : particles)
    {
        var->vel.x = 200;
        var->vel.y = 200;
    }*/
    b.init(particles, bonds);

    std::cout << "particles: " << particles.size() << "\n";
    std::cout << "Bonds    : " << bonds.size() << "\n";

    //pop.push_back(std::make_unique<EatingParticle>(EatingParticle(1,1,20,20)));

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        for (size_t i = 0; i < bonds.size(); i++) {
            bonds[i]->k = 200;

            //let's just make it so that neuron a has more control over neuron b
            if (auto c = dynamic_cast<Neuron*>(&bonds[i]->a)) {
                bonds[i]->k = c->stimulus() * 50;
            }

            /*if (auto c = dynamic_cast<Neuron*>(&bonds[i]->b)) {
                bonds[i]->k -= c->stimulus() * 50;
            }*/

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