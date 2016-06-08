SDL2 on Windows through CMake
=============================

People think this is easy, just throw SDL2 on the C:\ root, install CMake if you really need it, and generate a VS project. But the problem is that it's *not* that easy because you end up with something that's a) not as elegant as what you'd normally find on other platforms and b) a big mess that's hard to clean up. Remember, Windows was built for the user, not the developer. Proper workspaces should be easy to set up and clean up, which is why I've invested some time to make a workflow that is cross-platform and keeps external dependencies to an absolute minimum.

To begin, you should download the SDL includes and libraries and place them in `SDL/`. In `lib` you will find `x86` and `x64` so choose one (it'll be `x86` unless you are specifically compiling a 64-bit executable) and bring the contents of that folder up one level (so you'll have `SDL/lib/SDL2.lib` instead of `SDL/lib/x86/SDL2.lib`). You can leave the include folder alone.

Once you have that dependency taken care of, you should invoke cmake in a new folder to separate our source code from our generated project files. We can do this very simply:
```
> mkdir build
> cd build
> cmake ..
```

Text will fly and cmake might yell at you for not having pthreads. Threads are not a required dependency, but it gave me compiler errors anyway and held up the project generation. If you encounter this problem, I've found installing TDM-GCC-64 seems to fix the problem somehow. (Must be a coincidence, but I'll document it anyway.)

After that, just open up your Visual Studio project and hack away!