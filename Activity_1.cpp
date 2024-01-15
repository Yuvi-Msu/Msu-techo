#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>
#include <ctime>

class Citizen {
public:
    int age;

    Citizen() {
        age = rand() % 101;
    }

    void newCitizen(int newAge) {
        age = newAge;
    }
};

class City {
public:
    std::vector<Citizen> citizens;
    std::string cityName;

    City(std::string name, int num) {
        citizens = std::vector<Citizen>();
        if (name.empty()) {
            cityName = generateName();
        } else {
            cityName = name;
        }

        for (int i = 0; i < num; i++) {
            citizens.push_back(Citizen());
        }
    }

    std::string generateName() {
        std::string randName;
        for (int i = 0; i < 5; i++) {
            char character = 'a' + rand() % 26;
            randName += character;
        }
        return randName;
    }

    void addCitizen() {
        Citizen citizen = Citizen();
        citizens.push_back(citizen);
    }

    int totalCitizen() {
        return citizens.size();
    }
};

class World {
public:
    std::vector<City> cities;

    World(int num) {
        cities = std::vector<City>();
        for (int i = 0; i < num; i++) {
            cities.push_back(City("", num));
        }
    }

    void addCity(std::string name, int num) {
        City newCity = City(name, num);
        cities.push_back(newCity);
    }

    int totalCities() {
        return cities.size();
    }
};

void testForWorld() {
    World world(5);
    assert(world.totalCities() == 5);
}

void testTotalCity() {
    World world(5);
    world.addCity("abcde", 2);
    assert(world.totalCities() == 6);
}

void testTotalCitizen() {
    City city("TestCity", 5);
    assert(city.totalCitizen() == 5);
    city.addCitizen();
    assert(city.totalCitizen() == 6);
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    testForWorld();
    testTotalCity();
    testTotalCitizen();

    std::cout << "All tests passed." << std::endl;

    return 0;
}
