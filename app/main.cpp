#include "static_lib.h"
#include "dynamic_lib.h"
#include "header_only/math_utils.h"
#include <flecs.h> // Flecs header
#include <iostream>

// Simple Flecs components
struct Position
{
    float x, y;
};
struct Velocity
{
    float x, y;
};

int main()
{
    static_hello();
    shared_hello();

    // Use header-only library
    int sum = math_utils::add(5, 7);
    math_utils::print_result(sum);

    // --- Flecs ECS demo ---
    flecs::world ecs;

    // Register components
    ecs.component<Position>();
    ecs.component<Velocity>();

    // Create moving entity
    ecs.entity("MovingEntity")
        .set<Position>({10.0f, 20.0f})
        .set<Velocity>({1.0f, -0.5f});

    // Movement system
    // System iteration (iter)
    // System registered normally
    ecs.system<Position, const Velocity>("Move")
        .each([](Position &p, const Velocity &v) 
        {
            p.x += v.x;
            p.y += v.y; 
            std::cout << p.x << " " <<  p.y << std::endl;
        });

    // Progress world, system runs automatically
    for (int i = 0; i < 3; ++i)
    {
        ecs.progress();
    }

    // Keep console open in debug mode
#ifdef _DEBUG
    std::cout << "\nPress Enter to exit...";
    std::cin.ignore();
#endif

    return 0;
}