#include "ball.hxx"
#include <catch.hxx>

Block const The_Paddle {100, 400, 100, 20};

TEST_CASE("Ball::Ball")
{
    Game_config config;
    Ball ball(The_Paddle, config);

    CHECK(ball.center.x == 150);
    CHECK(ball.center.y == 394);
}

TEST_CASE("Ball::hits_side")
{
    Game_config config;
    Ball ball(The_Paddle, config);

    CHECK_FALSE(ball.hits_side(config));
    ball.center.x = 1;
    CHECK(ball.hits_side(config));
    ball.center.x = config.scene_dims.width - 1;
    CHECK(ball.hits_side(config));
    ball.center.x = config.scene_dims.width / 2;
    CHECK_FALSE(ball.hits_side(config));
}

TEST_CASE("Ball::hits_top")
{
    Game_config config;
    Ball ball(The_Paddle, config);

    CHECK_FALSE(ball.hits_top(config));
    ball.center.y = 1;
    CHECK(ball.hits_top(config));
    ball.center.y = config.scene_dims.height / 2;
    CHECK_FALSE(ball.hits_side(config));
}
TEST_CASE("Ball::hits_top and Ball::hits_side")
{
    Game_config config;
    Ball ball(The_Paddle, config);

    CHECK_FALSE(ball.hits_top(config));
    ball.radius = 1;
    ball.center.y = 0.9;
    ball.center.x = 0.9;
    CHECK(ball.hits_top(config));
    CHECK(ball.hits_side(config));
}
TEST_CASE("Ball at zeros")
{
    Game_config config;
    Ball ball(The_Paddle, config);

    CHECK_FALSE(ball.hits_top(config));
    ball.radius = 1;
    ball.center.y = 1;
    ball.center.x = 1;
    CHECK_FALSE(ball.hits_top(config));
    CHECK_FALSE(ball.hits_side(config));
}
TEST_CASE("Ball::hits_bottom")
{
    Game_config config;
    Ball ball(The_Paddle, config);

    CHECK_FALSE(ball.hits_top(config));
    ball.radius = 1.1;
    ball.center.y = config.scene_dims.height;
    CHECK(ball.hits_bottom(config));
}
