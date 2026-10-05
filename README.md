# Single Player Pong in C++.

## Observation and License:
This project was made using a template developed by "Programming with Nick" on YouTube. You can find it <a href="https://github.com/educ8s/Raylib-CPP-Starter-Template-for-VSCODE-V2" target="_blank"> here.</a> (I also recommend watching his video explaining how to use this template, you can find it <a href="https://www.youtube.com/watch?v=acvgbKRaxDI" target="_blank">here</a>).

The original template and it's respective archives remain under the rights of their auctor's. The modifications and the additional code were developed by me.

This project is licensed under the [MIT License](LICENSE), except for the
original template code used as its foundation.

## Description:
I created this game to specially to measure my knowledge about Raylib (the library used in this project), since I'm currently a beginner in the game making area.
Be known that this game might have some flaws in it's gameplay, and if you want, you can tell me about any flaw you find in this project.

<img src = "assets/game-footage.png" alt = "In-game Footage." width = 400>

## How to use it:
Firstly, you'll need to have the Raylib library already installed, since the whole game structure is based around it.

The installer for this library is available at the creator's website: <a href="https://www.raylib.com/" target="_blank" >raylib.com </a>

Then, you'll need these two requirements:
<ul>
<li> C++</li>
<li> A C++ running compiler, like MinGW (Windows), GCC (Linux) or Clang (Linux/macOS).
</ul>

If you have already met all these requirements, you can run the code by pressing F5 in VSCode (since this project was configured to run without a .exe file in the launch.json archive, it won't run by pressing the top-right or the Run and Debug menu).

## Structure:
```
Pong-Raylib/
├── .vscode/   /* VSCode configuration for it to run (from the template)*/
│   ├── .gitkeep
│   ├── c_cpp_properties.json
│   ├── launch.json
│   ├── setting.json
│   └── tasks.json
├── assets/   /* Images used */
│   └── game-footage.png
├── lib/      /* Compiler configuration (from the template)
│   ├── libgcc_s_dw2-1.dll
│   └── libstdc++-6.dll
├── src/     /* Game code */
│  └── main.cpp
├── .gitattributes         /* Other running configurations
├── .gitignore             and Makefile archive
├── main.code-workspace    (from the template)
├── Makefile               */
└── README.md   /* README */

```


