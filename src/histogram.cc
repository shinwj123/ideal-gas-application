#include "histogram.h"
#include "particle.h"

using std::vector;
using std::string;
using std::to_string;
using glm::length;
using glm::vec2;

namespace idealgas {

Histogram::Histogram() {
    bars_ = vector<int>(partitions_);
}

void Histogram::setMass(int mass) {
    mass_ = mass;
}

void Histogram::setParticles(const vector<Particle>& particles) {
    particles_ = particles;
}

void Historgram::setBars(const vector<int>& bars_) {
    bars_ = bars;
}

int Histogram::getMass() {
    return mass_;
}

const vector<Particle>& Histogram::getParticles() {
    return particles_;
}

const vector<int>& Histogram::getBars() {
    return bars_;
}

void Histogram::DrawParticle(size_t position, vector<Particle>& particles, int mass) {
    mass_ = mass;
    particle_ = SetParticleWithMass(particles);

    FillBars(particle_);
    DrawOutline(position);
    DrawTitle(position);
    DrawXAxis(position);
    DrawYAxis(position);
}

vector<Particle> Histogram::SetParticleWithMass(vector<Particle>& particles) {
    vector<Particle> list_of_particle;

    for (Particle particle : particles) {
        if (mass_ == particle.GetMass()) {
            list_of_particle.push_back(particle)
        }
    }

    return list_of_particle;
}

void Histogram::DrawOutline(size_t position) {
    cinder::gl::drawStrokedRect(cinder::Rectf(vec2{kLowerBoundX, position},
                                              vec2{kUpperBoundX, position + kHeight}));
    cinder::gl::color(cinder::Color("white"));
}

void Histogram::DrawXAxis(size_t position) {
    vec2 location = {(kXLowerBound + kXUpperBound) / 2, position + kHeight};
    const auto surface = cinder::TextBox().color("white").text("Speed").render();
    textureBuilder(location, surface);
}

void Histogram::DrawYAxis(size_t position) {
    vec2 location = {kXUpperBound - 75, (position * 2 + kHeight) / 2};
    const auto surface = cinder::TextBox().color("white").text("Frequency").render();
    textureBuilder(location, surface);
}

void Histogram::DrawTitle(size_t position) {
    vec2 location = {(kXLowerBound + kXUpperBound) / 2, position - 1.6 * kHeight};
    const auto surface = cinder::TextBox().color("white").text(title).render();
    textureBuilder(location, surface);

    string title = "Mass : " + to_string(mass_);
    ci::gl::color(ci::Color("white"));
}

void Histogram::textureBuilder(vec2 location, const auto surface) {
    const auto texture = cinder::gl::Texture::create(surface);
    cinder::gl::draw(texture, location);
}

double Histogram::GetMaxSpeed() {
    double maxSpeed = 0;
    for (Particle particle : particles_) {
        if (length(particle.GetVelocity()) > maxSpeed) {
            maxSpeed = length(particle.GetVelocity());
        }
    }
    return maxSpeed;
}

void Histogram::FillBars(const vector<Particle>& particles) {
    size_t count_of_particles = 0;
    double max_speed = GetMaxSpeed();
    double range_increment = 0;

    range_increment = partitions_ / max_speed;

    for (double min_speed = 0, bar = 0; bar < partitions_; min_speed += range_increment, bar++) {
        for (Particle particle: particles) {
            if (length(particle.GetVelocity()) >= min_speed && length(particle.GetVelocity()) < max_speed) {
                count_of_particles++;
            }

            bars_[bar] = count_of_particles;
        }
    }
}

}