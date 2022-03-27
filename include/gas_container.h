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

  /**
   * Updates the position and velocity value for particles
   */
  void AdvanceOneFrame();

  /**
   * Setting up the size of the container
   */
  const static size_t windowSizeWidth = 1000;
  const static size_t windowSizeHeight = 1000;
  const static size_t xLowerBound = windowSizeWidth * .2;
  const static size_t xUpperBound = windowSizeWidth * .8;
  const static size_t yLowerBound = windowSizeHeight * .2;
  const static size_t yUpperBound = windowSizeHeight * .8;

  /**
   * Draws the container wall
   */
  void DrawContainerWall();

  /**
   * Getter for getting particles
   * @return
   */
  const std::vector<Particle>& GetParticles() const;

  /**
   * Adds particles based on the information of position and velocity
   * @param amount
   * @param radius
   * @param color
   * @param x_coord
   * @param y_coord
   * @param initial_x_vel
   * @param initial_y_vel
   * @param mass
   */
  void AddParticles(size_t amount, double radius, const std::string& color, size_t x_coord, size_t y_coord,
                    double initial_x_vel, double initial_y_vel, double mass);
  /**
   * Checks the post collision velocity
   * @param particle1
   * @param particle2
   */
  void Collide(Particle& particle1, Particle& particle2);

  /**
   * Check whether collision could happen or not
   * @param particle1
   * @param particle2
   * @return
   */
  bool CheckCollide(const Particle& particle1, const Particle& particle2);

  /**
  * Finds the new location of particle as well as check if it hits wall
  */
  void CollideUpdate();

 private:
    constexpr static double minimumVelocity = 0.5;
    std::string color_;
    std::vector<Particle> particles_;

};

}  // namespace idealgas
