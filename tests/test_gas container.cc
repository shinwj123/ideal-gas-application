#include "catch.hpp"
#include "particle.h"
#include "gas_container.h"


using idealgas::GasContainer;
using glm::vec2;
using glm::distance;
using std::vector;

GasContainer gasContainer;

TEST_CASE("Test Adding Particles") {
    SECTION("Check particle add") {
        gasContainer.AddParticles(13,13,"orange");
        REQUIRE(gasContainer.GetParticles().size() == 13);
    }
    SECTION("Check particle update") {
        bool checker = true;

        std::vector<Particle> old_particles;

        for (const Particle &particle : gasContainer.GetParticles()) {
            old_particles.push_back(particle);
        }

        gasContainer.AdvanceOneFrame();
        std::vector<Particle> new_particles;

        for (const Particle &new_particle : gasContainer.GetParticles()) {
            new_particles.push_back(new_particle);
        }

        for (size_t i = 0; i < expected_particles.size(); i++) {
            if (new_particles[i].GetPosition() != old_particles[i].GetPosition() + old_particles[i].GetVelocity()) {
                checker = false;
            }
        }

        REQUIRE(checker == true);
    }
}

TEST_CASE("Test Colliding Particles") {
    SECTION("Only X Velocity moving but no collision") {
        gasContainer.AddParticles(1, 10, "orange", 400, 500, 4, 0);
        gasContainer.AddParticles(1, 10, "orange", 430, 500, -5, 0);
        gasContainer.AdvanceOneFrame();

        REQUIRE(vec2(4, 0) == gasContainer.GetParticles()[0].GetVelocity());
        REQUIRE(vec2(-5, 0) == gasContainer.GetParticles()[1].GetVelocity());
}

    SECTION("Only X Velocity moving with Collision") {
        gasContainer.AddParticles(1, 10, "orange", 400, 500, 2, 0);
        gasContainer.AddParticles(1, 10, "orange", 410, 500, -3, 0);
        gasContainer.AdvanceOneFrame();

        SECTION("Distance is less than Radii Combined (Can Collide)") {
            REQUIRE(distance(gasContainer.GetParticles()[0].GetPosition(),
                                  gasContainer.GetParticles()[1].GetPosition()) < 20);
        }

        REQUIRE(vec2(2, 0) == gasContainer.GetParticles()[1].GetVelocity());
        REQUIRE(vec2(-3, 0) == gasContainer.GetParticles()[0].GetVelocity());
    }

    SECTION("Only Y Velocity moving but no collision") {
        gasContainer.AddParticles(1, 10, "orange", 400, 500, 0, 4);
        gasContainer.AddParticles(1, 10, "orange", 400, 530, 0, -4);
        gasContainer.AdvanceOneFrame();
        REQUIRE(vec2(0, 4) == gasContainer.GetParticles()[0].GetVelocity());
        REQUIRE(vec2(0, -4) == gasContainer.GetParticles()[1].GetVelocity());
    }

    SECTION("Only Y Velocity moving with Collision") {
        gasContainer.AddParticles(1, 10, "orange", 400, 500, 0, 4);
        gasContainer.AddParticles(1, 10, "orange", 400, 510, 0, -4);
        gasContainer.AdvanceOneFrame();

    SECTION("Distance is less than Radii Combined (Can Collide)") {
        REQUIRE(distance(gasContainer.GetParticles()[0].GetPosition(),
                              gasContainer.GetParticles()[1].GetPosition()) < 20);
    }

        REQUIRE(vec2(0, -4) == gasContainer.GetParticles()[0].GetVelocity());
        REQUIRE(vec2(0, 4) == gasContainer.GetParticles()[1].GetVelocity());
    }
}

TEST_CASE("Particle Collides with Right Wall and Changes Velocity") {
    Particle particle(vec2(GasContainer::xUpperBound - 5, 75), vec2(5, 0), 5, "orange");
    double current_x = particle.GetVelocity().x;

    particle.Update();

    SECTION("Check Velocity Change") {
        REQUIRE(-(current_x) == particle.GetVelocity().x);
    }
    SECTION("Check Position Change") {
        REQUIRE(vec2(800,75) == particle.GetPosition());
    }
}

TEST_CASE("Particle Collides with Left Wall and Changes Velocity") {
    Particle particle(vec2(GasContainer::xLowerBound + 5, 75), vec2(-5, 0), 5, "orange");
    double current_x = particle.GetVelocity().x;

    particle.Update();

    SECTION("Check Velocity Change") {
        REQUIRE(-(current_x) == particle.GetVelocity().x);
    }
    SECTION("Check Position Change") {
        REQUIRE(vec2(200,75) == particle.GetPosition());
    }
}

TEST_CASE("Particle Collides with Top Wall and Changes Velocity") {
    Particle particle(vec2(75, GasContainer::yUpperBound - 5), vec2(0, 5), 5, "orange");
    double current_y = particle.GetVelocity().y;

    particle.Update();

    SECTION("Check Velocity Change") {
        REQUIRE(-(current_y) == particle.GetVelocity().y);
    }
    SECTION("Check Position Change") {
        REQUIRE(vec2(75,800) == particle.GetPosition());
    }
}

TEST_CASE("Particle Collides with Bottom Wall and Changes Velocity") {
    Particle particle(vec2(75, GasContainer::yLowerBound + 5), vec2(0, -5), 5, "orange");
    double current_y = particle.GetVelocity().y;

    particle.Update();

    SECTION("Check Velocity Change") {
        REQUIRE(-(current_y) == particle.GetVelocity().y);
    }

    SECTION("Check Position Change") {
        REQUIRE(vec2(75,200) == particle.GetPosition());
    }
}
