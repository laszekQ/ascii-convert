# ASCII-CONVERT
## What is it
An Image to ASCII converter capable of turning images (.bmp, .png, .jpg, etc.) into ASCII characters. Can convert in 1:1, 2:1 and 1:2 modes.

### What's the difference between 1:1, 2:1 and 1:2?
When we convert an image to ASCII 1:1, the output looks a bit vertically stretched because in most fonts the characters are 2 times longer in hight comparing to width. And in 1:1 mode, every pixel from the image is mapped to a single ASCII character, while in 2:1, every 2 pixels (taken vertically) are mapped to a single character, making the output look natural, 1:2, on the other hand, stretches the output horizontaally, repeating every character twice.

## Usage
```bash
./ascii-convert [INPUT FILE] [COLOR MODE] [GRADIENT LENGTH] [MODE] [OUTPUT FILE] [FONT] [FONT SIZE]
```
`COLOR MODE` - either `l`(light) or `d`(dark)

`GRADIENT LENGTH` - by default, the gradient is 10 characters long: `" .:-=+*#%@"` you can reduce it,if you want!

`MODE` - `1` - 1:1, `2` - 2:1, `3` - 1:2

`OUTPUT FILE` - not specifying will result in output to console

If you wish to generate the output as an image, add one of the following to the end of the FILE_OUT: (.bmp, .png, .tga, .jpg)<br>
This also requires a `FONT` file provided, you can look up supported font files in the [SFML documentation](https://www.sfml-dev.org/documentation/3.0.1/classsf_1_1Font.html)

### Demonstration "Eye" (light color mode, 9 length, 2:1)
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
You can do the same by simply running:
```bash
cmake .
make
```
in the project folder. This will download SFML 3.0.0 from the official repository.<br>
However, if you build on Windows, **you may face some problems** with SFML dependencies.
