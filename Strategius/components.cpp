#pragma once

struct Component {
    double health = 0;
    double mass = 0; //metric tons
    double energyCost = 0; // Kilo Joules
};

struct Weapon : Component {
    enum damageType: int{BasicEnergy, ComplexEnergy, BasicKenetic, ExplosiveKenetic, ShieldPenetratingKenetic, Subspace};

    double damage = 0; //speak softly and carry a high damage weapon
    //number of ticks between shots assuming full power
    double maxFireRate = 0;
    //m/s
    double projectileSpeed = 0;
    //degrees
    double fireArc = 0;
    damageType testing = BasicEnergy;

};

struct Protection : Component {
    enum protectionType: int {Armor, Hull, EnergyShield, PointDefense};

    int numOfTurrets = 0; //This is for point defense systems. If the value is 0 this means its not a PD system
};

struct Propulsion : Component {
    enum propulsionType: int{forward, rotational};
    //Newtons
    double thrust = 0; //if thrust is negative then it is a deceleation thruster
};

struct Sensor: Component {
    enum sensorType: int{targeting, positional};

    bool isActiveSensor = false;
    sensorType type = targeting;
};

struct EnergyGeneration : Component {
    double fuelConsumption = 0;
    bool canMeltDown = false; //The station has a critical weakness, a small heat exhaust port... 
};

struct EnergyStorage : Component {
    double capacity = 0; //kilo watt hours
    bool canMeltDown = false;
};

struct FuelStorage : Component {
    double capacity = 0;
    bool canMeltDown = false; //We're losing anti-matter containment! -LaForge, probably
};
