#include <3ds.h>
#include <stdio.h>
#include <string.h>
#include "RayTracer.h"
#include "Color.h"

int main(int argc, char **argv)
{
	gfxInitDefault();

	//Initialize console on top screen. Using NULL as the second argument tells the console library to use the internal console structure as current one
	consoleInit(GFX_BOTTOM, NULL);

	//We don't need double buffering in this example. In this way we can draw our image only once on screen.
	gfxSetDoubleBuffering(GFX_TOP, false);

	//Get the bottom screen's frame buffer
	u8* fb = gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL);

	printf("World's Slowest Ray Tracer\n");
	printf("Crunching numbers. Please wait.\n");

	gfxFlushBuffers();
	gfxSwapBuffers();
	
	//Copy our image in the bottom screen's frame buffer
	/*memcpy(fb, brew_bgr, brew_bgr_size);*/

	RayTracer rt(400, 240);
	rt.Setup();

	// Main loop
	int x = 0;
	int y = 0;
	bool complete = false;

	//Calculate our initial RGB values
	float* rgb = new float[400 * 240 * 3];
	float maximal = 0.f;
	while (!complete)
	{
		Color c = rt.TracePixel(x, y);

		if (c.r > maximal)
			maximal = c.r;
		if (c.g > maximal)
			maximal = c.g;
		if (c.b > maximal)
			maximal = c.b;

		int idx = ((x)*240) + (239-(y));
		rgb[idx*3+0] = c.b;
		rgb[idx*3+1] = c.g;
		rgb[idx*3+2] = c.r;

		x++;
		if (x > 399)
		{
			x = 0;
			y++;
		}
		if (y > 240)
			complete = true;
	}
	complete = false;
	x = 0;
	y = 0;

	printf("Clamping color values.\n");
	gfxFlushBuffers();
	gfxSwapBuffers();

	// Clamp colors to max
	while (!complete)
	{
		int idx = ((x)*240) + (239-(y));
		rgb[idx*3+0] /= maximal;
		rgb[idx*3+1] /= maximal;
		rgb[idx*3+2] /= maximal;

		x++;
		if (x > 399)
		{
			x = 0;
			y++;
		}
		if (y > 240)
			complete = true;
	}
	complete = false;
	x = 0;
	y = 0;

	printf("Finished. Coloring screen now.");

	gfxFlushBuffers();
	gfxSwapBuffers();

	while (aptMainLoop())
	{
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();

		//hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		u32 kDown = hidKeysDown();

		if (kDown & KEY_START) break; // break in order to return to hbmenu

		//Provides a sort of animation
		if (!complete)
		{
			int idx = ((x)*240) + (239-(y));

			fb[idx*3+0] = (u8)(255 * rgb[idx*3+0]);
			fb[idx*3+1] = (u8)(255 * rgb[idx*3+1]);
			fb[idx*3+2] = (u8)(255 * rgb[idx*3+2]);

			x++;
			if (x > 399)
			{
				x = 0;
				y++;
			}
			if (y > 240)
				complete = true;
		}


		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();

		//Wait for VBlank
		if (complete)
			gspWaitForVBlank();
	}

	// Exit services
	gfxExit();
	return 0;
}
