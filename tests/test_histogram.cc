#include "catch.hpp"

#include "particle.h"
#include "gas_container.h"
#include "histogram.h"

using namespace idealgas;

using std::vector;
using glm::vec2;

Histogram histogram = Histogram();

TEST_CASE("Test Particles Using Mass") {
    Histogram histogram;
    Particle particle(vec2(100, 50), vec2(3, 4), 10, "orange", 1);
    Particle particle2(vec2(100, 50), vec2(4, 3), 10, "orange", 2);
    vector<Particle> particles = {particle, particle2};
    vector<Particle> particles2 = {particle};

    SECTION("Testing particle addition") {
        histogram.setMass(1);
        REQUIRE(histogram.FindParticlesByMass(particles).size() == 1);
    }

    SECTION("Testing invalid particle addition") {
        histogram.setMass(7);
        REQUIRE(histogram.FindParticlesByMass(particles).size() == 0);
    }
}

TEST_CASE("Test Fill Bar value") {
    Histogram histogram;
    Particle particle(vec2(100, 50), vec2(3, 4), 10, "orange", 1);
    Particle particle2(vec2(100, 50), vec2(4, 3), 10, "orange", 1);
    Particle particle3(vec2(100, 50), vec2(5, 5), 10, "orange", 3);
    vector<Particle> particles = {particle, particle2, particle3};
    histogram.setParticles(particles);

    SECTION("Check Fill Bar") {
        histogram.setMass(1);
        histogram.FillBars(histogram.FindParticlesByMass(particles));
        REQUIRE(histogram.getBars()[3] == 2);
    }
}

