# (almost) Pong

![game screen shot](assets/images/gameplay.png)

The classic ping pong game with a catch: the ball gets faster after every bounce. Be quick!

## Dependencies

SFML library.

linux
```
sudo apt-get install libsfml-dev
```

### Build (_linux only_)


If you already have Clion, open the project with it and run with cmake. Otherwise, `cd` to the project directory and run:
```
g++ -c main.cpp
g++ main.o -o pingpong -lsfml-graphics -lsfml-window -lsfml-system
./pingpong
```