#pragma once

#include <string>

namespace ly
{
    // Owns the window and runs the game loop.
    // Phase 2: Raylib port.
    class Application
    {
    public:
        Application(unsigned int windowWidth, unsigned int windowHeight,
                    const std::string& title);
        ~Application();

        // Runs until the window closes. Fixed-timestep update, render as fast as allowed.
        void Run();

    private:
        void TickInternal(float deltaTime);
        void RenderInternal();

        float mTargetFrameRate;
    };
}
