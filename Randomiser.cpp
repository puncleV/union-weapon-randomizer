#include <random>

namespace GOTHIC_ENGINE {
    class Randomizer {
    private:
        std::mt19937 gen;

        void Seed() {
            std::random_device rdev;
            std::mt19937::result_type data[std::mt19937::state_size];
            std::generate_n(data, std::mt19937::state_size, std::ref(rdev));
            std::seed_seq prng_seed(data, data + std::mt19937::state_size);
            gen.seed(prng_seed);
        }

    public:
        Randomizer() {
            Seed();
        };

        int Random(int min, int max) {
            std::uniform_int_distribution<unsigned> distrib((((min) < (max)) ? (min) : (max)), (((min) > (max)) ? (min) : (max)));
            return distrib(gen);
        }

        template<std::size_t SIZE>
        zSTRING getRandomArrayElement(std::array<zSTRING, SIZE> elements) {
            return elements[Random(0, elements.size() - 1)];
        }
    };

    Randomizer randomizer;
}