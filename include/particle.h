#pragma once
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
#include <string>

using glm::vec2;
using std::string;

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
        Particle(const vec2& position, const vec2& velocity, double radius, const string& color);

        /**
         * Updates the position of the particle post collision based on the velocity
         */
        void Particle::Update();

        /**
         * Setter that sets the velocity of the particle
         * @param velocity
         */
        void SetVelocity(const vec2 &velocity);

        /**
         * Setter that sets the position of the particle
         * @param position
         */
        void SetPosition(const vec2 &position);

        /**
         * Getter that gets the position of the particle
         * @return
         */
        const vec2 &GetPosition() const;

        /**
         * Getter that gets the velocity of the particle
         * @return
         */
        const vec2 &GetVelocity() const;

        /**
         * Getter that gets the color of the particle
         * @return
         */
        const string &GetColor() const;

        /**
         * Getter that gets the radius of the particle
         * @return
         */
        double GetRadius() const;

        /**
        * Draws a Particle based on radius and position
        */
        void DrawParticle();

    private:
        vec2 position_;
        vec2 velocity_;
        string color_;
        double radius_;
    };
}