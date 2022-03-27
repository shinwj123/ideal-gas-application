#ifndef CINDER_HISTOGRAM_H
#define CINDER_HISTOGRAM_H

namespace idealgas {
    class Histogram {
    public:
        /**
         * Constructor for histogram
         */
        Histogram();

        /**
         * Setter that sets the mass
         * @param mass
         */
        void setMass(int mass);

        /**
         * Setter that sets the particles
         * @param particles
         */
        void setParticles(const std::vector<Particle>& particles);

        /**
         * Getter that gets the mass
         * @return
         */
        int getMass();

        /**
         * Getter that gets the particles
         * @return
         */
        const vector<Particle>& getParticles();

        /**
         * Getter that gets the bar of the histogram
         * @return
         */
        const std::vector<int>& getBars();

        /**
         * Draws the particle
         * @param position
         * @param particles
         * @param mass
         */
        void DrawParticle(size_t position, std::vector<Particle> particles, int mass);

        /**
         * Helper function to set up the particle with a certain mass
         * @param particle
         * @return vector of the certain particle
         */
        std::vector<Particle> SetParticleWithMass(std::vector<Particle>& particle);

        /**
         * Helper function to draw the outline of the histogram
         * @param position
         */
        void DrawOutline(size_t position);

        /**
         * Helper function to draw the x axis
         * @param position
         */
        void DrawXAxis(size_t position);

        /**
         * Helper function to draw the y axis
         * @param position
         */
        void DrawYAxis(size_t position);

        /**
         * Helper function to draw title
         * @param position
         */
        void DrawTitle(size_t position);

        /**
         * Helper function to build the texture
         * @param location
         * @param surface
         */
        void textureBuilder(glm::vec2 location, const auto surface);

        /**
         * Helper functino to get maximum speed of the particle
         * @return
         */
        double GetMaxSpeed();

        /**
         * Filling the bar with the count of particles
         * @param particles
         */
        void FillBars(const std::vector<Particle>& particles);

    private:
        std::vector<Particle> particles_;
        int mass_;
        std::vector<int> bars_;
        int partitions_ = 4;


        const static size_t kUpperBoundX = GasContainer::kWindowSizeWidth - 400;
        const static size_t kLowerBoundX = GasContainer::kWindowSizeWidth - 200;
        const static size_t kHeight = 200;
    };
}  // namespace idealgas
#endif // CINDER_HISTOGRAM_H