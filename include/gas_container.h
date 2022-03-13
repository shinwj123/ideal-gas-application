#pragma once

#include "cinder/gl/gl.h"

using glm::vec2;

namespace idealgas {

/**
 * The container in which all of the gas particles are contained. This class
 * stores all of the particles and updates them on each frame of the simulation.
 */
class GasContainer {
 public:
    /**
     * Blank constructor
     */
    GasContainer();

  /**
   * Constructor for the Gas Container
   * @param color
   * @param particles_
   */
  GasContainer(const std::string& color, std::vector<Particle> particles);

  /**
   * Displays the container walls and the current positions of the particles.
   */
  void Display() const;

  void AdvanceOneFrame();

  const static size_t windowSizeWidth = 1000;
  const static size_t windowSizeHeight = 1000;
  const static size_t xLowerBound = windowSizeWidth * .2;
  const static size_t xUpperBound = windowSizeWidth * .8;
  const static size_t yLowerBound = windowSizeHeight * .2;
  const static size_t yUpperBound = windowSizeHeight * .8;

  void DrawContainerWall();

  const std::vector<Particle>& GetParticles() const;

  void AddParticles(size_t amount, double radius, const std::string& color);


  void AddParticles(size_t amount, double radius, const std::string& color, size_t x_coord, size_t y_coord,
                    double initial_x_vel, double initial_y_vel);

  std::pair<size_t, size_t> GenerateRandomPosition();
  std::pair<double, double> GenerateRandomVelocity(double radius);

  void Collide(Particle& particle1, Particle& particle2);

  bool CheckCollide(const Particle& particle1, const Particle& particle2);

 private:
    constexpr static double minimumVelocity = 0.5;
    std::string color_;
    std::vector<Particle> particles_;

};

}  // namespace idealgas
