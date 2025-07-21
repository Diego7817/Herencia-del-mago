// Wizard.h
#pragma once
#include <string>
#include <vector>

class Wizard {
public:
    int id;
    std::string name;
    std::string last_name;
    char gender; // 'H' o 'M'
    int age;
    int id_father;
    bool is_dead;
    std::string type_magic; // elemental, unique, mixed, no_magic
    bool is_owner;
    std::vector<Wizard*> children;

    Wizard(int id, const std::string& name, const std::string& last_name, char gender,
           int age, int id_father, bool is_dead, const std::string& type_magic, bool is_owner);
};//
// Created by Diegoo on 7/20/2025.
//

#ifndef WIZARD_H
#define WIZARD_H

#endif //WIZARD_H
