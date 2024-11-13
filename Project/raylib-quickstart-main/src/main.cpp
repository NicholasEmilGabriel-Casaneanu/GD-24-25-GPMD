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

#define MAX_RECTS 1000

typedef struct Rect {
    Vector2 position;
    float width;
    float height;
    Color color;
} Rect;

int main() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Simple Drawing Package - Rectangle Mode");

    // Variables
    Rect rectangles[MAX_RECTS];
    int rectCount = 0;
    Color currentColor = BLACK;  // Default color for drawing rectangles
    Vector2 rectStart = { 0 };
    bool drawing = false;

    // Define a simple color palette
    Color palette[] = { BLACK, RED, GREEN, BLUE, YELLOW, ORANGE, PURPLE, MAROON };
    int paletteSize = sizeof(palette) / sizeof(palette[0]);
    int selectedColor = 0;

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            // Start a new rectangle
            rectStart = GetMousePosition();
            if (rectCount < MAX_RECTS) {
                Vector2 rectEnd = GetMousePosition();

                rectangles[rectCount].position.x = rectStart.x;
                rectangles[rectCount].position.y = rectStart.y;
                rectangles[rectCount].width = 10;
                rectangles[rectCount].height = 10;
                rectangles[rectCount].color = currentColor;
                rectCount++;
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

        // Draw all stored rectangles
        for (int i = 0; i < rectCount; i++) {
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