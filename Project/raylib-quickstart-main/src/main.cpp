/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

For a C++ project simply rename the file to .cpp and re-run the build script 

-- Copyright (c) 2020-2024 Jeffery Myers
--
--This software is provided "as-is", without any express or implied warranty. In no event 
--will the authors be held liable for any damages arising from the use of this software.

--Permission is granted to anyone to use this software for any purpose, including commercial 
--applications, and to alter it and redistribute it freely, subject to the following restrictions:

--  1. The origin of this software must not be misrepresented; you must not claim that you 
--  wrote the original software. If you use this software in a product, an acknowledgment 
--  in the product documentation would be appreciated but is not required.
--
--  2. Altered source versions must be plainly marked as such, and must not be misrepresented
--  as being the original software.
--
--  3. This notice may not be removed or altered from any source distribution.

*/


#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#define MAX_RECTS 100

typedef struct Rect {
    Vector2 position;
    float width;
    float height;
    Color color;
} Rect;

enum Tools {
    Draw = 0,
    Pick = 1
};

int main() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Simple Drawing Package - Rectangle Mode");

    // Variables
    Rect rectangles[MAX_RECTS];
    int rectanglesData[MAX_RECTS]; // a way to store the index of pallete[] of a color of a rectangle, to use for save/load
    int rectCount = 0; // unused as of now
    Color currentColor = BLACK;  // Default color for drawing rectangles
    Vector2 rectStart = { 0 };
    bool drawing = false;
    Tools tool = Tools::Draw;

    for (int i = 0; i < MAX_RECTS; i++)
    {
        rectangles[i].position.x = 200 + (i % 10) * 40;
        rectangles[i].position.y = 100 + (i / 10) * 40;
        rectangles[i].width = 40;
        rectangles[i].height = 40;
        rectangles[i].color = BLACK;
        rectanglesData[i] = 0;
    }

    // Define a simple color palette
    Color palette[] = { BLACK, RED, GREEN, BLUE, YELLOW, ORANGE, PURPLE, MAROON };
    int paletteSize = sizeof(palette) / sizeof(palette[0]);
    int selectedColor = 0;

    SetTargetFPS(60);
    bool showMessageBox = false;

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            // Start a new rectangle
            rectStart = GetMousePosition();
            Vector2 rectEnd = GetMousePosition();
            for (int i = 0; i < MAX_RECTS; i++)
            {
                Rectangle curRect;
                curRect.x = rectangles[i].position.x;
                curRect.y = rectangles[i].position.y;
                curRect.width = rectangles[i].width;
                curRect.height = rectangles[i].height;
                if(tool == Tools::Draw)
                {
                    
                    if (CheckCollisionPointRec(rectStart, curRect))
                    {
                        rectangles[i].color = currentColor;
                        rectanglesData[i] = selectedColor;
                    }
                }
                else if (tool == Tools::Pick)
                {
                    if (CheckCollisionPointRec(rectStart, curRect))
                    {
                        selectedColor = rectanglesData[i];
                        currentColor = palette[selectedColor];
                    }
                }
            }
        }


        // Change color based on palette selection
        for (int i = 0; i < paletteSize; i++) {
            Rectangle colorButton = { 10 + 40 * i, screenHeight - 40, 30, 30 };
            if (GuiButton(colorButton, "")) {
                currentColor = palette[i];
                selectedColor = i;
            }
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw the palette buttons
        for (int i = 0; i < paletteSize; i++) {
            Rectangle colorButton = { 10 + 40 * i, screenHeight - 40, 30, 30 };
            DrawRectangleRec(colorButton, palette[i]);
            if (i == selectedColor) {
                DrawRectangleLinesEx(colorButton, 2, BLACK);  // Highlight selected color
            }
        }

        // Draw tool buttons
        Rectangle toolButtons;
        toolButtons.x = 20;
        toolButtons.y = 20;
        toolButtons.width = 32;
        toolButtons.height = 32;
        if (GuiButton(toolButtons, "#23#") == 1)
        {
            tool = Tools::Draw;
        }

        toolButtons.x = 52;
        toolButtons.y = 20;
        toolButtons.width = 32;
        toolButtons.height = 32;
        if (GuiButton(toolButtons, "#27#") == 1)
        {
            tool = Tools::Pick;
        }

        // Draw all stored rectangles
        for (int i = 0; i < MAX_RECTS; i++) {
            DrawRectangleRec({ rectangles[i].position.x, rectangles[i].position.y, rectangles[i].width, rectangles[i].height }, rectangles[i].color);
        }

        // Draw the current rectangle if drawing


        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}



/*
#include "raylib.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

int main ()
{
	// Tell the window to use vysnc and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(1280, 800, "Hello Raylib");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	// Load a texture from the resources directory
	Texture wabbit = LoadTexture("wabbit_alpha.png");
	
	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		// drawing
		BeginDrawing();

		// Setup the backbuffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		// draw some text using the default font
		DrawText("Hello Raylib", 200,200,20,WHITE);

		// draw our texture to the screen
		DrawTexture(wabbit, 400, 200, WHITE);
		
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// cleanup
	// unload our texture so it can be cleaned up
	UnloadTexture(wabbit);

	// destory the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
*/