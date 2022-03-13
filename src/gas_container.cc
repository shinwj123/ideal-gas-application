#include "gas_container.h"

using std::string;
using std::vector;
using std::pair;
using glm::dot;
using glm::vec2;
using glm::distance;
using glm::length;

namespace idealgas {

GasContainer::GasContainer() {}

GasContainer::GasContainer(const std::string& color, std::vector<Particle> particles_) {
    color_ = color;
    particles_ = particles;
}

void GasContainer::Display() const {
  // This function has a lot of magic numbers; be sure to design your code in a way that avoids this.
  DrawContainerWall();

  for (Particle particle : particles_) {
      particle.DrawParticle();
  }
}

void GasContainer::AdvanceOneFrame() {
    for (size_t i = 0; i < particles_.size(); i++) {
        for(size_t j = 1 + i; j < particles_.size(); j++) {
            if (CheckCollide(particles_[i], particles_[j])) {
                Collide(particles_[i],particles_[j]);
            }
        }
        particles_[i].Update();
    }
}

void GasContainer::DrawContainerWall() {
    ci::gl::color(ci::Color(color_.c_str()));
    ci::gl::drawStrokedRect(ci::Rectf(vec2(xLowerBound, yLowerBound), vec2(xUpperBound, yUpperBound)))
}

void GasContainer::AddParticles(size_t amount, double radius, const std::string& color, size_t x_coord, size_t y_coord,
                                double initial_x_vel, double initial_y_vel) {
    for (size_t i = 0; i < amount; i++) {
        particles_.emplace_back(vec2(x_coord, y_coord), vec2(initial_x_vel, initial_y_vel), radius, color);
    }
}

void GasContainer::Collide(Particle& particle, Particle& particle1) {
    vec2 v_difference = particle.GetVelocity() - particle1.GetVelocity();
    vec2 x_difference = particle.GetPosition() - particle1.GetPosition();

    float magnitude = length(x1_difference);
    float dot = dot(v_difference,x_difference);

    vec2 v1_difference = particle1.GetVelocity() - particle.GetVelocity();
    vec2 x1_difference = particle1.GetPosition() - particle.GetPosition();

    float magnitude1 = length(x1_difference);
    float dot1 = dot(v1_difference,x1_difference);

    vec2 new_velocity = particle.GetVelocity() - (static_cast<float>(dot / (magnitude, 2)^2 )) * x_difference;
    vec2 new_velocity1 = particle1.GetVelocity() - (static_cast<float>(dot1 / (magnitude1, 2)^2))) * x1_difference;

    particle.SetVelocity(new_velocity);
    particle1.SetVelocity(new_velocity1);
}

bool GasContainer::CheckCollide(const Particle& particle1, const Particle& particle2) {
    if (particle1.GetRadius() + particle2.GetRadius() > distance(particle1.GetPosition(),particle2.GetPosition()))
    {
        vec2 v1_difference = particle1.GetVelocity() - particle2.GetVelocity();
        vec2 x1_difference = particle1.GetPosition() - particle2.GetPosition();

        if (dot(v1_difference, x1_difference) < 0) {
            return true;
        }
    }

    return false;
}

}  // namespace idealgas
