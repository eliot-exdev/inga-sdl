//
// Copyright 2020 Timo Kloss
//
// This file is part of Inga.
//
// Inga is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Inga is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with LowRes NX.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef Element_h
#define Element_h

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "Config.h"
#include "Utils.h"
#include "Image.h"
#include "ImageSet.h"
#include "NavigationMap.h"

typedef struct Location Location;

enum ElementAction {
    ElementActionIdle,
    ElementActionMove,
    ElementActionTalk,
    ElementActionAnimate
};

typedef struct Element {
    int id;
    Location *location;
    Vector position;
    bool isSelectable;
    SDL_Rect selectionRect;
    Vector target;
    bool isVisible;
    char name[ELEMENT_NAME_SIZE];
    struct Image *image;
    int frameIndex;
    int frameTicks;
    struct ImageSet *imageSet;
    int imageId;
    Vector direction;
    enum ElementAction action;
    NavigationPath *navigationPath;
    int navigationIndex;
    float speed;
    struct Element *next;
} Element;

Element *CreateElement(int id);
void FreeElement(Element *element);
void UpdateElement(Element *element, int deltaTicks);
void DrawElement(Element *element);
bool IsPointInElement(Element *element, int x, int y);

void ElementStop(Element *element);
void ElementLookTo(Element *element, int x, int y, int imageId);
void ElementMoveTo(Element *element, int x, int y, int imageId);
void ElementTalk(Element *element, const char *text, int imageId);
void ElementAnimate(Element *element, int imageId);

#endif /* Element_h */
