# (almost) Pong

![game screen shot](assets/images/gameplay.png)

The classic ping pong game with a catch: the ball gets faster after every bounce. Be quick!

## Dependencies

SFML library

ubuntu
```
sudo apt-get install libsfml-dev
```
macOs
```
brew install sfml
```

### Build

If you already have Clion, open the project with it and run. Otherwise, you would have to build it manually as follows.

- Download the entire project (including the assets)
- `cd` to the project directory
- Now let's compile and build it:

```
g++ -c main.cpp
g++ main.o -o pingpong -lsfml-graphics -lsfml-window -lsfml-system
./pingpong
```