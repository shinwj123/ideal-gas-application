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

