echo Note: this builder is made for Ubuntu 20.04
g++ rewrite.cpp -llua5.1 -ILua/ -L/usr/include/glm/ -lm -ldl -lglfw -lGL -o builds/engineish
echo OK