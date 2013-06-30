#sdltutorials.com
This is my own version of the tutorials from SDLTutorials.com. Some of the code
has been modified slightly to fit what I felt may have been more practical
coding practices as well as my own code style/conventions.

These should all be compiling examples of the sdltutorials.com series.

I wrote these all using Sublime Text 2 as my editor of choice, using `scons` as
a build system. I found a [working example of an SConstruct script][SConstruct]
as well as many other build system instructions for SDL over at the [game
programming wiki][gpwiki].

##Requirements
- scons 2.3.0
- SDL 1.2.15 (I installed SDL and its related libraries via Mac OS X/homebrew):


    brew install sdl sdl_gfx sdl_image sdl_mixer sdl_net sdl_rtf sdl_sound sdl_ttf

[SConstruct]: http://content.gpwiki.org/index.php/SDL:Tutorials:Setup#SCons
[gpwiki]: http://content.gpwiki.org/index.php/SDL:Tutorials:Setup
