#include <stdio.h>

struct fish {
    const char *name;
    const char *species;
    int teeth;
    int age;
};

// Print out the catalog entry
void catalog(struct fish f) {
    printf("%s is a %s with %i teeth. He is %i\n",
        f.name, f.species, f.teeth, f.age);
}

// Print the label for the tank
//~ void label(const char *name, const char *species, int teeth, int age) {
    //~ printf("Name:%s\nSpecies:%s\n%i years old, %i teeth\n",
        //~ name, species, teeth, age);
//~ }

int main() {
    struct fish snappy = {"Snappy", "Piranha", 69, 4};
    catalog(snappy);
    // We're skipping calling label for now
    // label("Snappy", "Piranha", 69, 4);
    return 0;
}
