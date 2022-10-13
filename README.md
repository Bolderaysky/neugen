# NeuGen
## What is NeuGen?
NeuGen is neumorphic password generator made in C++ and Web. C++ is used to create window, generate password and web for frontend. NeuGen is cross-platform, it means that this password generator will work on any platform which supports C++ and browsers.
## How frontend is bundled?
For this I use ```xxd``` linux utility, which can convert any file to C header, which I include in my code, convert from HEX back to string or binary format and use.
## How to compile this?
For compiling on GNU/Linux I provide shell script that is pretty easy to use:
```
./compile.sh
```
I don't have access to the MacOS, so I **can't** provide script for MacOS. On Windows it's easy to compile if you have Visual Studio or any compiler like MinGW.
