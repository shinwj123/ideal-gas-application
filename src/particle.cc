#include "particle.h"
#include "gas_container.h"

using glm::vec2;

namespace idealgas {

    Particle::Particle() {
    }

    Particle::Particle(const vec2& position, const vec2& velocity, double radius, const std::string& color) {
        position_ = position;
        velocity_ = velocity;
        radius_ = radius;
        color_ = color;
    }

    void Particle::DrawParticle() {
        ci::gl::color(ci::Color(color_.c_str()));
        ci::gl::drawSolidCircle(position_, radius_);
    }

    void Particle::Update() {
        position_ += velocity_;

        if (velocity_.x > 0) {
            if (position_.x >= GasContainer::kXUpperBound - radius_) {
                velocity_.x = -velocity_.x;
            }
        }

        if (velocity_.y > 0) {
            if (position_.y >= GasContainer::kYUpperBound - radius_) {
                velocity_.y = -velocity_.y;
            }
        }

        if (velocity_.x < 0) {
            if (position_.x <= GasContainer::kXLowerBound + radius_) {
                velocity_.x = -velocity_.x;
            }
        }

        if (velocity_.y < 0) {
            if (position_.y <= GasContainer::kYLowerBound + radius_) {
                velocity_.y = -velocity_.y;
            }
        }
    }

    void Particle::SetVelocity(const glm::vec2& velocity) {
        velocity_ = velocity;
    }

    void Particle::SetPosition(const glm::vec2& position) {
        position_ = position;
    }

    const glm::vec2& Particle::GetPosition() const {
        return position_;
    }

    const glm::vec2& Particle::GetVelocity() const {
        return velocity_;
    }

    const std::string& Particle::GetColor() const {
        return color_;
    }

    double Particle::GetRadius() const {
        return radius_;
    }
}

