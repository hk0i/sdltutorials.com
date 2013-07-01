#Changes
- SDL_LoadBMP > IMG_Load() using SDL_image - I made this change because the images they gave on the web were actually pngs and I didn't feel like converting them. (This requires SDL_Image)

##GApp.h
- Added a macro for loading surfaces and returning false on failure w/output message to stderr

##Surface.h
- `char *file` to `const char *file` - don't know why this was mutable before, and it was throwing warnings on my macro.