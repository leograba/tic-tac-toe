# Tic-Tac-Toe #

This is yet another version of the world famous tic-tac-toe game. But why?

- To learn the basics of SDL2. As I came across the
[sdltutorials.com](http://www.sdltutorials.com/), it explains the basics by
building the foundion for tic-tac-toe.
- To run an SDL2 app on [Torizon](https://www.toradex.com/torizon). Long story
short, it may help me port [Warzone 2100](https://wz2100.net/) to run on Torizon
someday.

![tic-tac-toe on Toradex Apalis iMX6D 512MB](./misc/media/tic-tac-toe-on-apalis-imx6d-512mb.gif)

## How to Run ##

Choose a [Docker Compose file](./docker-compose) according to your hardware -
either 32-bit or 64-bit - copy it to the board and run:

```
docker-compose up
```

Alternatively, if you want to have a bit more fun, upload the Docker Compose
file to the [Torizon Platform](https://app.torizon.io/#/) and deploy it with a
remote update.

## Development ##

This project is configured to be used with the [VS Code Extension for Torizon](
    https://developer.toradex.com/knowledge-base/visual-studio-code-extension-for-torizon).

- Open it on VS Code
- Select the configuration:
    - appconfig_0: 64-bit platform
    - appconfig_1: 32-bit platform