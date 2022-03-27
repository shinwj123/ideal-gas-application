#include "catch.hpp"
#include "particle.h"
#include "gas_container.h"

using namespace idealgas;
using glm::vec2;

TEST_CASE("Check Particle Creation") {
    Particle particle(vec2(100, 50), vec2(1, 3), 10, "orange");

    SECTION("Check Position") {
        REQUIRE(100 == particle.GetPosition().x);
        REQUIRE(50 == particle.GetPosition().y);
    }
    SECTION("Check Velocity") {
        REQUIRE(1  == particle.GetVelocity().x);
        REQUIRE(3 == particle.GetVelocity().y);
    }
    SECTION("Check Radius") {
        REQUIRE(particle.GetRadius() == 10);
    }
    SECTION("Check Color") {
        REQUIRE(particle.GetColor() == "orange");
    }
}

TEST_CASE("Check Particle Update") {
    Particle particle(vec2(100, 50), vec2(1, 3), 10, "orange");

    SECTION("Check Updated Position") {
        particle.Update();
        REQUIRE(151 == particle.GetPosition().x);
        REQUIRE(47 == particle.GetPosition().y);
    }
}



