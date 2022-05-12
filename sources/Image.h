//
// Copyright (c) 2020 Timo Kloss
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
//

#ifndef Image_h
#define Image_h

#include <stdio.h>
#include <stdbool.h>
#include "SDL_includes.h"
#include "Utils.h"

typedef struct Frame {
    SDL_Rect sourceRect;
    Vector pivot;
    int ticks;
} Frame;

typedef struct Animation {
    int numFrames;
    Frame *frames;
} Animation;

typedef struct Image {
    SDL_Texture *texture;
    SDL_Surface *surface;
    int width;
    int height;
    Animation *animation;
    Uint8 *pixelBuffer;
} Image;

enum StripDirection {
    StripDirectionHorizontal,
    StripDirectionVertical
};

Image *LoadImage(const char *filename, SDL_Palette *defaultPalette, bool createMask, bool keepSurface);
Image *LoadMaskedImage(const char *filename, Image *sourceImage);
void FreeImage(Image *image);
void DrawImage(const Image *image, Vector position);
void DrawAnimationFrame(const Image *image, Vector position, int index);

#endif /* Image_h */
