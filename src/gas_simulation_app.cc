#include "gas_simulation_app.h"

namespace idealgas {

IdealGasApp::IdealGasApp() {
  ci::app::setWindowSize(kWindowSize, kWindowSize);
}

void IdealGasApp::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);

  container_.Display();
}

void IdealGasApp::update() {
  container_.AdvanceOneFrame();
}

void IdealGasApp::setup() {
    container_.AddParticles(particle1Amount, particle1Radius,particle1Color);
    container_.AddParticles(particle2Amount, particle2Radius,particle2Color);
    container_.AddParticles(particle3Amount, particle3Radius,particle3Color);
}

}  // namespace idealgas
