## README

# WARNING
Library currenty under construction and not working!

### INTRODUCTION

This is a lightweight beginner friendly C++ graphics library that is easy and fun to use 
and carrys a lot of the annoying work of setting up the base of a project.
Utilizes SDL2, SDL2_image and SDL2_ttf for efficient graphics rendering.

### ABOUT SDL2

SDL2 is mostly a low-level graphics library written in C.
It has gained its popularity because of it's Cross Platform Compatibility, its easy to use syntax, great documentation and stability.

### PROJECT STATUS

**Note: This library is still in early development.
In future this library will be tested extensively and bug fixes and optimizations will follow soon!
Please report issues you encounter!
New Features will probably be added soon. 

### COMPILATION:
  
  First of, all it is highly recommended to install the SDL2-packages on your system, otherwise working with a 
  high level library like SDL2 can be really annoying.

  Download the packages of: [SDL2, SDL_image, SDL_ttf]. Ask Google or AI(My recommendation) how to do it on your operating system.

  Here is an example makefile for a simple project with only a main.cpp file, output
  directory and a makefile:

  ```make
    
    #-I are the EZ++ header files this one you can include in your
    #---C++ File and you should also link it io your compiler
    #-L is the library directory where all the necessary libaryfiles are included
    EZ_INC := -I"path/to/EZ++/inc" -L"path/to/EZ++/lib"

    #These are the specific libarys from my -L directory
    #---specify these with the -l flag and then the libary file without the "lib"
    #---at the beginning and the extention at the end (e.g. .a, .la, .dll, ...)
    #The here specified ones are the minimum, but you can add as many as you need or want
    LIB := -lEZ++ -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf

    #Output executable
    OUT := output/main.exe

    #type make into your commandline, after you installed make on your machine
    #this will compile your main.cpp file
    all:
      @echo "compiling..."
      g++ $(EZ_INC) main.cpp $(LIB) -o $(OUT)
      @echo "Compiled successfully! Now running..."
      ./$(OUT)
  
  ```

  You can copy this example into makefile into your project.
  Just make sure you are linking the path to your copy of this library correctly.

  In your main.cpp file, use #include"path/to//inc/.hpp" to include the necessary headers
  into your file.

### MAIN  CLASS

The ::Main class has all the configuration you need, when you don't want to do it manually.
Just create a class that inherits ::Main and override its Events(), Render() and Update() (optionally the OnClick()) methods and add desired funtionality.

First, add the EZ++Extention file to your makefile:
    
```make
    LIB := -lEZ++_Ext -lEZ++ -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf
```
It's important that the EZ++Extention file is before the main EZ++ library file. 

This library does not have its own event interface yet, so for event handling you just use the SDL2 syntax.

Here is an example of a main.cpp file

```cpp
  #include "path/to/EZ++/inc/EZ++.hpp"

  class Program : public EZ::Main {
  public:
    Program()
    : EZ::Main(new EZ::Window("Example", 10, 10, 800, 800)) {}

    void Events() override {
      switch(event.type) {
      case SDL_KEYDOWN:
        switch(event.key.keysym.sym) {
        case SDLK_w:
         //plays when 'w' is pressed
         break;
        case SDLK_a:
          //plays when 'a' is pressed
          break;
        }
        break;
      }
      //Your mouse will update automaticly when 'TrackMouse' is true
    }

    void Update() override {
      //Code that plays every frame
    }
  
    void Render() override {
      //Renders every frame
    }

    void OnClick() override {
      print("click!");
    }
  };


  int main(int argc, char* argv[]) { //<-- The parameters are neccecary because this library is based on C!
    Program PROGRAM;
    PROGRAM.StartLoop();
    return 0;
  }


```

There are a lot of resources to learn the SDL2 event syntax.

#### Here are a few Videos explaining the basic syntax:

Key input: https://www.youtube.com/watch?v=YfGYU7wWLo8&t=206s.
Mouse events: https://www.youtube.com/watch?v=4Gq-gnMyJa0&t=153s.

In the EZ++Extention library there are also a lot of other Main Class Extentions that handle basic tasks like proper WASD-Controls and Mouse-Tracking
feel free to explore and add on, as the source code is open for everyone, parsed in folders: [src/, ext/].
