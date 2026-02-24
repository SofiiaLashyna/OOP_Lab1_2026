#ifndef GALAXYFACTORY_H
#define GALAXYFACTORY_H

#include "nlohmann/json.hpp"
#include "RandomUtilities.h"
#include "Galaxy.h"
#include "GraphList.h"
#include "Planet.h"
#include "StarSystem.h"
#include "Nebula.h"

class GalaxyFactory {
public:

 /**
  * @brief Populates the galaxy with randomly generated objects.
  *
  * This method calls the factory methods (generateStarSystem, etc.)
  * and adds the results to the galaxy, taking ownership. It also randomly
  * connects objects with edges (distances).
  *
  * @param data JSON data containing generation parameters (Stars, Planets, Nebulae ranges).
  * @param rng Reference to the random number generator utility.
  *
  * @example
  * @code
  * // Load configuration from file
  * std::ifstream f("universe_config.json");
  * json data = json::parse(f);
  * RandomGenerator rng;
  *
  * Galaxy<GraphList<CelestialObject*>> myGalaxy;
  * // Automatically fill the galaxy
  * myGalaxy.generateGalaxy(data, rng);
  * @endcode
  */
    static void populateGalaxy(Galaxy<GraphList<CelestialObject*>>& galaxy, const nlohmann::json& data, RandomGenerator& rng);
    /**
     * @brief Factory method to generate a new random Planet.
     * @param rng Reference to the random number generator utility.
     * @param data JSON data containing generation parameters.
     * @return A pointer to a new Planet object (caller owns it).
     */
    static Planet* createPlanet(const nlohmann::json& data, RandomGenerator& rng);
    /**
     * @brief Factory method to generate a new random StarSystem.
     * @param id The ID to assign to the new system.
     * @param rng Reference to the random number generator utility.
     * @param data JSON data containing generation parameters.
     * @return A pointer to a new StarSystem object (caller owns it).
     */
    static StarSystem* createStarSystem(int id, const nlohmann::json& data, RandomGenerator& rng);
    /**
     * @brief Factory method to generate a new random Nebula.
     * @param rng Reference to the random number generator utility.
     * @param data JSON data containing generation parameters.
     * @return A pointer to a new Nebula object (caller owns it).
     */
    static Nebula* createNebula(const nlohmann::json& data, RandomGenerator& rng);
};

#endif // GALAXYFACTORY_H