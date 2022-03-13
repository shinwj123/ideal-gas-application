#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "gas_container.h"

namespace idealgas {

/**
 * An app for visualizing the behavior of an ideal gas.
 */
class IdealGasApp : public ci::app::App {
 public:
  IdealGasApp();

  /**
   * Draw for simulation
   */
  void draw() override;
  /**
   * Update for simulation
   */
  void update() override;
  /**
   * Set Up for simulation
   */
  void setUp() override;

  // TODO: Delete this comment. Feel free to play around with these variables
  // provided that you can see the entire UI on your screen.
  const int kWindowSize = 875;
  const int kMargin = 100;

 private:
  GasContainer container_;
    const std::string particle1Color = "white";
    const std::string particle2Color = "blue";
    const std::string kParticle3Color = "orange";

    constexpr static double particle1Radius = 12;
    constexpr static double particle2Radius = 10;
    constexpr static double particle3Radius = 5;

    const static size_t particle1Amount = 10;
    const static size_t particle2Amount = 10;
    const static size_t particle3Amount = 10;
};

}  // namespace idealgas
