#pragma once
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
#include <string>

namespace idealgas {

    class Particle {
    public:
        /**
         * Blank Constructor
         */
        Particle();

        /**
         * Constructor for the Particle
         * @param position
         * @param velocity
         * @param radius
         * @param color
         */
        Particle(const glm::vec2& position, const glm::vec2& velocity, double radius, const std::string& color);

        void SetVelocity(const glm::vec2 &velocity);

        void SetPosition(const glm::vec2 &position);

        const glm::vec2 &GetPosition() const;

        const glm::vec2 &GetVelocity() const;

        const std::string &GetColor() const;

        double GetRadius() const;

        /**
        * Draws a Particle based on radius and position
        */
        void DrawParticle();

        /**
         * Finds the new location of particle as well as check if it hits wall
         */
        void Update();

    private:
        glm::vec2 position_;
        glm::vec2 velocity_;
        std::string color_;
        double radius_;
    };
}