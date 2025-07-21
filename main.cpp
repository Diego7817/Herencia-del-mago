#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "Wizard.h"

std::map<int, Wizard*> readCSV(const std::string& filename) {
    std::map<int, Wizard*> wizards;
    std::ifstream file(filename);
    std::string line;
    getline(file, line); // skip header

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> fields;

        while (getline(ss, token, ',')) {
            fields.push_back(token);
        }

        int id = std::stoi(fields[0]);
        std::string name = fields[1];
        std::string last_name = fields[2];
        char gender = fields[3][0];
        int age = std::stoi(fields[4]);
        int id_father = std::stoi(fields[5]);
        bool is_dead = fields[6] == "1";
        std::string type_magic = fields[7];
        bool is_owner = fields[8] == "1";

        wizards[id] = new Wizard(id, name, last_name, gender, age, id_father, is_dead, type_magic, is_owner);
    }

    // Link children to their fathers
    for (auto& [id, wizard] : wizards) {
        if (wizard->id_father != 0 && wizards.count(wizard->id_father)) {
            wizards[wizard->id_father]->children.push_back(wizard);
        }
    }

    return wizards;
}