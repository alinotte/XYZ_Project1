#include <SFML/Graphics.hpp>
#include <assert.h>
#include <time.h>

/*int heightM = 20, widthN = 30;
int tileSize = 25;*/
const int SCREEN_WIDTH = 750;
const int SCREEN_HEIGHT = 500;
const int SPRITE_SIZE = 25;
const float SNAKE_SPEED = 150.f;
const int INITIAL_SNAKE_SIZE = 4;

bool isGameOver = false;
int snakeSize = INITIAL_SNAKE_SIZE;

struct Vector2D
{
    float x = 0;
    float y = 0;
};

typedef Vector2D Position2D;

enum class snakeDirection
{
    Right = 0,
    Up,
    Left,
    Down,
};

struct Snake
{
    snakeDirection direction = snakeDirection::Right;
    Position2D position;
} snakeArray[600];

struct Apple
{
    Position2D position;
} apple;

void UpdateGame(float deltaTime, Snake snake[])
{
    // snake position
    for (int i = INITIAL_SNAKE_SIZE; i > 0; i--)
    {
        snake[i].position.x = snake[i - 1].position.x;
        snake[i].position.y = snake[i - 1].position.y;
    }

    // snake head movement
    switch (snake[0].direction)
    {
    case snakeDirection::Right:
    {
        snake[0].position.x += SNAKE_SPEED * deltaTime;
        break;
    }
    case snakeDirection::Up:
    {
        snake[0].position.y -= SNAKE_SPEED * deltaTime;
        break;
    }
    case snakeDirection::Left:
    {
        snake[0].position.x -= SNAKE_SPEED * deltaTime;
        break;
    }
    case snakeDirection::Down:
    {
        snake[0].position.y += SNAKE_SPEED * deltaTime;
        break;
    }
    }

    // snake apple collision
    if ((snake[0].position.x == apple.position.x) &&
        (snake[0].position.y == apple.position.y))
    {
        snakeSize++;

        apple.position.x = (float)(rand() % SCREEN_WIDTH);
        apple.position.y = (float)(rand() % SCREEN_HEIGHT);
    }

    // snake screen border collision
    if (snake[0].position.x < 0 || snake[0].position.x > (SCREEN_WIDTH / SPRITE_SIZE))
    {
        isGameOver = true;
    }
    if (snake[0].position.y < 0 || snake[0].position.y > (SCREEN_HEIGHT / SPRITE_SIZE))
    {
        isGameOver = true;
    }
}

int main()
{
    // init random number generator
    unsigned int seed = (unsigned int)time(nullptr);
    srand(seed);

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Snake Game!");
 
    sf::Texture snakeTexture;
    assert(snakeTexture.loadFromFile("Resources/Paint/snake.png"));
    sf::Sprite snakeSprite(snakeTexture);

    sf::Texture appleTexture;
    assert(appleTexture.loadFromFile("Resources/Paint/apple.png"));
    sf::Sprite appleSprite(appleTexture);

    // apple position
    apple.position.x = (float)(rand() % SCREEN_WIDTH);
    apple.position.y = (float)(rand() % SCREEN_HEIGHT);

    // init game clock
    sf::Clock gameClock;
    sf::Time lastTime = gameClock.getElapsedTime();
    
    // game loop
    while (window.isOpen())
    {
        // reduce framerate not to spam CPU and GPU
        sf::sleep(sf::milliseconds(16));

        // calculate time delta
        sf::Time currentTime = gameClock.getElapsedTime();
        float deltaTime = currentTime.asSeconds() - lastTime.asSeconds();
        lastTime = currentTime;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // handle snake input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            snakeArray[0].direction = snakeDirection::Left;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            snakeArray[0].direction = snakeDirection::Right;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            snakeArray[0].direction = snakeDirection::Up;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            snakeArray[0].direction = snakeDirection::Down;

        UpdateGame(deltaTime, snakeArray);

        if (!isGameOver)
        {
            window.clear();

          // draw snake
            for (int i = 0; i < snakeSize; i++)
            {
                if (i != 0)
                    snakeSprite.setTextureRect(sf::IntRect(0, 0, SPRITE_SIZE, SPRITE_SIZE));
                else
                    snakeSprite.setTextureRect(sf::IntRect((int)snakeArray[i].direction * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));

                if (isGameOver && i == 0)
                {
                    snakeSprite.setTextureRect(sf::IntRect((int)snakeArray[i].direction * SPRITE_SIZE, SPRITE_SIZE * 2, SPRITE_SIZE, SPRITE_SIZE));
                }

                snakeSprite.setPosition(snakeArray[i].position.x, snakeArray[i].position.y);
                window.draw(snakeSprite);
            }

            // draw apple
            appleSprite.setPosition(apple.position.x, apple.position.y);
            window.draw(appleSprite);

            window.display();
        }
    }

    return 0;
}