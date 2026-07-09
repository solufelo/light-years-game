#include "core/Application.h"
#include <raylib.h>
#include <chrono>

namespace ly
{
    Application::Application(unsigned int windowWidth, unsigned int windowHeight,
                             const std::string& title)
        : mTargetFrameRate{ 60.f }
    {
        InitWindow(windowWidth, windowHeight, title.c_str());
        SetTargetFPS(60);
    }

    Application::~Application()
    {
        CloseWindow();
    }

    void Application::Run()
    {
        auto lastTime = std::chrono::high_resolution_clock::now();
        float accumulatedTime = 0.f;
        const float targetDeltaTime = 1.f / mTargetFrameRate;

        while (!WindowShouldClose())
        {
            auto currentTime = std::chrono::high_resolution_clock::now();
            float deltaTime = std::chrono::duration<float>(currentTime - lastTime).count();
            lastTime = currentTime;

            // Cap delta time to prevent "spiral of death" during lag spikes
            if (deltaTime > 0.25f)
            {
                deltaTime = 0.25f;
            }

            accumulatedTime += deltaTime;
            while (accumulatedTime >= targetDeltaTime)
            {
                TickInternal(targetDeltaTime);
                accumulatedTime -= targetDeltaTime;
            }

            RenderInternal();
        }
    }

    void Application::TickInternal(float deltaTime)
    {
        (void)deltaTime;
    }

    void Application::RenderInternal()
    {
        BeginDrawing();
        ClearBackground(Color{ 10, 10, 26, 255 }); // deep space, not pure black
        EndDrawing();
    }
}
