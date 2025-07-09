# ASCII-CONVERT
## What is it
An Image to ASCII converter capable of turning images (.bmp, .png, .jpg, etc.) into ASCII characters. Can convert in 1:1, 2:1 and 1:2 modes.

### What's the difference between 1:1, 2:1 and 1:2?
When we convert an image to ASCII 1:1, the output looks a bit vertically stretched because in most fonts the characters are 2 times longer in hight comparing to width. And in 1:1 mode, every pixel from the image is mapped to a single ASCII character, while in 2:1, every 2 pixels (taken vertically) are mapped to a single character, making the output look natural, 1:2, on the other hand, stretches the output horizontaally, repeating every character twice.

## Usage
```bash
./ascii-convert [INPUT FILE] [COLOR MODE] [GRADIENT LENGTH] [MODE] [OUTPUT FILE]
```
`COLOR MODE` - either `l`(light) or `d`(dark)

`GRADIENT LENGTH` - by default, the gradient is 10 characters long: `" .:-=+*#%@"` you can reduce it,if you want!

`MODE` - `1` - 1:1, `2` - 2:1, `3` - 1:2

`OUTPUT FILE` - not specifying will result in output to console

### Demonstration (light color mode, 9 length, 2:1)
```
#*=. :=:.-+***##*-.:++-:=###################*-  :*###############*==***+--+*=:--
*+-. ...-*######+:.--:-+*###################+. :*#################*==***+--+*+-:
*=:-:  -*######*- ..:=*####################*- :+###################*==+**+-=+*+-
+:.-. .=#######+.  :+**###########*********+-.=*####################*-:-+**=--+*
-:-: .-*######+:   ::.:----::::.:...........  ::-=+*#########**==*###*+--=**=:-*
-==..=****+==-.  ....:--.                          .:-==+=--:--=*######*=:-+*=-=
::. .--:::--:.-++=---=-.            .:::........       .::-=+*###########*=-==-:
:::-====+*##*+==:.            .:-+**#%%%###**#***==:.    .-+******+=--=*###*+-:.
***######*=-.                -*%%%%%%%%%%###########*+-.    .......:-+*######*+-
#####*+-:.                   -*%%%%%%%%%*=+############*=:.    .-=**############
####=:                        :+#%%%%%%%+-=###############*=.   :-+*############
###+:     ...     ..            :=*#%%#+.:+#%%%%%%%%%%######+.    .:--=+++++####
%%##=:   :+*+: .  ....         .:---==:. -#%%%%%%%%%%%%%%###=.    -=====-=+*###*      
%%%%#*=:.-*##+.   .::.        .-----:.  .=%%%%%%%%%%%%%%%%%#-    :*###########*=
%%%%%%#*++*#%#=. .::.::.    .:-------: .=#%%%%%%%%%%%%%%%%%#=:  :+###########*=.
%%%%%%%##%%%%%*: ..::--:.  .:-------:..-#%%%%%%%%%%%%%%%%%%+:.:+############=. 
%%%%%%%##%%%%%*- .:------::---------:.-*%%%%%%%%%%%%%%%%%%%#-:=*############+:.:
%%%%%%%%##%%%%%=..-----------------:.=#%%%%%%%%%%%%%%%%%%#=:+#############+:.:-
%%%%%%%%%##%%%%*:.:---------------::=#%%%%%%%%%%%%%%%%%%%#**#############*-..-=
%%%%%%%%%%%#%%%#+:::------------::-+%%%%%%%%%%%%%%%%%%%%%%################+:.-==
%%%%%%%%%%%%%%%##+=---:::::::::.:=#%%%%%%%#%%%%%%%%%%%%%%################*:.-===
%%%%%%%%%%%%%%%%%%%%%####**+==-:-=+****++++#%%%%%%%%%%%%%%%%############*-.:====
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%###**++++*##%%%%%%%%%%%%%%%%%%%%##########=. :====
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#######+: .-====
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%####*- .-=====
```

## External libraries
[SFML 3.0.0](https://www.sfml-dev.org/) is used to open image files and get pixel colors.

## Build
I built it on **Linux** using **CMake** 3.31.6.
You can do the same by running:
```bash
cmake .
make
```
in the project folder.<br>
However, if you build on Windows, **you may face some problems** with SFML dependencies.
