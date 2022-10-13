xxd -i bundle.html > bundle.h
g++ main.cpp -O2 -o NeuGen `pkg-config --cflags --libs gtk+-3.0 webkit2gtk-4.0`  
